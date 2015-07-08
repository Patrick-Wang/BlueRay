package com.BlueRay.mutton.service.item;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BZXDTGG;
import com.BlueRay.mutton.model.entity.jpa.CGXXB;
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
		} else if ("mpzlxx".equals(tableName)) {
			ret = queryMpzlxx();
		} else if ("zjdy".equals(tableName)) {
			ret = queryZjdy();
		} else if ("zjys".equals(tableName)) {
			ret = queryZjys();
		} else if ("zdqxh".equals(tableName)) {
			ret = queryZdqxh();
		} else if ("bzxdtgg".equals(tableName)) {
			ret = queryBzxdtgg();
		} else if ("zzs".equals(tableName)) {
			ret = queryZzs();
		} else if ("khqy".equals(tableName)) {
			ret = queryKhqy();
		} else if ("cgxx".equals(tableName)) {
			ret = queryCgxx();
		} 
		
		return ret;
	}

	private List<String> queryCgxx() {
		List<CGXXB> items = itemDao.queryCGXX();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getCg());
		}
		return ret;
	}

	private List<String> queryKhqy() {
		List<KHQY> items = itemDao.queryKHQY();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getKhqy());
		}
		return ret;
	}

	private List<String> queryZzs() {
		List<ZZS> items = itemDao.queryZZS();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZzs());
		}
		return ret;
	}

	private List<String> queryBzxdtgg() {
		List<BZXDTGG> items = itemDao.queryBzxdtgg();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getBzxdtgg());
		}
		return ret;
	}

	private List<String> queryZdqxh() {
		List<ZDQXH> items = itemDao.queryZdqxh();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZdqxh());
		}
		return ret;
	}

	private List<String> queryZjys() {
		List<ZJYS> items = itemDao.queryZJYS();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZjys());
		}
		return ret;
	}

	private List<String> queryZjdy() {
		List<ZJDY> items = itemDao.queryZJDY();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getZjdy());
		}
		return ret;
	}

	private List<String> queryMpzlxx() {
		List<MPZLXX> items = itemDao.queryMpzlxx();
		List<String> ret = new ArrayList<String>();
		for (int i = 0; i < items.size(); ++i) {
			ret.add(items.get(i).getMpzl());
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
