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
#include "Promise.h"


#define UM_REQUEST_RESULT

#define QUERY_URL_ID IDP_SALE + 1
#define ADD_URL_ID IDP_SALE + 2
#define DEL_URL_ID IDP_SALE + 3
#define MODIFY_URL_ID IDP_SALE + 4
#define BUSSINESS_APPROVE_URL_ID IDP_SALE + 5	//test purpose
#define BUSSINESS_REAPPROVE_BSN_URL_ID IDP_SALE + 6
#define BUSSINESS_REAPPROVE_PLAN_URL_ID IDP_SALE + 7

class OnSaleLoadDataListener : public CPromise<PageData_t>::IHttpResponse
{
	CONSTRUCTOR_3(OnSaleLoadDataListener, CSalePanel&, salePanel, table&, tb, CJQGridAPI*, pJqGridAPI)
public:
	virtual void OnSuccess(PageData_t& tb){
		//IntArray ia;
		//m_pJqGridAPI->GetCheckedRows(ia);
		//CString strFmt;
		//strFmt.Format(L"%d", ia.size());
		//m_salePanel.MessageBox(strFmt, strFmt);
		m_pJqGridAPI->Refresh(tb.rawData);
		m_tb = tb.rows;
		m_salePanel.HighLight();
		m_salePanel.GetParent()->EnableWindow(TRUE);
//		m_pJqGridAPI->UncheckedAll();
		m_salePanel.OnRowChecked();
		//m_pJqGridAPI->GetCheckedRows(ia);
		//strFmt.Format(L"%d", ia.size());
		//m_salePanel.MessageBox(strFmt, strFmt);
	}
	virtual void OnFailed(){
		m_salePanel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		m_salePanel.GetParent()->EnableWindow(TRUE);
	}
};

class CSaleSearchListener : public CPromise<PageData_t>::IHttpResponse{
	CONSTRUCTOR_3(CSaleSearchListener, CSalePanel&, salePanel, table&, tb, CJQGridAPI*, pJqGridAPI)
public:
	virtual void OnSuccess(PageData_t& tb){
		m_pJqGridAPI->Refresh(tb.rawData);

		m_tb = tb.rows;
		if (m_tb.empty())
		{
			m_salePanel.MessageBox(_T("没有符合条件的记录"), _T("查询结果"), MB_OK | MB_ICONWARNING);
		}
		m_salePanel.HighLight();
		m_salePanel.GetParent()->EnableWindow(TRUE);
//		m_pJqGridAPI->UncheckedAll();
		m_salePanel.OnRowChecked();
	}
	virtual void OnFailed(){
		m_salePanel.MessageBox(_T("获取数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
		m_salePanel.GetParent()->EnableWindow(TRUE);
	}
};



static int g_ReApproveBtnPos[][4] = {
		{ 640, 70, 90, 25 },
		{ 530, 70, 90, 25 }
};

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
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_SALE_COMBO_PROSTATUS, &CSalePanel::OnCbnSelchangeProductionStatus)
END_MESSAGE_MAP()

CSalePanel::CSalePanel(CJQGridAPI* pJqGridAPI)
//: CBRPanel(pJqGridAPI, pHttp)
: CBRPanel(pJqGridAPI)
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
, m_iCountBtnOfReApprove(-1)
, m_bsDateRange(NULL)
, m_bsMiddleLine(NULL)
, m_dtcSearchFrom(NULL)
, m_dtcSearchTo(NULL)
, m_bIfUpdateTableWhenTableFilter(false)
{
	m_tableFilterDlg.Initialize(m_pJqGridAPI.get(), Page_Sale);
}

CSalePanel::~CSalePanel()
{
}

void CSalePanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CBRPanel::OnShowWindow(bShow, nStatus);

	if (!bShow)
	{
		m_btnDelete->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnReApproveForBusiness->EnableWindow(FALSE);
		m_btnReApproveForPlan->EnableWindow(FALSE);
	}

	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getSale())
	{
		m_pJqGridAPI->HideGrid();
	}

