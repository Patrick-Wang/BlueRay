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
	
	public List<PCJHXX> getPcjhxx() {
		Query q = entityManager.createQuery("select p from PCJHXX p");
		return q.getResultList();
	}

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

}
