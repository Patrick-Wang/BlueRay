#include "stdafx.h"
#include "PlanPanel.h"
#include "resource_ids.h"
#include "Util.h"
#include "colors.h"

#define RIGHT_AREA_LEFT	150

BEGIN_MESSAGE_MAP(CPlanPanel, CControlPanel)
	ON_BN_CLICKED(IDC_PLAN_BTN_PLAN, &CPlanPanel::OnBnClickedPlan)
	ON_BN_CLICKED(IDC_PLAN_BTN_MODIFY, &CPlanPanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_PLAN_BTN_RESTORE, &CPlanPanel::OnBnClickedRestore)
	ON_BN_CLICKED(IDC_PLAN_BTN_SEARCH, &CPlanPanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_PLAN_BTN_MORE, &CPlanPanel::OnBnClickedMore)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI)
{

}


CPlanPanel::~CPlanPanel()
{
}


void CPlanPanel::OnWindowShow()
{
	m_pJqGridAPI->ShowGrid(_T("plan"));
}

void CPlanPanel::OnWindowHide()
{
	m_pJqGridAPI->HideGrid(_T("plan"));
}

void CPlanPanel::OnInitChilds()
{
	int delta = 277 - (RIGHT_AREA_LEFT + 15);
	m_editSearch = Util::CreateEdit(this, IDC_PLAN_BTN_SEARCH, _T(""), _T("Microsoft YaHei"), 12);
	m_editSearch->MoveWindow(235, 27, 240, 20);

	m_btnPlan.Create(this, IDC_PLAN_BTN_PLAN);
	m_btnPlan.SetWindowText(_T("计划"));
	m_btnPlan.SetBSFont(12);
	m_btnPlan.MoveWindow(20, 25, 90, 25);

	m_btnRestore.Create(this, IDC_PLAN_BTN_RESTORE);
	m_btnRestore.SetWindowText(_T("重置"));
	m_btnRestore.MoveWindow(125, 70, 90, 25);

	m_btnModify.Create(this, IDC_PLAN_BTN_MODIFY);
	m_btnModify.SetWindowText(_T("修改"));
	m_btnModify.MoveWindow(20, 70, 90, 25);

	m_btnSearch.Create(this, IDC_PLAN_BTN_SEARCH);
	m_btnSearch.SetWindowText(_T("查询"));
	m_btnSearch.MoveWindow(125, 25, 90, 25);

	m_btnMore.Create(this, IDC_PLAN_BTN_MORE);
	m_btnMore.SetWindowText(_T(">"));
	m_btnMore.MoveWindow(566, 25, 30, 25);

	m_bsMoreWord.Create(this, IDC_PLAN_BTN_MOREWORD);
	m_bsMoreWord.SetWindowText(_T("更多筛选"));
	m_bsMoreWord.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsMoreWord.MoveWindow(485, 27, 63, 20);

	m_btnRestore.EnableWindow(TRUE);
	m_btnModify.EnableWindow(FALSE);
}

void CPlanPanel::OnBnClickedPlan()
{

}

void CPlanPanel::OnBnClickedModify()
{

}

void CPlanPanel::OnBnClickedRestore()
{

}

void CPlanPanel::OnBnClickedSearch()
{

}


void CPlanPanel::OnBnClickedMore()
{

}

void CPlanPanel::OnNcDestroy()
{
	CControlPanel::OnNcDestroy();
}
