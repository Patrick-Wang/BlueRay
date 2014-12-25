package com.BlueRay.mutton.controller;

import java.util.ArrayList;
import java.util.List;

public class PageData {
	public class Row{
	
		Integer id;
		List<String> cell = new ArrayList<String>();
		public Integer getId() {
			return id;
		}
		public void setId(Integer id) {
			this.id = id;
		}
		public List<String> getCell() {
			return cell;
		}
		public void setCell(List<String> cell) {
			this.cell = cell;
		}
		
	}
	Integer total;
	public Integer getTotal() {
		return total;
	}
	public void setTotal(Integer total) {
		this.total = total;
	}
	public Integer getPage() {
		return page;
	}
	public void setPage(Integer page) {
		this.page = page;
	}
	public Integer getRecords() {
		return records;
	}
	public void setRecords(Integer records) {
		this.records = records;
	}
	public List<Row> getRows() {
		return rows;
	}
	public void setRows(List<Row> rows) {
		this.rows = rows;
	}
	Integer page;
	Integer records;
	List<Row> rows = new ArrayList<Row>();
}
