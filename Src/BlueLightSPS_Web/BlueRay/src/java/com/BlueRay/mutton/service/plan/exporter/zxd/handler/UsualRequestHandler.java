package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.service.plan.exporter.zxd.config.UsualConfiguration;

public class UsualRequestHandler extends BasicRequestHandler {


	public UsualRequestHandler(UsualConfiguration config) {
		super(config);
	}

	@Override
	protected boolean match(Request request) {
		return null != config;
	}

	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		
	}


}
