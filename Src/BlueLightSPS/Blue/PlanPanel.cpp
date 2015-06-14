#include "stdafx.h"
#include "Server.h"
#include "PlanPanel.h"
#include "PlanAddDlg.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "CommonDefine.h"
#include "Util.h"
#include "colors.h"
#include "User.h"
#include "Plan.h"

#define QUERY_URL_ID IDP_PLAN + 1
#define ADD_URL_ID IDP_PLAN + 2
#define DEL_URL_ID IDP_PLAN + 3
#define MODIFY_URL_ID IDP_PLAN + 4
#define REAPPROVE_URL_ID IDP_PLAN + 5

static int g_ReApproveBtnPos[][4] = {
		{ 610 - 12, 124, 120, 25 },
		{ 470 - 12, 124, 120, 25 },
		{ 330 - 12, 124, 120, 25 },
		{ 190 - 12, 124, 120, 25 }
};

BEGIN_MESSAGE_MAP(CPlanPanel, CBRPanel)
	ON_BN_CLICKED(IDC_PLAN_BTN_PLAN, &CPlanPanel::OnBnClickedPlan)
	ON_BN_CLICKED(IDC_PLAN_BTN_MODIFY, &CPlanPanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_PLAN_BTN_RESTORE, &CPlanPanel::OnBnClickedRestore)
	ON_BN_CLICKED(IDC_PLAN_BTN_SEARCH, &CPlanPanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_PLAN_BTN_MORE, &CPlanPanel::OnBnClickedMore)
	ON_BN_CLICKED(IDC_PLAN_BTN_TABLEFILTER, &CPlanPanel::OnBnClickedTableFilter)
	ON_BN_CLICKED(IDC_PLAN_BTN_REAPPROVEBZRQBUSINESS, &CPlanPanel::OnBnClickedReApproveBZRQBusiness)
	ON_BN_CLICKED(IDC_PLAN_BTN_REAPPROVEBZRQPLAN, &CPlanPanel::OnBnClickedReApproveBZRQPlan)
	ON_BN_CLICKED(IDC_PLAN_BTN_REAPPROVESCRQBUSINESS, &CPlanPanel::OnBnClickedReApproveSCRQBusiness)
	ON_BN_CLICKED(IDC_PLAN_BTN_REAPPROVESCRQPLAN, &CPlanPanel::OnBnClickedReApproveSCRQPlan)
	ON_WM_NCDESTROY()
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_PLAN_COMBO_PROSTATUS, &CPlanPanel::OnCbnSelchangeProductionStatus)
END_MESSAGE_MAP()



class CPlanSearchListener : public CPromise<PageData_t>::IHttpResponse{
	CONSTRUCTOR_3(CPlanSearchListener, CPlanPanel&, panel, table&, tb, CJQGridAPI*, pJqGridAPI)
public:
	virtual void OnSuccess(PageData_t& tb){
		m_pJqGridAPI->Refresh(tb.rawData);
		m_tb = tb.rows;
		if (m_tb.empty())
		{
			m_panel.MessageBox(_T("没有符合条件的记录"), _T("查询结果"), MB_OK | MB_ICONWARNING);
		}
		m_panel.HighLight();
		m_panel.GetParent()->EnableWindow(TRUE);
//		m_pJqGridAPI->UncheckedAll();
		m_panel.OnRowChecked();
	}
	virtual void OnFailed(){
		m_panel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		m_panel.GetParent()->EnableWindow(TRUE);
	}
};


class OnPlanLoadDataListener : public CPromise<PageData_t>::IHttpResponse
{
	CONSTRUCTOR_3(OnPlanLoadDataListener, CPlanPanel&, panel, table&, tb, CJQGridAPI*, pJqGridAPI)
public:
	virtual void OnSuccess(PageData_t& tb){
		//IntArray ia;
		//m_pJqGridAPI->GetCheckedRows(ia);
		//CString strFmt;
		//strFmt.Format(L"%d", ia.size());
		//m_panel.MessageBox(strFmt, strFmt);
		m_pJqGridAPI->Refresh(tb.rawData);
		m_tb = tb.rows;
		m_panel.HighLight();
		m_panel.GetParent()->EnableWindow(TRUE);
//		m_pJqGridAPI->UncheckedAll();
		m_panel.OnRowChecked();
		//m_pJqGridAPI->GetCheckedRows(ia);
		//strFmt.Format(L"%d", ia.size());
		//m_panel.MessageBox(strFmt, strFmt);
	}
	virtual void OnFailed(){
		m_panel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		m_panel.GetParent()->EnableWindow(TRUE);
	}
};

//CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI)
	: CBRPanel(pJqGridAPI)
	, m_btnPlan(NULL)
	, m_btnModify(NULL)
	, m_btnRestore(NULL)
	, m_btnSearch(NULL)
	, m_btnMore(NULL)
	, m_bsMoreWord(NULL)
	, m_editSearch(NULL)
	, m_staticProductionStatus(NULL)
	, m_comboProductionStatus(NULL)
	, m_btnTableFilter(NULL)
	, m_btnReApproveBZRQBusiness(NULL)
	, m_btnReApproveBZRQPlan(NULL)
	, m_btnReApproveSCRQBusiness(NULL)
	, m_btnReApproveSCRQPlan(NULL)
	, m_tableFilterDlg(_T("表格设置"))
	, m_iCountBtnOfReApprove(-1)
	, m_bsDateRange(NULL)
	, m_bsMiddleLine(NULL)
	, m_dtcSearchFrom(NULL)
	, m_dtcSearchTo(NULL)
	, m_bEnablePlanBtnForSCRQ(false)
	, m_bEnablePlanBtnForBZRQ(false)
	, m_bIfUpdateTableWhenTableFilter(false)
{
	m_tableFilterDlg.Initialize(m_pJqGridAPI.get(), Page_Plan);
}


CPlanPanel::~CPlanPanel()
{
}

void CPlanPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	if (!bShow)
	{
		m_btnPlan->EnableWindow(FALSE);
		m_btnRestore->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
		m_btnReApproveSCRQPlan->EnableWindow(FALSE);
		m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
		m_btnReApproveBZRQPlan->EnableWindow(FALSE);
	}
	else
	{
		m_pJqGridAPI->HideCol(nsPlan::Column_en::yxj);
		m_pJqGridAPI->HideCol(nsPlan::Column_en::dfr);
	}

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getPlan())
	{
		m_pJqGridAPI->HideGrid();
	}
}

void CPlanPanel::OnCbnSelchangeProductionStatus()
{
	DEFINE_PLAN_QUERY_PARAM(sqp);
	MakeBasicSearchCondition(sqp);
	//sqp.AddSortCondition(15, false);

	CServer::GetInstance()->GetPlan().Query(
		1,
		//m_pJqGridAPI->GetCurrentPage(),
		m_pJqGridAPI->GetPageSize(),
		sqp)
		.then(new OnPlanLoadDataListener(*this, m_table, m_pJqGridAPI.get()));

	GetParent()->EnableWindow(FALSE);
}

