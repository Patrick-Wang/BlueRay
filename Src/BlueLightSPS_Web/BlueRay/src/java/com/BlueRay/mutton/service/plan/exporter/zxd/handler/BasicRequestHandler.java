package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.ExporterUtil;
import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.common.RequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.BasicConfiguration;

public abstract class BasicRequestHandler extends RequestHandler<Request> {

	protected BasicConfiguration config;
	
	public BasicRequestHandler(BasicConfiguration config) {
		super();
		this.config = config;
	}

	protected HSSFCell setValue(HSSFSheet sheet, Location loc, String val){
		HSSFRow row = sheet.getRow(loc.getZeroBasedRow());
		HSSFCell cel = row.getCell(loc.getZeroBasedCol());
		if (cel == null) {
			cel = row.createCell(loc.getZeroBasedCol());
		}
		String value = cel.getStringCellValue();
		cel.setCellValue(value.replace("XXX", val));
		return cel;
	}
	
	protected List<HSSFCell> setValues(HSSFSheet sheet, List<Location> locs, String val){
		List<HSSFCell> list = new ArrayList<HSSFCell>();
		for (Location loc : locs){
			list.add(setValue(sheet, loc, val));
		}
		return list;
	}
	
	protected String getDigital(String val){
		String regEx="[^0-9]";   
		Pattern p = Pattern.compile(regEx);   
		Matcher m = p.matcher(val);   
		return m.replaceAll("").trim();
	}
	
	protected String getValue(String[] record, int col){
		if (PcjhColumn.dlcd.ordinal() == col){
			return getDigital(record[col]);
		}
		return record[col];
	}
	
	@Override
	public void onHandle(Request request) {
		int index = request.workbook.getSheetIndex(config.getSheetName());
		HSSFSheet sheet = request.workbook.cloneSheet(index);
		for (int j = 1; j < PcjhColumn.end.ordinal(); ++j) {
			List<Location> locs = config.getField(j);
			if (null != locs) {
				boolean highLight = ExporterUtil.validatePlanHighlight(j, request.record);

				for (Location loc : locs) {
					HSSFCell cel = setValue(sheet, loc, getValue(request.record, j));
					if (highLight){
						request.highLight(cel);
					}
				}
			}
		}
		onHandle(request, sheet);
	}

	abstract protected void onHandle(Request request, HSSFSheet sheet);
}
