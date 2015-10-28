package com.BlueRay.mutton.service.plan.exporter;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.util.ArrayList;
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

public class DBPCJHXXTemplateZzgzkExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;

	private static String pathTemplate = null;
	private static String pathMapfile = null;

	static {
		try {
			String basePath = new URI(DBPCJHXXTemplateZzgzkExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_zzgzk.xls";
			pathMapfile = basePath + "META-INF/template_zzgzk.xml";
			System.out.println(pathTemplate);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private final static int xh = -3;
	private static int baseRow = 0;
	private static long templateXmlTime = 0;
	private static Map<Integer, List<Location>> colsMap = new Hashtable<Integer, List<Location>>();

	private static void loadLocationMultiCell(Document doc, int val, Element e) {
		if (!colsMap.containsKey(val)) {
			colsMap.put(val, new ArrayList<Location>());
		}
		if (null != e) {
			NodeList cells = e.getElementsByTagName("cell");
			for (int j = 0; j < cells.getLength(); j++) {
				Element cell = (Element) cells.item(j);
				colsMap.get(val).add(
						new Location(cell.getAttribute("col"), Integer
								.valueOf(cell.getAttribute("row"))));
			}
		}
	}

	private static void loadLocationMultiCell(Document doc, int val,
			String tagName) {
		Element cell = (Element) doc.getElementsByTagName(tagName).item(0);
		loadLocationMultiCell(doc, val, cell);
	}

	private static synchronized void loadTemplateXml() {
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime) {
			templateXmlTime = time;
			colsMap.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			try {
				DocumentBuilder db = dbf.newDocumentBuilder();
				Document doc = db.parse(pathMapfile);
				loadLocationMultiCell(doc, xh, "xh");

				baseRow = Integer.valueOf(doc.getElementsByTagName("baseRow")
						.item(0).getFirstChild().getNodeValue());
				NodeList fields = doc.getElementsByTagName("table_field");

				for (int i = 0; i < fields.getLength(); i++) {
					Element e = (Element) fields.item(i);
					try {
						PcjhColumn enPcjh = PcjhColumn.valueOf(e
								.getAttribute("name"));
						loadLocationMultiCell(doc, enPcjh.ordinal(), e);

					} catch (Exception ex) {

					}
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

	public DBPCJHXXTemplateZzgzkExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
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
		HSSFSheet sheet = workbook.getSheetAt(0);
		int count = 0;
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			HSSFRow row = sheet.createRow(baseRow + count);
			++count;
			List<Location> locs = colsMap.get(xh);
			for (Location loc : locs) {
				HSSFCell cel = row.getCell(loc.getZeroBasedCol());
				if (cel == null) {
					cel = row.createCell(loc.getZeroBasedCol());
				}
				cel.setCellValue(count);
				cel.setCellStyle(style);
			}

			for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
				if (colsMap.containsKey(j)) {
					locs = colsMap.get(j);
					HSSFCellStyle st = style;
					if (ExporterUtil.validatePlanHighlight(j, ret)) {
						st = styleHighlight;
					}

					for (Location loc : locs) {
						HSSFCell cel = row.getCell(loc.getZeroBasedCol());
						if (cel == null) {
							cel = row.createCell(loc.getZeroBasedCol());
						}
						cel.setCellStyle(st);
						cel.setCellValue(ret[j]);
					}
				}
			}
		}
		workbook.write(os);
	}
}
