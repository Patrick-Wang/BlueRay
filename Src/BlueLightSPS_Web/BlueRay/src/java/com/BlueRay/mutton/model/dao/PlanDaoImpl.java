package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

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

}
