package com.BlueRay.mutton.service;

import java.sql.Date;
import java.util.List;

import net.sf.json.JSONArray;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;

@Service
@Transactional("transactionManager")
public class SaleServiceImpl implements SaleService {
	
	@Autowired
	private SaleDao saleDao;
	
	public String[][] query() {
		List<HTXX> list = saleDao.getSaleData();
		//"合同号", "客户名称", "规格型号", 
		//"数量", "轴承", "单复绕", 
		//"制动器电压", "曳引轮规格", "机房", 
		//"变频器型号", "编码器型号", "电缆长度", 
		//"闸线长度", "铭牌等资料", "备注", 
		//"订单日期", "审核-业务", "审核-计划"
		String[][] ret = new String[list.size()][19];
		HTXX htxx = null;
		for (int i = 0; i < list.size(); ++i){
			htxx = list.get(i);
			ret[i][0] = htxx.getID() + "";
			
			ret[i][1] = htxx.getHtID();
			ret[i][2] = htxx.getClientID();
			ret[i][3] = htxx.getGgxhID();
			
			ret[i][4] = htxx.getSl() + "";
			ret[i][5] = htxx.getZcID();
			ret[i][6] = htxx.getDfr();
			
			ret[i][7] = htxx.getZdqdyID();
			ret[i][8] = htxx.getYylggID();
			ret[i][9] = htxx.getSfjf();
			
			ret[i][10] = htxx.getBpqxhID();
			ret[i][11] = htxx.getBmqxhID();
			ret[i][12] = htxx.getDlcd();
			
			ret[i][13] = htxx.getZxcd();
			ret[i][14] = htxx.getMpzl();
			ret[i][15] = htxx.getBz();
			
			ret[i][16] = htxx.getDdrq() + "";
			ret[i][17] = htxx.getSftgywsh();
			ret[i][18] = htxx.getSftgjhsh();
			//ret[i][17] = htxx.getDdzt();
			
		}
		return ret;
	}

	public boolean update() {
		BMQXHFLXX bxx = new BMQXHFLXX();
		bxx.setBmqxh("asdf");
		bxx.setBmqxhID(12);
		//saleDao.insert(bxx);
		return false;
	}

	public String add(JSONArray ja) {
		HTXX htxx = new HTXX();
		
		htxx.setHtID(ja.getString(0));
		htxx.setClientID(ja.getString(1));
		htxx.setGgxhID(ja.getString(2));
		if (!"".equals(ja.getString(3))){
			htxx.setSl(Integer.valueOf(ja.getString(3)));
		}
		htxx.setZcID(ja.getString(4));
		htxx.setDfr(ja.getString(5));

		htxx.setZdqdyID(ja.getString(6));
		htxx.setYylggID(ja.getString(7));
		htxx.setSfjf(ja.getString(8));

		htxx.setBpqxhID(ja.getString(9));
		htxx.setBmqxhID(ja.getString(10));
		htxx.setDlcd(ja.getString(11));

		htxx.setZxcd(ja.getString(12));
		htxx.setMpzl(ja.getString(13));
		htxx.setBz(ja.getString(14));
		if (!"".equals(ja.getString(3))){
			htxx.setDdrq(Date.valueOf(ja.getString(15)));
		}
//		htxx.setSftgywsh(ja.getString(16));
//		htxx.setSftgjhsh(ja.getString(17));

		saleDao.insert(htxx);
		return htxx.getID() + "";
	}

	public String delete(JSONArray ja) {
		HTXX htxx = new HTXX();
		for (int i = 0; i < ja.size(); ++i){
			htxx.setID(Integer.valueOf(ja.getString(i)));
			saleDao.del(htxx);
		}
		
		return "";
	}

}
