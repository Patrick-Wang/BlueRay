#pragma once
#include "BRPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
#include "IHttp.h"
#include "TableFilterDlg.h"
class CPlanPanel :
	public CBRPanel
{
public:
	CPlanPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	~CPlanPanel();

	void OnRowChecked();
	void OnGridComplete();
	virtual void OnUIPrepared();
	void OnHttpSuccess(int id, LPCTSTR resp);
	void OnHttpFailed(int id);
	void OnLoadDataSuccess(CString& jsondata);
protected:
	virtual void OnInitChilds();
	virtual void OnInitData();
	afx_msg void OnBnClickedPlan();
	afx_msg void OnBnClickedRestore();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTableFilter();
	afx_msg void OnBnClickedMore();
	afx_msg void OnBnClickedReApproveBZRQBusiness();
	afx_msg void OnBnClickedReApproveBZRQPlan();
	afx_msg void OnBnClickedReApproveSCRQBusiness();
	afx_msg void OnBnClickedReApproveSCRQPlan();
	afx_msg void OnCbnSelchangeProductionStatus();

	void OnModifyDataSuccess(std::vector<CString>& newData);
	void OnReApproveSuccess(CPlan::ApproveType type);

private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::vector<CString> m_cacheRow;

	CBRButton* m_btnPlan;
	CBRButton* m_btnModify;
	CBRButton* m_btnRestore;
	CBRButton* m_btnSearch;
	CBRButton* m_btnMore;
	CBSStatic* m_bsMoreWord;
	CBRButton* m_btnTableFilter;
	CEdit* m_editSearch;

	CBRButton* m_btnReApproveSCRQBusiness;
	CBRButton* m_btnReApproveSCRQPlan;
	CBRButton* m_btnReApproveBZRQBusiness;
	CBRButton* m_btnReApproveBZRQPlan;

	CBSStatic* m_staticProductionStatus;
	CComboBox* m_comboProductionStatus;
	CTableFilterDlg m_tableFilterDlg;

	int m_iCountBtnOfReApprove;

	CBSStatic* m_staticNoPermWarning;

	enum enumProductionStatusForPlan
	{
		ProductionStatus_All,
		ProductionStatus_ToBePlan,
		ProductionStatus_Planning,
		ProductionStatus_Planned
	};


	DECLARE_MESSAGE_MAP()

	void ShowReApproveSCRQPlanBtn(BOOL bShow);
	void ShowReApproveBZRQBusinessBtn(BOOL bShow);
	void ShowReApproveBZRQPlanBtn(BOOL bShow);
	void ShowReApproveSCRQBusinessBtn(BOOL bShow);
	void ShowReApproveBtns();
	void FilterTableByStatus(enumProductionStatusForPlan productionStatus);

public:
	afx_msg void OnNcDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnDestroy();
};

