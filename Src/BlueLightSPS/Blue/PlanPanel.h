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
	CPlanPanel(CJQGridAPI* pJqGridAPI);
	~CPlanPanel();
	void HighLight();
	void OnRowChecked();
	void OnGridComplete();
	virtual void OnUIPrepared();
	//void OnHttpSuccess(int id, LPCTSTR resp);
	//void OnHttpFailed(int id);
	void OnLoadDataSuccess(CString& jsondata);
protected:
	void OnUpdateData(int page, int rows, int colIndex, bool bAsc);
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
	void OnExprotClicked();
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

	CBSStatic* m_bsDateRange;
	CBSStatic* m_bsMiddleLine;
	CDateTimeCtrl* m_dtcSearchFrom;
	CDateTimeCtrl* m_dtcSearchTo;

	CBSStatic* m_bsSCRQDateRange;
	CBSStatic* m_bsSCRQMiddleLine;
	CDateTimeCtrl* m_dtcSCRQSearchFrom;
	CDateTimeCtrl* m_dtcSCRQSearchTo;

	CBSStatic* m_bsBZRQDateRange;
	CBSStatic* m_bsBZRQMiddleLine;
	CDateTimeCtrl* m_dtcBZRQSearchFrom;
	CDateTimeCtrl* m_dtcBZRQSearchTo;

	CBSStatic* m_bsFHRQDateRange;
	CBSStatic* m_bsFHRQMiddleLine;
	CDateTimeCtrl* m_dtcFHRQSearchFrom;
	CDateTimeCtrl* m_dtcFHRQSearchTo;

	CBSStatic* m_staticProductionStatus;
	CComboBox* m_comboProductionStatus;
	CTableFilterDlg m_tableFilterDlg;

	int m_iCountBtnOfReApprove;

	CBSStatic* m_staticNoPermWarning;

	bool m_bEnablePlanBtnForSCRQ;
	bool m_bEnablePlanBtnForBZRQ;

	enum enumProductionStatusForPlan
	{
		ProductionStatus_All = 0,						//全部
		ProductionStatus_SCRQ_ToBePlanned,			//生产日期未计划
		ProductionStatus_SCRQ_ToBeApproved,			//生产日期已计划未审核
		ProductionStatus_SCRQ_Planning,				//生产日期已计划审核中	
		ProductionStatus_SCRQ_Planned,				//生产日期已审核
		ProductionStatus_BZRQ_ToBePlanned,			//包装日期未计划
		ProductionStatus_BZRQ_ToBeApproved,			//包装日期已计划未审核
		ProductionStatus_BZRQ_Planning,				//包装日期已计划审核中	
		ProductionStatus_BZRQ_Planned,				//包装日期已审核	
		ProductionStatus_FHRQ_Planned,				//发货日期已计划	
		ProductionStatus_FHRQ_ToBePlanned,			//发货日期未计划	
		ProductionStatus_All_PlannedAndApproved		//全部已审核已计划	
	};


	DECLARE_MESSAGE_MAP()

	void ShowReApproveSCRQPlanBtn(BOOL bShow);
	void ShowReApproveBZRQBusinessBtn(BOOL bShow);
	void ShowReApproveBZRQPlanBtn(BOOL bShow);
	void ShowReApproveSCRQBusinessBtn(BOOL bShow);
	void ShowReApproveBtns();
	void FilterTableByStatus(enumProductionStatusForPlan productionStatus, CJsonQueryParam &sqp);
	void MakeBasicSearchCondition(CJsonQueryParam &sqp);

public:
	afx_msg void OnNcDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnDestroy();
};

