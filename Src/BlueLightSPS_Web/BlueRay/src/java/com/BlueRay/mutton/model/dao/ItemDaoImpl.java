package com.BlueRay.mutton.model.dao;

import java.util.List;









import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BZXDTGG;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.DDZTB;
import com.BlueRay.mutton.model.entity.jpa.KHQY;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQXH;
import com.BlueRay.mutton.model.entity.jpa.ZJDY;
import com.BlueRay.mutton.model.entity.jpa.ZJYS;
import com.BlueRay.mutton.model.entity.jpa.ZZS;

@Repository
@Transactional("transactionManager")
public class ItemDaoImpl implements ItemDao{

	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;
	
	public List<BMQXHFLXX> queryBmqxhflxx() {
		Query q = entityManager.createQuery("select t from BMQXHFLXX t where t.bmqxhID > 1");
		return q.getResultList();
	}

	public List<ZDQDYFLXX> queryZdqdyflxx() {
		Query q = entityManager.createQuery("select t from ZDQDYFLXX t where t.zdqdyID > 1");
		return q.getResultList();
	}

	public List<ZCXX> queryZcxx() {
		Query q = entityManager.createQuery("select t from ZCXX t where t.zcxhID > 1");
		return q.getResultList();
	}

	public List<YYLGGFLXX> queryYylggflxx() {
		Query q = entityManager.createQuery("select t from YYLGGFLXX t where t.yylggID > 1");
		return q.getResultList();
	}

	public List<KHXX> queryKhxx() {
		Query q = entityManager.createQuery("select t from KHXX t where t.clientID > 1");
		return q.getResultList();
	}

	public List<DDZTB> queryDdztb() {
		Query q = entityManager.createQuery("select t from DDZTB t where t.ddztID > 1");
		return q.getResultList();
	}

	public List<BPQXHFLXX> queryBpqxhflxx() {
		Query q = entityManager.createQuery("select t from BPQXHFLXX t where t.bpqxhID > 1");
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
		Query q = entityManager.createQuery("select t from CPGGXHXX t where t.cpggxhID > 1");
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

	public BMQXHFLXX queryBmqxhflxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from BMQXHFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<BMQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZDQDYFLXX queryZdqdyflxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZDQDYFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZDQDYFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZCXX queryZcxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZCXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZCXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public YYLGGFLXX queryYylggflxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from YYLGGFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<YYLGGFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public KHXX queryKhxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from KHXX t where t." + colName + " = :val");
		//
		q.setParameter("val", val);
		List<KHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public DDZTB queryDdztbByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from DDZTB t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<DDZTB> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public BPQXHFLXX queryBpqxhflxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from BPQXHFLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<BPQXHFLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public CPGGXHXX queryCpggxhxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from CPGGXHXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<CPGGXHXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public List<MPZLXX> queryMpzlxx() {
		Query q = entityManager.createQuery("select t from MPZLXX t where t.id > 1");
		return q.getResultList();
	}

	public MPZLXX queryMpzlxxById(int id) {
		Query q = entityManager.createQuery("select t from MPZLXX t where t.id = :id");
		q.setParameter("id", id);
		List<MPZLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public MPZLXX queryMpzlxxByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from MPZLXX t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<MPZLXX> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public void insert(MPZLXX item) {
		entityManager.persist(item);
	}

	public List<BZXDTGG> queryBzxdtgg() {
		Query q = entityManager.createQuery("select t from BZXDTGG t where t.id > 1");
		return q.getResultList();
	}

	public BZXDTGG queryBzxdtggById(int id) {
		Query q = entityManager.createQuery("select t from BZXDTGG t where t.id = :id");
		q.setParameter("id", id);
		List<BZXDTGG> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public BZXDTGG queryBzxdtggByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from BZXDTGG t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<BZXDTGG> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public void insert(BZXDTGG item) {
		entityManager.persist(item);
	}

	public List<ZDQXH> queryZdqxh() {
		Query q = entityManager.createQuery("select t from ZDQXH t where t.id > 1");
		return q.getResultList();
	}

	public ZDQXH queryZdqxhById(int id) {
		Query q = entityManager.createQuery("select t from ZDQXH t where t.id = :id");
		q.setParameter("id", id);
		List<ZDQXH> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZDQXH queryZdqxhByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZDQXH t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZDQXH> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;	
	}

	public void insert(ZDQXH item) {
		entityManager.persist(item);		
	}

	public List<ZJDY> queryZJDY() {
		Query q = entityManager.createQuery("select t from ZJDY t where t.id > 1");
		return q.getResultList();
	}

	public ZJDY queryZJDYById(int id) {
		Query q = entityManager.createQuery("select t from ZJDY t where t.id = :id");
		q.setParameter("id", id);
		List<ZJDY> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZJDY queryZJDYByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZJDY t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZJDY> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;	
	}

	public void insert(ZJDY item) {
		entityManager.persist(item);
	}

	public List<ZJYS> queryZJYS() {
		Query q = entityManager.createQuery("select t from ZJYS t where t.id > 1");
		return q.getResultList();
	}

	public ZJYS queryZJYSById(int id) {
		Query q = entityManager.createQuery("select t from ZJYS t where t.id = :id");
		q.setParameter("id", id);
		List<ZJYS> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZJYS queryZJYSByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZJYS t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZJYS> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;	
	}

	public void insert(ZJYS item) {
		entityManager.persist(item);		
	}

	public List<KHQY> queryKHQY() {
		Query q = entityManager.createQuery("select t from KHQY t where t.id > 1");
		return q.getResultList();
	}

	public KHQY queryKHQYById(int id) {
		Query q = entityManager.createQuery("select t from KHQY t where t.id = :id");
		q.setParameter("id", id);
		List<KHQY> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public KHQY queryKHQYByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from KHQY t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<KHQY> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public void insert(KHQY item) {
		entityManager.persist(item);		
	}

	public List<ZZS> queryZZS() {
		Query q = entityManager.createQuery("select t from ZZS t where t.id > 1");
		return q.getResultList();
	}

	public ZZS queryZZSById(int id) {
		Query q = entityManager.createQuery("select t from ZZS t where t.id = :id");
		q.setParameter("id", id);
		List<ZZS> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public ZZS queryZZSByValue(String colName, String val) {
		Query q = entityManager.createQuery("select t from ZZS t where t." + colName + "  = :val");
		
		q.setParameter("val", val);
		List<ZZS> list = q.getResultList();
		if (list != null && !list.isEmpty()){
			return list.get(0);
		}
		return null;
	}

	public void insert(ZZS item) {
		entityManager.persist(item);				
	}

}