void CPlanPanel::FilterTableByStatus(enumProductionStatusForPlan productionStatus, CJsonQueryParam &sqp, CUnitedQuery* pUq)
{
	if (ProductionStatus_All == productionStatus)
	{

	}
	else if (ProductionStatus_SCRQ_ToBePlanned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::scrq, L"@==null");
		}
		else{
			pUq->and(UQ(nsPlan::scrq, L"@==null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
	}
	else if (ProductionStatus_SCRQ_ToBeApproved == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::scrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::scrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
	}
	else if (ProductionStatus_SCRQ_Planning == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::scrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::scrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, true);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 1);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 1);
	}
	else if (ProductionStatus_SCRQ_Planned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::scrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::scrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, true);
	}
	else if (ProductionStatus_BZRQ_ToBePlanned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::bzrq, L"@==null");
		}
		else{
			pUq->and(UQ(nsPlan::bzrq, L"@==null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, false);
	}
	else if (ProductionStatus_BZRQ_ToBeApproved == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::bzrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);


		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, false);
	}
	else if (ProductionStatus_BZRQ_Planning == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::bzrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, false);

		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 1);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 1);
	}
	else if (ProductionStatus_BZRQ_Planned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::bzrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, true);
	}
	else if (ProductionStatus_FHRQ_Planned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::fhrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::fhrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

	}
	else if (ProductionStatus_FHRQ_ToBePlanned == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::fhrq, L"@==null");
		}
		else{
			pUq->and(UQ(nsPlan::fhrq, L"@==null"));
		}
		sqp.SetUnitedQuery(*pUq);
	}
	else if (ProductionStatus_All_PlannedAndApproved == productionStatus)
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::fhrq, L"@!=null");
		}
		else{
			pUq->and(UQ(nsPlan::fhrq, L"@!=null"));
		}
		sqp.SetUnitedQuery(*pUq);

		sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true);
		sqp.AddApproveCondition(CPlan::PLAN_PLAN, true);
		sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true);
		sqp.AddApproveCondition(CPlan::PACK_PLAN, true);
	}

	//if (ProductionStatus_Planning == productionStatus)
	//{
	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 1);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 1);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 1);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 1);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 2);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 2);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 2);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 2);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 3);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 3);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 3);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 3);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 4);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 4);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 4);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 4);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 5);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 5);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 5);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 5);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, true, 6);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 6);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 6);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 6);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 7);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 7);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 7);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 7);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 8);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 8);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 8);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 8);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 9);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 9);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 9);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 9);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 10);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 10);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 10);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, false, 10);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 11);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, false, 11);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 11);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 11);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 12);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 12);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, true, 12);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 12);

	//	sqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false, 13);
	//	sqp.AddApproveCondition(CPlan::PLAN_PLAN, true, 13);
	//	sqp.AddApproveCondition(CPlan::PACK_BUSINESS, false, 13);
	//	sqp.AddApproveCondition(CPlan::PACK_PLAN, true, 13);
	//}
}

