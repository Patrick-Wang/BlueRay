#include "stdafx.h"
#include "Server.h"
#include "PlanAddDlg.h"
#include "resource_ids.h"
#include "Util.h"

#define IDC_EDIT_BASE (IDC_PLAN_ADD_Control_BASE)
#define IDC_STATIC_BASE (IDC_PLAN_ADD_Control_BASE + 20)
#define IDC_STATIC_TOSHOW_BASE (IDC_STATIC_BASE + 20)
#define IDC_DATETIME_BASE (IDC_STATIC_TOSHOW_BASE + 20)

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

CPlanAddDlg::CPlanAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CPopupDlg(title, pParent)
	, m_lpOption(NULL)
	, m_bEnablePlanBtnForSCRQ(false)
	, m_bEnablePlanBtnForBZRQ(false)
{

}


CPlanAddDlg::~CPlanAddDlg()
{
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
		{ _T("出厂编号") }

};

static int g_StaticPos[][4] = {
		{ 100 * 0 + 100 * 0, 40 * 1 - 15, 100, 20 }, //Static_HTH,
		{ 100 * 1 + 100 * 1, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
		{ 100 * 2 + 100 * 2, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
		{ 100 * 3 + 100 * 3, 40 * 1 - 15, 100, 20 }, //Static_SL,
		{ 100 * 0 + 100 * 0, 40 * 2 - 15, 100, 20 }, //Static_ZC,
		{ 100 * 1 + 100 * 1, 40 * 2 - 15, 100, 20 }, //Static_DFR,
		{ 100 * 2 + 100 * 2, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
		{ 100 * 3 + 100 * 3, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
		{ 100 * 0 + 100 * 0, 40 * 3 - 15, 100, 20 }, //Static_JF,
		{ 100 * 1 + 100 * 1, 40 * 3 - 15, 100, 20 }, //Static_BPQXH,
		{ 100 * 2 + 100 * 2, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
		{ 100 * 3 + 100 * 3, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
		{ 100 * 0 + 100 * 0, 40 * 4 - 15, 100, 20 }, //Static_ZXCD,
		{ 100 * 1 + 100 * 1, 40 * 4 - 15, 100, 20 }, //Static_MPZL,
		{ 100 * 2 + 100 * 2, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
		{ 100 * 3 + 100 * 3, 40 * 4 - 15, 100, 20 },  //Static_BZ,

		{ 100 * 0 + 100 * 0, 40 * 5 - 15, 100, 20 },  
		{ 100 * 1 + 100 * 1, 40 * 5 - 15, 100, 20 },  
		{ 100 * 2 + 100 * 2, 40 * 5 - 15, 100, 20 },  
		{ 100 * 3 + 100 * 3, 40 * 5 - 15, 100, 20 },  
		{ 100 * 0 + 100 * 0, 40 * 6 - 15, 100, 20 },  
		{ 100 * 1 + 100 * 1, 40 * 6 - 15, 100, 20 },  
		{ 100 * 2 + 100 * 2, 40 * 6 - 15, 100, 20 },  
		{ 100 * 3 + 100 * 3, 40 * 6 - 15, 100, 20 },  
		{ 100 * 0 + 100 * 0, 40 * 7 - 15, 100, 20 },  

		{ 100 * 0 + 100 * 0, 40 * 8, 100, 20 },  //Static_SCRQ,
		{ 100 * 1 + 100 * 1, 40 * 8, 100, 20 },  //Static_BZRQ,
		{ 100 * 2 + 100 * 2, 40 * 8, 100, 20 },  //Static_FHRQ,
		{ 100 * 0 + 100 * 0, 40 * 9, 100, 20 },  //Static_TCBH,
		{ 100 * 1 + 100 * 1, 40 * 9, 100, 20 }   //Static_CCBH
};


static int g_StaticToShowPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 1 - 15, 100, 20 }, //Edit_HTH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 1 - 15, 100, 20 }, //Comb_KHMC,
		{ 100 * 3 + 100 * 2 + 8, 40 * 1 - 15, 100, 20 }, //Comb_GGBH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 1 - 15, 100, 20 }, //Edit_SL,
		{ 100 * 1 + 100 * 0 + 8, 40 * 2 - 15, 100, 20 }, //Comb_ZC,
		{ 100 * 2 + 100 * 1 + 8, 40 * 2 - 15, 100, 20 }, //Comb_DFR,
		{ 100 * 3 + 100 * 2 + 8, 40 * 2 - 15, 100, 20 }, //Comb_ZDQDY,
		{ 100 * 4 + 100 * 3 + 8, 40 * 2 - 15, 100, 20 }, //Comb_YYLGG,
		{ 100 * 1 + 100 * 0 + 8, 40 * 3 - 15, 100, 20 }, //Comb_JF,
		{ 100 * 2 + 100 * 1 + 8, 40 * 3 - 15, 100, 20 }, //Comb_BPQXH,
		{ 100 * 3 + 100 * 2 + 8, 40 * 3 - 15, 100, 20 }, //Comb_BMQXH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 3 - 15, 100, 20 }, //Edit_DLCD,
		{ 100 * 1 + 100 * 0 + 8, 40 * 4 - 15, 100, 20 }, //Edit_ZXCD,
		{ 100 * 3 + 100 * 2 + 8, 40 * 4 - 15, 100, 20 }, //Edit_DDRQ,
		{ 100 * 2 + 100 * 1 + 8, 40 * 4 - 15, 100, 20 },	//Comb_MPZL,
		{ 100 * 4 + 100 * 3 + 8, 40 * 4 - 15, 100, 20 },  //Edit_BZ,

		{ 100 * 1 + 100 * 0 + 8, 40 * 5 - 15, 100, 20 },
		{ 100 * 3 + 100 * 2 + 8, 40 * 5 - 15, 100, 20 },
		{ 100 * 2 + 100 * 1 + 8, 40 * 5 - 15, 100, 20 },
		{ 100 * 4 + 100 * 3 + 8, 40 * 5 - 15, 100, 20 },
		{ 100 * 1 + 100 * 0 + 8, 40 * 6 - 15, 100, 20 },
		{ 100 * 3 + 100 * 2 + 8, 40 * 6 - 15, 100, 20 },
		{ 100 * 2 + 100 * 1 + 8, 40 * 6 - 15, 100, 20 },
		{ 100 * 4 + 100 * 3 + 8, 40 * 6 - 15, 100, 20 },
		{ 100 * 1 + 100 * 0 + 8, 40 * 7 - 15, 100, 20 }

};

static int g_EditsPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 9, 100, 20 }, //Edit_TCBH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 9, 100, 20 }  //Edit_CCBH,
};

static int g_DatePickersPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 8, 100, 20 }, //DatePicker_SCRQ,
		{ 100 * 2 + 100 * 1 + 8, 40 * 8, 100, 20 }, //DatePicker_BZRQ,
		{ 100 * 3 + 100 * 2 + 8, 40 * 8, 100, 20 }  //DatePicker_FHRQ,
};

static LPCTSTR g_EditItems[][1] = { //0: default text
		{ _T("投产编号") },
		{ _T("出厂编号") }
};


BOOL CPlanAddDlg::OnInitDialog()
{
	CPopupDlg::OnInitDialog();

	Util_Tools::Util::SetClientSize(m_hWnd, 837, 480);
	m_btnOK.MoveWindow(556, 40 * 11 - 20, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 11 - 20, 114, 30);
	
	CenterWindow();

	//init comb

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
		m_aEdits[i] = Util_Tools::Util::CreateEdit(this, IDC_EDIT_BASE + i, g_EditItems[i][0], _T("Microsoft YaHei"), 12);
		m_aEdits[i]->MoveWindow(g_EditsPos[i][0], g_EditsPos[i][1], g_EditsPos[i][2], g_EditsPos[i][3]);
	}

	//init date picker
	for (int i = 0; i < _countof(g_DatePickersPos); ++i)
	{
		m_aDatePickers[i] = Util_Tools::Util::CreateDateTimePicker(this, IDC_DATETIME_BASE + i, _T("Microsoft YaHei"), 12);
		m_aDatePickers[i]->MoveWindow(g_DatePickersPos[i][0], g_DatePickersPos[i][1], g_DatePickersPos[i][2], g_DatePickersPos[i][3]);
	}


	if (NULL != m_lpOption)
	{
		init(m_aStaticsToShow[StaticId2::Static2_HTH], m_lpOption->htbh);
		init(m_aStaticsToShow[StaticId2::Static2_KHMC], m_lpOption->khmc);
		init(m_aStaticsToShow[StaticId2::Static2_GGBH], m_lpOption->ggbh);
		init(m_aStaticsToShow[StaticId2::Static2_SL], m_lpOption->sl);
		init(m_aStaticsToShow[StaticId2::Static2_ZC], m_lpOption->zc);
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CPlanAddDlg::PostNcDestroy()
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
	if (!strTmp.IsEmpty() && NULL != m_lpOption && (OPT_FALSE == m_lpOption->tcbh || m_lpOption->tcbh.IsEmpty())){
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
	if (!strTmp.IsEmpty() && (NULL != m_lpOption && OPT_FALSE == m_lpOption->ccbh || m_lpOption->ccbh.IsEmpty())){
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
	

	CPopupDlg::OnOK();
}

void CPlanAddDlg::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}
