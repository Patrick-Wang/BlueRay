package com.vbarunner;

import java.net.URI;

public class VBAExcel
{
    public native void start();
    public native void stop();
    public native void runVBABarcode(String json, String guid);
   
    static
    {
    	try{
    		String basePath = new URI(VBAExcel.class
					.getClassLoader().getResource("").getPath()).getPath();
    		System.load(basePath + "META-INF/VBARunner.dll");
    	}catch(Exception e){
    		e.printStackTrace();
    	}
     
    }
}