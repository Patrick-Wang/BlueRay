package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

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

	public void exports() {
		HSSFWorkbook workbook = new HSSFWorkbook();
		HSSFSheet sheet = workbook.createSheet(excel.getName());
		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFRow row = sheet.createRow(0);
		String[] header = excel.getheader().get(0);
		for (short i = 0; i < header.length; i++) {
			HSSFCell cell = row.createCell(i);
			HSSFRichTextString text = new HSSFRichTextString(header[i]);
			cell.setCellValue(text);
		}
		
		try {
			String[] ret = new String[20];
			for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
				SaleServiceImpl.setHtxx(ret, excel.getRow(i), itemDao);
				row = sheet.createRow(i + 1);
				for (int j = 1; j < ret.length; ++j) {
					HSSFCell cell = row.createCell(j - 1);
					HSSFRichTextString text = new HSSFRichTextString(ret[j]);
					cell.setCellValue(text);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		try {
			workbook.write(os);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
