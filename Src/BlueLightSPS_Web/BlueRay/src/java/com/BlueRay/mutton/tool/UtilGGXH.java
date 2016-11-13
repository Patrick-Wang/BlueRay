package com.BlueRay.mutton.tool;

public class UtilGGXH {
	
	private static boolean ggIsX(String ggxh, char lower, char upper){
		if(ggxh != null && !ggxh.isEmpty() && (lower == ggxh.charAt(0) || upper == ggxh.charAt(0))){
			return true;
		}
		return false;
	}
	
	public static boolean ggIsS(String ggxh){
		return ggIsX(ggxh, 's', 'S');
	}

	public static boolean ggIsU(String ggxh){
		return ggIsX(ggxh, 'u', 'U');
	}
	
	public static boolean ggIsV(String ggxh){
		return ggIsX(ggxh, 'v', 'V');
	}
	
	
	public static boolean ggIsTStart(String ggxh){
		return ggIsX(ggxh, 't', 'T');
	}
	
	public static boolean ggIsY(String ggxh){
		return ggIsX(ggxh, 'y', 'Y');
	}
	
	public static boolean ggIsTA(String ggxh){
		if(ggxh != null && ggxh.length() > 1 && 
				('T' == ggxh.charAt(0) || 't' == ggxh.charAt(0)) &&
				('A' == ggxh.charAt(1) || 'a' == ggxh.charAt(1))){
			return true;
		}
		return false;
	}
	
	public static boolean ggIsLA(String ggxh){
		if(ggxh != null && ggxh.length() > 1 && 
				('L' == ggxh.charAt(0) || 'l' == ggxh.charAt(0)) &&
				('A' == ggxh.charAt(1) || 'a' == ggxh.charAt(1))){
			return true;
		}
		return false;
	}
	
	public static boolean ggIsL(String ggxh){
		if(ggxh != null && !ggxh.isEmpty() && 'L' == ggxh.charAt(0)){
			if (ggxh.length() > 1 
					&&( ('a' <= ggxh.charAt(1) && 'z' >= ggxh.charAt(1))
					 || ('A' <= ggxh.charAt(1) && 'Z' >= ggxh.charAt(1)))){
				return false;
			}
			return true;
		}
		return false;
	}
	
	public static boolean ggIsT(String ggxh){
		if(ggxh != null && !ggxh.isEmpty() && 'T' == ggxh.charAt(0)){
			if (ggxh.length() > 1 
					&&( ('a' <= ggxh.charAt(1) && 'z' >= ggxh.charAt(1))
					 || ('A' <= ggxh.charAt(1) && 'Z' >= ggxh.charAt(1)))){
				return false;
			}
			return true;
		}
		return false;
	}

	public static boolean ggIsLStart(String ggxh) {
		return ggIsX(ggxh, 'l', 'L');
	}

}
