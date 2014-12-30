package com.BlueRay.mutton.model.excel;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.tool.AbstractExcel;

public class DBHTXXExcel extends AbstractExcel<HTXX> {


	private EntityManager entityManager;
	private final static int limit = 100;
	private int start = 0;
	private List<HTXX> mHtxxs = new ArrayList<HTXX>();
	public DBHTXXExcel(EntityManager entityMgr) {
		super("htxx");
		entityManager = entityMgr;
	}

	@Override
	public int getRowCount() {
		String sql = "select count(p) from HTXX as p";
		Query q = entityManager.createQuery(sql);
		List<Long> ret = q.getResultList();
		return ret.get(0).intValue();
	}

	private int getStart(int index){
		return index / limit * limit;
	}

	@Override
	public HTXX getRow(int index) {
		if (null == mHtxxs || mHtxxs.isEmpty() || (start + limit) <= index || index < start){
			start = getStart(index);
			String sql = "from HTXX";
			Query q = entityManager.createQuery(sql);
			q.setFirstResult(start);
			q.setMaxResults(limit);
			mHtxxs = q.getResultList();
		}
		
		return mHtxxs.get(index - start);
	}

}
