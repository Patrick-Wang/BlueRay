#include "stdafx.h"
#include "Server.h"
#include "Sale.h"
#include "SaleAddDlg.h"
#include "resource_ids.h"
#include "CommonDefine.h"
#include "Util.h"
#include "JQGridAPI.h"

#define IDC_EDIT_BASE (IDC_SALE_ADD_Control_BASE)
#define IDC_COMBO_BASE (IDC_SALE_ADD_Control_BASE + 10)
#define IDC_STATIC_BASE (IDC_COMBO_BASE + 20)
#define IDC_DATETIME_BASE (IDC_STATIC_BASE + 10)

#define QUERY_COMBO_VALUE_KHMC_URL_ID		IDP_SALE_ADD + 1
#define QUERY_COMBO_VALUE_GGBH_URL_ID		IDP_SALE_ADD + 2
#define QUERY_COMBO_VALUE_ZC_URL_ID			IDP_SALE_ADD + 3
#define QUERY_COMBO_VALUE_DFR_URL_ID		IDP_SALE_ADD + 4
#define QUERY_COMBO_VALUE_ZDQDY_URL_ID		IDP_SALE_ADD + 5
#define QUERY_COMBO_VALUE_YYLGG_URL_ID		IDP_SALE_ADD + 6
#define QUERY_COMBO_VALUE_JF_URL_ID			IDP_SALE_ADD + 7
#define QUERY_COMBO_VALUE_BPQXH_URL_ID		IDP_SALE_ADD + 8
#define QUERY_COMBO_VALUE_BMQXH_URL_ID		IDP_SALE_ADD + 9
#define QUERY_COMBO_VALUE_MPZL_URL_ID		IDP_SALE_ADD + 10
#define QUERY_COMBO_VALUE_ZJDY_URL_ID		IDP_SALE_ADD + 11
#define QUERY_COMBO_VALUE_ZJYS_URL_ID		IDP_SALE_ADD + 12
#define QUERY_COMBO_VALUE_ZDQXH_URL_ID		IDP_SALE_ADD + 13
#define QUERY_COMBO_VALUE_BZXDTGG_URL_ID	IDP_SALE_ADD + 14
#define QUERY_COMBO_VALUE_ZZS_URL_ID		IDP_SALE_ADD + 15
#define QUERY_COMBO_VALUE_KHQY_URL_ID		IDP_SALE_ADD + 16


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
		{ _T("备注") },
		{ _T("主机电压") },
		{ _T("主机颜色") },
		{ _T("制动器型号") },
		{ _T("左/右置") },
		{ _T("包装箱/底托规格") },
		{ _T("制造商") },
		{ _T("客户区域") },
		{ _T("优先级") },
		{ _T("工号") }
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
		{ 100 * 3 + 100 * 3, 40 * 4, 100, 20 },  //Static_BZ,
		{ 100 * 0 + 100 * 0, 40 * 5, 100, 20 }, 
		{ 100 * 1 + 100 * 1, 40 * 5, 100, 20 }, 
		{ 100 * 2 + 100 * 2, 40 * 5, 100, 20 }, 
		{ 100 * 3 + 100 * 3, 40 * 5, 100, 20 }, 
		{ 100 * 0 + 100 * 0, 40 * 6, 100, 20 }, 
		{ 100 * 1 + 100 * 1, 40 * 6, 100, 20 }, 
		{ 100 * 2 + 100 * 2, 40 * 6, 100, 20 }, 
		{ 100 * 3 + 100 * 3, 40 * 6, 100, 20 },
		{ 100 * 0 + 100 * 0, 40 * 7, 100, 20 }
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
		{ 100 * 2 + 100 * 1, 40 * 4, 100, 20 },	//Comb_MPZL,
		{ 100 * 1 + 100 * 0, 40 * 5, 100, 20 }, 
		{ 100 * 2 + 100 * 1, 40 * 5, 100, 20 }, 
		{ 100 * 3 + 100 * 2, 40 * 5, 100, 20 }, 
		{ 100 * 4 + 100 * 3, 40 * 5, 100, 20 }, 
		{ 100 * 1 + 100 * 0, 40 * 6, 100, 20 }, 
		{ 100 * 2 + 100 * 1, 40 * 6, 100, 20 }, 
		{ 100 * 3 + 100 * 2, 40 * 6, 100, 20 }, 
		{ 100 * 4 + 100 * 3, 40 * 6, 100, 20 }
};

static int g_DatePickersPos[][4] = {
		{ 100 * 3 + 100 * 2, 40 * 4, 100, 20 }, //Edit_DDRQ,
};

