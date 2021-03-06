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
#include "SaleAddDlg.h"
#include "NotificationAddDlgForPlan.h"
#include "NotificationAddDlgForSale.h"
#include "TempCleaner.h"
#include <map>
#define GET_UNAPPROVED_URL_ID					IDP_NOTIFICATION + 1
#define QUERY_URL_UNAPPROVED_SALEBUSINESS		GET_UNAPPROVED_URL_ID + 1
#define QUERY_URL_UNAPPROVED_SALEPLAN			QUERY_URL_UNAPPROVED_SALEBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS	QUERY_URL_UNAPPROVED_SALEPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANSCRQPLAN		QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS	QUERY_URL_UNAPPROVED_PLANSCRQPLAN + 1
#define QUERY_URL_UNAPPROVED_PLANBZRQPLAN		QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS + 1
#define POST_URL_APPROVE		QUERY_URL_UNAPPROVED_PLANBZRQPLAN + 1

static int g_static_width = 235;
static int g_button_width = 90;
static int g_space_between = 80;

static int g_StaticPos[][4] = {
		{ 20 + (g_button_width + g_static_width + g_space_between) * 0, 25  - 10, g_static_width, 25 },
		{ 20 + (g_button_width + g_static_width + g_space_between) * 1, 25  - 10, g_static_width, 25 },
		{ 20 + (g_button_width + g_static_width + g_space_between) * 0, 75  - 10, g_static_width, 25 },
		{ 20 + (g_button_width + g_static_width + g_space_between) * 1, 75  - 10, g_static_width, 25 },
		{ 20 + (g_button_width + g_static_width + g_space_between) * 0, 125 - 10, g_static_width, 25 },
		{ 20 + (g_button_width + g_static_width + g_space_between) * 1, 125 - 10, g_static_width, 25 },
};

static int g_ButtoncPos[][4] = {
		{ 20 + g_static_width, 23 - 10, g_button_width, 25 },
		{ 20 + (g_button_width + g_static_width * 2 + g_space_between), 23 - 10, g_button_width, 25 },
		{ 20 + g_static_width, 73 - 10, g_button_width, 25 },
		{ 20 + (g_button_width + g_static_width * 2 + g_space_between), 73 - 10, g_button_width, 25 },
		{ 20 + g_static_width, 123 - 10, g_button_width, 25 },
		{ 20 + (g_button_width + g_static_width * 2 + g_space_between), 123 - 10, g_button_width, 25 }
};

#define NOTIFICATION_SALE_MAP(map, item)\
	map[nsNotification::item] = nsSale::item;
	
#define NOTIFICATION_PLAN_MAP(map, item)\
	map[nsNotification::item] = nsPlan::item;

#define TO_SALE_INDEX(index) \
	notificationSaleMap[index]

#define TO_PLAN_INDEX(index) \
	notificationPlanMap[index]

std::map<int, int> notificationSaleMap;
std::map<int, int> notificationPlanMap;

void initMap(){

		NOTIFICATION_SALE_MAP(notificationSaleMap, hth);
		NOTIFICATION_SALE_MAP(notificationSaleMap, khmc);	//客户名称"
		NOTIFICATION_SALE_MAP(notificationSaleMap, ggxh);	//规格型号"
		NOTIFICATION_SALE_MAP(notificationSaleMap, sl);	//数量"
		NOTIFICATION_SALE_MAP(notificationSaleMap, zc);	//轴承"
		NOTIFICATION_SALE_MAP(notificationSaleMap, dfr);	//单复�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, zdqdy);	//制动器电�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, yylgg);	//曳引轮规�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, jf);	//机房"
		NOTIFICATION_SALE_MAP(notificationSaleMap, bpqxh);	//变频器型�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, bmqxh);	//编码器型�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, dlcd);	//电缆长度"
		NOTIFICATION_SALE_MAP(notificationSaleMap, zxcd);	//闸线长度"
		NOTIFICATION_SALE_MAP(notificationSaleMap, mpzl);	//铭牌等资�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, bz);	//备注"
		NOTIFICATION_SALE_MAP(notificationSaleMap, ddrq);	//订单日期"
		NOTIFICATION_SALE_MAP(notificationSaleMap, zjdy);	//主机电压
		NOTIFICATION_SALE_MAP(notificationSaleMap, zjys);	//主机颜色
		NOTIFICATION_SALE_MAP(notificationSaleMap, zdqxh);	//制动器型�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, zyz);	// �?右置
		NOTIFICATION_SALE_MAP(notificationSaleMap, bzxdtgg);// 包装�?底托规格
		NOTIFICATION_SALE_MAP(notificationSaleMap, gh);	// 工号
		NOTIFICATION_SALE_MAP(notificationSaleMap, zzs);	// 制造商
		NOTIFICATION_SALE_MAP(notificationSaleMap, khqy);	// 客户区域
		NOTIFICATION_SALE_MAP(notificationSaleMap, yxj);	//优先�?
		NOTIFICATION_SALE_MAP(notificationSaleMap, ywsh);	//审核-业务
		NOTIFICATION_SALE_MAP(notificationSaleMap, jhsh);	//审核-计划"



		NOTIFICATION_PLAN_MAP(notificationPlanMap, hth);	//合同�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, khmc);	//客户名称"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, ggxh);	//规格型号"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, cg);
		NOTIFICATION_PLAN_MAP(notificationPlanMap, sl);	//数量"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zc);	//轴承"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, dfr);	//单复�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zdqdy);	//制动器电�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, yylgg);	//曳引轮规�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, jf);	//机房"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bpqxh);	//变频器型�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bmqxh);	//编码器型�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, dlcd);	//电缆长度"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zxcd);	//闸线长度"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, mpzl);	//铭牌等资�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bz);	//备注"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, ddrq);	//订单日期"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zjdy);	//主机电压
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zjys);	//主机颜色
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zdqxh);	//制动器型�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zyz);	// �?右置
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bzxdtgg);// 包装�?底托规格
		NOTIFICATION_PLAN_MAP(notificationPlanMap, gh);	// 工号
		NOTIFICATION_PLAN_MAP(notificationPlanMap, zzs);	// 制造商
		NOTIFICATION_PLAN_MAP(notificationPlanMap, khqy);	// 客户区域
		NOTIFICATION_PLAN_MAP(notificationPlanMap, yxj);	//优先�?
		NOTIFICATION_PLAN_MAP(notificationPlanMap, scrq);	//生产日期"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, jhshyw);	//计划审核-业务"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, jhshjh);	//计划审核-计划"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bzrq);	//包装日期"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bzshyw);	//包装审核-业务"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, bzshjh);	//包装审核-计划"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, fhrq);	//发货日期"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, tcbh);	//投产编号"
		NOTIFICATION_PLAN_MAP(notificationPlanMap, ccbh);	//出厂编号"
}


