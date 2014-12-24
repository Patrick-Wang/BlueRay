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
		{ 980, 70, 140, 25 },
		{ 820, 70, 140, 25 },
		{ 660, 70, 140, 25 },
		{ 500, 70, 140, 25 }
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
	ON_CBN_SELCHANGE(IDC_PLAN_COMBO_PROSTATUS, &CPlanPanel::OnCbnSelchangeProductionStatus)
END_MESSAGE_MAP()


CPlanPanel::CPlanPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: CBRPanel(pJqGridAPI, pHttp)
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

{
	m_tableFilterDlg.Initialize(m_pJqGridAPI.get(), Page_Plan);
}


CPlanPanel::~CPlanPanel()
{
}

void CPlanPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getPlan())
	{
		m_pJqGridAPI->HideGrid();
	}
}

void CPlanPanel::OnCbnSelchangeProductionStatus()
{
	int iIndex = m_comboProductionStatus->GetCurSel();

	if (0 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_All);
	}
	else if (1 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_ToBePlan);
	}
	else if (2 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_Planning);
	}
	else if (3 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_Planned);
	}
}

void CPlanPanel::FilterTableByStatus(enumProductionStatusForPlan productionStatus)
{
	std::vector<int> vecAll;
	std::vector<int> vecToBePlaned;
	std::vector<int> vecPlanning;
	std::vector<int> vecPlanned;

	for (int j = 0; j < m_table.size(); ++j)
	{
		bool bIfPlanning = false;
		bool bIfAnyItemApproved = false;

		if (_T("√") == m_table[j].second[17])
		{
			bIfPlanning = true;
			bIfAnyItemApproved = true;
		}

		if (_T("√") == m_table[j].second[18])
		{
			bIfPlanning = true;
			bIfAnyItemApproved = true;
		}

		if (_T("√") == m_table[j].second[20])
		{
			bIfPlanning = true;
			bIfAnyItemApproved = true;
		}

		if (_T("√") == m_table[j].second[21])
		{
			bIfPlanning = true;
			bIfAnyItemApproved = true;
		}

		if (!bIfAnyItemApproved)
		{
			vecToBePlaned.push_back(m_table[j].first);
		}
		else
		{
			if (bIfPlanning)
			{
				vecPlanning.push_back(m_table[j].first);
			}
			else
			{
				vecPlanned.push_back(m_table[j].first);
			}
		}

		vecAll.push_back(m_table[j].first);
	}

	if (ProductionStatus_All == productionStatus)
	{
		for (int j = 0; j < vecAll.size(); ++j)
		{
			m_pJqGridAPI->ShowRow(vecAll[j]);
		}
	}
	else
	{
		for (int i = 1; i <= m_table.size(); i++)
		{
			m_pJqGridAPI->HideRow(i);
		}

		if (ProductionStatus_ToBePlan == productionStatus)
		{
			for (int j = 0; j < vecToBePlaned.size(); ++j)
			{
				m_pJqGridAPI->ShowRow(vecToBePlaned[j]);
			}
		}
		else if (ProductionStatus_Planning == productionStatus)
		{
			for (int j = 0; j < vecPlanning.size(); ++j)
			{
				m_pJqGridAPI->ShowRow(vecPlanning[j]);
			}
		}
		else if (ProductionStatus_Planned == productionStatus)
		{
			for (int j = 0; j < vecPlanned.size(); ++j)
			{
				m_pJqGridAPI->ShowRow(vecPlanned[j]);
			}
		}
	}
}

