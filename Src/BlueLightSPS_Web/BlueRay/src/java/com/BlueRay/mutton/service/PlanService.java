package com.BlueRay.mutton.service;

import net.sf.json.JSONArray;

public interface PlanService {

	String[][] query();

	String update(JSONArray rows, JSONArray data);

}
