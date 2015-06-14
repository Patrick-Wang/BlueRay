package com.BlueRay.mutton.tool.vba;

import java.util.ArrayList;
import java.util.List;

public class Cells {
	private String path;
	private List<List<Integer>> cells = new ArrayList<List<Integer>>();
	/**
	 * @return the path
	 */
	public String getPath() {
		return path;
	}
	/**
	 * @return the cells
	 */
	public List<List<Integer>> getCells() {
		return cells;
	}
	/**
	 * @param path the path to set
	 */
	public void setPath(String path) {
		this.path = path;
	}
	/**
	 * @param cells the cells to set
	 */
	public void setCells(List<List<Integer>> cells) {
		this.cells = cells;
	}
}