void CPlanPanel::OnInitChilds()
{
	CString bh;
	CServer::GetInstance()->GetPlan().GetCcbhSync(bh);
	CServer::GetInstance()->GetPlan().GetTcbhSync(bh);

	m_pJqGridAPI->d_OnExportClicked += std::make_pair(this, &CPlanPanel::OnExportClicked);
	m_pJqGridAPI->d_OnTemplateExportClicked += std::make_pair(this, &CPlanPanel::OnTemplateExportClicked);

	CString strJsonWidths;
	if (CSettingManager::GetInstance()->GetColWidths(L"planCol", strJsonWidths))
	{
		m_pJqGridAPI->SetWidths(strJsonWidths);
	}
	m_pJqGridAPI->d_OnUpdateData += std::make_pair(this, &CPlanPanel::OnUpdateData);
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getPlan())
	{
		m_staticProductionStatus = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_PROSTATUS, _T("您没有计划的权限"), _T("Microsoft YaHei"), 16);
		m_staticProductionStatus->MoveWindow(20, 27, 500, 20);
		m_staticProductionStatus->SetTextAlign(DT_LEFT);
		m_pJqGridAPI->HideGrid();
	}
	else
	{
		//first line
		m_comboProductionStatus = Util_Tools::Util::CreateComboBox(this, IDC_PLAN_COMBO_PROSTATUS, _T("Microsoft YaHei"), 12, TRUE);
		m_comboProductionStatus->MoveWindow(20, /*23*/10, 200, 18);

		m_comboProductionStatus->InsertString(0, _T("全部"));
		m_comboProductionStatus->InsertString(1, _T("生产日期未计划"));
		m_comboProductionStatus->InsertString(2, _T("生产日期已计划未审核"));
		m_comboProductionStatus->InsertString(3, _T("生产日期已计划审核中"));
		m_comboProductionStatus->InsertString(4, _T("生产日期已审核"));
		m_comboProductionStatus->InsertString(5, _T("包装日期未计划"));
		m_comboProductionStatus->InsertString(6, _T("包装日期已计划未审核"));
		m_comboProductionStatus->InsertString(7, _T("包装日期已计划审核中"));
		m_comboProductionStatus->InsertString(8, _T("包装日期已审核"));
		m_comboProductionStatus->InsertString(9, _T("发货日期已计划"));
		m_comboProductionStatus->InsertString(10, _T("发货日期未计划"));
		m_comboProductionStatus->InsertString(11, _T("全部已审核已计划"));
		m_comboProductionStatus->SetCurSel(0);

		m_editSearch = Util_Tools::Util::CreateEdit(this, IDC_PLAN_BTN_SEARCH, _T("请输入关键字"), _T("Microsoft YaHei"), 12);
		m_editSearch->MoveWindow(485 - 220, 12, 227, 20);

		m_btnMore = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_MORE, _T("更多筛选"), _T("Microsoft YaHei"), 12);
		m_btnMore->MoveWindow(640 - 123, 10, 90, 25);

		m_btnSearch = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_SEARCH, _T("查询"), _T("Microsoft YaHei"), 12);
		m_btnSearch->MoveWindow(750 - 123, 10, 90, 25);

		m_btnTableFilter = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_TABLEFILTER, _T("表格设置"), _T("Microsoft YaHei"), 12);
		m_btnTableFilter->MoveWindow(750, 10, 90, 25);

		//生产日期
		COleDateTime oletimeTime;

		oletimeTime.SetStatus(COleDateTime::null);

		m_bsSCRQDateRange = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_DATERANGE_SCRQ, _T("生产日期"), _T("Microsoft YaHei"), 12);
		m_bsSCRQDateRange->MoveWindow(20, 52, 60, 20);

		m_dtcSCRQSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHFROM_SCRQ, _T("Microsoft YaHei"), 12);
		m_dtcSCRQSearchFrom->MoveWindow(80, 52, 108, 20);

		m_dtcSCRQSearchFrom->SetTime(oletimeTime);

		m_bsSCRQMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_MIDDLELINE_SCRQ, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsSCRQMiddleLine->MoveWindow(195, 52, 20, 20);

		m_dtcSCRQSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHTO_SCRQ, _T("Microsoft YaHei"), 12);
		m_dtcSCRQSearchTo->MoveWindow(220, /*70*/52, 108, 20);
		m_dtcSCRQSearchTo->SetTime(oletimeTime);

		//包装日期
		m_bsBZRQDateRange = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_DATERANGE_BZRQ, _T("包装日期"), _T("Microsoft YaHei"), 12);
		m_bsBZRQDateRange->MoveWindow(350 + 60, 52, 60, 20);

		m_dtcBZRQSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHFROM_BZRQ, _T("Microsoft YaHei"), 12);
		m_dtcBZRQSearchFrom->MoveWindow(410 + 60, 52, 108, 20);

		m_dtcBZRQSearchFrom->SetTime(oletimeTime);

		m_bsBZRQMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_MIDDLELINE_BZRQ, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsBZRQMiddleLine->MoveWindow(525 + 60, 52, 20, 20);

		m_dtcBZRQSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHTO_BZRQ, _T("Microsoft YaHei"), 12);
		m_dtcBZRQSearchTo->MoveWindow(550 + 60, 52, 108, 20);
		m_dtcBZRQSearchTo->SetTime(oletimeTime);

		//发货日期
		m_bsFHRQDateRange = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_DATERANGE_FHRQ, _T("发货日期"), _T("Microsoft YaHei"), 12);
		m_bsFHRQDateRange->MoveWindow(20, 88, 60, 20);

		m_dtcFHRQSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHFROM_FHRQ, _T("Microsoft YaHei"), 12);
		m_dtcFHRQSearchFrom->MoveWindow(80, 88, 108, 20);

		m_dtcFHRQSearchFrom->SetTime(oletimeTime);

		m_bsFHRQMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_MIDDLELINE_FHRQ, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsFHRQMiddleLine->MoveWindow(195, 88, 20, 20);

		m_dtcFHRQSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHTO_FHRQ, _T("Microsoft YaHei"), 12);
		m_dtcFHRQSearchTo->MoveWindow(220, /*70*/88, 108, 20);
		m_dtcFHRQSearchTo->SetTime(oletimeTime);

		//订单日期
		m_bsDateRange = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_DATERANGE, _T("订单日期"), _T("Microsoft YaHei"), 12);
		m_bsDateRange->MoveWindow(350 + 60, 88, 60, 20);

		m_dtcSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHFROM, _T("Microsoft YaHei"), 12);
		m_dtcSearchFrom->MoveWindow(410 + 60, 88, 108, 20);
		m_dtcSearchFrom->SetTime(oletimeTime);

		m_bsMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_MIDDLELINE, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsMiddleLine->MoveWindow(525 + 60, 88, 20, 20);

		m_dtcSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_PLAN_DATETIME_SEARCHTO, _T("Microsoft YaHei"), 12);
		m_dtcSearchTo->MoveWindow(550 + 60, 88, 108, 20);
		m_dtcSearchTo->SetTime(oletimeTime);

		//forth line
		m_btnPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_PLAN, _T("计划"), _T("Microsoft YaHei"), 12);
		m_btnPlan->MoveWindow(20, 124, 90, 25);

		//no display//////////////////////////////////////////////////////////////
		m_btnModify = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_MODIFY, _T("修改"), _T("Microsoft YaHei"), 12);
		m_btnModify->MoveWindow(130, 124, 90, 255);

		m_btnRestore = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_RESTORE, _T("重置"), _T("Microsoft YaHei"), 12);
		m_btnRestore->MoveWindow(240, 124, 90, 25);
		//////////////////////////////////////////////////////////////////////////

		m_btnReApproveSCRQBusiness = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVESCRQBUSINESS, _T("反审核-生产业务"), _T("Microsoft YaHei"), 12);
		m_btnReApproveSCRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVESCRQPLAN, _T("反审核-生产计划"), _T("Microsoft YaHei"), 12);
		m_btnReApproveBZRQBusiness = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQBUSINESS, _T("反审核-包装业务"), _T("Microsoft YaHei"), 12);
		m_btnReApproveBZRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQPLAN, _T("反审核-包装计划"), _T("Microsoft YaHei"), 12);
		ShowReApproveBtns();

		m_btnPlan->EnableWindow(FALSE);
		m_btnRestore->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnModify->ShowWindow(FALSE);
		m_btnRestore->ShowWindow(FALSE);

		m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
		m_btnReApproveSCRQPlan->EnableWindow(FALSE);
		m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
		m_btnReApproveBZRQPlan->EnableWindow(FALSE);

	}
}

