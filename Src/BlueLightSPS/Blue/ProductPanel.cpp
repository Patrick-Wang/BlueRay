#include "stdafx.h"
#include "ProductPanel.h"


CProductPanel::CProductPanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI)
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
	CControlPanel::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		m_pJqGridAPI->ShowGrid();
	}
	else
	{
		m_pJqGridAPI->HideGrid();
	}
}
