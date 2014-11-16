#include "stdafx.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "Util.h"
CSaleAddDlg::CSaleAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CAddDlg(title, pParent)
{

}


CSaleAddDlg::~CSaleAddDlg()
{
}

static LPCTSTR g_Items[][10] = {
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") },
		{ _T("1"), _T("2") }
};

static int g_Pos[][4] = {
		{ 0, 0, 100, 20},
		{ 0, 20, 100, 20 },
		{ 0, 20 * 2, 100, 20 },
		{ 0, 20 * 3, 100, 20 },
		{ 0, 20 * 4, 100, 20 },
		{ 0, 20 * 5, 100, 20 },
		{ 0, 20 * 6, 100, 20 },
		{ 0, 20 * 7, 100, 20 },
		{ 0, 20 * 8, 100, 20 },
		{ 0, 20 * 9, 100, 20 }
};

BOOL CSaleAddDlg::OnInitDialog()
{
	CAddDlg::OnInitDialog();
	for (int i = 0; i < _countof(g_Items); ++i)
	{
		m_aCombs[i] = Util::CreateComboBox(this, IDC_ADD_BASE + i);
		m_aCombs[i]->MoveWindow(g_Pos[i][0], g_Pos[i][1], g_Pos[i][2], g_Pos[i][3]);
		for (int j = 0; j < _countof(g_Items[i]); ++j)
		{
			m_aCombs[i]->InsertString(j, g_Items[i][j]);
		}
		m_aCombs[i]->SetCurSel(0);
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSaleAddDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	CAddDlg::PostNcDestroy();
}

void CSaleAddDlg::OnOKClicked()
{
	CString strTmp;
	for (int i = 0; i < CombId::END; ++i)
	{
		m_aCombs[i]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	CAddDlg::OnOKClicked();
}