// static int g_TableToBeHiddenForPlan[]
// {
// 	nsNotification::Column_en::ywsh,
// 		nsNotification::Column_en::jhsh,
// 		nsNotification::Column_en::dfr,
// 		nsNotification::Column_en::yxj
// };
// 
// static int g_TableToBeHiddenForSale[]
// {
// 	nsNotification::Column_en::cg,
// 	nsNotification::Column_en::dfr,
// 		nsNotification::Column_en::yxj,
// 		nsNotification::Column_en::scrq,
// 		nsNotification::Column_en::jhshyw,
// 		nsNotification::Column_en::jhshjh,
// 		nsNotification::Column_en::bzrq,
// 		nsNotification::Column_en::bzshyw,
// 		nsNotification::Column_en::bzshjh,
// 		nsNotification::Column_en::fhrq,
// 		nsNotification::Column_en::tcbh,
// 		nsNotification::Column_en::ccbh,
// };

CNotificationPanel::CNotificationPanel(CJQGridAPI* pJqGridAPI)
	: CBRPanel(pJqGridAPI)
	, m_enumCurrentApprovingItem(Approving_NULL)
	, m_pTableFilterForPlan(NULL)
	, m_pTableFilterForSale(NULL)
	, m_staticPromotion(NULL)
	, m_bIfUpdateTableWhenTableFilter(false)
	, m_btnSearch(NULL)
	, m_bsDateRange(NULL)
	, m_bsMiddleLine(NULL)
	, m_dtcSearchFrom(NULL)
	, m_dtcSearchTo(NULL)
	, m_btnMore(NULL)
	, m_editSearch(NULL)
{
	initMap();
}

CNotificationPanel::~CNotificationPanel()
{
	if (NULL != m_pTableFilterForSale)
	{
		delete m_pTableFilterForSale;
		m_pTableFilterForSale = NULL;
	}

	if (NULL != m_pTableFilterForPlan)
	{
		delete m_pTableFilterForPlan;
		m_pTableFilterForPlan = NULL;
	}
}

