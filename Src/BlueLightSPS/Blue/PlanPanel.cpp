#include "stdafx.h"
#include "PlanPanel.h"
#include "resource_ids.h"
#include "Util.h"
#include "colors.h"

BEGIN_MESSAGE_MAP(CPlanPanel, CControlPanel)
	ON_BN_CLICKED(IDC_PLAN_BTN_PLAN, &CPlanPanel::OnBnClickedPlan)
	ON_BN_CLICKED(IDC_PLAN_BTN_MODIFY, &CPlanPanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_PLAN_BTN_RESTORE, &CPlanPanel::OnBnClickedRestore)
	ON_BN_CLICKED(IDC_PLAN_BTN_SEARCH, &CPlanPanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_PLAN_BTN_MORE, &CPlanPanel::OnBnClickedMore)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI),
		m_btnPlan(NULL),
		m_btnModify(NULL),
		m_btnRestore(NULL),
		m_btnSearch(NULL),
		m_btnMore(NULL),
		m_bsMoreWord(NULL),
		m_editSearch(NULL),
		m_staticProductionStatus(NULL),
		m_comboProductionStatus(NULL)
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
	m_staticProductionStatus = Util::CreateStatic(this, IDC_PLAN_STATIC_PROSTATUS, _T("根据订单状态筛选"), _T("Microsoft YaHei"), 12);
	m_staticProductionStatus->MoveWindow(20, 27, 120, 20);
	m_staticProductionStatus->SetTextAlign(DT_LEFT);

	m_comboProductionStatus = Util::CreateComboBox(this, IDC_PLAN_COMBO_PROSTATUS, _T("Microsoft YaHei"), 12);
	m_comboProductionStatus->MoveWindow(140, 25, 150, 20);

	m_comboProductionStatus->InsertString(0, _T("全部订单"));
	m_comboProductionStatus->InsertString(1, _T("可排产计划订单"));
	m_comboProductionStatus->InsertString(2, _T("排产计划中订单"));
	m_comboProductionStatus->InsertString(3, _T("已完成排产计划订单"));

	m_comboProductionStatus->SetCurSel(0);

	m_btnSearch = Util::CreateButton(this, IDC_PLAN_BTN_SEARCH, _T("查询"), _T("Microsoft YaHei"), 12);
	m_btnSearch->MoveWindow(340, 25, 90, 25);

	m_editSearch = Util::CreateEdit(this, IDC_PLAN_BTN_SEARCH, _T(""), _T("Microsoft YaHei"), 12);
	m_editSearch->MoveWindow(450, 27, 240, 20);

	m_bsMoreWord = Util::CreateStatic(this, IDC_PLAN_BTN_MOREWORD, _T("更多筛选"), _T("Microsoft YaHei"), 12);
	m_bsMoreWord->MoveWindow(700, 27, 63, 20);

	m_btnMore = Util::CreateButton(this, IDC_PLAN_BTN_MORE, _T(">"), _T("Microsoft YaHei"), 12);
	m_btnMore->MoveWindow(780, 25, 30, 25);

	m_btnPlan = Util::CreateButton(this, IDC_PLAN_BTN_PLAN, _T("计划"), _T("Microsoft YaHei"), 12);
	m_btnPlan->MoveWindow(20, 70, 90, 25);

	m_btnModify = Util::CreateButton(this, IDC_PLAN_BTN_MODIFY, _T("修改"), _T("Microsoft YaHei"), 12);
	m_btnModify->MoveWindow(135, 70, 90, 25);

	m_btnRestore = Util::CreateButton(this, IDC_PLAN_BTN_RESTORE, _T("重置"), _T("Microsoft YaHei"), 12);
	m_btnRestore->MoveWindow(250, 70, 90, 25);

	m_btnRestore->EnableWindow(FALSE);
	m_btnModify->EnableWindow(FALSE);
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
	if (NULL != m_btnPlan)
	{
		delete m_btnPlan;
	}

	if (NULL != m_btnModify)
	{
		delete m_btnModify;
	}

	if (NULL != m_btnRestore)
	{
		delete m_btnRestore;
	}

	if (NULL != m_btnSearch)
	{
		delete m_btnSearch;
	}

	if (NULL != m_btnMore)
	{
		delete m_btnMore;
	}

	if (NULL != m_bsMoreWord)
	{
		delete m_bsMoreWord;
	}

	if (NULL != m_staticProductionStatus)
	{
		delete m_staticProductionStatus;
	}

	if (NULL != m_comboProductionStatus)
	{
		delete m_comboProductionStatus;
	}

	CControlPanel::OnNcDestroy();
}
