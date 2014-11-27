#include "stdafx.h"
#include "SalePanel.h"
#include "resource_ids.h"
#include "Util.h"
#include "SaleAddDlg.h"
#include "colors.h"
#include "JQGridAPI.h"
#define UM_REQUEST_RESULT

#define RIGHT_AREA_LEFT	150
#define QUERY_URL_ID IDP_SALE + 1
#define ADD_URL_ID IDP_SALE + 2
#define DEL_URL_ID IDP_SALE + 3
#define MODIFY_URL_ID IDP_SALE + 4


BEGIN_MESSAGE_MAP(CSalePanel, CControlPanel)
	ON_BN_CLICKED(IDC_SALE_BTN_ADD, &CSalePanel::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SALE_BTN_MODIFY, &CSalePanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_SALE_BTN_DELETE, &CSalePanel::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SALE_BTN_SEARCH, &CSalePanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_SALE_BTN_MORE, &CSalePanel::OnBnClickedMore)
	ON_WM_SHOWWINDOW()
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

CSalePanel::CSalePanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: m_pJqGridAPI(pJqGridAPI)
	, m_pHttp(pHttp)
{
	m_pJqGridAPI->d_OnRowChecked += std::make_pair(this, &CSalePanel::OnRowChecked);
	m_pHttp->d_OnSuccess += std::make_pair(this, &CSalePanel::OnHttpSuccess);
	m_pHttp->d_OnFailed += std::make_pair(this, &CSalePanel::OnHttpFailed);

	//m_table.resize(16);
	//for (int i = 0; i < m_table.size(); ++i)
	//{
	//	CString csHTH;
	//	csHTH.Format(_T("000000%02d"), i + 1);
	//	if (i % 2 == 0)
	//	{
	//		m_table[i].second.push_back(csHTH);
	//		m_table[i].second.push_back(_T("�㽭����"));
	//		m_table[i].second.push_back(_T("U1.0ES-H"));
	//		m_table[i].second.push_back(_T("1"));
	//		m_table[i].second.push_back(_T("BNN"));
	//		m_table[i].second.push_back(_T("��"));
	//		m_table[i].second.push_back(_T("DC110V"));
	//		m_table[i].second.push_back(_T("480*6*12*18"));
	//		m_table[i].second.push_back(_T("��"));
	//		m_table[i].second.push_back(_T("��ʿ"));
	//		m_table[i].second.push_back(_T("��1387"));
	//		m_table[i].second.push_back(_T("8��"));
	//		m_table[i].second.push_back(_T("5��"));
	//		m_table[i].second.push_back(_T("����Ӣ������"));
	//		m_table[i].second.push_back(_T("ԭ��ֵ"));
	//		m_table[i].second.push_back(_T("2014/08/15"));
	//	}
	//	else
	//	{
	//		m_table[i].second.push_back(csHTH);
	//		m_table[i].second.push_back(_T("��ԭ����"));
	//		m_table[i].second.push_back(_T("S1.6D-H"));
	//		m_table[i].second.push_back(_T("1"));
	//		m_table[i].second.push_back(_T("RC"));
	//		m_table[i].second.push_back(_T("��"));
	//		m_table[i].second.push_back(_T("DC220V"));
	//		m_table[i].second.push_back(_T("325*5*8*12"));
	//		m_table[i].second.push_back(_T("��"));
	//		m_table[i].second.push_back(_T("CV"));
	//		m_table[i].second.push_back(_T("��1387"));
	//		m_table[i].second.push_back(_T("10����"));
	//		m_table[i].second.push_back(_T("5��"));
	//		m_table[i].second.push_back(_T("��������"));
	//		m_table[i].second.push_back(_T("D��"));
	//		m_table[i].second.push_back(_T("2014/11/15"));
	//	}

	//}
}



CSalePanel::~CSalePanel()
{
}

void CSalePanel::OnInitChilds()
{
	int delta = 277 - (RIGHT_AREA_LEFT + 15);
	m_editSearch = Util::CreateEdit(this, IDC_SALE_BTN_SEARCH, _T(""), _T("Microsoft YaHei"), 12);
	m_editSearch->MoveWindow(235, 27, 240, 20);

	m_btnAdd.Create(this, IDC_SALE_BTN_ADD);
	m_btnAdd.SetWindowText(_T("���"));
	m_btnAdd.SetBSFont(12);
	m_btnAdd.MoveWindow(20, 25, 90, 25);

	m_btnDelete.Create(this, IDC_SALE_BTN_DELETE);
	m_btnDelete.SetWindowText(_T("ɾ��"));
	m_btnDelete.MoveWindow(125, 70, 90, 25);

	m_btnModify.Create(this, IDC_SALE_BTN_MODIFY);
	m_btnModify.SetWindowText(_T("�޸�"));
	m_btnModify.MoveWindow(20, 70, 90, 25);

	m_btnSearch.Create(this, IDC_SALE_BTN_SEARCH);
	m_btnSearch.SetWindowText(_T("��ѯ"));
	m_btnSearch.MoveWindow(125, 25, 90, 25);

	m_btnMore.Create(this, IDC_SALE_BTN_MORE);
	m_btnMore.SetWindowText(_T(">"));
	m_btnMore.MoveWindow(566, 25, 30, 25);

	m_bsMoreWord.Create(this, IDC_SALE_BTN_MOREWORD);
	m_bsMoreWord.SetWindowText(_T("����ɸѡ"));
	m_bsMoreWord.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsMoreWord.MoveWindow(485, 27, 63, 20);

	m_btnDelete.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);

	m_pHttp->Get(_T("http://10.1.4.107:8080/BlueRay/sale/query"), QUERY_URL_ID);
	GetParent()->EnableWindow(FALSE);
}
void CSalePanel::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("���"));
	dlg.InitHttpInstance(m_pHttp);
	if (IDOK == dlg.DoModal()){
		GetParent()->EnableWindow(FALSE);
		m_cacheRow = dlg.GetResult();
		std::map<CString, StringArrayPtr> attr;
		attr[_T("add")] = &m_cacheRow;
		m_pHttp->Post(_T("http://10.1.4.107:8080/BlueRay/sale/add"), ADD_URL_ID, attr);
	}
}

