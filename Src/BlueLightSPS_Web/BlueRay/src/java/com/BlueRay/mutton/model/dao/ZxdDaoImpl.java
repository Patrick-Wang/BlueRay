package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.ZXD;

@Repository
@Transactional("transactionManager")
public class ZxdDaoImpl implements ZxdDao{

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

	public ZXD getDataByType(String ggxh) {
		Query q = entityManager.createQuery("select t from ZXD t where t.type = :gg");
		q.setParameter("gg", ggxh);
		List<ZXD> zxds = q.getResultList();
		if (zxds != null && !zxds.isEmpty()){
			return zxds.get(0);
		}
		return null;
	}

}
