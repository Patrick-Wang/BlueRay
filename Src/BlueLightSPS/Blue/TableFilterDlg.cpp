// TableFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "JQGridAPI.h"
#include "TableFilterDlg.h"
#include "resource_ids.h"
#include "afxdialogex.h"
#include "Util.h"

#define IDC_CHECKBOX_BASE (IDC_TABLEFILTER_BASE + 1)

static LPCTSTR g_TableFilterSettingName[][1] = { //0: default text
		{ IDS_SETTING_ITEM_TABLEFILTER_HTH },
		{ IDS_SETTING_ITEM_TABLEFILTER_KHMC },
		{ IDS_SETTING_ITEM_TABLEFILTER_GGBH },
		{ IDS_SETTING_ITEM_TABLEFILTER_SL },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZC },
		{ IDS_SETTING_ITEM_TABLEFILTER_DFR },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZDQDY },
		{ IDS_SETTING_ITEM_TABLEFILTER_YYLGG },
		{ IDS_SETTING_ITEM_TABLEFILTER_JF },
		{ IDS_SETTING_ITEM_TABLEFILTER_BPQXH },
		{ IDS_SETTING_ITEM_TABLEFILTER_BMQXH },
		{ IDS_SETTING_ITEM_TABLEFILTER_DLCD },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZXCD },
		{ IDS_SETTING_ITEM_TABLEFILTER_MPZL },
		{ IDS_SETTING_ITEM_TABLEFILTER_BZ },
		{ IDS_SETTING_ITEM_TABLEFILTER_DDRQ },
		{ IDS_SETTING_ITEM_TABLEFILTER_SHYW },
		{ IDS_SETTING_ITEM_TABLEFILTER_SHJH },
		{ IDS_SETTING_ITEM_TABLEFILTER_SCRQ },
		{ IDS_SETTING_ITEM_TABLEFILTER_JHSHYW },
		{ IDS_SETTING_ITEM_TABLEFILTER_JHSHJH },
		{ IDS_SETTING_ITEM_TABLEFILTER_BZRQ },
		{ IDS_SETTING_ITEM_TABLEFILTER_BZSHYW },
		{ IDS_SETTING_ITEM_TABLEFILTER_BZSHJH },
		{ IDS_SETTING_ITEM_TABLEFILTER_FHRQ },
		{ IDS_SETTING_ITEM_TABLEFILTER_TCBH },
		{ IDS_SETTING_ITEM_TABLEFILTER_CCBH }

};

static LPCTSTR g_CheckBoxCaptions[][1] = { //0: default text
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
		{ _T("备注") },
		{ _T("订单日期") },

		{ _T("审核-业务") },
		{ _T("审核-计划") },
		{ _T("生产日期") },
		{ _T("计划审核-业务") },
		{ _T("计划审核-计划") },
		{ _T("包装日期") },
		{ _T("包装审核-业务") },
		{ _T("包装审核-计划") },
		{ _T("发货日期") },
		{ _T("投产编号") },
		{ _T("出厂编号") }

};

static int g_CheckBoxPos[][4] = {
		{ 80 * 1 + 80 * 0, 40 * 1, 100, 20 }, //CheckBox_HTH,
		{ 80 * 2 + 80 * 1, 40 * 1, 100, 20 }, //CheckBox_KHMC,
		{ 80 * 3 + 80 * 2, 40 * 1, 100, 20 }, //CheckBox_GGBH,
		{ 80 * 4 + 80 * 3, 40 * 1, 100, 20 }, //CheckBox_SL,
		{ 80 * 1 + 80 * 0, 40 * 2, 100, 20 }, //CheckBox_ZC,
		{ 80 * 2 + 80 * 1, 40 * 2, 100, 20 }, //CheckBox_DFR,
		{ 80 * 3 + 80 * 2, 40 * 2, 100, 20 }, //CheckBox_ZDQDY,
		{ 80 * 4 + 80 * 3, 40 * 2, 100, 20 }, //CheckBox_YYLGG,
		{ 80 * 1 + 80 * 0, 40 * 3, 100, 20 }, //CheckBox_JF,
		{ 80 * 2 + 80 * 1, 40 * 3, 100, 20 }, //CheckBox_BPQXH,
		{ 80 * 3 + 80 * 2, 40 * 3, 100, 20 }, //CheckBox_BMQXH,
		{ 80 * 4 + 80 * 3, 40 * 3, 100, 20 }, //CheckBox_DLCD,
		{ 80 * 1 + 80 * 0, 40 * 4, 100, 20 }, //CheckBox_ZXCD,
		{ 80 * 2 + 80 * 1, 40 * 4, 100, 20 }, //CheckBox_MPZL,
		{ 80 * 3 + 80 * 2, 40 * 4, 100, 20 }, //CheckBox_BZ,
		{ 80 * 4 + 80 * 3, 40 * 4, 100, 20 }, //CheckBox_DDRQ,
		{ 80 * 1 + 80 * 0, 40 * 5, 100, 20 }, //CheckBox_SHYW,
		{ 80 * 2 + 80 * 1, 40 * 5, 100, 20 }, //CheckBox_SHJH,
								   
		{ 80 * 3 + 80 * 2, 40 * 5, 100, 20 }, //CheckBox_SCRQ,
		{ 80 * 4 + 80 * 3, 40 * 5, 100, 20 }, //CheckBox_JHSHYW,
		{ 80 * 1 + 80 * 0, 40 * 6, 100, 20 }, //CheckBox_JHSHJH,
		{ 80 * 2 + 80 * 1, 40 * 6, 100, 20 }, //CheckBox_BZRQ,
		{ 80 * 3 + 80 * 2, 40 * 6, 100, 20 }, //CheckBox_BZSHYW,
		{ 80 * 4 + 80 * 3, 40 * 6, 100, 20 }, //CheckBox_BZSHJH,
		{ 80 * 1 + 80 * 0, 40 * 7, 100, 20 }, //CheckBox_FHRQ,
		{ 80 * 2 + 80 * 1, 40 * 7, 100, 20 }, //CheckBox_TCBH,
		{ 80 * 3 + 80 * 2, 40 * 7, 100, 20 }  //CheckBox_CCBH,
};											 

