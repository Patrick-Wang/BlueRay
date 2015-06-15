// TableFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "JQGridAPI.h"
#include "TableFilterDlgForNotificationPlan.h"
#include "resource_ids.h"
#include "afxdialogex.h"
#include "Util.h"

#define IDC_CHECKBOX_BASE (IDC_TABLEFILTER_BASE + 1)

static LPCTSTR g_TableFilterSettingName[][1] = { //0: default text
		{ IDS_SETTING_ITEM_TABLEFILTER_HTH },
		{ IDS_SETTING_ITEM_TABLEFILTER_KHMC },
		{ IDS_SETTING_ITEM_TABLEFILTER_GGBH },
		{ IDS_SETTING_ITEM_TABLEFILTER_CG },
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
		{ IDS_SETTING_ITEM_TABLEFILTER_ZJDY },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZJYS },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZDQXH },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZYZ },
		{ IDS_SETTING_ITEM_TABLEFILTER_BZXDTGG },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZZS },
		{ IDS_SETTING_ITEM_TABLEFILTER_KHQY },
		{ IDS_SETTING_ITEM_TABLEFILTER_YXJ },
		{ IDS_SETTING_ITEM_TABLEFILTER_GH },
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
		{ _T("磁钢") },
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
		{ _T("主机电压") },
		{ _T("主机颜色") },
		{ _T("制动器型号") },
		{ _T("左/右置") },
		{ _T("包装箱/底托规格") },
		{ _T("制造商") },
		{ _T("客户区域") },
		{ _T("优先级") },
		{ _T("工号") },
		{ _T("业务审核") },
		{ _T("计划审核") },
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
		{ 80 * 4 + 80 * 3, 40 * 1, 100, 20 }, //CheckBox_CG
		{ 80 * 1 + 80 * 0, 40 * 2, 100, 20 }, //CheckBox_SL,
		{ 80 * 2 + 80 * 1, 40 * 2, 100, 20 }, //CheckBox_ZC,
		{ 80 * 3 + 80 * 2, 40 * 2, 100, 20 }, //CheckBox_DFR,
		{ 80 * 4 + 80 * 3, 40 * 2, 100, 20 }, //CheckBox_ZDQDY,
		{ 80 * 1 + 80 * 0, 40 * 3, 100, 20 }, //CheckBox_YYLGG,
		{ 80 * 2 + 80 * 1, 40 * 3, 100, 20 }, //CheckBox_JF,
		{ 80 * 3 + 80 * 2, 40 * 3, 100, 20 }, //CheckBox_BPQXH,
		{ 80 * 4 + 80 * 3, 40 * 3, 100, 20 }, //CheckBox_BMQXH,
		{ 80 * 1 + 80 * 0, 40 * 4, 100, 20 }, //CheckBox_DLCD,
		{ 80 * 2 + 80 * 1, 40 * 4, 100, 20 }, //CheckBox_ZXCD,
		{ 80 * 3 + 80 * 2, 40 * 4, 100, 20 }, //CheckBox_MPZL,
		{ 80 * 4 + 80 * 3, 40 * 4, 100, 20 }, //CheckBox_BZ,
		{ 80 * 1 + 80 * 0, 40 * 5, 100, 20 }, //CheckBox_DDRQ,
		{ 80 * 2 + 80 * 1, 40 * 5, 100, 20 }, //CheckBox_ZJDY,
		{ 80 * 3 + 80 * 2, 40 * 5, 100, 20 }, //CheckBox_ZJYS,
		{ 80 * 4 + 80 * 3, 40 * 5, 100, 20 }, //CheckBox_ZDQXH,
		{ 80 * 1 + 80 * 0, 40 * 6, 100, 20 }, //CheckBox_ZYZ,
		{ 80 * 2 + 80 * 1, 40 * 6, 100, 20 }, //CheckBox_BZXDTGG
		{ 80 * 3 + 80 * 2, 40 * 6, 100, 20 }, //CheckBox_ZZS,
		{ 80 * 4 + 80 * 3, 40 * 6, 100, 20 }, //CheckBox_KHQY,,
		{ 80 * 1 + 80 * 0, 40 * 7, 100, 20 }, //CheckBox_YXJ,
		{ 80 * 2 + 80 * 1, 40 * 7, 100, 20 },  //CheckBox_GH,
		{ 0, 0, 0, 0 },  //CheckBox_shyw,
		{ 0, 0, 0, 0 },  //CheckBox_shjh,
		{ 80 * 3 + 80 * 2, 40 * 7, 100, 20 }, //CheckBox_SCRQ,
		{ 80 * 4 + 80 * 3, 40 * 7, 100, 20 }, //CheckBox_JHSHYW,
		{ 80 * 1 + 80 * 0, 40 * 8, 100, 20 }, //CheckBox_JHSHJH,
		{ 80 * 2 + 80 * 1, 40 * 8, 100, 20 }, //CheckBox_BZRQ,
		{ 80 * 3 + 80 * 2, 40 * 8, 100, 20 }, //CheckBox_BZSHYW,
		{ 80 * 4 + 80 * 3, 40 * 8, 100, 20 }, //CheckBox_BZSHJH,
		{ 80 * 1 + 80 * 0, 40 * 9, 100, 20 }, //CheckBox_FHRQ,
		{ 80 * 2 + 80 * 1, 40 * 9, 100, 20 }, //CheckBox_TCBH,
		{ 80 * 3 + 80 * 2, 40 * 9, 100, 20 }, //CheckBox_CCBH,
};

static int g_ColsMustBeHidden[] =
{
	nsNotification::Column_en::dfr,
	nsNotification::Column_en::yxj,
	nsNotification::Column_en::ywsh,
	nsNotification::Column_en::jhsh,
};

// CTableFilterDlgForNotificationPlan dialog

