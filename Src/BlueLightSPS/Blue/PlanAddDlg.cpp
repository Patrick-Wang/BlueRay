#include "stdafx.h"
#include "Server.h"
#include "PlanAddDlg.h"
#include "resource_ids.h"
#include "Util.h"

#define IDC_EDIT_BASE (IDC_PLAN_ADD_Control_BASE)
#define IDC_STATIC_BASE (IDC_PLAN_ADD_Control_BASE + 20)
#define IDC_STATIC_TOSHOW_BASE (IDC_STATIC_BASE + 20)
#define IDC_DATETIME_BASE (IDC_STATIC_TOSHOW_BASE + 20)
#define IDC_COMBO_BASE (IDC_DATETIME_BASE + 20)

#define QUERY_COMBO_VALUE_ZC_URL_ID		(IDC_COMBO_BASE + 21)
#define QUERY_COMBO_VALUE_CG_URL_ID		(IDC_COMBO_BASE + 22)


static int g_CombPos[][4] = {
		{ 100 * 3 + 100 * 2 + 8, 40 * 9, 120, 20 },  //Comb_ZC,
		{ 100 * 3 + 100 * 4 + 8, 40 * 9, 120, 20 }  //Comb_CG,
};

static int g_StaticPos[][4] = {
	 	
		{ 100 * 0 + 100 * 0, 40 * 1 - 15, 100, 20 }, //Static_HTH,
	 	{ 100 * 1 + 100 * 1, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
	 	{ 100 * 2 + 100 * 2, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
	 	{ 100 * 3 + 100 * 3, 40 * 1 - 15, 100, 20 }, //Static_SL,
		{ 0, 0, 0, 0 },									//Static_ZC,
		{ 0, 0, 0, 0 },									//Static_DFR,
	 	{ 100 * 2 + 100 * 2, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
	 	{ 100 * 3 + 100 * 3, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
	 	{ 100 * 0 + 100 * 0, 40 * 2 - 15, 100, 20 }, //Static_JF,
	 	{ 100 * 1 + 100 * 1, 40 * 2 - 15, 100, 20 }, //Static_BPQXH,
	 	{ 100 * 2 + 100 * 2, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
	 	{ 100 * 3 + 100 * 3, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
	 	{ 100 * 0 + 100 * 0, 40 * 3 - 15, 100, 20 }, //Static_ZXCD,
	 	{ 100 * 1 + 100 * 1, 40 * 3 - 15, 100, 20 }, //Static_MPZL,
	 	{ 100 * 2 + 100 * 2, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
	 	{ 100 * 3 + 100 * 3, 40 * 4 - 15, 100, 20 },  //Static_BZ,
	 	{ 100 * 0 + 100 * 0, 40 * 4 - 15, 100, 20 },	//zjdy
	 	{ 100 * 1 + 100 * 1, 40 * 4 - 15, 100, 20 },	//zjys
	 	{ 100 * 2 + 100 * 2, 40 * 5 - 15, 100, 20 },	//zdqxh
	 	{ 100 * 3 + 100 * 3, 40 * 5 - 15, 100, 20 },	//zyz
	 	{ 100 * 0 + 100 * 0, 40 * 5 - 15, 100, 20 },	//bzxgg
	 	{ 100 * 1 + 100 * 1, 40 * 5 - 15, 100, 20 },	//zzs
	 	{ 100 * 1 + 100 * 1, 40 * 6 - 15, 100, 20 },	//khqy
		{ 0, 0, 0, 0 },	//yxj
	 	{ 100 * 0 + 100 * 0, 40 * 6 - 15, 100, 20 },	//gh


		{ 100 * 0 + 100 * 0, 40 * 8, 100, 20 },  //Static_SCRQ,
		{ 100 * 1 + 100 * 1, 40 * 8, 100, 20 },  //Static_BZRQ,
		{ 100 * 2 + 100 * 2, 40 * 8, 100, 20 },  //Static_FHRQ,
		{ 100 * 0 + 100 * 0, 40 * 9, 100, 20 },  //Static_TCBH,
		{ 100 * 1 + 40 + 100 * 1, 40 * 9, 100 - 40, 20 },   //Static_CCBH
		{ 100 * 2 + 40 + 100 * 2, 40 * 9, 100 - 40, 20 },   //zc
		{ 100 * 3 + 40 + 100 * 3, 40 * 9, 100 - 40, 20 },   //cg
		{ 100 * 0 + 100 * 0, 40 * 10, 100, 20 },   //bz
};


static int g_StaticToShowPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 1 - 15, 100, 20 }, //Edit_HTH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 1 - 15, 100, 20 }, //Comb_KHMC,
		{ 100 * 3 + 100 * 2 + 8, 40 * 1 - 15, 100, 20 }, //Comb_GGBH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 1 - 15, 100, 20 }, //Edit_SL,
		{ 0, 0, 0, 0 }, //Comb_ZC,
		{ 0, 0, 0, 0 }, //Comb_DFR,
		{ 100 * 3 + 100 * 2 + 8, 40 * 2 - 15, 100, 20 }, //Comb_ZDQDY,
		{ 100 * 4 + 100 * 3 + 8, 40 * 2 - 15, 100, 20 }, //Comb_YYLGG,
		{ 100 * 1 + 100 * 0 + 8, 40 * 2 - 15, 100, 20 }, //Comb_JF,
		{ 100 * 2 + 100 * 1 + 8, 40 * 2 - 15, 100, 20 }, //Comb_BPQXH,
		{ 100 * 3 + 100 * 2 + 8, 40 * 3 - 15, 100, 20 }, //Comb_BMQXH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 3 - 15, 100, 20 }, //Edit_DLCD,
		{ 100 * 1 + 100 * 0 + 8, 40 * 3 - 15, 100, 20 }, //Edit_ZXCD,
		{ 100 * 2 + 100 * 1 + 8, 40 * 3 - 15, 100, 20 },	//Comb_MPZL,
		{ 100 * 3 + 100 * 2 + 8, 40 * 4 - 15, 100, 20 }, //Edit_DDRQ,
		{ 100 * 4 + 100 * 3 + 8, 40 * 4 - 15, 100, 20 },  //Edit_BZ,
		{ 100 * 1 + 100 * 0 + 8, 40 * 4 - 15, 100, 20 },//zjdy
		{ 100 * 2 + 100 * 1 + 8, 40 * 4 - 15, 100, 20 },//zjys
		{ 100 * 3 + 100 * 2 + 8, 40 * 5 - 15, 100, 20 },//zdqxh
		{ 100 * 4 + 100 * 3 + 8, 40 * 5 - 15, 100, 20 },//zyz
		{ 100 * 1 + 100 * 0 + 8, 40 * 5 - 15, 100, 20 },//bzxgg
		{ 100 * 2 + 100 * 1 + 8, 40 * 5 - 15, 100, 20 },//zzs
		{ 100 * 2 + 100 * 1 + 8, 40 * 6 - 15, 100, 20 },//khqy
		{ 0, 0, 0, 0 },	//yxj
		{ 100 * 1 + 100 * 0 + 8, 40 * 6 - 15, 100, 20 }//gh
};

static int g_EditsPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 9, 80, 20 }, //Edit_TCBH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 9, 80, 20 },  //Edit_CCBH,
		{ 100 * 1 + 100 * 0 + 8, 40 * 10, 500, 60 }  //bz
};

static int g_DatePickersPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 8, 120, 20 }, //DatePicker_SCRQ,
		{ 100 * 2 + 100 * 1 + 8, 40 * 8, 120, 20 }, //DatePicker_BZRQ,
		{ 100 * 3 + 100 * 2 + 8, 40 * 8, 120, 20 }  //DatePicker_FHRQ,
};

static LPCTSTR g_EditItems[][1] = { //0: default text
		{ _T("投产编号") },
		{ _T("出厂编号") },
		{ _T("备注") }
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

BEGIN_MESSAGE_MAP(CPlanAddDlg, CPopupDlg)
	ON_BN_CLICKED(IDC_PLAN_ADD_BTN_NEWIDFORSCRQ, &CPlanAddDlg::OnBnClickedNewIDForSCRQ)
	ON_BN_CLICKED(IDC_PLAN_ADD_BTN_NEWIDFORBZRQ, &CPlanAddDlg::OnBnClickedNewIDForBZRQ)
END_MESSAGE_MAP()

CPlanAddDlg::CPlanAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CPopupDlg(title, pParent)
	, m_lpOption(NULL)
	, m_bEnablePlanBtnForSCRQ(false)
	, m_bEnablePlanBtnForBZRQ(false)
	, m_btnNewIDForSCRQ(NULL)
	, m_btnNewIDForBZRQ(NULL)
{
	InitHttpInstance();
}


CPlanAddDlg::~CPlanAddDlg()
{

}

void CPlanAddDlg::OnBnClickedNewIDForSCRQ()
{
	if (m_bEnablePlanEditForTCBH)
	{
		CString text;
		CServer::GetInstance()->GetPlan().GetTcbhSync(text);
		m_aEdits[Edit_TCBH]->SetWindowText(text);
	}

}

void CPlanAddDlg::OnBnClickedNewIDForBZRQ()
{
	if (m_bEnablePlanEditForCCBH)
	{
 		CString text;
		CServer::GetInstance()->GetPlan().GetCcbhSync(text);
		m_aEdits[Edit_CCBH]->SetWindowText(text);
	}
}

void CPlanAddDlg::OnNcDestroy()
{
	if (NULL != m_btnNewIDForSCRQ)
	{
		delete m_btnNewIDForSCRQ;
		m_btnNewIDForSCRQ = NULL;
	}

	if (NULL != m_btnNewIDForBZRQ)
	{
		delete m_btnNewIDForBZRQ;
		m_btnNewIDForBZRQ = NULL;
	}

	__super::OnNcDestroy();
}

void CPlanAddDlg::InitHttpInstance()
{
	if (m_DropList.empty())
	{
		m_DropList.resize(CombId::Comb_END);
		CItem& item = CServer::GetInstance()->GetItem();

		//轴承
		item.QuerySync(CItem::ZCXX, m_DropList[CombId::Comb_ZC]);
		++m_iRef;

		//磁钢
		item.QuerySync(CItem::CG, m_DropList[CombId::Comb_CG]);
		++m_iRef;
	}
}

void CPlanAddDlg::OnHttpFailed(int id)
{
	switch (id)
	{
	case QUERY_COMBO_VALUE_ZC_URL_ID:
	{
		--m_iRef;
		if (0 == m_iRef)
		{
			EnableWindow(TRUE);
			InitCtrlData();
		}
	}
		break;
	case QUERY_COMBO_VALUE_CG_URL_ID:
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

void CPlanAddDlg::OnHttpSuccess(int id, LPCTSTR resp)
{
	switch (id)
	{
	case QUERY_COMBO_VALUE_ZC_URL_ID:
		OnLoadComboDataSuccess(Comb_ZC, CString(resp));
		break;
	case QUERY_COMBO_VALUE_CG_URL_ID:
		OnLoadComboDataSuccess(Comb_CG, CString(resp));
		break;
	default:
		break;
	}
}

void CPlanAddDlg::OnLoadComboDataSuccess(int id, CString strValList)
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

const std::vector<std::vector<CString>>& CPlanAddDlg::GetDropList()
{
	return m_DropList;
}

void CPlanAddDlg::InitCtrlData()
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
		init(m_aCombs[CombId::Comb_ZC], m_lpOption->zc);
		init(m_aCombs[CombId::Comb_CG], m_lpOption->cg);
		init(m_aEdits[EditId::Edit_BZ], m_lpOption->bz);
	}
	else
	{
		CString val(_T(""));

		init(m_aCombs[CombId::Comb_ZC], 0);
		init(m_aCombs[CombId::Comb_CG], 0);
		init(m_aEdits[EditId::Edit_BZ], val);
	}
}

void CPlanAddDlg::ConfigPlanBtns(bool scrq, bool bzrq)
{
	m_bEnablePlanBtnForSCRQ = scrq;
	m_bEnablePlanBtnForBZRQ = bzrq;
}

void CPlanAddDlg::DisableBHEdits(BOOL tcbh, BOOL ccbh)
{
	m_bEnablePlanEditForTCBH = tcbh;
	m_bEnablePlanEditForCCBH = ccbh;
}

static LPCTSTR g_StaticItems[][1] = { //0: default text
		{ _T("合同号:") },
		{ _T("客户名称:") },
		{ _T("规格型号:") },
		{ _T("数量:") },
		{ _T("轴承:") },
		{ _T("单复绕:") },
		{ _T("制动器电压:") },
		{ _T("曳引轮规格:") },
		{ _T("机房:") },
		{ _T("变频器型号:") },
		{ _T("编码器型号:") },
		{ _T("电缆长度:") },
		{ _T("闸线长度:") },
		{ _T("铭牌等资料:") },
		{ _T("订单日期:") },
		{ _T("备注:") },

		{ _T("主机电压:") },
		{ _T("主机颜色:") },
		{ _T("制动器型号:") },
		{ _T("左/右置:") },
		{ _T("包装箱/底托规格:") },
		{ _T("制造商:") },
		{ _T("客户区域:") },
		{ _T("优先级:") },
		{ _T("工号:") },

		{ _T("生产日期") },
		{ _T("包装日期") },
		{ _T("发货日期") },
		{ _T("投产编号") },
		{ _T("出厂编号") },
		{ _T("轴承") },
		{ _T("磁钢") },
		{ _T("备注") }

};

BOOL CPlanAddDlg::OnInitDialog()
{
	CPopupDlg::OnInitDialog();

	Util_Tools::Util::SetClientSize(m_hWnd, 837, 550);
	m_btnOK.MoveWindow(556, 40 * 11 + 50, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 11 + 50, 114, 30);

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
	for (int i = 0; i < _countof(g_EditItems); ++i)
	{
		if (i == Edit_BZ)
		{
			m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, g_EditItems[i][0], _T("Microsoft YaHei"), 12, true);
		}
		else
		{
			m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, g_EditItems[i][0], _T("Microsoft YaHei"), 12);
		}

		m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
	}

	//init date picker
	for (int i = 0; i < _countof(g_DatePickersPos); ++i)
	{
		m_aDatePickers[i] = Util_Tools::Util::CreateDateTimePicker(this, IDC_DATETIME_BASE + i, _T("Microsoft YaHei"), 12);
		m_aDatePickers[i]->MoveWindow(g_DatePickersPos[i][0], g_DatePickersPos[i][1], g_DatePickersPos[i][2], g_DatePickersPos[i][3]);
	}

	m_btnNewIDForSCRQ = Util_Tools::Util::CreateButton(this, IDC_PLAN_ADD_BTN_NEWIDFORSCRQ, _T("<-"), _T("Microsoft YaHei"), 12);
	m_btnNewIDForSCRQ->MoveWindow(100 * 1 + 100 * 0 + 8 + 85, 40 * 9, 35, 20);

	m_btnNewIDForBZRQ = Util_Tools::Util::CreateButton(this, IDC_PLAN_ADD_BTN_NEWIDFORBZRQ, _T("<-"), _T("Microsoft YaHei"), 12);
	m_btnNewIDForBZRQ->MoveWindow(100 * 2 + 100 * 1 + 8 + 85, 40 * 9, 35, 20);

	if (NULL != m_lpOption)
	{
		CString val(_T("NULL"));
		init(m_aStaticsToShow[StaticId2::Static2_HTH], m_lpOption->htbh);
		init(m_aStaticsToShow[StaticId2::Static2_KHMC], m_lpOption->khmc);
		init(m_aStaticsToShow[StaticId2::Static2_GGBH], m_lpOption->ggbh);
		init(m_aStaticsToShow[StaticId2::Static2_SL], m_lpOption->sl);
		init(m_aStaticsToShow[StaticId2::Static2_ZC], val);
		init(m_aStaticsToShow[StaticId2::Static2_DFR], m_lpOption->dfr);
		init(m_aStaticsToShow[StaticId2::Static2_ZDQDY], m_lpOption->zdqdy);
		init(m_aStaticsToShow[StaticId2::Static2_YYLGG], m_lpOption->yylgg);
		init(m_aStaticsToShow[StaticId2::Static2_JF], m_lpOption->jf);
		init(m_aStaticsToShow[StaticId2::Static2_BPQXH], m_lpOption->bpqxh);
		init(m_aStaticsToShow[StaticId2::Static2_BMQXH], m_lpOption->bmqxh);
		init(m_aStaticsToShow[StaticId2::Static2_DLCD], m_lpOption->dlcd);
		init(m_aStaticsToShow[StaticId2::Static2_ZXCD], m_lpOption->zxcd);
		init(m_aStaticsToShow[StaticId2::Static2_MPZL], m_lpOption->mpzl);
		init(m_aStaticsToShow[StaticId2::Static2_DDRQ], m_lpOption->ddrq);
		init(m_aStaticsToShow[StaticId2::Static2_BZ], m_lpOption->bz);

		init(m_aStaticsToShow[StaticId2::Static2_ZJDY], m_lpOption->zjdy);
		init(m_aStaticsToShow[StaticId2::Static2_ZJYS], m_lpOption->zjys);
		init(m_aStaticsToShow[StaticId2::Static2_ZDQXH], m_lpOption->zdqxh);
		init(m_aStaticsToShow[StaticId2::Static2_ZYZ], m_lpOption->zyz);
		init(m_aStaticsToShow[StaticId2::Static2_BZXDTGG], m_lpOption->bzxdtgg);
		init(m_aStaticsToShow[StaticId2::Static2_ZZS], m_lpOption->zzs);
		init(m_aStaticsToShow[StaticId2::Static2_KHQY], m_lpOption->khqy);
		init(m_aStaticsToShow[StaticId2::Static2_YXJ], m_lpOption->yxj);
		init(m_aStaticsToShow[StaticId2::Static2_GH], m_lpOption->gh);

		init(m_aEdits[EditId::Edit_CCBH], m_lpOption->ccbh);
		init(m_aEdits[EditId::Edit_TCBH], m_lpOption->tcbh);

		init(m_aDatePickers[DatePickerId::DatePicker_BZRQ], m_lpOption->bzrq);
		init(m_aDatePickers[DatePickerId::DatePicker_FHRQ], m_lpOption->fhrq);
		init(m_aDatePickers[DatePickerId::DatePicker_SCRQ], m_lpOption->scrq);
	}
	else
	{
		CString val(_T("NULL"));
		init(m_aStaticsToShow[StaticId2::Static2_HTH], val);
		init(m_aStaticsToShow[StaticId2::Static2_KHMC], val);
		init(m_aStaticsToShow[StaticId2::Static2_GGBH], val);
		init(m_aStaticsToShow[StaticId2::Static2_SL], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZC], val);
		init(m_aStaticsToShow[StaticId2::Static2_DFR], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZDQDY], val);
		init(m_aStaticsToShow[StaticId2::Static2_YYLGG], val);
		init(m_aStaticsToShow[StaticId2::Static2_JF], val);
		init(m_aStaticsToShow[StaticId2::Static2_BPQXH], val);
		init(m_aStaticsToShow[StaticId2::Static2_BMQXH], val);
		init(m_aStaticsToShow[StaticId2::Static2_DLCD], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZXCD], val);
		init(m_aStaticsToShow[StaticId2::Static2_MPZL], val);
		init(m_aStaticsToShow[StaticId2::Static2_DDRQ], val);
		init(m_aStaticsToShow[StaticId2::Static2_BZ], val);

		init(m_aStaticsToShow[StaticId2::Static2_ZJDY], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZJYS], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZDQXH], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZYZ], val);
		init(m_aStaticsToShow[StaticId2::Static2_BZXDTGG], val);
		init(m_aStaticsToShow[StaticId2::Static2_ZZS], val);
		init(m_aStaticsToShow[StaticId2::Static2_KHQY], val);
		init(m_aStaticsToShow[StaticId2::Static2_YXJ], val);
		init(m_aStaticsToShow[StaticId2::Static2_GH], val);

		init(m_aEdits[EditId::Edit_CCBH], val);
		init(m_aEdits[EditId::Edit_TCBH], val);

		val = _T("");

		init(m_aDatePickers[DatePickerId::DatePicker_BZRQ], val);
		init(m_aDatePickers[DatePickerId::DatePicker_FHRQ], val);
		init(m_aDatePickers[DatePickerId::DatePicker_SCRQ], val);
	}

	m_aDatePickers[DatePicker_SCRQ]->EnableWindow(m_bEnablePlanBtnForSCRQ);
	m_aDatePickers[DatePicker_BZRQ]->EnableWindow(m_bEnablePlanBtnForBZRQ);

	m_aEdits[Edit_TCBH]->EnableWindow(m_bEnablePlanEditForTCBH);
	m_aEdits[Edit_CCBH]->EnableWindow(m_bEnablePlanEditForCCBH);
	m_btnNewIDForSCRQ->EnableWindow(m_bEnablePlanEditForTCBH);
	m_btnNewIDForBZRQ->EnableWindow(m_bEnablePlanEditForCCBH);

	InitCtrlData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CPlanAddDlg::PostNcDestroy()
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

	for (int i = 0; i < _countof(m_aDatePickers); ++i)
	{
		if (NULL != m_aDatePickers[i])
		{
			delete m_aDatePickers[i];
		}
	}

	CPopupDlg::PostNcDestroy();
}

