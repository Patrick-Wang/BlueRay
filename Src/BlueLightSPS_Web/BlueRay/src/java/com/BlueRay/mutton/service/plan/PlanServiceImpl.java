package com.BlueRay.mutton.service.plan;

import java.io.IOException;
import java.io.OutputStream;
import java.sql.Date;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.common.HtxxColumn;
import com.BlueRay.mutton.common.PageData;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SNDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.dao.ZxdDao;
import com.BlueRay.mutton.model.entity.jpa.CGXXB;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.entity.jpa.SNIDType;
import com.BlueRay.mutton.model.entity.jpa.SerialNumber;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZZS;
import com.BlueRay.mutton.service.plan.exporter.DBPCJHXXExcelExporter;
import com.BlueRay.mutton.service.plan.exporter.DBPCJHXXTemplateBzjhExporter;
import com.BlueRay.mutton.service.plan.exporter.DBPCJHXXTemplateExporter;
import com.BlueRay.mutton.service.plan.exporter.DBPCJHXXTemplateScjhExporter;
import com.BlueRay.mutton.service.plan.exporter.zdqpq.DBPCJHXXTemplateZdqpqExporter;
import com.BlueRay.mutton.service.plan.exporter.zxd.DBPCJHXXTemplateZxdExporter;
import com.BlueRay.mutton.service.plan.exporter.zzgzk.DBPCJHXXTemplateZzgzkExporter;
import com.BlueRay.mutton.service.plan.exporter.zzjh.DBPCJHXXTemplateZzjhExporter;
import com.BlueRay.mutton.service.sale.SaleServiceImpl;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;
import com.opensymphony.oscache.util.StringUtil;


@Service
@Transactional("transactionManager")
public class PlanServiceImpl implements PlanService {

	@Autowired
	PlanDao planDao;
	
	@Autowired
	SNDao snDao;

	@Autowired
	private SaleDao saleDao;
	
	@Autowired
	private ZxdDao zxdDao;

	@Autowired
	private ItemDao itemDao;
	
	static IAdvanceTranslator planTranslator = new PlanAdvanceTranslator();

	public static void setPCJH(String[] ret, PCJHXX pcjhxx, Map<Integer, HTXX> htxxMap, ItemDao itemDao){
		Integer id = pcjhxx.getHtxxID();
		SaleServiceImpl.setHtxx(ret, htxxMap.get(id), itemDao);
		
		for (int i = HtxxColumn.end.ordinal() - 1; i >= HtxxColumn.id.ordinal(); --i){
			try{
				HtxxColumn htCol = HtxxColumn.valueOf(i);
				PcjhColumn pcjhCol = PcjhColumn.valueOf(htCol.name());
				ret[pcjhCol.ordinal()] = ret[htCol.ordinal()];
			}
			catch(Exception e){
				
			}
		}
		
		ret[PcjhColumn.id.ordinal()] = pcjhxx.getPcjhID() + "";	
		
		CGXXB cgxx = itemDao.queryCGXXById(pcjhxx.getCgID());
		ret[PcjhColumn.cg.ordinal()] = null != cgxx ? cgxx.getCg() : "";
		ret[PcjhColumn.sl.ordinal()] = "1";
		ZCXX zcxx = itemDao.queryZcxxById(pcjhxx.getZcID());
		ret[PcjhColumn.zc.ordinal()] = null != zcxx ? zcxx.getZcxh() : "";
		ret[PcjhColumn.bz.ordinal()] = pcjhxx.getBz();
		ret[PcjhColumn.scrq.ordinal()] = (null != pcjhxx.getJhscrq()) ? pcjhxx.getJhscrq()
				.toString() : "";
		ret[PcjhColumn.jhshyw.ordinal()] = planTranslator.out("sftgywsh", pcjhxx.getSftgywsh());
		ret[PcjhColumn.jhshjh.ordinal()] = planTranslator.out("sftgjhsh", pcjhxx.getSftgjhsh());
		ret[PcjhColumn.bzrq.ordinal()] = (null != pcjhxx.getJhbzrq()) ? pcjhxx.getJhbzrq()
				.toString() : "";
		ret[PcjhColumn.bzshyw.ordinal()] = planTranslator.out("bzsftgywsh", pcjhxx.getBzsftgywsh());
		ret[PcjhColumn.bzshjh.ordinal()] = planTranslator.out("bzsftgjhsh", pcjhxx.getBzsftgjhsh());
		ret[PcjhColumn.fhrq.ordinal()] = (null != pcjhxx.getJhfhrq()) ? pcjhxx.getJhfhrq()
				.toString() : "";
		ret[PcjhColumn.tcbh.ordinal()] = pcjhxx.getTcbh();
		ret[PcjhColumn.ccbh.ordinal()] = pcjhxx.getCcbh();			
		
	}
	
