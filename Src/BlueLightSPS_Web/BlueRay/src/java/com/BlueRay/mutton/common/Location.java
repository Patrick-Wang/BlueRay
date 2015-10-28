package com.BlueRay.mutton.common;

public class Location{
	int row;
	String col;
	public Location(String col, int x) {
		this.row = x;
		this.col = col;
	}
	/**
	 * @return the row
	 */
	public int getRow() {
		return row;
	}
	/**
	 * @return the col
	 */
	public String getCol() {
		return col;
	}
	
	private static Integer toInt(String col){
		Integer ret = 0;
		for (int i = 0; i < col.length(); ++i){
			ret +=  (col.charAt(i) - 'A' + 1) * zsys(('Z' - 'A' + 1), i);
		}
		return ret;
	}
	
	private static Integer zsys(Integer ds, int zs){
		Integer tmp = 1;
		for(int i = 0; i < zs; ++i){
			tmp *= ds;
		}
		return tmp;
	}
	
	public int getZeroBasedCol(){
		return toInt(col) - 1;
	}
	
	public int getZeroBasedRow(){
		return row - 1;
	}
	
	/**
	 * @param row the row to set
	 */
	public void setRow(int row) {
		this.row = row;
	}
	/**
	 * @param col the col to set
	 */
	public void setCol(String col) {
		this.col = col;
	}

	

}