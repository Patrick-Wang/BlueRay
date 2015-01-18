package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

class DBPCJHXXExcelExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	
	public DBPCJHXXExcelExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() {
		
		HSSFWorkbook workbook = new HSSFWorkbook();
	    HSSFSheet sheet = workbook.createSheet(excel.getName());
	    Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
	    List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
	    pcxxs.add(null);
	    //浜х敓琛ㄦ牸鏍囬琛�
		  HSSFRow row = sheet.createRow(0);
		  String[] header = excel.getheader().get(0);
		  for (short i = 0; i < header.length; i++) {
		     HSSFCell cell = row.createCell(i);
		     HSSFRichTextString text = new HSSFRichTextString(header[i]);
		     cell.setCellValue(text);
		  }
	      
		String[] ret = new String[35];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i){
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			row = sheet.createRow(i + 1);
			for (int j = 1; j < ret.length; ++j){
				 HSSFCell cell = row.createCell(j - 1);
				 HSSFRichTextString text = new HSSFRichTextString(ret[j]);
			     cell.setCellValue(text);
			}
			
		}
		try {
			workbook.write(os);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
