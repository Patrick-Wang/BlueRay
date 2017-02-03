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
import java.util.List;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;

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
import com.BlueRay.mutton.tool.UtilGGXH;

public class DBPCJHXXTemplateScjhExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	private static String pathTemplate = null;
	static 
	{
		try {
			String basePath = new URI(DBPCJHXXTemplateScjhExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_scjh.xls";			
			System.out.println(pathTemplate);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public DBPCJHXXTemplateScjhExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}
	
	private static PcjhColumn[] columns = new PcjhColumn[]{
		PcjhColumn.tcbh,
		PcjhColumn.khmc,
		PcjhColumn.ggxh,
		PcjhColumn.zjys,
		PcjhColumn.zjdy,
		PcjhColumn.bmqxh,
		PcjhColumn.sl,
		PcjhColumn.zdqdy,
		PcjhColumn.zdqxh,
		PcjhColumn.zc,
		PcjhColumn.cg,
		PcjhColumn.yylgg,
		PcjhColumn.jf,
		PcjhColumn.bz
	};

//	private boolean isSorT(String ggxh){
//		if (!ggxh.isEmpty()){
//			String tag = ggxh.substring(0, 1);
//			return tag.equals("S") || tag.equals("T");
//		}
//		return false;
//	}
//	
//	private boolean isU(String ggxh){
//		if (!ggxh.isEmpty()){
//			String tag = ggxh.substring(0, 1);
//			return tag.equals("U");
//		}
//		return false;
//	}
	
	public void exports() throws IOException {
		
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
//		HSSFSheet sheetST = workbook.getSheetAt(0);
//		HSSFSheet sheetU = workbook.getSheetAt(1);
//		HSSFSheet sheetOther = workbook.getSheetAt(2);
		
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
//		int countSorT = 0;
//		int countU = 0;
//		int countOther = 0;
		Map<String, Integer> mapScrq2Count = new HashMap<String, Integer>();
		Map<String, HSSFSheet> mapScrq2Sheet = new HashMap<String, HSSFSheet>();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			String scrq = ret[PcjhColumn.scrq.ordinal()];
			if (!scrq.isEmpty()){
				String ggxh = ret[PcjhColumn.ggxh.ordinal()];			
				if (UtilGGXH.ggIsS(ggxh) || UtilGGXH.ggIsTStart(ggxh) || UtilGGXH.ggIsL(ggxh) || UtilGGXH.ggIsLA(ggxh)){
					if (!mapScrq2Sheet.containsKey(scrq + "_ST")){
						mapScrq2Sheet.put(scrq + "_ST", workbook.cloneSheet(0));
						mapScrq2Count.put(scrq + "_ST", 1);
					}
					export2SorT(ret, mapScrq2Sheet.get(scrq + "_ST"), style, styleHighlight, mapScrq2Count.get(scrq + "_ST"));
					mapScrq2Count.put(scrq + "_ST", 1 + mapScrq2Count.get(scrq + "_ST"));
				} else if(UtilGGXH.ggIsU(ggxh) || UtilGGXH.ggIsV(ggxh)){
					if (!mapScrq2Sheet.containsKey(scrq + "_U")){
						mapScrq2Sheet.put(scrq + "_U", workbook.cloneSheet(1));
						mapScrq2Count.put(scrq + "_U", 1);
					}
					export2U(ret, mapScrq2Sheet.get(scrq + "_U"), style, styleHighlight, mapScrq2Count.get(scrq + "_U"));
					mapScrq2Count.put(scrq + "_U", 1 + mapScrq2Count.get(scrq + "_U"));
				} else if(UtilGGXH.ggIsL(ggxh) || UtilGGXH.ggIsLA(ggxh)) {
					if (!mapScrq2Sheet.containsKey(scrq + "_OTHERL")){
						mapScrq2Sheet.put(scrq + "_OTHERL", workbook.cloneSheet(3));
						mapScrq2Count.put(scrq + "_OTHERL", 1);
					}
					export2Other(ret, mapScrq2Sheet.get(scrq + "_OTHERL"), style, styleHighlight, mapScrq2Count.get(scrq + "_OTHERL"));
					mapScrq2Count.put(scrq + "_OTHERL", 1 + mapScrq2Count.get(scrq + "_OTHERL"));
				} else{
					if (!mapScrq2Sheet.containsKey(scrq + "_OTHER")){
						mapScrq2Sheet.put(scrq + "_OTHER", workbook.cloneSheet(2));
						mapScrq2Count.put(scrq + "_OTHER", 1);
					}
					export2Other(ret, mapScrq2Sheet.get(scrq + "_OTHER"), style, styleHighlight, mapScrq2Count.get(scrq + "_OTHER"));
					mapScrq2Count.put(scrq + "_OTHER", 1 + mapScrq2Count.get(scrq + "_OTHER"));
				}
			}
		}	
		
//		HSSFCellStyle styleBottom = workbook.createCellStyle();
//		styleBottom.setBorderBottom(HSSFCellStyle.BORDER_MEDIUM); // 下边框
//		styleBottom.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
//		styleBottom.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
//		styleBottom.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
//		
//		HSSFCellStyle styleBottomRight = workbook.createCellStyle();
//		styleBottomRight.setBorderBottom(HSSFCellStyle.BORDER_MEDIUM); // 下边框
//		styleBottomRight.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
//		styleBottomRight.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
//		styleBottomRight.setBorderRight(HSSFCellStyle.BORDER_MEDIUM);// 右边框
//		
//		HSSFCellStyle styleRight = workbook.createCellStyle();
//		styleRight.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
//		styleRight.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
//		styleRight.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
//		styleRight.setBorderRight(HSSFCellStyle.BORDER_MEDIUM);// 右边框
//				
//		for (String key : mapScrq2Sheet.keySet()) {
//			if (key.contains("_OTHER")) {
//				HSSFSheet sheetOther = mapScrq2Sheet.get(key);
//				HSSFRow row = sheetOther.getRow(sheetOther.getLastRowNum());
//				for (int i = 0; i < row.getLastCellNum() - 1; ++i){
//					row.getCell(i).setCellStyle(styleBottom);
//				}
//				row.getCell(columns.length).setCellStyle(styleBottomRight);
//				for (int i = 2; i < sheetOther.getLastRowNum(); ++i){
//					sheetOther.getRow(i).getCell(columns.length).setCellStyle(styleRight);
//				}
//			} else if (key.contains("_U")) {
//				HSSFSheet sheetU = mapScrq2Sheet.get(key);
//				HSSFRow row = sheetU.getRow(sheetU.getLastRowNum());
//				for (int i = 0; i < row.getLastCellNum() - 1; ++i){
//					row.getCell(i).setCellStyle(styleBottom);
//				}
//				row.getCell(columns.length).setCellStyle(styleBottomRight);
//				for (int i = 2; i < sheetU.getLastRowNum(); ++i){
//					sheetU.getRow(i).getCell(columns.length).setCellStyle(styleRight);
//				}
//			} else if (key.contains("_ST")) {
//				HSSFSheet sheetST = mapScrq2Sheet.get(key);
//				HSSFRow row = sheetST.getRow(sheetST.getLastRowNum());
//				for (int i = 0; i < row.getLastCellNum() - 1; ++i){
//					row.getCell(i).setCellStyle(styleBottom);
//				}
//				row.getCell(columns.length).setCellStyle(styleBottomRight);
//				for (int i = 3; i < sheetST.getLastRowNum(); ++i){
//					sheetST.getRow(i).getCell(columns.length).setCellStyle(styleRight);
//				}
//			}
//		}
		workbook.removeSheetAt(3);
		workbook.removeSheetAt(2);
		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);
		
		workbook.write(os);
	}

	private String getRq(String date){
		Date d = Date.valueOf(date);
		Calendar cal = Calendar.getInstance();
		cal.setTime(d);
		int dayWeek = cal.get(Calendar.DAY_OF_WEEK);
		return date + " " + Util.toChinese(dayWeek - 1);
	}
	
	private void export2Other(String[] ret, HSSFSheet sheetOther,
			HSSFCellStyle style, HSSFCellStyle styleHighlight, int count) {
		HSSFCell cellTitle = sheetOther.getRow(0).getCell(0);
		String val = cellTitle.getStringCellValue();
		val = val.replace("XXX", getRq(ret[PcjhColumn.scrq.ordinal()]));
		cellTitle.setCellValue(val);
		
		Calendar cal = Calendar.getInstance();
		String rq = "" + cal.get(Calendar.YEAR) + "-"
				 + (cal.get(Calendar.MONTH) + 1) + "-"
				 + cal.get(Calendar.DAY_OF_MONTH);
		HSSFCell cellRq = sheetOther.getRow(1).getCell(9);
		cellRq.setCellValue("计划下达日期:" + rq);
		
		HSSFCell cellHj = sheetOther.getRow(1).getCell(13);
		cellHj.setCellValue("" + count);
		
		HSSFRow row = sheetOther.createRow(3 + count - 1);
		HSSFCell cell = row.createCell(0);
		cell.setCellValue(count);
		cell.setCellStyle(style);
		for (int i = 0; i < columns.length; ++i){
			cell = row.createCell(i + 1);
			cell.setCellValue(ret[columns[i].ordinal()]);
			if (ExporterUtil.validatePlanHighlight(columns[i], ret)){
				cell.setCellStyle(styleHighlight);
			}else{
				cell.setCellStyle(style);
			}
		}
	}

	private void export2U(String[] ret, HSSFSheet sheetU, HSSFCellStyle style,
			HSSFCellStyle styleHighlight, int count) {
		HSSFCell cellTitle = sheetU.getRow(0).getCell(0);
		String val = cellTitle.getStringCellValue();
		val = val.replace("XXX", getRq(ret[PcjhColumn.scrq.ordinal()]));
		cellTitle.setCellValue(val);
		
		
		Calendar cal = Calendar.getInstance();
		String rq = "" + cal.get(Calendar.YEAR) + "-"
				 + (cal.get(Calendar.MONTH) + 1) + "-"
				 + cal.get(Calendar.DAY_OF_MONTH);
		HSSFCell cellRq = sheetU.getRow(1).getCell(9);
		cellRq.setCellValue("计划下达日期:" + rq);
		
		HSSFCell cellHj = sheetU.getRow(1).getCell(13);
		cellHj.setCellValue("" + count);
		
		
		HSSFRow row = sheetU.createRow(3 + count - 1);
		HSSFCell cell = row.createCell(0);
		cell.setCellValue(count);
		cell.setCellStyle(style);
		for (int i = 0; i < columns.length; ++i){
			cell = row.createCell(i + 1);
			cell.setCellValue(ret[columns[i].ordinal()]);
			if (ExporterUtil.validatePlanHighlight(columns[i], ret)){
				cell.setCellStyle(styleHighlight);
			}else{
				cell.setCellStyle(style);
			}
		}
	}

	private void export2SorT(String[] ret, HSSFSheet sheetST,
			HSSFCellStyle style, HSSFCellStyle styleHighlight, int count) {
		
		HSSFCell cellTitle = sheetST.getRow(0).getCell(0);
		String val = cellTitle.getStringCellValue();
		val = val.replace("XXX", getRq(ret[PcjhColumn.scrq.ordinal()]));
		cellTitle.setCellValue(val);
		
		Calendar cal = Calendar.getInstance();
		String rq = "" + cal.get(Calendar.YEAR) + "-"
				 + (cal.get(Calendar.MONTH) + 1) + "-"
				 + cal.get(Calendar.DAY_OF_MONTH);
		HSSFCell cellRq = sheetST.getRow(1).getCell(9);
		cellRq.setCellValue("计划下达日期:" + rq);
		
		HSSFCell cellHj = sheetST.getRow(1).getCell(13);
		cellHj.setCellValue("" + count);
		
		
		HSSFRow row = sheetST.createRow(3 + count - 1);
		HSSFCell cell = row.createCell(0);
		cell.setCellValue(count);
		cell.setCellStyle(style);

		for (int i = 0; i < columns.length; ++i){
			cell = row.createCell(i + 1);
			cell.setCellValue(ret[columns[i].ordinal()]);
			if (ExporterUtil.validatePlanHighlight(columns[i], ret)){
				cell.setCellStyle(styleHighlight);
			}else{
				cell.setCellStyle(style);
			}
		}
	}
}
