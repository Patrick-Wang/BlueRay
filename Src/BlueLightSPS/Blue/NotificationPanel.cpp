#include "stdafx.h"
#include "resource_ids.h"
#include "NotificationPanel.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "Util.h"
#include "CommonDefine.h"
#include "JsonType.h"
#include "User.h"
#include "Server.h"
#define GET_UNAPPROVED_URL_ID					IDP_NOTIFICATION + 1
#define QUERY_URL_UNAPPROVED_SALEBUSINESS		GET_UNAPPROVED_URL_ID + 1
#define QUERY_URL_UNAPPROVED_SALEPLAN			QUERY_URL_UNAPPROVED_SALEBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS	QUERY_URL_UNAPPROVED_SALEPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQPLAN		QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS	QUERY_URL_UNAPPROVED_PLANSCRQPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQPLAN		QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS + 1
#define POST_URL_APPROVE		QUERY_URL_UNAPPROVED_PLANBZRQPLAN + 1

static int g_StaticPos[][4] = {
		{  20, 25, 180, 25 },
		{ 270, 25, 180, 25 },
		{ 520, 25, 180, 25 },
		{ 20, 75, 180, 25 },
		{ 270, 75, 180, 25 },
		{ 520, 75, 180, 25 }
};

static int g_ButtoncPos[][4] = {
		{ 200, 23, 50, 25 }, 
		{ 450, 23, 50, 25 }, 
		{ 700, 23, 50, 25 },
		{ 200, 73, 50, 25 },
		{ 450, 73, 50, 25 },
		{ 700, 73, 50, 25 }
};

static int g_TableToBeHiddenForPlan[]
{
	17, 18, 20, 21
};

static int g_TableToBeHiddenForSale[]
{
	16, 17, 18, 19, 20, 21, 22, 23, 24
};


//CNotificationPanel::CNotificationPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
CNotificationPanel::CNotificationPanel(CJQGridAPI* pJqGridAPI)
//: CBRPanel(pJqGridAPI, pHttp)
	: CBRPanel(pJqGridAPI)
	, m_enumCurrentApprovingItem(Approving_NULL)
	, m_pTableFilter(NULL)
	, m_staticPromotion(NULL)
{

}

CNotificationPanel::~CNotificationPanel()
{
	if (NULL != m_pTableFilter)
	{
		delete m_pTableFilter;
		m_pTableFilter = NULL;
	}
}

void CNotificationPanel::AdjustTableStyleForPlan()
{
	for (int i = 0; i < _countof(g_TableToBeHiddenForSale); i++)
	{
		m_pJqGridAPI->ShowCol(g_TableToBeHiddenForSale[i]);
	}

	for (int i = 0; i < _countof(g_TableToBeHiddenForPlan); i++)
	{
		m_pJqGridAPI->HideCol(g_TableToBeHiddenForPlan[i]);
	}
}

void CNotificationPanel::AdjustTableStyleForSale()
{
	for (int i = 0; i < _countof(g_TableToBeHiddenForPlan); i++)
	{
		m_pJqGridAPI->ShowCol(g_TableToBeHiddenForPlan[i]);
	}

	for (int i = 0; i < _countof(g_TableToBeHiddenForSale); i++)
	{
		m_pJqGridAPI->HideCol(g_TableToBeHiddenForSale[i]);
	}
}

