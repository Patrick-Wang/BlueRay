package com.BlueRay.mutton.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.net.URISyntaxException;
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
	private static String path = null;
	static 
	{
		try {
			path = new URI(DBPCJHXXTemplateExporter.class
					.getClassLoader().getResource("").getPath()).getPath() + "META-INF/template.xls";
			System.out.println(path);
		} catch (URISyntaxException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	static class Location{
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

	
	final static Location mSLocs[] = new Location[Column.end.ordinal()];
	final static Location mULocs[] = new Location[Column.end.ordinal()];
	final static Location mYLocs[] = new Location[Column.end.ordinal()];
	final static Location mTALocs[] = new Location[Column.end.ordinal()];
	
	static {
		mSLocs[Column.id.ordinal()] = null;
		mSLocs[Column.hth.ordinal()] = new Location('D', 32); // 合同号 A
		mSLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mSLocs[Column.ggxh.ordinal()] = new Location('C', 4); // 规格型号 C
		mSLocs[Column.sl.ordinal()] = null; // 数量
		mSLocs[Column.zc.ordinal()] = new Location('C', 5); // 轴承 D
		mSLocs[Column.dfr.ordinal()] = null; // 单复绕
		mSLocs[Column.zdqdy.ordinal()] = new Location('H', 5); // 制动器电压 E
		mSLocs[Column.yylgg.ordinal()] = new Location('H', 4); // 曳引轮规格 F
		mSLocs[Column.jf.ordinal()] = new Location('N', 7); // 机房 G
		mSLocs[Column.bpqxh.ordinal()] = new Location('D', 33); // 变频器型号 H
		mSLocs[Column.bmqxh.ordinal()] = new Location('C', 6); // 编码器型号 I
		mSLocs[Column.dlcd.ordinal()] = new Location('H', 33); // 电缆长度 J
		mSLocs[Column.zxcd.ordinal()] = new Location('H', 32); // 闸线长度 K
		mSLocs[Column.mpzl.ordinal()] = new Location('D', 38); // 铭牌等资料 L
		mSLocs[Column.bz.ordinal()] = new Location('D', 36); // 备注 M
		mSLocs[Column.ddrq.ordinal()] = null; // 订单日期
		mSLocs[Column.zjdy.ordinal()] = new Location('H', 7); // 主机电压 N
		mSLocs[Column.zjys.ordinal()] = new Location('C', 7); // 主机颜色 O
		mSLocs[Column.zdqxh.ordinal()] = new Location('H', 6); // 制动器型号 P
		mSLocs[Column.zyz.ordinal()] = new Location('Q', 7); // 左/右置 Q
		mSLocs[Column.bzxdtgg.ordinal()] = new Location('D', 35); // 包装箱/底托规格 R
		mSLocs[Column.gh.ordinal()] = new Location('D', 34); // 工号 S
		mSLocs[Column.zzs.ordinal()] = new Location('H', 8); // 制造商 T
		mSLocs[Column.khqy.ordinal()] = null; // 客户区域
		mSLocs[Column.scrq.ordinal()] = null; // 生产日期
		mSLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mSLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mSLocs[Column.bzrq.ordinal()] = null; // 包装日期
		mSLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mSLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mSLocs[Column.fhrq.ordinal()] = null; // 发货日期
		mSLocs[Column.tcbh.ordinal()] = null; // 投产编号
		mSLocs[Column.ccbh.ordinal()] = new Location('C', 3); // 出厂编号 U
		mSLocs[Column.yxj.ordinal()] = new Location('C', 8); // 优先级 V
	}
	
	static {
		mYLocs[Column.id.ordinal()] = null;
		mYLocs[Column.hth.ordinal()] = new Location('D', 33); // 合同号 A
		mYLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mYLocs[Column.ggxh.ordinal()] = new Location('C', 4); // 规格型号 C
		mYLocs[Column.sl.ordinal()] = null; // 数量
		mYLocs[Column.zc.ordinal()] = new Location('C', 5); // 轴承 D
		mYLocs[Column.dfr.ordinal()] = null; // 单复绕
		mYLocs[Column.zdqdy.ordinal()] = new Location('H', 5); // 制动器电压 E
		mYLocs[Column.yylgg.ordinal()] = new Location('H', 4); // 曳引轮规格 F
		mYLocs[Column.jf.ordinal()] = new Location('N', 7); // 机房 G
		mYLocs[Column.bpqxh.ordinal()] = new Location('D', 34); // 变频器型号 H
		mYLocs[Column.bmqxh.ordinal()] = new Location('C', 6); // 编码器型号 I
		mYLocs[Column.dlcd.ordinal()] = new Location('H', 34); // 电缆长度 J
		mYLocs[Column.zxcd.ordinal()] = new Location('H', 33); // 闸线长度 K
		mYLocs[Column.mpzl.ordinal()] = new Location('D', 39); // 铭牌等资料 L
		mYLocs[Column.bz.ordinal()] = new Location('D', 37); // 备注 M
		mYLocs[Column.ddrq.ordinal()] = null; // 订单日期
		mYLocs[Column.zjdy.ordinal()] = new Location('H', 7); // 主机电压 N
		mYLocs[Column.zjys.ordinal()] = new Location('C', 7); // 主机颜色 O
		mYLocs[Column.zdqxh.ordinal()] = new Location('H', 6); // 制动器型号 P
		mYLocs[Column.zyz.ordinal()] = new Location('Q', 7); // 左/右置 Q
		mYLocs[Column.bzxdtgg.ordinal()] = new Location('D', 36); // 包装箱/底托规格 R
		mYLocs[Column.gh.ordinal()] = new Location('D', 35); // 工号 S
		mYLocs[Column.zzs.ordinal()] = new Location('H', 8); // 制造商 T
		mYLocs[Column.khqy.ordinal()] = null; // 客户区域
		mYLocs[Column.scrq.ordinal()] = null; // 生产日期
		mYLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mYLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mYLocs[Column.bzrq.ordinal()] = null; // 包装日期
		mYLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mYLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mYLocs[Column.fhrq.ordinal()] = null; // 发货日期
		mYLocs[Column.tcbh.ordinal()] = null; // 投产编号
		mYLocs[Column.ccbh.ordinal()] = new Location('C', 3); // 出厂编号 U
		mYLocs[Column.yxj.ordinal()] = new Location('C', 8); // 优先级 V
	}
	
	static {
		mULocs[Column.id.ordinal()] = null;
		mULocs[Column.hth.ordinal()] = new Location('D', 32); // 合同号 A
		mULocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mULocs[Column.ggxh.ordinal()] = new Location('C', 4); // 规格型号 C
		mULocs[Column.sl.ordinal()] = null; // 数量
		mULocs[Column.zc.ordinal()] = new Location('C', 5); // 轴承 D
		mULocs[Column.dfr.ordinal()] = null; // 单复绕
		mULocs[Column.zdqdy.ordinal()] = new Location('H', 5); // 制动器电压 E
		mULocs[Column.yylgg.ordinal()] = new Location('H', 4); // 曳引轮规格 F
		mULocs[Column.jf.ordinal()] = new Location('N', 7); // 机房 G
		mULocs[Column.bpqxh.ordinal()] = new Location('D', 33); // 变频器型号 H
		mULocs[Column.bmqxh.ordinal()] = new Location('C', 6); // 编码器型号 I
		mULocs[Column.dlcd.ordinal()] = new Location('H', 33); // 电缆长度 J
		mULocs[Column.zxcd.ordinal()] = new Location('H', 32); // 闸线长度 K
		mULocs[Column.mpzl.ordinal()] = new Location('D', 38); // 铭牌等资料 L
		mULocs[Column.bz.ordinal()] = new Location('D', 36); // 备注 M
		mULocs[Column.ddrq.ordinal()] = null; // 订单日期
		mULocs[Column.zjdy.ordinal()] = new Location('H', 7); // 主机电压 N
		mULocs[Column.zjys.ordinal()] = new Location('C', 7); // 主机颜色 O
		mULocs[Column.zdqxh.ordinal()] = new Location('H', 6); // 制动器型号 P
		mULocs[Column.zyz.ordinal()] = new Location('Q', 7); // 左/右置 Q
		mULocs[Column.bzxdtgg.ordinal()] = new Location('D', 35); // 包装箱/底托规格 R
		mULocs[Column.gh.ordinal()] = new Location('D', 34); // 工号 S
		mULocs[Column.zzs.ordinal()] = new Location('H', 8); // 制造商 T
		mULocs[Column.khqy.ordinal()] = null; // 客户区域
		mULocs[Column.scrq.ordinal()] = null; // 生产日期
		mULocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mULocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mULocs[Column.bzrq.ordinal()] = null; // 包装日期
		mULocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mULocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mULocs[Column.fhrq.ordinal()] = null; // 发货日期
		mULocs[Column.tcbh.ordinal()] = null; // 投产编号
		mULocs[Column.ccbh.ordinal()] = new Location('C', 3); // 出厂编号 U
		mULocs[Column.yxj.ordinal()] = new Location('C', 8); // 优先级 V
	}
	
	static {
		mTALocs[Column.id.ordinal()] = null;
		mTALocs[Column.hth.ordinal()] = new Location('D', 33); // 合同号 A
		mTALocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mTALocs[Column.ggxh.ordinal()] = new Location('C', 4); // 规格型号 C
		mTALocs[Column.sl.ordinal()] = null; // 数量
		mTALocs[Column.zc.ordinal()] = new Location('C', 5); // 轴承 D
		mTALocs[Column.dfr.ordinal()] = null; // 单复绕
		mTALocs[Column.zdqdy.ordinal()] = new Location('H', 5); // 制动器电压 E
		mTALocs[Column.yylgg.ordinal()] = new Location('H', 4); // 曳引轮规格 F
		mTALocs[Column.jf.ordinal()] = new Location('N', 7); // 机房 G
		mTALocs[Column.bpqxh.ordinal()] = new Location('D', 34); // 变频器型号 H
		mTALocs[Column.bmqxh.ordinal()] = new Location('C', 6); // 编码器型号 I
		mTALocs[Column.dlcd.ordinal()] = new Location('H', 34); // 电缆长度 J
		mTALocs[Column.zxcd.ordinal()] = new Location('H', 33); // 闸线长度 K
		mTALocs[Column.mpzl.ordinal()] = new Location('D', 39); // 铭牌等资料 L
		mTALocs[Column.bz.ordinal()] = new Location('D', 37); // 备注 M
		mTALocs[Column.ddrq.ordinal()] = null; // 订单日期
		mTALocs[Column.zjdy.ordinal()] = new Location('H', 7); // 主机电压 N
		mTALocs[Column.zjys.ordinal()] = new Location('C', 7); // 主机颜色 O
		mTALocs[Column.zdqxh.ordinal()] = new Location('H', 6); // 制动器型号 P
		mTALocs[Column.zyz.ordinal()] = new Location('Q', 7); // 左/右置 Q
		mTALocs[Column.bzxdtgg.ordinal()] = new Location('D', 36); // 包装箱/底托规格 R
		mTALocs[Column.gh.ordinal()] = new Location('D', 35); // 工号 S
		mTALocs[Column.zzs.ordinal()] = new Location('H', 8); // 制造商 T
		mTALocs[Column.khqy.ordinal()] = null; // 客户区域
		mTALocs[Column.scrq.ordinal()] = null; // 生产日期
		mTALocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mTALocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mTALocs[Column.bzrq.ordinal()] = null; // 包装日期
		mTALocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mTALocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mTALocs[Column.fhrq.ordinal()] = null; // 发货日期
		mTALocs[Column.tcbh.ordinal()] = null; // 投产编号
		mTALocs[Column.ccbh.ordinal()] = new Location('C', 3); // 出厂编号 U
		mTALocs[Column.yxj.ordinal()] = new Location('C', 8); // 优先级 V
	}
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
			
			Location locs[] = null;
			HSSFSheet sheet = null;
			if ("S".equalsIgnoreCase(ret[Column.ggxh.ordinal()].substring(0, 1))) {
				sheet = workbook.cloneSheet(1);
				locs = mSLocs;
			} else if ("Y".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
					.substring(0, 1))) {
				//updateYTemplate(ret, workbook.cloneSheet(3));
				sheet = workbook.cloneSheet(3);
				locs = mYLocs;
			} else if ("U".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
					.substring(0, 1))) {
				sheet = workbook.cloneSheet(4);
				locs = mULocs;
				//updateUTemplate(ret, workbook.cloneSheet(4));
			} else if (ret[Column.ggxh.ordinal()].length() > 1
					&& "TA".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
							.substring(0, 2))) {
				sheet = workbook.cloneSheet(2);
				locs = mTALocs;
				//updateTATemplate(ret, workbook.cloneSheet(2));
			}
			if (sheet != null){
				updateTemplate(ret, locs, sheet);
			}

		}
		workbook.removeSheetAt(4);
		workbook.removeSheetAt(3);
		workbook.removeSheetAt(2);
		workbook.removeSheetAt(1);
		workbook.removeSheetAt(0);
		workbook.write(os);
	}

	private void updateTemplate(String[] ret, Location[] locs, HSSFSheet sheet) {
		for (int i = Column.hth.ordinal(); i < Column.end.ordinal(); ++i) {
			if (null != locs[i]) {
				sheet.getRow(locs[i].getX()).getCell(locs[i].getY())
						.setCellValue(ret[i]);
			}
		}
	}

}
