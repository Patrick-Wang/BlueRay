package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;

import com.BlueRay.mutton.common.ExporterUtil;
import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.model.dao.ZxdDao;
import com.BlueRay.mutton.model.entity.jpa.ZXD;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.WksConfiguration;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.ZjydConfiguration;
import com.BlueRay.mutton.tool.PoiUtil;

public class ZjydRequestHandler extends BasicRequestHandler {


	ZxdDao zxdDao;
	HSSFSheet zjydSheet = null;
	int count = 0;
	public ZjydRequestHandler(ZjydConfiguration zjydConfiguration, ZxdDao zxdDao) {
		super(zjydConfiguration);
		this.zxdDao = zxdDao;
	}

	@Override
	protected boolean match(Request request) {
		return config != null &&
				request.record[PcjhColumn.mpzl.ordinal()].indexOf("怡达") >= 0;
	}

	@Override
	public void onHandle(Request request) {
		if (null == zjydSheet){
			int index = request.workbook.getSheetIndex(config.getSheetName());
			zjydSheet = request.workbook.cloneSheet(index);
		}
		onHandle(request, zjydSheet);
	}

	@Override
	protected void onHandle(Request request, HSSFSheet sheet) {
		count++;
		HSSFRow row = zjydSheet.getRow(config.getBaseRow() + count);
		if (1 != count){
			HSSFRow dest = zjydSheet.createRow(config.getBaseRow() + count);
			PoiUtil.copyRow(request.workbook, row, dest, true);
			row = dest;
		}
		
		List<Location> locs = config.getField(PcjhColumn.ggxh.ordinal());
		boolean highLight = ExporterUtil.validatePlanHighlight(PcjhColumn.ggxh.ordinal(), request.record);
		for (Location loc : locs) {
			HSSFCell cel = row.getCell(loc.getZeroBasedCol());
			if (cel == null) {
				cel = row.createCell(loc.getZeroBasedCol());
			}
			cel.setCellValue(request.record[PcjhColumn.ggxh.ordinal()]);
			if (highLight){
				request.highLight(cel);
			}
		}
		
		locs = config.getXh();
		for (Location loc : locs) {
			HSSFCell cel = row.getCell(loc.getZeroBasedCol());
			if (cel == null) {
				cel = row.createCell(loc.getZeroBasedCol());
			}
			cel.setCellValue(count);
		}
		
		locs = config.getBz();
		ZXD zxd = zxdDao.getDataByType(request.record[PcjhColumn.ggxh.ordinal()]);
		String bz = request.record[PcjhColumn.yylgg.ordinal()];
		if (zxd != null){
			bz = zxd.getPower() + "KW  " + bz;
		}
		for (Location loc : locs) {
			HSSFCell cel = row.getCell(loc.getZeroBasedCol());
			if (cel == null) {
				cel = row.createCell(loc.getZeroBasedCol());
			}
			cel.setCellValue(bz);
		}
	}

}