void CNotificationPanel::OnInitChilds()
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getXsywsh() && !perm.getXsjhsh() && !perm.getJhywsh() && !perm.getJhjhsh() && !perm.getJhbzywsh() && !perm.getJhbzjhsh())
	{
		m_staticPromotion = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_PROMOTION, _T("您没有审核的权限"), _T("Microsoft YaHei"), 16);
		m_staticPromotion->MoveWindow(20, 27, 500, 20);
		m_staticPromotion->SetTextAlign(DT_LEFT);
		m_pJqGridAPI->HideGrid();
	}
	else
	{
		//销售-业务
		m_bsSaleBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEBUSINESSAPPROVE);
		//m_bsSaleBusinessApprove.SetWindowText(_T("目前您有未处理的 销售-业务 审核"));
		m_bsSaleBusinessApprove.SetTextAlign(DT_LEFT);
		m_bsSaleBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsSaleBusinessApprove.MoveWindow(g_StaticPos[Approving_SaleBusiness][0], g_StaticPos[Approving_SaleBusiness][1], g_StaticPos[Approving_SaleBusiness][2], g_StaticPos[Approving_SaleBusiness][3]);

		m_btnSaleBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE);
		m_btnSaleBusinessApprove.SetWindowText(_T("审核"));
		m_btnSaleBusinessApprove.MoveWindow(g_ButtoncPos[Approving_SaleBusiness][0], g_ButtoncPos[Approving_SaleBusiness][1], g_ButtoncPos[Approving_SaleBusiness][2], g_ButtoncPos[Approving_SaleBusiness][3]);

		m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);

		//销售-计划
		m_bsSalePlanApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEPLANAPPROVE);
		//m_bsSalePlanApprove.SetWindowText(_T("目前您有未处理的 销售-计划 审核"));
		m_bsSalePlanApprove.SetTextAlign(DT_LEFT);
		m_bsSalePlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsSalePlanApprove.MoveWindow(g_StaticPos[Approving_SalePlan][0], g_StaticPos[Approving_SalePlan][1], g_StaticPos[Approving_SalePlan][2], g_StaticPos[Approving_SalePlan][3]);

		m_btnSalePlanApprove.Create(this, IDC_NOTIFICATION_BTN_SALEPLANAPPROVE);
		m_btnSalePlanApprove.SetWindowText(_T("审核"));
		m_btnSalePlanApprove.MoveWindow(g_ButtoncPos[Approving_SalePlan][0], g_ButtoncPos[Approving_SalePlan][1], g_ButtoncPos[Approving_SalePlan][2], g_ButtoncPos[Approving_SalePlan][3]);

		m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		m_btnSalePlanApprove.ShowWindow(SW_HIDE);

		//计划-生产日期-业务
		m_bsPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQBUSINESSAPPROVE);
		//m_bsPlanSCRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-业务 审核"));
		m_bsPlanSCRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanSCRQBusinessApprove.MoveWindow(g_StaticPos[Approving_PlanSCRQBusiness][0], g_StaticPos[Approving_PlanSCRQBusiness][1], g_StaticPos[Approving_PlanSCRQBusiness][2], g_StaticPos[Approving_PlanSCRQBusiness][3]);
		m_bsPlanSCRQBusinessApprove.SetTextAlign(DT_LEFT);

		m_btnPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE);
		m_btnPlanSCRQBusinessApprove.SetWindowText(_T("审核"));
		m_btnPlanSCRQBusinessApprove.MoveWindow(g_ButtoncPos[Approving_PlanSCRQBusiness][0], g_ButtoncPos[Approving_PlanSCRQBusiness][1], g_ButtoncPos[Approving_PlanSCRQBusiness][2], g_ButtoncPos[Approving_PlanSCRQBusiness][3]);

		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);

		//计划-生产日期-计划
		m_bsPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQPLANAPPROVE);
		//m_bsPlanSCRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-计划 审核"));
		m_bsPlanSCRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanSCRQPlanApprove.MoveWindow(g_StaticPos[Approving_PlanSCRQPlan][0], g_StaticPos[Approving_PlanSCRQPlan][1], g_StaticPos[Approving_PlanSCRQPlan][2], g_StaticPos[Approving_PlanSCRQPlan][3]);
		m_bsPlanSCRQPlanApprove.SetTextAlign(DT_LEFT);

		m_btnPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE);
		m_btnPlanSCRQPlanApprove.SetWindowText(_T("审核"));
		m_btnPlanSCRQPlanApprove.MoveWindow(g_ButtoncPos[Approving_PlanSCRQPlan][0], g_ButtoncPos[Approving_PlanSCRQPlan][1], g_ButtoncPos[Approving_PlanSCRQPlan][2], g_ButtoncPos[Approving_PlanSCRQPlan][3]);

		m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);

		//计划-包装日期-业务
		m_bsPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQBUSINESSAPPROVE);
		//m_bsPlanBZRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-业务 审核"));
		m_bsPlanBZRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanBZRQBusinessApprove.MoveWindow(g_StaticPos[Approving_PlanBZRQBusiness][0], g_StaticPos[Approving_PlanBZRQBusiness][1], g_StaticPos[Approving_PlanBZRQBusiness][2], g_StaticPos[Approving_PlanBZRQBusiness][3]);
		m_bsPlanBZRQBusinessApprove.SetTextAlign(DT_LEFT);

		m_btnPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE);
		m_btnPlanBZRQBusinessApprove.SetWindowText(_T("审核"));
		m_btnPlanBZRQBusinessApprove.MoveWindow(g_ButtoncPos[Approving_PlanBZRQBusiness][0], g_ButtoncPos[Approving_PlanBZRQBusiness][1], g_ButtoncPos[Approving_PlanBZRQBusiness][2], g_ButtoncPos[Approving_PlanBZRQBusiness][3]);

		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);

		//计划-包装日期-计划
		m_bsPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQPLANAPPROVE);
		//m_bsPlanBZRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-计划 审核"));
		m_bsPlanBZRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanBZRQPlanApprove.MoveWindow(g_StaticPos[Approving_PlanBZRQPlan][0], g_StaticPos[Approving_PlanBZRQPlan][1], g_StaticPos[Approving_PlanBZRQPlan][2], g_StaticPos[Approving_PlanBZRQPlan][3]);
		m_bsPlanBZRQPlanApprove.SetTextAlign(DT_LEFT);

		m_btnPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE);
		m_btnPlanBZRQPlanApprove.SetWindowText(_T("审核"));
		m_btnPlanBZRQPlanApprove.MoveWindow(g_ButtoncPos[Approving_PlanBZRQPlan][0], g_ButtoncPos[Approving_PlanBZRQPlan][1], g_ButtoncPos[Approving_PlanBZRQPlan][2], g_ButtoncPos[Approving_PlanBZRQPlan][3]);

		m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);

		//审批和返回
		m_btnApproveInSecond.Create(this, IDC_NOTIFICATION_BTN_APPROVE);
		m_btnApproveInSecond.SetWindowText(_T("通过审核"));
		m_btnApproveInSecond.MoveWindow(160, 23, 90, 25);
		m_btnApproveInSecond.ShowWindow(SW_HIDE);
		m_btnApproveInSecond.EnableWindow(FALSE);

		m_btnReturnToFirst.Create(this, IDC_NOTIFICATION_BTN_RETURN);
		m_btnReturnToFirst.SetWindowText(_T("返回"));
		m_btnReturnToFirst.MoveWindow(20, 23, 90, 25);
		m_btnReturnToFirst.ShowWindow(SW_HIDE);

		m_btnTableFilter.Create(this, IDC_NOTIFICATION_BTN_TABFILTER);
		m_btnTableFilter.SetWindowText(_T("表格设置"));
		m_btnTableFilter.MoveWindow(750, 23, 90, 25);
		m_btnTableFilter.ShowWindow(SW_HIDE);
	}
}

