package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.SerialNumber;
import com.BlueRay.mutton.model.entity.jpa.User;
@Repository
@Transactional("transactionManager")
public class SNDaoImpl implements SNDao{
	
	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
	
	public User getUserByName(String name){
		Query q = entityManager.createQuery("from User where name = :name");
		q.setParameter("name", name);
		List<User> users = q.getResultList();
		if (users != null && !users.isEmpty()){
			return users.get(0);
		}
		return null;
	}

	public SerialNumber getSNById(Integer id) {
		Query q = entityManager.createQuery("from SerialNumber where id = :id");
		q.setParameter("id", id);
		List<SerialNumber> SNs = q.getResultList();
		if (SNs != null && !SNs.isEmpty()){
			return SNs.get(0);
		}
		return null;
	}

	public void saveSN(SerialNumber sn) {
		entityManager.persist(sn);
	}
}
