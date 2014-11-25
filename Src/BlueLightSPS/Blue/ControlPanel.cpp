#include "stdafx.h"
#include "ControlPanel.h"

IMPLEMENT_DYNAMIC(CControlPanel, CBSObject)

CControlPanel::~CControlPanel()
{
}

BEGIN_MESSAGE_MAP(CControlPanel, CBSObject)
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


int CControlPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (CBSObject::OnCreate(lpCreateStruct) == -1)
		return -1;
	ShowWindow(SW_HIDE);
	OnInitChilds();
	//OnInitChilds();
	//PostMessage(UM_PANEL_CREATED);
	return 0;
}


BOOL CControlPanel::Create(CWnd* pParentWnd, UINT nID)
{

	return CBSObject::Create(NULL, NULL, WS_CLIPCHILDREN | WS_CHILDWINDOW, CRect(0, 0, 0, 0), pParentWnd, nID, NULL);
}



void CControlPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBSObject::OnShowWindow(bShow, nStatus);
	bShow ? OnWindowShow() : OnWindowHide();
	// TODO: Add your message handler code here
}
