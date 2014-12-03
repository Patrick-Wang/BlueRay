package com.BlueRay.mutton.service;

import java.sql.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.json.JSONArray;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;

@Service
@Transactional("transactionManager")
public class PlanServiceImpl implements PlanService {

	@Autowired
	PlanDao planDao;

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private ItemDao itemDao;

	public String[][] query() {

		List<PCJHXX> pcxxs = planDao.getPcjhxx();
		
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
		Integer id;
		PCJHXX pcjhxx;
		for (int i = pcxxs.size() - 1; i >= 0; --i) {
			pcjhxx = pcxxs.get(i);
			if (null != pcjhxx) {
				id = pcjhxx.getHtxxID();
				if (!htxxMap.containsKey(id)) {
					htxxMap.put(id, saleDao.getSaleDataById(id));
				}
				if (htxxMap.get(id) == null) {
					planDao.delete(pcjhxx);
					pcxxs.remove(i);
				}
			}else{
				pcxxs.remove(i);
			}
		}
		String[][] ret = new String[pcxxs.size()][26];
		for (int i = pcxxs.size() - 1; i >= 0; --i) {
			pcjhxx = pcxxs.get(i);
			id = pcjhxx.getHtxxID();
			SaleServiceImpl.setHtxx(ret[i], htxxMap.get(id), itemDao);
			ret[i][0] = pcjhxx.getPcjhID() + "";
			ret[i][4] = "1";// 数量
			ret[i][17] = (null != pcjhxx.getJhscrq()) ? pcjhxx.getJhscrq()
					.toString() : "";
			ret[i][18] = "Y".equals(pcjhxx.getSftgywsh()) ? "已审批" : "未审批";
			ret[i][19] = "Y".equals(pcjhxx.getSftgjhsh()) ? "已审批" : "未审批";
			ret[i][20] = (null != pcjhxx.getJhbzrq()) ? pcjhxx.getJhbzrq()
					.toString() : "";
			ret[i][21] = "Y".equals(pcjhxx.getBzsftgywsh()) ? "已审批" : "未审批";
			ret[i][22] = "Y".equals(pcjhxx.getBzsftgjhsh()) ? "已审批" : "未审批";
			ret[i][23] = (null != pcjhxx.getJhfhrq()) ? pcjhxx.getJhfhrq()
					.toString() : "";
			ret[i][24] = pcjhxx.getTcbh();
			ret[i][25] = pcjhxx.getCcbh();

		}
		return ret;
	}

	public String update(JSONArray rows, JSONArray data) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(rows.getInt(i));
			if (pcjhxx != null) {
				setJhscrq(pcjhxx, data.getString(0));
				setJhbzrq(pcjhxx, data.getString(1));
				setJhfhrq(pcjhxx, data.getString(2));
				setTcbh(pcjhxx, data.getString(3));
				setCcbh(pcjhxx, data.getString(4));

				planDao.update(pcjhxx);
			}

		}
		return "success";
	}

	private void setTcbh(PCJHXX pcjhxx, String data) {
		if (!"".equals(data))
			pcjhxx.setTcbh(data);

	}

	private void setCcbh(PCJHXX pcjhxx, String data) {
		if (!"".equals(data))
			pcjhxx.setCcbh(data);

	}

	private void setJhfhrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhfhrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}
		}

	}

	private void setJhbzrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhbzrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}
		}

	}

	private void setJhscrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhscrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}

		}

	}

}
