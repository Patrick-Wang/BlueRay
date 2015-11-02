package com.BlueRay.mutton.service.plan.exporter;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.UUID;

import net.sf.json.JSONObject;

import org.w3c.dom.Node;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

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
import com.vbarunner.Cells;
import com.vbarunner.VBAExcel;
import com.vbarunner.VBAServiceParam;

public class DBPCJHXXTemplateExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	static VBAExcel vbaExcel = new VBAExcel();
	static String basePath;
	private static String pathTemplate = null;
	private static String pathMapfile = null;
	private static long templateXmlTime = 0;
	static 
	{
		try {
			basePath = new URI(DBPCJHXXTemplateBzjhExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template.xls";
			pathMapfile = basePath + "META-INF/template.xml";
			
			System.out.println(pathTemplate);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		vbaExcel.start();
		
	}

	private static Set<String> getNames(NodeList names) {
		Set<String> nameSet = new HashSet<String>();
		for (int i = 0; i < names.getLength(); i++) {
			nameSet.add(names.item(i).getFirstChild()
					.getNodeValue());
		}
		return nameSet;
	}
	
	
	private static void parseCellMap(Map<String, Location[]> locations, Element field){
		String val = field.getAttribute("name");
		PcjhColumn col = null;
		try{
			col = PcjhColumn.valueOf(val);
			NodeList cells = field.getElementsByTagName("cell");
			if (cells.getLength() > 0){
				Location locs[] = new Location[cells.getLength()];
				locations.put("col_" + col.ordinal(), locs);
				 for (int i = 0; i < cells.getLength(); i++)  
		         {
					 Element cell = (Element) cells.item(i);
					 try{
						 locs[i] = new Location(
								 cell.getAttribute("col"),
								 Integer.valueOf(cell.getAttribute("row"))); 
					 }catch(Exception e){
						 
					 }
		         }
			}
		}
		catch(Exception e){
			
		}
	}
	
	private static void parseSheet(Element sheet){
		 Set<String> names = getNames(sheet.getElementsByTagName("sheet_name"));
		 NodeList fields = sheet.getElementsByTagName("table_field");
		 Map<String, Location[]> locations = new HashMap<String, Location[]>();
		 
		 for (int i = 0; i < fields.getLength(); i++)  
         {
			 parseCellMap(locations, (Element) fields.item(i));
         }
		 
		 for(String name: names){
			 DBTemplateMap.put(name, locations);
		 }		 
	}
	
	private static Map<String, Map<String, Location[]>> DBTemplateMap = new Hashtable<String, Map<String, Location[]>>();
	private static String DBTemplateMapJson = null;
	private static Integer toInt(String col){
		Integer ret = 0;
		for (int i = 0; i < col.length(); ++i){
			ret +=  (col.charAt(i) - 'A' + 1) * zsys(('Z' - 'A' + 1), i);
		}
		return ret;
	}
	
	private static Integer zsys(Integer ds, int zs){
		Integer tmp = 1;
		for(int i = 0; i < zs; ++i){
			tmp *= ds;
		}
		return tmp;
	}
	
	private synchronized void loadTemplateXml(){
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime){
			templateXmlTime = time;
			DBTemplateMap.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();  
	        try  
	        {  
	            DocumentBuilder db = dbf.newDocumentBuilder();  
	            Document doc = db.parse(pathMapfile);  
	  
	            NodeList sheets = doc.getElementsByTagName("sheet");  
	            for (int i = 0; i < sheets.getLength(); i++)  
	            {  
	                Node sheet = sheets.item(i);  
	                parseSheet((Element) sheet);
	            } 
	            HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
						pathTemplate)));
	            Set<String> errorSet = new HashSet<String>();
		        for (String sheetName : DBTemplateMap.keySet()){
		        	if (null == workbook.getSheet(sheetName)){
		        		errorSet.add(sheetName);
		        	}
		        }
		        
		        for(String err : errorSet){
		        	DBTemplateMap.remove(err);
		        }
	        }  
	        catch (Exception e)  
	        {  
	            e.printStackTrace();  
	        }
	        
	        DBTemplateMapJson = JSONObject.fromObject(DBTemplateMap).toString();
		}
	}

	
	public DBPCJHXXTemplateExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	
	private String getLocMap(String ggxh){
		if (ggxh.length() > 2 && DBTemplateMap.containsKey(ggxh.substring(0, 3))) {
			return ggxh.substring(0, 3);
		} else if (ggxh.length() > 1 && DBTemplateMap.containsKey(ggxh.substring(0, 2))) {
			return ggxh.substring(0, 2);
		} else if (ggxh.length() > 0 && DBTemplateMap.containsKey(ggxh.substring(0, 1))) {
			return ggxh.substring(0, 1);
		} 
		return null;
	}
	
	public void exports() throws IOException {
		loadTemplateXml();
		VBAServiceParam param = new VBAServiceParam();
		param.setTemplate(DBTemplateMapJson);

		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		String fileName = new java.util.Date().getTime() + "_bp";
		File fTemp = File.createTempFile(fileName, ".xls");
		FileOutputStream fo = new FileOutputStream(fTemp);
		param.setTemplatePath(fTemp.getAbsolutePath());
		
		FileInputStream fi = new FileInputStream(new File(pathTemplate));
		
		//do copy
		byte[] buffer = new byte[1024];
		int size = -1;
	    while ((size = fi.read(buffer)) != -1) {
	    	fo.write(buffer, 0, size);
	    }
	    
		fi.close();
		fo.close();
		
		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));
		int count = workbook.getNumberOfSheets();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			String[] ret = new String[PcjhColumn.end.ordinal()];
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			if (null == ret[PcjhColumn.ggxh.ordinal()]
					|| ret[PcjhColumn.ggxh.ordinal()].isEmpty()) {
				System.out.println("row : " + i + "ggxh : " + ret[PcjhColumn.ggxh.ordinal()] + " could not find template.");
				continue;
			}
			
			String type = getLocMap(ret[PcjhColumn.ggxh.ordinal()]);
			if (null == type){
				continue;
			}

			Map<String, Location[]> locations = DBTemplateMap.get(type);
			if (null == locations){
				continue;
			}
			
			int index = workbook.getSheetIndex(type);
			if (index < 0){
				continue;
			}
			
			param.getData().add(ret);
		}
