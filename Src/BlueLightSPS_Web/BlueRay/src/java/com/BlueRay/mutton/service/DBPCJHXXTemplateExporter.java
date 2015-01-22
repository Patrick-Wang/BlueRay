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
	private static String path = DBPCJHXXTemplateExporter.class
			.getClassLoader().getResource("/").getPath().substring(1)
			+ "META-INF/template.xls";

	class Location{
		int x;
		int y;
		public Location(char y, int x) {
			this.x = x - 1;
			this.y = y - 'A';
		}
		public int getX() {
			return x;
		}
		public int getY() {
			return y;
		}
		
	}
	
	enum Column {
		id, 
		hth, // 合同号"
		khmc, // 客户名称"
		ggxh, // 规格型号"
		sl, // 数量"
		zc, // 轴承"
		dfr, // 单复绕"
		zdqdy, // 制动器电压"
		yylgg, // 曳引轮规格"
		jf, // 机房"
		bpqxh, // 变频器型号"
		bmqxh, // 编码器型号"
		dlcd, // 电缆长度"
		zxcd, // 闸线长度"
		mpzl, // 铭牌等资料"
		bz, // 备注"
		ddrq, // 订单日期"
		zjdy, // 主机电压
		zjys, // 主机颜色
		zdqxh, // 制动器型号
		zyz, // 左/右置
		bzxdtgg, // 包装箱/底托规格
		gh, // 工号
		zzs, // 制造商
		khqy, // 客户区域
		scrq, // 生产日期"
		jhshyw, // 计划审核-业务"
		jhshjh, // 计划审核-计划"
		bzrq, // 包装日期"
		bzshyw, // 包装审核-业务"
		bzshjh, // 包装审核-计划"
		fhrq, // 发货日期"
		tcbh, // 投产编号"
		ccbh, // 出厂编号"
		yxj, // 优先级"
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

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				path)));

		String[] ret = new String[35];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			if (null == ret[Column.ggxh.ordinal()]
					&& ret[Column.ggxh.ordinal()].isEmpty()) {
				continue;
			}
			if ("S".equalsIgnoreCase(ret[Column.ggxh.ordinal()].substring(0, 1))) {
				updateSTemplate(ret, workbook.cloneSheet(1));
			} else if ("Y".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
					.substring(0, 1))) {
				updateYTemplate(ret, workbook.cloneSheet(3));
			} else if ("U".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
					.substring(0, 1))) {
				updateUTemplate(ret, workbook.cloneSheet(4));
			} else if (ret[Column.ggxh.ordinal()].length() > 1
					&& "TA".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
							.substring(0, 1))) {
				updateTATemplate(ret, workbook.cloneSheet(2));
			}

		}
		workbook.removeSheetAt(4);
		workbook.removeSheetAt(3);
		workbook.removeSheetAt(2);
		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);
		workbook.write(os);
	}

	private void updateTATemplate(String[] ret, HSSFSheet sheet) {
		// TODO Auto-generated method stub

	}

	private void updateUTemplate(String[] ret, HSSFSheet sheet) {
		// TODO Auto-generated method stub

	}

	private void updateYTemplate(String[] ret, HSSFSheet sheet) {
		// TODO Auto-generated method stub

	}

	private void updateSTemplate(String[] ret, HSSFSheet sheet) {
		Location locs[] = new Location[]{
				new Location('D', 32),//A
				new Location('H', 3),//B
				new Location('C', 4),//C
				null,
				new Location('C', 5),//D
				null,
				new Location('H', 5),//E
				new Location('H', 4),//F
				new Location('N', 7),//G
				
				new Location('D', 33),//H
				new Location('C', 6),//I
				new Location('H', 33),//J
				new Location('H', 32),//K
				new Location('D', 38),//L
				
				new Location('D', 36),//M
				null,
				new Location('H', 7),//N
				new Location('C', 7),//O
				new Location('H', 6),//P
				new Location('Q', 7),//Q
				new Location('D', 35),//R
				new Location('D', 34),//S
				new Location('H', 8),//T
				null,
				null,
				null,
				null,
				null,
				null,
				null,
				null,
				null,
				new Location('C', 3),//U
				new Location('C', 8)//V
		};
		for (int i = 0; i < locs.length; ++i) {
			if (null != locs[i]) {
				sheet.getRow(locs[i].getX()).getCell(locs[i].getY())
						.setCellValue(ret[i + Column.hth.ordinal()]);
			}
		}

	}

}
