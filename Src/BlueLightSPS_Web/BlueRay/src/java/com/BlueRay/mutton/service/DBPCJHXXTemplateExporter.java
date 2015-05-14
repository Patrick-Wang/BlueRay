package com.BlueRay.mutton.service;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.imageio.ImageIO;

import org.apache.poi.hssf.usermodel.HSSFClientAnchor;
import org.apache.poi.hssf.usermodel.HSSFPatriarch;
import org.apache.poi.hssf.usermodel.HSSFPicture;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.jbarcode.JBarcode;
import org.jbarcode.encode.Code11Encoder;
import org.jbarcode.encode.Code128Encoder;
import org.jbarcode.encode.Code39Encoder;
import org.jbarcode.encode.EAN13Encoder;
import org.jbarcode.encode.InvalidAtributeException;
import org.jbarcode.encode.UPCAEncoder;
import org.jbarcode.encode.UPCEEncoder;
import org.jbarcode.paint.BaseLineTextPainter;
import org.jbarcode.paint.EAN13TextPainter;
import org.jbarcode.paint.UPCATextPainter;
import org.jbarcode.paint.UPCETextPainter;
import org.jbarcode.paint.WideRatioCodedPainter;
import org.jbarcode.paint.WidthCodedPainter;
import org.jbarcode.util.ImageUtil;

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
		yxj, // 优先级"
		scrq, // 生产日期"
		jhshyw, // 计划审核-业务"
		jhshjh, // 计划审核-计划"
		bzrq, // 包装日期"
		bzshyw, // 包装审核-业务"
		bzshjh, // 包装审核-计划"
		fhrq, // 发货日期"
		tcbh, // 投产编号"
		ccbh, // 出厂编号"
		end
	};

	
	final static Location mSLocs[] = new Location[Column.end.ordinal()];
	final static Location mULocs[] = new Location[Column.end.ordinal()];
	final static Location mYLocs[] = new Location[Column.end.ordinal()];
	final static Location mTALocs[] = new Location[Column.end.ordinal()];
	
	static {
		mSLocs[Column.id.ordinal()] = null;
		mSLocs[Column.hth.ordinal()] = new Location('D', 32+ 1); // 合同号 A
		mSLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mSLocs[Column.ggxh.ordinal()] = new Location('C', 4+ 1); // 规格型号 C
		mSLocs[Column.sl.ordinal()] = null; // 数量
		mSLocs[Column.zc.ordinal()] = new Location('C', 5+ 1); // 轴承 D
		mSLocs[Column.dfr.ordinal()] = null; // 单复绕
		mSLocs[Column.zdqdy.ordinal()] = new Location('H', 5+ 1); // 制动器电压 E
		mSLocs[Column.yylgg.ordinal()] = new Location('H', 4+ 1); // 曳引轮规格 F
		mSLocs[Column.jf.ordinal()] = new Location('N', 7+ 1); // 机房 G
		mSLocs[Column.bpqxh.ordinal()] = new Location('D', 33+ 1); // 变频器型号 H
		mSLocs[Column.bmqxh.ordinal()] = new Location('C', 6+ 1); // 编码器型号 I
		mSLocs[Column.dlcd.ordinal()] = new Location('H', 33+ 1); // 电缆长度 J
		mSLocs[Column.zxcd.ordinal()] = new Location('H', 32+ 1); // 闸线长度 K
		mSLocs[Column.mpzl.ordinal()] = new Location('D', 38+ 1); // 铭牌等资料 L
		mSLocs[Column.bz.ordinal()] = new Location('D', 36+ 1); // 备注 M
		mSLocs[Column.ddrq.ordinal()] = null; // 订单日期
		mSLocs[Column.zjdy.ordinal()] = new Location('H', 7 + 1); // 主机电压 N
		mSLocs[Column.zjys.ordinal()] = new Location('C', 7 + 1); // 主机颜色 O
		mSLocs[Column.zdqxh.ordinal()] = new Location('H', 6 + 1); // 制动器型号 P
		mSLocs[Column.zyz.ordinal()] = new Location('Q', 7 + 1); // 左/右置 Q
		mSLocs[Column.bzxdtgg.ordinal()] = new Location('D', 35 + 1); // 包装箱/底托规格 R
		mSLocs[Column.gh.ordinal()] = new Location('D', 34 + 1); // 工号 S
		mSLocs[Column.zzs.ordinal()] = new Location('H', 8 + 1); // 制造商 T
		mSLocs[Column.khqy.ordinal()] = null; // 客户区域
		mSLocs[Column.scrq.ordinal()] = null; // 生产日期
		mSLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mSLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mSLocs[Column.bzrq.ordinal()] = null; // 包装日期
		mSLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mSLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mSLocs[Column.fhrq.ordinal()] = null; // 发货日期
		mSLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
		mSLocs[Column.ccbh.ordinal()] = new Location('C', 8 + 1); // 出厂编号V 
		mSLocs[Column.yxj.ordinal()] = null; // 优先级 
	}
	
	static {
		mYLocs[Column.id.ordinal()] = null;
		mYLocs[Column.hth.ordinal()] = new Location('D', 33 /*+ 1*/); // 合同号 A
		mYLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mYLocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
		mYLocs[Column.sl.ordinal()] = null; // 数量
		mYLocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
		mYLocs[Column.dfr.ordinal()] = null; // 单复绕
		mYLocs[Column.zdqdy.ordinal()] = new Location('H', 5 /*+ 1*/); // 制动器电压 E
		mYLocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
		mYLocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
		mYLocs[Column.bpqxh.ordinal()] = new Location('D', 34 /*+ 1*/); // 变频器型号 H
		mYLocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
		mYLocs[Column.dlcd.ordinal()] = new Location('H', 34 /*+ 1*/); // 电缆长度 J
		mYLocs[Column.zxcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 闸线长度 K
		mYLocs[Column.mpzl.ordinal()] = new Location('D', 39 /*+ 1*/); // 铭牌等资料 L
		mYLocs[Column.bz.ordinal()] = new Location('D', 37 /*+ 1*/); // 备注 M
		mYLocs[Column.ddrq.ordinal()] = null; // 订单日期
		mYLocs[Column.zjdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 主机电压 N
		mYLocs[Column.zjys.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机颜色 O
		mYLocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
		mYLocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
		mYLocs[Column.bzxdtgg.ordinal()] = new Location('D', 36 /*+ 1*/); // 包装箱/底托规格 R
		mYLocs[Column.gh.ordinal()] = new Location('D', 35 /*+ 1*/); // 工号 S
		mYLocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
		mYLocs[Column.khqy.ordinal()] = null; // 客户区域
		mYLocs[Column.scrq.ordinal()] = null; // 生产日期
		mYLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mYLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mYLocs[Column.bzrq.ordinal()] = null; // 包装日期
		mYLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mYLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mYLocs[Column.fhrq.ordinal()] = null; // 发货日期
		mYLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
		mYLocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
		mYLocs[Column.yxj.ordinal()] = null; // 优先级 
	}
	
	static {
		mULocs[Column.id.ordinal()] = null;
		mULocs[Column.hth.ordinal()] = new Location('D', 32 /*+ 1*/); // 合同号 A
		mULocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mULocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
		mULocs[Column.sl.ordinal()] = null; // 数量
		mULocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
		mULocs[Column.dfr.ordinal()] = null; // 单复绕
		mULocs[Column.zdqdy.ordinal()] = new Location('H', 5 /*+ 1*/); // 制动器电压 E
		mULocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
		mULocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
		mULocs[Column.bpqxh.ordinal()] = new Location('D', 33 /*+ 1*/); // 变频器型号 H
		mULocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
		mULocs[Column.dlcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 电缆长度 J
		mULocs[Column.zxcd.ordinal()] = new Location('H', 32 /*+ 1*/); // 闸线长度 K
		mULocs[Column.mpzl.ordinal()] = new Location('D', 38 /*+ 1*/); // 铭牌等资料 L
		mULocs[Column.bz.ordinal()] = new Location('D', 36 /*+ 1*/); // 备注 M
		mULocs[Column.ddrq.ordinal()] = null; // 订单日期
		mULocs[Column.zjdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 主机电压 N
		mULocs[Column.zjys.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机颜色 O
		mULocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
		mULocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
		mULocs[Column.bzxdtgg.ordinal()] = new Location('D', 35 /*+ 1*/); // 包装箱/底托规格 R
		mULocs[Column.gh.ordinal()] = new Location('D', 34 /*+ 1*/); // 工号 S
		mULocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
		mULocs[Column.khqy.ordinal()] = null; // 客户区域
		mULocs[Column.scrq.ordinal()] = null; // 生产日期
		mULocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mULocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mULocs[Column.bzrq.ordinal()] = null; // 包装日期
		mULocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mULocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mULocs[Column.fhrq.ordinal()] = null; // 发货日期
		mULocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
		mULocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
		mULocs[Column.yxj.ordinal()] = null; // 优先级 
	}
	
	static {
		mTALocs[Column.id.ordinal()] = null;
		mTALocs[Column.hth.ordinal()] = new Location('D', 33 /*+ 1*/); // 合同号 A
		mTALocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
		mTALocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
		mTALocs[Column.sl.ordinal()] = null; // 数量
		mTALocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
		mTALocs[Column.dfr.ordinal()] = null; // 单复绕
		mTALocs[Column.zdqdy.ordinal()] = new Location('H', 5 /*+ 1*/); // 制动器电压 E
		mTALocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
		mTALocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
		mTALocs[Column.bpqxh.ordinal()] = new Location('D', 34 /*+ 1*/); // 变频器型号 H
		mTALocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
		mTALocs[Column.dlcd.ordinal()] = new Location('H', 34 /*+ 1*/); // 电缆长度 J
		mTALocs[Column.zxcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 闸线长度 K
		mTALocs[Column.mpzl.ordinal()] = new Location('D', 39 /*+ 1*/); // 铭牌等资料 L
		mTALocs[Column.bz.ordinal()] = new Location('D', 37 /*+ 1*/); // 备注 M
		mTALocs[Column.ddrq.ordinal()] = null; // 订单日期
		mTALocs[Column.zjdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 主机电压 N
		mTALocs[Column.zjys.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机颜色 O
		mTALocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
		mTALocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
		mTALocs[Column.bzxdtgg.ordinal()] = new Location('D', 36 /*+ 1*/); // 包装箱/底托规格 R
		mTALocs[Column.gh.ordinal()] = new Location('D', 35 /*+ 1*/); // 工号 S
		mTALocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
		mTALocs[Column.khqy.ordinal()] = null; // 客户区域
		mTALocs[Column.scrq.ordinal()] = null; // 生产日期
		mTALocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
		mTALocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
		mTALocs[Column.bzrq.ordinal()] = null; // 包装日期
		mTALocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
		mTALocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
		mTALocs[Column.fhrq.ordinal()] = null; // 发货日期
		mTALocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
		mTALocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
		mTALocs[Column.yxj.ordinal()] = null; // 优先级 
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
		Calendar cal = Calendar.getInstance();
		String[] ret = new String[35];
		Location rq = new Location('A', 2);
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
				sheet = workbook.cloneSheet(3);
				locs = mYLocs;
			} else if ("U".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
					.substring(0, 1))) {
				sheet = workbook.cloneSheet(4);
				locs = mULocs;
			} else if (ret[Column.ggxh.ordinal()].length() > 1
					&& "TA".equalsIgnoreCase(ret[Column.ggxh.ordinal()]
							.substring(0, 2))) {
				sheet = workbook.cloneSheet(2);
				locs = mTALocs;
			}
			if (sheet != null) {
				updateTemplate(ret, locs, sheet);
				String tcrq = sheet.getRow(rq.getX()).getCell(rq.getY())
						.getStringCellValue();

				tcrq = tcrq.replace(" ", "")
						.replace("投", "                                                          投")
						.replace("年", " " + cal.get(Calendar.YEAR) + "年")
						.replace("月日", " " + (cal.get(Calendar.MONTH) + 1) + "月" + " " + cal.get(Calendar.DAY_OF_MONTH) + "日");
				sheet.getRow(rq.getX()).getCell(rq.getY()).setCellValue(tcrq);

				if (!ret[Column.tcbh.ordinal()].isEmpty()) {

					JBarcode localJBarcode = new JBarcode(
							Code128Encoder.getInstance(),
							WidthCodedPainter.getInstance(),
							BaseLineTextPainter.getInstance());

					localJBarcode.setShowCheckDigit(false);

					BufferedImage localBufferedImage;
					try {
						localJBarcode.setBarHeight(20);
						localJBarcode.setXDimension(0.4);
						localBufferedImage = localJBarcode
								.createBarcode(ret[Column.tcbh.ordinal()]);
						ByteArrayOutputStream byteArrayOut = new ByteArrayOutputStream();

						ImageIO.write(localBufferedImage, "PNG", byteArrayOut);
						// ImageUtil.encodeAndWrite(localBufferedImage,
						// ImageUtil.PNG, byteArrayOut, 96, 96);

						int pictureIdx1 = workbook.addPicture(byteArrayOut.toByteArray(),
								HSSFWorkbook.PICTURE_TYPE_PNG);
						
						// 画图的顶级管理器，一个sheet只能获取一个（一定要注意这点）
						HSSFPatriarch patriarch = sheet
								.createDrawingPatriarch();
						
						// anchor主要用于设置图片的属性
						HSSFClientAnchor anchor = new HSSFClientAnchor(10, 6,
								0, 0, (short) 14, 2, (short) 16, 6);
						anchor.setAnchorType(3);
						
						// 插入图片
						HSSFPicture pic = patriarch.createPicture(
								anchor,
								pictureIdx1);
						pic.resize();

					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				// ImageUtil.encodeAndWrite(localBufferedImage, ImageUtil.PNG,
				// arg2);

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
