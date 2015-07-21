#include "stdafx.h"
#include "Server.h"
#include "NotificationAddDlgForSale.h"
#include "resource_ids.h"
#include "Util.h"
#include "Association.h"

#define IDC_EDIT_BASE (IDC_PLAN_ADD_Control_BASE)
#define IDC_STATIC_BASE (IDC_PLAN_ADD_Control_BASE + 20)
#define IDC_STATIC_TOSHOW_BASE (IDC_STATIC_BASE + 20)
#define IDC_DATETIME_BASE (IDC_STATIC_TOSHOW_BASE + 20)
#define IDC_COMBO_BASE (IDC_DATETIME_BASE + 20)

#define QUERY_COMBO_BASE		(IDC_COMBO_BASE + 21)

#define QUERY_COMBO_VALUE_KHMC_URL_ID		QUERY_COMBO_BASE + 1
#define QUERY_COMBO_VALUE_GGBH_URL_ID		QUERY_COMBO_BASE + 2
#define QUERY_COMBO_VALUE_ZC_URL_ID			QUERY_COMBO_BASE + 3
#define QUERY_COMBO_VALUE_DFR_URL_ID		QUERY_COMBO_BASE + 4
#define QUERY_COMBO_VALUE_ZDQDY_URL_ID		QUERY_COMBO_BASE + 5
#define QUERY_COMBO_VALUE_YYLGG_URL_ID		QUERY_COMBO_BASE + 6
#define QUERY_COMBO_VALUE_JF_URL_ID			QUERY_COMBO_BASE + 7
#define QUERY_COMBO_VALUE_BPQXH_URL_ID		QUERY_COMBO_BASE + 8
#define QUERY_COMBO_VALUE_BMQXH_URL_ID		QUERY_COMBO_BASE + 9
#define QUERY_COMBO_VALUE_MPZL_URL_ID		QUERY_COMBO_BASE + 10
#define QUERY_COMBO_VALUE_ZJDY_URL_ID		QUERY_COMBO_BASE + 11
#define QUERY_COMBO_VALUE_ZJYS_URL_ID		QUERY_COMBO_BASE + 12
#define QUERY_COMBO_VALUE_ZDQXH_URL_ID		QUERY_COMBO_BASE + 13
#define QUERY_COMBO_VALUE_BZXDTGG_URL_ID	QUERY_COMBO_BASE + 14
#define QUERY_COMBO_VALUE_ZZS_URL_ID		QUERY_COMBO_BASE + 15
#define QUERY_COMBO_VALUE_KHQY_URL_ID		QUERY_COMBO_BASE + 16

