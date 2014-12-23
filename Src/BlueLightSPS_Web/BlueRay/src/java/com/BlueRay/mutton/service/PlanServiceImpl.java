package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.sql.Date;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.sf.json.JSONArray;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;



class DBPCJHXXExcelExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	
	public DBPCJHXXExcelExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() {
		
		HSSFWorkbook workbook = new HSSFWorkbook();
	    HSSFSheet sheet = workbook.createSheet(excel.getName());
	    Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();
	    List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
	    pcxxs.add(null);
	    //产生表格标题行
		  HSSFRow row = sheet.createRow(0);
		  String[] header = excel.getheader().get(0);
		  for (short i = 0; i < header.length; i++) {
		     HSSFCell cell = row.createCell(i);
		     HSSFRichTextString text = new HSSFRichTextString(header[i]);
		     cell.setCellValue(text);
		  }
	      
		String[] ret = new String[26];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i){
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			row = sheet.createRow(i + 1);
			for (int j = 1; j < ret.length; ++j){
				 HSSFCell cell = row.createCell(j);
				 HSSFRichTextString text = new HSSFRichTextString(ret[j]);
			     cell.setCellValue(text);
			}
			
		}
		try {
			workbook.write(os);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}

@Service
@Transactional("transactionManager")
public class PlanServiceImpl implements PlanService {

	@Autowired
	PlanDao planDao;

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private ItemDao itemDao;

	public static void setPCJH(String[] ret, PCJHXX pcjhxx, Map<Integer, HTXX> htxxMap, ItemDao itemDao){
		Integer id = pcjhxx.getHtxxID();
		SaleServiceImpl.setHtxx(ret, htxxMap.get(id), itemDao);
		ret[0] = pcjhxx.getPcjhID() + "";
		ret[4] = "1";// 数量
		ret[17] = (null != pcjhxx.getJhscrq()) ? pcjhxx.getJhscrq()
				.toString() : "";
		ret[18] = "Y".equals(pcjhxx.getSftgywsh()) ? "√" : "×";
		ret[19] = "Y".equals(pcjhxx.getSftgjhsh()) ? "√" : "×";
		ret[20] = (null != pcjhxx.getJhbzrq()) ? pcjhxx.getJhbzrq()
				.toString() : "";
		ret[21] = "Y".equals(pcjhxx.getBzsftgywsh()) ? "√" : "×";
		ret[22] = "Y".equals(pcjhxx.getBzsftgjhsh()) ? "√" : "×";
		ret[23] = (null != pcjhxx.getJhfhrq()) ? pcjhxx.getJhfhrq()
				.toString() : "";
		ret[24] = pcjhxx.getTcbh();
		ret[25] = pcjhxx.getCcbh();
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
//		Integer id;
//		
//		for (int i = pcxxs.size() - 1; i >= 0; --i) {
//			pcjhxx = pcxxs.get(i);
//			if (null != pcjhxx) {
//				id = pcjhxx.getHtxxID();
//				if (!htxxMap.containsKey(id)) {
//					htxxMap.put(id, saleDao.getSaleDataById(id));
//				}
//				if (htxxMap.get(id) == null) {
//					planDao.delete(pcjhxx);
//					pcxxs.remove(i);
//				}
//			}else{
//				pcxxs.remove(i);
//			}
//		}
		
		PCJHXX pcjhxx;
		String[][] ret = new String[pcxxs.size()][26];
		for (int i = pcxxs.size() - 1; i >= 0; --i) {
			pcjhxx = pcxxs.get(i);
			setPCJH(ret[i], pcjhxx, htxxMap, itemDao);
			
//			id = pcjhxx.getHtxxID();
//			SaleServiceImpl.setHtxx(ret[i], htxxMap.get(id), itemDao);
//			ret[i][0] = pcjhxx.getPcjhID() + "";
//			ret[i][4] = "1";// 数量
//			ret[i][17] = (null != pcjhxx.getJhscrq()) ? pcjhxx.getJhscrq()
//					.toString() : "";
//			ret[i][18] = "Y".equals(pcjhxx.getSftgywsh()) ? "√" : "×";
//			ret[i][19] = "Y".equals(pcjhxx.getSftgjhsh()) ? "√" : "×";
//			ret[i][20] = (null != pcjhxx.getJhbzrq()) ? pcjhxx.getJhbzrq()
//					.toString() : "";
//			ret[i][21] = "Y".equals(pcjhxx.getBzsftgywsh()) ? "√" : "×";
//			ret[i][22] = "Y".equals(pcjhxx.getBzsftgjhsh()) ? "√" : "×";
//			ret[i][23] = (null != pcjhxx.getJhfhrq()) ? pcjhxx.getJhfhrq()
//					.toString() : "";
//			ret[i][24] = pcjhxx.getTcbh();
//			ret[i][25] = pcjhxx.getCcbh();

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
		return "success";
	}

	public String planApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getSftgjhsh())) {
				pcjhxx.setSftgjhsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String packBusinessApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgywsh())) {
				pcjhxx.setBzsftgywsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String packPlanApprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if (!"Y".equals(pcjhxx.getBzsftgjhsh())) {
				pcjhxx.setBzsftgjhsh("Y");
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String businessUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getSftgywsh())) {
				pcjhxx.setSftgywsh("N");
				pcjhxx.setJhscrq(null);
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String planUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getSftgjhsh())) {
				pcjhxx.setSftgjhsh("N");
				pcjhxx.setJhscrq(null);
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String packBusinessUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getBzsftgywsh())) {
				pcjhxx.setBzsftgywsh("N");
				pcjhxx.setJhbzrq(null);
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String packPlanUnapprove(JSONArray rows) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			PCJHXX pcjhxx = planDao.getDataById(Integer.valueOf(rows.getInt(i)));
			if ("Y".equals(pcjhxx.getBzsftgjhsh())) {
				pcjhxx.setBzsftgjhsh("N");
				pcjhxx.setJhbzrq(null);
				planDao.update(pcjhxx);
			}
		}
		return "success";
	}

	public String export(OutputStream outputStream, Integer col, Boolean asc) {
		AbstractExcel<PCJHXX> excel = null;
		if (col >= 0){
			excel = planDao.getPcjhExcel(PCJHXX.class.getDeclaredFields()[col + 1].getName(), asc);
		}
		else{
			excel = planDao.getPcjhExcel(null, false);
		}
		excel.addHeader(new String[]{"合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"});
		IExcelExporter<PCJHXX> exportor = new DBPCJHXXExcelExporter(itemDao, saleDao, planDao, excel, outputStream);
		exportor.exports();
		try {
			outputStream.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "success";
	}

}
