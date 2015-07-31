package com.BlueRay.mutton.tool;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import net.sf.json.JSONObject;

public class Util {
	
	static String[] dayOfWeek = new String[]{
		"周日", "周一", "周二", "周三", "周四", "周五", "周六"
	};
	
	public static String toChinese(int iDayOfWeek){
		return dayOfWeek[iDayOfWeek];
	}
	
	public static String getUtf8(InputStream is) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(is,
				"UTF-8"));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		return sb.toString();
	}

	public static JSONObject parse(InputStream is) throws IOException {
		return JSONObject.fromObject(getUtf8(is));
	}

	public final static char[] hexChar = { '0', '1', '2', '3', '4', '5', '6',
			'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

	public static String Md5(String value){
		MessageDigest md5 = null;
		try {
			md5 = MessageDigest.getInstance("MD5");
			md5.update(value.getBytes());
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return toHexString(md5.digest());
	}

	private static String toHexString(byte[] b) {
		StringBuilder sb = new StringBuilder(b.length * 2);
		for (int i = 0; i < b.length; i++) {
			sb.append(hexChar[(b[i] & 0xf0) >>> 4]);
			sb.append(hexChar[b[i] & 0x0f]);
		}
		return sb.toString();
	}
	
	public static boolean ggIsS(String ggxh){
		if(ggxh != null && !ggxh.isEmpty() && ('S' == ggxh.charAt(0) || 's' == ggxh.charAt(0))){
			return true;
		}
		return false;
	}

	public static boolean ggIsU(String ggxh){
		if(ggxh != null && !ggxh.isEmpty() && ('U' == ggxh.charAt(0) || 'u' == ggxh.charAt(0))){
			return true;
		}
		return false;
	}
	
	public static boolean ggIsTStart(String ggxh){
		if(ggxh != null && !ggxh.isEmpty() && ('T' == ggxh.charAt(0) || 't' == ggxh.charAt(0))){
			return true;
		}
		return false;
	}
	
	public static boolean ggIsTA(String ggxh){
		if(ggxh != null && ggxh.length() > 1 && 
				('T' == ggxh.charAt(0) || 't' == ggxh.charAt(0)) &&
				('A' == ggxh.charAt(1) || 'a' == ggxh.charAt(1))){
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
	
	public static boolean isEmpty(String s){
		return s == null || s.isEmpty();
	}

}
