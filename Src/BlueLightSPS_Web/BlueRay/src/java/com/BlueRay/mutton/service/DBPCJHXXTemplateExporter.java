package com.BlueRay.mutton.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

public class DBPCJHXXTemplateExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	private static String path = DBPCJHXXTemplateExporter.class.getClassLoader().getResource("/").getPath().substring(1) + "META-INF/template.xls";
	enum Column{
		hth,	//合同号"
		khmc,	//客户名称"
		ggxh,	//规格型号"
		sl,	//数量"
		zc,	//轴承"
		dfr,	//单复绕"
		zdqdy,	//制动器电压"
		yylgg,	//曳引轮规格"
		jf,	//机房"
		bpqxh,	//变频器型号"
		bmqxh,	//编码器型号"
		dlcd,	//电缆长度"
		zxcd,	//闸线长度"
		mpzl,	//铭牌等资料"
		bz,	//备注"
		ddrq,	//订单日期"
		zjdy,	//主机电压
		zjys,	//主机颜色
		zdqxh,	//制动器型号
		zyz,	// 左/右置
		bzxdtgg,// 包装箱/底托规格
		gh,	// 工号
		zzs,	// 制造商
		khqy,	// 客户区域
		scrq,	//生产日期"
		jhshyw,	//计划审核-业务"
		jhshjh,	//计划审核-计划"
		bzrq,	//包装日期"
		bzshyw,	//包装审核-业务"
		bzshjh,	//包装审核-计划"
		fhrq,	//发货日期"
		tcbh,	//投产编号"
		ccbh,	//出厂编号"
		yxj,	//优先级"
		end
	};
	
	public DBPCJHXXTemplateExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() throws IOException {
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		//os.write(new byte[] { (byte) 0xEF, (byte) 0xBB, (byte) 0xBF });

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File("F:/tt.xls")));
	    HSSFSheet sheet = workbook.createSheet(excel.getName());
	    
		String[] ret = new String[35];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
//			firstCol = true;
//			for (int j = 1; j < ret.length; ++j) {
//				if (firstCol) {
//					firstCol = false;
//				} else {
//					builder.append(",");
//				}
//				builder.append(ret[j]);
//			}
//			builder.append("\r\n");

//			os.write(builder.toString().getBytes("utf-8"));
//			builder = new StringBuilder();
//			os.flush();

		}
	}

}
