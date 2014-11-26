package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;

public interface SaleDao {
	List<HTXX> getSaleData();

	void insert(HTXX bxx);
	
	void del(HTXX htxx);
}
