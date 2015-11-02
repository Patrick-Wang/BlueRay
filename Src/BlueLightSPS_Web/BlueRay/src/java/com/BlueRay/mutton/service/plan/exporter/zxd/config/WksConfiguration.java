package com.BlueRay.mutton.service.plan.exporter.zxd.config;

import java.util.List;

import org.w3c.dom.Element;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.service.plan.exporter.ConfigurationUtil;

public class WksConfiguration extends BasicConfiguration {
	private List<Location> zdqxh;
	private List<Location> zdqbh;
	private List<Location> qt;

	public WksConfiguration(Element eSheet) {
		super(eSheet);
		zdqxh = ConfigurationUtil.loadLocationMultiCell(eSheet, "zdqxh");
		zdqbh = ConfigurationUtil.loadLocationMultiCell(eSheet, "zdqbh");
		qt = ConfigurationUtil.loadLocationMultiCell(eSheet, "qt");
	}


	public List<Location> getZdqxh() {
		return zdqxh;
	}

	public List<Location> getZdqbh() {
		return zdqbh;
	}

	public List<Location> getQt() {
		return qt;
	}

}