static int g_EditsPos[][4] = {
		{ 100 * 1 + 100 * 0, 40 * 1, 100, 20 }, //Edit_HTH,
		{ 100 * 4 + 100 * 3, 40 * 1, 100, 20 }, //Edit_SL,
		{ 100 * 4 + 100 * 3, 40 * 3, 100, 20 }, //Edit_DLCD,
		{ 100 * 1 + 100 * 0, 40 * 4, 100, 20 }, //Edit_ZXCD,
		{ 100 * 4 + 100 * 3, 40 * 4, 100, 20 }, //Edit_BZ,
		{ 100 * 1 + 100 * 0, 40 * 7, 100, 20 } //Edit_GH,
};

static LPCTSTR g_EditItems[][1] = { //0: default text
		{ _T("合同号") },
		{ _T("数量") },
		{ _T("电缆长度") },
		{ _T("闸线长度") },
		{ _T("订单日期") },
		{ _T("备注") },
		{ _T("工号") },
};

inline void init(CEdit* edit, CString& val){
	if (val != OPT_FALSE)
	{
		edit->SetWindowText(val);
	}
	else
	{
		edit->EnableWindow(TRUE);
	}

}

inline void init(CDateTimeCtrl* dateTime, CString& val){
	if (val != OPT_FALSE)
	{
		if (_T("") == val)
		{
			COleDateTime oletimeTime;
			oletimeTime.SetStatus(COleDateTime::null);
			dateTime->SetTime(oletimeTime);
		}
		else
		{
			COleVariant VariantTime;
			VariantTime = val;
			VariantTime.ChangeType(VT_DATE);
			COleDateTime DataTime = VariantTime;

			dateTime->SetTime(DataTime);
		}
	}
}

inline void init(CComboBox* comb, int val){
	if (val != OPT_FALSE_INT)
	{
		comb->SetCurSel(val);
	}
}

CSaleAddDlg::CSaleAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CPopupDlg(title, pParent)
	, m_lpOption(NULL)
{
	InitHttpInstance();
}



CSaleAddDlg::~CSaleAddDlg()
{

}

void CSaleAddDlg::InitHttpInstance()
{
	if (m_DropList.empty())
	{
		m_DropList.resize(CombId::Comb_END);
		CItem& item = CServer::GetInstance()->GetItem();

		//客户名称
		CString url;
		item.QuerySync(CItem::KHXX, m_DropList[CombId::Comb_KHMC]);
		++m_iRef;

		//规格型号
		item.QuerySync(CItem::CPGGXHXX, m_DropList[CombId::Comb_GGBH]);
		++m_iRef;

		//轴承
		item.QuerySync(CItem::ZCXX, m_DropList[CombId::Comb_ZC]);
		++m_iRef;

		//单复绕
		m_DropList[Comb_DFR].push_back(_T("是"));
		m_DropList[Comb_DFR].push_back(_T("否"));

		//制动器电压
		item.QuerySync(CItem::ZDQDYFLXX, m_DropList[CombId::Comb_ZDQDY]);
		++m_iRef;

		//曳引轮规格
		item.QuerySync(CItem::YYLGGFLXX, m_DropList[CombId::Comb_YYLGG]);
		++m_iRef;

		//机房
		m_DropList[Comb_JF].push_back(_T("是"));
		m_DropList[Comb_JF].push_back(_T("否"));

		//变频器型号
		item.QuerySync(CItem::BPQXHFLXX, m_DropList[CombId::Comb_BPQXH]);

		//编码器型号
		item.QuerySync(CItem::BMQXHFLXX, m_DropList[CombId::Comb_BMQXH]);

		//铭牌等资料
		item.QuerySync(CItem::MPZLXX, m_DropList[CombId::Comb_MPZL]);

		//主机电压
		item.QuerySync(CItem::ZJDY, m_DropList[CombId::Comb_ZJDY]);

		//主机颜色
		item.QuerySync(CItem::ZJYS, m_DropList[CombId::Comb_ZJYS]);

		//制动器型号
		item.QuerySync(CItem::ZDQXH, m_DropList[CombId::Comb_ZDQXH]);

		//左 / 右置
		m_DropList[Comb_ZYZ].push_back(_T("是"));
		m_DropList[Comb_ZYZ].push_back(_T("否"));

		//包装箱 / 底托规格
		item.QuerySync(CItem::BZXDTGG, m_DropList[CombId::Comb_BZXDTGG]);

		//制造商
		item.QuerySync(CItem::ZZS, m_DropList[CombId::Comb_ZZS]);

		//客户区域
		item.QuerySync(CItem::KHQY, m_DropList[CombId::Comb_KHQY]);
		
		//优先级
		m_DropList[Comb_YXJ].push_back(_T("低"));
		m_DropList[Comb_YXJ].push_back(_T("高"));

	}
}

