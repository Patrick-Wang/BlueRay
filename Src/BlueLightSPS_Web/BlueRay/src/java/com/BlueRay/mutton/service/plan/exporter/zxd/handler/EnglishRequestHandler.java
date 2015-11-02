package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import java.sql.Date;
import java.text.DateFormat;
import java.util.Locale;

import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.EnglishConfiguration;

public class EnglishRequestHandler extends BasicRequestHandler {


	public EnglishRequestHandler(EnglishConfiguration config) {
		super(config);
	}

	@Override
	protected boolean match(Request request) {
		return config != null &&
		request.record[PcjhColumn.mpzl.ordinal()].indexOf("英文") >= 0;
	}

	protected String getValue(String[] record, int col){
		if (PcjhColumn.bzrq.ordinal() == col){
			DateFormat df = DateFormat.getDateInstance(DateFormat.DEFAULT,Locale.ENGLISH);
			return df.format(Date.valueOf(record[col]));
		}
		return record[col];
	}
	
	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		
	}


}
