package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;






import net.sf.json.JSONObject;






import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.excel.DBHTXXExcel;
import com.BlueRay.mutton.tool.AbstractExcel;

@Repository
@Transactional("transactionManager")
public class SaleDaoImpl implements SaleDao {

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

	public void insert(HTXX bxx) {
		entityManager.persist(bxx);
	}

	public void del(HTXX htxx) {
		entityManager.remove(htxx);
	}

	public void update(HTXX htxx) {
		entityManager.merge(htxx);

	}

	public HTXX getSaleDataById(int id) {
		Query q = entityManager
				.createQuery("select h from HTXX h where h.ID = :id");
		q.setParameter("id", id);
		List<HTXX> htxxs = q.getResultList();
		if (htxxs != null && !htxxs.isEmpty()) {
			return htxxs.get(0);
		}
		return null;
	}

	public int getSaleDataCount() {
		Query q = entityManager.createQuery("select count(h) from HTXX h");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public List<HTXX> getSaleData(Integer pagesize, Integer pagenum,
			Integer pagecount, JSONObject jparam, IAdvanceTranslator translator) {
		SaleQueryParams sqp = new SaleQueryParams(jparam, translator);
		String sql = sqp.toSql();
		Query q = entityManager.createQuery(sql);
		q.setFirstResult((pagenum - 1) * pagesize);
		q.setMaxResults(pagesize * pagecount);
		return q.getResultList();
	}

	public int getSaleDataCount(JSONObject jparam, IAdvanceTranslator translator) {
		SaleQueryParams sqp = new SaleQueryParams(jparam, translator);
		String sql = sqp.toSql();
		Query q = entityManager.createQuery(sql.replace("select HTXX_", "select count(HTXX_)"));
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public AbstractExcel<HTXX> getHtxxExcel(JSONObject jparam, IAdvanceTranslator translator) {
		return new DBHTXXExcel(entityManager, jparam, translator);
	}

	public int getSalePlanUnapproved() {
		Query q = entityManager.createQuery("select count(h) from HTXX h where h.sftgjhsh = 'N'");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	public int getSaleBussinessUnapproved() {
		Query q = entityManager.createQuery("select count(h) from HTXX h where h.sftgywsh = 'N'");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}
}
