package com.BlueRay.mutton.model.excel;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;

public class DBPCJHXXExcel extends AbstractExcel<PCJHXX> {


	private EntityManager entityManager;
	private String col;
	private boolean asc;
	private final static int limit = 100;
	private int start = 0;
	private List<PCJHXX> mPcjhs = new ArrayList<PCJHXX>();
	public DBPCJHXXExcel(EntityManager entityMgr, String col, boolean asc) {
		super("pcjhxxb");
		entityManager = entityMgr;
		this.col = col;
		this.asc = asc;
	}

	@Override
	public int getRowCount() {
		String sql = "select count(p) from PCJHXX as p";
		Query q = entityManager.createQuery(sql);
		List<Long> ret = q.getResultList();
		return ret.get(0).intValue();
	}

	private int getStart(int index){
		return index / limit * limit;
	}

	@Override
	public PCJHXX getRow(int index) {
		if (null == mPcjhs || mPcjhs.isEmpty() || (start + limit) <= index || index < start){
			start = getStart(index);
			String sql = "from PCJHXX";
			if (null != col){
				sql += " order by " + col + (asc ? "ASC" : "desc");
			}
			Query q = entityManager.createQuery(sql);
			q.setFirstResult(start);
			q.setMaxResults(limit);
			mPcjhs = q.getResultList();
		}
		
		return mPcjhs.get(index - start);
	}

}
