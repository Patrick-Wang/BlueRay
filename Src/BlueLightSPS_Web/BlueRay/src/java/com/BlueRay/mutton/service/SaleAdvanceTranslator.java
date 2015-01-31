package com.BlueRay.mutton.service;

import com.BlueRay.mutton.model.dao.IAdvanceTranslator;

public class SaleAdvanceTranslator extends IAdvanceTranslator {

	@Override
	public String out(String colName, String value) {
		if ("sfjf".equals(colName)) 
		{	
			if ("Y".equals(value)){
				return "有";
			}
			else {
				return "无";
			}
		}else if("dfr".equals(colName)){
			if ("Y".equals(value)){
				return "单绕";
			}
			else {
				return "复绕";
			}
		} else if("sftgywsh".equals(colName)
				|| "sftgjhsh".equals(colName)) {
			if ("Y".equals(value)){
				return "Y";
			}
			else {
				return "N";
			}
		} else if ("yxj".equals(colName)){
			if ("10".equals(value)){
				return "高";
			} else {
				return "低";
			}
		} else if ("zyz".equals(colName)){
			if ("Y".equals(value)){
				return "左置";
			}
			else {
				return "右置";
			}
		}
		return null;
	}

	@Override
	public String in(String colName, String value) {
		if (inMap.containsKey(value)){
			if ("dfr".equals(colName) || "sfjf".equals(colName)
					|| "sftgywsh".equals(colName)
					|| "sftgjhsh".equals(colName)
					|| "zyz".equals(colName)
					|| "yxj".equals(colName)) {
				return inMap.get(value);
			}
		}
		return null;
	}


}
