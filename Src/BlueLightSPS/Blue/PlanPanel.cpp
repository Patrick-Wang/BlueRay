#include "stdafx.h"
#include "PlanPanel.h"
#include "PlanAddDlg.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "CommonDefine.h"
#include "Util.h"
#include "colors.h"
#include "User.h"

#define QUERY_URL_ID IDP_PLAN + 1
#define ADD_URL_ID IDP_PLAN + 2
#define DEL_URL_ID IDP_PLAN + 3
#define MODIFY_URL_ID IDP_PLAN + 4
#define REAPPROVE_URL_ID IDP_PLAN + 5

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

{
	m_tableFilterDlg.Initialize(m_pJqGridAPI.get(), Page_Plan);
}


CPlanPanel::~CPlanPanel()
{
}

void CPlanPanel::OnInitChilds()
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
	m_btnReApproveSCRQBusiness->MoveWindow(500, 70, 140, 25);

	m_btnReApproveSCRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVESCRQPLAN, _T("反审核-生产日期-计划"), _T("Microsoft YaHei"), 12);
	m_btnReApproveSCRQPlan->MoveWindow(660, 70, 140, 25);
	
	m_btnReApproveBZRQBusiness = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQBUSINESS, _T("反审核-包装日期-业务"), _T("Microsoft YaHei"), 12);
	m_btnReApproveBZRQBusiness->MoveWindow(820, 70, 140, 25);
	
	m_btnReApproveBZRQPlan = Util_Tools::Util::CreateButton(this, IDC_PLAN_BTN_REAPPROVEBZRQPLAN, _T("反审核-包装日期-计划"), _T("Microsoft YaHei"), 12);
	m_btnReApproveBZRQPlan->MoveWindow(980, 70, 140, 25);

	m_btnPlan->EnableWindow(FALSE);
	m_btnRestore->EnableWindow(FALSE);
	m_btnModify->EnableWindow(FALSE);

	m_btnModify->ShowWindow(FALSE);
	m_btnRestore->ShowWindow(FALSE);
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
		CString url;
		url.Format(_T("http://%s:8080/BlueRay/plan/update"), IDS_HOST_NAME);
		StringArray tmpCheckRows;
		ToStringArray(checkedRows, tmpCheckRows);
		std::map<CString, StringArrayPtr> attr;
		attr[_T("rows")] = &tmpCheckRows;
		attr[_T("data")] = &m_cacheRow;
		m_pHttp->Post(url, MODIFY_URL_ID, attr);
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
	std::auto_ptr<CPlanAddDlg::Option_t> pstOpt;
	CPlanAddDlg dlg(_T("修改"));
	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	std::vector<int> checkedRowTableMap;
	checkedRowTableMap.resize(checkedRows.size(), -1);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		pRowData = NULL;
		for (int j = 0; j < m_table.size(); ++j)
		{
			if (m_table[j].first == checkedRows[i])
			{
				checkedRowTableMap[i] = j;
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
		
	}
}

void CPlanPanel::OnBnClickedRestore()
{
	if (IDOK == MessageBox(_T("是否撤销已排产的计划,并重新计划排产？"), _T("重新计划"), MB_OKCANCEL | MB_ICONQUESTION))
	{
		OnBnClickedPlan();
	}
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
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/pack/business/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, REAPPROVE_URL_ID, attr);
}

void CPlanPanel::OnBnClickedReApproveBZRQPlan()
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/pack/plan/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, REAPPROVE_URL_ID, attr);
}

void CPlanPanel::OnBnClickedReApproveSCRQBusiness()
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/business/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, REAPPROVE_URL_ID, attr);
}

void CPlanPanel::OnBnClickedReApproveSCRQPlan()
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/plan/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, REAPPROVE_URL_ID, attr);
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
	}
	else
	{
		m_btnPlan->EnableWindow(TRUE);
		m_btnRestore->EnableWindow(TRUE);
		m_btnModify->EnableWindow(TRUE);
	}
}

void CPlanPanel::OnUIPrepared()
{
	__super::OnUIPrepared();
	if (m_pJqGridAPI->GetRowCount() == 0)
	{
		for (int i = 0; i < m_table.size(); ++i)
		{
			m_table[i].first = m_pJqGridAPI->AddRow(m_table[i].second);
		}
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

	StringToTable(jsondata, m_table);
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
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/query/all/none"), IDS_HOST_NAME);
	m_pHttp->Get(url, QUERY_URL_ID);
	GetParent()->EnableWindow(FALSE);
}
