#pragma once
#include "BRPanel.h"
#include "JQGridAPI.h"
#include "BSStatic.h"
#include "BRButton.h"

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

private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPIForSale;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPIForPlan;

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

	void HideFirstViewOfNotificationPanel(BOOL bShow = FALSE);

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
};

