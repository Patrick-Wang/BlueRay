package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;

@Repository
@Transactional("transactionManager")
public class SaleDaoImpl implements SaleDao{


	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

	
//	public List<HTXX> getSaleData() {
//		Query q = entityManager.createQuery("select h from HTXX h");
//		return q.getResultList();
//	}


	public void insert(HTXX bxx) {
		entityManager.persist(bxx);
	}


	public void del(HTXX htxx) {
		HTXX entity = entityManager.find(HTXX.class, htxx.getID());
		entityManager.remove(entity);
	}


	public void update(HTXX htxx) {
		entityManager.merge(htxx);
		
	}


	public HTXX getSaleDataById(int id) {
		Query q = entityManager.createQuery("select h from HTXX h where h.ID = :id");
		q.setParameter("id", id);
		List<HTXX> htxxs = q.getResultList();
		if (htxxs != null && !htxxs.isEmpty()){
			return htxxs.get(0);
		}
		return null;
	}

	
	private String getApprovedSql(String approved){
		if ("approved".equals(approved)){
			return "'Y'";
		} else {
			return "'N'";
		} 
	}
	

	private String getApproveTypeSql(String approveType){
		if ("plan".equals(approveType)){
			return "sftgjhsh";
		} else if ("business".equals(approveType)){
			return "sftgywsh";
		} else{
			return "";
		} 
	}
	public List<HTXX> getSaleData(String approveType, String approved) {
		String sql = "from HTXX";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sql += " where " + approveSql + " = " + typeSql;
		} 
		Query q = entityManager.createQuery(sql);
		return q.getResultList();
	}


	public List<HTXX> getSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			String col, Boolean sort) {
		String sql = "from HTXX";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sql += " where " + approveSql + " = " + typeSql;
		} 
		
		if (col != null){
			sql += " order by " + col + (sort ? " asc" : " desc");
		}
		Query q = entityManager.createQuery(sql);
		q.setFirstResult((pagenum - 1) * pagesize);
		q.setMaxResults(pagesize * pagecount);
		return q.getResultList();
	}


	public int getSaleDataCount() {
		Query q = entityManager.createQuery("select count(h) from HTXX h");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}



}