//按显示的顺序行列排序
static int g_StaticPos[][4] = {

		{ 100 * 0 + 100 * 0, 40 * 1 - 15, 100, 20 }, //Static_HTH,
		{ 100 * 1 + 100 * 1, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
		{ 100 * 2 + 100 * 2, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
		{ 100 * 3 + 100 * 3, 40 * 1 - 15, 100, 20 }, //Static_SL,
		{ 0, 0, 0, 0 }, //Static_ZC,
		{ 100 * 0 + 100 * 0, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
		{ 100 * 1 + 100 * 1, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
		{ 100 * 2 + 100 * 2, 40 * 2 - 15, 100, 20 }, //Static_JF,
		{ 100 * 3 + 100 * 3, 40 * 2 - 15, 100, 20 }, //Static_BPQXH,
		{ 100 * 0 + 100 * 0, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
		{ 100 * 1 + 100 * 1, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
		{ 100 * 2 + 100 * 2, 40 * 3 - 15, 100, 20 }, //Static_ZXCD,
		{ 100 * 3 + 100 * 3, 40 * 3 - 15, 100, 20 }, //Static_MPZL,
		{ 100 * 0 + 100 * 0, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
		{ 100 * 1 + 100 * 1, 40 * 4 - 15, 100, 20 }, 	//zjdy
		{ 100 * 2 + 100 * 2, 40 * 4 - 15, 100, 20 }, 	//zjys
		{ 100 * 3 + 100 * 3, 40 * 4 - 15, 100, 20 }, 	//zdqxh
		{ 100 * 0 + 100 * 0, 40 * 5 - 15, 100, 20 }, 	//zyz
		{ 100 * 1 + 100 * 1, 40 * 5 - 15, 100, 20 }, 	//bzxgg
		{ 100 * 2 + 100 * 2, 40 * 5 - 15, 100, 20 }, 	//zzs
		{ 100 * 3 + 100 * 3, 40 * 5 - 15, 100, 20 }, 	//khqy
		{ 100 * 0 + 100 * 0, 40 * 6 - 15, 100, 20 }, 	//gh
		{ 100 * 1 + 100 * 1, 40 * 6 - 15, 100, 20 }, 	//ywsh
		{ 100 * 2 + 100 * 2, 40 * 6 - 15, 100, 20 }, 	//jhsh
		{ 100 * 0 + 100 * 0, 40 * 7 - 15, 100, 20 },   //bz
};


static int g_StaticToShowPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 1 - 15, 100, 20 }, //Static_HTH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
		{ 100 * 3 + 100 * 2 + 8, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 1 - 15, 100, 20 }, //Static_SL,
		{ 0, 0, 0, 0 }, //Static_ZC,
		{ 100 * 1 + 100 * 0 + 8, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
		{ 100 * 2 + 100 * 1 + 8, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
		{ 100 * 3 + 100 * 2 + 8, 40 * 2 - 15, 100, 20 }, //Static_JF,
		{ 100 * 4 + 100 * 3 + 8, 40 * 2 - 15, 100, 20 }, //Static_BPQXH,
		{ 100 * 1 + 100 * 0 + 8, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
		{ 100 * 3 + 100 * 2 + 8, 40 * 3 - 15, 100, 20 }, //Static_ZXCD,
		{ 100 * 4 + 100 * 3 + 8, 40 * 3 - 15, 100, 20 }, //Static_MPZL,
		{ 100 * 1 + 100 * 0 + 8, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
		{ 100 * 2 + 100 * 1 + 8, 40 * 4 - 15, 100, 20 }, 	//zjdy
		{ 100 * 3 + 100 * 2 + 8, 40 * 4 - 15, 100, 20 }, 	//zjys
		{ 100 * 4 + 100 * 3 + 8, 40 * 4 - 15, 100, 20 }, 	//zdqxh
		{ 100 * 1 + 100 * 0 + 8, 40 * 5 - 15, 100, 20 }, 	//zyz
		{ 100 * 2 + 100 * 1 + 8, 40 * 5 - 15, 100, 20 }, 	//bzxgg
		{ 100 * 3 + 100 * 2 + 8, 40 * 5 - 15, 100, 20 }, 	//zzs
		{ 100 * 4 + 100 * 3 + 8, 40 * 5 - 15, 100, 20 }, 	//khqy
		{ 100 * 1 + 100 * 0 + 8, 40 * 6 - 15, 100, 20 }, 	//gh
		{ 100 * 2 + 100 * 1 + 8, 40 * 6 - 15, 100, 20 }, 	//ywsh
		{ 100 * 3 + 100 * 2 + 8, 40 * 6 - 15, 100, 20 }, 	//jhsh
		{ 100 * 1 + 100 * 0 + 8, 40 * 7 - 15, 400, 60 },   //bz
};

static int g_EditsPos[][4] = {
		{ 100 * 1 + 100 * 0, 40 * 1, 100, 20 }, //Edit_HTH,
		{ 100 * 4 + 100 * 3, 40 * 1, 100, 20 }, //Edit_SL,
		{ 100 * 4 + 100 * 3, 40 * 3, 100, 20 }, //Edit_DLCD,
		{ 100 * 1 + 100 * 0, 40 * 3, 100, 20 }, //Edit_ZXCD,
		{ 100 * 4 + 100 * 3, 40 * 4, 100, 20 }, //Edit_GH,
		{ 100 * 1 + 100 * 0, 40 * 7, 500, 60 } //Edit_BZ,
};

static int g_CombPos[][4] = {
		{ 100 * 2 + 100 * 1, 40 * 1, 100, 20 }, //Comb_KHMC,
		{ 100 * 3 + 100 * 2, 40 * 1, 100, 20 }, //Comb_GGBH,
		{ 0, 0, 0, 0 }, //Comb_ZC,
		{ 0, 0, 0, 0 }, //Comb_DFR,
		{ 100 * 3 + 100 * 2, 40 * 2, 100, 20 }, //Comb_ZDQDY,
		{ 100 * 4 + 100 * 3, 40 * 2, 100, 20 }, //Comb_YYLGG,
		{ 100 * 1 + 100 * 0, 40 * 2, 100, 20 }, //Comb_JF,
		{ 100 * 2 + 100 * 1, 40 * 2, 100, 20 }, //Comb_BPQXH,
		{ 100 * 3 + 100 * 2, 40 * 3, 100, 20 }, //Comb_BMQXH,
		{ 0, 0, 0, 0 },	//Comb_YXJ
		{ 100 * 1 + 100 * 0, 40 * 4, 100, 20 }, //zjdy
		{ 100 * 2 + 100 * 1, 40 * 3, 100, 20 }, //zjys
		{ 100 * 3 + 100 * 2, 40 * 5, 100, 20 }, //zdqxh
		{ 100 * 4 + 100 * 3, 40 * 5, 100, 20 }, //zyz
		{ 100 * 1 + 100 * 0, 40 * 5, 100, 20 }, //bzxgg
		{ 100 * 2 + 100 * 1, 40 * 4, 100, 20 }, //zzs
		{ 100 * 2 + 100 * 1, 40 * 5, 100, 20 }, //khqy
		{ 100 * 1 + 100 * 0, 40 * 6, 500, 20 } //Comb_MPZL,
};

static int g_DatePickersPos[][4] = {
		{ 100 * 3 + 100 * 2, 40 * 4, 100, 20 }, //Edit_DDRQ,
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

inline void init(CBSStatic* sta, CString& val){
	if (val != OPT_FALSE)
	{
		sta->SetWindowText(val);
	}
}

inline void init(CComboBox* comb, int val){
	if (val != OPT_FALSE_INT)
	{
		comb->SetCurSel(val);
	}
}

BEGIN_MESSAGE_MAP(CNotificationAddDlgForSale, CPopupDlg)
// 	ON_CBN_SELCHANGE(IDC_COMBO_BASE, &CNotificationAddDlgForSale::OnCbnSelchangeKhOrGg)
// 	ON_CBN_SELCHANGE(IDC_COMBO_BASE + 1, &CNotificationAddDlgForSale::OnCbnSelchangeKhOrGg)
	ON_BN_CLICKED(IDC_NOTIFICATION_SALE_MODIFY_BTN, &CNotificationAddDlgForSale::OnBnClickedBtnModify)
END_MESSAGE_MAP()

CNotificationAddDlgForSale::CNotificationAddDlgForSale(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CPopupDlg(title, pParent)
	, m_lpOption(NULL)
	, m_bIsSalePage(TRUE)
	, m_bIsModifing(false)
{
	InitHttpInstance();
}


CNotificationAddDlgForSale::~CNotificationAddDlgForSale()
{

}

void CNotificationAddDlgForSale::OnBnClickedBtnModify()
{
	if (m_bIsModifing)
	{
		//init static to show
		for (int i = 0; i < _countof(g_StaticToShowPos); ++i)
		{
			m_aStaticsToShow[i]->ShowWindow(SW_SHOW);
		}

		//init edit
		for (int i = 0; i < _countof(g_EditsPos); ++i)
		{
			m_aEdits[i]->ShowWindow(SW_HIDE);
		}

		//init comb
		for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
		{
			m_aCombs[i]->ShowWindow(SW_HIDE);
		}

		//init date picker
		for (int i = 0; i < _countof(g_DatePickersPos); ++i)
		{
			m_aDatePickers[i]->ShowWindow(SW_HIDE);
		}

		m_btnModify.SetWindowTextW(_T("修改"));

		m_bIsModifing = false;
	}
	else
	{
		//init static to show
		for (int i = 0; i < _countof(g_StaticToShowPos); ++i)
		{
			if (i == StaticId::Static_YWSH || i == StaticId::Static_JHSH)
			{
				continue;
			}

			m_aStaticsToShow[i]->ShowWindow(SW_HIDE);
		}

		//init edit
		for (int i = 0; i < _countof(g_EditsPos); ++i)
		{
			m_aEdits[i]->ShowWindow(SW_SHOW);
		}

		//init comb
		for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
		{
			m_aCombs[i]->ShowWindow(SW_SHOW);
		}

		//init date picker
		for (int i = 0; i < _countof(g_DatePickersPos); ++i)
		{
			m_aDatePickers[i]->ShowWindow(SW_SHOW);
		}

		m_btnModify.SetWindowTextW(_T("取消修改"));

		m_bIsModifing = true;
	}
}

void CNotificationAddDlgForSale::SetDlgOption(BOOL bIsSalePage)
{
	m_bIsSalePage = bIsSalePage;
}


void CNotificationAddDlgForSale::OnNcDestroy()
{
	__super::OnNcDestroy();
}

void CNotificationAddDlgForSale::InitHttpInstance()
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
		m_DropList[Comb_DFR].push_back(_T("单绕"));
		m_DropList[Comb_DFR].push_back(_T("复绕"));
		m_DropList[Comb_DFR].push_back(_T("无"));
		m_DropList[Comb_DFR].push_back(_T(""));

		//制动器电压
		item.QuerySync(CItem::ZDQDYFLXX, m_DropList[CombId::Comb_ZDQDY]);
		++m_iRef;

		//曳引轮规格
		item.QuerySync(CItem::YYLGGFLXX, m_DropList[CombId::Comb_YYLGG]);
		++m_iRef;

		//机房
		m_DropList[Comb_JF].push_back(_T("有"));
		m_DropList[Comb_JF].push_back(_T("无"));
		m_DropList[Comb_JF].push_back(_T(""));

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
		m_DropList[Comb_ZYZ].push_back(_T("左置"));
		m_DropList[Comb_ZYZ].push_back(_T("右置"));
		m_DropList[Comb_ZYZ].push_back(_T(""));

		//包装箱 / 底托规格
		item.QuerySync(CItem::BZXDTGG, m_DropList[CombId::Comb_BZXDTGG]);

		//制造商
		item.QuerySync(CItem::ZZS, m_DropList[CombId::Comb_ZZS]);

		//客户区域
		item.QuerySync(CItem::KHQY, m_DropList[CombId::Comb_KHQY]);

		//优先级
		m_DropList[Comb_YXJ].push_back(_T("高"));
		m_DropList[Comb_YXJ].push_back(_T("低"));
		m_DropList[Comb_YXJ].push_back(_T(""));

	}
}


void CNotificationAddDlgForSale::OnHttpSuccess(int id, LPCTSTR resp)
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

void CNotificationAddDlgForSale::OnHttpFailed(int id)
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

void CNotificationAddDlgForSale::OnLoadComboDataSuccess(int id, CString strValList)
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

const std::vector<std::vector<CString>>& CNotificationAddDlgForSale::GetDropList()
{
	return m_DropList;
}

void CNotificationAddDlgForSale::InitCtrlData()
{
	if (NULL == m_lpOption)
	{
		d_GetOption(*this);
	}

	CFont* pFont = NULL;
	pFont = CBSObject::GetFontPtr(_T("Microsoft YaHei"), 12, FALSE, FALSE, FALSE);

	for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
	{
		for (int j = GetDropList()[i].size() - 1; j >= 0; --j)
		{
			m_aCombs[i]->InsertString(0, GetDropList()[i][j]);
		}

		m_aCombs[i]->SetDroppedWidth(Util_Tools::Util::CaculateMaxWidthOfItems((m_aCombs[i])->GetOwner(), GetDropList()[i], pFont));
	}

	if (NULL != m_lpOption)
	{
		init(m_aEdits[EditId::Edit_HTH], m_lpOption->htbh);
		if (m_lpOption->htbh == _T("-1"))
		{
			m_aEdits[EditId::Edit_HTH]->EnableWindow(FALSE);
		}

		init(m_aEdits[EditId::Edit_SL], m_lpOption->sl);
		if (m_lpOption->sl == _T("-1"))
		{
			m_aEdits[EditId::Edit_SL]->EnableWindow(FALSE);
		}

		init(m_aEdits[EditId::Edit_DLCD], m_lpOption->dlcd);
		if (m_lpOption->dlcd == _T("-1"))
		{
			m_aEdits[EditId::Edit_DLCD]->EnableWindow(FALSE);
		}

		init(m_aEdits[EditId::Edit_ZXCD], m_lpOption->zxcd);
		if (m_lpOption->zxcd == _T("-1"))
		{
			m_aEdits[EditId::Edit_ZXCD]->EnableWindow(FALSE);
		}

		init(m_aDatePickers[DatePickerId::DatePicker_DDRQ], m_lpOption->ddrq);
		if (m_lpOption->ddrq == _T("-1"))
		{
			m_aDatePickers[DatePickerId::DatePicker_DDRQ]->EnableWindow(FALSE);
		}

		init(m_aEdits[EditId::Edit_BZ], m_lpOption->bz);
		if (m_lpOption->bz == _T("-1"))
		{
			m_aEdits[EditId::Edit_BZ]->EnableWindow(FALSE);
		}


		init(m_aCombs[CombId::Comb_KHMC], m_lpOption->khmc);
		if (m_lpOption->khmc == -1)
		{
			m_aCombs[CombId::Comb_KHMC]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_GGBH], m_lpOption->ggbh);
		if (m_lpOption->ggbh == -1)
		{
			m_aCombs[CombId::Comb_GGBH]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZC], m_lpOption->zc);
		if (m_lpOption->zc == -1)
		{
			m_aCombs[CombId::Comb_ZC]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_DFR], m_lpOption->dfr);
		if (m_lpOption->dfr == -1)
		{
			m_aCombs[CombId::Comb_DFR]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZDQDY], m_lpOption->zdqdy);
		if (m_lpOption->zdqdy == -1)
		{
			m_aCombs[CombId::Comb_ZDQDY]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_YYLGG], m_lpOption->yylgg);
		if (m_lpOption->yylgg == -1)
		{
			m_aCombs[CombId::Comb_YYLGG]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_JF], m_lpOption->jf);
		if (m_lpOption->jf == -1)
		{
			m_aCombs[CombId::Comb_JF]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_BPQXH], m_lpOption->bpqxh);
		if (m_lpOption->bpqxh == -1)
		{
			m_aCombs[CombId::Comb_BPQXH]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_BMQXH], m_lpOption->bmqxh);
		if (m_lpOption->bmqxh == -1)
		{
			m_aCombs[CombId::Comb_BMQXH]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_MPZL], m_lpOption->mpzl);
		if (m_lpOption->mpzl == -1)
		{
			m_aCombs[CombId::Comb_MPZL]->EnableWindow(FALSE);
		}


		init(m_aEdits[EditId::Edit_GH], m_lpOption->gh);
		if (m_lpOption->gh == _T("-1"))
		{
			m_aEdits[EditId::Edit_GH]->EnableWindow(FALSE);
		}


		init(m_aCombs[CombId::Comb_ZJDY], m_lpOption->zjdy);
		if (m_lpOption->zjdy == -1)
		{
			m_aCombs[CombId::Comb_ZJDY]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZJYS], m_lpOption->zjys);
		if (m_lpOption->zjys == -1)
		{
			m_aCombs[CombId::Comb_ZJYS]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZDQXH], m_lpOption->zdqxh);
		if (m_lpOption->zdqxh == -1)
		{
			m_aCombs[CombId::Comb_ZDQXH]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZYZ], m_lpOption->zyz);
		if (m_lpOption->zyz == -1)
		{
			m_aCombs[CombId::Comb_ZYZ]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_BZXDTGG], m_lpOption->bzxdtgg);
		if (m_lpOption->bzxdtgg == -1)
		{
			m_aCombs[CombId::Comb_BZXDTGG]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_ZZS], m_lpOption->zzs);
		if (m_lpOption->zzs == -1)
		{
			m_aCombs[CombId::Comb_ZZS]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_KHQY], m_lpOption->khqy);
		if (m_lpOption->khqy == -1)
		{
			m_aCombs[CombId::Comb_KHQY]->EnableWindow(FALSE);
		}

		init(m_aCombs[CombId::Comb_YXJ], m_lpOption->yxj);
		if (m_lpOption->yxj == -1)
		{
			m_aCombs[CombId::Comb_YXJ]->EnableWindow(FALSE);
		}

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

	if (NULL != m_lpOption)
	{
		init(m_aStaticsToShow[StaticId::Static_HTH], m_lpOption->htbh);
		CString strValue(_T(""));
		m_aCombs[CombId::Comb_KHMC]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_KHMC], strValue);
		m_aCombs[CombId::Comb_GGBH]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_GGBH], strValue);
		init(m_aStaticsToShow[StaticId::Static_SL], m_lpOption->sl);
		m_aCombs[CombId::Comb_ZC]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZC], strValue);
		m_aCombs[CombId::Comb_ZDQDY]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZDQDY], strValue);
		m_aCombs[CombId::Comb_YYLGG]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_YYLGG], strValue);
		m_aCombs[CombId::Comb_JF]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_JF], strValue);
		m_aCombs[CombId::Comb_BPQXH]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_BPQXH], strValue);
		m_aCombs[CombId::Comb_BMQXH]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_BMQXH], strValue);
		init(m_aStaticsToShow[StaticId::Static_DLCD], m_lpOption->dlcd);
		init(m_aStaticsToShow[StaticId::Static_ZXCD], m_lpOption->zxcd);
		m_aCombs[CombId::Comb_MPZL]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_MPZL], strValue);
		init(m_aStaticsToShow[StaticId::Static_DDRQ], m_lpOption->ddrq);
		m_aCombs[CombId::Comb_ZJDY]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZJDY], strValue);
		m_aCombs[CombId::Comb_ZJYS]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZJYS], strValue);
		m_aCombs[CombId::Comb_ZDQXH]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZDQXH], strValue);
		m_aCombs[CombId::Comb_ZYZ]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZYZ], strValue);
		m_aCombs[CombId::Comb_BZXDTGG]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_BZXDTGG], strValue);
		m_aCombs[CombId::Comb_ZZS]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_ZZS], strValue);
		m_aCombs[CombId::Comb_KHQY]->GetWindowText(strValue);
		init(m_aStaticsToShow[StaticId::Static_KHQY], strValue);
		init(m_aStaticsToShow[StaticId::Static_GH], m_lpOption->gh);
		init(m_aStaticsToShow[StaticId::Static_YWSH], m_lpOption->ywsh);
		init(m_aStaticsToShow[StaticId::Static_JHSH], m_lpOption->jhsh);
		init(m_aStaticsToShow[StaticId::Static_BZ], m_lpOption->bz);
	}
	else
	{
		CString val(_T("NULL"));
		init(m_aStaticsToShow[StaticId::Static_HTH], val);
		init(m_aStaticsToShow[StaticId::Static_KHMC], val);
		init(m_aStaticsToShow[StaticId::Static_GGBH], val);
		init(m_aStaticsToShow[StaticId::Static_SL], val);
		init(m_aStaticsToShow[StaticId::Static_ZC], val);
		init(m_aStaticsToShow[StaticId::Static_ZDQDY], val);
		init(m_aStaticsToShow[StaticId::Static_YYLGG], val);
		init(m_aStaticsToShow[StaticId::Static_JF], val);
		init(m_aStaticsToShow[StaticId::Static_BPQXH], val);
		init(m_aStaticsToShow[StaticId::Static_BMQXH], val);
		init(m_aStaticsToShow[StaticId::Static_DLCD], val);
		init(m_aStaticsToShow[StaticId::Static_ZXCD], val);
		init(m_aStaticsToShow[StaticId::Static_MPZL], val);
		init(m_aStaticsToShow[StaticId::Static_DDRQ], val);
		init(m_aStaticsToShow[StaticId::Static_ZJDY], val);
		init(m_aStaticsToShow[StaticId::Static_ZJYS], val);
		init(m_aStaticsToShow[StaticId::Static_ZDQXH], val);
		init(m_aStaticsToShow[StaticId::Static_ZYZ], val);
		init(m_aStaticsToShow[StaticId::Static_BZXDTGG], val);
		init(m_aStaticsToShow[StaticId::Static_ZZS], val);
		init(m_aStaticsToShow[StaticId::Static_KHQY], val);
		init(m_aStaticsToShow[StaticId::Static_GH], val);
		init(m_aStaticsToShow[StaticId::Static_YWSH], val);
		init(m_aStaticsToShow[StaticId::Static_JHSH], val);
		init(m_aStaticsToShow[StaticId::Static_BZ], val);
	}
}

