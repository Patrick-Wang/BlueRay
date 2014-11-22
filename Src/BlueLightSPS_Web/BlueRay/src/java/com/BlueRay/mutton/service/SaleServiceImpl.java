package com.BlueRay.mutton.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;

@Service
@Transactional("transactionManager")
public class SaleServiceImpl implements SaleService {
	
	@Autowired
	private SaleDao saleDao;
	
	public String[][] query() {
		List<BMQXHFLXX> rets = saleDao.getSaleData();
		
		String[][] ret = new String[][]{
				{rets.get(0).getBmqxhID() + "", rets.get(0).getBmqxh()}
		};
		
		return ret;
	}

	public boolean update() {
		BMQXHFLXX bxx = new BMQXHFLXX();
		bxx.setBmqxh("asdf");
		bxx.setBmqxhID(12);
		saleDao.insert(bxx);
		return false;
	}

}
