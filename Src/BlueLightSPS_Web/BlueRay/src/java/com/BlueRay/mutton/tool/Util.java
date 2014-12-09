package com.BlueRay.mutton.tool;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import net.sf.json.JSONObject;
public class Util {
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
	
	public static JSONObject parse(InputStream is) throws IOException{
		return JSONObject.fromObject(getUtf8(is));
	}
}
