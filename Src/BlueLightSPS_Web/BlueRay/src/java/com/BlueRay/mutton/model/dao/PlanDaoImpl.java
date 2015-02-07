package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import net.sf.json.JSONObject;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.excel.DBPCJHXXExcel;
import com.BlueRay.mutton.tool.AbstractExcel;

@Repository
@Transactional("transactionManager")
public class PlanDaoImpl implements PlanDao{

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

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
	
	public AbstractExcel<PCJHXX> getPcjhExcel(JSONObject jparam, IAdvanceTranslator translator){
		return new DBPCJHXXExcel(entityManager, jparam, translator);
	}

	public PCJHXX getPlanDataByTcbh(String tcbh) {
		Query q = entityManager.createQuery("select t from PCJHXX t where t.tcbh = :tcbh");
		q.setParameter("tcbh", tcbh);
		List<PCJHXX> pcs = q.getResultList();
		if (pcs != null && !pcs.isEmpty()){
			return pcs.get(0);
		}
		return null;
	}
	
	public PCJHXX getPlanDataByCcbh(String ccbh) {
		Query q = entityManager.createQuery("select t from PCJHXX t where t.ccbh = :ccbh");
		q.setParameter("ccbh", ccbh);
		List<PCJHXX> pcs = q.getResultList();
		if (pcs != null && !pcs.isEmpty()){
			return pcs.get(0);
		}
		return null;
	}

	public List<PCJHXX> getPlanData(Integer pagesize, Integer pagenum,
			Integer pagecount, JSONObject jparam, IAdvanceTranslator translator) {
		PlanQueryParams pqp = new PlanQueryParams(jparam, translator);
		String sql = pqp.toSql();
		Query q = entityManager.createQuery(sql);
		q.setFirstResult((pagenum - 1) * pagesize);
		q.setMaxResults(pagesize * pagecount);
		return q.getResultList();
	}


	public int getPlanDataCount(JSONObject jparam, IAdvanceTranslator translator) {
		PlanQueryParams pqp = new PlanQueryParams(jparam, translator);
		String sql = pqp.toSql();
		Query q = entityManager.createQuery(sql.replace("select PCJHXX_", "select count(PCJHXX_)"));
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getPlanUnapproved() {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t where t.sftgjhsh = 'N' and t.jhscrq is not null");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getBusinessUnapproved() {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t where t.sftgywsh = 'N' and t.jhscrq is not null");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getPackPlanUnapproved() {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t where t.bzsftgjhsh = 'N' and t.jhbzrq is not null");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getPackBusinessUnapproved() {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t where t.bzsftgywsh = 'N' and t.jhbzrq is not null");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getArpprovedDataCount(Integer htId) {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t, HTXX h where t.htxxID = h.ID and h.htID = '" + htId + "' and (t.bzsftgywsh = 'Y' or t.bzsftgjhsh = 'Y' or t.sftgywsh = 'Y' or t.sftgjhsh = 'Y')");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue(); 
	}

	public int getDataCount(Integer id) {
		Query q = entityManager.createQuery(
				"select count(t) from PCJHXX t, HTXX h where t.htxxID = h.ID and h.htID = '" + id + "'");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue(); 
	}

}