void CNotificationPanel::OnNcDestroy()
{
	if (NULL != m_btnSearch)
	{
		delete m_btnSearch;
		m_btnSearch = NULL;
	}

	if (NULL != m_editSearch)
	{
		delete m_editSearch;
		m_editSearch = NULL;
	}

	if (NULL != m_btnMore)
	{
		delete m_btnMore;
		m_btnMore = NULL;
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

void CNotificationPanel::OnDestroy()
{
	m_pJqGridAPI->d_OnUpdateData -= std::make_pair(this, &CNotificationPanel::OnUpdateData);
	CBRPanel::OnDestroy();
}

// void CNotificationPanel::AdjustTableStyleForPlan()
// {
// 	for (int i = 0; i < _countof(g_TableToBeHiddenForSale); i++)
// 	{
// 		m_pJqGridAPI->ShowCol(g_TableToBeHiddenForSale[i]);
// 	}
// 
// 	for (int i = 0; i < _countof(g_TableToBeHiddenForPlan); i++)
// 	{
// 		m_pJqGridAPI->HideCol(g_TableToBeHiddenForPlan[i]);
// 	}
// }

// void CNotificationPanel::AdjustTableStyleForSale()
// {
// 	for (int i = 0; i < _countof(g_TableToBeHiddenForPlan); i++)
// 	{
// 		m_pJqGridAPI->ShowCol(g_TableToBeHiddenForPlan[i]);
// 	}
// 
// 	for (int i = 0; i < _countof(g_TableToBeHiddenForSale); i++)
// 	{
// 		m_pJqGridAPI->HideCol(g_TableToBeHiddenForSale[i]);
// 	}
// }


void CNotificationPanel::HighLight()
{
	//for (size_t i = 0, len = m_table.size(); i < len; i++)
	//{
	//	if (0 == m_table[i].second[nsSale::yxj].Compare(L"��"))
	//	{
	//		m_pJqGridAPI->HighLightRow(m_table[i].first);
	//	}
	//}
	for (size_t i = 0, len = m_table.size(); i < len; i++)
	{
		StringArray row = m_table[i].second;

		switch (m_enumCurrentApprovingItem)
		{
			case CNotificationPanel::Approving_SaleBusiness:
			case CNotificationPanel::Approving_SalePlan:
			{
				for (int index = _countof(g_TableToBeReplacedByNullForSale) - 1; index >= 0; --index)
				{
					row.insert(row.begin() + g_TableToBeReplacedByNullForSale[index], _T(""));
				}
			}
		}

		NotificationHighlightCell(m_table[i].first, row, m_pJqGridAPI);
	}
}

void CNotificationPanel::OnUpdateData(int page, int rows, int colIndex, bool bAsc)
{
	if (!m_bIfUpdateTableWhenTableFilter)
	{
		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			break;
		case CNotificationPanel::Approving_SaleBusiness:
		{
			DEFINE_NOTIFICATION_SALE_QUERY_PARAM(jqp);
			MakeBasicSearchCondition(jqp);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_SALE_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CSale::BUSINESS, false);
			CServer::GetInstance()->GetSale().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_SalePlan:
		{
			DEFINE_NOTIFICATION_SALE_QUERY_PARAM(jqp);
			MakeBasicSearchCondition(jqp);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_SALE_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CSale::PLAN, false);
			jqp.AddApproveCondition(CSale::BUSINESS, true);
			CServer::GetInstance()->GetSale().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		{
			DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_PLAN_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
			CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
			CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::scrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
			}

			CServer::GetInstance()->GetPlan().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanSCRQPlan:
		{
			DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
			CUnitedQuery* uq = MakeBasicSearchCondition(jqp);
			CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_PLAN_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
			if (NULL != uq){
				uq->and(UQ(nsPlan::scrq, L"@!=null"));
			}
			else{
				jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
			}
			
			CServer::GetInstance()->GetPlan().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		{
			DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_PLAN_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
			CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
			CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
			}
			
			CServer::GetInstance()->GetPlan().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanBZRQPlan:
		{
			DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
			if (colIndex >= 0){
				jqp.AddSortCondition(TO_PLAN_INDEX(colIndex), bAsc);
			}
			jqp.AddApproveCondition(CPlan::PACK_PLAN, false);
			CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
			CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
			}
		
			CServer::GetInstance()->GetPlan().Query(page, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_END:
			break;
		default:
			break;
		}

		GetParent()->EnableWindow(FALSE);
	}
}


void CNotificationPanel::OnInitChilds()
{
	m_pJqGridAPI->d_OnUpdateData += std::make_pair(this, &CNotificationPanel::OnUpdateData);

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getXsywsh() && !perm.getXsjhsh() && !perm.getJhywsh() && !perm.getJhjhsh() && !perm.getJhbzywsh() && !perm.getJhbzjhsh())
	{
		m_staticPromotion = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_PROMOTION, _T("��û����˵�Ȩ��"), _T("Microsoft YaHei"), 16);
		m_staticPromotion->MoveWindow(20, 27, 500, 20);
		m_staticPromotion->SetTextAlign(DT_LEFT);
		m_pJqGridAPI->HideGrid();
	}
	else
	{
		//����-ҵ��
		m_bsSaleBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEBUSINESSAPPROVE);
		//m_bsSaleBusinessApprove.SetWindowText(_T("Ŀǰ����δ������ ����-ҵ�� ���"));
		m_bsSaleBusinessApprove.SetTextAlign(DT_LEFT);
		m_bsSaleBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsSaleBusinessApprove.MoveWindow(g_StaticPos[Approving_SaleBusiness][0], g_StaticPos[Approving_SaleBusiness][1], g_StaticPos[Approving_SaleBusiness][2], g_StaticPos[Approving_SaleBusiness][3]);

		m_btnSaleBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_SALEBUSINESSAPPROVE);
		m_btnSaleBusinessApprove.SetWindowText(_T("ǰ�����"));
		m_btnSaleBusinessApprove.MoveWindow(g_ButtoncPos[Approving_SaleBusiness][0], g_ButtoncPos[Approving_SaleBusiness][1], g_ButtoncPos[Approving_SaleBusiness][2], g_ButtoncPos[Approving_SaleBusiness][3]);

		m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);

		//����-�ƻ�
		m_bsSalePlanApprove.Create(this, IDC_NOTIFICATION_STATIC_SALEPLANAPPROVE);
		//m_bsSalePlanApprove.SetWindowText(_T("Ŀǰ����δ������ ����-�ƻ� ���"));
		m_bsSalePlanApprove.SetTextAlign(DT_LEFT);
		m_bsSalePlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsSalePlanApprove.MoveWindow(g_StaticPos[Approving_SalePlan][0], g_StaticPos[Approving_SalePlan][1], g_StaticPos[Approving_SalePlan][2], g_StaticPos[Approving_SalePlan][3]);

		m_btnSalePlanApprove.Create(this, IDC_NOTIFICATION_BTN_SALEPLANAPPROVE);
		m_btnSalePlanApprove.SetWindowText(_T("ǰ�����"));
		m_btnSalePlanApprove.MoveWindow(g_ButtoncPos[Approving_SalePlan][0], g_ButtoncPos[Approving_SalePlan][1], g_ButtoncPos[Approving_SalePlan][2], g_ButtoncPos[Approving_SalePlan][3]);

		m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		m_btnSalePlanApprove.ShowWindow(SW_HIDE);

		//�ƻ�-��������-ҵ��
		m_bsPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQBUSINESSAPPROVE);
		//m_bsPlanSCRQBusinessApprove.SetWindowText(_T("Ŀǰ����δ������ �ƻ�-��������-ҵ�� ���"));
		m_bsPlanSCRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanSCRQBusinessApprove.MoveWindow(g_StaticPos[Approving_PlanSCRQBusiness][0], g_StaticPos[Approving_PlanSCRQBusiness][1], g_StaticPos[Approving_PlanSCRQBusiness][2], g_StaticPos[Approving_PlanSCRQBusiness][3]);
		m_bsPlanSCRQBusinessApprove.SetTextAlign(DT_LEFT);

		m_btnPlanSCRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQBUSINESSAPPROVE);
		m_btnPlanSCRQBusinessApprove.SetWindowText(_T("ǰ�����"));
		m_btnPlanSCRQBusinessApprove.MoveWindow(g_ButtoncPos[Approving_PlanSCRQBusiness][0], g_ButtoncPos[Approving_PlanSCRQBusiness][1], g_ButtoncPos[Approving_PlanSCRQBusiness][2], g_ButtoncPos[Approving_PlanSCRQBusiness][3]);

		m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);

		//�ƻ�-��������-�ƻ�
		m_bsPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANSCRQPLANAPPROVE);
		//m_bsPlanSCRQPlanApprove.SetWindowText(_T("Ŀǰ����δ������ �ƻ�-��������-�ƻ� ���"));
		m_bsPlanSCRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanSCRQPlanApprove.MoveWindow(g_StaticPos[Approving_PlanSCRQPlan][0], g_StaticPos[Approving_PlanSCRQPlan][1], g_StaticPos[Approving_PlanSCRQPlan][2], g_StaticPos[Approving_PlanSCRQPlan][3]);
		m_bsPlanSCRQPlanApprove.SetTextAlign(DT_LEFT);

		m_btnPlanSCRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANSCRQPLANAPPROVE);
		m_btnPlanSCRQPlanApprove.SetWindowText(_T("ǰ�����"));
		m_btnPlanSCRQPlanApprove.MoveWindow(g_ButtoncPos[Approving_PlanSCRQPlan][0], g_ButtoncPos[Approving_PlanSCRQPlan][1], g_ButtoncPos[Approving_PlanSCRQPlan][2], g_ButtoncPos[Approving_PlanSCRQPlan][3]);

		m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);

		//�ƻ�-��װ����-ҵ��
		m_bsPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQBUSINESSAPPROVE);
		//m_bsPlanBZRQBusinessApprove.SetWindowText(_T("Ŀǰ����δ������ �ƻ�-��װ����-ҵ�� ���"));
		m_bsPlanBZRQBusinessApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanBZRQBusinessApprove.MoveWindow(g_StaticPos[Approving_PlanBZRQBusiness][0], g_StaticPos[Approving_PlanBZRQBusiness][1], g_StaticPos[Approving_PlanBZRQBusiness][2], g_StaticPos[Approving_PlanBZRQBusiness][3]);
		m_bsPlanBZRQBusinessApprove.SetTextAlign(DT_LEFT);

		m_btnPlanBZRQBusinessApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQBUSINESSAPPROVE);
		m_btnPlanBZRQBusinessApprove.SetWindowText(_T("ǰ�����"));
		m_btnPlanBZRQBusinessApprove.MoveWindow(g_ButtoncPos[Approving_PlanBZRQBusiness][0], g_ButtoncPos[Approving_PlanBZRQBusiness][1], g_ButtoncPos[Approving_PlanBZRQBusiness][2], g_ButtoncPos[Approving_PlanBZRQBusiness][3]);

		m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);

		//�ƻ�-��װ����-�ƻ�
		m_bsPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_STATIC_PLANBZRQPLANAPPROVE);
		//m_bsPlanBZRQPlanApprove.SetWindowText(_T("Ŀǰ����δ������ �ƻ�-��װ����-�ƻ� ���"));
		m_bsPlanBZRQPlanApprove.SetBSFont(_T("Microsoft YaHei"), 12);
		m_bsPlanBZRQPlanApprove.MoveWindow(g_StaticPos[Approving_PlanBZRQPlan][0], g_StaticPos[Approving_PlanBZRQPlan][1], g_StaticPos[Approving_PlanBZRQPlan][2], g_StaticPos[Approving_PlanBZRQPlan][3]);
		m_bsPlanBZRQPlanApprove.SetTextAlign(DT_LEFT);

		m_btnPlanBZRQPlanApprove.Create(this, IDC_NOTIFICATION_BTN_PLANBZRQPLANAPPROVE);
		m_btnPlanBZRQPlanApprove.SetWindowText(_T("ǰ�����"));
		m_btnPlanBZRQPlanApprove.MoveWindow(g_ButtoncPos[Approving_PlanBZRQPlan][0], g_ButtoncPos[Approving_PlanBZRQPlan][1], g_ButtoncPos[Approving_PlanBZRQPlan][2], g_ButtoncPos[Approving_PlanBZRQPlan][3]);

		m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
		m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);

		//Second page 
		//first line
		m_bsDateRange = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_DATERANGE, _T("��ѯ����"), _T("Microsoft YaHei"), 12);
		m_bsDateRange->MoveWindow(20, 25, 60, 20);
		m_bsDateRange->SetTextAlign(DT_LEFT);

		m_dtcSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_NOTIFICATION_DATETIME_SEARCHFROM, _T("Microsoft YaHei"), 12);
		m_dtcSearchFrom->MoveWindow(210 - 120, 25, 108, 20);

		COleDateTime oletimeTime;
		oletimeTime.SetStatus(COleDateTime::null);
		m_dtcSearchFrom->SetTime(oletimeTime);

		m_bsMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_MIDDLELINE, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsMiddleLine->MoveWindow(325 - 120, 25, 20, 20);

		m_dtcSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_NOTIFICATION_DATETIME_SEARCHTO, _T("Microsoft YaHei"), 12);
		m_dtcSearchTo->MoveWindow(350 - 120, 25, 108, 20);
		m_dtcSearchTo->SetTime(oletimeTime);

		m_editSearch = Util_Tools::Util::CreateEdit(this, IDC_NOTIFICATION_EDIT_SEARCH, _T("������ؼ���"), _T("Microsoft YaHei"), 12);
		m_editSearch->MoveWindow(470 - 120, 25, 150, 20);
		m_editSearch->ShowWindow(SW_HIDE);

		m_btnMore = Util_Tools::Util::CreateButton(this, IDC_NOTIFICATION_BTN_MORE, _T("����ɸѡ"), _T("Microsoft YaHei"), 12);
		m_btnMore->MoveWindow(640 - 120, 23, 90, 25);

		m_btnSearch = Util_Tools::Util::CreateButton(this, IDC_NOTIFICATION_BTN_SEARCH, _T("��ѯ"), _T("Microsoft YaHei"), 12);
		m_btnSearch->MoveWindow(750 - 120, 23, 90, 25);

		//second line
		m_btnReturnToFirst.Create(this, IDC_NOTIFICATION_BTN_RETURN);
		m_btnReturnToFirst.SetWindowText(_T("����"));
		m_btnReturnToFirst.MoveWindow(20, 70, 90, 25);
		m_btnReturnToFirst.ShowWindow(SW_HIDE);

		m_btnApproveInSecond.Create(this, IDC_NOTIFICATION_BTN_APPROVE);
		m_btnApproveInSecond.SetWindowText(_T("���"));
		m_btnApproveInSecond.MoveWindow(130, 70, 90, 25);
		m_btnApproveInSecond.ShowWindow(SW_HIDE);
		m_btnApproveInSecond.EnableWindow(FALSE);


		m_btnTableFilter.Create(this, IDC_NOTIFICATION_BTN_TABFILTER);
		m_btnTableFilter.SetWindowText(_T("��������"));
		m_btnTableFilter.MoveWindow(750 - 120, 70, 90, 25);
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
	ON_WM_NCDESTROY()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_SEARCH, &CNotificationPanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_NOTIFICATION_BTN_MORE, &CNotificationPanel::OnBnClickedMore)
