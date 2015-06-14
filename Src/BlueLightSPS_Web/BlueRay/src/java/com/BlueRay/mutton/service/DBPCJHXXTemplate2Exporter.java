package com.BlueRay.mutton.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

public class DBPCJHXXTemplate2Exporter implements IExcelExporter<PCJHXX> {

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
			String basePath = new URI(DBPCJHXXTemplate2Exporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template2.xls";
			pathMapfile = basePath + "META-INF/template2.xml";
			
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
	
	private static Set<Integer> excludeSet = new HashSet<Integer>();
	static{
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();  
        try  
        {  
            DocumentBuilder db = dbf.newDocumentBuilder();  
            Document doc = db.parse(pathMapfile);  
  
            NodeList excludes = doc.getElementsByTagName("exclude");  
            for (int i = 0; i < excludes.getLength(); i++)  
            {  
                String col = excludes.item(i).getFirstChild().getNodeValue();
                try{
                	 PcjhColumn enCol = PcjhColumn.valueOf(col);
                	 excludeSet.add(enCol.ordinal());
                }catch(Exception e){
                	
                }
            }  
        }  
        catch (Exception e)  
        {  
            e.printStackTrace();  
        }
	}
	
	public DBPCJHXXTemplate2Exporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	
	
	public void exports() throws IOException {
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));
		String[] ret = new String[PcjhColumn.end.ordinal()];
	
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			String scrq = ret[PcjhColumn.scrq.ordinal()];
			if (!"".equals(scrq)){
				HSSFSheet sheet = workbook.getSheet(scrq);
				if (null == sheet){
					sheet = workbook.cloneSheet(0);
					workbook.setSheetName(workbook.getSheetIndex(sheet), scrq);
				}
				if (null != sheet){
					HSSFRow row = sheet.createRow(sheet.getLastRowNum());
					for(int j = 1; j < PcjhColumn.end.ordinal(); ++j){
						HSSFCell cell = row.createCell(j - 1);
						cell.setCellValue(ret[j]);
					}
				}
			}
		}
		
		workbook.removeSheetAt(0);
		
		for (int i = 0; i < workbook.getNumberOfSheets(); ++i){
			HSSFSheet sheet = workbook.getSheetAt(i);
			for (int j = 1; j < sheet.getLastRowNum(); ++j){
				HSSFRow row = sheet.getRow(j);
				for(int k = PcjhColumn.end.ordinal() - 1; null != row && k >= 1 ; --k){
					if (excludeSet.contains(k) && null != row.getCell(k - 1)){
						row.removeCell(row.getCell(k - 1));
					}
				}
			}
			HSSFRow row = sheet.createRow(sheet.getLastRowNum());
			row.createCell(0);
			HSSFCell cel = row.createCell(1);
			cel.setCellValue("审核: ");
			row.createCell(2);
			row.createCell(3);
			cel = row.createCell(4);
			cel.setCellValue("计划员：");
			row.createCell(5);
			cel = row.createCell(6);
			cel.setCellValue("计划下达日期：");
		}

		workbook.write(os);
	}
}
