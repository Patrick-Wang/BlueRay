#include "stdafx.h"
#include "ProductPanel.h"


CProductPanel::CProductPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: CBRPanel(pJqGridAPI, pHttp)
{

}

CProductPanel::~CProductPanel()
{
}

void CProductPanel::OnInitChilds()
{

}
BEGIN_MESSAGE_MAP(CProductPanel, CControlPanel)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


void CProductPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);
	/*if (bShow)
	{
	m_pJqGridAPI->ShowGrid();
	}
	else
	{
	m_pJqGridAPI->HideGrid();
	}*/
}

void CProductPanel::OnHttpSuccess(int id, LPCTSTR resp)
{

}

void CProductPanel::OnHttpFailed(int id)
{

}

void CProductPanel::OnRowChecked()
{

}
