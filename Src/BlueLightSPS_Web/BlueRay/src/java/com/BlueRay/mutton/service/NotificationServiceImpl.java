package com.BlueRay.mutton.service;

import java.util.List;

import net.sf.json.JSONObject;

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
public class NotificationServiceImpl implements NotificationService {

	@Autowired
	private SaleDao saleDao;

	@Autowired
	private PlanDao planDao;

	public UnapprovedBean getUnapproved() {
		UnapprovedBean unapproved = new UnapprovedBean();
//		int count = saleDao.getSaleDataCount();
//		List<HTXX> htxxs = saleDao.getSaleData(count, 1, 1, JSONObject.fromObject("{}"), null);
		unapproved.setSalePlan(saleDao.getSalePlanUnapproved());
		unapproved.setSaleBusiness(saleDao.getSaleBussinessUnapproved());

		unapproved.setPlanPlan(planDao.getPlanUnapproved());
		unapproved.setPlanBusiness(planDao.getBusinessUnapproved());
		unapproved.setPackPlan(planDao.getPackPlanUnapproved());
		unapproved.setPackBusiness(planDao.getPackBusinessUnapproved());
//		for (HTXX htxx : htxxs) {
//		if (!"Y".equals(htxx.getSftgjhsh())) {
//			unapproved.setSalePlan(unapproved.getSalePlan() + 1);
//		}
//		if (!"Y".equals(htxx.getSftgywsh())) {
//			unapproved.setSaleBussiness(unapproved.getSaleBussiness() + 1);
//		}
//	}
//		List<PCJHXX> pcjhxxs = planDao.getPcjhxx("all", "none");
//		for (PCJHXX pcjhxx : pcjhxxs) {
//			if (pcjhxx.getJhscrq() != null) {
//				if (!"Y".equals(pcjhxx.getSftgjhsh())) {
//					unapproved.setPlanPlan(unapproved.getPlanPlan() + 1);
//				}
//				if (!"Y".equals(pcjhxx.getSftgywsh())) {
//					unapproved
//							.setPlanBussiness(unapproved.getPlanBussiness() + 1);
//				}
//			}
//			if (pcjhxx.getJhbzrq() != null) {
//				if (!"Y".equals(pcjhxx.getBzsftgjhsh())) {
//					unapproved.setPackPlan(unapproved.getPackPlan() + 1);
//				}
//				if (!"Y".equals(pcjhxx.getBzsftgywsh())) {
//					unapproved
//							.setPackBussiness(unapproved.getPackBussiness() + 1);
//				}
//			}
//		}
		return unapproved;
	}

}
