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

static LPCTSTR g_CombItems[][10] = {
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

static int g_CombPos[][4] = {
		{ 100 * 1 + 100 * 0, 40 * 1, 100, 20 },
		{ 100 * 2 + 100 * 1, 40 * 1, 100, 20 },
		{ 100 * 3 + 100 * 2, 40 * 1, 100, 20 },
		{ 100 * 4 + 100 * 3, 40 * 1, 100, 20 },
		{ 100 * 1 + 100 * 0, 40 * 2, 100, 20 },
		{ 100 * 2 + 100 * 1, 40 * 2, 100, 20 },
		{ 100 * 3 + 100 * 2, 40 * 2, 100, 20 },
		{ 100 * 4 + 100 * 3, 40 * 2, 100, 20 },
		{ 100 * 1 + 100 * 0, 40 * 3, 100, 20 },
		{ 100 * 2 + 100 * 1, 40 * 3, 100, 20 }
};

static LPCTSTR g_StaticItems[][1] = {
		{ _T("合同号") },
		{ _T("客户名称") },
		{ _T("规格型号") },
		{ _T("数量") },
		{ _T("轴承") },
		{ _T("单复绕") },
		{ _T("制动器电压") },
		{ _T("曳引轮规格") },
		{ _T("机房") },
		{ _T("变频器型号") },
		{ _T("编码器型号") },
		{ _T("电缆长度") },
		{ _T("闸线长度") },
		{ _T("铭牌等资料") },
		{ _T("订单日期") },
		{ _T("备注") }
};

static int g_StaticPos[][4] = {
		{ 100 * 0 + 100 * 0, 40 * 1, 100, 20 },
		{ 100 * 1 + 100 * 1, 40 * 1, 100, 20 },
		{ 100 * 2 + 100 * 2, 40 * 1, 100, 20 },
		{ 100 * 3 + 100 * 3, 40 * 1, 100, 20 },
		{ 100 * 0 + 100 * 0, 40 * 2, 100, 20 },
		{ 100 * 1 + 100 * 1, 40 * 2, 100, 20 },
		{ 100 * 2 + 100 * 2, 40 * 2, 100, 20 },
		{ 100 * 3 + 100 * 3, 40 * 2, 100, 20 },
		{ 100 * 0 + 100 * 0, 40 * 3, 100, 20 },
		{ 100 * 1 + 100 * 1, 40 * 3, 100, 20 },
		{ 100 * 2 + 100 * 2, 40 * 3, 100, 20 },
		{ 100 * 3 + 100 * 3, 40 * 3, 100, 20 },
		{ 100 * 0 + 100 * 0, 40 * 4, 100, 20 },
		{ 100 * 1 + 100 * 1, 40 * 4, 100, 20 },
		{ 100 * 2 + 100 * 2, 40 * 4, 100, 20 },
		{ 100 * 3 + 100 * 3, 40 * 4, 100, 20 }
};

BOOL CSaleAddDlg::OnInitDialog()
{
	CAddDlg::OnInitDialog();
	for (int i = 0; i < _countof(g_CombItems); ++i)
	{
		m_aCombs[i] = Util::CreateComboBox(this, IDC_ADD_BASE + i);
		m_aCombs[i]->MoveWindow(g_CombPos[i][0], g_CombPos[i][1], g_CombPos[i][2], g_CombPos[i][3]);
		for (int j = 0; j < _countof(g_CombItems[i]); ++j)
		{
			m_aCombs[i]->InsertString(j, g_CombItems[i][j]);
		}
		m_aCombs[i]->SetCurSel(0);
	}

	for (int i = 0; i < _countof(g_StaticItems); ++i)
	{
		m_aStatics[i] = Util::CreateStatic(this, IDB_ADD_STATIC_BASE + i, g_StaticItems[i][0], _T("Segoe UI"), 12);
		m_aStatics[i]->MoveWindow(g_StaticPos[i][0], g_StaticPos[i][1], g_StaticPos[i][2], g_StaticPos[i][3]);
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
	for (int i = 0; i < CombId::Comb_END; ++i)
	{
		m_aCombs[i]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	CAddDlg::OnOKClicked();
}

void CSaleAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}
