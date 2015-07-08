package com.BlueRay.mutton.service.sale;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.Date;
import java.util.ArrayList;
import java.util.List;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.common.HtxxColumn;
import com.BlueRay.mutton.common.ImportResult;
import com.BlueRay.mutton.common.PageData;
import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BZXDTGG;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHQY;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQXH;
import com.BlueRay.mutton.model.entity.jpa.ZJDY;
import com.BlueRay.mutton.model.entity.jpa.ZJYS;
import com.BlueRay.mutton.model.entity.jpa.ZZS;
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
			row[HtxxColumn.id.ordinal()] = htxx.getID() + "";

			row[HtxxColumn.hth.ordinal()] = htxx.getHtID() + "";
			KHXX khxx = null != htxx.getClientID() ? itDao.queryKhxxById(htxx.getClientID()) : null;
			row[HtxxColumn.khmc.ordinal()] = null == khxx ? "" : khxx.getKhmc();
			
			CPGGXHXX cpgg = null != htxx.getGgxhID() ? itDao.queryCpggxhxxById(htxx.getGgxhID()) : null;
			row[HtxxColumn.ggxh.ordinal()] = null == cpgg ? "" : cpgg.getGg();

			row[HtxxColumn.sl.ordinal()] = htxx.getSl() + "";
			ZCXX zcxx = null != htxx.getZcID() ? itDao.queryZcxxById(htxx.getZcID()) : null;
			row[HtxxColumn.zc.ordinal()] = null == zcxx ? "" : zcxx.getZcxh();
			row[HtxxColumn.dfr.ordinal()] = translator.out("dfr", htxx.getDfr());

			ZDQDYFLXX zdq = null != htxx.getZdqdyID() ? itDao.queryZdqdyflxxById(htxx.getZdqdyID()) : null;
			row[HtxxColumn.zdqdy.ordinal()] = null == zdq ? "" : zdq.getZdqdy();
			
			YYLGGFLXX yyl = null != htxx.getYylggID() ? itDao.queryYylggflxxById(htxx.getYylggID()) : null;			
			row[HtxxColumn.yylgg.ordinal()] = null == yyl ? "" : yyl.getYylgg();
			row[HtxxColumn.jf.ordinal()] = translator.out("sfjf", htxx.getSfjf());

			BPQXHFLXX bpq = null != htxx.getBpqxhID() ? itDao.queryBpqxhflxxById(htxx.getBpqxhID()) : null;	
			row[HtxxColumn.bpqxh.ordinal()] = null == bpq ? "" : bpq.getBpqxh();
			
			BMQXHFLXX bmq = null != htxx.getBmqxhID() ? itDao.queryBmqxhflxxById(htxx.getBmqxhID()) : null;						
			row[HtxxColumn.bmqxh.ordinal()] = null == bmq ? "" : bmq.getBmqxh();
			row[HtxxColumn.dlcd.ordinal()] = htxx.getDlcd();

			row[HtxxColumn.zxcd.ordinal()] = htxx.getZxcd();
			
			MPZLXX mpzl = null != htxx.getMpzl() ? itDao.queryMpzlxxById(htxx.getMpzl()): null;			
			row[HtxxColumn.mpzl.ordinal()] = null == mpzl ? "" : mpzl.getMpzl();
			row[HtxxColumn.bz.ordinal()] = htxx.getBz();
			row[HtxxColumn.ddrq.ordinal()] = htxx.getDdrq() + "";

			
			ZJDY zjdy = null != htxx.getZjdyID() ? itDao.queryZJDYById(htxx.getZjdyID()) : null;
			row[HtxxColumn.zjdy.ordinal()] = null == zjdy ? "" : zjdy.getZjdy();
			
			ZJYS zjys = null != htxx.getZjysID() ? itDao.queryZJYSById(htxx.getZjysID()) : null;
			row[HtxxColumn.zjys.ordinal()] = null == zjys ? "" : zjys.getZjys();
			
			ZDQXH zdqxh = null != htxx.getZdqxhID() ? itDao.queryZdqxhById(htxx.getZdqxhID()) : null;
			row[HtxxColumn.zdqxh.ordinal()] = null == zdqxh ? "" : zdqxh.getZdqxh();
			
			row[HtxxColumn.zyz.ordinal()] = translator.out("zyz", htxx.getZyz());
			
			BZXDTGG bzxdtgg = null != htxx.getBzxdtggID() ? itDao.queryBzxdtggById(htxx.getBzxdtggID()) : null;
			row[HtxxColumn.bzxdtgg.ordinal()] = null == bzxdtgg ? "" : bzxdtgg.getBzxdtgg();
	
			row[HtxxColumn.gh.ordinal()] = htxx.getGh();

			ZZS zzs = null != htxx.getZzsID() ? itDao.queryZZSById(htxx.getZzsID()) : null;
			row[HtxxColumn.zzs.ordinal()] = null == zzs ? "" : zzs.getZzs();

			KHQY khqy = null != htxx.getKhqyID() ? itDao.queryKHQYById(htxx.getKhqyID()) : null;
			row[HtxxColumn.khqy.ordinal()] = null == khqy ? "" : khqy.getKhqy();
			row[HtxxColumn.yxj.ordinal()] = translator.out("yxj", htxx.getYxj() + "");
			
			row[HtxxColumn.xsjhshyw.ordinal()] = translator.out("sftgywsh", htxx.getSftgywsh());
			row[HtxxColumn.xsjhshjh.ordinal()] = translator.out("sftgjhsh", htxx.getSftgjhsh());
			

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

	private static List<Method> setMethods = new ArrayList<Method>();
	static{
		try {
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setHtID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setClientID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setGgxhID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setSl", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZcID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setDfr", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZdqdyID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setYylggID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setSfjf", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setBpqxhID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setBmqxhID", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setDlcd", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZxcd", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setMpzl", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setBz", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setDdrq", HTXX.class, String.class));		
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZjdy", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZjys", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZdqxh", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZyz", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setBzxdtgg", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setGh", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setZzs", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setKhqy", HTXX.class, String.class));
			setMethods.add(SaleServiceImpl.class.getDeclaredMethod("setYxj", HTXX.class, String.class));

		} catch (NoSuchMethodException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void updateHtxxSingleRow(JSONArray ja, HTXX htxx) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {

			for (int i = ja.size() > setMethods.size() ? setMethods.size() - 1
					: ja.size() - 1; i >= 0; --i) {
				if (!"".equals(ja.getString(i)) || setMethods.get(i).getName().equals("setDdrq")){
					setMethods.get(i).invoke(this, htxx, ja.getString(i));
				}
			}
		
	}
	
	private void updateHtxxMultiRow(JSONArray ja, HTXX htxx) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {

		for (int i = ja.size() > setMethods.size() ? setMethods.size() - 1
				: ja.size() - 1; i >= 0; --i) {
			if (!"".equals(ja.getString(i))){
				setMethods.get(i).invoke(this, htxx, ja.getString(i));
			}
		}
	
}
	
	
	
	public String add(JSONArray ja) throws Exception {
		HTXX htxx = new HTXX();

		updateHtxxSingleRow(ja, htxx);

		saleDao.insert(htxx);
		return htxx.getID() + "";
	}

	private void setKhqy(HTXX htxx, String val) {
		if (!"".equals(val)) {
			KHQY item = itemDao.queryKHQYByValue("khqy", val);
			if (null == item) {
				item = new KHQY();
				item.setKhqy(val);
				itemDao.insert(item);
			}
			htxx.setKhqyID(item.getId());
		}	
	}

	private void setZzs(HTXX htxx, String val) {
		if (!"".equals(val)) {
			ZZS item = itemDao.queryZZSByValue("zzs", val);
			if (null == item) {
				item = new ZZS();
				item.setZzs(val);
				itemDao.insert(item);
			}
			htxx.setZzsID(item.getId());
		}			
	}

	private void setGh(HTXX htxx, String val) {
		htxx.setGh(val);
	}

	private void setBzxdtgg(HTXX htxx, String val) {
		if (!"".equals(val)) {
			BZXDTGG item = itemDao.queryBzxdtggByValue("bzxdtgg", val);
			if (null == item) {
				item = new BZXDTGG();
				item.setBzxdtgg(val);
				itemDao.insert(item);
			}
			htxx.setBzxdtggID(item.getId());
		}					
	}

	private void setZyz(HTXX htxx, String val) {
		htxx.setZyz(translator.in("zyz", val));		
	}

	private void setZdqxh(HTXX htxx, String val) {
		if (!"".equals(val)) {
			ZDQXH item = itemDao.queryZdqxhByValue("zdqxh", val);
			if (null == item) {
				item = new ZDQXH();
				item.setZdqxh(val);
				itemDao.insert(item);
			}
			htxx.setZdqxhID(item.getId());
		}			
	}

	private void setZjys(HTXX htxx, String val) {
		if (!"".equals(val)) {
			ZJYS item = itemDao.queryZJYSByValue("zjys", val);
			if (null == item) {
				item = new ZJYS();
				item.setZjys(val);
				itemDao.insert(item);
			}
			htxx.setZjysID(item.getId());
		}		
	}

	private void setZjdy(HTXX htxx, String val) {
		if (!"".equals(val)) {
			ZJDY item = itemDao.queryZJDYByValue("zjdy", val);
			if (null == item) {
				item = new ZJDY();
				item.setZjdy(val);
				itemDao.insert(item);
			}
			htxx.setZjdyID(item.getId());
		}			
	}

	private void setYxj(HTXX htxx, String val) {
		val = translator.in("yxj", val);
		if (null != val)	{
			htxx.setYxj(Integer.valueOf(val));
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


	public void upgradeGgxh(CPGGXHXX ggxh, String value){
		ggxh.setGg(value);
		if (!value.isEmpty() && ggxh.getDw().isEmpty()){
			int num = -1;
			for (int i = 0; i < value.length(); ++i){
				if (value.charAt(i) >= '0' && value.charAt(i) <= '9'){
					num = i;
					break;
				}
			}
			
			if (num >= 0){
				int letter = -1;
				for (int i = num + 1; i < value.length(); ++i){
					if ((value.charAt(i) >= 'a' && value.charAt(i) <= 'z') || (value.charAt(i) >= 'A' && value.charAt(i) <= 'Z') ){
						letter = i;
						break;
					}
				}
				ggxh.setXh(value.substring(0, num));
				
				if (letter > 0){
					ggxh.setDw(value.substring(num, letter));
					ggxh.setTs(value.substring(letter));
				}
			}
		}
	}
	
	private void setGgxhID(HTXX htxx, String value) {
		if (!"".equals(value)) {
			CPGGXHXX item = itemDao.queryCpggxhxxByValue("gg", value);
			if (null == item) {
				item = new CPGGXHXX();
				upgradeGgxh(item, value);
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
			htxx = saleDao.getSaleDataById(Integer.valueOf(ja.getString(i)));
			if (htxx != null && !"Y".equals(htxx.getSftgjhsh()) && !"Y".equals(htxx.getSftgywsh())){
				saleDao.del(htxx);
			}
		}

		return "success";
	}

	public String update(JSONArray rows, JSONArray data) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (htxx != null && !"Y".equals(htxx.getSftgjhsh()) && !"Y".equals(htxx.getSftgywsh())) {
				try {
					if (rows.size() == 1){
						updateHtxxSingleRow(data, htxx);
					}else{
						updateHtxxMultiRow(data, htxx);
					}
					saleDao.update(htxx);
				} catch (Exception e) {
					e.printStackTrace();
				}
				
			}
		}
		return "success";
	}

	
	private boolean validatePassApprove(HTXX htxx) {
		if ("Y".equals(htxx.getSftgjhsh()) && "Y".equals(htxx.getSftgywsh())) {
			if (htxx.getSl() == null){
				return false;
			}
			for (int j = htxx.getSl() - 1; j >= 0; j--) {
				PCJHXX pcjhxx = new PCJHXX();
				pcjhxx.setHtxxID(htxx.getID());
				pcjhxx.setBz(htxx.getBz());
				pcjhxx.setZcID(htxx.getZcID());
				pcjhxx.setCgID(1);
				planDao.insert(pcjhxx);
			}
		}
		return true;
	}
	
	public String businessApprove(JSONArray rows) {
		JSONArray jaRet = new JSONArray();
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(htxx.getSftgywsh())) {
				htxx.setSftgywsh("Y");
				if (validatePassApprove(htxx)){
					saleDao.update(htxx);
				}else{
					jaRet.add(rows.getInt(i) + "");
				}
			}
		}
		return jaRet.toString();
	}

	public String planApprove(JSONArray rows) {
		JSONArray jaRet = new JSONArray();
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(htxx.getSftgjhsh())) {
				htxx.setSftgjhsh("Y");
				if (validatePassApprove(htxx)){
					saleDao.update(htxx);
				}else{
					jaRet.add(rows.getInt(i) + "");
				}
			}
		}
		return jaRet.toString();
	}

	public String businessUnapprove(JSONArray rows) {
		JSONArray jaRet = new JSONArray();
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao
					.getSaleDataById(Integer.valueOf(rows.getInt(i)));
			if (null != htxx) {
				if ("Y".equals(htxx.getSftgywsh())) {
					htxx.setSftgywsh("N");
					if (!validatePassUnapprove(htxx)) {
						jaRet.add(rows.getInt(i) + "");
					} else{
						saleDao.update(htxx);
					}
				}
			} else {
				jaRet.add(rows.getInt(i) + "");
			}
		}
		return jaRet.toString();
	}

	private boolean validatePassUnapprove(HTXX htxx) {
		if (!"Y".equals(htxx.getSftgjhsh()) || !"Y".equals(htxx.getSftgywsh())) {
			int approvedCount = planDao.getArpprovedDataCount(htxx.getID());
			if (approvedCount == 0) {
				List<PCJHXX> pcjhs = planDao.getDateByHtxxId(htxx.getID());
				for (PCJHXX pcjh : pcjhs) {
					planDao.delete(pcjh);
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

	public String planUnapprove(JSONArray rows) {
		JSONArray jaRet = new JSONArray();
		for (int i = rows.size() - 1; i >= 0; --i) {
			HTXX htxx = saleDao.getSaleDataById(rows.getInt(i));
			if (null != htxx) {
				if ("Y".equals(htxx.getSftgjhsh())) {
					htxx.setSftgjhsh("N");
					if (!validatePassUnapprove(htxx)) {
						jaRet.add(rows.getInt(i) + "");
					}else{
						saleDao.update(htxx);
					}
				}
			} else {
				jaRet.add(rows.getInt(i) + "");
			}
		}
		return jaRet.toString();
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
		String[] row = new String[HtxxColumn.end.ordinal()];
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
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "审核-业务", "审核-计划"});
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

	public ImportResult importData(JSONArray data) {
		ImportResult ret = new ImportResult();
		ret.total = data.size();
		for (int i = 0, len = data.size(); i < len; ++i){
			try {
				add(data.getJSONArray(i));
				++ret.succeed;
			} catch (Exception e) {
				++ret.failed;
				e.printStackTrace();
			}
		}
		return ret;
	}
	
	public boolean isHtidExist(String id){
		return saleDao.containsHtid(id);
	}

	public void upgradeGgxh() {
		List<CPGGXHXX> ggxhs = itemDao.getGGXHs();
		for (CPGGXHXX ggxh : ggxhs){
			upgradeGgxh(ggxh, ggxh.getGg());
			itemDao.update(ggxh);
		}
		
	}
}