BEGIN_MESSAGE_MAP(CNotificationPanel, CControlPanel)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedSaleBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_SALEPLANAPPROVE, &CNotificationPanel::OnBnClickedSalePlanApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE, &CNotificationPanel::OnBnClickedPlanSCRQPlanApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE, &CNotificationPanel::OnBnClickedPlanBZRQPlanApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_RETURN, &CNotificationPanel::OnBnClickedBtnReturn)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_APPROVE, &CNotificationPanel::OnBnClickedBtnApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_TABFILTER, &CNotificationPanel::OnBnClickedBtnTableFilter)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

void CNotificationPanel::OnBnClickedBtnReturn()
{
	m_pJqGridAPI->HideGrid();

	HideChild(&m_btnReturnToFirst);
	HideChild(&m_btnApproveInSecond);
	HideChild(&m_btnTableFilter);
		
	OnInitData();

	m_enumCurrentApprovingItem = Approving_NULL;
}

void CNotificationPanel::OnBnClickedBtnApprove()
{
	//update status to DB

	GetParent()->EnableWindow(FALSE);

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	class CApproveListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_1(CApproveListener, CNotificationPanel&, panel)
	public:
		virtual void OnSuccess(bool& ret){
			m_panel.MessageBox(_T("审核成功"), _T("审核结果"), MB_OK | MB_ICONWARNING);
			m_panel.OnBnClickedBtnReturn();
			m_panel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("审核失败"), _T("审核结果"), MB_OK | MB_ICONWARNING);
			m_panel.OnBnClickedBtnReturn();
			m_panel.GetParent()->EnableWindow(TRUE);
		}
	};

	CString url;
	switch (m_enumCurrentApprovingItem)
	{
	case CNotificationPanel::Approving_NULL:
		break;
	case CNotificationPanel::Approving_SaleBusiness:
		//url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
		CServer::GetInstance()->GetSale().Approve(CSale::BUSINESS, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_SalePlan:
		//url.Format(_T("http://%s:8080/BlueRay/sale/approve/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetSale().Approve(CSale::PLAN, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_PlanSCRQBusiness:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/business"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PLAN_BUSINESS, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_PlanSCRQPlan:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PLAN_PLAN, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_PlanBZRQBusiness:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/business"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PACK_BUSINESS, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_PlanBZRQPlan:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PACK_PLAN, checkedRows).then(new CApproveListener(*this));
		break;
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}
	
	//m_pHttp->Post(url, POST_URL_APPROVE, attr);
}

