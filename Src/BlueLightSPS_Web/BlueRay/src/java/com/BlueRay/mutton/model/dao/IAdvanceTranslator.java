package com.BlueRay.mutton.model.dao;

import java.util.HashMap;
import java.util.Map;

import net.sf.json.JSONArray;

public abstract class IAdvanceTranslator{
	protected Map<String, String> inMap = new HashMap<String, String>();
	public IAdvanceTranslator(){
		inMap.put("是", "Y");
		inMap.put("√", "Y");
		inMap.put("否", "N");
		inMap.put("×", "N");
	}
	
	public abstract String out(String colName, String value);
	public abstract String in(String colName, String value);
}