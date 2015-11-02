package com.BlueRay.mutton.service.plan.exporter.zzjh;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
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
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.service.plan.PlanServiceImpl;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;



public class DBPCJHXXTemplateZzjhExporter implements IExcelExporter<PCJHXX> {

	static class SheetContext {
		public HSSFSheet sheet;
		public int count = 0;
		public Map<String, Integer> repeatRow = new HashMap<String, Integer>();
		public String scrq;
		
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
			
		public void fixed(Location zs, Location jhxdrq) {
			String val = getCell(0, 0).getStringCellValue();
			getCell(0, 0).setCellValue(val.replace("XXX", scrq));
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


	
	public DBPCJHXXTemplateZzjhExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	private Map<String, String[]> getRelationMap(HSSFSheet sheetRelation) {
		Map<String, String[]> relationMap = new HashMap<String, String[]>();
		for (int i = 2; i < sheetRelation.getLastRowNum(); ++i) {
			HSSFRow row = sheetRelation.getRow(i);
			relationMap.put(row.getCell(0).getStringCellValue(), new String[] {
					row.getCell(1).getStringCellValue(),
					row.getCell(2).getStringCellValue(),
					row.getCell(3).getStringCellValue(),
					row.getCell(4).getStringCellValue() });
		}
		return relationMap;
	}

	private SheetContext getContext(String scrq, HSSFWorkbook workbook) {
		if (!contextMap.containsKey(scrq)) {
			contextMap.put(scrq, new SheetContext());
			contextMap.get(scrq).sheet = workbook.cloneSheet(0);
			workbook.setSheetName(workbook.getSheetIndex(contextMap.get(scrq).sheet), scrq);
			contextMap.get(scrq).scrq = scrq;
		}
		return contextMap.get(scrq);
	}

	public void exports() throws IOException {
		
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(config.getTemplatePath()));

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
		
		Map<String, String[]> relationMap = this.getRelationMap(workbook
				.getSheetAt(1));
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] ret = new String[PcjhColumn.end.ordinal()];
	

		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			PCJHXX pcjh = excel.getRow(i);
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			String scrq = ret[PcjhColumn.scrq.ordinal()];

			if (!scrq.isEmpty()) {
				SheetContext context = getContext(scrq, workbook);
				String repeatTag = "";
				HSSFRow row = context.sheet.createRow(config.getBaseRow() + context.count);
				context.count++;
				for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {

					if (config.containsField(j)) {
						if (j == PcjhColumn.sl.ordinal()) {
							List<Location> locs = config.getField(j);
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
									cel.setCellValue(0);
									cel.setCellStyle(style);
								}
								double val = cel.getNumericCellValue();
								cel.setCellValue(val + Integer.valueOf(ret[j]));
							}
						} else if (j == PcjhColumn.ggxh.ordinal()) {
							CPGGXHXX ggxh = itemDao.queryCpggxhxxById(saleDao
									.getSaleDataById(pcjh.getHtxxID())
									.getGgxhID());
							repeatTag += ggxh.getXh() + ggxh.getDw();
							List<Location> locs = config.getField(j);
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
								}
								cel.setCellValue(ret[j]);
								cel.setCellStyle(style);
							}
							String key = ggxh.getXh() + ggxh.getDw();
							String[] map = relationMap.get(key);
							locs = config.getWldm();
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc
										.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
								}
								cel.setCellValue(map != null ? map[0] : "");
								cel.setCellStyle(style);
							}

							locs = config.getMc();
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc
										.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
								}
								cel.setCellValue(map != null ? map[1] : "");
								cel.setCellStyle(style);
							}

							locs = config.getGg();
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc
										.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
								}
								cel.setCellValue(map != null ? map[2] : "");
								cel.setCellStyle(style);
							}

							locs = config.getZjdm();
							for (Location loc : locs) {
								HSSFCell cel = row.getCell(loc
										.getZeroBasedCol());
								if (cel == null) {
									cel = row.createCell(loc.getZeroBasedCol());
								}
								cel.setCellValue(map != null ? map[3] : "");
								cel.setCellStyle(style);
							}
						} else {
							repeatTag += ret[j];
							List<Location> locs =  config.getField(j);
							HSSFCellStyle st = style;
							if (ExporterUtil.validatePlanHighlight(j, ret)){
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
				
				if (context.repeatRow.containsKey(repeatTag)) {
					context.sheet.removeRow(row);
					context.count--;
					row = context.sheet
							.getRow(config.getBaseRow() + context.repeatRow.get(repeatTag) - 1);
					List<Location> locs = config.getField(PcjhColumn.sl.ordinal());
					for (Location loc : locs) {
						HSSFCell cel = row.getCell(loc.getZeroBasedCol());
						if (cel == null) {
							cel = row.createCell(loc.getZeroBasedCol());
							cel.setCellValue(0);
						}
						double val = cel.getNumericCellValue();
						cel.setCellValue(val
								+ Integer.valueOf(ret[PcjhColumn.sl.ordinal()]));
					}
				} else{
					context.repeatRow.put(repeatTag, context.count);
					List<Location> locs = config.getXh();
					for (Location loc : locs) {
						HSSFCell cel = row.getCell(loc.getZeroBasedCol());
						if (cel == null) {
							cel = row.createCell(loc.getZeroBasedCol());
						}
						cel.setCellValue(context.count);
						cel.setCellStyle(style);
					}
				}
			}
		}
		
		for (String tag : contextMap.keySet()){
			contextMap.get(tag).fixed(config.getZs(), config.getJhxdrq());
		}

		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);

		workbook.write(os);
	}

}