	public static Map<Integer, HTXX> getHtxxMap(List<PCJHXX> pcxxs, SaleDao saleDao, PlanDao planDao, Map<Integer, HTXX> htxxMap){
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
		return htxxMap;
	}

	public String[][] query(String approveType, String approved) {

		List<PCJHXX> pcxxs = null;//
		pcxxs = planDao.getPcjhxx(approveType, approved);
		
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
		getHtxxMap(pcxxs, saleDao, planDao, htxxMap);

		PCJHXX pcjhxx;
		String[][] ret = new String[pcxxs.size()][PcjhColumn.end.ordinal()];
		for (int i = pcxxs.size() - 1; i >= 0; --i) {
			pcjhxx = pcxxs.get(i);
			setPCJH(ret[i], pcjhxx, htxxMap, itemDao);
		}
		return ret;
	}

	public String update(JSONArray rows, JSONArray data) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(rows.getInt(i));
			if (pcjhxx != null) {
				if (rows.size() == 1){
					setJhscrq(pcjhxx, data.getString(0));
					setJhbzrq(pcjhxx, data.getString(1));
					setJhfhrq(pcjhxx, data.getString(2));	
					setTcbh(pcjhxx, data.getString(3));	
					setCcbh(pcjhxx, data.getString(4));
				}else{
					if (!"".equals(data.getString(0)))
						setJhscrq(pcjhxx, data.getString(0));
					if (!"".equals(data.getString(1)))
						setJhbzrq(pcjhxx, data.getString(1));
					if (!"".equals(data.getString(2)))
						setJhfhrq(pcjhxx, data.getString(2));	
					if (!"".equals(data.getString(3)))
						setTcbh(pcjhxx, data.getString(3));	
					if (!"".equals(data.getString(4)))
						setCcbh(pcjhxx, data.getString(4));
				}

				
				if (data.size() > 5 && !"".equals(data.getString(5))){				
					ZCXX item = itemDao.queryZcxxByValue("zcxh", data.getString(5));
					if (null == item) {
						item = new ZCXX();
						item.setZcxh(data.getString(5));
						itemDao.insert(item);
					}
					pcjhxx.setZcID(item.getZcxhID());
				}
				if (data.size() > 6 && !"".equals(data.getString(6))){
					pcjhxx.setBz(data.getString(6));
				} 
				if (data.size() > 7 && !"".equals(data.getString(7))){
					CGXXB item = itemDao.queryCgxxByValue("cg", data.getString(7));
					if (null == item) {
						item = new CGXXB();
						item.setCg(data.getString(7));
						itemDao.insert(item);
					}
					pcjhxx.setCgID(item.getCgID());
				} 
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}
//	private void setZcID(HTXX htxx, String value) {
//		if (!"".equals(value)) {
//			ZCXX item = itemDao.queryZcxxByValue("zcxh", value);
//			if (null == item) {
//				item = new ZCXX();
//				item.setZcxh(value);
//				itemDao.insert(item);
//			}
//			htxx.setZcID(item.getZcxhID());
//		}
//
//	}

	private void setTcbh(PCJHXX pcjhxx, String data) {
		pcjhxx.setTcbh(data);
	}

	private void setCcbh(PCJHXX pcjhxx, String data) {
		pcjhxx.setCcbh(data);

	}

