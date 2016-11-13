package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.model.dao.ZxdDao;
import com.BlueRay.mutton.model.entity.jpa.ZXD;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.WksConfiguration;
import com.BlueRay.mutton.tool.UtilGGXH;

public class WksRequestHandler extends BasicRequestHandler {

	ZxdDao zxdDao;

	public WksRequestHandler(WksConfiguration config, ZxdDao zxdDao) {
		super(config);
		this.zxdDao = zxdDao;
	}

	@Override
	protected boolean match(Request request) {
		return config != null &&
				request.record[PcjhColumn.mpzl.ordinal()].indexOf("沃克斯") >= 0;
	}

	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		WksConfiguration config = (WksConfiguration) this.config;
		List<Location> locs = config.getZdqxh();//********************
		String zdqxh = "BLB";
		String ggxh = request.record[PcjhColumn.ggxh.ordinal()];
		if (UtilGGXH.ggIsS(ggxh) || UtilGGXH.ggIsY(ggxh)){
			zdqxh = "DZE";
		}else if(UtilGGXH.ggIsLStart(ggxh)){
			zdqxh = "BLS";
		}
		setValues(sheet, locs, zdqxh);
		
		locs = config.getZdqbh();//********************
		String ccbh = request.record[PcjhColumn.ccbh.ordinal()];
		if (ccbh.isEmpty()){
			setValues(sheet, locs, ccbh);
		}else{
			setValues(sheet, locs, ccbh + "01/" + ccbh + "02");
		}	
		
		locs = config.getQt();
		ZXD zxd = zxdDao.getDataByType(ggxh);
		String qt = "";	
		if (zxd != null){
			qt = zxd.getPower() + "kw/" + request.record[PcjhColumn.yylgg.ordinal()] + request.record[PcjhColumn.bmqxh.ordinal()];
		}
		setValues(sheet, locs, qt);
	}

	

}
