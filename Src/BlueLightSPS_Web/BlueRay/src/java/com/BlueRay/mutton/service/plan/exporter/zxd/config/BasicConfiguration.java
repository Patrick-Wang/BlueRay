package com.BlueRay.mutton.service.plan.exporter.zxd.config;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.w3c.dom.Element;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.service.plan.exporter.ConfigurationUtil;

public class BasicConfiguration {

	String sheetName;
	protected Map<Integer, List<Location>> locsMap = new HashMap<Integer, List<Location>>();
	int baseRow;
	List<Location> xh;
	List<Location> bz;
	public BasicConfiguration(Element eSheet) {
		sheetName = ConfigurationUtil.getSheetName(eSheet);
		ConfigurationUtil.loadTableFields(locsMap, eSheet);
		baseRow = ConfigurationUtil.getBaseRow(eSheet);
		xh = ConfigurationUtil.loadLocationMultiCell(eSheet, "xh");
		xh = ConfigurationUtil.loadLocationMultiCell(eSheet, "bz");
	}

	public String getSheetName() {
		return sheetName;
	}

	public List<Location> getField(int j) {
		return locsMap.get(j);
	}

	public int getBaseRow() {
		return baseRow;
	}

	public List<Location> getXh() {
		return xh;
	}

	public List<Location> getBz() {
		return bz;
	}
}
