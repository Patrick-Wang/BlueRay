package com.BlueRay.mutton.tool;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import org.apache.poi.hssf.usermodel.HSSFCell;

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

	private static String toHexString(byte[] b) {
		StringBuilder sb = new StringBuilder(b.length * 2);
		for (int i = 0; i < b.length; i++) {
			sb.append(hexChar[(b[i] & 0xf0) >>> 4]);
			sb.append(hexChar[b[i] & 0x0f]);
		}
		return sb.toString();
	}
	
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
	
	public static boolean isEmpty(String s){
		return s == null || s.isEmpty();
	}
	

}
