package com.BlueRay.mutton.service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;

@Service
@Transactional("transactionManager")
public class PlanServiceImpl implements PlanService{

	@Autowired
	PlanDao planDao;

	@Autowired
	private SaleDao saleDao;
	
	public String[][] query() {
		
		List<PCJHXX> pcxxs = planDao.getPcjhxx();
		String[][] ret = new String[pcxxs.size()][25];
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
		Integer id;
		for (PCJHXX pcjhxx : pcxxs){
			if (null != pcjhxx){
				id = pcjhxx.getHtxxID();
				if (!htxxMap.containsKey(id)){
					htxxMap.put(id, saleDao.getSaleDataById(id));
				}
				if (htxxMap.get(id) != null){
					SaleServiceImpl.setHtxx(row, htxx, itDao);
				}
				
			}
		}
		return null;
	}



}
