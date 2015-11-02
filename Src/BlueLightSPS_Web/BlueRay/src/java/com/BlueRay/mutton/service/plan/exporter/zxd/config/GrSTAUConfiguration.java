package com.BlueRay.mutton.service.plan.exporter.zxd.config;

import java.util.List;

import org.w3c.dom.Element;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.service.plan.exporter.ConfigurationUtil;

public class GrSTAUConfiguration extends BasicConfiguration{

	private List<Location> zzl;
	private List<Location> ts;

	public GrSTAUConfiguration(Element eSheet) {
		super(eSheet);
		ts = ConfigurationUtil.loadLocationMultiCell(eSheet, "ts");
		zzl = ConfigurationUtil.loadLocationMultiCell(eSheet, "zzl");
	}

	public List<Location> getZzl() {
		return zzl;
	}

	public List<Location> getTs() {
		return ts;
	}

}
