#pragma once
#include "ControlPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
class CPlanPanel :
	public CControlPanel
{
public:
	CPlanPanel(CJQGridAPI* pJqGridAPI);
	~CPlanPanel();

	void OnRowChecked();
	void OnGridComplete();

protected:
	virtual void OnInitChilds();
	virtual void OnWindowShow();
	virtual void OnWindowHide();

	afx_msg void OnBnClickedPlan();
	afx_msg void OnBnClickedRestore();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
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
	CEdit* m_editSearch;
	CBSStatic* m_staticProductionStatus;
	CComboBox* m_comboProductionStatus;

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnNcDestroy();
};

