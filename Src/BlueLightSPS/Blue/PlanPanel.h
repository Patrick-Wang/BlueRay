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
protected:
	virtual void OnInitChilds();
	virtual void OnWindowShow();
	virtual void OnWindowHide();
private:
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	CJQGridAPI* m_pJqGridAPI;
};

