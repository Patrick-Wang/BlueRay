#include "stdafx.h"
#include "SalePanel.h"
#include "resource_ids.h"
#include "Util.h"
#include "SaleAddDlg.h"
#include "colors.h"
#define RIGHT_AREA_LEFT	150

BEGIN_MESSAGE_MAP(CSalePanel, CControlPanel)
	ON_BN_CLICKED(IDC_SALE_BTN_ADD, &CSalePanel::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SALE_BTN_MODIFY, &CSalePanel::OnBnClickedModify)
	ON_BN_CLICKED(IDC_SALE_BTN_DELETE, &CSalePanel::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SALE_BTN_SEARCH, &CSalePanel::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_SALE_BTN_MORE, &CSalePanel::OnBnClickedMore)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

CSalePanel::CSalePanel(CJQGridAPI* pJqGridAPI)
	: m_pJqGridAPI(pJqGridAPI)
{
	m_pJqGridAPI->d_OnRowChecked += std::make_pair(this, &CSalePanel::OnRowChecked);
	m_pJqGridAPI->d_OnGridComplete += std::make_pair(this, &CSalePanel::OnGridDataLoaded);
	m_table.resize(16);
	for (int i = 0; i < m_table.size(); ++i)
	{
		CString csHTH;
		csHTH.Format(_T("000000%02d"), i + 1);
		if (i % 2 == 0)
		{
			m_table[i].second.push_back(csHTH);
			m_table[i].second.push_back(_T("�㽭����"));
			m_table[i].second.push_back(_T("U1.0ES-H"));
			m_table[i].second.push_back(_T("1"));
			m_table[i].second.push_back(_T("BNN"));
			m_table[i].second.push_back(_T("��"));
			m_table[i].second.push_back(_T("DC110V"));
			m_table[i].second.push_back(_T("480*6*12*18"));
			m_table[i].second.push_back(_T("��"));
			m_table[i].second.push_back(_T("��ʿ"));
			m_table[i].second.push_back(_T("��1387"));
			m_table[i].second.push_back(_T("8��"));
			m_table[i].second.push_back(_T("5��"));
			m_table[i].second.push_back(_T("����Ӣ������"));
			m_table[i].second.push_back(_T("ԭ��ֵ"));
			m_table[i].second.push_back(_T("2014/08/15"));
		}
		else
		{
			m_table[i].second.push_back(csHTH);
			m_table[i].second.push_back(_T("��ԭ����"));
			m_table[i].second.push_back(_T("S1.6D-H"));
			m_table[i].second.push_back(_T("1"));
			m_table[i].second.push_back(_T("RC"));
			m_table[i].second.push_back(_T("��"));
			m_table[i].second.push_back(_T("DC220V"));
			m_table[i].second.push_back(_T("325*5*8*12"));
			m_table[i].second.push_back(_T("��"));
			m_table[i].second.push_back(_T("CV"));
			m_table[i].second.push_back(_T("��1387"));
			m_table[i].second.push_back(_T("10����"));
			m_table[i].second.push_back(_T("5��"));
			m_table[i].second.push_back(_T("��������"));
			m_table[i].second.push_back(_T("D��"));
			m_table[i].second.push_back(_T("2014/11/15"));
		}

	}
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
}
void CSalePanel::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("���"));
	if (IDOK == dlg.DoModal()){
		m_table.push_back(std::make_pair(
			m_pJqGridAPI->AddRow(dlg.GetResult()),
			dlg.GetResult()));
	}

}

void CSalePanel::OnBnClickedModify()
{
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt;
	CSaleAddDlg dlg(_T("�޸�"));
	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	std::vector<int> checkedRowTableMap;
	checkedRowTableMap.resize(checkedRows.size(), -1);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		pRowData = NULL;
		for (int j = 0; i < m_table.size(); ++j)
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
		const std::vector<CString>& result = dlg.GetResult();
		for (int j = result.size() - 1; j >= 0; --j)
		{
			if (!result[j].IsEmpty())
			{
				for (int i = checkedRows.size() - 1; i >= 0; --i)
				{
					if (checkedRowTableMap[i] >= 0)
					{
						m_table[checkedRowTableMap[i]].second[j] = result[j];
					}
					m_pJqGridAPI->SetCell(checkedRows[i], j + 1, result[j]);
				}
			}
		}
	}
}

void CSalePanel::OnBnClickedDelete()
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
	CString searchText;
	m_editSearch->GetWindowText(searchText);
	CString rowData;
	bool bMatch = false;
	for (int i = 0; i < m_table.size(); ++i)
	{
		bMatch = false;
		for (int j = 0; j < m_table[i].second.size(); ++j)
		{
			if (searchText.IsEmpty() || m_table[i].second[j].Find(searchText) >= 0)
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
		}
	}
}


void CSalePanel::OnBnClickedMore()
{
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
				if (!searchVals[j].IsEmpty() && m_table[i].second[j].Compare(searchVals[j]) != 0)
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
			}
		}
	}
}

void CSalePanel::OnGridDataLoaded()
{
	m_pJqGridAPI->d_OnGridComplete -= std::make_pair(this, &CSalePanel::OnGridDataLoaded);
	if (m_pJqGridAPI->GetRowCount() <= 0){
		for (int j = 0; j < m_table.size(); ++j)
		{
			m_table[j].first = m_pJqGridAPI->AddRow(m_table[j].second);
		}
	}
}


void CSalePanel::OnNcDestroy()
{
	CControlPanel::OnNcDestroy();

	// TODO: Add your message handler code here
}



void CSalePanel::OnWindowShow()
{
	m_pJqGridAPI->ShowGrid(_T("sale"));
}

void CSalePanel::OnWindowHide()
{
	m_pJqGridAPI->HideGrid(_T("sale"));
}
