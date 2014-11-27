package com.BlueRay.mutton.model.dao;

import java.util.List;






import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.DDZTB;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

@Repository
@Transactional("transactionManager")
public class ItemDaoImpl implements ItemDao{

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
	
	public List<BMQXHFLXX> queryBmqxhflxx() {
		Query q = entityManager.createQuery("select t from BMQXHFLXX t");
		return q.getResultList();
	}

	public List<ZDQDYFLXX> queryZdqdyflxx() {
		Query q = entityManager.createQuery("select t from ZDQDYFLXX t");
		return q.getResultList();
	}

	public List<ZCXX> queryZcxx() {
		Query q = entityManager.createQuery("select t from ZCXX t");
		return q.getResultList();
	}

	public List<YYLGGFLXX> queryYylggflxx() {
		Query q = entityManager.createQuery("select t from YYLGGFLXX t");
		return q.getResultList();
	}

	public List<KHXX> queryKhxx() {
		Query q = entityManager.createQuery("select t from KHXX t");
		return q.getResultList();
	}

	public List<DDZTB> queryDdztb() {
		Query q = entityManager.createQuery("select t from DDZTB t");
		return q.getResultList();
	}

	public List<BPQXHFLXX> queryBpqxhflxx() {
		Query q = entityManager.createQuery("select t from BPQXHFLXX t");
		return q.getResultList();
	}

	public BMQXHFLXX queryBmqxhflxxById(int id) {
		Query q = entityManager.createQuery("select t from BMQXHFLXX t where t.bmqxhID = :id");
		q.setParameter("id", id);
		List<BMQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZDQDYFLXX queryZdqdyflxxById(int id) {
		Query q = entityManager.createQuery("select t from ZDQDYFLXX t where t.zdqdyID = :id");
		q.setParameter("id", id);
		List<ZDQDYFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZCXX queryZcxxById(int id) {
		Query q = entityManager.createQuery("select t from ZCXX t where t.zcxhID = :id");
		q.setParameter("id", id);
		List<ZCXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public YYLGGFLXX queryYylggflxxById(int id) {
		Query q = entityManager.createQuery("select t from YYLGGFLXX t where t.yylggID = :id");
		q.setParameter("id", id);
		List<YYLGGFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public KHXX queryKhxxById(int id) {
		Query q = entityManager.createQuery("select t from KHXX t where t.clientID = :id");
		q.setParameter("id", id);
		List<KHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public DDZTB queryDdztbById(int id) {
		Query q = entityManager.createQuery("select t from DDZTB t where t.ddztID = :id");
		q.setParameter("id", id);
		List<DDZTB> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public BPQXHFLXX queryBpqxhflxxById(int id) {
		Query q = entityManager.createQuery("select t from BPQXHFLXX t where t.bpqxhID = :id");
		q.setParameter("id", id);
		List<BPQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public List<CPGGXHXX> queryCpggxhxx() {
		Query q = entityManager.createQuery("select t from CPGGXHXX t");
		return q.getResultList();
	}

	public CPGGXHXX queryCpggxhxxById(int id) {
		Query q = entityManager.createQuery("select t from CPGGXHXX t where t.cpggxhID = :id");
		q.setParameter("id", id);
		List<CPGGXHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public void insert(BMQXHFLXX item) {
		entityManager.persist(item);
		
	}

	public void insert(ZDQDYFLXX item) {
		entityManager.persist(item);	}

	public void insert(ZCXX item) {
		entityManager.persist(item);		
	}

	public void insert(YYLGGFLXX item) {
		entityManager.persist(item);		// TODO Auto-generated method stub
		
	}

	public void insert(KHXX item) {
		entityManager.persist(item);		// TODO Auto-generated method stub
		
	}

	public void insert(DDZTB item) {
		entityManager.persist(item);		// TODO Auto-generated method stub
		
	}

	public void insert(BPQXHFLXX item) {
		entityManager.persist(item);		// TODO Auto-generated method stub
		
	}

	public void insert(CPGGXHXX item) {
		entityManager.persist(item);		// TODO Auto-generated method stub
	}

	public BMQXHFLXX queryBmqxhflxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from BMQXHFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<BMQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZDQDYFLXX queryZdqdyflxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from ZDQDYFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZDQDYFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZCXX queryZcxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from ZCXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZCXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public YYLGGFLXX queryYylggflxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from YYLGGFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<YYLGGFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public KHXX queryKhxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from KHXX t where t." + colName + " = :val");
		//
		q.setParameter("val", val);
		List<KHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public DDZTB queryDdztbByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from DDZTB t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<DDZTB> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public BPQXHFLXX queryBpqxhflxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from BPQXHFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<BPQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public CPGGXHXX queryCpggxhxxByValue(String colName, Object val) {
		Query q = entityManager.createQuery("select t from CPGGXHXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<CPGGXHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

}
