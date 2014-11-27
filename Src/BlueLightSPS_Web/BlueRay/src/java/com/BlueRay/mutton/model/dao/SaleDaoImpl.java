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

	
	public List<HTXX> getSaleData() {
		Query q = entityManager.createQuery("select h from HTXX h");
		return q.getResultList();
	}


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

}