void CSaleAddDlg::OnHttpSuccess(int id, LPCTSTR resp)
{
	switch (id)
	{
	case QUERY_COMBO_VALUE_KHMC_URL_ID:
		OnLoadComboDataSuccess(Comb_KHMC, CString(resp));
		break;
	case QUERY_COMBO_VALUE_GGBH_URL_ID:
		OnLoadComboDataSuccess(Comb_GGBH, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZC_URL_ID:
		OnLoadComboDataSuccess(Comb_ZC, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZDQDY_URL_ID:
		OnLoadComboDataSuccess(Comb_ZDQDY, CString(resp));
		break;
	case QUERY_COMBO_VALUE_YYLGG_URL_ID:
		OnLoadComboDataSuccess(Comb_YYLGG, CString(resp));
		break;
	case QUERY_COMBO_VALUE_BPQXH_URL_ID:
		OnLoadComboDataSuccess(Comb_BPQXH, CString(resp));
		break;
	case QUERY_COMBO_VALUE_BMQXH_URL_ID:
		OnLoadComboDataSuccess(Comb_BMQXH, CString(resp));
		break;
	case QUERY_COMBO_VALUE_MPZL_URL_ID:
		OnLoadComboDataSuccess(Comb_MPZL, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZJDY_URL_ID:
		OnLoadComboDataSuccess(Comb_ZJDY, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZJYS_URL_ID:
		OnLoadComboDataSuccess(Comb_ZJYS, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZDQXH_URL_ID:
		OnLoadComboDataSuccess(Comb_ZDQXH, CString(resp));
		break;
	case QUERY_COMBO_VALUE_BZXDTGG_URL_ID:
		OnLoadComboDataSuccess(Comb_BZXDTGG, CString(resp));
		break;
	case QUERY_COMBO_VALUE_ZZS_URL_ID:
		OnLoadComboDataSuccess(Comb_ZZS, CString(resp));
		break;
	case QUERY_COMBO_VALUE_KHQY_URL_ID:
		OnLoadComboDataSuccess(Comb_KHQY, CString(resp));
		break;

	default:
		break;
	}
}

void CSaleAddDlg::OnHttpFailed(int id)
{
	//GetParent()->EnableWindow(TRUE);
	switch (id)
	{
	case QUERY_COMBO_VALUE_KHMC_URL_ID:
	case QUERY_COMBO_VALUE_GGBH_URL_ID:
	case QUERY_COMBO_VALUE_ZC_URL_ID:
		//case QUERY_COMBO_VALUE_DFR_URL_ID:
	case QUERY_COMBO_VALUE_ZDQDY_URL_ID:
	case QUERY_COMBO_VALUE_YYLGG_URL_ID:
		//case QUERY_COMBO_VALUE_JF_URL_ID:
	case QUERY_COMBO_VALUE_BPQXH_URL_ID:
	case QUERY_COMBO_VALUE_BMQXH_URL_ID:
	case QUERY_COMBO_VALUE_MPZL_URL_ID:
	case QUERY_COMBO_VALUE_ZJDY_URL_ID:
	case QUERY_COMBO_VALUE_ZJYS_URL_ID:
	case QUERY_COMBO_VALUE_ZDQXH_URL_ID:
	case QUERY_COMBO_VALUE_BZXDTGG_URL_ID:
	case QUERY_COMBO_VALUE_ZZS_URL_ID:
	case QUERY_COMBO_VALUE_KHQY_URL_ID:
	{
		--m_iRef;
		if (0 == m_iRef)
		{
			EnableWindow(TRUE);
			InitCtrlData();
		}
	}
		break;
	default:
		break;
	}

}

void CSaleAddDlg::OnLoadComboDataSuccess(int id, CString strValList)
{
	--m_iRef;
	std::vector<CString> vec;
	Util_Tools::Util::Split(strValList, _T(','), vec);

	for (int i = 0; i < vec.size(); i++)
	{
		m_DropList[id].push_back(vec[i]);
	}

	if (0 == m_iRef)
	{
		EnableWindow(TRUE);
		InitCtrlData();
	}
}

BOOL CSaleAddDlg::OnInitDialog()
{
	CPopupDlg::OnInitDialog();
	CenterWindow();

	//init comb
	for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
	{
		m_aCombs[i] = Util_Tools::Util::CreateComboBox(this, IDC_COMBO_BASE + i, _T("Microsoft YaHei"), 12);
		m_aCombs[i]->MoveWindow(g_CombPos[i][0], g_CombPos[i][1], g_CombPos[i][2], g_CombPos[i][3]);
	}

	//init static
	for (int i = 0; i < _countof(g_StaticItems); ++i)
	{
		m_aStatics[i] = Util_Tools::Util::CreateStatic(this, IDC_STATIC_BASE + i, g_StaticItems[i][0], _T("Microsoft YaHei"), 12);
		m_aStatics[i]->MoveWindow(g_StaticPos[i][0], g_StaticPos[i][1], g_StaticPos[i][2], g_StaticPos[i][3]);
	}

	//init edit
	for (int i = 0; i < _countof(g_EditItems); ++i)
	{
		m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, g_EditItems[i][0], _T("Microsoft YaHei"), 12);
		m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
	}

	//init date picker
	for (int i = 0; i < _countof(g_DatePickersPos); ++i)
	{
		m_aDatePickers[i] = Util_Tools::Util::CreateDateTimePicker(this, IDC_DATETIME_BASE + i, _T("Microsoft YaHei"), 12);
		m_aDatePickers[i]->MoveWindow(g_DatePickersPos[i][0], g_DatePickersPos[i][1], g_DatePickersPos[i][2], g_DatePickersPos[i][3]);
	}


	InitCtrlData();

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

	for (int i = 0; i < _countof(m_aDatePickers); ++i)
	{
		if (NULL != m_aDatePickers[i])
		{
			delete m_aDatePickers[i];
		}
	}

	CPopupDlg::PostNcDestroy();
}

void CSaleAddDlg::OnOK()
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

	m_aEdits[EditId::Edit_DLCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->dlcd : _T("")));

	m_aEdits[EditId::Edit_ZXCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zxcd : _T("")));

	m_aCombs[CombId::Comb_MPZL]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bmqxh : 0));

	m_aEdits[EditId::Edit_BZ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bz : _T("")));

	CTime time;
	DWORD dwResult = m_aDatePickers[DatePickerId::DatePicker_DDRQ]->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		m_aDatePickers[DatePickerId::DatePicker_DDRQ]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	else
	{
		m_vecResult.push_back(_T(""));
	}

	m_aCombs[CombId::Comb_ZJDY]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZJYS]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZDQXH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZYZ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_BZXDTGG]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aEdits[EditId::Edit_GH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZZS]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_KHQY]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

 	m_aCombs[CombId::Comb_YXJ]->GetWindowText(strTmp);
 	m_vecResult.push_back(strTmp);

	CPopupDlg::OnOK();
}

void CSaleAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption.reset(lpOpt);
}

const std::vector<std::vector<CString>>& CSaleAddDlg::GetDropList()
{
	return m_DropList;
}

void CSaleAddDlg::InitCtrlData()
{
	if (NULL == m_lpOption.get())
	{
		d_GetOption(*this);
	}

	for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
	{
		for (int j = GetDropList()[i].size() - 1; j >= 0; --j)
		{
			m_aCombs[i]->InsertString(0, GetDropList()[i][j]);
		}
	}

	if (NULL != m_lpOption.get())
	{
		init(m_aEdits[EditId::Edit_HTH], m_lpOption->htbh);
		init(m_aEdits[EditId::Edit_SL], m_lpOption->sl);
		init(m_aEdits[EditId::Edit_DLCD], m_lpOption->dlcd);
		init(m_aEdits[EditId::Edit_ZXCD], m_lpOption->zxcd);
		init(m_aDatePickers[DatePickerId::DatePicker_DDRQ], m_lpOption->ddrq);
		init(m_aEdits[EditId::Edit_BZ], m_lpOption->bz);

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

		init(m_aEdits[EditId::Edit_GH], m_lpOption->gh);

		init(m_aCombs[CombId::Comb_ZJDY], m_lpOption->zjdy);
		init(m_aCombs[CombId::Comb_ZJYS], m_lpOption->zjys);
		init(m_aCombs[CombId::Comb_ZDQXH], m_lpOption->zdqxh);
		init(m_aCombs[CombId::Comb_ZYZ], m_lpOption->zyz);
		init(m_aCombs[CombId::Comb_BZXDTGG], m_lpOption->bzxdtgg);
		init(m_aCombs[CombId::Comb_ZZS], m_lpOption->zzs);
		init(m_aCombs[CombId::Comb_KHQY], m_lpOption->khqy);
		init(m_aCombs[CombId::Comb_YXJ], m_lpOption->yxj);

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

		init(m_aCombs[CombId::Comb_ZJDY], 0);
		init(m_aCombs[CombId::Comb_ZJYS], 0);
		init(m_aCombs[CombId::Comb_ZDQXH], 0);
		init(m_aCombs[CombId::Comb_ZYZ], 0);
		init(m_aCombs[CombId::Comb_BZXDTGG], 0);
		init(m_aCombs[CombId::Comb_ZZS], 0);
		init(m_aCombs[CombId::Comb_KHQY], 0);
		init(m_aCombs[CombId::Comb_YXJ], 0);

		CString val(_T(""));
		init(m_aDatePickers[DatePickerId::DatePicker_DDRQ], val);
	}
}

int CSaleAddDlg::m_iRef = 0;

std::vector<std::vector<CString>> CSaleAddDlg::m_DropList;