package com.vbarunner;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import com.BlueRay.mutton.service.Location;

public class VBAServiceParam {
	String template;
	String templatePath;
	List<String[]> data = new ArrayList<String[]>();
	
	/**
	 * @return the templatePath
	 */
	public String getTemplatePath() {
		return templatePath;
	}
	/**
	 * @return the data
	 */
	public List<String[]> getData() {
		return data;
	}
	
	/**
	 * @return the template
	 */
	public String getTemplate() {
		return template;
	}
	/**
	 * @param template the template to set
	 */
	public void setTemplate(String jsonTemplate) {
		this.template = jsonTemplate;
	}
	/**
	 * @param templatePath the templatePath to set
	 */
	public void setTemplatePath(String templatePath) {
		this.templatePath = templatePath;
	}
	/**
	 * @param data the data to set
	 */
	public void setData(List<String[]> data) {
		this.data = data;
	}
	
	public String toJson(){
		return "{\"template\":" + template + "," +
				"\"templatePath\":\"" + templatePath.replace("\\", "\\\\") + "\"," +
				"\"data\":" + JSONArray.fromObject(data).toString() + "}";
	}
}
