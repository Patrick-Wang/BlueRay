package com.BlueRay.mutton.service.plan.exporter.zxd.handler;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;

import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;

public class Request {
	
	static public interface GGXHPicker{
		CPGGXHXX pick();
	}
	
	public String[] record;
	public HSSFWorkbook workbook;
	private CPGGXHXX ggxh;
	GGXHPicker ggxhPicker;
	
	public void setGGXHPicker(GGXHPicker picker){
		ggxhPicker = picker;
		ggxh = null;
	}
	
	public void highLight(HSSFCell cell){
		HSSFCellStyle style = cell.getCellStyle();
		style.setFillForegroundColor(HSSFColor.YELLOW.index);
		style.setFillBackgroundColor(HSSFColor.YELLOW.index);
		style.setFillPattern(HSSFCellStyle.SOLID_FOREGROUND);
	}
	
	public CPGGXHXX getGGXH(){
		if (null == ggxh){
			ggxh = ggxhPicker.pick();
		}
		return ggxh;
	}
}
