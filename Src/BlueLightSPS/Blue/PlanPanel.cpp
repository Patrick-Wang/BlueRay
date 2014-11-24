#include "stdafx.h"
#include "PlanPanel.h"



CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI)
{

}


CPlanPanel::~CPlanPanel()
{
}


void CPlanPanel::OnWindowShow()
{
	//m_pJqGridAPI->ShowGrid(_T("plan"));
}

void CPlanPanel::OnWindowHide()
{
	//m_pJqGridAPI->HideGrid(_T("plan"));
}

void CPlanPanel::OnInitChilds()
{

}
