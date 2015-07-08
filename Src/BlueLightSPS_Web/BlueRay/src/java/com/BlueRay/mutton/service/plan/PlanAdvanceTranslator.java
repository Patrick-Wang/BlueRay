package com.BlueRay.mutton.service.plan;

import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.service.sale.SaleAdvanceTranslator;

public class PlanAdvanceTranslator extends IAdvanceTranslator {

	private SaleAdvanceTranslator saleTranslator = new SaleAdvanceTranslator();

	@Override
	public String out(String colName, String value) {
		String newValue = saleTranslator.out(colName, value);
		if (null == newValue){
				if ("sftgywsh".equals(colName) || 
					"sftgjhsh".equals(colName) || 
					"bzsftgywsh".equals(colName) || 
					"bzsftgjhsh".equals(colName)) {
					if ("Y".equals(value)){
						return "Y";
					}
					else {
						return "N";
					}
				}
		}
		return newValue;
	}

	@Override
	public String in(String colName, String value) {
		String newValue = saleTranslator.in(colName, value);
		if (null == newValue){
			if (inMap.containsKey(value)) {
				if ("sftgywsh".equals(colName) || 
					"sftgjhsh".equals(colName) || 
					"bzsftgywsh".equals(colName) || 
					"bzsftgjhsh".equals(colName)) {
					newValue = inMap.get(value);
				}
			}
		}
		return newValue;
	}

}
