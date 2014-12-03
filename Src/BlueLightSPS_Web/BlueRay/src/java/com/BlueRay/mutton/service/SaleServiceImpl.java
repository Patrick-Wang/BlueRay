package com.BlueRay.mutton.service;

import java.sql.Date;
import java.util.List;

import net.sf.json.JSONArray;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
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

	@Autowired
	private PlanDao planDao;

	public static void setHtxx(String[] row, HTXX htxx, ItemDao itDao) {
		try {
			row[0] = htxx.getID() + "";

			row[1] = htxx.getHtID() + "";
			row[2] = itDao.queryKhxxById(htxx.getClientID()).getKhmc();
			row[3] = itDao.queryCpggxhxxById(htxx.getGgxhID()).getGg();

			row[4] = htxx.getSl() + "";
			row[5] = itDao.queryZcxxById(htxx.getZcID()).getZcxh();
			row[6] = "Y".equals(htxx.getDfr()) ? "是" : "否";

			row[7] = itDao.queryZdqdyflxxById(htxx.getZdqdyID()).getZdqdy();
			row[8] = itDao.queryYylggflxxById(htxx.getYylggID()).getYylgg();
			row[9] = htxx.getSfjf();

			row[10] = itDao.queryBpqxhflxxById(htxx.getBpqxhID()).getBpqxh();
			row[11] = itDao.queryBmqxhflxxById(htxx.getBmqxhID()).getBmqxh();
			row[12] = htxx.getDlcd();

			row[13] = htxx.getZxcd();
			row[14] = itDao.queryMpzlxxById(htxx.getMpzl()).getMpzl();
			row[15] = htxx.getBz();

			row[16] = htxx.getDdrq() + "";
			row[17] = "Y".equals(htxx.getSftgywsh()) ? "已审批" : "未审批";
			row[18] = "Y".equals(htxx.getSftgjhsh()) ? "已审批" : "未审批";
		} catch (Exception e) {

		}
	}

	public String[][] query() {
		List<HTXX> list = saleDao.getSaleData();
		// "合同号", "客户名称", "规格型号",
		// "数量", "轴承", "单复绕",
		// "制动器电压", "曳引轮规格", "机房",
		// "变频器型号", "编码器型号", "电缆长度",
		// "闸线长度", "铭牌等资料", "备注",
		// "订单日期", "审核-业务", "审核-计划"
		String[][] ret = new String[list.size()][19];
		HTXX htxx = null;
		for (int i = 0; i < list.size(); ++i) {
			htxx = list.get(i);
			setHtxx(ret[i], htxx, itemDao);
			// try {
			// ret[i][0] = htxx.getID() + "";
			//
			// ret[i][1] = htxx.getHtID() + "";
			// ret[i][2] = itemDao.queryKhxxById(htxx.getClientID()).getKhmc();
			// ret[i][3] = itemDao.queryCpggxhxxById(htxx.getGgxhID()).getGg();
			//
			// ret[i][4] = htxx.getSl() + "";
			// ret[i][5] = itemDao.queryZcxxById(htxx.getZcID()).getZcxh();
			// ret[i][6] = "Y".equals(htxx.getDfr()) ? "是": "否";
			//
			// ret[i][7] = itemDao.queryZdqdyflxxById(htxx.getZdqdyID())
			// .getZdqdy();
			// ret[i][8] = itemDao.queryYylggflxxById(htxx.getYylggID())
			// .getYylgg();
			// ret[i][9] = htxx.getSfjf();
			//
			// ret[i][10] = itemDao.queryBpqxhflxxById(htxx.getBpqxhID())
			// .getBpqxh();
			// ret[i][11] = itemDao.queryBmqxhflxxById(htxx.getBmqxhID())
			// .getBmqxh();
			// ret[i][12] = htxx.getDlcd();
			//
			// ret[i][13] = htxx.getZxcd();
			// ret[i][14] = itemDao.queryMpzlxxById(htxx.getMpzl()).getMpzl();
			// ret[i][15] = htxx.getBz();
			//
			// ret[i][16] = htxx.getDdrq() + "";
			// ret[i][17] = "Y".equals(htxx.getSftgywsh()) ? "已审批" : "未审批";
			// ret[i][18] = "Y".equals(htxx.getSftgjhsh()) ? "已审批" : "未审批";
			// } catch (Exception e) {
			//
			// }
			// ret[i][17] = htxx.getDdzt();

		}
		return ret;
	}

	public boolean update() {
		BMQXHFLXX bxx = new BMQXHFLXX();
		bxx.setBmqxh("asdf");
		bxx.setBmqxhID(12);
		// saleDao.insert(bxx);
		return false;
	}

	public String add(JSONArray ja) throws Exception {
		HTXX htxx = new HTXX();
		if ("".equals(ja.getString(0))) {
			throw new Exception("Id cannot be none");
		}
		setHtID(htxx, ja.getString(0));
		setClientID(htxx, ja.getString(1));
		setGgxhID(htxx, ja.getString(2));
		setSl(htxx, ja.getString(3));
		setZcID(htxx, ja.getString(4));
		setDfr(htxx, ja.getString(5));
		setZdqdyID(htxx, ja.getString(6));
		setYylggID(htxx, ja.getString(7));
		setSfjf(htxx, ja.getString(8));
		setBpqxhID(htxx, ja.getString(9));
		setBmqxhID(htxx, ja.getString(10));
		setDlcd(htxx, ja.getString(11));

		setZxcd(htxx, ja.getString(12));
		setMpzl(htxx, ja.getString(13));
		setBz(htxx, ja.getString(14));
		setDdrq(htxx, ja.getString(15));

		saleDao.insert(htxx);
		return htxx.getID() + "";
	}

	private void setHtID(HTXX htxx, String val) {
		if (!"".equals(val)) {
			htxx.setHtID(val);
		}
	}

	private void setDdrq(HTXX htxx, String value) {
		if (!"".equals(value)) {
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
			MPZLXX item = itemDao.queryMpzlxxByValue("mpzl", value);
			if (null == item) {
				item = new MPZLXX();
				item.setMpzl(value);
				itemDao.insert(item);
			}
			htxx.setMpzl(item.getId());
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
		if (!"".equals(value)) {
			BMQXHFLXX item = itemDao.queryBmqxhflxxByValue("bmqxh", value);
			if (null == item) {
				item = new BMQXHFLXX();
				item.setBmqxh(value);
				itemDao.insert(item);
			}
			htxx.setBmqxhID(item.getBmqxhID());
		}
	}

	private void setBpqxhID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			BPQXHFLXX item = itemDao.queryBpqxhflxxByValue("bpqxh", value);
			if (null == item) {
				item = new BPQXHFLXX();
				item.setBpqxh(value);
				itemDao.insert(item);
			}
			htxx.setBpqxhID(item.getBpqxhID());
		}
	}

	private void setSfjf(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setSfjf(value);
		}
	}

	private void setYylggID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			YYLGGFLXX item = itemDao.queryYylggflxxByValue("yylgg", value);
			if (null == item) {
				item = new YYLGGFLXX();
				item.setYylgg(value);
				itemDao.insert(item);
			}
			htxx.setYylggID(item.getYylggID());
		}
	}

	private void setZdqdyID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			ZDQDYFLXX item = itemDao.queryZdqdyflxxByValue("zdqdy", value);
			if (null == item) {
				item = new ZDQDYFLXX();
				item.setZdqdy(value);
				itemDao.insert(item);
			}
			htxx.setZdqdyID(item.getZdqdyID());
		}
	}

	private void setDfr(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setDfr("是".equals(value) ? "Y" : "N");
		}
	}

	private void setZcID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			ZCXX item = itemDao.queryZcxxByValue("zcxh", value);
			if (null == item) {
				item = new ZCXX();
				item.setZcxh(value);
				itemDao.insert(item);
			}
			htxx.setZcID(item.getZcxhID());
		}

	}

	private void setSl(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setSl(Integer.valueOf(value));
		}
	}

	private void setGgxhID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			CPGGXHXX item = itemDao.queryCpggxhxxByValue("gg", value);
			if (null == item) {
				item = new CPGGXHXX();
				item.setGg(value);
				itemDao.insert(item);
			}
			htxx.setGgxhID(item.getCpggxhID());
		}
	}

	private void setClientID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			KHXX khxx = itemDao.queryKhxxByValue("khmc", value);
			if (null == khxx) {

			} else {
				htxx.setClientID(khxx.getClientID());
			}
		}
	}

	public String delete(JSONArray ja) {
		HTXX htxx = new HTXX();
		for (int i = 0; i < ja.size(); ++i) {
			htxx.setID(Integer.valueOf(ja.getString(i)));
			saleDao.del(htxx);
		}

		return "";
	}

	public String update(JSONArray rows, JSONArray data) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (htxx != null) {
				setHtID(htxx, data.getString(0));
				setClientID(htxx, data.getString(1));
				setGgxhID(htxx, data.getString(2));
				setSl(htxx, data.getString(3));
				setZcID(htxx, data.getString(4));
				setDfr(htxx, data.getString(5));
				setZdqdyID(htxx, data.getString(6));
				setYylggID(htxx, data.getString(7));
				setSfjf(htxx, data.getString(8));
				setBpqxhID(htxx, data.getString(9));
				setBmqxhID(htxx, data.getString(10));
				setDlcd(htxx, data.getString(11));

				setZxcd(htxx, data.getString(12));
				setMpzl(htxx, data.getString(13));
				setBz(htxx, data.getString(14));
				setDdrq(htxx, data.getString(15));

				saleDao.update(htxx);
			}
		}
		return "success";
	}

	public String businessApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if ("N".equals(htxx.getSftgywsh())) {
				htxx.setSftgywsh("Y");
				saleDao.update(htxx);
				PCJHXX pcjhxx = new PCJHXX();
				pcjhxx.setHtxxID(htxx.getID());
				planDao.insert(pcjhxx);
			}
		}
		return "success";
	}

}