void CPlanPanel::OnInitChilds()
{
	CString strJsonWidths;
	if (CSettingManager::GetInstance()->GetColWidths(L"planCol", strJsonWidths))
	{
		m_pJqGridAPI->SetWidths(strJsonWidths);
	}

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
		m_staticProductionStatus = Util_Tools::Util::CreateStatic(this, IDC_PLAN_STATIC_PROSTATUS, _T("根据订单状态筛选"), _T("Microsoft YaHei"), 12);
		m_staticProductionStatus->MoveWindow(20, 27, 120, 20);
		m_staticProductionStatus->SetTextAlign(DT_LEFT);

		m_comboProductionStatus = Util_Tools::Util::CreateComboBox(this, IDC_PLAN_COMBO_PROSTATUS, _T("Microsoft YaHei"), 12, TRUE);
		m_comboProductionStatus->MoveWindow(140, 25, 150, 20);

		m_comboProductionStatus->InsertString(0, _T("全部订单"));
		m_comboProductionStatus->InsertString(1, _T("可排产计划订单"));
		m_comboProductionStatus->InsertString(2, _T("排产计划中订单"));
		m_comboProductionStatus->InsertString(3, _T("已完成排产计划订单"));

		m_comboProductionStatus->SetCurSel(0);

		m_btnSearch = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_SEARCH, _T("查询"), _T("Microsoft YaHei"), 12);
		m_btnSearch->MoveWindow(340, 25, 90, 25);

		m_editSearch = Util_Tools::Util::CreateEdit(this, IDC_PLAN_BTN_SEARCH, _T(""), _T("Microsoft YaHei"), 12);
		m_editSearch->MoveWindow(450, 27, 240, 20);

		m_bsMoreWord = Util_Tools::Util::CreateStatic(this, IDC_PLAN_BTN_MOREWORD, _T("更多筛选"), _T("Microsoft YaHei"), 12);
		m_bsMoreWord->MoveWindow(700, 27, 63, 20);

		m_btnMore = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_MORE, _T(">"), _T("Microsoft YaHei"), 12);
		m_btnMore->MoveWindow(780, 25, 30, 25);

		m_btnPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_PLAN, _T("计划"), _T("Microsoft YaHei"), 12);
		m_btnPlan->MoveWindow(20, 70, 90, 25);

		m_btnModify = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_MODIFY, _T("修改"), _T("Microsoft YaHei"), 12);
		m_btnModify->MoveWindow(135, 70, 90, 25);

		m_btnRestore = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_RESTORE, _T("重置"), _T("Microsoft YaHei"), 12);
		m_btnRestore->MoveWindow(250, 70, 90, 25);

		m_btnTableFilter = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_TABLEFILTER, _T("表格设置"), _T("Microsoft YaHei"), 12);
		m_btnTableFilter->MoveWindow(860, 25, 90, 25);

		m_btnReApproveSCRQBusiness = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVESCRQBUSINESS, _T("反审核-生产日期-业务"), _T("Microsoft YaHei"), 12);
		m_btnReApproveSCRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVESCRQPLAN, _T("反审核-生产日期-计划"), _T("Microsoft YaHei"), 12);
		m_btnReApproveBZRQBusiness = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQBUSINESS, _T("反审核-包装日期-业务"), _T("Microsoft YaHei"), 12);
		m_btnReApproveBZRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQPLAN, _T("反审核-包装日期-计划"), _T("Microsoft YaHei"), 12);
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
	if (IDOK == m_tableFilterDlg.DoModal()){
	}
}

void CPlanPanel::OnBnClickedModify()
{
	//dropped
}

void CPlanPanel::OnBnClickedRestore()
{
	//dropped
}

void CPlanPanel::OnBnClickedSearch()
{
	int iCountShot = 0;
	CString searchText;
	m_editSearch->GetWindowText(searchText);
	CString rowData;
	bool bMatch = false;
	for (int i = 0; i < m_table.size(); ++i)
	{
		bMatch = false;
		for (int j = 0; j < m_table[i].second.size(); ++j)
		{
			CString strSource = m_table[i].second[j];
			strSource.MakeUpper();
			searchText.MakeUpper();

			if (searchText.IsEmpty() || strSource.Find(searchText) >= 0)
			{
				bMatch = true;
				break;
			}
		}
		if (!bMatch)
		{
			m_pJqGridAPI->HideRow(m_table[i].first);
		}
		else
		{
			m_pJqGridAPI->ShowRow(m_table[i].first);
			iCountShot++;
		}
	}

	if (iCountShot == 0)
	{
		MessageBox(_T("没有符合条件的记录"), _T("查询结果"), MB_OK | MB_ICONWARNING);
	}
}


void CPlanPanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("高级搜索"), m_pHttp);
	CSaleAddDlg::Option_t* pstOpt(new CSaleAddDlg::Option_t());
	dlg.SetOption(pstOpt);
	if (IDOK == dlg.DoModal()){
		const std::vector<CString>& searchVals = dlg.GetResult();
		bool bMatch = true;
		for (int i = 0; i < m_table.size(); ++i)
		{
			bMatch = true;
			for (int j = 0; j < searchVals.size(); ++j)
			{
				if (!searchVals[j].IsEmpty() && m_table[i].second[j].CompareNoCase(searchVals[j]) != 0)
				{
					bMatch = false;
					break;
				}
			}

			if (!bMatch)
			{
				m_pJqGridAPI->HideRow(m_table[i].first);
			}
			else
			{
				m_pJqGridAPI->ShowRow(m_table[i].first);
				iCountShot++;
			}
		}
		if (iCountShot == 0)
		{
			MessageBox(_T("没有符合条件的记录"), _T("查询结果"), MB_OK | MB_ICONWARNING);
		}
	}
}

