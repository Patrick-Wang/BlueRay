package com.BlueRay.mutton.model.dao;

import java.util.List;

import net.sf.json.JSONObject;

import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;

public interface PlanDao {

	void insert(PCJHXX pcjhxx);

	PCJHXX getDataById(int id);

	List<PCJHXX> getDateByHtxxId(int id);
	
	void update(PCJHXX pcjhxx);

	void delete(PCJHXX pcjhxx);

	List<PCJHXX> getPcjhxx(String approveType, String approved);

	AbstractExcel<PCJHXX> getPcjhExcel(String col, boolean asc);

	PCJHXX getPlanDataByTcbh(String tcbh);

	PCJHXX getPlanDataByCcbh(String ccbh);

	List<PCJHXX> getPlanData(Integer pagesize, Integer pagenum,
			Integer pagecount, JSONObject jparam, IAdvanceTranslator translator);

	int getPlanDataCount(JSONObject jparam, IAdvanceTranslator translator);
}
