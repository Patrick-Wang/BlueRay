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
	virtual void OnDataUpdate();
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

	void OnModifyDataSuccess(std::vector<CString>& newData);

private:
	virtual void PostNcDestroy();

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
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnNcDestroy();
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

