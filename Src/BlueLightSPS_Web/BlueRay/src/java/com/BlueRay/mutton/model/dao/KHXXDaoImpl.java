package com.BlueRay.mutton.model.dao;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

@Repository
@Transactional("transactionManager")
public class KHXXDaoImpl implements KHXXDao {
	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
}
