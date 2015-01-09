package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.sql.Date;
import java.util.List;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.controller.PageData;
import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
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
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;


@Service
@Transactional("transactionManager")
public class SaleServiceImpl implements SaleService {

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private ItemDao itemDao;

	@Autowired
	private PlanDao planDao;

	
	
	private static IAdvanceTranslator translator = new SaleAdvanceTranslator();
	
	
	public static void setHtxx(String[] row, HTXX htxx, ItemDao itDao) {
		try {
			row[0] = htxx.getID() + "";

			row[1] = htxx.getHtID() + "";
			KHXX khxx = null != htxx.getClientID() ? itDao.queryKhxxById(htxx.getClientID()) : null;
			row[2] = null == khxx ? "" : khxx.getKhmc();
			
			CPGGXHXX cpgg = null != htxx.getGgxhID() ? itDao.queryCpggxhxxById(htxx.getGgxhID()) : null;
			row[3] = null == cpgg ? "" : cpgg.getGg();

			row[4] = htxx.getSl() + "";
			ZCXX zcxx = null != htxx.getZcID() ? itDao.queryZcxxById(htxx.getZcID()) : null;
			row[5] = null == zcxx ? "" : zcxx.getZcxh();
			row[6] = translator.out("dfr", htxx.getDfr());

			ZDQDYFLXX zdq = null != htxx.getZdqdyID() ? itDao.queryZdqdyflxxById(htxx.getZdqdyID()) : null;
			row[7] = null == zdq ? "" : zdq.getZdqdy();
			
			YYLGGFLXX yyl = null != htxx.getYylggID() ? itDao.queryYylggflxxById(htxx.getYylggID()) : null;			
			row[8] = null == yyl ? "" : yyl.getYylgg();
			row[9] = translator.out("sfjf", htxx.getSfjf());

			BPQXHFLXX bpq = null != htxx.getBpqxhID() ? itDao.queryBpqxhflxxById(htxx.getBpqxhID()) : null;	
			row[10] = null == bpq ? "" : bpq.getBpqxh();
			
			BMQXHFLXX bmq = null != htxx.getBmqxhID() ? itDao.queryBmqxhflxxById(htxx.getBmqxhID()) : null;						
			row[11] = null == bmq ? "" : bmq.getBmqxh();
			row[12] = htxx.getDlcd();

			row[13] = htxx.getZxcd();
			
			MPZLXX mpzl = null != htxx.getMpzl() ? itDao.queryMpzlxxById(htxx.getMpzl()): null;			
			row[14] = null == mpzl ? "" : mpzl.getMpzl();
			row[15] = htxx.getBz();
			row[16] = htxx.getDdrq() + "";
			row[17] = translator.out("sftgywsh", htxx.getSftgywsh());
			row[18] = translator.out("sftgjhsh", htxx.getSftgjhsh());
			row[19] = translator.out("yxj", htxx.getYxj() + "");

		} catch (Exception e) {
			e.printStackTrace();
		}
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
		setYxj(htxx, ja.getString(16));
		
		saleDao.insert(htxx);
		return htxx.getID() + "";
	}

	private void setYxj(HTXX htxx, String val) {
		if ("".equals(val))	{
			htxx.setYxj(100);
		} else if (10 == Integer.valueOf(val)){
			htxx.setYxj(10);
		}
	}

	private void setHtID(HTXX htxx, String val) {
		htxx.setHtID(val);
	}

	private void setDdrq(HTXX htxx, String value) {
		if (!"".equals(value)) {
			htxx.setDdrq(Date.valueOf(value.replace("/", "-")));
		} else{
			htxx.setDdrq(null);
		}
	}

	private void setBz(HTXX htxx, String value) {
		htxx.setBz(value);
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
		htxx.setZxcd(value);
	}

	private void setDlcd(HTXX htxx, String value) {
		htxx.setDlcd(value);
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
		htxx.setSfjf(this.translator.in("sfjf", value));
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
		htxx.setDfr(this.translator.in("dfr", value));
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
		else {
			htxx.setSl(null);
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
				khxx = new KHXX();
				khxx.setKhmc(value);
				itemDao.insert(khxx);
			} 
			htxx.setClientID(khxx.getClientID());
		}
	}

	public String delete(JSONArray ja) {
		HTXX htxx = new HTXX();
		for (int i = 0; i < ja.size(); ++i) {
			htxx.setID(Integer.valueOf(ja.getString(i)));
			saleDao.del(htxx);
		}

		return "success";
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
				setYxj(htxx, data.getString(16));
				saleDao.update(htxx);
			}
		}
		return "success";
	}

	
	private void validatePassApprove(HTXX htxx) {
		if ("Y".equals(htxx.getSftgjhsh()) && "Y".equals(htxx.getSftgywsh())) {
			for (int j = htxx.getSl() - 1; j >= 0; j--) {
				PCJHXX pcjhxx = new PCJHXX();
				pcjhxx.setHtxxID(htxx.getID());
				planDao.insert(pcjhxx);
			}
		}
	}
	
	public String businessApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(htxx.getSftgywsh())) {
				htxx.setSftgywsh("Y");
				saleDao.update(htxx);
				validatePassApprove(htxx);
			}
		}
		return "success";
	}

	public String planApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(htxx.getSftgjhsh())) {
				htxx.setSftgjhsh("Y");
				saleDao.update(htxx);
				validatePassApprove(htxx);
			}
		}
		return "success";
	}

	public String businessUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(htxx.getSftgywsh())) {
				htxx.setSftgywsh("N");
				saleDao.update(htxx);
				validatePassUnapprove(htxx);
			}
		}
		return "success";
	}

	private void validatePassUnapprove(HTXX htxx) {
		if (!"Y".equals(htxx.getSftgjhsh()) && !"Y".equals(htxx.getSftgywsh())) {
			List<PCJHXX> pcjhs = planDao.getDateByHtxxId(htxx.getID());
			for (PCJHXX pcjh : pcjhs){
				planDao.delete(pcjh);
			}
		}
	}

	public String planUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(htxx.getSftgjhsh())) {
				htxx.setSftgjhsh("N");
				saleDao.update(htxx);
				validatePassUnapprove(htxx);
			}
		}
		return "success";
	}


	public PageData pageQuery(Integer pagesize, Integer pagenum,
			Integer pagecount, JSONObject jparam) {
		List<HTXX> htxxs = saleDao.getSaleData(pagesize, pagenum, pagecount,
				jparam, translator);
		int count = saleDao.getSaleDataCount(jparam, translator);
		PageData pd = new PageData();
		pd.setPage(pagenum);
		pd.setRecords(count);
		int pageCount = count / pagesize;
		pageCount += count % pagesize > 0 ? 1 : 0;
		pd.setTotal(pageCount);
		String[] row = new String[21];
		PageData.Row rd;
		
		for (int i = 0; i < htxxs.size(); ++i){
			rd = pd.new Row();
			setHtxx(row, htxxs.get(i), itemDao);
			rd.setId(Integer.valueOf(row[0]));
			pd.getRows().add(rd);
			for (int j = 1; j < row.length; ++j){
				rd.getCell().add(row[j]);
			} 
		}
		
		return pd;
	}

	public String export(OutputStream out, JSONObject jparam) {
		AbstractExcel<HTXX> excel = saleDao.getHtxxExcel(jparam, translator);
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "审核-业务", "审核-计划", "优先级"});
		IExcelExporter<HTXX> exportor = new DBHTXXExcelExporter(itemDao, saleDao, excel, out);
		
		try {
			exportor.exports();
			out.close();
			return "success";
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "error";
	}
}
