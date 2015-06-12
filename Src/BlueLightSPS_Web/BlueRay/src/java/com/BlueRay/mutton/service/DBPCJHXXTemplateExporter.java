package com.BlueRay.mutton.service;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.net.URISyntaxException;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.w3c.dom.Node;

import javax.imageio.ImageIO;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.poi.hssf.usermodel.HSSFClientAnchor;
import org.apache.poi.hssf.usermodel.HSSFPatriarch;
import org.apache.poi.hssf.usermodel.HSSFPicture;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.jbarcode.JBarcode;
import org.jbarcode.encode.Code11Encoder;
import org.jbarcode.encode.Code128Encoder;
import org.jbarcode.encode.Code39Encoder;
import org.jbarcode.encode.EAN13Encoder;
import org.jbarcode.encode.InvalidAtributeException;
import org.jbarcode.encode.UPCAEncoder;
import org.jbarcode.encode.UPCEEncoder;
import org.jbarcode.paint.BaseLineTextPainter;
import org.jbarcode.paint.EAN13TextPainter;
import org.jbarcode.paint.UPCATextPainter;
import org.jbarcode.paint.UPCETextPainter;
import org.jbarcode.paint.WideRatioCodedPainter;
import org.jbarcode.paint.WidthCodedPainter;
import org.jbarcode.util.ImageUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.service.vba.VBAExcel;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;
import com.BlueRay.mutton.tool.PoiUtil;

