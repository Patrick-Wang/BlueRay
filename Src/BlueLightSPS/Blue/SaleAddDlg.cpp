#include "stdafx.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "Util.h"

#define IDC_EDIT_BASE (IDC_ADD_BASE)
#define IDC_COMBO_BASE (IDC_ADD_BASE + 10)
#define IDB_STATIC_BASE (IDC_COMBO_BASE + 20)

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

CSaleAddDlg::CSaleAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CAddDlg(title, pParent)
	, m_lpOption(NULL)
{

}


CSaleAddDlg::~CSaleAddDlg()
{
}


static LPCTSTR g_StaticItems[][1] = { //0: default text
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
		{ 100 * 0 + 100 * 0, 40 * 1, 100, 20 }, //Static_HTH,
		{ 100 * 1 + 100 * 1, 40 * 1, 100, 20 }, //Static_KHMC,
		{ 100 * 2 + 100 * 2, 40 * 1, 100, 20 }, //Static_GGBH,
		{ 100 * 3 + 100 * 3, 40 * 1, 100, 20 }, //Static_SL,
		{ 100 * 0 + 100 * 0, 40 * 2, 100, 20 }, //Static_ZC,
		{ 100 * 1 + 100 * 1, 40 * 2, 100, 20 }, //Static_DFR,
		{ 100 * 2 + 100 * 2, 40 * 2, 100, 20 }, //Static_ZDQDY,
		{ 100 * 3 + 100 * 3, 40 * 2, 100, 20 }, //Static_YYLGG,
		{ 100 * 0 + 100 * 0, 40 * 3, 100, 20 }, //Static_JF,
		{ 100 * 1 + 100 * 1, 40 * 3, 100, 20 }, //Static_BPQXH,
		{ 100 * 2 + 100 * 2, 40 * 3, 100, 20 }, //Static_BMQXH,
		{ 100 * 3 + 100 * 3, 40 * 3, 100, 20 }, //Static_DLCD,
		{ 100 * 0 + 100 * 0, 40 * 4, 100, 20 }, //Static_ZXCD,
		{ 100 * 1 + 100 * 1, 40 * 4, 100, 20 }, //Static_MPZL,
		{ 100 * 2 + 100 * 2, 40 * 4, 100, 20 }, //Static_DDRQ,
		{ 100 * 3 + 100 * 3, 40 * 4, 100, 20 }  //Static_BZ,
};											   

static int g_CombPos[][4] = {
		{ 100 * 2 + 100 * 1, 40 * 1, 100, 20 }, //Comb_KHMC,
		{ 100 * 3 + 100 * 2, 40 * 1, 100, 20 }, //Comb_GGBH,
		{ 100 * 1 + 100 * 0, 40 * 2, 100, 20 }, //Comb_ZC,
		{ 100 * 2 + 100 * 1, 40 * 2, 100, 20 }, //Comb_DFR,
		{ 100 * 3 + 100 * 2, 40 * 2, 100, 20 }, //Comb_ZDQDY,
		{ 100 * 4 + 100 * 3, 40 * 2, 100, 20 }, //Comb_YYLGG,
		{ 100 * 1 + 100 * 0, 40 * 3, 100, 20 }, //Comb_JF,
		{ 100 * 2 + 100 * 1, 40 * 3, 100, 20 }, //Comb_BPQXH,
		{ 100 * 3 + 100 * 2, 40 * 3, 100, 20 }, //Comb_BMQXH,
		{ 100 * 2 + 100 * 1, 40 * 4, 100, 20 }	//Comb_MPZL,
};

static int g_EditsPos[][4] = {
		{ 100 * 1 + 100 * 0, 40 * 1, 100, 20 }, //Edit_HTH,
		{ 100 * 4 + 100 * 3, 40 * 1, 100, 20 }, //Edit_SL,
		{ 100 * 4 + 100 * 3, 40 * 3, 100, 20 }, //Edit_DLCD,
		{ 100 * 1 + 100 * 0, 40 * 4, 100, 20 }, //Edit_ZXCD,
		{ 100 * 3 + 100 * 2, 40 * 4, 100, 20 }, //Edit_DDRQ,
		{ 100 * 4 + 100 * 3, 40 * 4, 100, 20 }, //Edit_BZ,
};												

static LPCTSTR g_EditItems[][1] = { //0: default text
		{ _T("合同号") }, 
		{ _T("数量") },
		{ _T("电缆长度") },
		{ _T("闸线长度") },
		{ _T("订单日期") },
		{ _T("备注") }
};


