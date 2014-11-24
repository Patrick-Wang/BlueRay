#pragma once
#include "BSObject.h"
class CControlPanel : public CBSObject
{
	DECLARE_DYNAMIC(CControlPanel)
public:
	virtual ~CControlPanel();
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitChilds() = 0;
	virtual void OnWindowShow(){};
	virtual void OnWindowHide(){};
public:
	virtual BOOL Create(CWnd* pParentWnd, UINT nID);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

