#pragma once
#include "BRPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
#include "IHttp.h"
#include "TableFilterDlg.h"
#include "SaleAddDlg.h"

class CSalePanel :
	public CBRPanel
{
public:
	CSalePanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	~CSalePanel();

	void OnRowChecked();
	void OnGridComplete();
	void OnHttpSuccess(int id, LPCTSTR resp);
	void OnHttpFailed(int id);
	void OnSaleDlgGetModifyOption(CSaleAddDlg& dlg);
protected:
	virtual void OnDataUpdate();
	virtual void OnInitChilds();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTableFilter();
	afx_msg void OnBnClickedMore();
	afx_msg void OnBnClickedApprove();	//test purpose
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void OnLoadDataSuccess();
	void OnDelDataSuccess();
	void OnModifyDataSuccess(std::vector<CString>& newData);
	void OnAddDataSuccess(int id, std::vector<CString>& data);
	void OnApproveDataSuccess();
private:
	CBRButton m_btnAdd;
	CBRButton m_btnSearch;
	CBRButton m_btnModify;
	CBRButton m_btnDelete;
	CBRButton m_btnMore;
	CBRButton m_btnTableFilter;
	CBSStatic m_bsMoreWord;
	CEdit* m_editSearch;
	DECLARE_MESSAGE_MAP()
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::vector<CString> m_cacheRow;
	CTableFilterDlg m_tableFilterDlg;

	//CBRButton m_btnApprove; //only for test purpose

public:
	afx_msg void OnNcDestroy();
};