void CPlanPanel::OnBnClickedPlan()
{
	std::auto_ptr<CPlanAddDlg::Option_t> pstOpt;
	CPlanAddDlg dlg(_T("排产计划"));
	dlg.ConfigPlanBtns(m_bEnablePlanBtnForSCRQ, m_bEnablePlanBtnForBZRQ);

	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		pRowData = NULL;
		for (int j = 0; j < m_table.size(); ++j)
		{
			if (m_table[j].first == checkedRows[i])
			{
				pRowData = &(m_table[j].second);
				break;
			}
		}

		if (NULL != pRowData)
		{
			if (pstOpt.get() == NULL)
			{
				pstOpt.reset(new CPlanAddDlg::Option_t(*pRowData));
			}
			else
			{
				pstOpt->Merge(*pRowData);
			}
		}
	}

	dlg.SetOption(pstOpt.get());

	if (checkedRows.size() > 1)
	{
		dlg.DisableBHEdits(FALSE, FALSE);
	}
	else
	{
		dlg.DisableBHEdits((/*_T("N") == pstOpt->jhywsh && */_T("N") == pstOpt->jhjhsh),
			(/*_T("N") == pstOpt->bzywsh &&*/ _T("N") == pstOpt->bzjhsh));
	}

	if (IDOK == dlg.DoModal())
	{
		m_cacheRow = dlg.GetResult();

		class OnPlanUpdateListener : public CPromise<bool>::IHttpResponse{
			CONSTRUCTOR_2(OnPlanUpdateListener, std::vector<CString>&, cacheRow, CPlanPanel&, planPanel)
		public:
			void OnSuccess(bool& bRet)
			{
				if (bRet)
				{
					(m_planPanel.CPlanPanel::OnModifyDataSuccess)(m_cacheRow);
					m_planPanel.OnUpdateData(m_planPanel.m_pJqGridAPI->GetCurrentPage(), m_planPanel.m_pJqGridAPI->GetGridPageSize(), m_planPanel.m_iCurSortCol, m_planPanel.m_bCurSortAsc);
				}
				m_planPanel.GetParent()->EnableWindow(TRUE);
			}
			void OnFailed()
			{
				m_planPanel.MessageBox(_T("修改数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_planPanel.GetParent()->EnableWindow(TRUE);
			}
		};

		CServer::GetInstance()->GetPlan().Update(checkedRows, m_cacheRow)
			.then(new OnPlanUpdateListener(m_cacheRow, *this));

		GetParent()->EnableWindow(FALSE);
	}
}

void CPlanPanel::OnBnClickedTableFilter()
{
	m_bIfUpdateTableWhenTableFilter = true;

	if (IDOK == m_tableFilterDlg.DoModal()){
	}

	m_bIfUpdateTableWhenTableFilter = false;
}

void CPlanPanel::OnBnClickedModify()
{
	//dropped
}

void CPlanPanel::OnBnClickedRestore()
{
	//dropped
}

void CPlanPanel::MakeBasicSearchCondition(CJsonQueryParam &sqp)
{
	int iCountShot = 0;
	CString searchText;
	m_editSearch->GetWindowText(searchText);

	if (!searchText.IsEmpty()){
		sqp.SetBasicSearchCondition(searchText, false);
	}

	CString strFrom;
	CString strTo;
	bool bHasFrom = false;
	bool bHasTo = false;
	CTime time;

	//订单日期
	DWORD dwResult = m_dtcSearchFrom->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasFrom = true;
		m_dtcSearchFrom->GetWindowText(strFrom);
	}
	else
	{
		bHasFrom = false;
		//m_dtcSearchFrom->GetWindowText(strFrom);
	}

	dwResult = m_dtcSearchTo->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasTo = true;
		m_dtcSearchTo->GetWindowText(strTo);
	}
	else
	{
		bHasTo = false;
		//m_dtcSearchTo->GetWindowText(strTo);
	}

	if (bHasFrom || bHasTo)
	{
		sqp.SetDateSearchCondition(strFrom, strTo);
	}

	//生产日期
	CString strSCRQondition;
	CString strSCRQFrom;
	CString strSCRQTo;
	dwResult = m_dtcSCRQSearchFrom->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasFrom = true;
		m_dtcSCRQSearchFrom->GetWindowText(strSCRQFrom);
	}
	else
	{
		bHasFrom = false;
		//m_dtcSCRQSearchFrom->GetWindowText(strSCRQFrom);
	}

	dwResult = m_dtcSCRQSearchTo->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasTo = true;
		m_dtcSCRQSearchTo->GetWindowText(strSCRQTo);
	}
	else
	{
		bHasTo = false;
		//m_dtcSCRQSearchTo->GetWindowText(strTo);
	}
	
	Util_Tools::Util::MakeDateQueryCommand(bHasFrom, bHasTo, strSCRQFrom, strSCRQTo, strSCRQondition);

	//if (bHasFrom || bHasTo)
	//{
	//	strSCRQondition.Format(_T("@between %s and %s"), strFrom, strTo);
	//}
	//else
	//{
	//	strSCRQondition = _T("@between 1990-01-01 and 2090-01-01");
	//}

	//包装日期
	CString strBZRQondition;
	CString strBZRQFrom;
	CString strBZRQTo;
	dwResult = m_dtcBZRQSearchFrom->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasFrom = true;
		m_dtcBZRQSearchFrom->GetWindowText(strBZRQFrom);
	}
	else
	{
		bHasFrom = false;
		//m_dtcBZRQSearchFrom->GetWindowText(strBZRQFrom);
	}

	dwResult = m_dtcBZRQSearchTo->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasTo = true;
		m_dtcBZRQSearchTo->GetWindowText(strBZRQTo);
	}
	else
	{
		bHasTo = false;
		//m_dtcBZRQSearchTo->GetWindowText(strTo);
	}

	//if (bHasFrom || bHasTo)
	//{
	//	strBZRQondition.Format(_T("@between %s and %s"), strFrom, strTo);
	//}
	//else
	//{
	//	strBZRQondition = _T("@between 1990-01-01 and 2090-01-01");
	//}
	Util_Tools::Util::MakeDateQueryCommand(bHasFrom, bHasTo, strBZRQFrom, strBZRQTo, strBZRQondition);

	//发货日期
	CString strFHRQondition;
	CString strFHRQFrom;
	CString strFHRQTo;
	dwResult = m_dtcFHRQSearchFrom->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasFrom = true;
		m_dtcFHRQSearchFrom->GetWindowText(strFHRQFrom);
	}
	else
	{
		bHasFrom = false;
		//m_dtcFHRQSearchFrom->GetWindowText(strFrom);
	}

	dwResult = m_dtcFHRQSearchTo->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasTo = true;
		m_dtcFHRQSearchTo->GetWindowText(strFHRQTo);
	}
	else
	{
		bHasTo = false;
		//m_dtcFHRQSearchTo->GetWindowText(strTo);
	}

	//if (bHasFrom || bHasTo)
	//{
	//	strFHRQondition.Format(_T("@between %s and %s"), strFrom, strTo);
	//}
	//else
	//{
	//	strFHRQondition = _T("@between 1990-01-01 and 2090-01-01");
	//}
	Util_Tools::Util::MakeDateQueryCommand(bHasFrom, bHasTo, strFHRQFrom, strFHRQTo, strFHRQondition);
	CUnitedQuery* pUq = NULL;
	if (!strSCRQondition.IsEmpty())
	{
		pUq = &UQ(nsPlan::scrq, strSCRQondition);
	}

	if (!strBZRQondition.IsEmpty())
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::bzrq, strBZRQondition);
		}
		else
		{
			pUq->and(UQ(nsPlan::bzrq, strBZRQondition));
		}
	}

	if (!strFHRQondition.IsEmpty())
	{
		if (NULL == pUq)
		{
			pUq = &UQ(nsPlan::fhrq, strFHRQondition);
		}
		else
		{
			pUq->and(UQ(nsPlan::fhrq, strFHRQondition));
		}
	}

	//CUnitedQuery& uq = UQ(nsPlan::scrq, strSCRQondition).and(UQ(nsPlan::bzrq, strBZRQondition).and(UQ(nsPlan::fhrq, strFHRQondition)));
	if (NULL != pUq)
	{
		sqp.SetUnitedQuery(*pUq);
	}

	FilterTableByStatus(enumProductionStatusForPlan(m_comboProductionStatus->GetCurSel()), sqp, pUq);

	//if (0 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_All, sqp);
	//}
	//else if (1 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_SCRQ_ToBePlanned, sqp);
	//}
	//else if (2 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_SCRQ_ToBeApproved, sqp);
	//}
	//else if (3 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_SCRQ_Planning, sqp);
	//}
	//else if (4 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_SCRQ_Planned, sqp);
	//}
	//else if (5 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_BZRQ_ToBePlanned, sqp);
	//}
	//else if (6 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_BZRQ_ToBeApproved, sqp);
	//}
	//else if (7 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_BZRQ_Planning, sqp);
	//}
	//else if (8 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_BZRQ_Planned, sqp);
	//}
	//else if (9 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_FHRQ_Planned, sqp);
	//}
	//else if (10 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_FHRQ_ToBePlanned, sqp);
	//}
	//else if (11 == iIndex)
	//{
	//	FilterTableByStatus(ProductionStatus_All_PlannedAndApproved, sqp);
	//}

	sqp.SetAdvancedCondition(&m_advanceSearchVals);

}

