package com.BlueRay.mutton.model.dao;

import java.lang.reflect.Field;
import java.sql.Date;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

@Repository
@Transactional("transactionManager")
public class SaleDaoImpl implements SaleDao{


	@PersistenceContext(unitName = "localDB")
	private EntityManager entityManager;

	
	public void insert(HTXX bxx) {
		entityManager.persist(bxx);
	}


	public void del(HTXX htxx) {
		HTXX entity = entityManager.find(HTXX.class, htxx.getID());
		entityManager.remove(entity);
	}


	public void update(HTXX htxx) {
		entityManager.merge(htxx);
		
	}


	public HTXX getSaleDataById(int id) {
		Query q = entityManager.createQuery("select h from HTXX h where h.ID = :id");
		q.setParameter("id", id);
		List<HTXX> htxxs = q.getResultList();
		if (htxxs != null && !htxxs.isEmpty()){
			return htxxs.get(0);
		}
		return null;
	}

	
	private String getApprovedSql(String approved){
		if ("approved".equals(approved)){
			return "'Y'";
		} else {
			return "'N'";
		} 
	}
	

	private String getApproveTypeSql(String approveType){
		if ("plan".equals(approveType)){
			return "sftgjhsh";
		} else if ("business".equals(approveType)){
			return "sftgywsh";
		} else{
			return "";
		} 
	}
	public List<HTXX> getSaleData(String approveType, String approved) {
		String sql = "from HTXX";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sql += " where " + approveSql + " = " + typeSql;
		} 
		Query q = entityManager.createQuery(sql);
		return q.getResultList();
	}


	public List<HTXX> getSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			Integer col, Boolean sort) {
		String sql = "select h from HTXX h ";
		String colName = null;
		String id = null;
		if (col >= 0){
			Class<?> cls = HTXX.getFroeignClass(col);
			if (null != cls){
				sql += ", " + cls.getName() + " cls ";
				if (cls.getName().equals(KHXX.class.getName())){
					id = "clientID";
					colName = "khmc";
				} else if (cls.getName().equals(CPGGXHXX.class.getName())){
					id = "cpggxhID";
					colName = "gg";
				} else if (cls.getName().equals(ZCXX.class.getName())){
					colName = "zcxh";
					id = "zcxhID";
				} else if (cls.getName().equals(ZDQDYFLXX.class.getName())){
					colName = "zdqdy";
					id = "zdqdyID";
				} else if (cls.getName().equals(YYLGGFLXX.class.getName())){
					colName = "yylgg";
					id = "yylggID";
				} else if (cls.getName().equals(BPQXHFLXX.class.getName())){
					colName = "bpqxh";
					id = "bpqxhID";
				} else if (cls.getName().equals(BMQXHFLXX.class.getName())){
					colName = "bmqxh";
					id = "bmqxhID";
				}
			} 
		}
		String sqlWhere = " where ";
		String sqlOrder = " order by ";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sqlWhere += " h." + approveSql + " = " + typeSql;
		} 
		
		if (null != colName){
			if (!" where ".equals(sqlWhere)){
				sqlWhere += " and ";
			}
			sqlWhere += " h." + HTXX.class.getDeclaredFields()[col].getName() + "=cls." + id;
			sqlOrder += "cls." + colName + (sort ? " asc" : " desc");	
		} else{
			if (col >= 0){
				sqlOrder += " h." + HTXX.class.getDeclaredFields()[col].getName() + (sort ? " asc" : " desc");
			}
		}
		
		if (!" where ".equals(sqlWhere)){
			sql += sqlWhere;
		}
		
		if (!" order by ".equals(sqlOrder)){
			sql += sqlOrder;
		}
		
		Query q = entityManager.createQuery(sql);
		q.setFirstResult((pagenum - 1) * pagesize);
		q.setMaxResults(pagesize * pagecount);
		return q.getResultList();
	}


	public int getSaleDataCount() {
		Query q = entityManager.createQuery("select count(h) from HTXX h");
		List<Object> objs = q.getResultList();
		return ((Long) objs.get(0)).intValue();
	}

	private String getForginId(Class<?> cls){
		String colName = null;
		String id = null;
		if (cls.getName().equals(KHXX.class.getName())){
			id = "clientID";
			colName = "khmc";
		} else if (cls.getName().equals(CPGGXHXX.class.getName())){
			id = "cpggxhID";
			colName = "gg";
		} else if (cls.getName().equals(ZCXX.class.getName())){
			colName = "zcxh";
			id = "zcxhID";
		} else if (cls.getName().equals(ZDQDYFLXX.class.getName())){
			colName = "zdqdy";
			id = "zdqdyID";
		} else if (cls.getName().equals(YYLGGFLXX.class.getName())){
			colName = "yylgg";
			id = "yylggID";
		} else if (cls.getName().equals(BPQXHFLXX.class.getName())){
			colName = "bpqxh";
			id = "bpqxhID";
		} else if (cls.getName().equals(BMQXHFLXX.class.getName())){
			colName = "bmqxh";
			id = "bmqxhID";
		}
		return id;
	}
	
	private String getForginName(Class<?> cls){
		String colName = null;
		String id = null;
		if (cls.getName().equals(KHXX.class.getName())){
			id = "clientID";
			colName = "khmc";
		} else if (cls.getName().equals(CPGGXHXX.class.getName())){
			id = "cpggxhID";
			colName = "gg";
		} else if (cls.getName().equals(ZCXX.class.getName())){
			colName = "zcxh";
			id = "zcxhID";
		} else if (cls.getName().equals(ZDQDYFLXX.class.getName())){
			colName = "zdqdy";
			id = "zdqdyID";
		} else if (cls.getName().equals(YYLGGFLXX.class.getName())){
			colName = "yylgg";
			id = "yylggID";
		} else if (cls.getName().equals(BPQXHFLXX.class.getName())){
			colName = "bpqxh";
			id = "bpqxhID";
		} else if (cls.getName().equals(BMQXHFLXX.class.getName())){
			colName = "bmqxh";
			id = "bmqxhID";
		}
		return colName;
	}
	
	private String getSqlKeyword(Field field, String keyword) throws Exception{
		String ret = null;
		try {
			if (field.getType().getSimpleName().equals(Integer.class.getSimpleName())){
				Integer.valueOf(keyword);
				ret = keyword;
			} else if (field.getType().getSimpleName().equals(String.class.getSimpleName())){
				ret = "'" + keyword + "'";
			} else if (field.getType().getSimpleName().equals(Boolean.class.getSimpleName())){
				try {
					Boolean.valueOf(keyword);
					ret = keyword;
				}
				catch (Exception e){
					throw new Exception("is not boolean");
				}
			} else if (field.getType().getSimpleName().equals(Date.class.getSimpleName())){
				try {
					Date.valueOf(keyword);
					throw new Exception("is date");
				}
				catch (Exception e){
					if ("is date".equals(e.getMessage())){
						throw e;
					} else	{
						throw new Exception("is not date");
					}
				}
				
			}
		}
		catch (Exception e){
			if ("is date".equals(e.getMessage())){
				throw e;
			} else if("is not date".equals(e.getMessage())){
				throw e;
			} else if("is not boolean".equals(e.getMessage())){
				throw e;
			} 
		}
		
		return ret;
	}
	
	public List<HTXX> getSearchedSaleData(String approveType, String approved,
			Integer pagesize, Integer pagenum, Integer pagecount,
			Integer col, Boolean sort, String keyword) {
		String sql = "select h from HTXX h, KHXX KHXX_, CPGGXHXX CPGGXHXX_, ZCXX ZCXX_, ZDQDYFLXX ZDQDYFLXX_, YYLGGFLXX YYLGGFLXX_, BPQXHFLXX BPQXHFLXX_, BMQXHFLXX BMQXHFLXX_ ";
		String colName = null;
		String id = null;
		if (col >= 0){
			Class<?> cls = HTXX.getFroeignClass(col);
			if (null != cls){
				id = getForginId(cls);
				colName = getForginName(cls);
			} 
		}
		String sqlWhere = " where ";
		String sqlOrder = " order by ";
		String typeSql = getApproveTypeSql(approveType);
		String approveSql =  getApprovedSql(approved);
		if (!typeSql.isEmpty()){
			sqlWhere += " h." + approveSql + " = " + typeSql;
		} 
		
		if (null != colName){
			Class<?> cls = HTXX.getFroeignClass(col);
			sqlOrder += cls.getSimpleName() + "_." + colName + (sort ? " asc" : " desc");	
		} else{
			if (col >= 0){
				sqlOrder += " h." + HTXX.class.getDeclaredFields()[col].getName() + (sort ? " asc" : " desc");
			}
		}
		
		boolean firstAnd = false;
		if (!" where ".equals(sqlWhere)){
			sqlWhere += " and ";
		}
		
		Field[] fields = HTXX.class.getDeclaredFields();
		for (int i = 1; i < fields.length - 1; ++i){
			if (i != col){
				Class<?> cls = HTXX.getFroeignClass(i);
				if (null != cls){
					if (!firstAnd){
						firstAnd = true;
					} 
					else{
						sqlWhere += " and ";
					}
					sqlWhere += " h." + fields[i].getName() + "="  +  cls.getSimpleName() + "_." + getForginId(cls) + " ";
				}
			}
		}
		firstAnd = false;
		sqlWhere += " and ( ";
		for (int i = 1; i < fields.length - 1; ++i){
				
				
				Class<?> cls = HTXX.getFroeignClass(i);
				if (null != cls){
					if (!firstAnd){
						firstAnd = true;
					} 
					else{
						sqlWhere += " or ";
					}
					sqlWhere += cls.getSimpleName() + "_." + getForginName(cls) + "='"  + keyword + "' ";
				} else{
					try {
						String key = getSqlKeyword(fields[i], keyword);
						if (!firstAnd){
							firstAnd = true;
						} 
						else{
							sqlWhere += " or ";
						}
						sqlWhere += "h." + fields[i].getName() + "="  + key + " ";
					} catch (Exception e) {
						if ("is date".equals(e.getMessage())){
							if (!firstAnd){
								firstAnd = true;
							} 
							else{
								sqlWhere += " or ";
							}
							sqlWhere += "DATEDIFF(yymmdd, h." + fields[i].getName() + ","  + keyword + ") ";
						}
					}
					
					
				}
		}
		sqlWhere += " ) ";
		
		if (!" where ".equals(sqlWhere)){
			sql += sqlWhere;
		}
		
		if (!" order by ".equals(sqlOrder)){
			sql += sqlOrder;
		}
		
		Query q = entityManager.createQuery(sql);
		q.setFirstResult((pagenum - 1) * pagesize);
		q.setMaxResults(pagesize * pagecount);
		return q.getResultList();
	}



}
