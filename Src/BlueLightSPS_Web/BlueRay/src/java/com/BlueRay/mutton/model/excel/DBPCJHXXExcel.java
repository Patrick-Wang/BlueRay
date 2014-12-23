package com.BlueRay.mutton.model.excel;

import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.Date;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.Query;

import org.apache.poi.hssf.usermodel.HSSFRow;

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
	
	private void convert(List<Object[]> objs) {
		for (Object[] objArr : objs) {
			PCJHXX pcxx = new PCJHXX();
		
			pcxx.setPcjhID((Integer) objArr[0]);
			pcxx.setHtxxID((Integer) objArr[1]);
			pcxx.setJhscrq(objArr[2] != null ? (Date)objArr[2]: null);
			pcxx.setJhbzrq(objArr[3] != null ? (Date)objArr[3]: null);
			pcxx.setJhfhrq(objArr[4] != null ? (Date)objArr[4]: null);
			pcxx.setTcbh(objArr[5] != null ? (String)objArr[5]: null);
			pcxx.setCcbh(objArr[6] != null ? (String)objArr[6]: null);
			pcxx.setSftgywsh(objArr[7] != null ? "" + objArr[7]: null);
			pcxx.setSftgjhsh(objArr[8] != null ? "" + objArr[8]: null);
			pcxx.setBzsftgywsh(objArr[9] != null ? "" + objArr[9]: null);
			pcxx.setBzsftgjhsh(objArr[10] != null ? "" + objArr[10]: null);
			pcxx.setDdzt(objArr[11] != null ? (String)objArr[11]: null);
			this.mPcjhs.add(pcxx);
		}
	}

	@Override
	public PCJHXX getRow(int index) {
		if (null == mPcjhs || mPcjhs.isEmpty() || (start + limit) <= index || index < start){
			start = getStart(index);
			String sql = "select * from pcjhxxb limit " + start + ", " + limit;
			if (null != col){
				sql += " order by " + col + (asc ? "ASC" : "desc");
			}
			Query q = entityManager.createNativeQuery(sql);
			List<Object[]> objs = q.getResultList();
			convert(objs);
			//mPcjhs = q.getResultList();
			
		}
		
		return mPcjhs.get(index - start);
	}

}
