#include "stdafx.h"
#include "Server.h"
#include "SalePanel.h"
#include "resource_ids.h"
#include "CommonDefine.h"
#include "Util.h"
#include "SaleAddDlg.h"
#include "colors.h"
#include "JQGridAPI.h"
#include "User.h"
#define UM_REQUEST_RESULT

#define RIGHT_AREA_LEFT	150
#define QUERY_URL_ID IDP_SALE + 1
#define ADD_URL_ID IDP_SALE + 2
#define DEL_URL_ID IDP_SALE + 3
#define MODIFY_URL_ID IDP_SALE + 4
#define BUSSINESS_APPROVE_URL_ID IDP_SALE + 5	//test purpose
#define BUSSINESS_REAPPROVE_BSN_URL_ID MODIFY_URL_ID + 6
#define BUSSINESS_REAPPROVE_PLAN_URL_ID MODIFY_URL_ID + 7


BEGIN_MESSAGE_MAP(CSalePanel, CBRPanel)
	ON_BN_CLICKED(IDC_SALE_BTN_ADD, &CSalePanel::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SALE_BTN_MODIFY, &CSalePanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_SALE_BTN_DELETE, &CSalePanel::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SALE_BTN_SEARCH, &CSalePanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_SALE_BTN_MORE, &CSalePanel::OnBnClickedMore)
	ON_BN_CLICKED(IDC_SALE_BTN_TABLEFILTER, &CSalePanel::OnBnClickedTableFilter)
	ON_BN_CLICKED(IDC_SALE_BTN_REAPPROVEFORBUSINESS, &CSalePanel::OnBnClickedReApproveBusiness)
	ON_BN_CLICKED(IDC_SALE_BTN_REAPPROVEFORPLAN, &CSalePanel::OnBnClickedReApprovePlan)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

CSalePanel::CSalePanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: CBRPanel(pJqGridAPI, pHttp)
	, m_tableFilterDlg(_T("表格设置"))
	, m_btnAdd(NULL)
	, m_btnSearch(NULL)
	, m_btnModify(NULL)
	, m_btnDelete(NULL)
	, m_btnMore(NULL)
	, m_btnTableFilter(NULL)
	, m_btnReApproveForBusiness(NULL)
	, m_btnReApproveForPlan(NULL)
	, m_bsMoreWord(NULL)
	, m_editSearch(NULL)
{
	m_tableFilterDlg.Initialize(m_pJqGridAPI.get(), Page_Sale);
}

CSalePanel::~CSalePanel()
{
}

void CSalePanel::OnInitChilds()
{
	m_editSearch = Util_Tools::Util::CreateEdit(this, IDC_SALE_BTN_SEARCH, _T(""), _T("Microsoft YaHei"), 12);
	m_editSearch->MoveWindow(235, 27, 240, 20);

	m_btnAdd = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_ADD, _T("添加"), _T("Microsoft YaHei"), 12);
	m_btnAdd->MoveWindow(20, 25, 90, 25);


	m_btnDelete = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_DELETE, _T("删除"), _T("Microsoft YaHei"), 12);
	m_btnDelete->MoveWindow(125, 70, 90, 25);

	m_btnModify = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_MODIFY, _T("修改"), _T("Microsoft YaHei"), 12);
	m_btnModify->MoveWindow(20, 70, 90, 25);

	m_btnSearch = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_SEARCH, _T("查询"), _T("Microsoft YaHei"), 12);
	m_btnSearch->MoveWindow(125, 25, 90, 25);

	m_btnMore = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_MORE, _T(">"), _T("Microsoft YaHei"), 12);
	m_btnMore->MoveWindow(566, 25, 30, 25);

	m_btnTableFilter = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_TABLEFILTER, _T("表格设置"), _T("Microsoft YaHei"), 12);
	m_btnTableFilter->MoveWindow(640, 25, 90, 25);

	m_btnReApproveForBusiness = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_REAPPROVEFORBUSINESS, _T("反审核-业务"), _T("Microsoft YaHei"), 12);
	m_btnReApproveForBusiness->MoveWindow(900, 70, 90, 25);

	m_btnReApproveForPlan = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_ADD, _T("反审核-计划"), _T("Microsoft YaHei"), 12);
	m_btnReApproveForPlan->MoveWindow(1010, 70, 90, 25);

	m_bsMoreWord = Util_Tools::Util::CreateStatic(this, IDC_SALE_BTN_MOREWORD, _T("更多筛选"), _T("Microsoft YaHei"), 12);
	m_bsMoreWord->MoveWindow(485, 27, 63, 20);

	m_btnDelete->EnableWindow(FALSE);
	m_btnModify->EnableWindow(FALSE);

	m_btnReApproveForBusiness->EnableWindow(FALSE);
	m_btnReApproveForPlan->EnableWindow(FALSE);
}

