#pragma once
#include "UILib/BSObject.h"

#define UM_UI_PREPARED	WM_APP + 11021

class CControlPanel : public CBSObject
{
	DECLARE_DYNAMIC(CControlPanel)
public:
	virtual ~CControlPanel();
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitChilds() = 0;
public:
	virtual BOOL Create(CWnd* pParentWnd, UINT nID);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

