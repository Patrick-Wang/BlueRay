package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.User;
@Repository
@Transactional("transactionManager")
public class UserDaoImpl implements UserDao{
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
}
