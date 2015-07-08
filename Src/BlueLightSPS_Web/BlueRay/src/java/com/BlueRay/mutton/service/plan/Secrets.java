package com.BlueRay.mutton.service.plan;

import java.io.File;
import java.net.URI;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;

public class Secrets{

	private static String pathSecretsfile = null;
	static 
	{
		try {
			String basePath = new URI(Secrets.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathSecretsfile = basePath + "META-INF/secrets.xml";
			
			System.out.println(pathSecretsfile);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static long templateXmlTime = 0;
	private static String psw = "";

	
	private static synchronized String loadTemplateXml(){
		long time = new File(pathSecretsfile).lastModified();
		if (time != templateXmlTime){
			templateXmlTime = time;

			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();  
	        try  
	        {  
	            DocumentBuilder db = dbf.newDocumentBuilder();  
	            Document doc = db.parse(pathSecretsfile);  
	            psw = doc.getElementsByTagName("secret").item(0).getFirstChild().getNodeValue();
	        }  
	        catch (Exception e)  
	        {  
	            e.printStackTrace();  
	        }
		}
		return psw;
	}
	
	public static String getSecret(){
		return loadTemplateXml();
	}

}