//	m_pJqGridAPI->UncheckedAll();
}

void CSalePanel::OnInitChilds()
{
	m_pJqGridAPI->d_OnExportClicked += std::make_pair(this, &CSalePanel::OnExportClicked);
	CPermission& perm = CUser::GetInstance()->GetPermission();
	CString strJsonWidths;
	if (CSettingManager::GetInstance()->GetColWidths(L"saleCol", strJsonWidths))
	{
		m_pJqGridAPI->SetWidths(strJsonWidths);
	}

	m_pJqGridAPI->d_OnUpdateData += std::make_pair(this, &CSalePanel::OnUpdateData);
	m_pJqGridAPI->d_OnImportClicked += std::make_pair(this, &CSalePanel::OnImportClicked);
	if (!perm.getSale())
	{
		m_bsMoreWord = Util_Tools::Util::CreateStatic(this, IDC_SALE_BTN_MOREWORD, _T("您没有销售录入的权限"), _T("Microsoft YaHei"), 16);
		m_bsMoreWord->MoveWindow(20, 27, 500, 20);
		m_bsMoreWord->SetTextAlign(DT_LEFT);
		m_pJqGridAPI->HideGrid();
	}
	else
	{
		//first line
		m_comboProductionStatus = Util_Tools::Util::CreateComboBox(this, IDC_SALE_COMBO_PROSTATUS, _T("Microsoft YaHei"), 12, TRUE);
		m_comboProductionStatus->MoveWindow(20, 23, 100, 18);

		m_comboProductionStatus->InsertString(0, _T("全部订单"));
		m_comboProductionStatus->InsertString(1, _T("未审核订单"));
		m_comboProductionStatus->InsertString(2, _T("审核中订单"));
		m_comboProductionStatus->InsertString(3, _T("已审核订单"));
		m_comboProductionStatus->SetCurSel(1);

		m_bsDateRange = Util_Tools::Util::CreateStatic(this, IDC_SALE_STATIC_DATERANGE, _T("查询日期"), _T("Microsoft YaHei"), 12);
		m_bsDateRange->MoveWindow(140, 25, 60, 20);

		m_dtcSearchFrom = Util_Tools::Util::CreateDateTimePicker(this, IDC_SALE_DATETIME_SEARCHFROM, _T("Microsoft YaHei"), 12);
		m_dtcSearchFrom->MoveWindow(210, 25, 108, 20);

		COleDateTime oletimeTime;
		oletimeTime.SetStatus(COleDateTime::null);
		m_dtcSearchFrom->SetTime(oletimeTime);

		m_bsMiddleLine = Util_Tools::Util::CreateStatic(this, IDC_SALE_STATIC_MIDDLELINE, _T("--"), _T("Microsoft YaHei"), 12);
		m_bsMiddleLine->MoveWindow(325, 25, 20, 20);

		m_dtcSearchTo = Util_Tools::Util::CreateDateTimePicker(this, IDC_SALE_DATETIME_SEARCHTO, _T("Microsoft YaHei"), 12);
		m_dtcSearchTo->MoveWindow(350, 25, 108, 20);
		m_dtcSearchTo->SetTime(oletimeTime);

		m_editSearch = Util_Tools::Util::CreateEdit(this, IDC_SALE_BTN_SEARCH, _T("请输入关键字"), _T("Microsoft YaHei"), 12);
		m_editSearch->MoveWindow(470, 25, 150, 20);

		m_btnMore = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_MORE, _T("更多筛选"), _T("Microsoft YaHei"), 12);
		m_btnMore->MoveWindow(640, 23, 90, 25);

		m_btnSearch = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_SEARCH, _T("查询"), _T("Microsoft YaHei"), 12);
		m_btnSearch->MoveWindow(750, 23, 90, 25);

		//second line
		m_btnAdd = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_ADD, _T("添加"), _T("Microsoft YaHei"), 12);
		m_btnAdd->MoveWindow(20, 70, 90, 25);

		m_btnModify = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_MODIFY, _T("修改"), _T("Microsoft YaHei"), 12);
		m_btnModify->MoveWindow(130, 70, 90, 25);

		m_btnDelete = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_DELETE, _T("删除"), _T("Microsoft YaHei"), 12);
		m_btnDelete->MoveWindow(240, 70, 90, 25);

		m_btnReApproveForBusiness = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_REAPPROVEFORBUSINESS, _T("反审核-业务"), _T("Microsoft YaHei"), 12);
		m_btnReApproveForPlan = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_REAPPROVEFORPLAN, _T("反审核-计划"), _T("Microsoft YaHei"), 12);
		ShowReApproveBtns();

		m_btnDelete->EnableWindow(FALSE);
		m_btnModify->EnableWindow(FALSE);

		m_btnReApproveForBusiness->EnableWindow(FALSE);
		m_btnReApproveForPlan->EnableWindow(FALSE);

		m_btnTableFilter = Util_Tools::Util::CreateButton(this, IDC_SALE_BTN_TABLEFILTER, _T("表格设置"), _T("Microsoft YaHei"), 12);
		m_btnTableFilter->MoveWindow(750, 70, 90, 25);
	}
}


