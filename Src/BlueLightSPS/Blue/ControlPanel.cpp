#include "stdafx.h"
#include "ControlPanel.h"
#define TM_UI	50112
IMPLEMENT_DYNAMIC(CControlPanel, CBSObject)

CControlPanel::~CControlPanel()
{
}

BEGIN_MESSAGE_MAP(CControlPanel, CBSObject)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


int CControlPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (CBSObject::OnCreate(lpCreateStruct) == -1)
		return -1;
	OnInitChilds();
	ShowWindow(SW_HIDE);
	return 0;
}


BOOL CControlPanel::Create(CWnd* pParentWnd, UINT nID)
{
	return CBSObject::Create(NULL, NULL, WS_CLIPCHILDREN | WS_CHILDWINDOW, CRect(0, 0, 0, 0), pParentWnd, nID, NULL);
}


void CControlPanel::OnTimer(UINT_PTR nIDEvent)
{
	if (TM_UI == nIDEvent)
	{
		KillTimer(TM_UI);
		OnUIPrepared();// SendMessage(UM_UI_PREPARED);
	}

	CBSObject::OnTimer(nIDEvent);
}


void CControlPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBSObject::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		SetTimer(TM_UI, 10, NULL);
	}
	
}

void CControlPanel::ShowChild(CWnd* pChild)
{
	if (pChild != NULL)
	{
		pChild->ShowWindow(SW_SHOW);
	}
}

void CControlPanel::HideChild(CWnd* pChild)
{
	pChild->ShowWindow(SW_HIDE);
	CRect rt;
	pChild->GetClientRect(rt);
	pChild->ClientToScreen(rt);
	GetParent()->ScreenToClient(rt);
	GetParent()->InvalidateRect(rt);
}
