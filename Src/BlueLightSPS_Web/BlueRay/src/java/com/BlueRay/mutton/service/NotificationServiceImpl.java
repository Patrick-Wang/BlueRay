package com.BlueRay.mutton.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.controller.UnapprovedBean;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;

@Service
@Transactional("transactionManager")
public class NotificationServiceImpl implements NotificationService{

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private PlanDao planDao;
	
	public UnapprovedBean getUnapproved(){
		UnapprovedBean unapproved = new UnapprovedBean();
		List<HTXX> htxxs = saleDao.getSaleData();
		for (HTXX htxx : htxxs){
			if (!"Y".equals(htxx.getSftgjhsh())){
				unapproved.setSalePlan(unapproved.getSalePlan() + 1);
			}
			if (!"Y".equals(htxx.getSftgywsh())){
				unapproved.setSaleBussiness(unapproved.getSaleBussiness() + 1);
			}
		}
		List<PCJHXX> pcjhxxs = planDao.getPcjhxx();
		for (PCJHXX pcjhxx : pcjhxxs){
			if (!"Y".equals(pcjhxx.getSftgjhsh())){
				unapproved.setPlanPlan(unapproved.getPlanPlan() + 1);
			}
			if (!"Y".equals(pcjhxx.getSftgywsh())){
				unapproved.setPlanBussiness(unapproved.getPlanBussiness() + 1);
			}
			if (!"Y".equals(pcjhxx.getBzsftgjhsh())){
				unapproved.setPackPlan(unapproved.getPackPlan() + 1);
			}
			if (!"Y".equals(pcjhxx.getBzsftgywsh())){
				unapproved.setPackBussiness(unapproved.getPackBussiness() + 1);
			}
		}
		return unapproved;
	}

}
