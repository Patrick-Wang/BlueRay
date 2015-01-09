package com.BlueRay.mutton.model.excel;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import net.sf.json.JSONObject;

import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.model.dao.SaleQueryParams;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.tool.AbstractExcel;

public class DBHTXXExcel extends AbstractExcel<HTXX> {


	private EntityManager entityManager;
	private final static int limit = 5000;
	private int start = 0;
	private String mSql;
	private List<HTXX> mHtxxs = new ArrayList<HTXX>();
	public DBHTXXExcel(EntityManager entityMgr, JSONObject jparam, IAdvanceTranslator translator) {
		super("htxx");
		entityManager = entityMgr;
		SaleQueryParams params = new SaleQueryParams(jparam, translator);
		mSql = params.toSql();
	}

	@Override
	public int getRowCount() {
		String sql = mSql.replace("select HTXX_", "select count(HTXX_)");
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
			Query q = entityManager.createQuery(mSql);
			q.setFirstResult(start);
			q.setMaxResults(limit);
			mHtxxs = q.getResultList();
		}
		
		return mHtxxs.get(index - start);
	}

}