END_MESSAGE_MAP()

void CNotificationPanel::OnBnClickedSearch()
{
	//m_pJqGridAPI->UncheckedAll();
	//m_advanceSearchVals.clear();
	m_pJqGridAPI->CancelSort();
	//DEFINE_NOTIFICATION_SALE_QUERY_PARAM(jqp);
	CJsonQueryParam jqp;

	CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);


// 	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), sqp)
// 		.then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));

	switch (m_enumCurrentApprovingItem)
	{
	case CNotificationPanel::Approving_NULL:
		break;
	case CNotificationPanel::Approving_SaleBusiness:
	{
		MAKE_SALE_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CSale::BUSINESS, false);
		CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_SalePlan:
	{
		MAKE_SALE_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CSale::PLAN, false);
		jqp.AddApproveCondition(CSale::BUSINESS, true);
		CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_PlanSCRQBusiness:
	{
		CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
		MAKE_PLAN_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
		if (NULL != pUq)
		{
			pUq->and(UQ(nsPlan::scrq, L"@!=null"));
		}
		else
		{
			jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
		}
		CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_PlanSCRQPlan:
	{
		CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
		MAKE_PLAN_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
		
		if (NULL != pUq)
		{
			pUq->and(UQ(nsPlan::scrq, L"@!=null"));
		}
		else
		{
			jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
		}
		CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_PlanBZRQBusiness:
	{
		CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
		MAKE_PLAN_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);

		if (NULL != pUq)
		{
			pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
		}
		else
		{
			jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
		}
		CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_PlanBZRQPlan:
	{
		CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
		MAKE_PLAN_QUERY_PARAM(jqp);
		jqp.AddApproveCondition(CPlan::PACK_PLAN, false);

		if (NULL != pUq)
		{
			pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
		}
		else
		{
			jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
		}
		CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
		break;
	}
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}

	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("�߼�����"));
	dlg.SetIfUseDefaultValue(false);
	
	if (m_advanceSearchVals.size() <= 0)
	{
		dlg.SetOption(new CSaleAddDlg::Option_t());
	}
	else
	{
		if (Approving_SaleBusiness != m_enumCurrentApprovingItem &&
			Approving_SalePlan != m_enumCurrentApprovingItem){
			m_advanceSearchVals.erase(m_advanceSearchVals.begin() + nsPlan::cg);
		}
		dlg.SetOption(new CSaleAddDlg::Option_t(m_advanceSearchVals));
	}

	auto_ptr<CTempCleaner> ptc;
	if (IDOK == dlg.DoModal()){
		m_advanceSearchVals = const_cast<std::vector<CString>&>(dlg.GetResult());
		m_pJqGridAPI->CancelSort();
		CJsonQueryParam jqp;
		CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
		if (Approving_SaleBusiness != m_enumCurrentApprovingItem &&
			Approving_SalePlan != m_enumCurrentApprovingItem){
			m_advanceSearchVals.insert(m_advanceSearchVals.begin() + nsPlan::cg, L"");
			ptc.reset(new CTempCleaner(m_advanceSearchVals, nsPlan::ggxh));
		}
	
// 		switch (m_enumCurrentApprovingItem)
// 		{
// 		case CNotificationPanel::Approving_NULL:
// 			break;
// 		case CNotificationPanel::Approving_SaleBusiness:
// 		case CNotificationPanel::Approving_SalePlan:
// 		{
// 			CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
// 			break;
// 		}
// 		case CNotificationPanel::Approving_PlanSCRQBusiness:
// 		case CNotificationPanel::Approving_PlanSCRQPlan:
// 		case CNotificationPanel::Approving_PlanBZRQBusiness:
// 		case CNotificationPanel::Approving_PlanBZRQPlan:
// 		{
// 			CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
// 			break;
// 		}
// 		case CNotificationPanel::Approving_END:
// 			break;
// 		default:
// 			break;
// 		}

		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			break;
		case CNotificationPanel::Approving_SaleBusiness:
		{
			MAKE_SALE_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CSale::BUSINESS, false);
			CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_SalePlan:
		{
			MAKE_SALE_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CSale::PLAN, false);
			jqp.AddApproveCondition(CSale::BUSINESS, true);
			CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		{
			MAKE_PLAN_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::scrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
			}
			CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanSCRQPlan:
		{
			MAKE_PLAN_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
			
			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::scrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
			}
			CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		{
			MAKE_PLAN_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);

			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
			}
			CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_PlanBZRQPlan:
		{
			MAKE_PLAN_QUERY_PARAM(jqp);
			jqp.AddApproveCondition(CPlan::PACK_PLAN, false);

			if (NULL != pUq)
			{
				pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
			}
			else
			{
				jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
			}
			CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CNotificationSearchListener(*this, m_table, m_pJqGridAPI.get()));
			break;
		}
		case CNotificationPanel::Approving_END:
			break;
		default:
			break;
		}

		GetParent()->EnableWindow(FALSE);
	}
}

