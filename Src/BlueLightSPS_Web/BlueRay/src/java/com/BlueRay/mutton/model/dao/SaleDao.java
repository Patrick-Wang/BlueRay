package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;

public interface SaleDao {
	List<BMQXHFLXX> getSaleData();

	void insert(BMQXHFLXX bxx);
}
