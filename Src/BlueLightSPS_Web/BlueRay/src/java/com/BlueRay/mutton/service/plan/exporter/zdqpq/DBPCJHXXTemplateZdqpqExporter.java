package com.BlueRay.mutton.service.plan.exporter.zdqpq;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;
import com.BlueRay.mutton.common.ExporterUtil;
import com.BlueRay.mutton.common.Location;
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


public class DBPCJHXXTemplateZdqpqExporter implements IExcelExporter<PCJHXX> {

	static class SheetContext {
		public HSSFSheet sheet;
		public int count = 0;
		public String scrq;
		public boolean isZdq;
		public static String getContextKey(String sheetName, String scrq){
			return sheetName + scrq;
		}
		
		private HSSFCell getCell(int row, int col){
			HSSFRow hRow = sheet.getRow(row);
			if (null == hRow){
				hRow = sheet.createRow(row);
			}
			if (null == hRow.getCell(col)){
				return hRow.createCell(row);
			}
			return hRow.getCell(col);
		}
			
		private String getRq(String date){
			Date d = Date.valueOf(date);
			Calendar cal = Calendar.getInstance();
			cal.setTime(d);
			int dayWeek = cal.get(Calendar.DAY_OF_WEEK);
			return date + " " + Util.toChinese(dayWeek - 1);
		}
		
		public void fixed(Configuration config) {
			Location zs = null;
			if (isZdq){
				zs = config.getZdqZs();
			}else{
				zs = config.getPqZs();
			}
			Location jhxdrq = null;
			if (isZdq){
				jhxdrq = config.getZdqJhxdrq();
			}else{
				jhxdrq = config.getPqJhxdrq();
			}
			String val = getCell(0, 0).getStringCellValue();
			getCell(0, 0).setCellValue(val.replace("XXX", getRq(scrq)));
			getCell(zs.getZeroBasedRow(), zs.getZeroBasedCol())
					.setCellValue("" + count);
			
			// 计划下达日期
			Calendar cal = Calendar.getInstance();
			String rq = "" + cal.get(Calendar.YEAR) + "-"
					+ (cal.get(Calendar.MONTH) + 1) + "-"
					+ cal.get(Calendar.DAY_OF_MONTH);
			getCell(jhxdrq.getZeroBasedRow(), jhxdrq.getZeroBasedCol())
			.setCellValue(rq);
		}
	}
	
	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	Configuration config = new Configuration();
	
	private Map<String, SheetContext> contextMap = new Hashtable<String, SheetContext>();


	
	public DBPCJHXXTemplateZdqpqExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	private SheetContext getContext(String scrq, boolean isZdq, HSSFWorkbook workbook, String sheetName) {
		String key = SheetContext.getContextKey(sheetName, scrq);
		if (!contextMap.containsKey(key)) {
			contextMap.put(key, new SheetContext());
			contextMap.get(key).sheet = workbook.cloneSheet(workbook.getSheetIndex(sheetName));
			workbook.setSheetName(workbook.getSheetIndex(contextMap.get(key).sheet), sheetName + "_" + scrq);
			contextMap.get(key).scrq = scrq;
			contextMap.get(key).isZdq = isZdq;
		}
		return contextMap.get(key);
	}
	
	
	private void export(SheetContext context, HSSFRow row, String[] record,
			HSSFCellStyle style, HSSFCellStyle styleHighlight) {
		for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {

			if (context.isZdq ? config.containsZdqField(j) : config.containsPqField(j)) {
				List<Location> locs = context.isZdq ? config.getZdqField(j) : config.getPqField(j);
				HSSFCellStyle st = style;
				if (ExporterUtil.validatePlanHighlight(j, record)) {
					st = styleHighlight;
				}

				for (Location loc : locs) {
					HSSFCell cel = row.getCell(loc.getZeroBasedCol());
					if (cel == null) {
						cel = row.createCell(loc.getZeroBasedCol());
					}
					cel.setCellStyle(st);
					cel.setCellValue(record[j]);
				}
			}
		}

	}

	private void updateRecord(String[] record, List<PCJHXX> pcxxs, PCJHXX pcjh, Map<Integer, HTXX> htxxMap){
		pcxxs.set(0, pcjh);
		PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
		PlanServiceImpl.setPCJH(record, pcxxs.get(0), htxxMap, itemDao);
	}
	
	public void exports() throws IOException {
		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(config.getTemplatePath())));

		HSSFCellStyle style = workbook.createCellStyle();
		style.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		style.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		style.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		style.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		HSSFFont font = workbook.createFont();
		font.setFontHeightInPoints((short) 10);
		style.setFont(font);
		
		HSSFCellStyle styleHighlight = workbook.createCellStyle();
		styleHighlight.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		styleHighlight.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		styleHighlight.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		styleHighlight.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		styleHighlight.setFillForegroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillBackgroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillPattern(HSSFCellStyle.SOLID_FOREGROUND);
		styleHighlight.setFont(font);
		
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			updateRecord(ret, pcxxs, excel.getRow(i), htxxMap);
			String scrq = ret[PcjhColumn.scrq.ordinal()];
			String ggxh = ret[PcjhColumn.ggxh.ordinal()];
			if (!scrq.isEmpty()) {
				if (UtilGGXH.ggIsT(ggxh) || UtilGGXH.ggIsY(ggxh)){
					SheetContext context = this.getContext(scrq, true, workbook, config.getZdqTemplateName());
					HSSFRow row = context.sheet.createRow(config.getZdqBaseRow() + context.count);
					context.count++;
					List<Location> locs = config.getZdqXh();
					for (Location loc : locs) {
						HSSFCell cel = row.getCell(loc.getZeroBasedCol());
						if (cel == null) {
							cel = row.createCell(loc.getZeroBasedCol());
						}
						cel.setCellValue(context.count);
						cel.setCellStyle(style);
					}
					export(context, row, ret, style, styleHighlight);
				}else{
					SheetContext context = this.getContext(scrq, false, workbook, config.getPqTemplateName());
					HSSFRow row = context.sheet.createRow(config.getPqBaseRow() + context.count);
					context.count++;
					List<Location> locs = config.getPqXh();
					for (Location loc : locs) {
						HSSFCell cel = row.getCell(loc.getZeroBasedCol());
						if (cel == null) {
							cel = row.createCell(loc.getZeroBasedCol());
						}
						cel.setCellValue(context.count);
						cel.setCellStyle(style);
					}
					export(context, row, ret, style, styleHighlight);
				}
			}
		}
		
		for (String tag : contextMap.keySet()){
			SheetContext context = contextMap.get(tag);
			context.fixed(config);
		}

		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);

		workbook.write(os);
	}

}