CUnitedQuery* CNotificationPanel::MakeBasicSearchCondition(CJsonQueryParam &sqp)
{
	CUnitedQuery* pUq = NULL;
	int iCountShot = 0;
	CString searchText;
	m_editSearch->GetWindowText(searchText);

	if (!searchText.IsEmpty()){
		sqp.SetBasicSearchCondition(searchText, false);
	}

	CString strAdvanceCondition;
	CString strFrom;
	CString strTo;
	bool bHasFrom = false;
	bool bHasTo = false;
	CTime time;

	DWORD dwResult = m_dtcSearchFrom->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasFrom = true;
		m_dtcSearchFrom->GetWindowText(strFrom);
	}
	else
	{
		strFrom = L"";
	}

	dwResult = m_dtcSearchTo->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		bHasTo = true;
		m_dtcSearchTo->GetWindowText(strTo);
	}
	else
	{
		strTo = L"";
	}

	if (bHasFrom || bHasTo)
	{
		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			break;
		case CNotificationPanel::Approving_SaleBusiness:
		case CNotificationPanel::Approving_SalePlan:
		{
			sqp.SetDateSearchCondition(strFrom, strTo);
			break;
		}
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		case CNotificationPanel::Approving_PlanSCRQPlan:
		{
			Util_Tools::Util::MakeDateQueryCommand(bHasFrom, bHasTo, strFrom, strTo, strAdvanceCondition);

			//CUnitedQuery* pUq = NULL;
			if (!strAdvanceCondition.IsEmpty())
			{
				pUq = &UQ(nsPlan::scrq, strAdvanceCondition);
				if (NULL != pUq)
				{
					sqp.SetUnitedQuery(*pUq);
				}
			}

			

	
			break;
		}
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		case CNotificationPanel::Approving_PlanBZRQPlan:
		{
			Util_Tools::Util::MakeDateQueryCommand(bHasFrom, bHasTo, strFrom, strTo, strAdvanceCondition);

			//CUnitedQuery* pUq = NULL;
			if (!strAdvanceCondition.IsEmpty())
			{
				pUq = &UQ(nsPlan::bzrq, strAdvanceCondition);
				if (NULL != pUq)
				{
					sqp.SetUnitedQuery(*pUq);
				}
			}



	
			break;
		}
		case CNotificationPanel::Approving_END:
			break;
		default:
			break;
		}
	}

	if (!m_advanceSearchVals.empty())
	{
		CString strGgxh = m_advanceSearchVals[nsPlan::ggxh];
		if (!strGgxh.IsEmpty())
		{
			strGgxh = strGgxh.Mid(1);
			if (!strGgxh.IsEmpty())
			{
				if (NULL == pUq)
				{
					pUq = &UQ(nsPlan::ggxh, L"@like " + strGgxh);
				}
				else
				{
					pUq->and(UQ(nsPlan::ggxh, L"@like " + strGgxh));
				}
			}
		}
	}

	if (NULL != pUq)
	{
		sqp.SetUnitedQuery(*pUq);
	}

	sqp.SetAdvancedCondition(&m_advanceSearchVals);
	return pUq;

}

void CNotificationPanel::OnBnClickedBtnReturn()
{
	m_pJqGridAPI->HideGrid();
		
	OnInitData();
	//HideFirstViewOfNotificationPanel(TRUE);

	m_enumCurrentApprovingItem = Approving_NULL;
}

void CNotificationPanel::OnBnClickedBtnApprove()
{
	//update status to DB

	GetParent()->EnableWindow(FALSE);

	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	INT_PTR dlgResult = IDCANCEL;
	
	bool bIfUpdateSaleInfo = false;
	vector<CString> resultRow;

	switch (m_enumCurrentApprovingItem)
	{
	case CNotificationPanel::Approving_NULL:
		break;
	case CNotificationPanel::Approving_SaleBusiness:
	case CNotificationPanel::Approving_SalePlan:
	{
		bIfUpdateSaleInfo = true;

		std::auto_ptr<CNotificationAddDlgForSale::Option_t> pstOpt;
		CNotificationAddDlgForSale dlg(_T("�������"));

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
					pstOpt.reset(new CNotificationAddDlgForSale::Option_t(*pRowData));
				}
				else
				{
					pstOpt->Merge(*pRowData);
				}
			}
		}

		dlg.SetOption(pstOpt.get());

		dlgResult = dlg.DoModal();

		if (IDOK == dlgResult)
		{
			resultRow = dlg.GetResult();
		}

		break;
	}

	case CNotificationPanel::Approving_PlanSCRQBusiness:
	case CNotificationPanel::Approving_PlanSCRQPlan:
	case CNotificationPanel::Approving_PlanBZRQBusiness:
	case CNotificationPanel::Approving_PlanBZRQPlan:
	{
		std::auto_ptr<CNotificationAddDlgForPlan::Option_t> pstOpt;
		CNotificationAddDlgForPlan dlg(_T("�ƻ����"));


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
					pstOpt.reset(new CNotificationAddDlgForPlan::Option_t(*pRowData));
				}
				else
				{
					pstOpt->Merge(*pRowData);
				}
			}
		}

		dlg.SetOption(pstOpt.get());

		dlgResult = dlg.DoModal();

		break;
	}
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}

	if (IDOK == dlgResult)
	{
		//ͬ���޸���Ϣ�����������ʱ????
		if (bIfUpdateSaleInfo)
		{
			class CUpdateListener : public CPromise<bool>::IHttpResponse{
				CONSTRUCTOR_3(CUpdateListener, CNotificationPanel&, notificationPanel, StringArray, cacheRow, IntArray, checkedRows)
			public:
				virtual void OnSuccess(bool& ret){
					if (ret)
					{
						m_notificationPanel.Approve(m_checkedRows);
					}
					else
					{
						m_notificationPanel.MessageBox(_T("�޸�����ʧ��"), _T("����"), MB_OK | MB_ICONWARNING);
						m_notificationPanel.GetParent()->EnableWindow(TRUE);
					}
				}
				virtual void OnFailed(){
					m_notificationPanel.MessageBox(_T("�������"), _T("����"), MB_OK | MB_ICONWARNING);
					m_notificationPanel.GetParent()->EnableWindow(TRUE);
				}
			};

			CServer::GetInstance()->GetSale().Update(checkedRows, resultRow).then(new CUpdateListener(*this, resultRow, checkedRows));
		}
		else
		{
			Approve(checkedRows);
		}
	}
}

