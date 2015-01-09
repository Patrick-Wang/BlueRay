package com.BlueRay.mutton.model.excel;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import net.sf.json.JSONObject;

import com.BlueRay.mutton.model.dao.IAdvanceTranslator;
import com.BlueRay.mutton.model.dao.PlanQueryParams;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;

public class DBPCJHXXExcel extends AbstractExcel<PCJHXX> {


	private EntityManager entityManager;
	String mSql;
	private final static int limit = 5000;
	private int start = 0;
	private List<PCJHXX> mPcjhs = new ArrayList<PCJHXX>();
	public DBPCJHXXExcel(EntityManager entityMgr, JSONObject jparam, IAdvanceTranslator translator) {
		super("pcjhxxb");
		entityManager = entityMgr;
		PlanQueryParams param = new PlanQueryParams(jparam, translator);
		mSql = param.toSql();
	}

	@Override
	public int getRowCount() {
		String sql = mSql.replace("select PCJHXX_", "select count(PCJHXX_)");
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
			Query q = entityManager.createQuery(mSql);
			q.setFirstResult(start);
			q.setMaxResults(limit);
			mPcjhs = q.getResultList();
		}
		
		return mPcjhs.get(index - start);
	}

}