public class DBPCJHXXTemplateExporter implements IExcelExporter<PCJHXX> {

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
			String basePath = new URI(DBPCJHXXTemplateExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template.xls";
			pathMapfile = basePath + "META-INF/template.xml";
			
			System.out.println(pathTemplate);
		} catch (Exception e) {
			// TODO Auto-generated catch block
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
	

	final static Location mSLocs[] = new Location[PcjhColumn.end.ordinal()];
	final static Location mULocs[] = new Location[PcjhColumn.end.ordinal()];
	final static Location mYLocs[] = new Location[PcjhColumn.end.ordinal()];
	final static Location mTALocs[] = new Location[PcjhColumn.end.ordinal()];
	final static Location mVLocs[] = new Location[PcjhColumn.end.ordinal()];
	final static Location mLLocs[] = new Location[PcjhColumn.end.ordinal()];
	

	private static Set<String> getNames(NodeList names) {
		Set<String> nameSet = new HashSet<String>();
		for (int i = 0; i < names.getLength(); i++) {
			nameSet.add(names.item(i).getFirstChild()
					.getNodeValue());
		}
		return nameSet;
	}
	
	
	private static void parseCellMap(Map<Integer, Location[]> locations, Element field){
		String val = field.getAttribute("name");
		PcjhColumn col = null;
		try{
			col = PcjhColumn.valueOf(val);
			NodeList cells = field.getElementsByTagName("cell");
			if (cells.getLength() > 0){
				Location locs[] = new Location[cells.getLength()];
				locations.put(col.ordinal(), locs);
				 for (int i = 0; i < cells.getLength(); i++)  
		         {
					 Element cell = (Element) cells.item(i);
					 try{
						 locs[i] = new Location(
								 cell.getAttribute("col").charAt(0),
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
		 Map<Integer, Location[]> locations = new HashMap<Integer, Location[]>();
		 
		 for (int i = 0; i < fields.getLength(); i++)  
         {
			 parseCellMap(locations, (Element) fields.item(i));
         }
		 
		 for(String name: names){
			 DBTemplateMap.put(name, locations);
		 }		 
	}
	
	private static Map<String, Map<Integer, Location[]>> DBTemplateMap = new HashMap<String, Map<Integer, Location[]>>();
	static{
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
        }  
        catch (Exception e)  
        {  
            e.printStackTrace();  
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
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));
		String[] ret = new String[PcjhColumn.end.ordinal()];
		Location rq = new Location('A', 2);
		int count = workbook.getNumberOfSheets();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			if (null == ret[PcjhColumn.ggxh.ordinal()]
					|| ret[PcjhColumn.ggxh.ordinal()].isEmpty()) {
				System.out.println("row : " + i + "ggxh : " + ret[PcjhColumn.ggxh.ordinal()] + " could not find template.");
				continue;
			}

			Map<Integer, Location[]> locations;
			HSSFSheet sheet = null;
			String type = getLocMap(ret[PcjhColumn.ggxh.ordinal()]);
			if (null == type){
				continue;
			}
			
			int index = workbook.getSheetIndex(type);
			sheet = workbook.cloneSheet(index);
			locations = DBTemplateMap.get(type);

			
			if (sheet != null) {
				updateTemplate(ret, locations, sheet);

				try{
					Calendar calTmp = Calendar.getInstance();
					calTmp.setTime(Date.valueOf(ret[PcjhColumn.scrq.ordinal()]));
					String tcrq = sheet.getRow(rq.getX()).getCell(rq.getY())
							.getStringCellValue();

					tcrq = tcrq.replace(" ", "")
							.replace("投", "                                                          投")
							.replace("年", " " + calTmp.get(Calendar.YEAR) + "年")
							.replace("月日", " " + (calTmp.get(Calendar.MONTH) + 1) + "月" + " " + calTmp.get(Calendar.DAY_OF_MONTH) + "日");
					sheet.getRow(rq.getX()).getCell(rq.getY()).setCellValue(tcrq);
				} catch(Exception e){
					e.printStackTrace();
				}
				
				if (!ret[PcjhColumn.tcbh.ordinal()].isEmpty()) {

					JBarcode localJBarcode = new JBarcode(
							Code128Encoder.getInstance(),
							WidthCodedPainter.getInstance(),
							BaseLineTextPainter.getInstance());

					localJBarcode.setShowCheckDigit(false);

					BufferedImage localBufferedImage;
					try {
						localBufferedImage = localJBarcode
								.createBarcode(ret[PcjhColumn.tcbh.ordinal()]);
						ByteArrayOutputStream byteArrayOut = new ByteArrayOutputStream();

						 ImageUtil.encodeAndWrite(localBufferedImage,
						 ImageUtil.PNG, byteArrayOut, 96, 96);

						// 画图的顶级管理器，一个sheet只能获取一个（一定要注意这点）
						HSSFPatriarch patriarch = sheet.createDrawingPatriarch();
						
						// anchor主要用于设置图片的属性
						HSSFClientAnchor anchor = PoiUtil.measureAnchor(
								13, 2, 5, 7, 
								localBufferedImage.getWidth(), 
								localBufferedImage.getHeight(), 
								sheet, 
								workbook);
								
//								new HSSFClientAnchor(200, 100,
//								1000, 200, (short) 14, 2, (short) 17, 5);
						anchor.setAnchorType(HSSFClientAnchor.DONT_MOVE_AND_RESIZE);
						
						// 插入图片
						HSSFPicture pic = patriarch.createPicture(
								anchor,
								workbook.addPicture(byteArrayOut.toByteArray(),
										HSSFWorkbook.PICTURE_TYPE_PNG));
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				// ImageUtil.encodeAndWrite(localBufferedImage, ImageUtil.PNG,
				// arg2);

			}
		}
		
		for (int i = count - 1; i >= 0; --i){
			workbook.removeSheetAt(i);
		}
		
		String fileName = new java.util.Date().getTime() + "_bp";
		File f = File.createTempFile(fileName, ".xls");
		
		FileOutputStream fs = new FileOutputStream(f);
		workbook.write(fs);
		
		VBAExcel ve = new VBAExcel();
		
		f.delete();
	}

	private void updateTemplate(String[] ret, Map<Integer, Location[]> locations, HSSFSheet sheet) {
		for(Integer field : locations.keySet()){
			Location[] locs = locations.get(field);
			for (int i = 0; i < locs.length; ++i){
				if (null != locs[i]){
					sheet.getRow(locs[i].getX()).getCell(locs[i].getY()).setCellValue(ret[field]);
				}
			}
		}
	}

}