void CNotificationPanel::OnBnClickedBtnTableFilter()
{
	m_bIfUpdateTableWhenTableFilter = true;


	if (NULL != m_pTableFilterForSale && NULL != m_pTableFilterForPlan)
	{
		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			return;
		case CNotificationPanel::Approving_SaleBusiness:
		case CNotificationPanel::Approving_SalePlan:
			if (IDOK == m_pTableFilterForSale->DoModal())
			{
			}
			break;
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		case CNotificationPanel::Approving_PlanSCRQPlan:
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		case CNotificationPanel::Approving_PlanBZRQPlan:
			if (IDOK == m_pTableFilterForPlan->DoModal())
			{
			}
			break;
		case CNotificationPanel::Approving_END:
			return;
		default:
			return;
		}
	}


	m_bIfUpdateTableWhenTableFilter = false;
}

void CNotificationPanel::OnBnClickedSaleBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_SaleBusiness;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��������"));

	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	DEFINE_NOTIFICATION_SALE_QUERY_PARAM(jqp);
	MakeBasicSearchCondition(jqp);
	jqp.AddApproveCondition(CSale::BUSINESS, false);

	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));

	/*CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/query/business/unapproved"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEBUSINESS);*/
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedSalePlanApprove()
{
	m_enumCurrentApprovingItem = Approving_SalePlan;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��������"));

	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	DEFINE_NOTIFICATION_SALE_QUERY_PARAM(jqp);
	MakeBasicSearchCondition(jqp);
	jqp.AddApproveCondition(CSale::PLAN, false);
	jqp.AddApproveCondition(CSale::BUSINESS, true);
	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));
	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/sale/query/plan/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_SALEPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQBusiness;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��������"));

	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
	CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
	CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
	jqp.AddApproveCondition(CPlan::PLAN_BUSINESS, false);
	if (NULL != pUq)
	{
		pUq->and(UQ(nsPlan::scrq, L"@!=null"));
	}
	else
	{
		jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
	}

	
	CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_businessApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanSCRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanSCRQPlan;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��������"));

	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
	jqp.AddApproveCondition(CPlan::PLAN_PLAN, false);
	CUnitedQuery* pUq = MakeBasicSearchCondition(jqp); 
	CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
	if (NULL != pUq)
	{
		pUq->and(UQ(nsPlan::scrq, L"@!=null"));
	}
	else
	{
		jqp.SetUnitedQuery(UQ(nsPlan::scrq, L"@!=null"));
	}
	CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/plan_planApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANSCRQPLAN);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQBusinessApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQBusiness;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��װ����"));

	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);
	DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);

	jqp.AddApproveCondition(CPlan::PACK_BUSINESS, false);
	CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
	CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
	if (NULL != pUq)
	{
		pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
	}
	else
	{
		jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
	}
	
	CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));

	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/pack_businessApprove/unapproved"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_UNAPPROVED_PLANBZRQBUSINESS);
	GetParent()->EnableWindow(FALSE);
}

void CNotificationPanel::OnBnClickedPlanBZRQPlanApprove()
{
	m_enumCurrentApprovingItem = Approving_PlanBZRQPlan;
	m_advanceSearchVals.clear();
	m_editSearch->SetWindowTextW(_T(""));

	m_bsDateRange->SetWindowTextW(_T("��װ����"));
	
	COleDateTime oletimeTime;
	oletimeTime.SetStatus(COleDateTime::null);
	m_dtcSearchFrom->SetTime(oletimeTime);
	m_dtcSearchTo->SetTime(oletimeTime);

	m_pJqGridAPI->ShowGrid();
	HideFirstViewOfNotificationPanel(FALSE);

	DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(jqp);
	jqp.AddApproveCondition(CPlan::PACK_PLAN, false);
	CUnitedQuery* pUq = MakeBasicSearchCondition(jqp);
	CTempCleaner tc(m_advanceSearchVals, nsPlan::ggxh);
	if (NULL != pUq)
	{
		pUq->and(UQ(nsPlan::bzrq, L"@!=null"));
	}
	else
	{
		jqp.SetUnitedQuery(UQ(nsPlan::bzrq, L"@!=null"));
	}

	CServer::GetInstance()->GetPlan().Query(1, m_pJqGridAPI->GetPageSize(), jqp).then(new CQueryListener(*this, m_table, m_pJqGridAPI.get()));

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

		HideChild(m_bsDateRange);
		HideChild(m_bsMiddleLine);
		HideChild(m_dtcSearchFrom);
		HideChild(m_dtcSearchTo);
		HideChild(this->m_editSearch);
		HideChild(m_btnSearch);
		HideChild(m_btnMore);
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

		ShowChild(m_bsDateRange);
		ShowChild(m_bsMiddleLine);
		ShowChild(m_dtcSearchFrom);
		ShowChild(m_dtcSearchTo);
		ShowChild(m_editSearch);
		ShowChild(m_btnSearch);
		ShowChild(m_btnMore);
	}
}

void CNotificationPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	m_pJqGridAPI->HideGrid();
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
//	m_bIfUpdateTableWhenTableFilter = true;

// 	if ((m_enumCurrentApprovingItem == Approving_SaleBusiness) || (m_enumCurrentApprovingItem == Approving_SalePlan))
// 	{
// 		AdjustTableStyleForSale();
// 	} 
// 	else
// 	{
// 		AdjustTableStyleForPlan();
// 	}

