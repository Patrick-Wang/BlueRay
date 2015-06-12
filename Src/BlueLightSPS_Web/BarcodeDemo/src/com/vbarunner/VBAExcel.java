package com.vbarunner;

import java.net.URI;
import java.util.List;


public class VBAExcel
{
    public  native void start();
    public  native void stop();
    public  native void runVBABarcode(String json, String guid);
    static
    {
    	try{
    		String basePath = new URI(VBAExcel.class
					.getClassLoader().getResource("").getPath()).getPath();
			System.out.println(basePath);
			Runtime runtime = Runtime.getRuntime();
			runtime.exec(basePath + "VBARunnerService.exe");
			Thread.sleep(1000);
    		   System.load(basePath + "VBARunner.dll");
    	}catch(Exception e){
    		e.printStackTrace();
    	}
    }
}