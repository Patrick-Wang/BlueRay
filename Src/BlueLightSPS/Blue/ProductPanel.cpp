#include "stdafx.h"
#include "ProductPanel.h"


CProductPanel::CProductPanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI)
{

}

CProductPanel::~CProductPanel()
{
}


void CProductPanel::OnWindowShow()
{
	m_pJqGridAPI->ShowGrid(_T("product"));
}

void CProductPanel::OnWindowHide()
{
	m_pJqGridAPI->HideGrid(_T("product"));
}

void CProductPanel::OnInitChilds()
{

}
