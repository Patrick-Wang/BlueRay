package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.XdConfiguration;

public class XdRequestHandler extends BasicRequestHandler {

	public XdRequestHandler(XdConfiguration config) {
		super(config);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected boolean match(Request request) {
		return config != null &&
				request.record[PcjhColumn.mpzl.ordinal()].indexOf("西德") >= 0;
	}
	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		// TODO Auto-generated method stub
		
	}
}
