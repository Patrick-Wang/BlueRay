package com.BlueRay.mutton.service;

import java.io.OutputStream;

import com.BlueRay.mutton.controller.ImportResult;
import com.BlueRay.mutton.controller.PageData;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;


public interface SaleService{

	boolean update();

	String add(JSONArray ja) throws Exception;

	String delete(JSONArray ja);

	String update(JSONArray rows, JSONArray data);

	String businessApprove(JSONArray rows);

	String planApprove(JSONArray rows);

	String businessUnapprove(JSONArray rows);

	String planUnapprove(JSONArray rows);

	PageData pageQuery(Integer pagesize, Integer pagenum, Integer pagecount,
			JSONObject jparam);

	String export(OutputStream out, JSONObject jparam);

	ImportResult importData(JSONArray fromObject);
	
	boolean isHtidExist(String id);

	void upgradeGgxh();
}