void CSalePanel::OnBnClickedModify()
{
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt;
	CSaleAddDlg dlg(_T("�޸�"));
	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		pRowData = NULL;
		for (int j = 0; i < m_table.size(); ++j)
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
				pstOpt.reset(new CSaleAddDlg::Option_t(*pRowData));
			}
			else
			{
				pstOpt->Merge(*pRowData);
			}
		}
	}
	dlg.SetOption(pstOpt.get());
	if (IDOK == dlg.DoModal()){
		GetParent()->EnableWindow(FALSE);
		//std::map<CString, std::vector<CString&>> attr;
		//attr[_T("add")] = m_cacheRow;
		//m_pHttp->Post(_T("http://10.1.4.107:8080/BlueRay/sale/modify"), MODIFY_URL_ID, std::map<CString, CString>(), _T(""));
		m_cacheRow = dlg.GetResult();
	}
}

void CSalePanel::OnBnClickedDelete()
{
	if (IDOK == MessageBox(_T("�Ƿ�ȷ��ɾ���˼�¼�� ��ע�⣬ɾ�����޷��ָ���"), _T("ɾ��"), MB_OKCANCEL | MB_ICONQUESTION))
	{
		std::vector<int> checkedRows;
		m_pJqGridAPI->GetCheckedRows(checkedRows);
		GetParent()->EnableWindow(FALSE);
		std::map<CString, IntArrayPtr> attr;
		attr[_T("del")] = &checkedRows;
		m_pHttp->Post(_T("http://10.1.4.107:8080/BlueRay/sale/delete"), DEL_URL_ID, attr);
	}
}

void CSalePanel::OnRowChecked()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	if (checkedRows.empty())
	{
		m_btnDelete.EnableWindow(FALSE);
		m_btnModify.EnableWindow(FALSE);
	}
	else{
		m_btnDelete.EnableWindow(TRUE);
		m_btnModify.EnableWindow(TRUE);
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
		MessageBox(_T("û�з��������ļ�¼"), _T("��ѯ���"), MB_OK | MB_ICONWARNING);
	}
}


void CSalePanel::OnBnClickedMore()
{
	int iCountShot = 0;
	CSaleAddDlg dlg(_T("�߼�����"));
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt(new CSaleAddDlg::Option_t());
	dlg.SetOption(pstOpt.get());
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
			MessageBox(_T("û�з��������ļ�¼"), _T("��ѯ���"), MB_OK | MB_ICONWARNING);
		}
	}
}


void CSalePanel::OnNcDestroy()
{
	CControlPanel::OnNcDestroy();
}


void CSalePanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CControlPanel::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		m_pJqGridAPI->ShowGrid(_T("sale"));
	}
	else
	{
		m_pJqGridAPI->HideGrid(_T("sale"));
	}

}


void CSalePanel::OnHttpSuccess(int id, LPCTSTR resp)
{
	GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_URL_ID:
		OnLoadDataSuccess(CString(resp));
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
		MessageBox(_T("��ȡ����ʧ��"), _T("����"), MB_OK | MB_ICONWARNING);
		break;
	case ADD_URL_ID:
		MessageBox(_T("�������ʧ��"), _T("����"), MB_OK | MB_ICONWARNING);
		break;
	case DEL_URL_ID:
		MessageBox(_T("ɾ������ʧ��"), _T("����"), MB_OK | MB_ICONWARNING);
		break;
	case MODIFY_URL_ID:
		MessageBox(_T("�޸�����ʧ��"), _T("����"), MB_OK | MB_ICONWARNING);
		break;
	default:
		break;
	}

}

void CSalePanel::OnLoadDataSuccess(CString& jsondata)
{
	std::vector<CString> vec;
	jsondata.Replace(_T("],["), _T("#"));
	jsondata.Remove(_T('['));
	jsondata.Remove(_T(']'));
	jsondata.Remove(_T('\"'));
	CJQGridAPI::Split(jsondata, _T('#'), vec);
	m_table.resize(vec.size());
	for (int i = 0; i < vec.size(); ++i)
	{
		CJQGridAPI::Split(vec[i], _T(','), m_table[i].second);
		m_table[i].first = _tstoi(m_table[i].second[0]);
		m_table[i].second.erase(m_table[i].second.begin());
	}
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
}

void CSalePanel::OnModifyDataSuccess(std::vector<CString>& newData)
{

	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	std::vector<int> checkedRowTableMap;
	checkedRowTableMap.resize(checkedRows.size(), -1);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		for (int j = 0; i < m_table.size(); ++j)
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
}

void CSalePanel::OnAddDataSuccess(int id, std::vector<CString>& data)
{
	m_table.push_back(std::make_pair(
		id,
		data));
	m_pJqGridAPI->AddRow(id, data);
}