//	m_bIfUpdateTableWhenTableFilter = false;

	
	CTableFilterDlgForNotificationSale *objTableFilterForSale();
	CTableFilterDlgForNotificationPlan *objTableFilterForPlan();

	if (NULL != m_pTableFilterForSale)
	{
		delete m_pTableFilterForSale;
		m_pTableFilterForSale = NULL;
	}

	m_pTableFilterForSale = new CTableFilterDlgForNotificationSale(_T("��������"));

	if (NULL != m_pTableFilterForPlan)
	{
		delete m_pTableFilterForPlan;
		m_pTableFilterForPlan = NULL;
	}

	m_pTableFilterForPlan = new CTableFilterDlgForNotificationPlan(_T("��������"));

	if (NULL != m_pTableFilterForSale && NULL != m_pTableFilterForPlan)
	{
		switch (m_enumCurrentApprovingItem)
		{
		case CNotificationPanel::Approving_NULL:
			return;
		case CNotificationPanel::Approving_SaleBusiness:
		case CNotificationPanel::Approving_SalePlan:
			m_pTableFilterForSale->Initialize(m_pJqGridAPI.get());
			break;
		case CNotificationPanel::Approving_PlanSCRQBusiness:
		case CNotificationPanel::Approving_PlanSCRQPlan:
		case CNotificationPanel::Approving_PlanBZRQBusiness:
		case CNotificationPanel::Approving_PlanBZRQPlan:
			m_pTableFilterForPlan->Initialize(m_pJqGridAPI.get());
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
		//m_staticPromotion = Util_Tools::Util::CreateStatic(this, IDC_NOTIFICATION_STATIC_PROMOTION, _T("��û����˵�Ȩ��"), _T("Microsoft YaHei"), 16);
		//m_staticPromotion->MoveWindow(20, 27, 500, 20);
		//m_staticPromotion->SetTextAlign(DT_LEFT);
		//m_pJqGridAPI->HideGrid();
	}
	else
	{
		m_advanceSearchVals.clear();

		HideFirstViewOfNotificationPanel(TRUE);
		CString strRet;
		//��ȡδ��������
		CNotification::Unapproved_t stUnapproved = {};
		CServer::GetInstance()->GetNotification().GetUnapprovedSync(stUnapproved);
		//m_pHttp->SyncGet(_T("http://localhost:8080/BlueRay/notification/unapproved"), strRet);
		OnReturnApprovedNum(stUnapproved);
	}
}