	private void setJhfhrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhfhrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}
		}
		else{
			pcjhxx.setJhfhrq(null);
		}

	}

	private void setJhbzrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhbzrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}
		}
		else{
			pcjhxx.setJhbzrq(null);
		}
	}

	private void setJhscrq(PCJHXX pcjhxx, String data) {
		if (!"".equals(data)) {
			try {
				pcjhxx.setJhscrq(Date.valueOf(data.replace('/', '-')));
			} catch (Exception e) {

			}

		}
		else{
			pcjhxx.setJhscrq(null);
		}

	}

	public String businessApprove(JSONArray rows) {
		for (int i = 0; i < rows.size(); ++i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getSftgywsh())) {
				pcjhxx.setSftgywsh("Y");
				pcjhxx.setYwshrq(new Date(Calendar.getInstance().getTimeInMillis()));
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String planApprove(JSONArray rows) {
		for (int i = 0; i < rows.size(); ++i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getSftgjhsh())) {
				pcjhxx.setSftgjhsh("Y");
				pcjhxx.setJhshrq(new Date(Calendar.getInstance().getTimeInMillis()));
				if (StringUtil.isEmpty(pcjhxx.getTcbh())){
					HTXX htxx = saleDao.getSaleDataById(pcjhxx.getHtxxID());
					if (null != htxx){
						ZZS zzs = itemDao.queryZZSById(htxx.getZzsID());
						String tcbh = getTcbh(zzs, pcjhxx.getJhscrq());
						pcjhxx.setTcbh(tcbh);
					}
				}
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String packBusinessApprove(JSONArray rows) {
		for (int i = 0; i < rows.size(); ++i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgywsh())) {
				pcjhxx.setBzsftgywsh("Y");
				pcjhxx.setBzywshrq(new Date(Calendar.getInstance().getTimeInMillis()));
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String packPlanApprove(JSONArray rows) {
		for (int i = 0; i < rows.size(); ++i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgjhsh())) {
				pcjhxx.setBzsftgjhsh("Y");
				pcjhxx.setBzjhshrq(new Date(Calendar.getInstance().getTimeInMillis()));
				if (StringUtil.isEmpty(pcjhxx.getCcbh())){
					HTXX htxx = saleDao.getSaleDataById(pcjhxx.getHtxxID());
					if (null != htxx){
						ZZS zzs = itemDao.queryZZSById(htxx.getZzsID());
						String ccbh = getCcbh(zzs, pcjhxx.getJhbzrq());
						pcjhxx.setCcbh(ccbh);
					}
				}
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	
//	private void validatePlanUnapprove(PCJHXX pcjhxx){
//		if (!"Y".equals(pcjhxx.getSftgywsh()) && !"Y".equals(pcjhxx.getSftgjhsh())){
//			pcjhxx.setJhscrq(null);
//		}
//	}
	
	public String businessUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getSftgywsh())) {
				pcjhxx.setSftgywsh("N");
//				validatePlanUnapprove(pcjhxx);
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String planUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getSftgjhsh())) {
				pcjhxx.setSftgjhsh("N");
				Calendar cal = Calendar.getInstance();
				pcjhxx.setJhshrq(new Date(cal.getTimeInMillis()));
//				validatePlanUnapprove(pcjhxx);
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

//	private void validatePackUnapprove(PCJHXX pcjhxx){
//		if (!"Y".equals(pcjhxx.getBzsftgywsh()) && !"Y".equals(pcjhxx.getBzsftgjhsh())){
//			pcjhxx.setJhbzrq(null);
//		}
//	}
	
	
	public String packBusinessUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getBzsftgywsh())) {
				pcjhxx.setBzsftgywsh("N");
//				validatePackUnapprove(pcjhxx);
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String packPlanUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getBzsftgjhsh())) {
				pcjhxx.setBzsftgjhsh("N");
//				validatePackUnapprove(pcjhxx);
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String export(OutputStream outputStream, JSONObject jparam) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jparam, planTranslator);
		excel.addHeader(new String[] { "合同号", "客户名称", "规格型号", "磁钢", "数量", "轴承",
				"单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度",
				"闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置",
				"包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务",
				"计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号" });
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXExcelExporter(itemDao,
				saleDao, planDao, excel, outputStream);

		try {
			exportor.exports();
			outputStream.close();
			return "success";
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "error";
	}

	public String validate(String item, String value) {
		if("tcbh".equalsIgnoreCase(item)){
			if (null != planDao.getPlanDataByTcbh(value)){
				return "false";
			}
		} else if("ccbh".equalsIgnoreCase(item)){
			if (null != planDao.getPlanDataByCcbh(value)){
				return "false";
			}
		}
		return "true";
	}

	public PageData pageQuery(Integer pagesize, Integer pagenum,
			Integer pagecount, JSONObject jparam) {
		List<PCJHXX> pcxxs = planDao.getPlanData(pagesize, pagenum, pagecount, jparam, planTranslator);
		int count = planDao.getPlanDataCount(jparam, planTranslator);
		
		PageData pd = new PageData();
		
		pd.setPage(pagenum);
		
		pd.setRecords(count);
		
		int pageCount = count / pagesize;
		pageCount += count % pagesize > 0 ? 1 : 0;
		pd.setTotal(pageCount);
		
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
		getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
		
		PageData.Row rd;
		String[] row = new String[PcjhColumn.end.ordinal()];
		for (int i = 0; i < pcxxs.size(); ++i) {
			rd = pd.new Row();
			setPCJH(row, pcxxs.get(i), htxxMap, itemDao);
			rd.setId(Integer.valueOf(row[0]));
			pd.getRows().add(rd);
			for (int j = 1; j < row.length; ++j){
				rd.getCell().add(row[j]);
			} 
		}
		return pd;
	}

	public String templateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "磁钢", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"});
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateExporter(itemDao, saleDao, planDao, excel, out);
		
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

	private String getTcbh(ZZS zzs, Date scrq){
		Calendar cal = Calendar.getInstance();
		cal.setTime(scrq);
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH) + 1;
		int day = cal.get(Calendar.DAY_OF_MONTH);
		if (month >= 12 && day >= 26){
			year += 1;
			if (null != zzs){
				resetTcSerialNumber(zzs.getId());
			}else{
				resetTcSerialNumber(0);
			}
		}
		String ret = null;
		do{
			if (null != zzs){
				ret = String.format("%02d%05d", year % 100, increaseTcSerialNumber(zzs.getId(), SNIDType.TC) % 100000);
				ret = zzs.getCode() + ret;
			}else{
				ret = String.format("%02d%05d", year % 100, increaseTcSerialNumber(0, SNIDType.TC) % 100000);
				ret = 'X' + ret;
			}
		}while(!"true".equals(validate("tcbh", ret)));
		
		return ret;
	}
	
	private String getCcbh(ZZS zzs, Date bzrq){
		Calendar cal = Calendar.getInstance();
		cal.setTime(bzrq);
		int day = cal.get(Calendar.DAY_OF_MONTH);
		if (day >= 26){
			cal.add(Calendar.MONTH, 1);
			if (null != zzs){
				resetCcSerialNumber(zzs.getId());
			}else{
				resetCcSerialNumber(0);
			}
			
		}
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH) + 1;
		String ret = null;
		do{
			if (null != zzs){
				ret = String.format("%02d%X%04d", year % 100, month, increaseCcSerialNumber(zzs.getId(), SNIDType.CC) % 10000);
				ret = zzs.getCode() + ret;
			}else{
				ret = String.format("%02d%X%04d", year % 100, month, increaseCcSerialNumber(0, SNIDType.CC) % 10000);
				ret = 'X' + ret;
			}
		}while(!"true".equals(validate("ccbh", ret)));
		return ret;
	}
	
	public String getBh(String item, String zzsName, Date date) {
		String ret = "";
		ZZS zzs = itemDao.queryZZSByValue("zzs", zzsName);
		if("tcbh".equalsIgnoreCase(item)){
			ret = getTcbh(zzs, date);			
		} else if("ccbh".equalsIgnoreCase(item)){
			ret = getCcbh(zzs, date);			
		}
		return ret;
	}

	public String bzjhtemplateExport(OutputStream outputStream, JSONObject jparam) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jparam, planTranslator);
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "磁钢", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"});
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateBzjhExporter(itemDao, saleDao, planDao, excel, outputStream);
		
		try {
			exportor.exports();
			outputStream.close();
			return "success";
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "error";
	}

	public void resetCcSerialNumber(Integer zzsId) {
		SerialNumber sn = snDao.getSN(zzsId, SNIDType.CC);
		sn.setMax(1);
		snDao.saveSN(sn);
	}

	private Integer increaseCcSerialNumber(Integer zzsId, SNIDType type) {
		SerialNumber snNumber = snDao.getSNByZzs(zzsId, type);
		if (null == snNumber){
			snNumber = snDao.getSNByZzs(0, type);
		}
		int maxNum = snNumber.getMax();
		snNumber.setMax((maxNum + 1) % 10000);
		snDao.saveSN(snNumber);
		return maxNum;
	}
	
	public void resetTcSerialNumber(Integer zzsId) {
		SerialNumber sn = snDao.getSN(zzsId, SNIDType.TC);
		sn.setMax(1);
		snDao.saveSN(sn);
	}
	
	private Integer increaseTcSerialNumber(Integer zzsId, SNIDType type) {
		SerialNumber snNumber = snDao.getSNByZzs(zzsId, type);
		if (null == snNumber){
			snNumber = snDao.getSNByZzs(0, type);
		}
		int maxNum = snNumber.getMax();
		snNumber.setMax((maxNum + 1) % 100000);
		snDao.saveSN(snNumber);		
		return maxNum;
	}

	public String scjhtemplateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateScjhExporter(itemDao, saleDao, planDao, excel, out);
		
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

	public String zzjhtemplateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateZzjhExporter(itemDao, saleDao, planDao, excel, out);
		
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

	public String zzgzktemplateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateZzgzkExporter(itemDao, saleDao, planDao, excel, out);
		
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

	public String zdqPqtemplateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateZdqpqExporter(itemDao, saleDao, planDao, excel, out);
		
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

	public String zxdtemplateExport(OutputStream out, JSONObject jquery) {
		AbstractExcel<PCJHXX> excel = planDao.getPcjhExcel(jquery, planTranslator);
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXTemplateZxdExporter(itemDao, saleDao, planDao, zxdDao, excel, out);
		
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
