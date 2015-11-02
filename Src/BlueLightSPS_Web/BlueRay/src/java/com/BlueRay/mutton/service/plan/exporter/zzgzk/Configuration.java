package com.BlueRay.mutton.service.plan.exporter.zzgzk;

import java.io.File;
import java.net.URI;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.service.plan.exporter.ConfigurationUtil;

public class Configuration {
	
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
	private static Map<Integer, List<Location>> locsMap = new Hashtable<Integer, List<Location>>();

	
	private static synchronized void loadTemplateXml() {
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime) {
			templateXmlTime = time;
			locsMap.clear();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			try {
				DocumentBuilder db = dbf.newDocumentBuilder();
				Document doc = db.parse(pathMapfile);
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), xh, "xh");
				baseRow = ConfigurationUtil.getBaseRow(doc.getDocumentElement());
				ConfigurationUtil.loadTableFields(locsMap, doc.getDocumentElement());
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

	
	public Configuration(){
		loadTemplateXml();
	}
	
	public String getTemplatePath(){
		return pathTemplate;
	}
	
	public boolean containsField(int col){
		return locsMap.containsKey(col);
	}
	
	public List<Location> getField(int col){
		return locsMap.get(col);
	}
	
	public int getBaseRow(){
		return baseRow;
	}
		
	public List<Location> getXh(){
		return locsMap.get(xh);
	}
}