BOOL CSaleAddDlg::OnInitDialog()
{
	CAddDlg::OnInitDialog();

	//init comb
	for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
	{
		m_aCombs[i] = Util::CreateComboBox(this, IDC_COMBO_BASE + i, _T("Segoe UI"), 12);
		m_aCombs[i]->MoveWindow(g_CombPos[i][0], g_CombPos[i][1], g_CombPos[i][2], g_CombPos[i][3]);
		for (int j = GetDropList()[i].size() - 1; j >= 0; --j)
		{
			m_aCombs[i]->InsertString(0, GetDropList()[i][j]);
		}
	}

	//init static
	for (int i = 0; i < _countof(g_StaticItems); ++i)
	{
		m_aStatics[i] = Util::CreateStatic(this, IDB_STATIC_BASE + i, g_StaticItems[i][0], _T("Segoe UI"), 12);
		m_aStatics[i]->MoveWindow(g_StaticPos[i][0], g_StaticPos[i][1], g_StaticPos[i][2], g_StaticPos[i][3]);
	}
	
	//init edit
	for (int i = 0; i < _countof(g_EditItems); ++i)
	{
		m_aEdits[i] = Util::CreateEdit(this, IDC_EDIT_BASE + i, g_EditItems[i][0], _T("Segoe UI"), 12);
		m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
	}

	if (NULL != m_lpOption)
	{

		//init(m_aEdits[EditId::Edit_HTH], m_lpOption->htbh);
		//init(m_aEdits[EditId::Edit_SL], m_lpOption->sl);
		//init(m_aEdits[EditId::Edit_DLCD], m_lpOption->mpzl);
		//init(m_aEdits[EditId::Edit_ZXCD], m_lpOption->bz);
		//init(m_aEdits[EditId::Edit_DDRQ], m_lpOption->bz);
		//init(m_aEdits[EditId::Edit_BZ], m_lpOption->bz);

		init(m_aCombs[CombId::Comb_KHMC], m_lpOption->khmc);
		init(m_aCombs[CombId::Comb_GGBH], m_lpOption->ggbh);
		init(m_aCombs[CombId::Comb_ZC], m_lpOption->zc);
		init(m_aCombs[CombId::Comb_DFR], m_lpOption->dfr);
		init(m_aCombs[CombId::Comb_ZDQDY], m_lpOption->zdqdy);
		init(m_aCombs[CombId::Comb_YYLGG], m_lpOption->yylgg);
		init(m_aCombs[CombId::Comb_JF], m_lpOption->jf);
		init(m_aCombs[CombId::Comb_BPQXH], m_lpOption->bpqxh);
		init(m_aCombs[CombId::Comb_BMQXH], m_lpOption->bmqxh);
		init(m_aCombs[CombId::Comb_MPZL], m_lpOption->mpzl);
		//init(m_aCombs[CombId::Comb_DLCD], m_lpOption->dlcd);
		//init(m_aCombs[CombId::Comb_ZXCD], m_lpOption->zxcd);
	}
	else
	{
		init(m_aCombs[CombId::Comb_KHMC], 0);
		init(m_aCombs[CombId::Comb_GGBH], 0);
		init(m_aCombs[CombId::Comb_ZC], 0);
		init(m_aCombs[CombId::Comb_DFR], 0);
		init(m_aCombs[CombId::Comb_ZDQDY], 0);
		init(m_aCombs[CombId::Comb_YYLGG], 0);
		init(m_aCombs[CombId::Comb_JF], 0);
		init(m_aCombs[CombId::Comb_BPQXH], 0);
		init(m_aCombs[CombId::Comb_BMQXH], 0);
		init(m_aCombs[CombId::Comb_MPZL], 0);
		//init(m_aCombs[CombId::Comb_DLCD], 0);
		//init(m_aCombs[CombId::Comb_ZXCD], 0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSaleAddDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CFont* pFont = NULL;
	for (int i = 0; i < _countof(m_aCombs); ++i)
	{
		if (NULL != m_aCombs[i])
		{
			delete m_aCombs[i];
		}
	}

	for (int i = 0; i < _countof(m_aStatics); ++i)
	{
		if (NULL != m_aStatics[i])
		{
			delete m_aStatics[i];
		}
	}

	for (int i = 0; i < _countof(m_aEdits); ++i)
	{
		if (NULL != m_aEdits[i])
		{
			delete m_aEdits[i];
		}
	}

	CAddDlg::PostNcDestroy();
}

void CSaleAddDlg::OnOKClicked()
{
	CString strTmp;

	m_aEdits[EditId::Edit_HTH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->htbh : _T("")));
	
	m_aCombs[CombId::Comb_KHMC]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);
	
	m_aCombs[CombId::Comb_GGBH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);
	
	m_aEdits[EditId::Edit_SL]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->sl : _T("")));

	m_aCombs[CombId::Comb_ZC]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_DFR]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZDQDY]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zdqdy : 0));
	
	m_aCombs[CombId::Comb_YYLGG]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->yylgg : 0));
	
	m_aCombs[CombId::Comb_JF]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->jf : 0));
	
	m_aCombs[CombId::Comb_BPQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bpqxh : 0));
	
	m_aCombs[CombId::Comb_BMQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bmqxh : 0));
	
	//m_aCombs[CombId::Comb_DLCD]->GetWindowText(strTmp);
	//m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->dlcd : 0));
	
	//m_aCombs[CombId::Comb_ZXCD]->GetWindowText(strTmp);
	//m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zxcd : 0));
	
	m_aEdits[EditId::Edit_DLCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->dlcd : _T("")));
	
	m_aEdits[EditId::Edit_ZXCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zxcd : _T("")));
	
	m_aCombs[CombId::Comb_MPZL]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bmqxh : 0));

	m_aEdits[EditId::Edit_DDRQ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->ddrq : _T("")));
	
	m_aEdits[EditId::Edit_BZ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bz : _T("")));

	CAddDlg::OnOKClicked();
}

void CSaleAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}

const std::vector<std::vector<CString>>& CSaleAddDlg::GetDropList()
{
	if (m_DropList.empty())
	{
		m_DropList.resize(CombId::Comb_END);

		//客户名称
		m_DropList[Comb_KHMC].push_back(_T("浙江怡达")); 
		m_DropList[Comb_KHMC].push_back(_T("中原智能"));
		m_DropList[Comb_KHMC].push_back(_T("恒达富士"));
		m_DropList[Comb_KHMC].push_back(_T("天津奥斯达"));
		m_DropList[Comb_KHMC].push_back(_T("预投"));

		//规格型号
		m_DropList[Comb_GGBH].push_back(_T("U1.0ES-H"));
		m_DropList[Comb_GGBH].push_back(_T("S1.6C-H"));
		m_DropList[Comb_GGBH].push_back(_T("TA1.5C-H"));
		m_DropList[Comb_GGBH].push_back(_T("TA1.0CZ - H"));

		//轴承
		m_DropList[Comb_ZC].push_back(_T("BNN"));
		m_DropList[Comb_ZC].push_back(_T("RC"));

		//单复绕
		m_DropList[Comb_DFR].push_back(_T("是"));
		m_DropList[Comb_DFR].push_back(_T("否"));

		//制动器电压
		m_DropList[Comb_ZDQDY].push_back(_T("DC110V"));
		m_DropList[Comb_ZDQDY].push_back(_T("AC220V"));
		m_DropList[Comb_ZDQDY].push_back(_T("DC220V"));

		//曳引轮规格
		m_DropList[Comb_YYLGG].push_back(_T("480 * 6 * 12 * 18"));
		m_DropList[Comb_YYLGG].push_back(_T("400 * 5 * 10 * 16"));
		m_DropList[Comb_YYLGG].push_back(_T("325 * 5 * 8 * 12")); 
		m_DropList[Comb_YYLGG].push_back(_T("400 * 5 * 10 * 16 - 2(SB)"));

		//机房
		m_DropList[Comb_JF].push_back(_T("有"));
		m_DropList[Comb_JF].push_back(_T("无"));

		//变频器型号
		m_DropList[Comb_BPQXH].push_back(_T("富士"));
		m_DropList[Comb_BPQXH].push_back(_T("默纳克"));
		m_DropList[Comb_BPQXH].push_back(_T("CV"));
		m_DropList[Comb_BPQXH].push_back(_T("蓝光一体化"));

		//编码器型号
		m_DropList[Comb_BMQXH].push_back(_T("海1387"));
		m_DropList[Comb_BMQXH].push_back(_T("其他"));

		//铭牌等资料
		m_DropList[Comb_MPZL].push_back(_T("蓝光英文铭牌"));
		m_DropList[Comb_MPZL].push_back(_T("蓝光铭牌"));
		m_DropList[Comb_MPZL].push_back(_T("蓝光英文西门子监制"));
		m_DropList[Comb_MPZL].push_back(_T("主机用西德英文铭牌，制动器和上行超速铭牌用蓝光英文"));

		//电缆长度
		//m_DropList[Comb_DLCD].push_back(_T("0"));

		//闸线长度
		//m_DropList[Comb_ZXCD].push_back(_T("0"));

	}
	return m_DropList;
}

std::vector<std::vector<CString>> CSaleAddDlg::m_DropList;
