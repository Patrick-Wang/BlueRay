package com.bar;

import java.io.File;
import java.io.IOException;

import net.sf.jni4net.Bridge;

public class DotNet {

	public static void main(String[] args) throws IOException {
		 if (args.length>0){
				Bridge.setClrVersion(args[0]);
			}
			Bridge.init();

	    system.Type re = system.Type.GetType("System.Runtime.InteropServices.RuntimeEnvironment");
	    system.reflection.MethodInfo mi = re.GetMethod("GetSystemVersion");
			System.out.println("clr.version         :" + mi.Invoke(null,null).toString());
			System.out.println("java.version        :" + System.getProperty("java.version"));
			System.out.println("sun.arch.data.model :" + System.getProperty("sun.arch.data.model"));
			System.out.println("");
		
		//Bridge.init();
		Bridge.LoadAndRegisterAssemblyFrom(new File("C:/Users/Floyd/Documents/visual studio 2013/Projects/WindowsFormsApplication3/VBARunner/bin/Debug/VBARunner.dll"));
		re = system.Type.GetType("VBARunner.VBAExcel");
		mi = re.GetMethod("Start");
		mi.Invoke(null,null);
	}

}
