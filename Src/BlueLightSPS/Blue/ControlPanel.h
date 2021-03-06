#pragma once
#include "UILib/BSObject.h"



class CControlPanel : public CBSObject
{
	DECLARE_DYNAMIC(CControlPanel)
public:
	virtual ~CControlPanel();
	void ShowChild(CWnd* pChild);
	void HideChild(CWnd* pChild);
	
public:
	DECLARE_MESSAGE_MAP()
	virtual void OnUIPrepared(){};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitChilds() = 0;
public:
	virtual BOOL Create(CWnd* pParentWnd, UINT nID);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

