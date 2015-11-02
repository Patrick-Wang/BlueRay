package com.BlueRay.mutton.service.plan.exporter.zzjh;

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
			String basePath = new URI(DBPCJHXXTemplateZzjhExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_zzjh.xls";
			pathMapfile = basePath + "META-INF/template_zzjh.xml";
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private final static int jhxdrq = -1;
	private final static int zs = -2;
	private final static int xh = -3;
	private final static int wldm = -4;
	private final static int mc = -5;
	private final static int gg = -6;
	private final static int zjdm = -7;

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
				ConfigurationUtil.loadLocation(locsMap, doc.getDocumentElement(), jhxdrq, "jhxdrq");
				ConfigurationUtil.loadLocation(locsMap, doc.getDocumentElement(), zs, "zs");
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), xh, "xh");
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), wldm, "wldm");
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), mc, "mc");
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), gg, "gg");
				ConfigurationUtil.loadLocationMultiCell(locsMap, doc.getDocumentElement(), zjdm, "zjdm");

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
	
	public Location getJhxdrq(){
		if (locsMap.containsKey(jhxdrq)){
			return locsMap.get(jhxdrq).get(0);
		}
		return null;
	}
	
	public Location getZs(){
		if (locsMap.containsKey(zs)){
			return locsMap.get(zs).get(0);
		}
		return null;
	}
	
	public List<Location> getXh(){
		return locsMap.get(xh);
	}
	
	public List<Location> getWldm(){
		return locsMap.get(wldm);
	}
	
	public List<Location> getMc(){
		return locsMap.get(mc);
	}
	
	public List<Location> getGg(){
		return locsMap.get(gg);
	}
	
	public List<Location> getZjdm(){
		return locsMap.get(zjdm);
	}
}
