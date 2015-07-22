package com.BlueRay.mutton.service.sale;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;

import com.BlueRay.mutton.common.ExporterUtil;
import com.BlueRay.mutton.common.HtxxColumn;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

class DBHTXXExcelExporter implements IExcelExporter<HTXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	AbstractExcel<HTXX> excel;
	OutputStream os;

	public DBHTXXExcelExporter(ItemDao itemDao, SaleDao saleDao,
			AbstractExcel<HTXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() throws IOException {
		HSSFWorkbook workbook = new HSSFWorkbook();
		HSSFSheet sheet = workbook.createSheet(excel.getName());
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

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
		
		HSSFRow row = sheet.createRow(0);
		String[] header = excel.getheader().get(0);
		for (int i = 0; i < header.length; i++) {
			HSSFCell cell = row.createCell(i);
			HSSFRichTextString text = new HSSFRichTextString(header[i]);
			cell.setCellValue(text);
			cell.setCellStyle(style);
		}

		try {
			String[] ret = new String[HtxxColumn.end.ordinal()];
			for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
				SaleServiceImpl.setHtxx(ret, excel.getRow(i), itemDao);
				row = sheet.createRow(i + 1);
				for (int j = 1; j < ret.length; ++j) {
					HSSFCell cell = row.createCell(j - 1);
					HSSFRichTextString text = new HSSFRichTextString(ret[j]);
					cell.setCellValue(text);
					if (ExporterUtil.validateSaleHighlight(j, ret)){
				    	 cell.setCellStyle(styleHighlight);
				     }else{
				    	 cell.setCellStyle(style);
				     }
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		workbook.write(os);

	}

}
