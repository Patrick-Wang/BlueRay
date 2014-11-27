package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;

public interface SaleDao {
	List<HTXX> getSaleData();

	HTXX getSaleDataById(int id);

	void insert(HTXX htxx);

	void del(HTXX htxx);

	void update(HTXX htxx);
}
