package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.model.dao.ZxdDao;
import com.BlueRay.mutton.model.entity.jpa.ZXD;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.GrYConfiguration;
import com.BlueRay.mutton.tool.UtilGGXH;

public class GrYRequestHandler extends BasicRequestHandler {

	ZxdDao zxdDao;

	public GrYRequestHandler(GrYConfiguration config, ZxdDao zxdDao) {
		super(config);
		this.zxdDao = zxdDao;
	}

	@Override
	protected boolean match(Request request) {
		String ggxh = request.record[PcjhColumn.ggxh.ordinal()];
		return config != null &&
				request.record[PcjhColumn.mpzl.ordinal()].indexOf("广日") >= 0 &&
				UtilGGXH.ggIsY(ggxh);

	}


	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		GrYConfiguration config = (GrYConfiguration) this.config;
		List<Location> locs = config.getZzl();
		ZXD zxd = zxdDao.getDataByType(request.record[PcjhColumn.ggxh.ordinal()]);
		if (null != zxd){
			setValues(sheet, locs, zxd.getCapacity() + "");
		}else{
			setValues(sheet, locs, "");
		}
		locs = config.getTs();
		setValues(sheet, locs, request.getGGXH().getTs());
	}

	
}
