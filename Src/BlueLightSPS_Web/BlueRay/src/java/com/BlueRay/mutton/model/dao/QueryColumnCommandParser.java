package com.BlueRay.mutton.model.dao;

public class QueryColumnCommandParser {
	public static String parse(String colName, String cmd){
		if (cmd.equals("@!=null")){
			return colName + " is not null ";
		}
		return null;
	}
}
