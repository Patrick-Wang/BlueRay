package com.vbarunner;

import java.util.List;

public class VBAExcel
{
    public  native void start();
    public  native void stop();
    public  native void runVBABarcode(String path, int[] sheets, int[] rows, int[] colss);
    static
    {
    	try{
    		   System.loadLibrary("nativeVBARunnerProxy");
    	}catch(Exception e){
    		e.printStackTrace();
    	}
     
    }
}