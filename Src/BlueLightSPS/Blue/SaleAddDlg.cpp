#include "stdafx.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "Util.h"

#define IDC_COMBO_BASE (IDC_ADD_BASE + 10)
#define IDC_EDIT_BASE (IDC_ADD_BASE)

inline void init(CEdit& edit, CString& val){
	if (val != OPT_FALSE)
	{
		edit.SetWindowText(val);
	}
}

inline void init(CComboBox* comb, int val){
	if (val != OPT_FALSE_INT)
	{
		comb->SetCurSel(val);
	}
}

inline CString& CompareWithOptFalse(CString& text){
	if (text.IsEmpty())
	{
		text = OPT_FALSE;
	}
	return text;
}

CSaleAddDlg::CSaleAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CAddDlg(title, pParent)
	, m_lpOption(NULL)
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
	m_htbhEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE/* | WS_BORDER | WS_HSCROLL |
							 WS_VSCROLL | ES_MULTILINE */ | ES_WANTRETURN,
							 CRect(120, 0, 400, 30), this, IDC_EDIT_BASE);
	m_slEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE/* | WS_BORDER | WS_HSCROLL |
							 WS_VSCROLL | ES_MULTILINE */ | ES_WANTRETURN,
							 CRect(120, 30, 400, 60), this, IDC_EDIT_BASE + 1);
	m_mpzlEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE/* | WS_BORDER | WS_HSCROLL |
							 WS_VSCROLL | ES_MULTILINE*/ | ES_WANTRETURN,
							 CRect(120, 60, 400, 90), this, IDC_EDIT_BASE + 2);
	m_bzEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
		WS_CHILD | WS_VISIBLE/* | WS_BORDER | WS_HSCROLL |
							 WS_VSCROLL | ES_MULTILINE*/ | ES_WANTRETURN,
							 CRect(120, 90, 400, 120), this, IDC_EDIT_BASE + 3);


	for (int i = 0; i < _countof(g_CombItems); ++i)
	{
		m_aCombs[i] = Util::CreateComboBox(this, IDC_COMBO_BASE + i);
		m_aCombs[i]->MoveWindow(g_CombPos[i][0], g_CombPos[i][1], g_CombPos[i][2], g_CombPos[i][3]);
		for (int j = 0; j < _countof(g_CombItems[i]); ++j)
		{
			m_aCombs[i]->InsertString(j, g_CombItems[i][j]);
		}
	}


	for (int i = 0; i < _countof(g_StaticItems); ++i)
	{
		m_aStatics[i] = Util::CreateStatic(this, IDB_ADD_STATIC_BASE + i, g_StaticItems[i][0], _T("Segoe UI"), 12);
		m_aStatics[i]->MoveWindow(g_StaticPos[i][0], g_StaticPos[i][1], g_StaticPos[i][2], g_StaticPos[i][3]);
	}
	

	if (NULL != m_lpOption)
	{
		init(m_htbhEdit, m_lpOption->htbh);
		init(m_slEdit, m_lpOption->sl);
		init(m_mpzlEdit, m_lpOption->mpzl);
		init(m_bzEdit, m_lpOption->bz);
		init(m_bzEdit, m_lpOption->bz);
		init(m_aCombs[CombId::Comb_KHMC], m_lpOption->bmqxh);
		init(m_aCombs[CombId::Comb_GGBH], m_lpOption->ggbh);
		init(m_aCombs[CombId::Comb_DFR], m_lpOption->dfr);
		init(m_aCombs[CombId::Comb_ZDQDY], m_lpOption->zdqdy);
		init(m_aCombs[CombId::Comb_YYLGG], m_lpOption->zylgg);
		init(m_aCombs[CombId::Comb_JF], m_lpOption->jf);
		init(m_aCombs[CombId::Comb_BPQXH], m_lpOption->bpqxh);
		init(m_aCombs[CombId::Comb_BMQXH], m_lpOption->bmqxh);
		init(m_aCombs[CombId::Comb_DLCD], m_lpOption->dlcd);
		init(m_aCombs[CombId::Comb_ZXCD], m_lpOption->zxcd);
	}
	else
	{
		init(m_aCombs[CombId::Comb_KHMC], 0);
		init(m_aCombs[CombId::Comb_GGBH], 0);
		init(m_aCombs[CombId::Comb_DFR], 0);
		init(m_aCombs[CombId::Comb_ZDQDY], 0);
		init(m_aCombs[CombId::Comb_YYLGG], 0);
		init(m_aCombs[CombId::Comb_JF], 0);
		init(m_aCombs[CombId::Comb_BPQXH], 0);
		init(m_aCombs[CombId::Comb_BMQXH], 0);
		init(m_aCombs[CombId::Comb_DLCD], 0);
		init(m_aCombs[CombId::Comb_ZXCD], 0);
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
	m_aCombs[CombId::Comb_KHMC]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_GGBH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_DFR]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_ZDQDY]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_YYLGG]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_JF]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_BPQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_BMQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_DLCD]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::Comb_ZXCD]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_htbhEdit.GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_slEdit.GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_mpzlEdit.GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_bzEdit.GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));

	CAddDlg::OnOKClicked();
}

void CSaleAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}
