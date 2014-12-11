#include "stdafx.h"
#include "resource_ids.h"
#include "NotificationPanel.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "Util.h"
#include "CommonDefine.h"

#define GET_UNAPPROVED_URL_ID					IDP_NOTIFICATION + 1
#define QUERY_URL_UNAPPROVED_SALEBUSINESS		GET_UNAPPROVED_URL_ID + 1
#define QUERY_URL_UNAPPROVED_SALEPLAN			QUERY_URL_UNAPPROVED_SALEBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS	QUERY_URL_UNAPPROVED_SALEPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQPLAN		QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS	QUERY_URL_UNAPPROVED_PLANSCRQPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQPLAN		QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS + 1
#define POST_URL_APPROVE		QUERY_URL_UNAPPROVED_PLANBZRQPLAN + 1


CNotificationPanel::CNotificationPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: CBRPanel(pJqGridAPI, pHttp)
	, m_enumCurrentApprovingItem(Approving_NULL)
{

}

CNotificationPanel::~CNotificationPanel()
{
}

void CNotificationPanel::OnInitChilds()
{

	//销售-业务
	m_bsSaleBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEBUSINESSAPPROVE);
	//m_bsSaleBusinessApprove.SetWindowText(_T("目前您有未处理的 销售-业务 审核"));
	m_bsSaleBusinessApprove.SetTextAlign(DT_LEFT);
	m_bsSaleBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSaleBusinessApprove.MoveWindow(20, 25, 220, 25);

	m_btnSaleBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE);
	m_btnSaleBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnSaleBusinessApprove.MoveWindow(240, 23, 90, 25);

	m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
	m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);

	//销售-计划
	m_bsSalePlanApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEPLANAPPROVE);
	//m_bsSalePlanApprove.SetWindowText(_T("目前您有未处理的 销售-计划 审核"));
	m_bsSalePlanApprove.SetTextAlign(DT_LEFT);
	m_bsSalePlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSalePlanApprove.MoveWindow(380, 25, 220, 25);

	m_btnSalePlanApprove.Create(this, IDC_NOTIFICATION_BTN_SALEPLANAPPROVE);
	m_btnSalePlanApprove.SetWindowText(_T("前往审核"));
	m_btnSalePlanApprove.MoveWindow(600, 23, 90, 25);

	m_bsSalePlanApprove.ShowWindow(SW_HIDE);
	m_btnSalePlanApprove.ShowWindow(SW_HIDE);

	//计划-生产日期-业务
	m_bsPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQBUSINESSAPPROVE);
	//m_bsPlanSCRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-业务 审核"));
	m_bsPlanSCRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQBusinessApprove.MoveWindow(740, 25, 220, 25);
	m_bsPlanSCRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE);
	m_btnPlanSCRQBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnPlanSCRQBusinessApprove.MoveWindow(960, 23, 90, 25);

	m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
	m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);

	//计划-生产日期-计划
	m_bsPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQPLANAPPROVE);
	//m_bsPlanSCRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-计划 审核"));
	m_bsPlanSCRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQPlanApprove.MoveWindow(20, 75, 220, 25);
	m_bsPlanSCRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE);
	m_btnPlanSCRQPlanApprove.SetWindowText(_T("前往审核"));
	m_btnPlanSCRQPlanApprove.MoveWindow(240, 73, 90, 25);

	m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
	m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);

	//计划-包装日期-业务
	m_bsPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQBUSINESSAPPROVE);
	//m_bsPlanBZRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-业务 审核"));
	m_bsPlanBZRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQBusinessApprove.MoveWindow(380, 75, 220, 25);
	m_bsPlanBZRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE);
	m_btnPlanBZRQBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnPlanBZRQBusinessApprove.MoveWindow(600, 73, 90, 25);

	m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
	m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);

	//计划-包装日期-计划
	m_bsPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQPLANAPPROVE);
	//m_bsPlanBZRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-计划 审核"));
	m_bsPlanBZRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQPlanApprove.MoveWindow(740, 75, 220, 25);
	m_bsPlanBZRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE);
	m_btnPlanBZRQPlanApprove.SetWindowText(_T("前往审核"));
	m_btnPlanBZRQPlanApprove.MoveWindow(960, 73, 90, 25);

	m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
	m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);

	//审批和返回
	m_btnApproveInSecond.Create(this, IDC_NOTIFICATION_BTN_APPROVE);
	m_btnApproveInSecond.SetWindowText(_T("通过审核"));
	m_btnApproveInSecond.MoveWindow(150, 23, 90, 25);
	m_btnApproveInSecond.ShowWindow(SW_HIDE);
	m_btnApproveInSecond.EnableWindow(FALSE);

	m_btnReturnToFirst.Create(this, IDC_NOTIFICATION_BTN_RETURN);
	m_btnReturnToFirst.SetWindowText(_T("返回"));
	m_btnReturnToFirst.MoveWindow(20, 23, 90, 25);
	m_btnReturnToFirst.ShowWindow(SW_HIDE);
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
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

