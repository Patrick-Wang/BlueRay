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
		{ 0, 0, 100, 20 },
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

	for (int i = 0; i < _countof(g_Items); ++i)
	{
		m_aCombs[i] = Util::CreateComboBox(this, IDC_COMBO_BASE + i);
		m_aCombs[i]->MoveWindow(g_Pos[i][0], g_Pos[i][1], g_Pos[i][2], g_Pos[i][3]);
		for (int j = 0; j < _countof(g_Items[i]); ++j)
		{
			m_aCombs[i]->InsertString(j, g_Items[i][j]);
		}
	}

	if (NULL != m_lpOption)
	{
		init(m_htbhEdit, m_lpOption->htbh);
		init(m_slEdit, m_lpOption->sl);
		init(m_mpzlEdit, m_lpOption->mpzl);
		init(m_bzEdit, m_lpOption->bz);
		init(m_bzEdit, m_lpOption->bz);
		init(m_aCombs[CombId::KHMC], m_lpOption->bmqxh);
		init(m_aCombs[CombId::GGBH], m_lpOption->ggbh);
		init(m_aCombs[CombId::DFR], m_lpOption->dfr);
		init(m_aCombs[CombId::ZDQDY], m_lpOption->zdqdy);
		init(m_aCombs[CombId::ZYLGG], m_lpOption->zylgg);
		init(m_aCombs[CombId::JF], m_lpOption->jf);
		init(m_aCombs[CombId::BPQXH], m_lpOption->bpqxh);
		init(m_aCombs[CombId::BMQXH], m_lpOption->bmqxh);
		init(m_aCombs[CombId::DLCD], m_lpOption->dlcd);
		init(m_aCombs[CombId::ZXCD], m_lpOption->zxcd);
	}
	else
	{
		init(m_aCombs[CombId::KHMC], 0);
		init(m_aCombs[CombId::GGBH], 0);
		init(m_aCombs[CombId::DFR], 0);
		init(m_aCombs[CombId::ZDQDY], 0);
		init(m_aCombs[CombId::ZYLGG], 0);
		init(m_aCombs[CombId::JF], 0);
		init(m_aCombs[CombId::BPQXH], 0);
		init(m_aCombs[CombId::BMQXH], 0);
		init(m_aCombs[CombId::DLCD], 0);
		init(m_aCombs[CombId::ZXCD], 0);
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
	m_aCombs[CombId::KHMC]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::GGBH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::DFR]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::ZDQDY]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::ZYLGG]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::JF]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::BPQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::BMQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::DLCD]->GetWindowText(strTmp);
	m_vecResult.push_back(CompareWithOptFalse(strTmp));
	m_aCombs[CombId::ZXCD]->GetWindowText(strTmp);
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
