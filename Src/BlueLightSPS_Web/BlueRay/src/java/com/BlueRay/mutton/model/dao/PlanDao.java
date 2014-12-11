package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.PCJHXX;

public interface PlanDao {

//	List<PCJHXX> getPcjhxx();

	void insert(PCJHXX pcjhxx);

	PCJHXX getDataById(int id);

	void update(PCJHXX pcjhxx);

	void delete(PCJHXX pcjhxx);

	List<PCJHXX> getPcjhxx(String approveType, String approved);

}