void CPlanPanel::OnBnClickedSearch()
{
	//m_advanceSearchVals.clear(); //必须在MakeBasicSearchCondition之前调用
	DEFINE_PLAN_QUERY_PARAM(sqp);
	MakeBasicSearchCondition(sqp);
	m_iCurSortCol = -1;
	m_bCurSortAsc = false;
	m_pJqGridAPI->CancelSort();
	CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), sqp)
		.then(new CPlanSearchListener(*this, m_table, m_pJqGridAPI.get()));
	GetParent()->EnableWindow(FALSE);
}

void CPlanPanel::HighLight()
{
	//for (size_t i = 0, len = m_table.size(); i < len; i++)
	//{
	//	if (0 == m_table[i].second[nsPlan::yxj].Compare(L"高"))
	//	{
	//		m_pJqGridAPI->HighLightRow(m_table[i].first);
	//	}
	//}
}

void CPlanPanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("高级搜索"));

	dlg.SetIfUseDefaultValue(false);

	//dlg.SetOption(new CSaleAddDlg::Option_t());

	if (m_advanceSearchVals.size() <= 0)
	{
		dlg.SetOption(new CSaleAddDlg::Option_t());
	}
	else
	{
		dlg.SetOption(new CSaleAddDlg::Option_t(m_advanceSearchVals));
	}

	if (IDOK == dlg.DoModal()){
		m_advanceSearchVals = const_cast<std::vector<CString>&>(dlg.GetResult());
		m_advanceSearchVals.insert(m_advanceSearchVals.begin() + nsPlan::cg, L"");
// 		searchVals.insert(searchVals.begin() + 16, L"");//插入生产日期
// 		searchVals.insert(searchVals.begin() + 17, L"");//插入生产日期业务审核
// 		searchVals.insert(searchVals.begin() + 18, L"");//插入生产日期计划审核
// 		searchVals.insert(searchVals.begin() + 19, L"");//插入包装日期
// 		searchVals.insert(searchVals.begin() + 20, L"");//插入包装日期业务审核
// 		searchVals.insert(searchVals.begin() + 21, L"");//插入包装日期计划审核
// 		searchVals.insert(searchVals.begin() + 22, L"");//插入发货日期
// 		searchVals.insert(searchVals.begin() + 23, L"");//插入生产编码
// 		searchVals.insert(searchVals.begin() + 24, L"");//插入出厂编码
// 		searchVals.insert(searchVals.begin() + 25, L"");//插入优先级

		DEFINE_PLAN_QUERY_PARAM(jqp);

		MakeBasicSearchCondition(jqp);
		m_iCurSortCol = -1;
		m_bCurSortAsc = false;
		m_pJqGridAPI->CancelSort();
		CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp)
			.then(new CPlanSearchListener(*this, m_table, m_pJqGridAPI.get()));
		GetParent()->EnableWindow(FALSE);
	}
}

void CPlanPanel::OnBnClickedReApproveBZRQBusiness()
{
	class OnReApproveBZRQBusinessListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveBZRQBusinessListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(StringArray& strRet){

				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PACK_BUSINESS);
	
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CPlan& plan = CServer::GetInstance()->GetPlan();
			plan.Unapprove(CPlan::PACK_BUSINESS, checkedRows).then(new OnReApproveBZRQBusinessListener(*this));
			GetParent()->EnableWindow(FALSE);
		}
	}
}

void CPlanPanel::OnBnClickedReApproveBZRQPlan()
{
	class OnReApproveBZRQPlanListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveBZRQPlanListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(StringArray& strRet){
	
				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PACK_PLAN);
			
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CPlan& plan = CServer::GetInstance()->GetPlan();
			plan.Unapprove(CPlan::PACK_PLAN, checkedRows).then(new OnReApproveBZRQPlanListener(*this));
			GetParent()->EnableWindow(FALSE);
		}
	}
}

void CPlanPanel::OnBnClickedReApproveSCRQBusiness()
{
	class OnReApproveSCRQBusinessListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveSCRQBusinessListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(StringArray& strRet){

			m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
			(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PLAN_BUSINESS);

			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CPlan& plan = CServer::GetInstance()->GetPlan();
			plan.Unapprove(CPlan::PLAN_BUSINESS, checkedRows).then(new OnReApproveSCRQBusinessListener(*this));
			GetParent()->EnableWindow(FALSE);
		}
	}
}

void CPlanPanel::OnBnClickedReApproveSCRQPlan()
{
	class OnReApproveSCRQPlanListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveSCRQPlanListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(StringArray& strRet){

			m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
			(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PLAN_PLAN);

			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CPlan& plan = CServer::GetInstance()->GetPlan();
			plan.Unapprove(CPlan::PLAN_PLAN, checkedRows).then(new OnReApproveSCRQPlanListener(*this));
			GetParent()->EnableWindow(FALSE);
		}
	}
}

void CPlanPanel::OnReApproveSuccess(CPlan::ApproveType type)
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	std::vector<int> checkedRowTableMap;
	checkedRowTableMap.resize(checkedRows.size(), -1);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < m_table.size(); ++j)
		{
			if (m_table[j].first == checkedRows[i])
			{
				checkedRowTableMap[i] = j;
				break;
			}
		}
	}

	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		if (checkedRowTableMap[i] >= 0)
		{
			if (CPlan::ApproveType::PLAN_BUSINESS == type)
			{
				m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::jhshyw] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::jhshyw + 1, IDS_COMMON_NO);

				//if (m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::jhshjh] == IDS_COMMON_NO)
				//{
				//	//如果生产日期的业务和计划都被反审核，设置生产日期为空
				//	m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::scrq] = _T("");
				//	m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::scrq + 1, _T(""));
				//}

				m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PLAN_PLAN == type)
			{
				m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::jhshjh] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::jhshjh + 1, IDS_COMMON_NO);

				//if (m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::jhshyw] == IDS_COMMON_NO)
				//{
				//	m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::scrq] = _T("");
				//	m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::scrq + 1, _T(""));
				//}

				m_btnReApproveSCRQPlan->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PACK_BUSINESS == type)
			{
				m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzshyw] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::bzshyw + 1, IDS_COMMON_NO);

				//if (m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzshjh] == IDS_COMMON_NO)
				//{
				//	m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzrq] = _T("");
				//	m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::bzrq + 1, _T(""));
				//}

				m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PACK_PLAN == type)
			{
				m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzshjh] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::bzshjh + 1, IDS_COMMON_NO);

				//if (m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzshyw] == IDS_COMMON_NO)
				//{
				//	m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzrq] = _T("");
				//	m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::bzrq + 1, _T(""));
				//}

				m_btnReApproveBZRQPlan->EnableWindow(FALSE);
			}
		}
	}
	OnRowChecked();
}

