package com.BlueRay.mutton.service.plan.exporter.zdqpq;

import java.io.File;
import java.net.URI;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.service.plan.exporter.ConfigurationUtil;

public class Configuration {
	
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
	private static Map<Integer, List<Location>> locsMapZdq = new Hashtable<Integer, List<Location>>();
	private static Map<Integer, List<Location>> locsMapPq = new Hashtable<Integer, List<Location>>();
	private static String templateZdqName;
	private static String templatePqName;
	
	private static synchronized void loadTemplateXml() {
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime) {
			templateXmlTime = time;
			locsMapZdq.clear();
			locsMapPq.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			try {
				DocumentBuilder db = dbf.newDocumentBuilder();
				Document doc = db.parse(pathMapfile);
				Element eSheetZdq = (Element) doc.getElementsByTagName("sheet_zdqzpPlan").item(0);
				Element eSheetPq = (Element) doc.getElementsByTagName("sheet_pqPlan").item(0);
				
				ConfigurationUtil.loadLocation(locsMapZdq, eSheetZdq, jhxdrq, "jhxdrq");
				ConfigurationUtil.loadLocation(locsMapZdq, eSheetZdq, zs, "zs");
				ConfigurationUtil.loadLocationMultiCell(locsMapZdq, eSheetZdq, xh, "xh");
				baseRowZdq = ConfigurationUtil.getBaseRow(eSheetZdq);
				ConfigurationUtil.loadTableFields(locsMapZdq, eSheetZdq);
				templateZdqName = ConfigurationUtil.getSheetName(eSheetZdq);
				
				ConfigurationUtil.loadLocation(locsMapPq, eSheetPq, jhxdrq, "jhxdrq");
				ConfigurationUtil.loadLocation(locsMapPq, eSheetPq, zs, "zs");
				ConfigurationUtil.loadLocationMultiCell(locsMapPq, eSheetPq, xh, "xh");
				baseRowPq = ConfigurationUtil.getBaseRow(eSheetPq);
				ConfigurationUtil.loadTableFields(locsMapPq, eSheetPq);
				templatePqName = ConfigurationUtil.getSheetName(eSheetPq);
				
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	public Configuration(){
		loadTemplateXml();
	}

	public String getZdqTemplateName(){
		return templateZdqName;
	}
	
	public String getPqTemplateName(){
		return templatePqName;
	}
	
	public String getTemplatePath(){
		return pathTemplate;
	}
	
	public boolean containsZdqField(int col){
		return locsMapZdq.containsKey(col);
	}
	
	public boolean containsPqField(int col){
		return locsMapPq.containsKey(col);
	}
	
	public List<Location> getZdqField(int col){
		return locsMapZdq.get(col);
	}
	
	public List<Location> getPqField(int col){
		return locsMapPq.get(col);
	}
	
	public int getZdqBaseRow(){
		return baseRowZdq;
	}
	
	public int getPqBaseRow(){
		return baseRowPq;
	}
	
	public Location getZdqJhxdrq(){
		if (locsMapZdq.containsKey(jhxdrq)){
			return locsMapZdq.get(jhxdrq).get(0);
		}
		return null;
	}
	
	public Location getPqJhxdrq(){
		if (locsMapPq.containsKey(jhxdrq)){
			return locsMapPq.get(jhxdrq).get(0);
		}
		return null;
	}
	
	public Location getZdqZs(){
		if (locsMapZdq.containsKey(zs)){
			return locsMapZdq.get(zs).get(0);
		}
		return null;
	}
	
	public Location getPqZs(){
		if (locsMapPq.containsKey(zs)){
			return locsMapPq.get(zs).get(0);
		}
		return null;
	}
	
	public List<Location> getZdqXh(){
		return locsMapZdq.get(xh);
	}
	
	public List<Location> getPqXh(){
		return locsMapPq.get(xh);
	}
}
