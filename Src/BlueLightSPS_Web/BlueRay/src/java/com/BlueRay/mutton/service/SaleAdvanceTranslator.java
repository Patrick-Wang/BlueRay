package com.BlueRay.mutton.service;

import com.BlueRay.mutton.model.dao.IAdvanceTranslator;

public class SaleAdvanceTranslator extends IAdvanceTranslator {

	@Override
	public String out(String colName, String value) {
		if ("dfr".equals(colName) || "sfjf".equals(colName)){
			if ("Y".equals(value)){
				return "是";
			}
			else {
				return "否";
			}
		} else if("sftgywsh".equals(colName)
				|| "sftgjhsh".equals(colName)) {
			if ("Y".equals(value)){
				return "√";
			}
			else {
				return "×";
			}
		}
		return null;
	}

	@Override
	public String in(String colName, String value) {
		if (inMap.containsKey(value)){
			if ("dfr".equals(colName) || "sfjf".equals(colName)
					|| "sftgywsh".equals(colName)
					|| "sftgjhsh".equals(colName)) {
				return inMap.get(value);
			}
		}
		return null;
	}


}
