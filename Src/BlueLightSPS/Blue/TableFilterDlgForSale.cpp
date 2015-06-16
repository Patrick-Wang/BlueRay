// TableFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "JQGridAPI.h"
#include "TableFilterDlgForSale.h"
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
		{ IDS_SETTING_ITEM_TABLEFILTER_SHJH }
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
		{ _T("主机电压") },
		{ _T("主机颜色") },
		{ _T("制动器型号") },
		{ _T("左/右置") },
		{ _T("包装箱/底托规格") },
		{ _T("工号") },
		{ _T("制造商") },
		{ _T("客户区域") },
		{ _T("优先级") },
		{ _T("审核-业务") },
		{ _T("审核-计划") }

};

static int g_CheckBoxPos[][4] = {
		{ 80 * 1 + 80 * 0, 40 * 1, 100, 20 }, //{ _T("合同号") },
		{ 80 * 2 + 80 * 1, 40 * 1, 100, 20 }, //{ _T("客户名称") },
		{ 80 * 3 + 80 * 2, 40 * 1, 100, 20 }, //{ _T("规格型号") },
		{ 80 * 4 + 80 * 3, 40 * 1, 100, 20 }, //{ _T("数量") },
		{ 0, 0, 0, 0 },						  //{ _T("轴承") },
		{ 0, 0, 0, 0 },						  //{ _T("单复绕") },
		{ 80 * 1 + 80 * 0, 40 * 2, 100, 20 }, //{ _T("制动器电压") },
		{ 80 * 2 + 80 * 1, 40 * 2, 100, 20 }, //{ _T("曳引轮规格") },
		{ 80 * 3 + 80 * 2, 40 * 2, 100, 20 }, //{ _T("机房") },
		{ 80 * 4 + 80 * 3, 40 * 2, 100, 20 }, //{ _T("变频器型号") },
		{ 80 * 1 + 80 * 0, 40 * 3, 100, 20 }, //{ _T("编码器型号") },
		{ 80 * 2 + 80 * 1, 40 * 3, 100, 20 }, //{ _T("电缆长度") },
		{ 80 * 3 + 80 * 2, 40 * 3, 100, 20 }, //{ _T("闸线长度") },
		{ 80 * 4 + 80 * 3, 40 * 3, 100, 20 }, //{ _T("铭牌等资料") },
		{ 80 * 1 + 80 * 0, 40 * 4, 100, 20 }, //{ _T("备注") },
		{ 80 * 2 + 80 * 1, 40 * 4, 100, 20 }, //{ _T("订单日期") },
		{ 80 * 3 + 80 * 2, 40 * 4, 100, 20 }, //{ _T("主机电压") },
		{ 80 * 4 + 80 * 3, 40 * 4, 100, 20 }, //{ _T("主机颜色") },
		{ 80 * 1 + 80 * 0, 40 * 5, 100, 20 }, //{ _T("制动器型号") },
		{ 80 * 2 + 80 * 1, 40 * 5, 100, 20 }, //{ _T("左/右置") },
		{ 80 * 3 + 80 * 2, 40 * 5, 100, 20 }, //{ _T("包装箱/底托规格") }, ,
		{ 80 * 4 + 80 * 3, 40 * 5, 100, 20 }, //{ _T("工号") },
		{ 80 * 1 + 80 * 0, 40 * 6, 100, 20 }, //{ _T("制造商") },
		{ 80 * 2 + 80 * 1, 40 * 6, 100, 20 }, //{ _T("客户区域") },
		{ 0, 0, 0, 0 },						  //{ _T("优先级") },
		{ 80 * 3 + 80 * 2, 40 * 6, 100, 20 }, //{ _T("审核-业务") },
		{ 80 * 4 + 80 * 3, 40 * 6, 100, 20 }, //{ _T("审核-计划") }
};

static int g_ColsMustBeHidden[] =
{
	nsSale::Column_en::yxj,
	nsSale::Column_en::dfr,
	nsSale::Column_en::zc
};

// CTableFilterDlgForSale dialog

IMPLEMENT_DYNAMIC(CTableFilterDlgForSale, CPopupDlg)

CTableFilterDlgForSale::CTableFilterDlgForSale(LPCTSTR title, CWnd* pParent /*=NULL*/)
: CPopupDlg(title, pParent)
{

}

CTableFilterDlgForSale::~CTableFilterDlgForSale()
{
}

bool CTableFilterDlgForSale::Initialize(CJQGridAPI* pJqGridAPI)
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

		for (int i = 0; i < nsSale::end; ++i)
		{
			pobjSettingManager->GetTableFilterSettingForSale(g_TableFilterSettingName[i][0], strValue);

			if (0 != strValue.Compare(IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED))
			{
				m_pJqGridAPI->HideCol(i);
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

BEGIN_MESSAGE_MAP(CTableFilterDlgForSale, CPopupDlg)
	ON_BN_CLICKED(IDC_CHECKBOX_SELECTALL, &CTableFilterDlgForSale::OnBnClickedSelectAll)
END_MESSAGE_MAP()


// CTableFilterDlgForSale message handlers

BOOL CTableFilterDlgForSale::OnInitDialog()
{
	__super::OnInitDialog();
	Util_Tools::Util::SetClientSize(m_hWnd, 837, 480 - 100);
	m_btnOK.MoveWindow(556, 40 * 11 - 20 - 100, 114, 30);
	m_btnCancel.MoveWindow(690, 40 * 11 - 20 - 100, 114, 30);
	CenterWindow();

	m_checkboxSelectAll = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_SELECTALL, _T("全选"), _T("Microsoft YaHei"), 12);
	m_checkboxSelectAll->MoveWindow(80 * 1 + 80 * 0, 40 * 11 - 20 - 100, 100, 20);

	//const std::set<int>& hiddenCols = m_pJqGridAPI->getHiddenCols();

	//init check box according to user setting
	
	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL == pobjSettingManager)
	{
		return FALSE;
	}

	CString strValue;
	int iIgnoreItemForPlan = 0;
	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i] = NULL;
		m_aCheckBoxs[i] = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_BASE + i, g_CheckBoxCaptions[i][0], _T("Microsoft YaHei"), 12);
		m_aCheckBoxs[i]->MoveWindow(g_CheckBoxPos[i][0], g_CheckBoxPos[i][1], g_CheckBoxPos[i][2], g_CheckBoxPos[i][3]);

		pobjSettingManager->GetTableFilterSettingForSale(g_TableFilterSettingName[i][0], strValue);

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

void CTableFilterDlgForSale::SaveColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL != pobjSettingManager)
	{
		for (int i = 0; i < _countof(g_TableFilterSettingName); ++i)
		{
			pobjSettingManager->SetTableFilterSettingForSale(g_TableFilterSettingName[i][0], vecColsStatus[i]);
		}
	}
}

void CTableFilterDlgForSale::GetColsSetting(std::vector<CString>& vecColsStatus)
{
	CString strValue;

	CSettingManager *pobjSettingManager = CSettingManager::GetInstance();
	if (NULL != pobjSettingManager)
	{
		for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
		{
			pobjSettingManager->GetTableFilterSettingForSale(g_TableFilterSettingName[i][0], strValue);

			vecColsStatus.push_back(strValue);
		}
	}
}

void CTableFilterDlgForSale::PostNcDestroy()
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

void CTableFilterDlgForSale::OnOK(){

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

void CTableFilterDlgForSale::OnCancel(){

	__super::OnCancel();
}



void CTableFilterDlgForSale::OnBnClickedSelectAll()
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

bool CTableFilterDlgForSale::IsMustBeHiddenCol(int iColIndex)
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