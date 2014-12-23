package com.BlueRay.mutton.tool;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

public abstract class AbstractExcel<T> {
	String name = "";
	List<String[]> header = new ArrayList<String[]>();
	
	public AbstractExcel(String name){
		this.name = name;
	}
	
	public void setName(String name){
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	public void addHeader(String[] header){
		this.header.add(header);
	}
	
	public List<String[]> getheader(){
		return header;
	}
	
	abstract public int getRowCount();
	
	abstract public T getRow(int index);
}