void CNotificationPanel::OnBnClickedBtnTableFilter()
{
	if (IDOK == m_pTableFilter->DoModal()){
	}
}

void CNotificationPanel::OnBnClickedSaleBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_SaleBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	CJsonQueryParam jqp;
	jqp.AddSortCondition(17, true);
	jqp.AddApproveCondition(CSale::BUSINESS, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));

	/*CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/query/business/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEBUSINESS);*/
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedSalePlanApprove()
{
	m_enumCurrentApprovingItem = Approving_SalePlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	DEFINE_SALE_QUERY_PARAM(jqp);
	jqp.AddApproveCondition(CSale::PLAN, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));
	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/sale/query/plan/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	CJsonQueryParam jqp;
	jqp.AddSortCondition(24, true);//for yxj
	jqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_businessApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQPlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CJsonQueryParam jqp;
	jqp.AddSortCondition(24, true);//for yxj
	jqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_planApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	CJsonQueryParam jqp;
	jqp.AddSortCondition(24, true);//for yxj
	jqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/pack_businessApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQPlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CJsonQueryParam jqp;
	jqp.AddSortCondition(24, true);//for yxj
	jqp.AddApproveCondition(CPlan::PACK_PLAN, false);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/pack_planApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANBZRQPLAN);
	GetParent()->EnableWindow(FALSE);
}


void CNotificationPanel::HideFirstViewOfNotificationPanel(BOOL bShow)
{
	if (bShow)
	{
		ShowChild(&m_bsSaleBusinessApprove);
		ShowChild(&m_bsSalePlanApprove);
		ShowChild(&m_bsPlanSCRQBusinessApprove);
		ShowChild(&m_bsPlanSCRQPlanApprove);
		ShowChild(&m_bsPlanBZRQBusinessApprove);
		ShowChild(&m_bsPlanBZRQPlanApprove);

		ShowChild(&m_btnSaleBusinessApprove);
		ShowChild(&m_btnSalePlanApprove);
		ShowChild(&m_btnPlanSCRQBusinessApprove);
		ShowChild(&m_btnPlanSCRQPlanApprove);
		ShowChild(&m_btnPlanBZRQBusinessApprove);
		ShowChild(&m_btnPlanBZRQPlanApprove);

		//disable for two button in second page
		HideChild(&m_btnReturnToFirst);
		HideChild(&m_btnApproveInSecond);
		HideChild(&m_btnTableFilter);
	}
	else
	{
		HideChild(&m_bsSaleBusinessApprove);
		HideChild(&m_bsSalePlanApprove);
		HideChild(&m_bsPlanSCRQBusinessApprove);
		HideChild(&m_bsPlanSCRQPlanApprove);
		HideChild(&m_bsPlanBZRQBusinessApprove);
		HideChild(&m_bsPlanBZRQPlanApprove);

		HideChild(&m_btnSaleBusinessApprove);
		HideChild(&m_btnSalePlanApprove);
		HideChild(&m_btnPlanSCRQBusinessApprove);
		HideChild(&m_btnPlanSCRQPlanApprove);
		HideChild(&m_btnPlanBZRQBusinessApprove);
		HideChild(&m_btnPlanBZRQPlanApprove);

		//available for two button in second page
		ShowChild(&m_btnReturnToFirst);
		ShowChild(&m_btnApproveInSecond);
		ShowChild(&m_btnTableFilter);
	}
}

void CNotificationPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	m_pJqGridAPI->HideGrid();
}

void CNotificationPanel::OnHttpSuccess(int id, LPCTSTR resp)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_UNAPPROVED_SALEBUSINESS:
	case QUERY_URL_UNAPPROVED_SALEPLAN:
	case QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS:
	case QUERY_URL_UNAPPROVED_PLANSCRQPLAN:
	case QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS:
	case QUERY_URL_UNAPPROVED_PLANBZRQPLAN:
		//OnLoadDataSuccess(CString(resp));
		break;
	case POST_URL_APPROVE:
		MessageBox(_T("审核成功"), _T("审核结果"), MB_OK | MB_ICONWARNING);
		OnBnClickedBtnReturn();
		break;
	default:
		break;
	}
}

void CNotificationPanel::OnHttpFailed(int id)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_UNAPPROVED_SALEBUSINESS:
	case QUERY_URL_UNAPPROVED_SALEPLAN:
	case QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS:
	case QUERY_URL_UNAPPROVED_PLANSCRQPLAN:
	case QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS:
	case QUERY_URL_UNAPPROVED_PLANBZRQPLAN:
		break;
	case POST_URL_APPROVE:
		MessageBox(_T("审核失败"), _T("审核结果"), MB_OK | MB_ICONWARNING);
		OnBnClickedBtnReturn();
		break;
	default:
		break;
	}
}

void CNotificationPanel::OnRowChecked()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	if (checkedRows.empty())
	{
		m_btnApproveInSecond.EnableWindow(FALSE);
	}
	else
	{
		m_btnApproveInSecond.EnableWindow(TRUE);
	}
}


void CNotificationPanel::OnLoadDataSuccess(PageData_t& page)
{
	//for (int j = 0; j < m_table.size(); ++j)
	//{
	//	m_pJqGridAPI->DelRow(m_table[j].first);
	//}
	m_table = page.rows;
	m_pJqGridAPI->Refresh(page.rawData);
	
	//StringToTable(jsondata, m_table);
	//for (int j = 0; j < m_table.size(); ++j)
	//{
	//	m_pJqGridAPI->AddRow(m_table[j].first, m_table[j].second);
	//}

	if ((m_enumCurrentApprovingItem == Approving_SaleBusiness) || (m_enumCurrentApprovingItem == Approving_SalePlan))
	{
		AdjustTableStyleForSale();
	} 
	else
	{
		AdjustTableStyleForPlan();
	}
	
	CTableFilterDlg *objTableFilter();

	if (NULL != m_pTableFilter)
	{
		delete m_pTableFilter;
		m_pTableFilter = NULL;
	}

	m_pTableFilter = new CTableFilterDlg(_T("表格设置"));

	if (NULL != m_pTableFilter)
	{
		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			return;
		case CNotificationPanel::Approving_SaleBusiness:
		case CNotificationPanel::Approving_SalePlan:
			m_pTableFilter->Initialize(m_pJqGridAPI.get(), Page_Notification_Sale);
			break;
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		case CNotificationPanel::Approving_PlanSCRQPlan:
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		case CNotificationPanel::Approving_PlanBZRQPlan:
			m_pTableFilter->Initialize(m_pJqGridAPI.get(), Page_Notification_Plan);
			break;
		case CNotificationPanel::Approving_END:
			return;
		default:
			return;
		}
	}

}

