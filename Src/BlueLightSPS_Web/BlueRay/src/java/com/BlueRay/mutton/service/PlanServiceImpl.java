package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.reflect.Field;
import java.sql.Date;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.controller.PageData;
import com.BlueRay.mutton.controller.PageData.Row;
import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;


@Service
@Transactional("transactionManager")
public class PlanServiceImpl implements PlanService {

	@Autowired
	PlanDao planDao;

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private ItemDao itemDao;
	
	static IAdvanceTranslator planTranslator = new PlanAdvanceTranslator();

	public static void setPCJH(String[] ret, PCJHXX pcjhxx, Map<Integer, HTXX> htxxMap, ItemDao itemDao){
		Integer id = pcjhxx.getHtxxID();
		SaleServiceImpl.setHtxx(ret, htxxMap.get(id), itemDao);
		ret[0] = pcjhxx.getPcjhID() + "";
		ret[4] = "1";// 鏁伴噺
		ret[18 + 8] = (null != pcjhxx.getJhscrq()) ? pcjhxx.getJhscrq()
				.toString() : "";
		ret[19 + 8] = planTranslator.out("sftgywsh", pcjhxx.getSftgywsh());
		ret[20 + 8] = planTranslator.out("sftgjhsh", pcjhxx.getSftgjhsh());
		ret[21 + 8] = (null != pcjhxx.getJhbzrq()) ? pcjhxx.getJhbzrq()
				.toString() : "";
		ret[22 + 8] = planTranslator.out("bzsftgywsh", pcjhxx.getBzsftgywsh());
		ret[23 + 8] = planTranslator.out("bzsftgjhsh", pcjhxx.getBzsftgjhsh());
		ret[24 + 8] = (null != pcjhxx.getJhfhrq()) ? pcjhxx.getJhfhrq()
				.toString() : "";
		ret[25 + 8] = pcjhxx.getTcbh();
		ret[26 + 8] = pcjhxx.getCcbh();		
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
		String[][] ret = new String[pcxxs.size()][35];
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
				if (!"".equals(data.getString(0)) && 
						!"Y".equals(pcjhxx.getSftgjhsh()) && 
						!"Y".equals(pcjhxx.getSftgywsh()) )
					setJhscrq(pcjhxx, data.getString(0));
				if (!"".equals(data.getString(1)) && 
						!"Y".equals(pcjhxx.getBzsftgjhsh()) && 
						!"Y".equals(pcjhxx.getBzsftgywsh()))
					setJhbzrq(pcjhxx, data.getString(1));
				if (!"".equals(data.getString(2)))
					setJhfhrq(pcjhxx, data.getString(2));
				if (!"".equals(data.getString(3)))
					setTcbh(pcjhxx, data.getString(3));
				if (!"".equals(data.getString(4)))
					setCcbh(pcjhxx, data.getString(4));
				if (data.size() > 5 && !"".equals(data.getString(5))){
					HTXX htxx = saleDao.getSaleDataById(pcjhxx.getHtxxID());
					if (null != htxx){
						setZcID(htxx, data.getString(5));
					}
				}
				planDao.update(pcjhxx);
			}

		}
		return "success";
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
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getSftgywsh())) {
				pcjhxx.setSftgywsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String planApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getSftgjhsh())) {
				pcjhxx.setSftgjhsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String packBusinessApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgywsh())) {
				pcjhxx.setBzsftgywsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "[]";
	}

	public String packPlanApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgjhsh())) {
				pcjhxx.setBzsftgjhsh("Y");
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
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"});
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXExcelExporter(itemDao, saleDao, planDao, excel, outputStream);
		
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
		String[] row = new String[35];
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
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号", "优先级"});
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

}