void CSalePanel::MakeBasicSearchCondition(CJsonQueryParam &sqp)
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
		bHasFrom = true;
		m_dtcSearchTo->GetWindowText(strTo);
	}
	else
	{
		strTo = L"";
	}

	if (bHasFrom || bHasTo)
	{
		sqp.SetDateSearchCondition(strFrom, strTo);
	}

	int iIndex = m_comboProductionStatus->GetCurSel();

	if (0 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_All, sqp);
	}
	else if (1 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_ToBeApprove, sqp);
	}
	else if (2 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_Approving, sqp);
	}
	else if (3 == iIndex)
	{
		FilterTableByStatus(ProductionStatus_Approved, sqp);
	}
}

void CSalePanel::OnCbnSelchangeProductionStatus()
{
	DEFINE_SALE_QUERY_PARAM(sqp);
	MakeBasicSearchCondition(sqp);

	CServer::GetInstance()->GetSale().Query(
		1,
		//m_pJqGridAPI->GetCurrentPage(),
		m_pJqGridAPI->GetPageSize(),
		sqp)
		.then(new OnSaleLoadDataListener(*this, m_table, m_pJqGridAPI.get()));

	GetParent()->EnableWindow(FALSE);
}

void CSalePanel::FilterTableByStatus(enumProductionStatusForSale productionStatus, CJsonQueryParam &sqp)
{
	if (ProductionStatus_ToBeApprove == productionStatus)
	{
		sqp.AddApproveCondition(CSale::BUSINESS, false);
		sqp.AddApproveCondition(CSale::PLAN, false);
	}
	else if (ProductionStatus_Approving == productionStatus)
	{
		sqp.AddApproveCondition(CSale::BUSINESS, true);
		sqp.AddApproveCondition(CSale::PLAN, false);
		sqp.AddApproveCondition(CSale::BUSINESS, false, 1);
		sqp.AddApproveCondition(CSale::PLAN, true, 1);
	}
	else if (ProductionStatus_Approved == productionStatus)
	{
		sqp.AddApproveCondition(CSale::BUSINESS, true);
		sqp.AddApproveCondition(CSale::PLAN, true);
	}
}

