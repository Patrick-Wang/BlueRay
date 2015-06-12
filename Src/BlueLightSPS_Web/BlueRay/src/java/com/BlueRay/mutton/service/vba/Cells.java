package com.BlueRay.mutton.service.vba;

import java.util.List;

public class Cells {
	private String path;
	private List<Integer[]> cells;
	/**
	 * @return the path
	 */
	public String getPath() {
		return path;
	}
	/**
	 * @return the cells
	 */
	public List<Integer[]> getCells() {
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
	public void setCells(List<Integer[]> cells) {
		this.cells = cells;
	}
}