void CPlanPanel::OnNcDestroy()
{
	if (NULL != m_btnPlan)
	{
		delete m_btnPlan;
		m_btnPlan = NULL;
	}

	if (NULL != m_btnModify)
	{
		delete m_btnModify;
		m_btnModify = NULL;
	}

	if (NULL != m_btnRestore)
	{
		delete m_btnRestore;
		m_btnRestore = NULL;
	}

	if (NULL != m_btnSearch)
	{
		delete m_btnSearch;
		m_btnSearch = NULL;
	}

	if (NULL != m_btnMore)
	{
		delete m_btnMore;
		m_btnMore = NULL;
	}

	if (NULL != m_bsMoreWord)
	{
		delete m_bsMoreWord;
		m_bsMoreWord = NULL;
	}

	if (NULL != m_editSearch)
	{
		delete m_editSearch;
		m_editSearch = NULL;
	}

	if (NULL != m_staticProductionStatus)
	{
		delete m_staticProductionStatus;
		m_staticProductionStatus = NULL;
	}

	if (NULL != m_comboProductionStatus)
	{
		delete m_comboProductionStatus;
		m_comboProductionStatus = NULL;
	}

	if (NULL != m_btnTableFilter)
	{
		delete m_btnTableFilter;
		m_btnTableFilter = NULL;
	}

	if (NULL != m_btnReApproveBZRQBusiness)
	{
		delete m_btnReApproveBZRQBusiness;
		m_btnReApproveBZRQBusiness = NULL;
	}

	if (NULL != m_btnReApproveBZRQPlan)
	{
		delete m_btnReApproveBZRQPlan;
		m_btnReApproveBZRQPlan = NULL;
	}

	if (NULL != m_btnReApproveSCRQBusiness)
	{
		delete m_btnReApproveSCRQBusiness;
		m_btnReApproveSCRQBusiness = NULL;
	}

	if (NULL != m_btnReApproveSCRQPlan)
	{
		delete m_btnReApproveSCRQPlan;
		m_btnReApproveSCRQPlan = NULL;
	}

	if (NULL != m_bsDateRange)
	{
		delete m_bsDateRange;
		m_bsDateRange = NULL;
	}

	if (NULL != m_bsMiddleLine)
	{
		delete m_bsMiddleLine;
		m_bsMiddleLine = NULL;
	}

	if (NULL != m_dtcSearchFrom)
	{
		delete m_dtcSearchFrom;
		m_dtcSearchFrom = NULL;
	}

	if (NULL != m_dtcSearchTo)
	{
		delete m_dtcSearchTo;
		m_dtcSearchTo = NULL;
	}

	__super::OnNcDestroy();
}

void CPlanPanel::OnRowChecked()
{
	m_bEnablePlanBtnForSCRQ = false;
	m_bEnablePlanBtnForBZRQ = false;

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	if (checkedRows.empty())
	{
		m_btnPlan->EnableWindow(FALSE);
		m_btnRestore->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
		m_btnReApproveSCRQPlan->EnableWindow(FALSE);
		m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
		m_btnReApproveBZRQPlan->EnableWindow(FALSE);
	}
	else
	{
		m_btnPlan->EnableWindow(TRUE);
		m_btnRestore->EnableWindow(TRUE);
		m_btnModify->EnableWindow(TRUE);

		bool bIfBreak = false;

		for (int i = checkedRows.size() - 1; i >= 0; --i)
		{
			bool bIsToBeApproveBusinessForSCRQ = false;
			bool bIsToBeApprovePlanForSCRQ = false;

			bool bIsToBeApproveBusinessForBZRQ = false;
			bool bIsToBeApprovePlanForBZRQ = false;

			for (int j = 0; j < m_table.size(); ++j)
			{
				if (m_table[j].first == checkedRows[i])
				{
					if (IDS_COMMON_YES == m_table[j].second[nsPlan::Column_en::jhshyw])
					{
						m_btnReApproveSCRQBusiness->EnableWindow(TRUE);
						bIfBreak = true;
					}
					else
					{
						bIsToBeApproveBusinessForSCRQ = true;
					}

					if (IDS_COMMON_YES == m_table[j].second[nsPlan::Column_en::jhshjh])
					{
						m_btnReApproveSCRQPlan->EnableWindow(TRUE);
						bIfBreak = true;
					}
					else
					{
						bIsToBeApprovePlanForSCRQ = true;
					}

					if (IDS_COMMON_YES == m_table[j].second[nsPlan::Column_en::bzshyw])
					{
						m_btnReApproveBZRQBusiness->EnableWindow(TRUE);
						bIfBreak = true;
					}
					else
					{
						bIsToBeApproveBusinessForBZRQ = true;
					}

					if (IDS_COMMON_YES == m_table[j].second[nsPlan::Column_en::bzshjh])
					{
						m_btnReApproveBZRQPlan->EnableWindow(TRUE);
						bIfBreak = true;
					}
					else
					{
						bIsToBeApprovePlanForBZRQ = true;
					}

					if (bIsToBeApproveBusinessForSCRQ /*&& bIsToBeApprovePlanForSCRQ*/)
					{
						m_bEnablePlanBtnForSCRQ = true;
					}

					if (bIsToBeApproveBusinessForBZRQ /*&& bIsToBeApprovePlanForBZRQ*/)
					{
						m_bEnablePlanBtnForBZRQ = true;
					}

					break;
				}
			}

			if (bIfBreak)
			{
				continue;
			}
			else
			{
				m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
				m_btnReApproveSCRQPlan->EnableWindow(FALSE);
				m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
				m_btnReApproveBZRQPlan->EnableWindow(FALSE);
			}
		}
	}
}

void CPlanPanel::OnUIPrepared()
{
	__super::OnUIPrepared();

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (perm.getPlan())
	{
		if (m_pJqGridAPI->GetRowCount() == 0)
		{
			for (int i = 0; i < m_table.size(); ++i)
			{
				m_table[i].first = m_pJqGridAPI->AddRow(m_table[i].second);
			}
		}
	}
	else
	{
		m_pJqGridAPI->HideGrid();
	}
}

