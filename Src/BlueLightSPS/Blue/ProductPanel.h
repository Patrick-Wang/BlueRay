#pragma once
#include "ControlPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
class CProductPanel :
	public CControlPanel
{
public:
	CProductPanel(CJQGridAPI* pJqGridAPI);
	~CProductPanel();
protected:
	virtual void OnInitChilds();
private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