// CTableFilterDlg dialog

IMPLEMENT_DYNAMIC(CTableFilterDlg, CPopupDlg)

CTableFilterDlg::CTableFilterDlg(LPCTSTR title, CJQGridAPI* pJqGridAPI, PageIDEnum pageID, CWnd* pParent /*=NULL*/)
: CPopupDlg(title, pParent)
, m_enumPage(pageID)
//, m_Title(title)
, m_pJqGridAPI(pJqGridAPI)
{

}

CTableFilterDlg::~CTableFilterDlg()
{
}

//void CTableFilterDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//	DDX_Control(pDX, IDOK, m_btnOK);
//	DDX_Control(pDX, IDCANCEL, m_btnCancel);
//}


BEGIN_MESSAGE_MAP(CTableFilterDlg, CPopupDlg)
END_MESSAGE_MAP()


// CTableFilterDlg message handlers

BOOL CTableFilterDlg::OnInitDialog()
{
	__super::OnInitDialog();

	CenterWindow();

	//const std::set<int>& hiddenCols = m_pJqGridAPI->getHiddenCols();

	//init check box according to user setting
	CString strValue;
	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i] = Util::CreateCheckBox(this, IDC_CHECKBOX_BASE + i, g_CheckBoxCaptions[i][0], _T("Microsoft YaHei"), 12);
		m_aCheckBoxs[i]->MoveWindow(g_CheckBoxPos[i][0], g_CheckBoxPos[i][1], g_CheckBoxPos[i][2], g_CheckBoxPos[i][3]);

		if (Page_Sale == m_enumPage)
		{
			m_objSettingManager.GetTableFilterSettingForSale(g_TableFilterSettingName[i][0], strValue);
		}
		else if (Page_Plan == m_enumPage)
		{
			m_objSettingManager.GetTableFilterSettingForPlan(g_TableFilterSettingName[i][0], strValue);
		}

		if (0 == strValue.Compare(IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED))
		{
			m_aCheckBoxs[i]->SetCheck(TRUE);
		}
		else
		{
			m_aCheckBoxs[i]->SetCheck(FALSE);
		}

		if (Page_Sale == m_enumPage)
		{
			if (i == m_breakPointOfPlanPage)
			{
				break;
			}
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CTableFilterDlg::SaveColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	for (int i = 0; i < vecColsStatus.size(); ++i)
	{
		if (Page_Sale == m_enumPage)
		{
			m_objSettingManager.SetTableFilterSettingForSale(g_TableFilterSettingName[i][0], vecColsStatus[i]);
		}
		else if (Page_Plan == m_enumPage)
		{
			m_objSettingManager.SetTableFilterSettingForPlan(g_TableFilterSettingName[i][0], vecColsStatus[i]);
		}

		if (Page_Sale == m_enumPage)
		{
			if (i == m_breakPointOfPlanPage)
			{
				break;
			}
		}
	}
}

void CTableFilterDlg::GetColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		if (Page_Sale == m_enumPage)
		{
			m_objSettingManager.GetTableFilterSettingForSale(g_TableFilterSettingName[i][0], strValue);
		}
		else if (Page_Plan == m_enumPage)
		{
			m_objSettingManager.GetTableFilterSettingForPlan(g_TableFilterSettingName[i][0], strValue);
		}

		vecColsStatus[i] = strValue;

		if (Page_Sale == m_enumPage)
		{
			if (i == m_breakPointOfPlanPage)
			{
				break;
			}
		}
	}
}

void CTableFilterDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	for (int i = 0; i < _countof(m_aCheckBoxs); ++i)
	{
		if (NULL != m_aCheckBoxs[i])
		{
			delete m_aCheckBoxs[i];
		}
	}

	CDialogEx::PostNcDestroy();
}

void CTableFilterDlg::OnOK(){

	//save user settings

	//update table

	std::vector<CString> vecColsStatus;

	for (int i = 0; i < _countof(m_aCheckBoxs); ++i)
	{
		if (!m_aCheckBoxs[i]->GetCheck())
		{
			vecColsStatus[i] = IDS_SETTING_ITEM_TABLEFILTER_VALUE_UNCHECKED;
			m_pJqGridAPI->HideCol(i);
		}
		else
		{
			vecColsStatus[i] = IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED;
			m_pJqGridAPI->ShowCol(i);
		}

		if (Page_Sale == m_enumPage)
		{
			if (i == m_breakPointOfPlanPage)
			{
				break;
			}
		}
	}

	SaveColsSetting(vecColsStatus);
	
	__super::OnOK();
}

void CTableFilterDlg::OnCancel(){

	__super::OnCancel();
}
