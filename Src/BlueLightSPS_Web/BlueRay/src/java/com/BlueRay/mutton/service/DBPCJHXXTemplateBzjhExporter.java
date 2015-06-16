package com.BlueRay.mutton.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

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
	
	
	static class Location{
		int x;
		int y;
		public Location(char y, int x) {
			this.x = x - 1;
			this.y = y - 'A';
		}
		public int getX() {
			return x;
		}
		public int getY() {
			return y;
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
	                    	colsMap.get(enPcjh.ordinal()).add(toInt(cell.getAttribute("col")));
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

	static String[] title = new String[]{
		    "合同号", "客户名称", "规格型号", "磁钢", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"
	};
	
	private void exportEachDayOneSheet(HSSFWorkbook workbook,
			HSSFCellStyle style, Map<Integer, HTXX> htxxMap) {
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			String scrq = ret[PcjhColumn.scrq.ordinal()];
			if (!"".equals(scrq)) {
				HSSFSheet sheet = workbook.getSheet(scrq);
				if (null == sheet) {
					sheet = workbook.cloneSheet(workbook
							.getSheetIndex(sheetName));
					workbook.setSheetName(workbook.getSheetIndex(sheet), scrq);

					HSSFRow row = sheet.createRow(sheet.getLastRowNum());
					for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
						if (colsMap.containsKey(j)) {
							List<Integer> cols = colsMap.get(j);
							for (Integer col : cols) {
								HSSFCell cell = row.createCell(col);
								cell.setCellStyle(style);
								cell.setCellValue(title[j - 1]);
							}
						}
					}
					HSSFCell cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("磁极角");
					cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("径向跳动");
					cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("法向跳动");
				}
				if (null != sheet) {
					HSSFRow row = sheet.createRow(sheet.getLastRowNum() + 1);
					for (int j = 1, k = 0; j < PcjhColumn.end.ordinal(); ++j) {
						if (colsMap.containsKey(j)) {
							List<Integer> cols = colsMap.get(j);
							for (Integer col : cols) {
								HSSFCell cell = row.createCell(col);
								cell.setCellStyle(style);
								cell.setCellValue(ret[j]);
							}
						}
					}
					HSSFCell cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("");
					cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("");
					cell = row.createCell((int) row.getLastCellNum());
					cell.setCellStyle(style);
					cell.setCellValue("");
				}
			}
		}

		workbook.removeSheetAt(workbook.getSheetIndex(sheetName));

		for (int i = 0; i < workbook.getNumberOfSheets(); ++i) {
			HSSFSheet sheet = workbook.getSheetAt(i);
			// int colCount = sheet.getRow(0).getLastCellNum();
			// for (int j = 0; j < colCount; ++j) {
			// sheet.autoSizeColumn(j, true);
			// }
			HSSFRow row = sheet.createRow(sheet.getLastRowNum() + 1);
			row.createCell(0);
			HSSFCell cel = row.createCell(1);
			cel.setCellValue("审核: ");
			row.createCell(2);
			row.createCell(3);
			cel = row.createCell(4);
			cel.setCellValue("计划员：");
			row.createCell(5);
			cel = row.createCell(6);
			cel.setCellValue("计划下达日期：" + sheet.getSheetName());
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
		// HSSFFont font = workbook.createFont();
		// font.setFontHeightInPoints((short) 16);
		// style.setFont(font);
		if (1 == templateStyle) {
			this.exportEachDayOneSheet(workbook, style, htxxMap);
		} else {
			this.exportOnlyOneSheet(workbook, style, htxxMap);
		}
		workbook.write(os);
	}

	private void exportOnlyOneSheet(HSSFWorkbook workbook, HSSFCellStyle style,
			Map<Integer, HTXX> htxxMap) {
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
		HSSFSheet sheet = workbook.getSheet(sheetName);
		if (null != sheet) {

			HSSFRow row = sheet.createRow(sheet.getLastRowNum());
			for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
				if (colsMap.containsKey(j)) {
					List<Integer> cols = colsMap.get(j);
					for (Integer col : cols) {
						HSSFCell cell = row.createCell(col);
						cell.setCellStyle(style);
						cell.setCellValue(title[j - 1]);
					}
				}
			}
			HSSFCell cell = row.createCell((int) row.getLastCellNum());
			cell.setCellStyle(style);
			cell.setCellValue("磁极角");
			cell = row.createCell((int) row.getLastCellNum());
			cell.setCellStyle(style);
			cell.setCellValue("径向跳动");
			cell = row.createCell((int) row.getLastCellNum());
			cell.setCellStyle(style);
			cell.setCellValue("法向跳动");

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
							cell.setCellStyle(style);
							cell.setCellValue(ret[j]);
						}
					}
				}
				cell = row.createCell((int) row.getLastCellNum());
				cell.setCellStyle(style);
				cell.setCellValue("");
				cell = row.createCell((int) row.getLastCellNum());
				cell.setCellStyle(style);
				cell.setCellValue("");
				cell = row.createCell((int) row.getLastCellNum());
				cell.setCellStyle(style);
				cell.setCellValue("");

			}
		}
	}
}
