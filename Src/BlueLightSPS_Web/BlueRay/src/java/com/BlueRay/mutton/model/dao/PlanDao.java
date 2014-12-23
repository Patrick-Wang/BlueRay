package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.excel.DBPCJHXXExcel;
import com.BlueRay.mutton.tool.AbstractExcel;

public interface PlanDao {

//	List<PCJHXX> getPcjhxx();

	void insert(PCJHXX pcjhxx);

	PCJHXX getDataById(int id);

	
	List<PCJHXX> getDateByHtxxId(int id);
	
	void update(PCJHXX pcjhxx);

	void delete(PCJHXX pcjhxx);

	List<PCJHXX> getPcjhxx(String approveType, String approved);

	AbstractExcel<PCJHXX> getPcjhExcel(String col, boolean asc);

	PCJHXX getPlanDataByTcbh(String tcbh);

	PCJHXX getPlanDataByCcbh(String ccbh);
}
