#pragma once
#include "BRPanel.h"
#include "JQGridAPI.h"
#include "BSStatic.h"
#include "BRButton.h"
#include "TableFilterDlg.h"
#include "Notification.h"
#include "JsonQueryParam.h"

class CNotificationPanel :
	public CBRPanel
{

	class CNotificationSearchListener : public CPromise<PageData_t>::IHttpResponse{
		CONSTRUCTOR_3(CNotificationSearchListener, CNotificationPanel&, notificationPanel, table&, tb, CJQGridAPI*, pJqGridAPI)
	public:
		virtual void OnSuccess(PageData_t& tb){
			m_pJqGridAPI->Refresh(tb.rawData);

			m_tb = tb.rows;
			if (m_tb.empty())
			{
				m_notificationPanel.MessageBox(_T("没有符合条件的记录"), _T("查询结果"), MB_OK | MB_ICONWARNING);
			}
			m_notificationPanel.GetParent()->EnableWindow(TRUE);

			m_notificationPanel.HighLight();
			//			m_pJqGridAPI->UncheckedAll();
			m_notificationPanel.OnRowChecked();
		}
		virtual void OnFailed(){
			m_notificationPanel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
			m_notificationPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	class CQueryListener : public CPromise<PageData_t>::IHttpResponse{
		CONSTRUCTOR_3(CQueryListener, CNotificationPanel&, panel, table&, page, CJQGridAPI*, pJqGridAPI)
	public:
		virtual void OnSuccess(PageData_t& page){
			m_pJqGridAPI->Refresh(page.rawData);
			m_page = page.rows;

			(m_panel.OnLoadDataSuccess)(page);
			m_panel.GetParent()->EnableWindow(TRUE);
			m_panel.HighLight();
//			m_pJqGridAPI->UncheckedAll();
			m_panel.OnRowChecked();
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
			m_panel.GetParent()->EnableWindow(TRUE);
		}
	};

public:
	//CNotificationPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	CNotificationPanel(CJQGridAPI* pJqGridAPI);
	~CNotificationPanel();

protected:
	virtual void OnInitData();
	virtual void OnInitChilds();
	//virtual void OnHttpSuccess(int id, LPCTSTR resp);
	//virtual void OnHttpFailed(int id);
	virtual void OnRowChecked();
	void OnUpdateData(int page, int rows, int colIndex, bool bAsc);
	void HighLight();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedMore();

private:
	void OnReturnApprovedNum(CNotification::Unapproved_t& stUnapproved);
	void HideFirstViewOfNotificationPanel(BOOL bShow = FALSE);
	void OnLoadDataSuccess(PageData_t& page);
	void AdjustTableStyleForPlan();
	void AdjustTableStyleForSale();
	void AdjustTableStyleForNotification();
	void MakeBasicSearchCondition(CJsonQueryParam &sqp);

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
	CBSStatic* m_staticPromotion;
	bool m_bIfUpdateTableWhenTableFilter;
	std::vector<CString> advanceSearchVals;
	//add for search/filter
	CBSStatic* m_bsDateRange;
	CBSStatic* m_bsMiddleLine;
	CDateTimeCtrl* m_dtcSearchFrom;
	CDateTimeCtrl* m_dtcSearchTo;
	CEdit* m_editSearch;
	CBRButton* m_btnSearch;
	CBRButton* m_btnMore;

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
	afx_msg void OnNcDestroy();

	afx_msg void OnBnClickedSaleBusinessApprove();
	afx_msg void OnBnClickedSalePlanApprove();
	afx_msg void OnBnClickedPlanSCRQBusinessApprove();
	afx_msg void OnBnClickedPlanSCRQPlanApprove();
	afx_msg void OnBnClickedPlanBZRQBusinessApprove();
	afx_msg void OnBnClickedPlanBZRQPlanApprove();
	afx_msg void OnDestroy();

	afx_msg void OnBnClickedBtnApprove();
	afx_msg void OnBnClickedBtnReturn();
	afx_msg void OnBnClickedBtnTableFilter();
};