void CSalePanel::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("添加"));
	dlg.SetOption(new CSaleAddDlg::Option_t());

	if (IDOK == dlg.DoModal())
	{
		m_cacheRow = dlg.GetResult();

		class CAddListener : public CPromise<int>::IHttpResponse{
			CONSTRUCTOR_2(CAddListener, CSalePanel&, salePanel, StringArray&, cacheRow)
		public:
			virtual void OnSuccess(int& ret){
				if (ret)
				{
					(m_salePanel.CSalePanel::OnAddDataSuccess)(ret, m_cacheRow);
					m_salePanel.OnUpdateData(1, m_salePanel.m_pJqGridAPI->GetGridPageSize(), -1, true);
				}
				else
				{
					m_salePanel.MessageBox(_T("添加数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				}
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
			virtual void OnFailed(){
				m_salePanel.MessageBox(_T("添加数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
		};

		CServer::GetInstance()->GetSale().Add(m_cacheRow).then(new CAddListener(*this, m_cacheRow));
		GetParent()->EnableWindow(FALSE);
	}
}

void CSalePanel::OnBnClickedTableFilter()
{
	m_bIfUpdateTableWhenTableFilter = true;

	if (IDOK == m_tableFilterDlg.DoModal())
	{

	}

	m_bIfUpdateTableWhenTableFilter = false;
}

void CSalePanel::OnBnClickedReApproveBusiness()
{
	class OnReApproveBusinessListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_2(OnReApproveBusinessListener, CSalePanel&, salePanel, CJQGridAPI*, pJqGridAPI)
	public:
		virtual void OnSuccess(StringArray& arrRet){
			std::vector<int> checkedRows;
			m_pJqGridAPI->GetCheckedRows(checkedRows);
			CString strFmt;
			strFmt.Format(L"%d 条未删除相关排产计划 \r\n", arrRet.size());
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
			strFmtTmp.Format(L"%d 条成功完成反审核 \r\n", checkedRows.size());
			for (int i = 0; i < checkedRows.size(); ++i)
			{
				m_pJqGridAPI->GetRow(checkedRows[i], row);
				strFmtTmp += row[0] + L" ";
				row.clear();
			}
			strFmt = strFmtTmp + L"\r\n" + strFmt;

			m_salePanel.MessageBox(strFmt, _T("反审核"), MB_OK | MB_ICONWARNING);
			(m_salePanel.CSalePanel::OnReApproveSuccess)(CSale::ApproveType::BUSINESS);

			m_salePanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_salePanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_salePanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CSale& sale = CServer::GetInstance()->GetSale();
			sale.Unapprove(CSale::BUSINESS, checkedRows).then(new OnReApproveBusinessListener(*this, m_pJqGridAPI.get()));
			GetParent()->EnableWindow(FALSE);
		}
	}
}


void CSalePanel::OnBnClickedReApprovePlan()
{
	class OnReApprovePlanListener : public CPromise<StringArray>::IHttpResponse{
		CONSTRUCTOR_2(OnReApprovePlanListener, CSalePanel&, salePanel, CJQGridAPI*, pJqGridAPI)
	public:
		virtual void OnSuccess(StringArray& arrRet){
			std::vector<int> checkedRows;
			m_pJqGridAPI->GetCheckedRows(checkedRows);
			CString strFmt;
			strFmt.Format(L"%d 条未删除相关排产计划 \r\n", arrRet.size());
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
			strFmtTmp.Format(L"%d 条成功完成反审核 \r\n", checkedRows.size());
			for (int i = 0; i < checkedRows.size(); ++i)
			{
				m_pJqGridAPI->GetRow(checkedRows[i], row);
				strFmtTmp += row[0] + L" ";
				row.clear();
			}
			strFmt = strFmtTmp + L"\r\n" + strFmt;
			m_salePanel.MessageBox(strFmt, _T("反审核"), MB_OK | MB_ICONWARNING);
			(m_salePanel.CSalePanel::OnReApproveSuccess)(CSale::ApproveType::PLAN);
			
			m_salePanel.GetParent()->EnableWindow(TRUE);
		}
		virtual void OnFailed(){
			m_salePanel.MessageBox(_T("反审核失败"), _T("反审核"), MB_OK | MB_ICONWARNING);
			m_salePanel.GetParent()->EnableWindow(TRUE);
		}
	};

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	if (checkedRows.size() > 0)
	{
		if (IDOK == MessageBox(_T("反审核会导致数据的永久改变，请确认是否继续？"), _T("反审核"), MB_OKCANCEL | MB_ICONWARNING))
		{
			CSale& sale = CServer::GetInstance()->GetSale();
			sale.Unapprove(CSale::PLAN, checkedRows).then(new OnReApprovePlanListener(*this, m_pJqGridAPI.get()));
			GetParent()->EnableWindow(FALSE);
		}
	}
}

void CSalePanel::OnReApproveSuccess(CSale::ApproveType type)
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
			if (CSale::ApproveType::BUSINESS == type)
			{
				m_table[checkedRowTableMap[i]].second[nsSale::Column_en::ywsh] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsSale::Column_en::ywsh + 1, IDS_COMMON_NO);

				m_btnReApproveForBusiness->EnableWindow(FALSE);
			}
			else if (CSale::ApproveType::PLAN == type)
			{
				m_table[checkedRowTableMap[i]].second[nsSale::Column_en::jhsh] = IDS_COMMON_NO;
				m_pJqGridAPI->SetCell(checkedRows[i], nsSale::Column_en::jhsh + 1, IDS_COMMON_NO);

				m_btnReApproveForPlan->EnableWindow(FALSE);
			}
		}
	}

	OnRowChecked();
}



void CSalePanel::OnBnClickedModify()
{
	CSaleAddDlg dlg(_T("修改"));
	dlg.d_GetOption += std::make_pair(this, &CSalePanel::OnSaleDlgGetModifyOption);

	if (IDOK == dlg.DoModal())
	{
		m_cacheRow = dlg.GetResult();

		std::map<CString, StringArrayPtr> attr;
		StringArray tmpCheckRows;
		std::vector<int> checkedRows;
		m_pJqGridAPI->GetCheckedRows(checkedRows);

		//已审核或部分审核的订单不允许修改
		std::vector<CString>* pRowData = NULL;
		std::vector<int>::iterator iter;

		for (iter = checkedRows.begin(); iter != checkedRows.end(); )
		{
			for (int j = 0; j < m_table.size(); ++j)
			{
				if (m_table[j].first == *iter)
				{
					pRowData = &(m_table[j].second);
					break;
				}
			}

			if (NULL != pRowData)
			{
				if ((pRowData->at(nsSale::Column_en::ywsh).CompareNoCase(_T("Y")) == 0) ||
					(pRowData->at(nsSale::Column_en::jhsh).CompareNoCase(_T("Y")) == 0))
				{
					iter = checkedRows.erase(iter);
				}
				else
				{
					iter++;
				}
			}
			else
			{
				iter++;
			}
		}

		class CUpdateListener : public CPromise<bool>::IHttpResponse{
			CONSTRUCTOR_2(CUpdateListener, CSalePanel&, salePanel, StringArray&, cacheRow)
		public:
			virtual void OnSuccess(bool& ret){
				if (ret)
				{
					(m_salePanel.CSalePanel::OnModifyDataSuccess)(m_cacheRow);
					m_salePanel.OnUpdateData(m_salePanel.m_pJqGridAPI->GetCurrentPage(), m_salePanel.m_pJqGridAPI->GetGridPageSize(), -1, true);
				}
				else
				{
					m_salePanel.MessageBox(_T("修改数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				}
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
			virtual void OnFailed(){
				m_salePanel.MessageBox(_T("修改数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
		};

		CServer::GetInstance()->GetSale().Update(checkedRows, m_cacheRow).then(new CUpdateListener(*this, m_cacheRow));
		GetParent()->EnableWindow(FALSE);
	}
}

void CSalePanel::OnBnClickedDelete()
{
	if (IDOK == MessageBox(_T("是否确认删除此记录？ 请注意，删除后无法恢复！"), _T("删除"), MB_OKCANCEL | MB_ICONQUESTION))
	{
		std::vector<int> checkedRows;
		m_pJqGridAPI->GetCheckedRows(checkedRows);
		std::map<CString, IntArrayPtr> attr;
		attr[_T("del")] = &checkedRows;

		class CDeleteListener : public CPromise<bool>::IHttpResponse{
			CONSTRUCTOR_1(CDeleteListener, CSalePanel&, salePanel)
		public:
			virtual void OnSuccess(bool& ret){
				if (ret)
				{
					(m_salePanel.CSalePanel::OnDelDataSuccess)();
					m_salePanel.OnUpdateData(1, m_salePanel.m_pJqGridAPI->GetGridPageSize(), -1, true);
				}
				else
				{
					m_salePanel.MessageBox(_T("删除数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				}
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
			virtual void OnFailed(){
				m_salePanel.MessageBox(_T("删除数据失败"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_salePanel.GetParent()->EnableWindow(TRUE);
			}
		};

		CServer::GetInstance()->GetSale().Delete(checkedRows).then(new CDeleteListener(*this));
		GetParent()->EnableWindow(FALSE);
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
		bool bIsAnyApproved = false;
		bool bIfShowModifyAndDelete = false;

		for (int i = checkedRows.size() - 1; i >= 0; --i)
		{
			bool bIsToBeApproveBusiness = false;
			bool bIsToBeApprovePlan = false;

			for (int j = 0; j < m_table.size(); ++j)
			{
				if (m_table[j].first == checkedRows[i])
				{
					if (IDS_COMMON_YES == m_table[j].second[nsSale::Column_en::ywsh])
					{
						m_btnReApproveForBusiness->EnableWindow(TRUE);
						bIsAnyApproved = true;
					}
					else
					{
						bIsToBeApproveBusiness = true;
					}

					if (IDS_COMMON_YES == m_table[j].second[nsSale::Column_en::jhsh])
					{
						m_btnReApproveForPlan->EnableWindow(TRUE);
						bIsAnyApproved = true;
					}
					else
					{
						bIsToBeApprovePlan = true;
					}

					if (bIsToBeApproveBusiness && bIsToBeApprovePlan)
					{
						bIfShowModifyAndDelete = true;
					}

					break;
				}
			}

			if (bIsAnyApproved)
			{
				continue;
			}
			else
			{
				m_btnReApproveForBusiness->EnableWindow(FALSE);
				m_btnReApproveForPlan->EnableWindow(FALSE);
			}
		}

		m_btnDelete->EnableWindow(bIfShowModifyAndDelete);
		m_btnModify->EnableWindow(bIfShowModifyAndDelete);
	}
}

void CSalePanel::OnBnClickedSearch()
{
//	m_pJqGridAPI->UncheckedAll();
	DEFINE_SALE_QUERY_PARAM(sqp);
	MakeBasicSearchCondition(sqp);
	//sqp.AddSortCondition(15, false);

	CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), sqp)
		.then(new CSaleSearchListener(*this, m_table, m_pJqGridAPI.get()));
	GetParent()->EnableWindow(FALSE);
}


void CSalePanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("高级搜索"));

	dlg.SetOption(new CSaleAddDlg::Option_t());
	if (IDOK == dlg.DoModal()){
		std::vector<CString>& searchVals = const_cast<std::vector<CString>&>(dlg.GetResult());
		// 		searchVals.insert(searchVals.begin() + 16, L"");//插入业务审核
		// 		searchVals.insert(searchVals.begin() + 17, L"");//插入计划审核
		// 		searchVals.insert(searchVals.begin() + 18, L"");//插入优先级
		DEFINE_SALE_QUERY_PARAM(jqp);
		jqp.SetAdvancedCondition(&searchVals);

		MakeBasicSearchCondition(jqp);
		//jqp.AddSortCondition(15, false);

		CServer::GetInstance()->GetSale().Query(1, m_pJqGridAPI->GetPageSize(), jqp)
			.then(new CSaleSearchListener(*this, m_table, m_pJqGridAPI.get()));
		GetParent()->EnableWindow(FALSE);
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

void CSalePanel::OnLoadDataSuccess()
{
	//for (int j = 0; j < m_table.size(); ++j)
	//{
	//	m_pJqGridAPI->AddRow(m_table[j].first, m_table[j].second);
	//}
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
// 	std::vector<int> checkedRows;
// 	m_pJqGridAPI->GetCheckedRows(checkedRows);
// 
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
// 	for (int j = newData.size() - 1; j >= 0; --j)
// 	{
// 		if (!newData[j].IsEmpty())
// 		{
// 			for (int i = checkedRows.size() - 1; i >= 0; --i)
// 			{
// 				if (checkedRowTableMap[i] >= 0)
// 				{
// 					m_table[checkedRowTableMap[i]].second[j] = newData[j];
// 				}
// 				m_pJqGridAPI->SetCell(checkedRows[i], j + 1, newData[j]);
// 			}
// 		}
// 	}

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
			if ((pRowData->at(nsSale::Column_en::ywsh).CompareNoCase(_T("Y")) == 0) || 
				(pRowData->at(nsSale::Column_en::jhsh).CompareNoCase(_T("Y")) == 0))
			{
				continue;
			}

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
		m_table[checkedRowTableMap[i]].second[nsSale::Column_en::ywsh] = IDS_COMMON_YES;
		m_pJqGridAPI->SetCell(checkedRows[i], nsSale::Column_en::ywsh + 1, IDS_COMMON_YES);
	}
	GetParent()->PostMessage(WM_SALE_UPDATED);
	OnRowChecked();
}

void CSalePanel::OnInitData()
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (perm.getSale())
	{
		DEFINE_SALE_QUERY_PARAM(sqp);
		MakeBasicSearchCondition(sqp);

		CServer::GetInstance()->GetSale().Query(
			1,
			//m_pJqGridAPI->GetCurrentPage(),
			m_pJqGridAPI->GetPageSize(),
			sqp)
			.then(new OnSaleLoadDataListener(*this, m_table, m_pJqGridAPI.get()));
		GetParent()->EnableWindow(FALSE);
	}
	else
	{
		m_pJqGridAPI->HideGrid();
	}
}

void CSalePanel::ShowReApproveBusinessBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getXsywsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveForBusiness->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveForBusiness->ShowWindow(SW_HIDE);
	}

	m_btnReApproveForBusiness->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}

void CSalePanel::ShowReApprovePlanBtn(BOOL bShow)
{
	CPermission& perm = CUser::GetInstance()->GetPermission();

	if (!perm.getXsjhsh())
	{
		bShow = FALSE;
	}
	else
	{
		m_iCountBtnOfReApprove++;
	}

	if (bShow)
	{
		m_btnReApproveForPlan->ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnReApproveForPlan->ShowWindow(SW_HIDE);
	}

	m_btnReApproveForPlan->MoveWindow(g_ReApproveBtnPos[m_iCountBtnOfReApprove][0],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][1],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][2],
		g_ReApproveBtnPos[m_iCountBtnOfReApprove][3]);
}


void CSalePanel::ShowReApproveBtns()
{
	m_iCountBtnOfReApprove = -1;
	//order must be kept
	ShowReApprovePlanBtn(TRUE);
	ShowReApproveBusinessBtn(TRUE);
}

void CSalePanel::OnDestroy()
{
	CString strWidths;
	m_pJqGridAPI->GetWidths(strWidths);
	CSettingManager::GetInstance()->SetColWidths(L"saleCol", strWidths);
	m_pJqGridAPI->d_OnUpdateData -= std::make_pair(this, &CSalePanel::OnUpdateData);
	m_pJqGridAPI->d_OnExportClicked -= std::make_pair(this, &CSalePanel::OnExportClicked);
	m_pJqGridAPI->d_OnImportClicked -= std::make_pair(this, &CSalePanel::OnImportClicked);
	CBRPanel::OnDestroy();
}

void CSalePanel::OnUpdateData(int page, int rows, int colIndex, bool bAsc)
{
	if (!m_bIfUpdateTableWhenTableFilter)
	{
		DEFINE_SALE_QUERY_PARAM(jqp);

		MakeBasicSearchCondition(jqp);
		if (colIndex >= 0){
			jqp.AddSortCondition(colIndex, bAsc);
		}

		CServer::GetInstance()->GetSale().Query(page, CJQGridAPI::GetPageSize(), jqp)
			.then(new OnSaleLoadDataListener(*this, m_table, m_pJqGridAPI.get()));

		GetParent()->EnableWindow(FALSE);
	}
}

void CSalePanel::HighLight()
{
	for (size_t i = 0, len = m_table.size(); i < len; i++)
	{
		if (0 == m_table[i].second[nsSale::yxj].Compare(L"高"))
		{
			m_pJqGridAPI->HighLightRow(m_table[i].first);
		}
	}
}

void CSalePanel::OnExportClicked()
{

	class CSaleExportListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CSaleExportListener, CSalePanel&, panel, CString, fileName);
	public:
		virtual void OnSuccess(bool& ret){
			if (ret)
			{
				m_panel.MessageBox(_T("销售数据已经成功导出到文件 : ") + m_fileName, _T("导出成功"), MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				m_panel.MessageBox(_T("销售数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
				DeleteFile(m_fileName);
			}
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("销售数据导出失败"), _T("导出失败"), MB_OK | MB_ICONWARNING);
			DeleteFile(m_fileName);
		}
	};

	COleDateTime time(COleDateTime::GetCurrentTime());
	CString strFileName(_T("销售订单数据"));
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
		try{
			DEFINE_SALE_QUERY_PARAM(sqp);

			MakeBasicSearchCondition(sqp);

			CString filePathName = hFileDlg.GetPathName();
			CServer::GetInstance()->GetSale().Export(filePathName, sqp).then(
				new CSaleExportListener(*this, filePathName));
		}
		catch (std::exception& e)
		{
			MessageBoxA(m_hWnd, (char*)e.what(), "导出失败", MB_OK | MB_ICONWARNING);
		}
	}
}

void CSalePanel::OnImportClicked()
{
	class CSaleImportListener : public CPromise<CSale::ImportResult_t>::IHttpResponse{
		CONSTRUCTOR_2(CSaleImportListener, CSalePanel&, panel, CString, fileName);
	public:
		virtual void OnSuccess(CSale::ImportResult_t& ret){

			CString result;
			result.Format(_T("数据总数 : %d\r\n导入成功 : %d\r\n导入失败 : %d"), ret.iTotal, ret.iSucceed, ret.iFailed);
			m_panel.MessageBox(result, _T("导入完成"), MB_OK | MB_ICONWARNING);
		}
		virtual void OnFailed(){
			m_panel.MessageBox(_T("销售数据导入失败"), L"导入失败", MB_OK | MB_ICONWARNING);
		}
	};

	CFileDialog hFileDlg(TRUE, _T("(*.csv)|*.csv"), _T("*.csv"), OFN_FILEMUSTEXIST | OFN_READONLY, _T("Excel(*.csv)|*.csv||"), NULL);
	hFileDlg.m_ofn.nFilterIndex = 1;
	hFileDlg.m_ofn.hwndOwner = GetParent()->GetSafeHwnd();
	hFileDlg.m_ofn.lStructSize = sizeof(OPENFILENAME);
	hFileDlg.m_ofn.lpstrTitle = TEXT("选择导入文件位置");
	hFileDlg.m_ofn.nMaxFile = MAX_PATH;

	if (hFileDlg.DoModal() == IDOK)
	{
		CSale::ImportResult_t ret;
		CString filePathName = hFileDlg.GetPathName();
		try{
			CServer::GetInstance()->GetSale().Import(filePathName).then(new CSaleImportListener(*this, filePathName));
		}catch (std::exception& e)
		{
			MessageBoxA(m_hWnd, (char*)e.what(), "导入失败", MB_OK | MB_ICONWARNING);
		}
	}
}
