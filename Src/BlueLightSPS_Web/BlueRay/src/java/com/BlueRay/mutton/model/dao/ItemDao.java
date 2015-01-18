package com.BlueRay.mutton.model.dao;

import java.util.List;

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

public interface ItemDao {

	List<BMQXHFLXX> queryBmqxhflxx();
	BMQXHFLXX queryBmqxhflxxById(int id);
	BMQXHFLXX queryBmqxhflxxByValue(String colName, Object val);
	void insert(BMQXHFLXX item);

	List<ZDQDYFLXX> queryZdqdyflxx();
	ZDQDYFLXX queryZdqdyflxxById(int id);
	ZDQDYFLXX queryZdqdyflxxByValue(String colName, Object val);
	void insert(ZDQDYFLXX item);

	List<ZCXX> queryZcxx();
	ZCXX queryZcxxById(int id);
	ZCXX queryZcxxByValue(String colName, Object val);
	void insert(ZCXX item);

	List<YYLGGFLXX> queryYylggflxx();
	YYLGGFLXX queryYylggflxxById(int id);
	YYLGGFLXX queryYylggflxxByValue(String colName, Object val);
	void insert(YYLGGFLXX item);

	List<KHXX> queryKhxx();
	KHXX queryKhxxById(int id);
	KHXX queryKhxxByValue(String colName, Object val);
	void insert(KHXX item);

	List<DDZTB> queryDdztb();
	DDZTB queryDdztbById(int id);
	DDZTB queryDdztbByValue(String colName, Object val);
	void insert(DDZTB item);

	List<BPQXHFLXX> queryBpqxhflxx();
	BPQXHFLXX queryBpqxhflxxById(int id);
	BPQXHFLXX queryBpqxhflxxByValue(String colName, Object val);
	void insert(BPQXHFLXX item);

	List<CPGGXHXX> queryCpggxhxx();
	CPGGXHXX queryCpggxhxxById(int id);
	CPGGXHXX queryCpggxhxxByValue(String colName, Object val);
	void insert(CPGGXHXX item);

	List<MPZLXX> queryMpzlxx();
	MPZLXX queryMpzlxxById(int id);
	MPZLXX queryMpzlxxByValue(String colName, Object val);
	void insert(MPZLXX item);
	
	List<BZXDTGG> queryBzxdtgg();
	BZXDTGG queryBzxdtggById(int id);
	BZXDTGG queryBzxdtggByValue(String colName, Object val);
	void insert(BZXDTGG item);
	
	List<ZDQXH> queryZdqxh();
	ZDQXH queryZdqxhById(int id);
	ZDQXH queryZdqxhByValue(String colName, Object val);
	void insert(ZDQXH item);
	
	List<ZJDY> queryZJDY();
	ZJDY queryZJDYById(int id);
	ZJDY queryZJDYByValue(String colName, Object val);	
	void insert(ZJDY item);
	
	List<ZJYS> queryZJYS();
	ZJYS queryZJYSById(int id);
	ZJYS queryZJYSByValue(String colName, Object val);	
	void insert(ZJYS item);
	
	List<KHQY> queryKHQY();
	KHQY queryKHQYById(int id);
	KHQY queryKHQYByValue(String colName, Object val);	
	void insert(KHQY item);
	
	List<ZZS> queryZZS();
	ZZS queryZZSById(int id);
	ZZS queryZZSByValue(String colName, Object val);	
	void insert(ZZS item);
}