//void CPlanPanel::OnHttpSuccess(int id, LPCTSTR resp)
//{
//	GetParent()->EnableWindow(TRUE);
//	switch (id)
//	{
//	case QUERY_URL_ID:
//		OnLoadDataSuccess(CString(resp));
//		break;
//	case ADD_URL_ID:
//		//OnAddDataSuccess(_tstoi(resp), m_cacheRow);
//		break;
//	case DEL_URL_ID:
//		//OnDelDataSuccess();
//		break;
//	case MODIFY_URL_ID:
//		OnModifyDataSuccess(m_cacheRow);
//		break;
//	//case BUSSINESS_APPROVE_URL_ID:	//test purpose
//		//break;
//	case REAPPROVE_URL_ID:
//		MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
//		break;
//	default:
//		break;
//	}
//}
//
//void CPlanPanel::OnHttpFailed(int id)
//{
//	GetParent()->EnableWindow(TRUE);
//	switch (id)
//	{
//	case QUERY_URL_ID:
//		MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
//		break;
//	case ADD_URL_ID:
//		MessageBox(_T("添加数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
//		break;
//	case DEL_URL_ID:
//		MessageBox(_T("删除数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
//		break;
//	case MODIFY_URL_ID:
//		MessageBox(_T("修改数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
//		break;
//	case REAPPROVE_URL_ID:
//		MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
//		break;
//	default:
//		break;
//	}
//}

void CPlanPanel::OnLoadDataSuccess(CString& jsondata)
{
	//for (int j = 0; j < m_table.size(); ++j)
	//{
	//	m_pJqGridAPI->DelRow(m_table[j].first);
	//}

	//m_pJqGridAPI->Refresh();

	////StringToTable(jsondata, m_table);
	//for (int j = 0; j < m_table.size(); ++j)
	//{
	//	m_pJqGridAPI->AddRow(m_table[j].first, m_table[j].second);
	//}
}

void CPlanPanel::OnModifyDataSuccess(std::vector<CString>& newData)
{
// 	std::vector<int> checkedRows;
// 	m_pJqGridAPI->GetCheckedRows(checkedRows);
// 	std::vector<int> checkedRowTableMap;
// 	checkedRowTableMap.resize(checkedRows.size(), -1);
// 	for (int i = checkedRows.size() - 1; i >= 0; --i)
// 	{
// 		for (int j = 0; j < m_table.size(); ++j)
// 		{
// 			if (m_table[j].first == checkedRows[i])
// 			{
// 				checkedRowTableMap[i] = j;
// 				break;
// 			}
// 		}
// 	}
// 
// 	for (int i = checkedRows.size() - 1; i >= 0; --i)
// 	{
// 		if (checkedRowTableMap[i] >= 0)
// 		{
// 			m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::scrq] = newData[0];
// 			m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::bzrq] = newData[1];
// 			m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::fhrq] = newData[2];
// 			m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::tcbh] = newData[3];
// 			m_table[checkedRowTableMap[i]].second[nsPlan::Column_en::ccbh] = newData[4];
// 		}
// 
// 		m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::scrq + 1, newData[0]);
// 		m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::bzrq + 1, newData[1]);
// 		m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::fhrq + 1, newData[2]);
// 		m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::tcbh + 1, newData[3]);
// 		m_pJqGridAPI->SetCell(checkedRows[i], nsPlan::Column_en::ccbh + 1, newData[4]);
// 	}
}

void CPlanPanel::OnInitData()
{
	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/all/none"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_ID);
	m_iCurSortCol = -1;
	m_bCurSortAsc = false;
	m_pJqGridAPI->CancelSort();
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (perm.getPlan())
	{
		/*	class OnLoadDataListener : public CPromise<table>::IHttpResponse
			{
			CONSTRUCTOR_3(OnLoadDataListener, CPlanPanel&, planPanel, table&, tb, CJQGridAPI*, pJqGridAPI)
			public:
			virtual void OnSuccess(table& tb){
			for (int j = 0; j < m_tb.size(); ++j)
			{
			m_pJqGridAPI->DelRow(m_tb[j].first);
			}

			m_pJqGridAPI->Refresh();

			m_tb = tb;

			for (int j = 0; j < m_tb.size(); ++j)
			{
			m_pJqGridAPI->AddRow(m_tb[j].first, m_tb[j].second);
			}

			m_planPanel.GetParent()->EnableWindow(TRUE);
			}
			virtual void OnFailed(){
			m_planPanel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
			}
			};*/

		/*	class CInitListener : public CPromise<PageData_t>::IHttpResponse{
				CONSTRUCTOR_3(CInitListener, CPlanPanel&, planPanel, table&, tb, CJQGridAPI*, pJqGridAPI)
				public:
				virtual void OnSuccess(PageData_t& tb){
				m_pJqGridAPI->Refresh(tb.rawData);
				m_tb = tb.rows;
				m_planPanel.HighLight();
				m_planPanel.GetParent()->EnableWindow(TRUE);
				}
				virtual void OnFailed(){
				m_planPanel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_planPanel.GetParent()->EnableWindow(TRUE);
				}
				};*/

		m_advanceSearchVals.clear();

		DEFINE_PLAN_QUERY_PARAM(pqp);
			
		MakeBasicSearchCondition(pqp);
		// (nsPlan::bzrq != null and nsPlan::scrq !=null) or (nsPlan::bzrq == null and nsPlan::scrq==null)
		//CUnitedQuery& pUq =
		//	UQ(nsPlan::bzrq, L"@!=null").and(UQ(nsPlan::scrq, L"@!=null")).group().or(
		//		UQ(nsPlan::bzrq, L"@==null").and(UQ(nsPlan::scrq, L"@==null")).group());
		//pqp.SetUnitedQuery(pUq);

		CPlan& plan = CServer::GetInstance()->GetPlan();
		plan.Query(1, m_pJqGridAPI->GetPageSize(), pqp).then(new OnPlanLoadDataListener(*this, m_table, m_pJqGridAPI.get()));

		//class CDownLoadListener : public CPromise<bool>::IHttpResponse{
		//	CONSTRUCTOR_1(CDownLoadListener, CPlanPanel&, panel)
		//public:
		//	virtual void OnSuccess(bool& ret){
		//		m_panel.MessageBox(L"download success");
		//	}
		//	virtual void OnFailed(){
		//		m_panel.MessageBox(L"download failed");
		//	}
		//};
		//plan.Export(L"D://bbccs.xls").then(new CDownLoadListener(*this));

		GetParent()->EnableWindow(FALSE);
	}
	else
	{
		m_pJqGridAPI->HideGrid();
	}
}