static LPCTSTR g_StaticItems[][1] = { //0: default text
		{ _T("合同号:") },
		{ _T("客户名称:") },
		{ _T("规格型号:") },
		{ _T("数量:") },
		{ _T("轴承:") },
		{ _T("制动器电压:") },
		{ _T("曳引轮规格:") },
		{ _T("机房:") },
		{ _T("变频器型号:") },
		{ _T("编码器型号:") },
		{ _T("电缆长度:") },
		{ _T("闸线长度:") },
		{ _T("铭牌等资料:") },
		{ _T("订单日期:") },
		{ _T("主机电压:") },
		{ _T("主机颜色:") },
		{ _T("制动器型号:") },
		{ _T("左/右置:") },
		{ _T("包装箱/底托规格:") },
		{ _T("制造商:") },
		{ _T("客户区域:") },
		{ _T("工号:") },
		{ _T("业务审核:") },
		{ _T("计划审核:") },
		{ _T("备注:") }

};

BOOL CNotificationAddDlgForSale::OnInitDialog()
{
	CPopupDlg::OnInitDialog();

	Util_Tools::Util::SetClientSize(m_hWnd, 837, 550 - 160);
	m_btnOK.MoveWindow(556, 40 * 7 + 50, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 7 + 50, 114, 30);

	m_btnOK.SetWindowTextW(_T("确认审核"));
	m_btnCancel.SetWindowTextW(_T("取消审核"));
	
	m_btnModify.Create(this, IDC_NOTIFICATION_SALE_MODIFY_BTN);
	m_btnModify.MoveWindow(20, 40 * 7 + 50, 114, 30);
	m_btnModify.SetWindowText(_T("修改"));

	CenterWindow();

	//init static
	for (int i = 0; i < _countof(g_StaticPos); ++i)
	{
		m_aStatics[i] = Util_Tools::Util::CreateStatic(this, IDC_STATIC_BASE + i, g_StaticItems[i][0], _T("Microsoft YaHei"), 12);
		m_aStatics[i]->MoveWindow(g_StaticPos[i][0], g_StaticPos[i][1], g_StaticPos[i][2], g_StaticPos[i][3]);
		m_aStatics[i]->SetTextAlign(DT_RIGHT);
	}

	//init static to show
	for (int i = 0; i < _countof(g_StaticToShowPos); ++i)
	{
		m_aStaticsToShow[i] = Util_Tools::Util::CreateStatic(this, IDC_STATIC_TOSHOW_BASE + i, _T(""), _T("Microsoft YaHei"), 12);
		m_aStaticsToShow[i]->MoveWindow(g_StaticToShowPos[i][0], g_StaticToShowPos[i][1], g_StaticToShowPos[i][2], g_StaticToShowPos[i][3]);
		m_aStaticsToShow[i]->SetTextAlign(DT_LEFT);
	}

	//init edit
	for (int i = 0; i < _countof(g_EditsPos); ++i)
	{
		if (i == EditId::Edit_BZ)
		{
			m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, _T(""), _T("Microsoft YaHei"), 12, true);
			m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
		}
		else
		{
			m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, _T(""), _T("Microsoft YaHei"), 12);
			m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
		}

		m_aEdits[i]->ShowWindow(SW_HIDE);

	}

	//init comb
	for (int i = _countof(g_CombPos) - 1; i >= 0; --i)
	{
		if (Comb_DFR == i || Comb_JF == i || Comb_ZYZ == i || Comb_YXJ == i)
		{
			m_aCombs[i] = Util_Tools::Util::CreateComboBox(this, IDC_COMBO_BASE + i, _T("Microsoft YaHei"), 12, TRUE);
		}
		else
		{
			m_aCombs[i] = Util_Tools::Util::CreateComboBox(this, IDC_COMBO_BASE + i, _T("Microsoft YaHei"), 12);
		}
		m_aCombs[i]->MoveWindow(g_CombPos[i][0], g_CombPos[i][1], g_CombPos[i][2], g_CombPos[i][3]);

		m_aCombs[i]->ShowWindow(SW_HIDE);

	}

	//init date picker
	for (int i = 0; i < _countof(g_DatePickersPos); ++i)
	{
		m_aDatePickers[i] = Util_Tools::Util::CreateDateTimePicker(this, IDC_DATETIME_BASE + i, _T("Microsoft YaHei"), 12);
		m_aDatePickers[i]->MoveWindow(g_DatePickersPos[i][0], g_DatePickersPos[i][1], g_DatePickersPos[i][2], g_DatePickersPos[i][3]);
		m_aDatePickers[i]->ShowWindow(SW_HIDE);
	}

	InitCtrlData();

	m_aEdits[EditId::Edit_HTH]->GetWindowText(m_strInitHtH);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CNotificationAddDlgForSale::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CFont* pFont = NULL;

	for (int i = 0; i < _countof(m_aStaticsToShow); ++i)
	{
		if (NULL != m_aStaticsToShow[i])
		{
			delete m_aStaticsToShow[i];
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

	for (int i = 0; i < _countof(m_aCombs); ++i)
	{
		if (NULL != m_aCombs[i])
		{
			delete m_aCombs[i];
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

void CNotificationAddDlgForSale::OnOK()
{
	if (ConfirmModifyInfo())
	{
		CPopupDlg::OnOK();
	}
}

bool CNotificationAddDlgForSale::ConfirmModifyInfo()
{
	CString strTmp;

	m_aEdits[EditId::Edit_HTH]->GetWindowText(strTmp);

	if ((strTmp != m_strInitHtH) && CServer::GetInstance()->GetSale().isHtIDUsed(strTmp))
	{
		MessageBox(CString(L"合同号 ") + strTmp + L" 已经被占用，请重新输入", L"警告", MB_OK | MB_ICONWARNING);
		return false;
	}

	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->htbh : _T("")));

	GetText(m_aCombs[CombId::Comb_KHMC], CombId::Comb_KHMC, strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_GGBH], CombId::Comb_GGBH, strTmp);
	m_vecResult.push_back(strTmp);

	m_aEdits[EditId::Edit_SL]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->sl : _T("")));

	GetText(m_aCombs[CombId::Comb_ZC], Comb_ZC, strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_DFR]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_ZDQDY], Comb_ZDQDY, strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zdqdy : 0));

	GetText(m_aCombs[CombId::Comb_YYLGG], Comb_YYLGG, strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->yylgg : 0));

	m_aCombs[CombId::Comb_JF]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->jf : 0));

	GetText(m_aCombs[CombId::Comb_BPQXH], Comb_BPQXH, strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bpqxh : 0));

	GetText(m_aCombs[CombId::Comb_BMQXH], Comb_BMQXH, strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->bmqxh : 0));

	m_aEdits[EditId::Edit_DLCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->dlcd : _T("")));

	m_aEdits[EditId::Edit_ZXCD]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp); //m_vecResult.push_back(CompareWithOptFalse(strTmp, m_lpOption != NULL ? m_lpOption->zxcd : _T("")));

	GetText(m_aCombs[CombId::Comb_MPZL], Comb_MPZL, strTmp);
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

	GetText(m_aCombs[CombId::Comb_ZJDY], Comb_ZJDY, strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_ZJYS], Comb_ZJYS, strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_ZDQXH], Comb_ZDQXH, strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_ZYZ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_BZXDTGG], Comb_BZXDTGG, strTmp);
	m_vecResult.push_back(strTmp);

	m_aEdits[EditId::Edit_GH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_ZZS], Comb_ZZS, strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_KHQY], Comb_KHQY, strTmp);
	m_vecResult.push_back(strTmp);

	m_aCombs[CombId::Comb_YXJ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	return true;
}


