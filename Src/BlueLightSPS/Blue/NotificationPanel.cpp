#include "stdafx.h"
#include "resource_ids.h"
#include "NotificationPanel.h"
#include "reader.h"
#include "Util.h"
#define GET_UNAPPROVED_URL_ID IDP_NOTIFICATION + 1

CNotificationPanel::CNotificationPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: CBRPanel(pJqGridAPI, pHttp)
{

}

CNotificationPanel::~CNotificationPanel()
{
}

void CNotificationPanel::OnInitChilds()
{
	//销售-业务
	m_bsSaleBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEBUSINESSAPPROVE);
	m_bsSaleBusinessApprove.SetWindowText(_T("目前您有未处理的 销售-业务 审核"));
	m_bsSaleBusinessApprove.SetTextAlign(DT_LEFT);
	m_bsSaleBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSaleBusinessApprove.MoveWindow(20, 25, 220, 25);

	m_btnSaleBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE);
	m_btnSaleBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnSaleBusinessApprove.MoveWindow(240, 23, 90, 25);

	//销售-计划
	m_bsSalePlanApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEPLANAPPROVE);
	m_bsSalePlanApprove.SetWindowText(_T("目前您有未处理的 销售-计划 审核"));
	m_bsSalePlanApprove.SetTextAlign(DT_LEFT);
	m_bsSalePlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSalePlanApprove.MoveWindow(380, 25, 220, 25);

	m_btnSalePlanApprove.Create(this, IDC_NOTIFICATION_BTN_SALEPLANAPPROVE);
	m_btnSalePlanApprove.SetWindowText(_T("前往审核"));
	m_btnSalePlanApprove.MoveWindow(600, 23, 90, 25);

	//计划-生产日期-业务
	m_bsPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQBUSINESSAPPROVE);
	m_bsPlanSCRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-业务 审核"));
	m_bsPlanSCRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQBusinessApprove.MoveWindow(740, 25, 220, 25);
	m_bsPlanSCRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE);
	m_btnPlanSCRQBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnPlanSCRQBusinessApprove.MoveWindow(960, 23, 90, 25);

	//计划-生产日期-计划
	m_bsPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQPLANAPPROVE);
	m_bsPlanSCRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-生产日期-计划 审核"));
	m_bsPlanSCRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQPlanApprove.MoveWindow(20, 75, 220, 25);
	m_bsPlanSCRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE);
	m_btnPlanSCRQPlanApprove.SetWindowText(_T("前往审核"));
	m_btnPlanSCRQPlanApprove.MoveWindow(240, 73, 90, 25);

	//计划-包装日期-业务
	m_bsPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQBUSINESSAPPROVE);
	m_bsPlanBZRQBusinessApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-业务 审核"));
	m_bsPlanBZRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQBusinessApprove.MoveWindow(380, 75, 220, 25);
	m_bsPlanBZRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE);
	m_btnPlanBZRQBusinessApprove.SetWindowText(_T("前往审核"));
	m_btnPlanBZRQBusinessApprove.MoveWindow(600, 73, 90, 25);

	//计划-包装日期-计划
	m_bsPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQPLANAPPROVE);
	m_bsPlanBZRQPlanApprove.SetWindowText(_T("目前您有未处理的 计划-包装日期-计划 审核"));
	m_bsPlanBZRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQPlanApprove.MoveWindow(740, 75, 220, 25);
	m_bsPlanBZRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE);
	m_btnPlanBZRQPlanApprove.SetWindowText(_T("前往审核"));
	m_btnPlanBZRQPlanApprove.MoveWindow(960, 73, 90, 25);

}

BEGIN_MESSAGE_MAP(CNotificationPanel, CControlPanel)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedSaleBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_SALEPLANAPPROVE, &CNotificationPanel::OnBnClickedSalePlanApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE, &CNotificationPanel::OnBnClickedPlanSCRQPlanApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE, &CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE, &CNotificationPanel::OnBnClickedPlanBZRQPlanApprove)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

void CNotificationPanel::OnBnClickedSaleBusinessApprove()
{
	m_pJqGridAPI->ShowGrid();
	//HideFirstViewOfNotificationPanel(TRUE);
	//query
}

void CNotificationPanel::OnBnClickedSalePlanApprove()
{
	m_pJqGridAPI->ShowGrid();

	//query
}

void CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove()
{
	m_pJqGridAPI->ShowGrid();

	//query
}

void CNotificationPanel::OnBnClickedPlanSCRQPlanApprove()
{
	m_pJqGridAPI->ShowGrid();

	//query
}

void CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove()
{
	m_pJqGridAPI->ShowGrid();

	//query
}

void CNotificationPanel::OnBnClickedPlanBZRQPlanApprove()
{
	m_pJqGridAPI->ShowGrid();

	//query
}


void CNotificationPanel::HideFirstViewOfNotificationPanel(BOOL bShow)
{
	if (bShow)
	{
		m_bsSaleBusinessApprove.ShowWindow(SW_SHOW);
		m_bsSalePlanApprove.ShowWindow(SW_SHOW);
		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		m_bsPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		m_bsPlanBZRQPlanApprove.ShowWindow(SW_SHOW);

		m_btnSaleBusinessApprove.ShowWindow(SW_SHOW);
		m_btnSalePlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
	}
	else
	{
		m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);

		m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_btnSalePlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
	}

	UpdateWindow();
}

void CNotificationPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	m_pJqGridAPI->HideGrid();
}

void CNotificationPanel::OnHttpSuccess(int id, LPCTSTR resp)
{
	if (GET_UNAPPROVED_URL_ID == id)
	{
		std::string json;
		Util_Tools::Util::Utf16leToUtf8(CString(resp), json);
		Json::Reader reader;
		Json::Value val;
		reader.parse(json, val);
		int i = val["packBussiness"].asInt();//打包-业务未审批数
		i = val["packPlan"].asInt();//打包-计划未审批数
		i = val["planBussiness"].asInt();//计划-业务未审批数
		i = val["planPlan"].asInt();//计划-计划未审批数
		i = val["saleBussiness"].asInt();//销售-业务未审批数
		i = val["salePlan"].asInt();//销售-计划未审批数
	}
}

void CNotificationPanel::OnHttpFailed(int id)
{

}

void CNotificationPanel::OnRowChecked()
{

}

void CNotificationPanel::OnDataUpdate()
{
	m_pHttp->Get(_T("http://localhost:8080/BlueRay/notification/unapproved"), GET_UNAPPROVED_URL_ID);
}
