#pragma once
#include "BRPanel.h"
#include "JQGridAPI.h"
#include "BSStatic.h"
#include "BRButton.h"
#include "TableFilterDlg.h"

class CNotificationPanel :
	public CBRPanel
{
public:
	CNotificationPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	~CNotificationPanel();

protected:
	virtual void OnDataUpdate();
	virtual void OnInitChilds();
	virtual void OnHttpSuccess(int id, LPCTSTR resp);
	virtual void OnHttpFailed(int id);
	virtual void OnRowChecked();

private:
	void OnReturnApprovedNum(LPCTSTR resp);
	void HideFirstViewOfNotificationPanel(BOOL bShow = FALSE);
	void OnLoadDataSuccess(CString& jsondata);
	void AdjustTableStyleForPlan();
	void AdjustTableStyleForSale();
	void AdjustTableStyleForNotification();

private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;

	CBSStatic m_bsSaleBusinessApprove;
	CBSStatic m_bsSalePlanApprove;
	CBSStatic m_bsPlanSCRQBusinessApprove;
	CBSStatic m_bsPlanSCRQPlanApprove;
	CBSStatic m_bsPlanBZRQBusinessApprove;
	CBSStatic m_bsPlanBZRQPlanApprove;

	CBRButton m_btnSaleBusinessApprove;
	CBRButton m_btnSalePlanApprove;
	CBRButton m_btnPlanSCRQBusinessApprove;
	CBRButton m_btnPlanSCRQPlanApprove;
	CBRButton m_btnPlanBZRQBusinessApprove;
	CBRButton m_btnPlanBZRQPlanApprove;

	CBRButton m_btnApproveInSecond;
	CBRButton m_btnReturnToFirst;

	CBRButton m_btnTableFilter;

	CTableFilterDlg *m_pTableFilter;

	enum enumApprovingItem{
		Approving_NULL = -1,
		Approving_SaleBusiness,
		Approving_SalePlan,
		Approving_PlanSCRQBusiness,
		Approving_PlanSCRQPlan,
		Approving_PlanBZRQBusiness,
		Approving_PlanBZRQPlan,
		Approving_END
	};

	enumApprovingItem m_enumCurrentApprovingItem;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	afx_msg void OnBnClickedSaleBusinessApprove();
	afx_msg void OnBnClickedSalePlanApprove();
	afx_msg void OnBnClickedPlanSCRQBusinessApprove();
	afx_msg void OnBnClickedPlanSCRQPlanApprove();
	afx_msg void OnBnClickedPlanBZRQBusinessApprove();
	afx_msg void OnBnClickedPlanBZRQPlanApprove();

	afx_msg void OnBnClickedBtnApprove();
	afx_msg void OnBnClickedBtnReturn();
	afx_msg void OnBnClickedBtnTableFilter();
};

