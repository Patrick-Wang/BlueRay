package com.BlueRay.mutton.model.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.Permission;
@Repository
@Transactional("transactionManager")
public class PermissionDaoImpl implements PermissionDao{
	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
	
	public Permission getPermissionByRole(String role) {
		Query q = entityManager.createQuery("from Permission where role = :role");
		q.setParameter("role", role);
		List<Permission> permissions = q.getResultList();
		if (permissions != null && !permissions.isEmpty()){
			return permissions.get(0);
		}
		return null;
	}
}