void CSalePanel::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("添加"), m_pHttp);
	if (IDOK == dlg.DoModal())
	{
		//GetParent()->EnableWindow(FALSE);
		m_cacheRow = dlg.GetResult();
		m_cacheRow.push_back(_T("×"));
		m_cacheRow.push_back(_T("×"));
		std::map<CString, StringArrayPtr> attr;
		attr[_T("add")] = &m_cacheRow;

		//CString url;
		//url.Format(_T("http://%s:8080/BlueRay/sale/add/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());

		//m_pHttp->Post(url, ADD_URL_ID, attr);
		int rowId;
		if (CServer::GetInstance()->GetSale().Add(m_cacheRow, rowId)){
			OnAddDataSuccess(rowId, m_cacheRow);
		}
		else
		{
			OnHttpFailed(ADD_URL_ID);
		}
	}
}

void CSalePanel::OnBnClickedTableFilter()
{
	if (IDOK == m_tableFilterDlg.DoModal())
	{

	}
}

void CSalePanel::OnBnClickedReApproveBusiness()
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/business/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, BUSSINESS_REAPPROVE_BSN_URL_ID, attr);
}

void CSalePanel::OnBnClickedReApprovePlan()
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/plan/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	std::map<CString, IntArrayPtr> attr;
	attr[L"rows"] = &checkedRows;

	m_pHttp->Post(url, BUSSINESS_REAPPROVE_PLAN_URL_ID, attr);
}

void CSalePanel::OnBnClickedModify()
{
	CSaleAddDlg dlg(_T("修改"), m_pHttp);
	dlg.d_GetOption += std::make_pair(this, &CSalePanel::OnSaleDlgGetModifyOption);

	if (IDOK == dlg.DoModal())
	{
		//GetParent()->EnableWindow(FALSE);
		m_cacheRow = dlg.GetResult();
		std::map<CString, StringArrayPtr> attr;
		StringArray tmpCheckRows;
		std::vector<int> checkedRows;
		m_pJqGridAPI->GetCheckedRows(checkedRows);
		//ToStringArray(checkedRows, tmpCheckRows);

		//attr[_T("rows")] = &tmpCheckRows;
		//attr[_T("data")] = &m_cacheRow;
		//CString url;
		//url.Format(_T("http://%s:8080/BlueRay/sale/modify"), IDS_HOST_NAME);
		//m_pHttp->Post(url, MODIFY_URL_ID, attr);

		if (CServer::GetInstance()->GetSale().Update(checkedRows, m_cacheRow))
		{
			OnModifyDataSuccess(m_cacheRow);
		}
		else
		{
			OnHttpFailed(MODIFY_URL_ID);
		}
	}
}

void CSalePanel::OnBnClickedDelete()
{
	if (IDOK == MessageBox(_T("是否确认删除此记录？ 请注意，删除后无法恢复！"), _T("删除"), MB_OKCANCEL | MB_ICONQUESTION))
	{
		std::vector<int> checkedRows;
		m_pJqGridAPI->GetCheckedRows(checkedRows);
		//GetParent()->EnableWindow(FALSE);
		std::map<CString, IntArrayPtr> attr;
		attr[_T("del")] = &checkedRows;

		//CString url;
		//url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
		//m_pHttp->Post(url, DEL_URL_ID, attr);

		if (CServer::GetInstance()->GetSale().Delete(checkedRows)){
			OnDelDataSuccess();
		}
		else
		{
			OnHttpFailed(DEL_URL_ID);
		}
	}
}

void CSalePanel::OnRowChecked()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.empty())
	{
		m_btnDelete->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnReApproveForBusiness->EnableWindow(FALSE);
		m_btnReApproveForPlan->EnableWindow(FALSE);
	}
	else
	{
		m_btnDelete->EnableWindow(TRUE);
		m_btnModify->EnableWindow(TRUE);

		m_btnReApproveForBusiness->EnableWindow(TRUE);
		m_btnReApproveForPlan->EnableWindow(TRUE);
	}
}

void CSalePanel::OnBnClickedSearch()
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


void CSalePanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("高级搜索"), m_pHttp);

	dlg.SetOption(new CSaleAddDlg::Option_t());
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

