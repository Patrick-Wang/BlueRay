package com.BlueRay.mutton.service;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import java.net.URISyntaxException;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.w3c.dom.Node;

import javax.imageio.ImageIO;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

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
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;
import com.BlueRay.mutton.tool.PoiUtil;

public class DBPCJHXXTemplateExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	private static String pathTemplate = null;
	private static String pathMapfile = null;
	static 
	{
		try {
			String basePath = new URI(DBPCJHXXTemplateExporter.class
					.getClassLoader().getResource("").getPath()).getPath();
			pathTemplate = basePath + "META-INF/template.xls";
			pathMapfile = basePath + "META-INF/template.xml";
			System.out.println(pathTemplate);
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
	final static Location mVLocs[] = new Location[Column.end.ordinal()];
	final static Location mLLocs[] = new Location[Column.end.ordinal()];
	
//	static {
//		mSLocs[Column.id.ordinal()] = null;
//		mSLocs[Column.hth.ordinal()] = new Location('C', 32/*+ 1*/); // 合同号 A
//		mSLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mSLocs[Column.ggxh.ordinal()] = new Location('C', 4/*+ 1*/); // 规格型号 C
//		mSLocs[Column.sl.ordinal()] = null; // 数量
//		mSLocs[Column.zc.ordinal()] = new Location('C', 5/*+ 1*/); // 轴承 D
//		mSLocs[Column.dfr.ordinal()] = null; // 单复绕
//		mSLocs[Column.zdqdy.ordinal()] = new Location('H', 7/*+ 1*/); // 制动器电压 E
//		mSLocs[Column.yylgg.ordinal()] = new Location('H', 4/*+ 1*/); // 曳引轮规格 F
//		mSLocs[Column.jf.ordinal()] = new Location('N', 7/*+ 1*/); // 机房 G
//		mSLocs[Column.bpqxh.ordinal()] = new Location('C', 33/*+ 1*/); // 变频器型号 H
//		mSLocs[Column.bmqxh.ordinal()] = new Location('C', 6/*+ 1*/); // 编码器型号 I
//		mSLocs[Column.dlcd.ordinal()] = new Location('H', 33/*+ 1*/); // 电缆长度 J
//		mSLocs[Column.zxcd.ordinal()] = new Location('H', 32/*+ 1*/); // 闸线长度 K
//		mSLocs[Column.mpzl.ordinal()] = new Location('D', 38/*+ 1*/); // 铭牌等资料 L
//		mSLocs[Column.bz.ordinal()] = new Location('D', 36/*+ 1*/); // 备注 M
//		mSLocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mSLocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mSLocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mSLocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mSLocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mSLocs[Column.bzxdtgg.ordinal()] = new Location('D', 35 /*+ 1*/); // 包装箱/底托规格 R
//		mSLocs[Column.gh.ordinal()] = new Location('C', 34 /*+ 1*/); // 工号 S
//		mSLocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mSLocs[Column.khqy.ordinal()] = null; // 客户区域
//		mSLocs[Column.scrq.ordinal()] = null; // 生产日期
//		mSLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mSLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mSLocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mSLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mSLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mSLocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mSLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mSLocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mSLocs[Column.yxj.ordinal()] = null; // 优先级 
//	}
//	
//	static {
//		mYLocs[Column.id.ordinal()] = null;
//		mYLocs[Column.hth.ordinal()] = new Location('C', 33 /*+ 1*/); // 合同号 A
//		mYLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mYLocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
//		mYLocs[Column.sl.ordinal()] = null; // 数量
//		mYLocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
//		mYLocs[Column.dfr.ordinal()] = null; // 单复绕
//		mYLocs[Column.zdqdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 制动器电压 E
//		mYLocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
//		mYLocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
//		mYLocs[Column.bpqxh.ordinal()] = new Location('C', 34 /*+ 1*/); // 变频器型号 H
//		mYLocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
//		mYLocs[Column.dlcd.ordinal()] = new Location('H', 34 /*+ 1*/); // 电缆长度 J
//		mYLocs[Column.zxcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 闸线长度 K
//		mYLocs[Column.mpzl.ordinal()] = new Location('D', 39 /*+ 1*/); // 铭牌等资料 L
//		mYLocs[Column.bz.ordinal()] = new Location('D', 37 /*+ 1*/); // 备注 M
//		mYLocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mYLocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mYLocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mYLocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mYLocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mYLocs[Column.bzxdtgg.ordinal()] = new Location('D', 36 /*+ 1*/); // 包装箱/底托规格 R
//		mYLocs[Column.gh.ordinal()] = new Location('C', 35 /*+ 1*/); // 工号 S
//		mYLocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mYLocs[Column.khqy.ordinal()] = null; // 客户区域
//		mYLocs[Column.scrq.ordinal()] = null; // 生产日期
//		mYLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mYLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mYLocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mYLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mYLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mYLocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mYLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mYLocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mYLocs[Column.yxj.ordinal()] = null; // 优先级 
//	}
//	
//	static {
//		mULocs[Column.id.ordinal()] = null;
//		mULocs[Column.hth.ordinal()] = new Location('C', 32 /*+ 1*/); // 合同号 A
//		mULocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mULocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
//		mULocs[Column.sl.ordinal()] = null; // 数量
//		mULocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
//		mULocs[Column.dfr.ordinal()] = null; // 单复绕
//		mULocs[Column.zdqdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 制动器电压 E
//		mULocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
//		mULocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
//		mULocs[Column.bpqxh.ordinal()] = new Location('C', 33 /*+ 1*/); // 变频器型号 H
//		mULocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
//		mULocs[Column.dlcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 电缆长度 J
//		mULocs[Column.zxcd.ordinal()] = new Location('H', 32 /*+ 1*/); // 闸线长度 K
//		mULocs[Column.mpzl.ordinal()] = new Location('D', 38 /*+ 1*/); // 铭牌等资料 L
//		mULocs[Column.bz.ordinal()] = new Location('D', 36 /*+ 1*/); // 备注 M
//		mULocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mULocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mULocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mULocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mULocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mULocs[Column.bzxdtgg.ordinal()] = new Location('D', 35 /*+ 1*/); // 包装箱/底托规格 R
//		mULocs[Column.gh.ordinal()] = new Location('C', 34 /*+ 1*/); // 工号 S
//		mULocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mULocs[Column.khqy.ordinal()] = null; // 客户区域
//		mULocs[Column.scrq.ordinal()] = null; // 生产日期
//		mULocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mULocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mULocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mULocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mULocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mULocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mULocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mULocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mULocs[Column.yxj.ordinal()] = null; // 优先级 
//	}
//	
//	static {
//		mTALocs[Column.id.ordinal()] = null;
//		mTALocs[Column.hth.ordinal()] = new Location('C', 33 /*+ 1*/); // 合同号 A
//		mTALocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mTALocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
//		mTALocs[Column.sl.ordinal()] = null; // 数量
//		mTALocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
//		mTALocs[Column.dfr.ordinal()] = null; // 单复绕
//		mTALocs[Column.zdqdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 制动器电压 E
//		mTALocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
//		mTALocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
//		mTALocs[Column.bpqxh.ordinal()] = new Location('C', 34 /*+ 1*/); // 变频器型号 H
//		mTALocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
//		mTALocs[Column.dlcd.ordinal()] = new Location('H', 34 /*+ 1*/); // 电缆长度 J
//		mTALocs[Column.zxcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 闸线长度 K
//		mTALocs[Column.mpzl.ordinal()] = new Location('D', 39 /*+ 1*/); // 铭牌等资料 L
//		mTALocs[Column.bz.ordinal()] = new Location('D', 37 /*+ 1*/); // 备注 M
//		mTALocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mTALocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mTALocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mTALocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mTALocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mTALocs[Column.bzxdtgg.ordinal()] = new Location('D', 36 /*+ 1*/); // 包装箱/底托规格 R
//		mTALocs[Column.gh.ordinal()] = new Location('C', 35 /*+ 1*/); // 工号 S
//		mTALocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mTALocs[Column.khqy.ordinal()] = null; // 客户区域
//		mTALocs[Column.scrq.ordinal()] = null; // 生产日期
//		mTALocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mTALocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mTALocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mTALocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mTALocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mTALocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mTALocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mTALocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mTALocs[Column.yxj.ordinal()] = null; // 优先级 
//	}
//	
//	
//	static {
//		mVLocs[Column.id.ordinal()] = null;
//		mVLocs[Column.hth.ordinal()] = new Location('C', 32 /*+ 1*/); // 合同号 A
//		mVLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mVLocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
//		mVLocs[Column.sl.ordinal()] = null; // 数量
//		mVLocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
//		mVLocs[Column.dfr.ordinal()] = null; // 单复绕
//		mVLocs[Column.zdqdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 制动器电压 E
//		mVLocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
//		mVLocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
//		mVLocs[Column.bpqxh.ordinal()] = new Location('C', 33 /*+ 1*/); // 变频器型号 H
//		mVLocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
//		mVLocs[Column.dlcd.ordinal()] = new Location('H', 33 /*+ 1*/); // 电缆长度 J
//		mVLocs[Column.zxcd.ordinal()] = new Location('H', 32 /*+ 1*/); // 闸线长度 K
//		mVLocs[Column.mpzl.ordinal()] = new Location('D', 38 /*+ 1*/); // 铭牌等资料 L
//		mVLocs[Column.bz.ordinal()] = new Location('D', 36 /*+ 1*/); // 备注 M
//		mVLocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mVLocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mVLocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mVLocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mVLocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mVLocs[Column.bzxdtgg.ordinal()] = new Location('D', 35 /*+ 1*/); // 包装箱/底托规格 R
//		mVLocs[Column.gh.ordinal()] = new Location('C', 34 /*+ 1*/); // 工号 S
//		mVLocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mVLocs[Column.khqy.ordinal()] = null; // 客户区域
//		mVLocs[Column.scrq.ordinal()] = null; // 生产日期
//		mVLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mVLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mVLocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mVLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mVLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mVLocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mVLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mVLocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mVLocs[Column.yxj.ordinal()] = null; // 优先级 
//	}
//	
//	static {
//		mLLocs[Column.id.ordinal()] = null;
//		mLLocs[Column.hth.ordinal()] = new Location('C', 28 /*+ 1*/); // 合同号 A
//		mLLocs[Column.khmc.ordinal()] = new Location('H', 3); // 客户名称 B
//		mLLocs[Column.ggxh.ordinal()] = new Location('C', 4 /*+ 1*/); // 规格型号 C
//		mLLocs[Column.sl.ordinal()] = null; // 数量
//		mLLocs[Column.zc.ordinal()] = new Location('C', 5 /*+ 1*/); // 轴承 D
//		mLLocs[Column.dfr.ordinal()] = null; // 单复绕
//		mLLocs[Column.zdqdy.ordinal()] = new Location('H', 7 /*+ 1*/); // 制动器电压 E
//		mLLocs[Column.yylgg.ordinal()] = new Location('H', 4 /*+ 1*/); // 曳引轮规格 F
//		mLLocs[Column.jf.ordinal()] = new Location('N', 7 /*+ 1*/); // 机房 G
//		mLLocs[Column.bpqxh.ordinal()] = new Location('C', 29 /*+ 1*/); // 变频器型号 H
//		mLLocs[Column.bmqxh.ordinal()] = new Location('C', 6 /*+ 1*/); // 编码器型号 I
//		mLLocs[Column.dlcd.ordinal()] = new Location('H', 29 /*+ 1*/); // 电缆长度 J
//		mLLocs[Column.zxcd.ordinal()] = new Location('H', 28 /*+ 1*/); // 闸线长度 K
//		mLLocs[Column.mpzl.ordinal()] = new Location('D', 34 /*+ 1*/); // 铭牌等资料 L
//		mLLocs[Column.bz.ordinal()] = new Location('D', 32 /*+ 1*/); // 备注 M
//		mLLocs[Column.ddrq.ordinal()] = null; // 订单日期
//		mLLocs[Column.zjdy.ordinal()] = new Location('C', 7 /*+ 1*/); // 主机电压 N
//		mLLocs[Column.zjys.ordinal()] = new Location('H', 5 /*+ 1*/); // 主机颜色 O
//		mLLocs[Column.zdqxh.ordinal()] = new Location('H', 6 /*+ 1*/); // 制动器型号 P
//		mLLocs[Column.zyz.ordinal()] = new Location('Q', 7 /*+ 1*/); // 左/右置 Q
//		mLLocs[Column.bzxdtgg.ordinal()] = new Location('D', 31 /*+ 1*/); // 包装箱/底托规格 R
//		mLLocs[Column.gh.ordinal()] = new Location('C', 30 /*+ 1*/); // 工号 S
//		mLLocs[Column.zzs.ordinal()] = new Location('H', 8 /*+ 1*/); // 制造商 T
//		mLLocs[Column.khqy.ordinal()] = null; // 客户区域
//		mLLocs[Column.scrq.ordinal()] = null; // 生产日期
//		mLLocs[Column.jhshyw.ordinal()] = null; // 计划审核-业务
//		mLLocs[Column.jhshjh.ordinal()] = null; // 计划审核-计划
//		mLLocs[Column.bzrq.ordinal()] = null; // 包装日期
//		mLLocs[Column.bzshyw.ordinal()] = null; // 包装审核-业务
//		mLLocs[Column.bzshjh.ordinal()] = null; // 包装审核-计划
//		mLLocs[Column.fhrq.ordinal()] = null; // 发货日期
//		mLLocs[Column.tcbh.ordinal()] = new Location('C', 3); // 投产编号U
//		mLLocs[Column.ccbh.ordinal()] = new Location('C', 8 /*+ 1*/); // 出厂编号V 
//		mLLocs[Column.yxj.ordinal()] = null; // 优先级 
//	}

	private static Set<String> getNames(NodeList names) {
		Set<String> nameSet = new HashSet<String>();
		for (int i = 0; i < names.getLength(); i++) {
			nameSet.add(names.item(i).getFirstChild()
					.getNodeValue());
		}
		return nameSet;
	}
	
	
	private static void parseCellMap(Map<Integer, Location[]> locations, Element field){
		String val = field.getAttribute("name");
		Column col = null;
		try{
			col = Column.valueOf(val);
			NodeList cells = field.getElementsByTagName("cell");
			if (cells.getLength() > 0){
				Location locs[] = new Location[cells.getLength()];
				locations.put(col.ordinal(), locs);
				 for (int i = 0; i < cells.getLength(); i++)  
		         {
					 Element cell = (Element) cells.item(i);
					 try{
						 locs[i] = new Location(
								 cell.getAttribute("col").charAt(0),
								 Integer.valueOf(cell.getAttribute("row"))); 
					 }catch(Exception e){
						 
					 }
		         }
			}
		}
		catch(Exception e){
			
		}
	}
	
	private static void parseSheet(Element sheet){
		 Set<String> names = getNames(sheet.getElementsByTagName("sheet_name"));
		 NodeList fields = sheet.getElementsByTagName("table_field");
		 Map<Integer, Location[]> locations = new HashMap<Integer, Location[]>();
		 
		 for (int i = 0; i < fields.getLength(); i++)  
         {
			 parseCellMap(locations, (Element) fields.item(i));
         }
		 
		 for(String name: names){
			 DBTemplateMap.put(name, locations);
		 }		 
	}
	
	private static Map<String, Map<Integer, Location[]>> DBTemplateMap = new HashMap<String, Map<Integer, Location[]>>();
	static{
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();  
        try  
        {  
            DocumentBuilder db = dbf.newDocumentBuilder();  
            Document doc = db.parse(pathMapfile);  
  
            NodeList sheets = doc.getElementsByTagName("sheet");  
            for (int i = 0; i < sheets.getLength(); i++)  
            {  
                Node sheet = sheets.item(i);  
                parseSheet((Element) sheet);
            }  
        }  
        catch (Exception e)  
        {  
            e.printStackTrace();  
        }
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

	
	private String getLocMap(String ggxh){
		if (ggxh.length() > 2 && DBTemplateMap.containsKey(ggxh.substring(0, 3))) {
			return ggxh.substring(0, 3);
		} else if (ggxh.length() > 1 && DBTemplateMap.containsKey(ggxh.substring(0, 2))) {
			return ggxh.substring(0, 2);
		} else if (ggxh.length() > 0 && DBTemplateMap.containsKey(ggxh.substring(0, 1))) {
			return ggxh.substring(0, 1);
		} 
		return null;
	}
	
	public void exports() throws IOException {
		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				pathTemplate)));
		String[] ret = new String[35];
		Location rq = new Location('A', 2);
		int count = workbook.getNumberOfSheets();
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			if (null == ret[Column.ggxh.ordinal()]
					|| ret[Column.ggxh.ordinal()].isEmpty()) {
				System.out.println("row : " + i + "ggxh : " + ret[Column.ggxh.ordinal()] + " could not find template.");
				continue;
			}

			Map<Integer, Location[]> locations;
			HSSFSheet sheet = null;
			String type = getLocMap(ret[Column.ggxh.ordinal()]);
			if (null == type){
				continue;
			}
			
			int index = workbook.getSheetIndex(type);
			sheet = workbook.cloneSheet(index);
			locations = DBTemplateMap.get(type);

			
			if (sheet != null) {
				updateTemplate(ret, locations, sheet);

				try{
					Calendar calTmp = Calendar.getInstance();
					calTmp.setTime(Date.valueOf(ret[Column.scrq.ordinal()]));
					String tcrq = sheet.getRow(rq.getX()).getCell(rq.getY())
							.getStringCellValue();

					tcrq = tcrq.replace(" ", "")
							.replace("投", "                                                          投")
							.replace("年", " " + calTmp.get(Calendar.YEAR) + "年")
							.replace("月日", " " + (calTmp.get(Calendar.MONTH) + 1) + "月" + " " + calTmp.get(Calendar.DAY_OF_MONTH) + "日");
					sheet.getRow(rq.getX()).getCell(rq.getY()).setCellValue(tcrq);
				} catch(Exception e){
					e.printStackTrace();
				}
				
				if (!ret[Column.tcbh.ordinal()].isEmpty()) {

					JBarcode localJBarcode = new JBarcode(
							Code128Encoder.getInstance(),
							WidthCodedPainter.getInstance(),
							BaseLineTextPainter.getInstance());

					localJBarcode.setShowCheckDigit(false);

					BufferedImage localBufferedImage;
					try {
						localBufferedImage = localJBarcode
								.createBarcode(ret[Column.tcbh.ordinal()]);
						ByteArrayOutputStream byteArrayOut = new ByteArrayOutputStream();

						 ImageUtil.encodeAndWrite(localBufferedImage,
						 ImageUtil.PNG, byteArrayOut, 96, 96);

						// 画图的顶级管理器，一个sheet只能获取一个（一定要注意这点）
						HSSFPatriarch patriarch = sheet.createDrawingPatriarch();
						
						// anchor主要用于设置图片的属性
						HSSFClientAnchor anchor = PoiUtil.measureAnchor(
								13, 2, 5, 7, 
								localBufferedImage.getWidth(), 
								localBufferedImage.getHeight(), 
								sheet, 
								workbook);
								
//								new HSSFClientAnchor(200, 100,
//								1000, 200, (short) 14, 2, (short) 17, 5);
						anchor.setAnchorType(HSSFClientAnchor.DONT_MOVE_AND_RESIZE);
						
						// 插入图片
						HSSFPicture pic = patriarch.createPicture(
								anchor,
								workbook.addPicture(byteArrayOut.toByteArray(),
										HSSFWorkbook.PICTURE_TYPE_PNG));
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				// ImageUtil.encodeAndWrite(localBufferedImage, ImageUtil.PNG,
				// arg2);

			}
		}
		
		for (int i = count - 1; i >= 0; --i){
			workbook.removeSheetAt(i);
		}
		workbook.write(os);
	}

	private void updateTemplate(String[] ret, Map<Integer, Location[]> locations, HSSFSheet sheet) {
		for(Integer field : locations.keySet()){
			Location[] locs = locations.get(field);
			for (int i = 0; i < locs.length; ++i){
				if (null != locs[i]){
					sheet.getRow(locs[i].getX()).getCell(locs[i].getY()).setCellValue(ret[field]);
				}
			}
		}
	}

}