void CPlanPanel::ShowReApproveSCRQBusinessBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getJhywsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveSCRQBusiness->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveSCRQBusiness->ShowWindow(SW_HIDE);
	}

	m_btnReApproveSCRQBusiness->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}

void CPlanPanel::ShowReApproveSCRQPlanBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getJhjhsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveSCRQPlan->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveSCRQPlan->ShowWindow(SW_HIDE);
	}

	m_btnReApproveSCRQPlan->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}

void CPlanPanel::ShowReApproveBZRQBusinessBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getJhbzywsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveBZRQBusiness->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveBZRQBusiness->ShowWindow(SW_HIDE);
	}

	m_btnReApproveBZRQBusiness->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}

void CPlanPanel::ShowReApproveBZRQPlanBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getJhbzjhsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveBZRQPlan->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveBZRQPlan->ShowWindow(SW_HIDE);
	}

	m_btnReApproveBZRQPlan->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}

void CPlanPanel::ShowReApproveBtns()
{
	m_iCountBtnOfReApprove = -1;

	//order must be kept
	ShowReApproveBZRQPlanBtn(TRUE);
	ShowReApproveBZRQBusinessBtn(TRUE);
	ShowReApproveSCRQPlanBtn(TRUE);
	ShowReApproveSCRQBusinessBtn(TRUE);
}

void CPlanPanel::OnDestroy()
{
	CString strWidths;
	m_pJqGridAPI->GetWidths(strWidths);
	CSettingManager::GetInstance()->SetColWidths(L"planCol", strWidths);
	m_pJqGridAPI->d_OnExportClicked -= std::make_pair(this, &CPlanPanel::OnExportClicked);
	m_pJqGridAPI->d_OnExportClicked -= std::make_pair(this, &CPlanPanel::OnTemplateExportClicked);
	m_pJqGridAPI->d_OnUpdateData -= std::make_pair(this, &CPlanPanel::OnUpdateData);

	CBRPanel::OnDestroy();

	// TODO: Add your message handler code here
}

void CPlanPanel::OnUpdateData(int page, int rows, int colIndex, bool bAsc)
{
	m_iCurSortCol = colIndex;
	m_bCurSortAsc = bAsc;
	if (!m_bIfUpdateTableWhenTableFilter)
	{
		CJsonQueryParam jqp;
		MakeBasicSearchCondition(jqp);
		if (colIndex >= 0){
			jqp.AddSortCondition(colIndex, bAsc);
		}
		else{
			MAKE_PLAN_QUERY_PARAM(jqp);
		}

		CServer::GetInstance()->GetPlan().Query(page, m_pJqGridAPI->GetPageSize(), jqp)
			.then(new OnPlanLoadDataListener(*this, m_table, m_pJqGridAPI.get()));

		GetParent()->EnableWindow(FALSE);
	}
}

void CPlanPanel::OnExportClicked()
{
	class CPlanExportListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CPlanExportListener, CPlanPanel&, panel, CString, fileName);
	public:
		virtual void OnSuccess(bool& ret){
			if (ret)
			{
				m_panel.MessageBox(_T("计划数据已经成功导出到文件 : ") + m_fileName, _T("导出成功"), MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				m_panel.MessageBox(_T("计划数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
				DeleteFile(m_fileName);
			}
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("计划数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
			DeleteFile(m_fileName);
		}
	};


	COleDateTime time(COleDateTime::GetCurrentTime());
	CString strFileName(_T("计划订单数据"));
	CString strTimestamp;
	strTimestamp.Format(_T("(%4d%02d%02d_%02d_%02d_%02d).xls"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	strFileName += strTimestamp;

	CFileDialog hFileDlg(FALSE, _T("(*.xls)|*.xls"), strFileName, OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT, _T("Excel(*.xls)|*.xls||"), NULL);
	hFileDlg.m_ofn.nFilterIndex = 1;
	hFileDlg.m_ofn.hwndOwner = GetParent()->GetSafeHwnd();
	hFileDlg.m_ofn.lStructSize = sizeof(OPENFILENAME);
	hFileDlg.m_ofn.lpstrTitle = TEXT("选择导出文件位置");
	hFileDlg.m_ofn.nMaxFile = MAX_PATH;

	if (hFileDlg.DoModal() == IDOK)
	{
		DEFINE_PLAN_QUERY_PARAM(pqp);
		MakeBasicSearchCondition(pqp);

		try
		{
			CString filePathName = hFileDlg.GetPathName();
			CServer::GetInstance()->GetPlan().Export(filePathName, pqp).then(
				new CPlanExportListener(*this, filePathName));
		}
		catch (std::exception& e)
		{
			MessageBoxA(m_hWnd, (char*)e.what(), "导出失败", MB_OK | MB_ICONWARNING);
		}
	}
}

void CPlanPanel::OnTemplateExportClicked()
{
	class CPlanTemplateExportListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CPlanTemplateExportListener, CPlanPanel&, panel, CString, fileName);
	public:
		virtual void OnSuccess(bool& ret){
			if (ret)
			{
				m_panel.MessageBox(_T("计划数据已经成功导出到文件 : ") + m_fileName, _T("导出成功"), MB_OK | MB_ICONINFORMATION);
			}
			else
			{ 
				m_panel.MessageBox(_T("计划数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
				DeleteFile(m_fileName);
			}
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("计划数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
			DeleteFile(m_fileName);
		}
	};

	COleDateTime time(COleDateTime::GetCurrentTime());
	CString strFileName(_T("生产订单数据"));
	CString strTimestamp;
	strTimestamp.Format(_T("(%4d%02d%02d_%02d_%02d_%02d).xls"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	strFileName += strTimestamp;

	CFileDialog hFileDlg(FALSE, _T("(*.xls)|*.xls"), strFileName, OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT, _T("Excel(*.xls)|*.xls||"), NULL);
	hFileDlg.m_ofn.nFilterIndex = 1;
	hFileDlg.m_ofn.hwndOwner = GetParent()->GetSafeHwnd();
	hFileDlg.m_ofn.lStructSize = sizeof(OPENFILENAME);
	hFileDlg.m_ofn.lpstrTitle = TEXT("选择导出文件位置");
	hFileDlg.m_ofn.nMaxFile = MAX_PATH;

	if (hFileDlg.DoModal() == IDOK)
	{
		try
		{
			CString filePathName = hFileDlg.GetPathName();
			DEFINE_PLAN_QUERY_PARAM(pqp);
			MakeBasicSearchCondition(pqp);
			CString fileNameNew = filePathName;
			CServer::GetInstance()->GetPlan().TemplateExport(fileNameNew, pqp).then(
				new CPlanTemplateExportListener(*this, fileNameNew));
		}
		catch (std::exception& e)
		{
			MessageBoxA(m_hWnd, (char*)e.what(), "导出失败", MB_OK | MB_ICONWARNING);
		}
	}
}