void CNotificationPanel::OnInitData()
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getXsywsh() && !perm.getXsjhsh() && !perm.getJhywsh() && !perm.getJhjhsh() && !perm.getJhbzywsh() && !perm.getJhbzjhsh())
	{
		//m_staticPromotion = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_PROMOTION, _T("您没有审核的权限"), _T("Microsoft YaHei"), 16);
		//m_staticPromotion->MoveWindow(20, 27, 500, 20);
		//m_staticPromotion->SetTextAlign(DT_LEFT);
		//m_pJqGridAPI->HideGrid();
	}
	else
	{
		HideFirstViewOfNotificationPanel(TRUE);
		CString strRet;
		//获取未审批数量
		CNotification::Unapproved_t stUnapproved = {};
		CServer::GetInstance()->GetNotification().GetUnapprovedSync(stUnapproved);
		//m_pHttp->SyncGet(_T("http://localhost:8080/BlueRay/notification/unapproved"), strRet);
		OnReturnApprovedNum(stUnapproved);
	}
}

void CNotificationPanel::OnReturnApprovedNum(CNotification::Unapproved_t& stUnapproved)
{
	Json::JsonParser parser;
	int iPackBussiness = stUnapproved.iPackBussiness; //打包-业务未审批数
	int iPackPlan = stUnapproved.iPackPlan;//打包-计划未审批数
	int iPlanBussiness = stUnapproved.iPlanBussiness;//计划-业务未审批数
	int iPlanPlan = stUnapproved.iPlanPlan;//计划-计划未审批数
	int iSaleBussiness = stUnapproved.iSaleBussiness;//销售-业务未审批数
	int iSalePlan = stUnapproved.iSalePlan;//销售-计划未审批数

	CString strSaleBussiness;
	strSaleBussiness.Format(_T("您有 %d条 未审核的 销售-业务"), iSaleBussiness);
	m_bsSaleBusinessApprove.SetWindowText(strSaleBussiness);

	int iPosIndex = 0;

	CPermission& perm = CUser::GetInstance()->GetPermission();
	bool bHasSp = false;
	if (0 < iSaleBussiness && perm.getXsywsh())
	{
		m_bsSaleBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnSaleBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		
		m_bsSaleBusinessApprove.ShowWindow(SW_SHOW);
		m_btnSaleBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strSalePlan;
	strSalePlan.Format(_T("您有 %d条 未审核的 销售-计划"), iSalePlan);
	m_bsSalePlanApprove.SetWindowText(strSalePlan);

	if (0 < iSalePlan && perm.getXsjhsh())
	{
		m_bsSalePlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnSalePlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		m_bsSalePlanApprove.ShowWindow(SW_SHOW);
		m_btnSalePlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		m_btnSalePlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanBussiness;
	strPlanBussiness.Format(_T("您有 %d条 未审核的 业务-生产"), iPlanBussiness);
	m_bsPlanSCRQBusinessApprove.SetWindowText(strPlanBussiness);

	if (0 < iPlanBussiness && perm.getJhywsh())
	{
		m_bsPlanSCRQBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanSCRQBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanPlan;
	strPlanPlan.Format(_T("您有 %d条 未审核的 计划-生产"), iPlanPlan);
	m_bsPlanSCRQPlanApprove.SetWindowText(strPlanPlan);

	if (0 < iPlanPlan && perm.getJhjhsh())
	{
		m_bsPlanSCRQPlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanSCRQPlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		m_bsPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPackBussiness;
	strPackBussiness.Format(_T("您有 %d条 未审核的 业务-包装"), iPackBussiness);
	m_bsPlanBZRQBusinessApprove.SetWindowText(strPackBussiness);

	if (0 < iPackBussiness && perm.getJhbzywsh())
	{
		m_bsPlanBZRQBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanBZRQBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPackPlan;
	strPackPlan.Format(_T("您有 %d条 未审核的 计划-包装"), iPackPlan);
	m_bsPlanBZRQPlanApprove.SetWindowText(strPackPlan);

	if (0 < iPackPlan && perm.getJhbzjhsh())
	{
		m_bsPlanBZRQPlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanBZRQPlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		m_bsPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
	}
}