//			locations = DBTemplateMap.get(type);
//			sheet = workbook.getSheetAt(index);
//			
//			
//			if (sheet != null) {
//				updateTemplate(ret, locations, sheet);
//
//				try{
//					Calendar calTmp = Calendar.getInstance();
//					calTmp.setTime(Date.valueOf(ret[PcjhColumn.scrq.ordinal()]));
//					String tcrq = sheet.getRow(rq.getRow() - 1).getCell(toInt(rq.getCol()))
//							.getStringCellValue();
//
//					int rqPos = tcrq.indexOf("：");
//					tcrq = tcrq.substring(0, rqPos + 1);
//					tcrq = tcrq
//							.replace(" ", "")
//							.replace("投", "                                                          投");
//					tcrq += calTmp.get(Calendar.YEAR) + " 年 " + (calTmp.get(Calendar.MONTH) + 1) + "月 " + calTmp.get(Calendar.DAY_OF_MONTH) + "日";
//
//					sheet.getRow(rq.getRow()).getCell(toInt(rq.getCol())).setCellValue(tcrq);
//				} catch(Exception e){
//					String tcrq = sheet.getRow(rq.getRow()).getCell(toInt(rq.getCol()))
//							.getStringCellValue();
//					int rqPos = tcrq.indexOf("：");
//					tcrq = tcrq.substring(0, rqPos + 1);
//					tcrq = tcrq
//							.replace(" ", "")
//							.replace("投", "                                                          投");
//					tcrq += " 年  月  日";
//					sheet.getRow(rq.getRow()).getCell(toInt(rq.getCol())).setCellValue(tcrq);
//					e.printStackTrace();
//				}
//				
//				//if (!ret[PcjhColumn.tcbh.ordinal()].isEmpty()) {
//					Location[] locs = locations.get(PcjhColumn.tcbh.ordinal());
//					
//					if (null == locs || 0 == locs.length){
//						cells.getCells().get(0).add(index);
//						cells.getCells().get(1).add(2);
//						cells.getCells().get(2).add(2);
//					}else{
//						for(Location loc : locs){
//							cells.getCells().get(0).add(index);
//							cells.getCells().get(1).add(loc.getRow());
//							cells.getCells().get(2).add(toInt(loc.getCol()));
//						}
//					}
//				//}
//				
//				
//				
//				
//				FileOutputStream fs = new FileOutputStream(f);
//				workbook.write(fs);
//				fs.close();
//				f = null;
//				vbaExcel.runVBABarcode(JSONObject.fromObject(cells).toString(), UUID.randomUUID().toString());
//				
//				f = new File(cells.getPath());
//				FileInputStream fi = new FileInputStream(f);
////				 try {
////					opc = OPCPackage.open(fi);
////				} catch (InvalidFormatException e) {
////					// TODO Auto-generated catch block
////					e.printStackTrace();
////				}
//				workbook = new HSSFWorkbook(fi);
//				
////				workbook.cloneSheet(index);
//				cells.getCells().get(0).clear();
//				cells.getCells().get(1).clear();
//				cells.getCells().get(2).clear();
//			}
//		}
		
		vbaExcel.runVBABarcode(param.toJson(), UUID.randomUUID().toString());
	
//		f = new File(cells.getPath());
		
//		String fileName = new java.util.Date().getTime() + "_bp";
//		File f = File.createTempFile(fileName, ".xls");
//		cells.setPath(f.getAbsolutePath());
//		FileOutputStream fs = new FileOutputStream(f);
//		workbook.write(fs);
//		fs.close();
//		f = null;
//		VBAExcel ve = new VBAExcel();
//		ve.runVBABarcode(JSONObject.fromObject(cells).toString(), UUID.randomUUID().toString());
//		
//		f = new File(cells.getPath());
		fi = new FileInputStream(fTemp);
		workbook = new HSSFWorkbook(fi);
		for (int i = count - 1; i >= 0; --i){
			workbook.removeSheetAt(i);
		}
		workbook.write(os);
		fi.close();
//		FileInputStream fi = new FileInputStream(f);
//
//		byte[] buffer = new byte[1024];
//
//		int len = -1;
//	    while ((len = fi.read(buffer)) != -1) {
//        	os.write(buffer, 0, len);
//	    }
//		fi.close();
//		f.delete();

//		fi = new FileInputStream(fTemp);
//		size = -1;
//	    while ((size = fi.read(buffer)) != -1) {
//	    	os.write(buffer, 0, size);
//	    }
	}

//	private void updateTemplate(String[] ret, Map<String, Location[]> locations, HSSFSheet sheet) {
//		for(String field : locations.keySet()){
//			int index = field.indexOf('#');
//			index = Integer.valueOf(field.substring(index) + 1);
//			Location[] locs = locations.get(field);
//			for (int i = 0; i < locs.length; ++i){
//				if (null != locs[i]){
//					sheet.getRow(locs[i].getRow()).getCell(toInt(locs[i].getCol())).setCellValue(ret[index]);
//				}
//			}
//		}
//	}

}