void CNotificationAddDlgForSale::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}

int CNotificationAddDlgForSale::m_iRef = 0;

std::vector<std::vector<CString>> CNotificationAddDlgForSale::m_DropList;

void CNotificationAddDlgForSale::GetText(CComboBox* pComboBox, CombId comId, CString& text)
{
	pComboBox->GetWindowText(text);
	CString strTmp;
	int i = m_DropList[comId].size() - 1;
	for (; i >= 0; --i)
	{
		if (m_DropList[comId][i] == text)
		{
			break;
		}
	}
	if (i < 0)
	{
		m_DropList[comId].push_back(text);
	}
}

void CNotificationAddDlgForSale::Assosication()
{
	CString kh(_T(""));
	//GetText(m_aCombs[CombId::Comb_KHMC], CombId::Comb_KHMC, kh);
	int iCurSel = m_aCombs[CombId::Comb_KHMC]->GetCurSel();
	if (0 <= iCurSel)
	{
		kh = m_DropList[CombId::Comb_KHMC][iCurSel];
	}

	CString gg(_T(""));
	//GetText(m_aCombs[CombId::Comb_GGBH], CombId::Comb_GGBH, gg);
	iCurSel = m_aCombs[CombId::Comb_GGBH]->GetCurSel();
	if (0 <= iCurSel)
	{
		gg = m_DropList[CombId::Comb_GGBH][iCurSel];
	}

	if (!kh.IsEmpty() && !gg.IsEmpty())
	{
		StringArray* pFields = (StringArray*)CAssociation::GetInstance()->find(kh, gg);
		if (NULL != pFields)
		{
			CString temp;

			m_aEdits[Edit_SL]->GetWindowText(temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::sl - nsSale::sl).IsEmpty()){
				m_aEdits[Edit_SL]->SetWindowText(pFields->at(nsSale::sl - nsSale::sl));
			}


			GetText(m_aCombs[Comb_ZC], Comb_ZC, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::zc - nsSale::sl).IsEmpty()){
				SetText(m_aCombs[Comb_ZC], Comb_ZC, pFields->at(nsSale::zc - nsSale::sl));
			}

			GetText(m_aCombs[Comb_DFR], Comb_DFR, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::dfr - nsSale::sl).IsEmpty()){
				CString dfr = (0 == pFields->at(nsSale::dfr - nsSale::sl).Compare(L"单")) ? L"是" : L"否";
				SetText(m_aCombs[Comb_DFR], Comb_DFR, dfr);
			}

			GetText(m_aCombs[Comb_ZDQDY], Comb_ZDQDY, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::zdqdy - nsSale::sl).IsEmpty()){
				SetText(m_aCombs[Comb_ZDQDY], Comb_ZDQDY, pFields->at(nsSale::zdqdy - nsSale::sl));
			}

			GetText(m_aCombs[Comb_YYLGG], Comb_YYLGG, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::yylgg - nsSale::sl).IsEmpty()){
				SetText(m_aCombs[Comb_YYLGG], Comb_YYLGG, pFields->at(nsSale::yylgg - nsSale::sl));
			}

			GetText(m_aCombs[Comb_JF], Comb_JF, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::jf - nsSale::sl).IsEmpty()){
				CString jf = (0 == pFields->at(nsSale::jf - nsSale::sl).Compare(L"单")) ? L"是" : L"否";
				SetText(m_aCombs[Comb_JF], Comb_JF, jf);
			}

			GetText(m_aCombs[Comb_BPQXH], Comb_BPQXH, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::bpqxh - nsSale::sl).IsEmpty()){
				SetText(m_aCombs[Comb_BPQXH], Comb_BPQXH, pFields->at(nsSale::bpqxh - nsSale::sl));
			}

			GetText(m_aCombs[Comb_BMQXH], Comb_BMQXH, temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::bmqxh - nsSale::sl).IsEmpty()){
				SetText(m_aCombs[Comb_BMQXH], Comb_BMQXH, pFields->at(nsSale::bmqxh - nsSale::sl));
			}

			m_aEdits[Edit_DLCD]->GetWindowText(temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::dlcd - nsSale::sl).IsEmpty()){
				m_aEdits[Edit_DLCD]->SetWindowText(pFields->at(nsSale::dlcd - nsSale::sl));
			}

			m_aEdits[Edit_ZXCD]->GetWindowText(temp);
			if (/*temp.IsEmpty() && */!pFields->at(nsSale::zxcd - nsSale::sl).IsEmpty()){
				m_aEdits[Edit_ZXCD]->SetWindowText(pFields->at(nsSale::zxcd - nsSale::sl));
			}
		}
	}
}