void CNotificationPanel::OnBnClickedBtnReturn()
{
	m_pJqGridAPI->HideGrid();

	HideChild(&m_btnReturnToFirst);
	HideChild(&m_btnApproveInSecond);

	OnDataUpdate();

	m_enumCurrentApprovingItem = Approving_NULL;
}

void CNotificationPanel::OnBnClickedBtnApprove()
{
	//update status to DB

	GetParent()->EnableWindow(FALSE);

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;
	
	CString url;

	switch (m_enumCurrentApprovingItem)
	{
	case CNotificationPanel::Approving_NULL:
		break;
	case CNotificationPanel::Approving_SaleBusiness:
		url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_SalePlan:
		url.Format(_T("http://%s:8080/BlueRay/sale/approve/plan"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_PlanSCRQBusiness:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/business"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_PlanSCRQPlan:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/plan"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_PlanBZRQBusiness:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/business"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_PlanBZRQPlan:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/plan"), IDS_HOST_NAME);
		break;
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}

	m_pHttp->Post(url, POST_URL_APPROVE, attr);
}


void CNotificationPanel::OnBnClickedSaleBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_SaleBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/query/business/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedSalePlanApprove()
{
	m_enumCurrentApprovingItem = Approving_SalePlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/query/plan/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_bussinessApprove/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQPlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_planApprove/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQBusiness;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/query/pack_bussinessApprove/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQPlan;

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/query/pack_planApprove/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANBZRQPLAN);
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
	}
}

void CNotificationPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	m_pJqGridAPI->HideGrid();
	HideFirstViewOfNotificationPanel(TRUE);
	OnDataUpdate();
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
		OnLoadDataSuccess(CString(resp));
		break;
	case POST_URL_APPROVE:
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


void CNotificationPanel::OnLoadDataSuccess(CString& jsondata)
{
	for (int j = 0; j < m_table.size(); ++j)
	{
		m_pJqGridAPI->DelRow(m_table[j].first);
	}
	m_pJqGridAPI->Refresh();
	StringToTable(jsondata, m_table);
	for (int j = 0; j < m_table.size(); ++j)
	{
		m_pJqGridAPI->AddRow(m_table[j].first, m_table[j].second);
	}
}

void CNotificationPanel::OnDataUpdate()
{
	CString strRet;
	//获取未审批数量
	m_pHttp->SyncGet(_T("http://localhost:8080/BlueRay/notification/unapproved"), strRet);
	OnReturnApprovedNum(strRet);
}

void CNotificationPanel::OnReturnApprovedNum(LPCTSTR resp)
{
	Json::JsonParser parser;
	std::shared_ptr<Json::JsonObject> joPtr = parser.Parse((LPTSTR)resp);
	int iPackBussiness = joPtr->asInt(L"packBussiness"); //打包-业务未审批数
	int iPackPlan = joPtr->asInt(L"packPlan");//打包-计划未审批数
	int iPlanBussiness = joPtr->asInt(L"planBussiness");//计划-业务未审批数
	int iPlanPlan = joPtr->asInt(L"planPlan");//计划-计划未审批数
	int iSaleBussiness = joPtr->asInt(L"saleBussiness");//销售-业务未审批数
	int iSalePlan = joPtr->asInt(L"salePlan");//销售-计划未审批数

	CString strSaleBussiness;
	strSaleBussiness.Format(_T("目前您有 %d条 未处理的 销售-业务 审核"), iSaleBussiness);
	m_bsSaleBusinessApprove.SetWindowText(strSaleBussiness);

	if (0 < iSaleBussiness)
	{
		m_bsSaleBusinessApprove.ShowWindow(SW_SHOW);
		m_btnSaleBusinessApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strSalePlan;
	strSalePlan.Format(_T("目前您有 %d条 未处理的 销售-计划 审核"), iSalePlan);
	m_bsSalePlanApprove.SetWindowText(strSalePlan);

	if (0 < iSalePlan)
	{
		m_bsSalePlanApprove.ShowWindow(SW_SHOW);
		m_btnSalePlanApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		m_btnSalePlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanBussiness;
	strPlanBussiness.Format(_T("目前您有 %d条 未处理的 计划-生产日期-业务 审核"), iPlanBussiness);
	m_bsPlanSCRQBusinessApprove.SetWindowText(strPlanBussiness);

	if (0 < iPlanBussiness)
	{
		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanPlan;
	strPlanPlan.Format(_T("目前您有 %d条 未处理的 计划-生产日期-计划 审核"), iPlanPlan);
	m_bsPlanSCRQPlanApprove.SetWindowText(strPlanPlan);

	if (0 < iPlanPlan)
	{
		m_bsPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPackBussiness;
	strPackBussiness.Format(_T("目前您有 %d条 未处理的 计划-包装日期-业务 审核"), iPackBussiness);
	m_bsPlanBZRQBusinessApprove.SetWindowText(strPackBussiness);

	if (0 < iPackBussiness)
	{
		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPackPlan;
	strPackPlan.Format(_T("目前您有 %d条 未处理的 计划-包装日期-计划 审核"), iPackPlan);
	m_bsPlanBZRQPlanApprove.SetWindowText(strPackPlan);

	if (0 < iPackPlan)
	{
		m_bsPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
	}
}
