package com.BlueRay.mutton.service;

import java.util.List;

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
		saleDao.insert(bxx);
		return false;
	}

}