void CSalePanel::OnNcDestroy()
{
	if (NULL != m_btnAdd)
	{
		delete m_btnAdd;
		m_btnAdd = NULL;
	}

	if (NULL != m_btnSearch)
	{
		delete m_btnSearch;
		m_btnSearch = NULL;
	}

	if (NULL != m_btnModify)
	{
		delete m_btnModify;
		m_btnModify = NULL;
	}

	if (NULL != m_btnDelete)
	{
		delete m_btnDelete;
		m_btnDelete = NULL;
	}

	if (NULL != m_btnMore)
	{
		delete m_btnMore;
		m_btnMore = NULL;
	}

	if (NULL != m_btnTableFilter)
	{
		delete m_btnTableFilter;
		m_btnTableFilter = NULL;
	}

	if (NULL != m_btnReApproveForBusiness)
	{
		delete m_btnReApproveForBusiness;
		m_btnReApproveForBusiness = NULL;
	}

	if (NULL != m_btnReApproveForPlan)
	{
		delete m_btnReApproveForPlan;
		m_btnReApproveForPlan = NULL;
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

	__super::OnNcDestroy();
}

void CSalePanel::OnHttpSuccess(int id, LPCTSTR resp)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_ID:
		OnLoadDataSuccess();
		break;
	case ADD_URL_ID:
		OnAddDataSuccess(_tstoi(resp), m_cacheRow);
		break;
	case DEL_URL_ID:
		OnDelDataSuccess();
		break;
	case MODIFY_URL_ID:
		OnModifyDataSuccess(m_cacheRow);
		break;
	case BUSSINESS_APPROVE_URL_ID:	//test purpose
		OnApproveDataSuccess();
		break;
	case BUSSINESS_REAPPROVE_BSN_URL_ID:
	case BUSSINESS_REAPPROVE_PLAN_URL_ID:
		MessageBox(_T("反审核成功"), _T("反审核"), MB_OK | MB_ICONWARNING);
		break;
	default:
		break;
	}
}

void CSalePanel::OnHttpFailed(int id)
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
	case BUSSINESS_REAPPROVE_BSN_URL_ID:
	case BUSSINESS_REAPPROVE_PLAN_URL_ID:
		MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
		break;
	default:
		break;
	}

}

void CSalePanel::OnLoadDataSuccess()
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

void CSalePanel::OnDelDataSuccess()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		m_pJqGridAPI->DelRow(checkedRows[i]);
	}

	for (int i = m_table.size() - 1; i >= 0; --i)
	{
		for (int j = checkedRows.size() - 1; j >= 0; --j)
		{
			if (m_table[i].first == checkedRows[j]){
				m_table.erase(m_table.begin() + i);
				break;
			}
		}
	}

	OnRowChecked();
	GetParent()->PostMessage(WM_SALE_UPDATED);
}

void CSalePanel::OnModifyDataSuccess(std::vector<CString>& newData)
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

	for (int j = newData.size() - 1; j >= 0; --j)
	{
		if (!newData[j].IsEmpty())
		{
			for (int i = checkedRows.size() - 1; i >= 0; --i)
			{
				if (checkedRowTableMap[i] >= 0)
				{
					m_table[checkedRowTableMap[i]].second[j] = newData[j];
				}
				m_pJqGridAPI->SetCell(checkedRows[i], j + 1, newData[j]);
			}
		}
	}

	GetParent()->PostMessage(WM_SALE_UPDATED);
}

void CSalePanel::OnAddDataSuccess(int id, std::vector<CString>& data)
{
	m_table.push_back(std::make_pair(
		id,
		data));
	m_pJqGridAPI->AddRow(id, data);
	GetParent()->PostMessage(WM_SALE_UPDATED);
}

void CSalePanel::OnSaleDlgGetModifyOption(CSaleAddDlg& dlg)
{
	CSaleAddDlg::Option_t* pstOpt = NULL;
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
			if (pstOpt == NULL)
			{
				pstOpt = new CSaleAddDlg::Option_t(*pRowData);
			}
			else
			{
				pstOpt->Merge(*pRowData);
			}
		}
	}

	dlg.SetOption(pstOpt);
}

void CSalePanel::OnApproveDataSuccess()
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
		m_table[checkedRowTableMap[i]].second[16] = _T("√");
		m_pJqGridAPI->SetCell(checkedRows[i], 17, _T("√"));
	}
	GetParent()->PostMessage(WM_SALE_UPDATED);
	OnRowChecked();
}

void CSalePanel::OnDataUpdate()
{
	//CString url;
	//url.Format(_T("http://%s:8080/BlueRay/sale/query/all/none"), IDS_HOST_NAME);
	//CString jsondata;
	//m_pHttp->SyncGet(url, jsondata);

	if (!CServer::GetInstance()->GetSale().Query(m_table))
	{
		OnHttpFailed(QUERY_URL_ID);
	}

	OnLoadDataSuccess();
	//GetParent()->EnableWindow(FALSE);
}