IMPLEMENT_DYNAMIC(CTableFilterDlgForNotificationPlan, CPopupDlg)

CTableFilterDlgForNotificationPlan::CTableFilterDlgForNotificationPlan(LPCTSTR title, CWnd* pParent /*=NULL*/)
: CPopupDlg(title, pParent)
{

}

CTableFilterDlgForNotificationPlan::~CTableFilterDlgForNotificationPlan()
{
}

bool CTableFilterDlgForNotificationPlan::Initialize(CJQGridAPI* pJqGridAPI)
{
	bool bRet = false;

	do 
	{
		CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
		if (NULL == pobjSettingManager)
		{
			break;
		}
		
		m_pJqGridAPI = pJqGridAPI;
		
		if (NULL == m_pJqGridAPI)
		{
			break;
		}
		

		CString strValue;

		for (int i = 0; i < nsNotification::end; ++i)
		{

			pobjSettingManager->GetTableFilterSettingForNotificationPlan(g_TableFilterSettingName[i][0], strValue);

			if (0 != strValue.Compare(IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED))
			{
				m_pJqGridAPI->HideCol(i);
			}
			else
			{
				m_pJqGridAPI->ShowCol(i);
			}

		}

		for (int i = 0; i < _countof(g_ColsMustBeHidden); i++)
		{
			m_pJqGridAPI->HideCol(g_ColsMustBeHidden[i]);
		}

		bRet = true;

	} while (false);

	return bRet;
}

BEGIN_MESSAGE_MAP(CTableFilterDlgForNotificationPlan, CPopupDlg)
	ON_BN_CLICKED(IDC_CHECKBOX_SELECTALL, &CTableFilterDlgForNotificationPlan::OnBnClickedSelectAll)
END_MESSAGE_MAP()


// CTableFilterDlgForNotificationPlan message handlers

BOOL CTableFilterDlgForNotificationPlan::OnInitDialog()
{
	__super::OnInitDialog();
	Util_Tools::Util::SetClientSize(m_hWnd, 837, 480);
	m_btnOK.MoveWindow(556, 40 * 11 - 20, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 11 - 20, 114, 30);
	CenterWindow();

	m_checkboxSelectAll = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_SELECTALL, _T("全选"), _T("Microsoft YaHei"), 12);
	m_checkboxSelectAll->MoveWindow(80 * 1 + 80 * 0, 40 * 11 - 20, 100, 20);

	//const std::set<int>& hiddenCols = m_pJqGridAPI->getHiddenCols();

	//init check box according to user setting
	
	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL == pobjSettingManager)
	{
		return FALSE;
	}

	CString strValue;
	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i] = NULL;
		m_aCheckBoxs[i] = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_BASE + i, g_CheckBoxCaptions[i][0], _T("Microsoft YaHei"), 12);
		m_aCheckBoxs[i]->MoveWindow(g_CheckBoxPos[i][0], g_CheckBoxPos[i][1], g_CheckBoxPos[i][2], g_CheckBoxPos[i][3]);

		pobjSettingManager->GetTableFilterSettingForNotificationPlan(g_TableFilterSettingName[i][0], strValue);

		if (0 == strValue.Compare(IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED))
		{
			m_aCheckBoxs[i]->SetCheck(TRUE);
		}
		else
		{
			m_aCheckBoxs[i]->SetCheck(FALSE);
		}

	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CTableFilterDlgForNotificationPlan::SaveColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL != pobjSettingManager)
	{
		for (int i = 0; i < _countof(g_TableFilterSettingName); ++i)
		{
			pobjSettingManager->SetTableFilterSettingForNotificationPlan(g_TableFilterSettingName[i][0], vecColsStatus[i]);
		}
	}
}

void CTableFilterDlgForNotificationPlan::GetColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL != pobjSettingManager)
	{
		for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
		{

			pobjSettingManager->GetTableFilterSettingForNotificationPlan(g_TableFilterSettingName[i][0], strValue);
			
			vecColsStatus.push_back(strValue);

		}
	}
}

void CTableFilterDlgForNotificationPlan::PostNcDestroy()
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

void CTableFilterDlgForNotificationPlan::OnOK(){

	//save user settings

	//update table

	std::vector<CString> vecColsStatus;

	for (int i = 0; i < _countof(m_aCheckBoxs); ++i)
	{

		if (!m_aCheckBoxs[i]->GetCheck())
		{
			vecColsStatus.push_back(IDS_SETTING_ITEM_TABLEFILTER_VALUE_UNCHECKED);
			m_pJqGridAPI->HideCol(i);
		}
		else
		{
			vecColsStatus.push_back(IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED);

			if (!IsMustBeHiddenCol(i))
			{
				m_pJqGridAPI->ShowCol(i);
			}
			else
			{
				m_pJqGridAPI->HideCol(i);
			}
		}
	}

	SaveColsSetting(vecColsStatus);
	
	__super::OnOK();
}

void CTableFilterDlgForNotificationPlan::OnCancel(){

	__super::OnCancel();
}

bool CTableFilterDlgForNotificationPlan::IsMustBeHiddenCol(int iColIndex)
{

	bool bRet = false;

	for (int i = 0; i < _countof(g_ColsMustBeHidden); i++)
	{
		if (iColIndex == g_ColsMustBeHidden[i])
		{
			bRet = true;
			break;
		}
	}

	return bRet;

}

void CTableFilterDlgForNotificationPlan::OnBnClickedSelectAll()
{
	// TODO: Add your control notification handler code here

	bool bCheckedAll = false;

	if (m_checkboxSelectAll->GetCheck())
	{
		bCheckedAll = true;
	}
	else
	{
		bCheckedAll = false;
	}

	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i]->SetCheck(bCheckedAll);
	}
}