package com.BlueRay.mutton.service;

import java.sql.Date;
import java.util.List;

import net.sf.json.JSONArray;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

@Service
@Transactional("transactionManager")
public class SaleServiceImpl implements SaleService {
	
	@Autowired
	private SaleDao saleDao;
	
	@Autowired
	private ItemDao itemDao;
	
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
			try{
				ret[i][0] = htxx.getID() + "";
				
				ret[i][1] = htxx.getHtID() + "";
				ret[i][2] = itemDao.queryKhxxById(htxx.getClientID()).getKhmc();
				ret[i][3] = itemDao.queryCpggxhxxById(htxx.getGgxhID()).getGg();
				
				ret[i][4] = htxx.getSl() + "";
				ret[i][5] = itemDao.queryZcxxById(htxx.getZcID()).getZcxh();
				ret[i][6] = htxx.getDfr();
				
				ret[i][7] = itemDao.queryZdqdyflxxById(htxx.getZdqdyID()).getZdqdy();
				ret[i][8] = itemDao.queryYylggflxxById(htxx.getYylggID()).getYylgg();
				ret[i][9] = htxx.getSfjf();
				
				ret[i][10] = itemDao.queryBpqxhflxxById(htxx.getBpqxhID()).getBpqxh();
				ret[i][11] = itemDao.queryBmqxhflxxById(htxx.getBmqxhID()).getBmqxh();
				ret[i][12] = htxx.getDlcd();
				
				ret[i][13] = htxx.getZxcd();
				ret[i][14] = htxx.getMpzl();
				ret[i][15] = htxx.getBz();
				
				ret[i][16] = htxx.getDdrq() + "";
				ret[i][17] = htxx.getSftgywsh();
				ret[i][18] = htxx.getSftgjhsh();
			}
			catch (Exception e){
				
			}
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


	public String add(JSONArray ja) throws Exception {
		HTXX htxx = new HTXX();
		setHtID(htxx, ja.getString(0));
		setClientID(htxx,  ja.getString(1));
		setGgxhID(htxx,  ja.getString(2));
		setSl(htxx,  ja.getString(3));
		setZcID(htxx,  ja.getString(4));
		setDfr(htxx,  ja.getString(5));
		setZdqdyID(htxx,  ja.getString(6));
		setYylggID(htxx,  ja.getString(7));
		setSfjf(htxx,  ja.getString(8));
		setBpqxhID(htxx, ja.getString(9));
		setBmqxhID(htxx,ja.getString(10));
		setDlcd(htxx,ja.getString(11));

		setZxcd(htxx,ja.getString(12));
		setMpzl(htxx,ja.getString(13));
		setBz(htxx,ja.getString(14));
		setDdrq(htxx, ja.getString(15));
		
		
//		
//		
//		
//		
//		
//		
//		htxx.setZcID(ja.getString(4));
//		htxx.setDfr(ja.getString(5));
//
//		htxx.setZdqdyID(ja.getString(6));
//		htxx.setYylggID(ja.getString(7));
//		htxx.setSfjf(ja.getString(8));
//
//		htxx.setBpqxhID(ja.getString(9));
//		htxx.setBmqxhID(ja.getString(10));
//		htxx.setDlcd(ja.getString(11));
//
//		htxx.setZxcd(ja.getString(12));
//		htxx.setMpzl(ja.getString(13));
//		htxx.setBz(ja.getString(14));
//		if (!"".equals(ja.getString(3))){
//			htxx.setDdrq(Date.valueOf(ja.getString(15)));
//		}
//		htxx.setSftgywsh(ja.getString(16));
//		htxx.setSftgjhsh(ja.getString(17));

		saleDao.insert(htxx);
		return htxx.getID() + "";
	}

	
	private void setHtID(HTXX htxx, String val) throws Exception{
		if (!"".equals(val)){
			htxx.setHtID(Integer.valueOf(val));
		}
		else {
			throw new Exception();
		}
	}
	
	
	private void setDdrq(HTXX htxx, String value) {
		if (!"".equals(value)){
			htxx.setDdrq(Date.valueOf(value.replace("/", "-")));
		}		
	}

	private void setBz(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setBz(value);
		}
	}

	private void setMpzl(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setMpzl(value);
		}
	}

	private void setZxcd(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setZxcd(value);
		}
	}

	private void setDlcd(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setDlcd(value);
		}
	}

	private void setBmqxhID(HTXX htxx, String value) {
		if (!"".equals(value)){
			BMQXHFLXX item = itemDao.queryBmqxhflxxByValue("bmqxh", value);
			if (null == item){
				item = new BMQXHFLXX();
				item.setBmqxh(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getBmqxhID());
		}		
	}

	private void setBpqxhID(HTXX htxx, String value) {
		if (!"".equals(value)){
			BPQXHFLXX item = itemDao.queryBpqxhflxxByValue("bpqxh", value);
			if (null == item){
				item = new BPQXHFLXX();
				item.setBpqxh(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getBpqxhID());
		}		
	}

	private void setSfjf(HTXX htxx, String value) {
		if (!"".equals(value)){
			htxx.setSfjf(value);
		}		
	}

	private void setYylggID(HTXX htxx, String value) {
		if (!"".equals(value)){
			YYLGGFLXX item = itemDao.queryYylggflxxByValue("yylgg", value);
			if (null == item){
				item = new YYLGGFLXX();
				item.setYylgg(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getYylggID());
		}		
	}

	private void setZdqdyID(HTXX htxx, String value) {
		if (!"".equals(value)){
			ZDQDYFLXX item = itemDao.queryZdqdyflxxByValue("zdqdy", value);
			if (null == item){
				item = new ZDQDYFLXX();
				item.setZdqdy(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getZdqdyID());
		}		
	}

	private void setDfr(HTXX htxx, String value) {
		if (!"".equals(value)){
			htxx.setDfr(value);
		}
	}

	private void setZcID(HTXX htxx, String value) {
		if (!"".equals(value)){
			ZCXX item = itemDao.queryZcxxByValue("zcxh", value);
			if (null == item){
				item = new ZCXX();
				item.setZcxh(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getZcxhID());
		}
		
	}

	private void setSl(HTXX htxx, String value) {
		if (!"".equals(value)){
			htxx.setSl(Integer.valueOf(value));
		}
	}

	private void setGgxhID(HTXX htxx, String value) {
		if (!"".equals(value)){
			CPGGXHXX item = itemDao.queryCpggxhxxByValue("gg", value);
			if (null == item){
				item = new CPGGXHXX();
				item.setGg(value);
				itemDao.insert(item);
			}
			htxx.setGgxhID(item.getCpggxhID());
		}
	}

	private void setClientID(HTXX htxx, String value) {
		if (!"".equals(value)){
			KHXX khxx = itemDao.queryKhxxByValue("khmc", value);
			if (null == khxx){

			}
			else {
				htxx.setClientID(khxx.getClientID());
			}
		}
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
