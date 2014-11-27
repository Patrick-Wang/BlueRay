package com.BlueRay.mutton.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.DDZTB;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

@Service
@Transactional("transactionManager")
public class ItemQueryServiceImpl implements ItemQueryService {

	@Autowired
	private ItemDao itemDao;

	public List<String> queryItems(String tableName) {
		List<String> ret = null;
		if ("bmqxhflxx".equals(tableName)) {
			ret = queryBmqxhflxx();
		} else if ("bpqxhflxx".equals(tableName)) {
			ret = queryBpqxhflxx();
		} else if ("ddztb".equals(tableName)) {
			ret = queryDdztb();
		} else if ("khxx".equals(tableName)) {
			ret = queryKhxx();
		} else if ("yylggflxx".equals(tableName)) {
			ret = queryYylggflxx();
		} else if ("zcxx".equals(tableName)) {
			ret = queryZcxx();
		} else if ("zdqdyflxx".equals(tableName)) {
			ret = queryZdqdyflxx();
		} else if ("cpggxhxx".equals(tableName)) {
			ret = queryCpggxhxx();
		} 
		
		return ret;
	}

	private List<String> queryCpggxhxx() {
		List<CPGGXHXX> items = itemDao.queryCpggxhxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getGg());
		}
		return ret;
	}

	private List<String> queryBmqxhflxx() {
		List<BMQXHFLXX> items = itemDao.queryBmqxhflxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getBmqxh());
		}
		return ret;
	}

	private List<String> queryZdqdyflxx() {
		List<ZDQDYFLXX> items = itemDao.queryZdqdyflxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZdqdy());
		}
		return ret;
	}

	private List<String> queryZcxx() {
		List<ZCXX> items = itemDao.queryZcxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZcxh());
		}
		return ret;
	}

	private List<String> queryYylggflxx() {
		List<YYLGGFLXX> items = itemDao.queryYylggflxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getYylgg());
		}
		return ret;
	}

	private List<String> queryKhxx() {
		List<KHXX> items = itemDao.queryKhxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getKhmc());
		}
		return ret;
	}

	private List<String> queryDdztb() {
		List<DDZTB> items = itemDao.queryDdztb();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getDdzt());
		}
		return ret;
	}

	private List<String> queryBpqxhflxx() {
		List<BPQXHFLXX> items = itemDao.queryBpqxhflxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getBpqxh());
		}
		return ret;
	}

}
