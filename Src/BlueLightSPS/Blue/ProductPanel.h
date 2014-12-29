#pragma once
#include "BRPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
class CProductPanel :
	public CBRPanel
{
public:
	CProductPanel(CJQGridAPI* pJqGridAPI);
	~CProductPanel();
protected:
	virtual void OnInitChilds();
	virtual void OnHttpSuccess(int id, LPCTSTR resp);
	virtual void OnHttpFailed(int id) ;
	virtual void OnRowChecked();
private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

