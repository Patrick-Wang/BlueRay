package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;

@Repository
@Transactional("transactionManager")
public class SaleDaoImpl implements SaleDao{


	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

	
	public List<BMQXHFLXX> getSaleData() {
		Query q = entityManager.createQuery(
				"select b from BMQXHFLXX b");
		return q.getResultList();
	}


	public void insert(BMQXHFLXX bxx) {
		entityManager.persist(bxx);
		
	}

}