void CPlanPanel::OnBnClickedReApproveBZRQBusiness()
{
	class OnReApproveBZRQBusinessListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveBZRQBusinessListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(bool& bRet){
			if (bRet)
			{
				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PACK_BUSINESS);
			}
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	CPlan& plan = CServer::GetInstance()->GetPlan();
	plan.Unapprove(CPlan::PACK_BUSINESS, checkedRows).then(new OnReApproveBZRQBusinessListener(*this));
	GetParent()->EnableWindow(FALSE);
}

void CPlanPanel::OnBnClickedReApproveBZRQPlan()
{
	class OnReApproveBZRQPlanListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveBZRQPlanListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(bool& bRet){
			if (bRet)
			{
				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PACK_PLAN);
			}
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	
	CPlan& plan = CServer::GetInstance()->GetPlan();
	plan.Unapprove(CPlan::PACK_PLAN, checkedRows).then(new OnReApproveBZRQPlanListener(*this));
	GetParent()->EnableWindow(FALSE);
}

void CPlanPanel::OnBnClickedReApproveSCRQBusiness()
{
	class OnReApproveSCRQBusinessListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveSCRQBusinessListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(bool& bRet){
			if (bRet)
			{
				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PLAN_BUSINESS);
			}
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	
	CPlan& plan = CServer::GetInstance()->GetPlan();
	plan.Unapprove(CPlan::PLAN_BUSINESS, checkedRows).then(new OnReApproveSCRQBusinessListener(*this));
	GetParent()->EnableWindow(FALSE);
}

void CPlanPanel::OnBnClickedReApproveSCRQPlan()
{
	class OnReApproveSCRQPlanListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_1(OnReApproveSCRQPlanListener, CPlanPanel&, planPanel)
	public:
		virtual void OnSuccess(bool& bRet){
			if (bRet)
			{
				m_planPanel.MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
				(m_planPanel.CPlanPanel::OnReApproveSuccess)(CPlan::ApproveType::PLAN_PLAN);
			}
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_planPanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_planPanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	
	CPlan& plan = CServer::GetInstance()->GetPlan();
	plan.Unapprove(CPlan::PLAN_PLAN, checkedRows).then(new OnReApproveSCRQPlanListener(*this));
	GetParent()->EnableWindow(FALSE);
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
				m_table[checkedRowTableMap[i]].second[17] = _T("×");
				m_pJqGridAPI->SetCell(checkedRows[i], 18, _T("×"));

				if (m_table[checkedRowTableMap[i]].second[18] == _T("×"))
				{
					//如果生产日期的业务和计划都被反审核，设置生产日期为空
					m_table[checkedRowTableMap[i]].second[16] = _T("");
					m_pJqGridAPI->SetCell(checkedRows[i], 17, _T(""));
				}

				m_btnReApproveSCRQBusiness->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PLAN_PLAN == type)
			{
				m_table[checkedRowTableMap[i]].second[18] = _T("×");
				m_pJqGridAPI->SetCell(checkedRows[i], 19, _T("×"));

				if (m_table[checkedRowTableMap[i]].second[17] == _T("×"))
				{
					m_table[checkedRowTableMap[i]].second[16] = _T("");
					m_pJqGridAPI->SetCell(checkedRows[i], 17, _T(""));
				}

				m_btnReApproveSCRQPlan->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PACK_BUSINESS == type)
			{
				m_table[checkedRowTableMap[i]].second[20] = _T("×");
				m_pJqGridAPI->SetCell(checkedRows[i], 21, _T("×"));

				if (m_table[checkedRowTableMap[i]].second[21] == _T("×"))
				{
					m_table[checkedRowTableMap[i]].second[19] = _T("");
					m_pJqGridAPI->SetCell(checkedRows[i], 20, _T(""));
				}

				m_btnReApproveBZRQBusiness->EnableWindow(FALSE);
			}
			else if (CPlan::ApproveType::PACK_PLAN == type)
			{
				m_table[checkedRowTableMap[i]].second[21] = _T("×");
				m_pJqGridAPI->SetCell(checkedRows[i], 22, _T("×"));
				
				if (m_table[checkedRowTableMap[i]].second[20] == _T("×"))
				{
					m_table[checkedRowTableMap[i]].second[19] = _T("");
					m_pJqGridAPI->SetCell(checkedRows[i], 20, _T(""));
				}

				m_btnReApproveBZRQPlan->EnableWindow(FALSE);
			}
		}
	}
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

	__super::OnNcDestroy();
}

