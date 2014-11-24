#pragma once
#include "ControlPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
class CSalePanel :
	public CControlPanel
{
public:
	CSalePanel(CJQGridAPI* pJqGridAPI);
	~CSalePanel();
	void OnGridDataLoaded();
	void OnRowChecked();
	void OnGridComplete();
protected:
	virtual void OnInitChilds();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedMore();
	virtual void OnWindowShow();
	virtual void OnWindowHide();
private:
	CBRButton m_btnAdd;
	CBRButton m_btnSearch;
	CBRButton m_btnModify;
	CBRButton m_btnDelete;
	CBRButton m_btnMore;
	CBSStatic m_bsMoreWord;
	CEdit* m_editSearch;
	DECLARE_MESSAGE_MAP()
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	CJQGridAPI* m_pJqGridAPI;

public:
	afx_msg void OnNcDestroy();
};

