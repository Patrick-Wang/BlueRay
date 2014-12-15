package com.BlueRay.mutton.service;

import net.sf.json.JSONArray;

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

}
