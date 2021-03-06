package com.BlueRay.mutton.service.plan;

import java.io.OutputStream;
import java.util.Date;

import javax.servlet.ServletOutputStream;

import com.BlueRay.mutton.common.PageData;
import com.BlueRay.mutton.model.dao.IAdvanceTranslator;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

public interface PlanService {

	String[][] query(String approveType, String approved);

	String update(JSONArray rows, JSONArray data);

	String businessApprove(JSONArray rows);

	String planApprove(JSONArray rows);

	String packBusinessApprove(JSONArray rows);

	String packPlanApprove(JSONArray rows);

	String businessUnapprove(JSONArray rows);

	String planUnapprove(JSONArray rows);

	String packBusinessUnapprove(JSONArray rows);

	String packPlanUnapprove(JSONArray rows);

	String validate(String item, String value);

	PageData pageQuery(Integer pagesize, Integer pagenum, Integer pagecount,
			JSONObject jparam);

	String export(OutputStream out, JSONObject jquery);

	String templateExport(OutputStream out, JSONObject jquery);

	String getBh(String item, String zzs, java.sql.Date date);

	String bzjhtemplateExport(OutputStream out, JSONObject jquery);

	void resetCcSerialNumber(Integer zzsId);

	void resetTcSerialNumber(Integer zzsId);

	String scjhtemplateExport(OutputStream out, JSONObject jquery);

	String zzjhtemplateExport(OutputStream out, JSONObject jquery);

	String zzgzktemplateExport(OutputStream out, JSONObject jquery);

	String zdqPqtemplateExport(OutputStream out, JSONObject jquery);

	String zxdtemplateExport(OutputStream out, JSONObject jquery);

}
