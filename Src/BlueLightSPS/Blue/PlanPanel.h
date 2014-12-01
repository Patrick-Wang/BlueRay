#pragma once
#include "ControlPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
#include "IHttp.h"
class CPlanPanel :
	public CControlPanel
{
public:
	CPlanPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	~CPlanPanel();

	void OnRowChecked();
	void OnGridComplete();
	void OnUIPrepared();
protected:
	virtual void OnInitChilds();

	afx_msg void OnBnClickedPlan();
	afx_msg void OnBnClickedRestore();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTableFilter();
	afx_msg void OnBnClickedMore();

private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	CJQGridAPI* m_pJqGridAPI;

	CBRButton* m_btnPlan;
	CBRButton* m_btnModify;
	CBRButton* m_btnRestore;
	CBRButton* m_btnSearch;
	CBRButton* m_btnMore;
	CBSStatic* m_bsMoreWord;
	CBRButton m_btnTableFilter;
	CEdit* m_editSearch;
	CBSStatic* m_staticProductionStatus;
	CComboBox* m_comboProductionStatus;
	IHttp* m_pHttp;
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnNcDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

