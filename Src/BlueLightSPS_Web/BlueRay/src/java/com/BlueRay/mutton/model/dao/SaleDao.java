package com.BlueRay.mutton.model.dao;

import java.util.List;

import net.sf.json.JSONArray;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;

public interface SaleDao {
//	List<HTXX> getSaleData();

	HTXX getSaleDataById(int id);
	
	void insert(HTXX htxx);

	void del(HTXX htxx);

	void update(HTXX htxx);

	List<HTXX> getSaleData(String approveType, String approved);

	List<HTXX> getSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			Integer col, Boolean sort);

	int getSaleDataCount();

	List<HTXX> getSearchedSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			Integer colIndex, Boolean sort, String keyword);

	List<HTXX> getSearchedSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			Integer colIndex, Boolean sort, JSONArray keyWords);
}
