package com.BlueRay.mutton.service;

import com.BlueRay.mutton.controller.PageData;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;


public interface SaleService{
	//String[][] query(String approveType, String approved);

	boolean update();

	String add(JSONArray ja) throws Exception;

	String delete(JSONArray ja);

	String update(JSONArray rows, JSONArray data);

	String businessApprove(JSONArray rows);

	String planApprove(JSONArray rows);

	String businessUnapprove(JSONArray rows);

	String planUnapprove(JSONArray rows);

//	PageData pageQuery(String approveType, String approved, Integer pagesize,
//			Integer pagenum, Integer pagecount, Integer colIndex, Boolean sort);
//
//	PageData pageSearch(String approveType, String approved, Integer pagesize,
//			Integer pagenum, Integer pagecount, Integer colIndex, Boolean sort,
//			String keyword);
//
//	PageData pageSearch(String approveType, String approved, Integer pagesize,
//			Integer pagenum, Integer pagecount, Integer colIndex, Boolean sort,
//			JSONArray keyWords);
//
//	PageData pageQuery(String approveType, String approved, Integer pagesize,
//			Integer pagenum, Integer pagecount);
//
//	PageData pageQuery(String approveType, String approved, Integer pagesize,
//			Integer pagenum, Integer pagecount, JSONObject jparam);

	PageData pageQuery(Integer pagesize, Integer pagenum, Integer pagecount,
			JSONObject jparam);
}
