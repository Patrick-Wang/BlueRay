package com.BlueRay.mutton.service.plan.exporter.zxd.config;

import java.io.File;
import java.net.URI;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import com.BlueRay.mutton.service.plan.exporter.zzgzk.DBPCJHXXTemplateZzgzkExporter;

public class ConfigurationFactory {
	private static String pathTemplate = null;
	private static String pathMapfile = null;
	private static long templateXmlTime = 0;
	
	static {
		try {
			String basePath = new URI(DBPCJHXXTemplateZzgzkExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template_zxd.xls";
			pathMapfile = basePath + "META-INF/template_zxd.xml";
			System.out.println(pathTemplate);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static EnglishConfiguration englishConfig;
	private static GrSTAUConfiguration grSTAUConfig;
	private static GrYConfiguration grYConfig;
	private static WksConfiguration wksConfig;
	private static XdConfiguration xdConfig;
	private static UsualConfiguration usualConfig;
	private static ZjydConfiguration zjydConfig;

	private static Element getFirstElement(NodeList list) {
		if (list.getLength() > 0) {
			return (Element) list.item(0);
		}
		return null;
	}

	private static synchronized void loadTemplateXml() {
		long time = new File(pathMapfile).lastModified();
		if (time != templateXmlTime) {
			templateXmlTime = time;
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			try {
				DocumentBuilder db = dbf.newDocumentBuilder();
				Document doc = db.parse(pathMapfile);
				Element eSheet = getFirstElement(doc
						.getElementsByTagName("sheet_english"));
				if (eSheet != null) {
					englishConfig = new EnglishConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc
						.getElementsByTagName("sheet_gr_S_TA_U"));
				if (eSheet != null) {
					grSTAUConfig = new GrSTAUConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc.getElementsByTagName("sheet_gr_Y"));
				if (eSheet != null) {
					grYConfig = new GrYConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc.getElementsByTagName("sheet_wks"));
				if (eSheet != null) {
					wksConfig = new WksConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc.getElementsByTagName("sheet_xd"));
				if (eSheet != null) {
					xdConfig = new XdConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc
						.getElementsByTagName("sheet_usual"));
				if (eSheet != null) {
					usualConfig = new UsualConfiguration(eSheet);
				}
				eSheet = getFirstElement(doc.getElementsByTagName("sheet_zjyd"));
				if (eSheet != null) {
					zjydConfig = new ZjydConfiguration(eSheet);
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

	public ConfigurationFactory(){
		loadTemplateXml();
	}
	
	public String getPathTemplate() {
		return pathTemplate;
	}

	public long getTemplateXmlTime() {
		return templateXmlTime;
	}

	public EnglishConfiguration getEnglishConfiguration() {
		return englishConfig;
	}

	public GrSTAUConfiguration getGrSTAUConfiguration() {
		return grSTAUConfig;
	}

	public GrYConfiguration getGrYConfiguration() {
		return grYConfig;
	}

	public WksConfiguration getWksConfiguration() {
		return wksConfig;
	}

	public XdConfiguration getXdConfiguration() {
		return xdConfig;
	}

	public UsualConfiguration getUsualConfiguration() {
		return usualConfig;
	}

	public ZjydConfiguration getZjydConfiguration() {
		return zjydConfig;
	}

}
