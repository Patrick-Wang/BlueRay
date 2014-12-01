#pragma once
#include "ControlPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
#include "IHttp.h"
#include "SaleAddDlg.h"
class CSalePanel :
	public CControlPanel
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
	virtual void OnInitChilds();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTableFilter();
	afx_msg void OnBnClickedMore();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void OnLoadDataSuccess(CString& data);
	void OnDelDataSuccess();
	void OnModifyDataSuccess(std::vector<CString>& newData);
	void OnAddDataSuccess(int id, std::vector<CString>& data);
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
	CJQGridAPI* m_pJqGridAPI;
	IHttp* m_pHttp;
	std::vector<CString> m_cacheRow;
public:
	afx_msg void OnNcDestroy();
};

