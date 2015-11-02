package com.BlueRay.mutton.service.plan.exporter.zzgzk;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
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

public class DBPCJHXXTemplateZzgzkExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	Configuration config = new Configuration();
	
	
	public DBPCJHXXTemplateZzgzkExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() throws IOException {

		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

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
		HSSFSheet sheet = workbook.getSheetAt(0);
		int count = 0;
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			HSSFRow row = sheet.createRow(config.getBaseRow() + count);
			++count;
			List<Location> locs = config.getXh();
			for (Location loc : locs) {
				HSSFCell cel = row.getCell(loc.getZeroBasedCol());
				if (cel == null) {
					cel = row.createCell(loc.getZeroBasedCol());
				}
				cel.setCellValue(count);
				cel.setCellStyle(style);
			}

			for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
				if (config.containsField(j)) {
					locs = config.getField(j);
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
