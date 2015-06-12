#include "stdafx.h"
#include "Server.h"
#include "NotificationAddDlgForPlan.h"
#include "resource_ids.h"
#include "Util.h"

#define IDC_EDIT_BASE (IDC_PLAN_ADD_Control_BASE)
#define IDC_STATIC_BASE (IDC_PLAN_ADD_Control_BASE + 20)
#define IDC_STATIC_TOSHOW_BASE (IDC_STATIC_BASE + 20)
#define IDC_DATETIME_BASE (IDC_STATIC_TOSHOW_BASE + 20)
#define IDC_COMBO_BASE (IDC_DATETIME_BASE + 20)

#define QUERY_COMBO_VALUE_ZC_URL_ID		(IDC_COMBO_BASE + 21)
#define QUERY_COMBO_VALUE_CG_URL_ID		(IDC_COMBO_BASE + 22)


//按显示的顺序行列排序，与Static的定义顺序一致
static int g_StaticPos[][4] = {
		{ 100 * 0 + 100 * 0, 40 * 1 - 15, 100, 20 }, //Static_HTH,
		{ 100 * 1 + 100 * 1, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
		{ 100 * 2 + 100 * 2, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
		{ 100 * 3 + 100 * 3, 40 * 1 - 15, 100, 20 }, //Static_CG,
		{ 100 * 0 + 100 * 0, 40 * 2 - 15, 100, 20 }, //Static_SL,
		{ 100 * 1 + 100 * 1, 40 * 2 - 15, 100, 20 }, //Static_ZC,
		{ 100 * 2 + 100 * 2, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
		{ 100 * 3 + 100 * 3, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
		{ 100 * 0 + 100 * 0, 40 * 3 - 15, 100, 20 }, //Static_JF,
		{ 100 * 1 + 100 * 1, 40 * 3 - 15, 100, 20 }, //Static_BPQXH,
		{ 100 * 2 + 100 * 2, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
		{ 100 * 3 + 100 * 3, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
		{ 100 * 0 + 100 * 0, 40 * 4 - 15, 100, 20 }, //Static_ZXCD,
		{ 100 * 1 + 100 * 1, 40 * 4 - 15, 100, 20 }, //Static_MPZL,
		{ 100 * 2 + 100 * 2, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
		{ 100 * 3 + 100 * 3, 40 * 4 - 15, 100, 20 },	//zjdy
		{ 100 * 0 + 100 * 0, 40 * 5 - 15, 100, 20 },	//zjys
		{ 100 * 1 + 100 * 1, 40 * 5 - 15, 100, 20 },	//zdqxh
		{ 100 * 2 + 100 * 2, 40 * 5 - 15, 100, 20 },	//zyz
		{ 100 * 3 + 100 * 3, 40 * 5 - 15, 100, 20 },	//bzxgg
		{ 100 * 0 + 100 * 0, 40 * 6 - 15, 100, 20 },	//zzs
		{ 100 * 1 + 100 * 1, 40 * 6 - 15, 100, 20 },	//khqy
		{ 100 * 2 + 100 * 2, 40 * 6 - 15, 100, 20 },	//gh
		{ 100 * 3 + 100 * 3, 40 * 6 - 15, 100, 20 },  //Static_SCRQ,
		{ 100 * 0 + 100 * 0, 40 * 7 - 15, 100, 20 },  //Static_JHYWSH,
		{ 100 * 1 + 100 * 1, 40 * 7 - 15, 100, 20 },  //Static_JHJHSH,
		{ 100 * 2 + 100 * 2, 40 * 7 - 15, 100, 20 },  //Static_BZRQ,
		{ 100 * 3 + 100 * 3, 40 * 7 - 15, 100, 20 },  //Static_BZYWSH,
		{ 100 * 0 + 100 * 0, 40 * 8 - 15, 100, 20 },  //Static_BZJHSH,
		{ 100 * 1 + 100 * 1, 40 * 8 - 15, 100, 20 },  //Static_FHRQ,
		{ 100 * 2 + 100 * 2, 40 * 8 - 15, 100, 20 },  //Static_TCBH,
		{ 100 * 3 + 100 * 3, 40 * 8 - 15, 100, 20 },   //Static_CCBH
		{ 100 * 0 + 100 * 0, 40 * 9 - 15, 100, 20 },   //bz
};


static int g_StaticToShowPos[][4] = {
		{ 100 * 1 + 100 * 0 + 8, 40 * 1 - 15, 100, 20 }, //Static_HTH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 1 - 15, 100, 20 }, //Static_KHMC,
		{ 100 * 3 + 100 * 2 + 8, 40 * 1 - 15, 100, 20 }, //Static_GGBH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 1 - 15, 100, 20 }, //Static_CG,
		{ 100 * 1 + 100 * 0 + 8, 40 * 2 - 15, 100, 20 }, //Static_SL,
		{ 100 * 2 + 100 * 1 + 8, 40 * 2 - 15, 100, 20 }, //Static_ZC,
		{ 100 * 3 + 100 * 2 + 8, 40 * 2 - 15, 100, 20 }, //Static_ZDQDY,
		{ 100 * 4 + 100 * 3 + 8, 40 * 2 - 15, 100, 20 }, //Static_YYLGG,
		{ 100 * 1 + 100 * 0 + 8, 40 * 3 - 15, 100, 20 }, //Static_JF,
		{ 100 * 2 + 100 * 1 + 8, 40 * 3 - 15, 100, 20 }, //Static_BPQXH,
		{ 100 * 3 + 100 * 2 + 8, 40 * 3 - 15, 100, 20 }, //Static_BMQXH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 3 - 15, 100, 20 }, //Static_DLCD,
		{ 100 * 1 + 100 * 0 + 8, 40 * 4 - 15, 100, 20 }, //Static_ZXCD,
		{ 100 * 2 + 100 * 1 + 8, 40 * 4 - 15, 100, 20 }, //Static_MPZL,
		{ 100 * 3 + 100 * 2 + 8, 40 * 4 - 15, 100, 20 }, //Static_DDRQ,
		{ 100 * 4 + 100 * 3 + 8, 40 * 4 - 15, 100, 20 },	//zjdy
		{ 100 * 1 + 100 * 0 + 8, 40 * 5 - 15, 100, 20 },	//zjys
		{ 100 * 2 + 100 * 1 + 8, 40 * 5 - 15, 100, 20 },	//zdqxh
		{ 100 * 3 + 100 * 2 + 8, 40 * 5 - 15, 100, 20 },	//zyz
		{ 100 * 4 + 100 * 3 + 8, 40 * 5 - 15, 100, 20 },	//bzxgg
		{ 100 * 1 + 100 * 0 + 8, 40 * 6 - 15, 100, 20 },	//zzs
		{ 100 * 2 + 100 * 1 + 8, 40 * 6 - 15, 100, 20 },	//khqy
		{ 100 * 3 + 100 * 2 + 8, 40 * 6 - 15, 100, 20 },	//gh
		{ 100 * 4 + 100 * 3 + 8, 40 * 6 - 15, 100, 20 },  //Static_SCRQ,
		{ 100 * 1 + 100 * 0 + 8, 40 * 7 - 15, 100, 20 },  //Static_JHYWSH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 7 - 15, 100, 20 },  //Static_JHJHSH,
		{ 100 * 3 + 100 * 2 + 8, 40 * 7 - 15, 100, 20 },  //Static_BZRQ,
		{ 100 * 4 + 100 * 3 + 8, 40 * 7 - 15, 100, 20 },  //Static_BZYWSH,
		{ 100 * 1 + 100 * 0 + 8, 40 * 8 - 15, 100, 20 },  //Static_BZJHSH,
		{ 100 * 2 + 100 * 1 + 8, 40 * 8 - 15, 100, 20 },  //Static_FHRQ,
		{ 100 * 3 + 100 * 2 + 8, 40 * 8 - 15, 100, 20 },  //Static_TCBH,
		{ 100 * 4 + 100 * 3 + 8, 40 * 8 - 15, 100, 20 },   //Static_CCBH
		{ 100 * 1 + 100 * 0 + 8, 40 * 9 - 15, 400, 60 },   //bz

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

BEGIN_MESSAGE_MAP(CNotificationAddDlgForPlan, CPopupDlg)
END_MESSAGE_MAP()

CNotificationAddDlgForPlan::CNotificationAddDlgForPlan(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CPopupDlg(title, pParent)
	, m_lpOption(NULL)
	, m_bIsSalePage(TRUE)
{

}


CNotificationAddDlgForPlan::~CNotificationAddDlgForPlan()
{

}

void CNotificationAddDlgForPlan::SetDlgOption(BOOL bIsSalePage)
{
	m_bIsSalePage = bIsSalePage;
}


void CNotificationAddDlgForPlan::OnNcDestroy()
{
	__super::OnNcDestroy();
}

void CNotificationAddDlgForPlan::InitHttpInstance()
{

}

void CNotificationAddDlgForPlan::OnHttpFailed(int id)
{

}

void CNotificationAddDlgForPlan::OnHttpSuccess(int id, LPCTSTR resp)
{

}

void CNotificationAddDlgForPlan::OnLoadComboDataSuccess(int id, CString strValList)
{

}

const std::vector<std::vector<CString>>& CNotificationAddDlgForPlan::GetDropList()
{
	return m_DropList;
}

void CNotificationAddDlgForPlan::InitCtrlData()
{
	if (NULL == m_lpOption)
	{
		d_GetOption(*this);
	}

	CFont* pFont = NULL;
	pFont = CBSObject::GetFontPtr(_T("Microsoft YaHei"), 12, FALSE, FALSE, FALSE);
}

static LPCTSTR g_StaticItems[][1] = { //0: default text
		{ _T("合同号:") },
		{ _T("客户名称:") },
		{ _T("规格型号:") },
		{ _T("磁钢:") },
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
		{ _T("生产日期:") },
		{ _T("生产业务审核:") },
		{ _T("生产计划审核:") },
		{ _T("包装日期:") },
		{ _T("包装业务审核:") },
		{ _T("包装计划审核:") },
		{ _T("发货日期:") },
		{ _T("投产编号:") },
		{ _T("出厂编号:") },
		{ _T("备注:") }
};

BOOL CNotificationAddDlgForPlan::OnInitDialog()
{
	CPopupDlg::OnInitDialog();

	Util_Tools::Util::SetClientSize(m_hWnd, 837, 460);
	m_btnOK.MoveWindow(556, 40 * 10 + 10, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 10 + 10, 114, 30);

	m_btnOK.SetWindowTextW(_T("确认审核"));
	m_btnCancel.SetWindowTextW(_T("取消审核"));

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

	if (NULL != m_lpOption)
	{
		init(m_aStaticsToShow[StaticId::Static_HTH], m_lpOption->htbh);
		init(m_aStaticsToShow[StaticId::Static_KHMC], m_lpOption->khmc);
		init(m_aStaticsToShow[StaticId::Static_GGBH], m_lpOption->ggbh);
		init(m_aStaticsToShow[StaticId::Static_CG], m_lpOption->cg);
		init(m_aStaticsToShow[StaticId::Static_SL], m_lpOption->sl);
		init(m_aStaticsToShow[StaticId::Static_ZC], m_lpOption->zc);
		init(m_aStaticsToShow[StaticId::Static_ZDQDY], m_lpOption->zdqdy);
		init(m_aStaticsToShow[StaticId::Static_YYLGG], m_lpOption->yylgg);
		init(m_aStaticsToShow[StaticId::Static_JF], m_lpOption->jf);
		init(m_aStaticsToShow[StaticId::Static_BPQXH], m_lpOption->bpqxh);
		init(m_aStaticsToShow[StaticId::Static_BMQXH], m_lpOption->bmqxh);
		init(m_aStaticsToShow[StaticId::Static_DLCD], m_lpOption->dlcd);
		init(m_aStaticsToShow[StaticId::Static_ZXCD], m_lpOption->zxcd);
		init(m_aStaticsToShow[StaticId::Static_MPZL], m_lpOption->mpzl);
		init(m_aStaticsToShow[StaticId::Static_DDRQ], m_lpOption->ddrq);
		init(m_aStaticsToShow[StaticId::Static_ZJDY], m_lpOption->zjdy);
		init(m_aStaticsToShow[StaticId::Static_ZJYS], m_lpOption->zjys);
		init(m_aStaticsToShow[StaticId::Static_ZDQXH], m_lpOption->zdqxh);
		init(m_aStaticsToShow[StaticId::Static_ZYZ], m_lpOption->zyz);
		init(m_aStaticsToShow[StaticId::Static_BZXDTGG], m_lpOption->bzxdtgg);
		init(m_aStaticsToShow[StaticId::Static_ZZS], m_lpOption->zzs);
		init(m_aStaticsToShow[StaticId::Static_KHQY], m_lpOption->khqy);
		init(m_aStaticsToShow[StaticId::Static_GH], m_lpOption->gh);
		init(m_aStaticsToShow[StaticId::Static_SCRQ], m_lpOption->scrq);
		init(m_aStaticsToShow[StaticId::Static_JHYWSH], m_lpOption->jhywsh);
		init(m_aStaticsToShow[StaticId::Static_JHJHSH], m_lpOption->jhjhsh);
		init(m_aStaticsToShow[StaticId::Static_BZRQ], m_lpOption->bzrq);
		init(m_aStaticsToShow[StaticId::Static_BZYWSH], m_lpOption->bzywsh);
		init(m_aStaticsToShow[StaticId::Static_BZJHSH], m_lpOption->bzjhsh);
		init(m_aStaticsToShow[StaticId::Static_FHRQ], m_lpOption->fhrq);
		init(m_aStaticsToShow[StaticId::Static_TCBH], m_lpOption->tcbh);
		init(m_aStaticsToShow[StaticId::Static_CCBH], m_lpOption->ccbh);
		init(m_aStaticsToShow[StaticId::Static_BZ], m_lpOption->bz);

	}
	else
	{
		CString val(_T("NULL"));
		init(m_aStaticsToShow[StaticId::Static_HTH], val);
		init(m_aStaticsToShow[StaticId::Static_KHMC], val);
		init(m_aStaticsToShow[StaticId::Static_GGBH], val);
		init(m_aStaticsToShow[StaticId::Static_CG], val);
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
		init(m_aStaticsToShow[StaticId::Static_SCRQ], val);
		init(m_aStaticsToShow[StaticId::Static_JHYWSH], val);
		init(m_aStaticsToShow[StaticId::Static_JHJHSH], val);
		init(m_aStaticsToShow[StaticId::Static_BZRQ], val);
		init(m_aStaticsToShow[StaticId::Static_BZYWSH], val);
		init(m_aStaticsToShow[StaticId::Static_BZJHSH], val);
		init(m_aStaticsToShow[StaticId::Static_FHRQ], val);
		init(m_aStaticsToShow[StaticId::Static_TCBH], val);
		init(m_aStaticsToShow[StaticId::Static_CCBH], val);
		init(m_aStaticsToShow[StaticId::Static_BZ], val);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CNotificationAddDlgForPlan::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CFont* pFont = NULL;

// 	for (int i = 0; i < _countof(m_aCombs); ++i)
// 	{
// 		if (NULL != m_aCombs[i])
// 		{
// 			delete m_aCombs[i];
// 		}
// 	}

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

	CPopupDlg::PostNcDestroy();
}

void CNotificationAddDlgForPlan::OnOK()
{
	CPopupDlg::OnOK();
}

// void CNotificationAddDlgForPlan::GetText(CComboBox* pComboBox, CombId comId, CString& text)
// {
// 	pComboBox->GetWindowText(text);
// 	CString strTmp;
// 	int i = m_DropList[comId].size() - 1;
// 	for (; i >= 0; --i)
// 	{
// 		if (m_DropList[comId][i] == text)
// 		{
// 			break;
// 		}
// 	}
// 	if (i < 0)
// 	{
// 		m_DropList[comId].push_back(text);
// 	}
// }
// 
// void CNotificationAddDlgForPlan::SetText(CComboBox* pComboBox, CombId comId, CString& text)
// {
// 	CString strTmp;
// 	int i = m_DropList[comId].size() - 1;
// 	for (; i >= 0; --i)
// 	{
// 		if (m_DropList[comId][i] == text)
// 		{
// 			break;
// 		}
// 	}
// 	if (i < 0)
// 	{
// 		m_DropList[comId].push_back(text);
// 		pComboBox->AddString(text);
// 		pComboBox->SetCurSel(pComboBox->GetCount() - 1);
// 	}
// 	else
// 	{
// 		pComboBox->SetCurSel(i);
// 	}
// }


void CNotificationAddDlgForPlan::SetOption(Option_t* lpOpt)
{
	m_lpOption = lpOpt;
}

int CNotificationAddDlgForPlan::m_iRef = 0;

std::vector<std::vector<CString>> CNotificationAddDlgForPlan::m_DropList;

BOOL CNotificationAddDlgForPlan::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
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
// 		CString text;
// 		m_aCombs[nID - IDC_COMBO_BASE]->GetWindowText(text);
// 		if (text.IsEmpty())
// 		{
// 			int count = m_aCombs[nID - IDC_COMBO_BASE]->GetCount();
// 			for (int i = 0; i < count; ++i)
// 			{
// 				m_aCombs[nID - IDC_COMBO_BASE]->DeleteString(0);
// 			}
// 			for (int j = GetDropList()[nID - IDC_COMBO_BASE].size() - 1; j >= 0; --j)
// 			{
// 				m_aCombs[nID - IDC_COMBO_BASE]->InsertString(0, GetDropList()[nID - IDC_COMBO_BASE][j]);
// 			}
		}
		else
		{
// 			std::vector<CString> tmpVals;
// 			for (int i = 0; i < GetDropList()[nID - IDC_COMBO_BASE].size(); ++i)
// 			{
// 				if (GetDropList()[nID - IDC_COMBO_BASE][i].Find(text) >= 0)
// 				{
// 					tmpVals.push_back(GetDropList()[nID - IDC_COMBO_BASE][i]);
// 				}
// 			}
// 
// 			int count = m_aCombs[nID - IDC_COMBO_BASE]->GetCount();
// 			for (int i = 0; i < count; ++i)
// 			{
// 				m_aCombs[nID - IDC_COMBO_BASE]->DeleteString(0);
// 			}
// 			for (int i = 0; i < tmpVals.size(); ++i)
// 			{
// 				m_aCombs[nID - IDC_COMBO_BASE]->AddString(tmpVals[i]);
// 			}
// 		}
// 		m_aCombs[nID - IDC_COMBO_BASE]->ShowDropDown(TRUE);
	}

	return CPopupDlg::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
