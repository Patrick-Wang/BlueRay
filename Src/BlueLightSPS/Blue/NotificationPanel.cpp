#include "stdafx.h"
#include "resource_ids.h"
#include "NotificationPanel.h"
#include "JsonParser.h"
#include "JsonObjects.h"
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
	//����-ҵ��
	m_bsSaleBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEBUSINESSAPPROVE);
	m_bsSaleBusinessApprove.SetWindowText(_T("Ŀǰ����δ����� ����-ҵ�� ���"));
	m_bsSaleBusinessApprove.SetTextAlign(DT_LEFT);
	m_bsSaleBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSaleBusinessApprove.MoveWindow(20, 25, 220, 25);

	m_btnSaleBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE);
	m_btnSaleBusinessApprove.SetWindowText(_T("ǰ�����"));
	m_btnSaleBusinessApprove.MoveWindow(240, 23, 90, 25);

	//����-�ƻ�
	m_bsSalePlanApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEPLANAPPROVE);
	m_bsSalePlanApprove.SetWindowText(_T("Ŀǰ����δ����� ����-�ƻ� ���"));
	m_bsSalePlanApprove.SetTextAlign(DT_LEFT);
	m_bsSalePlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsSalePlanApprove.MoveWindow(380, 25, 220, 25);

	m_btnSalePlanApprove.Create(this, IDC_NOTIFICATION_BTN_SALEPLANAPPROVE);
	m_btnSalePlanApprove.SetWindowText(_T("ǰ�����"));
	m_btnSalePlanApprove.MoveWindow(600, 23, 90, 25);

	//�ƻ�-��������-ҵ��
	m_bsPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQBUSINESSAPPROVE);
	m_bsPlanSCRQBusinessApprove.SetWindowText(_T("Ŀǰ����δ����� �ƻ�-��������-ҵ�� ���"));
	m_bsPlanSCRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQBusinessApprove.MoveWindow(740, 25, 220, 25);
	m_bsPlanSCRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE);
	m_btnPlanSCRQBusinessApprove.SetWindowText(_T("ǰ�����"));
	m_btnPlanSCRQBusinessApprove.MoveWindow(960, 23, 90, 25);

	//�ƻ�-��������-�ƻ�
	m_bsPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQPLANAPPROVE);
	m_bsPlanSCRQPlanApprove.SetWindowText(_T("Ŀǰ����δ����� �ƻ�-��������-�ƻ� ���"));
	m_bsPlanSCRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanSCRQPlanApprove.MoveWindow(20, 75, 220, 25);
	m_bsPlanSCRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE);
	m_btnPlanSCRQPlanApprove.SetWindowText(_T("ǰ�����"));
	m_btnPlanSCRQPlanApprove.MoveWindow(240, 73, 90, 25);

	//�ƻ�-��װ����-ҵ��
	m_bsPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQBUSINESSAPPROVE);
	m_bsPlanBZRQBusinessApprove.SetWindowText(_T("Ŀǰ����δ����� �ƻ�-��װ����-ҵ�� ���"));
	m_bsPlanBZRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQBusinessApprove.MoveWindow(380, 75, 220, 25);
	m_bsPlanBZRQBusinessApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE);
	m_btnPlanBZRQBusinessApprove.SetWindowText(_T("ǰ�����"));
	m_btnPlanBZRQBusinessApprove.MoveWindow(600, 73, 90, 25);

	//�ƻ�-��װ����-�ƻ�
	m_bsPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQPLANAPPROVE);
	m_bsPlanBZRQPlanApprove.SetWindowText(_T("Ŀǰ����δ����� �ƻ�-��װ����-�ƻ� ���"));
	m_bsPlanBZRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPlanBZRQPlanApprove.MoveWindow(740, 75, 220, 25);
	m_bsPlanBZRQPlanApprove.SetTextAlign(DT_LEFT);

	m_btnPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE);
	m_btnPlanBZRQPlanApprove.SetWindowText(_T("ǰ�����"));
	m_btnPlanBZRQPlanApprove.MoveWindow(960, 73, 90, 25);
	

	//�����ͷ���
	m_btnApproveInSecond.Create(this, IDC_NOTIFICATION_BTN_APPROVE);
	m_btnApproveInSecond.SetWindowText(_T("ͨ�����"));
	m_btnApproveInSecond.MoveWindow(150, 23, 90, 25);
	m_btnApproveInSecond.ShowWindow(SW_HIDE);

	m_btnReturnToFirst.Create(this, IDC_NOTIFICATION_BTN_RETURN);
	m_btnReturnToFirst.SetWindowText(_T("����"));
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
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

void CNotificationPanel::OnBnClickedSaleBusinessApprove()
{
	m_pJqGridAPI->ShowGrid();
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
		Json::JsonParser parser;
		std::shared_ptr<Json::JsonObject> joPtr = parser.Parse((LPTSTR)resp);
		int i = joPtr->asInt(L"packBussiness"); //���-ҵ��δ������
		i = joPtr->asInt(L"packPlan");//���-�ƻ�δ������
		i = joPtr->asInt(L"planBussiness");//�ƻ�-ҵ��δ������
		i = joPtr->asInt(L"planPlan");//�ƻ�-�ƻ�δ������
		i = joPtr->asInt(L"saleBussiness");//����-ҵ��δ������
		i = joPtr->asInt(L"salePlan");//����-�ƻ�δ������
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