void CPlanPanel::OnRowChecked()
{
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
			for (int j = 0; j < m_table.size(); ++j)
			{
				if (m_table[j].first == checkedRows[i])
				{
					if (_T("√") == m_table[j].second[17])
					{
						m_btnReApproveSCRQBusiness->EnableWindow(TRUE);
						bIfBreak = true;
					}

					if (_T("√") == m_table[j].second[18])
					{
						m_btnReApproveSCRQPlan->EnableWindow(TRUE);
						bIfBreak = true;
					}

					if (_T("√") == m_table[j].second[20])
					{
						m_btnReApproveBZRQBusiness->EnableWindow(TRUE);
						bIfBreak = true;
					}

					if (_T("√") == m_table[j].second[21])
					{
						m_btnReApproveBZRQPlan->EnableWindow(TRUE);
						bIfBreak = true;
					}

					if (bIfBreak)
					{
						break;
					}
				}
			}

			if (bIfBreak)
			{
				break;
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

void CPlanPanel::OnHttpSuccess(int id, LPCTSTR resp)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_ID:
		OnLoadDataSuccess(CString(resp));
		break;
	case ADD_URL_ID:
		//OnAddDataSuccess(_tstoi(resp), m_cacheRow);
		break;
	case DEL_URL_ID:
		//OnDelDataSuccess();
		break;
	case MODIFY_URL_ID:
		OnModifyDataSuccess(m_cacheRow);
		break;
	//case BUSSINESS_APPROVE_URL_ID:	//test purpose
		//break;
	case REAPPROVE_URL_ID:
		MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
		break;
	default:
		break;
	}
}

void CPlanPanel::OnHttpFailed(int id)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_ID:
		MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		break;
	case ADD_URL_ID:
		MessageBox(_T("添加数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		break;
	case DEL_URL_ID:
		MessageBox(_T("删除数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		break;
	case MODIFY_URL_ID:
		MessageBox(_T("修改数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		break;
	case REAPPROVE_URL_ID:
		MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
		break;
	default:
		break;
	}
}

void CPlanPanel::OnLoadDataSuccess(CString& jsondata)
{
	for (int j = 0; j < m_table.size(); ++j)
	{
		m_pJqGridAPI->DelRow(m_table[j].first);
	}
	
	m_pJqGridAPI->Refresh();

	//StringToTable(jsondata, m_table);
	for (int j = 0; j < m_table.size(); ++j)
	{
		m_pJqGridAPI->AddRow(m_table[j].first, m_table[j].second);
	}
}

void CPlanPanel::OnModifyDataSuccess(std::vector<CString>& newData)
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
			m_table[checkedRowTableMap[i]].second[16] = newData[0];
			m_table[checkedRowTableMap[i]].second[19] = newData[1];
			m_table[checkedRowTableMap[i]].second[22] = newData[2];
			m_table[checkedRowTableMap[i]].second[23] = newData[3];
			m_table[checkedRowTableMap[i]].second[24] = newData[4];
		}

		m_pJqGridAPI->SetCell(checkedRows[i], 17, newData[0]);
		m_pJqGridAPI->SetCell(checkedRows[i], 20, newData[1]);
		m_pJqGridAPI->SetCell(checkedRows[i], 23, newData[2]);
		m_pJqGridAPI->SetCell(checkedRows[i], 24, newData[3]);
		m_pJqGridAPI->SetCell(checkedRows[i], 25, newData[4]);
	}
}

void CPlanPanel::OnDataUpdate()
{
	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/plan/query/all/none"), IDS_HOST_NAME);
	//m_pHttp->Get(url, QUERY_URL_ID);

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (perm.getPlan())
	{
		class OnLoadDataListener : public CPromise<table>::IHttpResponse
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
		};
		CPlan& plan = CServer::GetInstance()->GetPlan();
		plan.Query().then(new OnLoadDataListener(*this, m_table, m_pJqGridAPI.get()));
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
	CBRPanel::OnDestroy();

	// TODO: Add your message handler code here
}
