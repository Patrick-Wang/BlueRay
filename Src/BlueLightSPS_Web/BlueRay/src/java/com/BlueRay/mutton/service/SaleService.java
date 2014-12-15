package com.BlueRay.mutton.service;

import net.sf.json.JSONArray;


public interface SaleService{
	String[][] query(String approveType, String approved);

	boolean update();

	String add(JSONArray ja) throws Exception;

	String delete(JSONArray ja);

	String update(JSONArray rows, JSONArray data);

	String businessApprove(JSONArray rows);

	String planApprove(JSONArray rows);

	String businessUnapprove(JSONArray rows);

	String planUnapprove(JSONArray rows);
}
