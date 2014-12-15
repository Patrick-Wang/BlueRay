package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;

@Repository
@Transactional("transactionManager")
public class PlanDaoImpl implements PlanDao{

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
	
//	public List<PCJHXX> getPcjhxx() {
//		Query q = entityManager.createQuery("select p from PCJHXX p");
//		return q.getResultList();
//	}

	public void insert(PCJHXX pcjhxx) {
		entityManager.persist(pcjhxx);
	}

	public PCJHXX getDataById(int id) {
		Query q = entityManager.createQuery("select t from PCJHXX t where t.pcjhID = :id");
		q.setParameter("id", id);
		List<PCJHXX> pcs = q.getResultList();
		if (pcs != null && !pcs.isEmpty()){
			return pcs.get(0);
		}
		return null;
	}

	public void update(PCJHXX pcjhxx) {
		entityManager.merge(pcjhxx);
	}

	public void delete(PCJHXX pcjhxx) {
		entityManager.remove(pcjhxx);
	}

	
	private String getApprovedSql(String approved){
		if ("approved".equals(approved)){
			return "'Y'";
		} else {
			return "'N'";
		} 
	}
	

	private String getApproveTypeSql(String approveType){
		String sql = "from PCJHXX";
		if ("plan_planApprove".equals(approveType)){
			return "jhscrq is not null and sftgjhsh";
		} else if("plan_businessApprove".equals(approveType)){
			return "jhscrq is not null and sftgywsh";
		} else if("pack_businessApprove".equals(approveType)){
			return "jhbzrq is not null and bzsftgywsh";
		} else if("pack_planApprove".equals(approveType)){
			return "jhbzrq is not null and bzsftgjhsh";
		} else{
			return "";
		}
	}
	
	
	public List<PCJHXX> getPcjhxx(String approveType, String approved) {
		String sql = "from PCJHXX";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sql += " where " + typeSql + " = " + approveSql;
		} 
		Query q = entityManager.createQuery(sql);
		return q.getResultList();
	}

	public List<PCJHXX> getDateByHtxxId(int id) {
		String sql = "from PCJHXX where htxxID = :id";
		Query q = entityManager.createQuery(sql);
		q.setParameter("id", id);
		return q.getResultList();
	}

}
