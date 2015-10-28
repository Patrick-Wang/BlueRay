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
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

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


public class DBPCJHXXTemplateZdqpqExporter implements IExcelExporter<PCJHXX> {

	static class SheetContext {
		public HSSFSheet sheet;
		public int count = 0;
		public String scrq;
		public Map<Integer, List<Location>> colsMap;
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
		
		public void fixed() {
			Location zs = colsMap.get(DBPCJHXXTemplateZdqpqExporter.zs).get(0);
			Location jhxdrq = colsMap.get(DBPCJHXXTemplateZdqpqExporter.jhxdrq).get(0);
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

	private static String pathTemplate = null;
	private static String pathMapfile = null;

	static {
		try {
			String basePath = new URI(DBPCJHXXTemplateZdqpqExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_zdqPq.xls";
			pathMapfile = basePath + "META-INF/template_zdqPq.xml";
			System.out.println(pathTemplate);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private final static int jhxdrq = -1;
	private final static int zs = -2;
	private final static int xh = -3;
	
	private static int baseRowZdq = 0;
	private static int baseRowPq = 0;
	private static long templateXmlTime = 0;
	private static Map<Integer, List<Location>> colsMapZdq = new Hashtable<Integer, List<Location>>();
	private static Map<Integer, List<Location>> colsMapPq = new Hashtable<Integer, List<Location>>();
	private static String templateZdqName;
	private static String templatePqName;
	private Map<String, SheetContext> contextMap = new Hashtable<String, SheetContext>();

	private static void loadLocation(Map<Integer, List<Location>> colsMap, Element eSheet, int val, String tagName) {
		Element cell = (Element) eSheet.getElementsByTagName(tagName).item(0);
		if (!colsMap.containsKey(val)) {
			colsMap.put(val, new ArrayList<Location>());
		}
		colsMap.get(val).add(
				new Location(cell.getAttribute("col"), Integer.valueOf(cell
						.getAttribute("row"))));
	}

	private static void loadLocationMultiCell(Map<Integer, List<Location>> colsMap, int val, Element e) {
		if (!colsMap.containsKey(val)) {
			colsMap.put(val, new ArrayList<Location>());
		}
		if (null != e){
			NodeList cells = e.getElementsByTagName("cell");
			for (int j = 0; j < cells.getLength(); j++) {
				Element cell = (Element) cells.item(j);
				colsMap.get(val).add(
						new Location(cell.getAttribute("col"), Integer.valueOf(cell
								.getAttribute("row"))));
			}
		}
	}

	private static void loadLocationMultiCell(Map<Integer, List<Location>> colsMap, Element eSheet, int val, String tagName) {
		Element cell = (Element) eSheet.getElementsByTagName(tagName).item(0);
		loadLocationMultiCell(colsMap, val, cell);
	}

	private static int getBaseRow(Element eSheet){
		try{
		return Integer.valueOf(eSheet.getElementsByTagName("baseRow")
				.item(0).getFirstChild().getNodeValue());
		}catch(Exception e){
			return 0;
		}
	}
	
	private static String getSheetName(Element eSheet){
		return eSheet.getElementsByTagName("sheet_name")
				.item(0).getFirstChild().getNodeValue();
	}
	
	
	private static void loadTableFields(Map<Integer, List<Location>> colsMap, Element eSheet){
		NodeList fields = eSheet.getElementsByTagName("table_field");

		for (int i = 0; i < fields.getLength(); i++) {
			Element e = (Element) fields.item(i);
			try {
				PcjhColumn enPcjh = PcjhColumn.valueOf(e
						.getAttribute("name"));
				loadLocationMultiCell(colsMap, enPcjh.ordinal(), e);
			} catch (Exception ex) {

			}
		}
	}
	
	private static synchronized void loadTemplateXml() {
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime) {
			templateXmlTime = time;
			colsMapZdq.clear();
			colsMapPq.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			try {
				DocumentBuilder db = dbf.newDocumentBuilder();
				Document doc = db.parse(pathMapfile);
				Element eSheetZdq = (Element) doc.getElementsByTagName("sheet_zdqzpPlan").item(0);
				Element eSheetPq = (Element) doc.getElementsByTagName("sheet_pqPlan").item(0);
				
				loadLocation(colsMapZdq, eSheetZdq, jhxdrq, "jhxdrq");
				loadLocation(colsMapZdq, eSheetZdq, zs, "zs");
				loadLocationMultiCell(colsMapZdq, eSheetZdq, xh, "xh");
				baseRowZdq = getBaseRow(eSheetZdq);
				loadTableFields(colsMapZdq, eSheetZdq);
				templateZdqName = getSheetName(eSheetZdq);
				
				loadLocation(colsMapPq, eSheetPq, jhxdrq, "jhxdrq");
				loadLocation(colsMapPq, eSheetPq, zs, "zs");
				loadLocationMultiCell(colsMapPq, eSheetPq, xh, "xh");
				baseRowPq = getBaseRow(eSheetPq);
				loadTableFields(colsMapPq, eSheetPq);
				templatePqName = getSheetName(eSheetPq);
				
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	public DBPCJHXXTemplateZdqpqExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	private SheetContext getContext(String scrq, Map<Integer, List<Location>> colsMap, HSSFWorkbook workbook, String sheetName) {
		String key = SheetContext.getContextKey(sheetName, scrq);
		if (!contextMap.containsKey(key)) {
			contextMap.put(key, new SheetContext());
			contextMap.get(key).sheet = workbook.cloneSheet(workbook.getSheetIndex(sheetName));
			workbook.setSheetName(workbook.getSheetIndex(contextMap.get(key).sheet), sheetName + "_" + scrq);
			contextMap.get(key).scrq = scrq;
			contextMap.get(key).colsMap = colsMap;
		}
		return contextMap.get(key);
	}
	
	
	private void export(SheetContext context, int baseRow, String[] record,
			HSSFCellStyle style, HSSFCellStyle styleHighlight) {
		Map<Integer, List<Location>> colsMap = context.colsMap;
		HSSFRow row = context.sheet.createRow(baseRow + context.count);
		context.count++;
		if (colsMap.containsKey(xh)) {
			List<Location> locs = colsMap.get(xh);
			for (Location loc : locs) {
				HSSFCell cel = row.getCell(loc.getZeroBasedCol());
				if (cel == null) {
					cel = row.createCell(loc.getZeroBasedCol());
				}
				cel.setCellValue(context.count);
				cel.setCellStyle(style);
			}
		}

		for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {

			if (colsMap.containsKey(j)) {
				List<Location> locs = colsMap.get(j);
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
		loadTemplateXml();
		
		

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));

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
				if (Util.ggIsT(ggxh) || Util.ggIsY(ggxh)){
					SheetContext context = this.getContext(scrq, colsMapZdq, workbook, templateZdqName);
					export(context, baseRowZdq, ret, style, styleHighlight);
				}else{
					SheetContext context = this.getContext(scrq, colsMapPq, workbook, templatePqName);
					export(context, baseRowPq, ret, style, styleHighlight);
				}
			}
		}
		
		for (String tag : contextMap.keySet()){
			SheetContext context = contextMap.get(tag);
			context.fixed();
		}

		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);

		workbook.write(os);
	}

}