void CNotificationPanel::OnReturnApprovedNum(CNotification::Unapproved_t& stUnapproved)
{
	Json::JsonParser parser;
	int iPackBussiness = stUnapproved.iPackBussiness; //���-ҵ��δ������
	int iPackPlan = stUnapproved.iPackPlan;//���-�ƻ�δ������
	int iPlanBussiness = stUnapproved.iPlanBussiness;//�ƻ�-ҵ��δ������
	int iPlanPlan = stUnapproved.iPlanPlan;//�ƻ�-�ƻ�δ������
	int iSaleBussiness = stUnapproved.iSaleBussiness;//����-ҵ��δ������
	int iSalePlan = stUnapproved.iSalePlan;//����-�ƻ�δ������

	CString strSaleBussiness;
	strSaleBussiness.Format(_T("���� %3d�� δ��˵� ������ҵ�񲿣�"), iSaleBussiness);
	m_bsSaleBusinessApprove.SetWindowText(strSaleBussiness);

	int iPosIndex = 0;

	CPermission& perm = CUser::GetInstance()->GetPermission();
	bool bHasSp = false;
	if (0 < iSaleBussiness && perm.getXsywsh())
	{
		m_bsSaleBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnSaleBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		
		ShowChild(&m_bsSaleBusinessApprove);
		ShowChild(&m_btnSaleBusinessApprove);
		//m_bsSaleBusinessApprove.ShowWindow(SW_SHOW);
		//m_btnSaleBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_bsSaleBusinessApprove);
		HideChild(&m_btnSaleBusinessApprove);

		//m_bsSaleBusinessApprove.ShowWindow(SW_HIDE);
		//m_btnSaleBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strSalePlan;
	strSalePlan.Format(_T("���� %3d�� δ��˵� �������ƻ��ƣ�"), iSalePlan);
	m_bsSalePlanApprove.SetWindowText(strSalePlan);

	if (0 < iSalePlan && perm.getXsjhsh())
	{
		m_bsSalePlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnSalePlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;

		ShowChild(&m_bsSalePlanApprove);
		ShowChild(&m_btnSalePlanApprove);
		//m_bsSalePlanApprove.ShowWindow(SW_SHOW);
		//m_btnSalePlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_btnSalePlanApprove);
		HideChild(&m_bsSalePlanApprove);
		//m_bsSalePlanApprove.ShowWindow(SW_HIDE);
		//m_btnSalePlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanBussiness;
	strPlanBussiness.Format(_T("���� %3d�� δ��˵� �������ڣ�ҵ�񲿣�"), iPlanBussiness);
	m_bsPlanSCRQBusinessApprove.SetWindowText(strPlanBussiness);

	if (0 < iPlanBussiness && perm.getJhywsh())
	{
		m_bsPlanSCRQBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanSCRQBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		ShowChild(&m_bsPlanSCRQBusinessApprove);
		ShowChild(&m_btnPlanSCRQBusinessApprove);
		//m_bsPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		//m_btnPlanSCRQBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_bsPlanSCRQBusinessApprove);
		HideChild(&m_btnPlanSCRQBusinessApprove);
		//m_bsPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
		//m_btnPlanSCRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPlanPlan;
	strPlanPlan.Format(_T("���� %3d�� δ��˵� �������ڣ��ƻ��ƣ�"), iPlanPlan);
	m_bsPlanSCRQPlanApprove.SetWindowText(strPlanPlan);

	if (0 < iPlanPlan && perm.getJhjhsh())
	{
		m_bsPlanSCRQPlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanSCRQPlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		ShowChild(&m_btnPlanSCRQPlanApprove);
		ShowChild(&m_bsPlanSCRQPlanApprove);

		//m_bsPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		//m_btnPlanSCRQPlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_bsPlanSCRQPlanApprove);
		HideChild(&m_btnPlanSCRQPlanApprove);
		//m_bsPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
		//m_btnPlanSCRQPlanApprove.ShowWindow(SW_HIDE);
	}

	CString strPackBussiness;
	strPackBussiness.Format(_T("���� %3d�� δ��˵� ��װ���ڣ�ҵ�񲿣�"), iPackBussiness);
	m_bsPlanBZRQBusinessApprove.SetWindowText(strPackBussiness);

	if (0 < iPackBussiness && perm.getJhbzywsh())
	{
		m_bsPlanBZRQBusinessApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanBZRQBusinessApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		ShowChild(&m_bsPlanBZRQBusinessApprove);
		ShowChild(&m_btnPlanBZRQBusinessApprove);

		//m_bsPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		//m_btnPlanBZRQBusinessApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_btnPlanBZRQBusinessApprove);
		HideChild(&m_bsPlanBZRQBusinessApprove);

		//m_bsPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
		//m_btnPlanBZRQBusinessApprove.ShowWindow(SW_HIDE);
	}

	CString strPackPlan;
	strPackPlan.Format(_T("���� %3d�� δ��˵� ��װ���ڣ��ƻ��ƣ�"), iPackPlan);
	m_bsPlanBZRQPlanApprove.SetWindowText(strPackPlan);

	if (0 < iPackPlan && perm.getJhbzjhsh())
	{
		m_bsPlanBZRQPlanApprove.MoveWindow(g_StaticPos[iPosIndex][0], g_StaticPos[iPosIndex][1], g_StaticPos[iPosIndex][2], g_StaticPos[iPosIndex][3]);
		m_btnPlanBZRQPlanApprove.MoveWindow(g_ButtoncPos[iPosIndex][0], g_ButtoncPos[iPosIndex][1], g_ButtoncPos[iPosIndex][2], g_ButtoncPos[iPosIndex][3]);
		iPosIndex++;
		ShowChild(&m_btnPlanBZRQPlanApprove);
		ShowChild(&m_bsPlanBZRQPlanApprove);
		//m_bsPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
		//m_btnPlanBZRQPlanApprove.ShowWindow(SW_SHOW);
		bHasSp = true;
	}
	else
	{
		HideChild(&m_bsPlanBZRQPlanApprove);
		HideChild(&m_btnPlanBZRQPlanApprove);
		//m_bsPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
		//m_btnPlanBZRQPlanApprove.ShowWindow(SW_HIDE);
	}

	m_advanceSearchVals.clear();
}


bool CNotificationPanel::IsSaleApproving()
{
	bool bRet = false;
	switch (m_enumCurrentApprovingItem)
	{
	case CNotificationPanel::Approving_NULL:
		break;
	case CNotificationPanel::Approving_SaleBusiness:
	case CNotificationPanel::Approving_SalePlan:
	{
		bRet = true;
		break;
	}
	case CNotificationPanel::Approving_PlanSCRQBusiness:
	case CNotificationPanel::Approving_PlanSCRQPlan:
	case CNotificationPanel::Approving_PlanBZRQBusiness:
	case CNotificationPanel::Approving_PlanBZRQPlan:
	{
		bRet = false;
		break;
	}
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}

	return bRet;
}

void CNotificationPanel::Approve(std::vector<int>& checkedRows)
{
	class CApproveListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_2(CApproveListener, CNotificationPanel&, panel, CJQGridAPI*, pJqGridAPI)
	public:
		virtual void OnSuccess(StringArray& arrRet){
			std::vector<int> checkedRows;
			m_pJqGridAPI->GetCheckedRows(checkedRows);
			CString strFmt;
			strFmt.Format(L"%d �����ʧ�� \r\n", arrRet.size());
			std::vector<int>::iterator it;
			StringArray row;
			for (int i = 0; i < arrRet.size(); ++i)
			{
				it = std::find(checkedRows.begin(), checkedRows.end(), _tstoi(arrRet[i]));
				if (it != checkedRows.end())
				{
					m_pJqGridAPI->GetRow(*it, row);
					strFmt += row[0] + L" ";
					checkedRows.erase(it);
					row.clear();
				}
			}

			CString strFmtTmp;
			strFmtTmp.Format(L"%d ����˳ɹ� \r\n", checkedRows.size());
			for (int i = 0; i < checkedRows.size(); ++i)
			{
				m_pJqGridAPI->GetRow(checkedRows[i], row);
				strFmtTmp += row[0] + L" ";
				row.clear();
			}

			strFmt = strFmtTmp + L"\r\n" + strFmt;

			m_panel.MessageBox(strFmt, _T("��˽��"), MB_OK | MB_ICONWARNING);
			//m_panel.OnBnClickedBtnReturn();

			switch (m_panel.m_enumCurrentApprovingItem)
			{
			case CNotificationPanel::Approving_NULL:
				m_panel.OnBnClickedBtnReturn();
				break;
			case CNotificationPanel::Approving_SaleBusiness:
				m_panel.OnBnClickedSaleBusinessApprove();
				break;
			case CNotificationPanel::Approving_SalePlan:
				m_panel.OnBnClickedSalePlanApprove();
				break;
			case CNotificationPanel::Approving_PlanSCRQBusiness:
				m_panel.OnBnClickedPlanSCRQBusinessApprove();
				break;
			case CNotificationPanel::Approving_PlanSCRQPlan:
				m_panel.OnBnClickedPlanSCRQPlanApprove();
				break;
			case CNotificationPanel::Approving_PlanBZRQBusiness:
				m_panel.OnBnClickedPlanBZRQBusinessApprove();
				break;
			case CNotificationPanel::Approving_PlanBZRQPlan:
				m_panel.OnBnClickedPlanBZRQPlanApprove();
				break;
			case CNotificationPanel::Approving_END:
				m_panel.OnBnClickedBtnReturn();
				break;
			default:
				m_panel.OnBnClickedBtnReturn();
				break;
			}

			m_panel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("���ʧ��"), _T("��˽��"), MB_OK | MB_ICONWARNING);
			//m_panel.OnBnClickedBtnReturn();

			switch (m_panel.m_enumCurrentApprovingItem)
			{
			case CNotificationPanel::Approving_NULL:
				m_panel.OnBnClickedBtnReturn();
				break;
			case CNotificationPanel::Approving_SaleBusiness:
				m_panel.OnBnClickedSaleBusinessApprove();
				break;
			case CNotificationPanel::Approving_SalePlan:
				m_panel.OnBnClickedSalePlanApprove();
				break;
			case CNotificationPanel::Approving_PlanSCRQBusiness:
				m_panel.OnBnClickedPlanSCRQBusinessApprove();
				break;
			case CNotificationPanel::Approving_PlanSCRQPlan:
				m_panel.OnBnClickedPlanSCRQPlanApprove();
				break;
			case CNotificationPanel::Approving_PlanBZRQBusiness:
				m_panel.OnBnClickedPlanBZRQBusinessApprove();
				break;
			case CNotificationPanel::Approving_PlanBZRQPlan:
				m_panel.OnBnClickedPlanBZRQPlanApprove();
				break;
			case CNotificationPanel::Approving_END:
				m_panel.OnBnClickedBtnReturn();
				break;
			default:
				m_panel.OnBnClickedBtnReturn();
				break;
			}

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
		CServer::GetInstance()->GetSale().Approve(CSale::BUSINESS, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_SalePlan:
		//url.Format(_T("http://%s:8080/BlueRay/sale/approve/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetSale().Approve(CSale::PLAN, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_PlanSCRQBusiness:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/business"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PLAN_BUSINESS, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_PlanSCRQPlan:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PLAN_PLAN, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_PlanBZRQBusiness:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/business"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PACK_BUSINESS, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_PlanBZRQPlan:
		//url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/plan"), IDS_HOST_NAME);
		CServer::GetInstance()->GetPlan().Approve(CPlan::PACK_PLAN, checkedRows).then(new CApproveListener(*this, m_pJqGridAPI.get()));
		break;
	case CNotificationPanel::Approving_END:
		break;
	default:
		break;
	}
}
