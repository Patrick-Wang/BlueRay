package com.BlueRay.mutton.service;

import net.sf.json.JSONArray;


public interface SaleService{
	String[][] query();

	boolean update();

	String add(JSONArray ja);

	String delete(JSONArray ja);
}