void CNotificationAddDlgForSale::OnCbnSelchangeKhOrGg()
{
	Assosication();
}

void CNotificationAddDlgForSale::SetText(CComboBox* pComboBox, CombId comId, CString& text)
{
	CString strTmp;
	int i = m_DropList[comId].size() - 1;
	for (; i >= 0; --i)
	{
		if (m_DropList[comId][i] == text)
		{
			break;
		}
	}
	if (i < 0)
	{
		m_DropList[comId].push_back(text);
		pComboBox->AddString(text);
		pComboBox->SetCurSel(pComboBox->GetCount() - 1);
	}
	else
	{
		pComboBox->SetCurSel(i);
	}
}

BOOL CNotificationAddDlgForSale::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	if (CBN_SELCHANGE == nCode)
	{
		//MessageBox(L"ok");
	}
	else if (CBN_DROPDOWN == nCode)
	{
		SendMessage(WM_SETCURSOR, 0, 0);
	}
	else if (CBN_CLOSEUP == nCode)
	{
		//int count = m_aCombs[nID - IDC_COMBO_BASE]->GetCount();
		//for (int i = 0; i < count; ++i)
		//{
		//	m_aCombs[nID - IDC_COMBO_BASE]->DeleteString(0);
		//}

		//for (int j = GetDropList()[nID - IDC_COMBO_BASE].size() - 1; j >= 0; --j)
		//{
		//	m_aCombs[nID - IDC_COMBO_BASE]->InsertString(0, GetDropList()[nID - IDC_COMBO_BASE][j]);
		//}
	}
	else if (CBN_EDITCHANGE == nCode)
	{
		CString text;
		m_aCombs[nID - IDC_COMBO_BASE]->GetWindowText(text);
		if (text.IsEmpty())
		{
			int count = m_aCombs[nID - IDC_COMBO_BASE]->GetCount();
			for (int i = 0; i < count; ++i)
			{
				m_aCombs[nID - IDC_COMBO_BASE]->DeleteString(0);
			}
			for (int j = GetDropList()[nID - IDC_COMBO_BASE].size() - 1; j >= 0; --j)
			{
				m_aCombs[nID - IDC_COMBO_BASE]->InsertString(0, GetDropList()[nID - IDC_COMBO_BASE][j]);
			}
		}
		else
		{
			std::vector<CString> tmpVals;
			for (int i = 0; i < GetDropList()[nID - IDC_COMBO_BASE].size(); ++i)
			{
				if (GetDropList()[nID - IDC_COMBO_BASE][i].Find(text) >= 0)
				{
					tmpVals.push_back(GetDropList()[nID - IDC_COMBO_BASE][i]);
				}
			}

			int count = m_aCombs[nID - IDC_COMBO_BASE]->GetCount();
			for (int i = 0; i < count; ++i)
			{
				m_aCombs[nID - IDC_COMBO_BASE]->DeleteString(0);
			}
			for (int i = 0; i < tmpVals.size(); ++i)
			{
				m_aCombs[nID - IDC_COMBO_BASE]->AddString(tmpVals[i]);
			}
		}
		m_aCombs[nID - IDC_COMBO_BASE]->ShowDropDown(TRUE);
	}
	return CPopupDlg::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

