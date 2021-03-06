package com.BlueRay.mutton.service.plan.exporter;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.common.ExporterUtil;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.service.plan.PlanServiceImpl;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;
import com.BlueRay.mutton.tool.Util;

public class DBPCJHXXTemplateBzjhExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	private static String pathTemplate = null;
	private static String pathMapfile = null;
	static 
	{
		try {
			String basePath = new URI(DBPCJHXXTemplateBzjhExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_bzjh.xls";
			pathMapfile = basePath + "META-INF/template_bzjh.xml";
			
			System.out.println(pathTemplate);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	

	private static long templateXmlTime = 0;
	private static String sheetName = null;
	private static Integer templateStyle = null;
	private static Map<Integer, List<Integer>> colsMap = new Hashtable<Integer, List<Integer>>();
	
	private static Integer toInt(String col){
		Integer ret = 0;
		for (int i = 0; i < col.length(); ++i){
			ret +=  (col.charAt(i) - 'A' + 1) * zsys(('Z' - 'A' + 1), i);
		}
		return ret;
	}
	
	private static Integer zsys(Integer ds, int zs){
		Integer tmp = 1;
		for(int i = 0; i < zs; ++i){
			tmp *= ds;
		}
		return tmp;
	}
	
	private static synchronized void loadTemplateXml(){
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime){
			templateXmlTime = time;
			colsMap.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();  
	        try  
	        {  
	            DocumentBuilder db = dbf.newDocumentBuilder();  
	            Document doc = db.parse(pathMapfile);  
	            sheetName = doc.getElementsByTagName("sheet_name").item(0).getFirstChild().getNodeValue();
	            templateStyle = Integer.valueOf(doc.getElementsByTagName("sheet_style").item(0).getFirstChild().getNodeValue());
	            NodeList fields = doc.getElementsByTagName("table_field");  
	            
	            for (int i = 0; i < fields.getLength(); i++)  
	            {  
	            	Element e = (Element)fields.item(i);
	                try{
	                	 PcjhColumn enPcjh = PcjhColumn.valueOf(e.getAttribute("name"));
	                  	 colsMap.put(enPcjh.ordinal(), new ArrayList<Integer>());
	                  	NodeList cells = e.getElementsByTagName("cell");
	                  	for (int j = 0; j < cells.getLength(); j++)  
	                    {  
	                    	Element cell = (Element)cells.item(j);
	                    	colsMap.get(enPcjh.ordinal()).add(toInt(cell.getAttribute("col")) - 1);
	                    }  
	                }catch(Exception ex){
	                	
	                }
	            }  
	        }  
	        catch (Exception e)  
	        {  
	            e.printStackTrace();  
	        }
		}
	}
	
	public DBPCJHXXTemplateBzjhExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	private void exportEachDayOneSheet(HSSFWorkbook workbook,
			HSSFCellStyle style, HSSFCellStyle styleHighlight, Map<Integer, HTXX> htxxMap) {
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
		int start = workbook.getNumberOfSheets();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			ret[PcjhColumn.yxj.ordinal()] = "";
			String bzrq = ret[PcjhColumn.bzrq.ordinal()];
			if (!"".equals(bzrq)) {
				HSSFSheet sheet = workbook.getSheet(bzrq);
				if (null == sheet) {
					sheet = workbook.cloneSheet(workbook.getSheetIndex(sheetName));
					workbook.setSheetName(workbook.getSheetIndex(sheet), bzrq);
					HSSFRow row = sheet.getRow(0);
					if (null != row){
						HSSFCell cell = row.getCell(1);
						if (null != cell){
							Date d = Date.valueOf(bzrq);
							Calendar cal = Calendar.getInstance();
							cal.setTime(d);
							int dayWeek = cal.get(Calendar.DAY_OF_WEEK);
							String oldVal = cell.getStringCellValue();
							String newVal = bzrq + "（" + Util.toChinese(dayWeek - 1) + "）" + oldVal;
							cell.setCellValue(newVal);
						}
					}
					row = sheet.getRow(2);
					if (null != row){
						HSSFCell cell = row.createCell(14);
						if (null != cell){
							cell.setCellValue("0");
						}
					}
				}
				if (null != sheet) {
					HSSFRow row = sheet.createRow(sheet.getLastRowNum() + 1);
					for (int j = 0; j < PcjhColumn.end.ordinal(); ++j) {
						if (colsMap.containsKey(j)) {
							List<Integer> cols = colsMap.get(j);
							for (Integer col : cols) {
								HSSFCell cell = row.createCell(col);
								cell.setCellValue(ret[j]);
								 if (ExporterUtil.validatePlanHighlight(j, ret)){
							    	 cell.setCellStyle(styleHighlight);
							     }else{
							    	 cell.setCellStyle(style);
							     }
							}
						}
					}
					row = sheet.getRow(2);
					if (null != row){
						HSSFCell cell = row.getCell(14);
						if (null != cell){
							cell.setCellValue((1 + Integer.valueOf(cell.getStringCellValue())) + "");
						}
					}
				}
			}
		}

	
		for (int i = start; i < workbook.getNumberOfSheets(); ++i) {
			HSSFSheet sheet = workbook.getSheetAt(i);		
			HSSFRow rowRq = sheet.getRow(2);
			if (null != rowRq){
				HSSFCell cellRq = rowRq.getCell(7);
				if (null != cellRq){
					Calendar cal = Calendar.getInstance();
					cellRq.setCellValue("计划下达日期:" + cal.get(Calendar.YEAR) + "-"
							 + (cal.get(Calendar.MONTH) + 1) + "-"
							 + cal.get(Calendar.DAY_OF_MONTH));
				}
			}
		}

		for (int i = 0; i < start; ++i){
			workbook.removeSheetAt(i);
		}
	}

	public void exports() throws IOException {
		loadTemplateXml();
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));

		HSSFCellStyle style = workbook.createCellStyle();
		style.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		style.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		style.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		style.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		
		HSSFCellStyle styleHighlight = workbook.createCellStyle();
		styleHighlight.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		styleHighlight.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		styleHighlight.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		styleHighlight.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		styleHighlight.setFillForegroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillBackgroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillPattern(HSSFCellStyle.SOLID_FOREGROUND);
		// HSSFFont font = workbook.createFont();
		// font.setFontHeightInPoints((short) 16);
		// style.setFont(font);
		if (1 == templateStyle) {
			this.exportEachDayOneSheet(workbook, style, styleHighlight, htxxMap);
		} else {
			this.exportOnlyOneSheet(workbook, style, styleHighlight, htxxMap);
		}
		workbook.write(os);
	}

	private void exportOnlyOneSheet(HSSFWorkbook workbook, HSSFCellStyle style,
			HSSFCellStyle styleHighlight, Map<Integer, HTXX> htxxMap) {
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
		HSSFSheet sheet = workbook.getSheet(sheetName);
		if (null != sheet) {
			HSSFRow row = null;
			HSSFCell cell = null;
			for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
				pcxxs.set(0, excel.getRow(i));
				PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
				PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);

				row = sheet.createRow(sheet.getLastRowNum() + 1);
				for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
					if (colsMap.containsKey(j)) {
						List<Integer> cols = colsMap.get(j);
						for (Integer col : cols) {
							cell = row.createCell(col);
							cell.setCellValue(ret[j]);
							 if (ExporterUtil.validatePlanHighlight(j, ret)){
						    	 cell.setCellStyle(styleHighlight);
						     }else{
						    	 cell.setCellStyle(style);
						     }
						}
					}
				}


			}			
		}
		
		HSSFRow rowRq = sheet.getRow(2);
		if (null != rowRq){
			HSSFCell cellRq = rowRq.getCell(8);
			if (null != cellRq){
				Calendar cal = Calendar.getInstance();
				cellRq.setCellValue("计划下达日期:" + cal.get(Calendar.YEAR) + "-"
						 + (cal.get(Calendar.MONTH) + 1) + "-"
						 + cal.get(Calendar.DAY_OF_MONTH));
			}
		}
	}
}
