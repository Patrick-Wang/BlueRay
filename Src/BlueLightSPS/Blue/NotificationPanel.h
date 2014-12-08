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
	virtual void OnInitChilds();
	virtual void OnHttpSuccess(int id, LPCTSTR resp);
	virtual void OnHttpFailed(int id);
	virtual void OnRowChecked();
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

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