void CPlanAddDlg::OnOK()
{
	CString strTmp;
	CTime time;
	m_vecResult.clear();
	DWORD dwResult = m_aDatePickers[DatePickerId::DatePicker_SCRQ]->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		m_aDatePickers[DatePickerId::DatePicker_SCRQ]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	else
	{
		m_vecResult.push_back(_T(""));
	}

	dwResult = m_aDatePickers[DatePickerId::DatePicker_BZRQ]->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		m_aDatePickers[DatePickerId::DatePicker_BZRQ]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	else
	{
		m_vecResult.push_back(_T(""));
	}

	dwResult = m_aDatePickers[DatePickerId::DatePicker_FHRQ]->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		m_aDatePickers[DatePickerId::DatePicker_FHRQ]->GetWindowText(strTmp);
		m_vecResult.push_back(strTmp);
	}
	else
	{
		m_vecResult.push_back(_T(""));
	}

	//m_aDatePickers[DatePickerId::DatePicker_BZRQ]->GetWindowText(strTmp);
	//m_vecResult.push_back(strTmp);

	//m_aDatePickers[DatePickerId::DatePicker_FHRQ]->GetWindowText(strTmp);
	//m_vecResult.push_back(strTmp);

	m_aEdits[EditId::Edit_TCBH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);
	bool bCanBeUse = false;
	if (!strTmp.IsEmpty() && NULL != m_lpOption && strTmp != m_lpOption->tcbh){
		if (CServer::GetInstance()->GetPlan().ValidateTcbhSync(strTmp, bCanBeUse))
		{
			if (!bCanBeUse)
			{
				MessageBox(_T("投产编号已使用"), _T("警告"), MB_OK | MB_ICONWARNING);
				return;
			}
		}
		else{
			MessageBox(_T("网络连接错误"), _T("警告"), MB_OK | MB_ICONWARNING);
			return;
		}
	}

	m_aEdits[EditId::Edit_CCBH]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);
	if (!strTmp.IsEmpty() && NULL != m_lpOption && strTmp != m_lpOption->ccbh){
		if (CServer::GetInstance()->GetPlan().ValidateCcbhSync(strTmp, bCanBeUse))
		{
			if (!bCanBeUse)
			{
				MessageBox(_T("出厂编号已使用"), _T("警告"), MB_OK | MB_ICONWARNING);
				return;
			}
		}
		else{
			MessageBox(_T("网络连接错误"), _T("警告"), MB_OK | MB_ICONWARNING);
			return;
		}
	}

	GetText(m_aCombs[CombId::Comb_ZC], Comb_ZC, strTmp);
	m_vecResult.push_back(strTmp);

	m_aEdits[EditId::Edit_BZ]->GetWindowText(strTmp);
	m_vecResult.push_back(strTmp);

	GetText(m_aCombs[CombId::Comb_CG], Comb_CG, strTmp);
	m_vecResult.push_back(strTmp);

	CPopupDlg::OnOK();
}

void CPlanAddDlg::GetText(CComboBox* pComboBox, CombId comId, CString& text)
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

void CPlanAddDlg::SetText(CComboBox* pComboBox, CombId comId, CString& text)
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


void CPlanAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}

int CPlanAddDlg::m_iRef = 0;

std::vector<std::vector<CString>> CPlanAddDlg::m_DropList;

BOOL CPlanAddDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
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
