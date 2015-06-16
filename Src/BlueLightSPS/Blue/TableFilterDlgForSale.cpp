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
		{ _T("��ͬ��") },
		{ _T("�ͻ�����") },
		{ _T("����ͺ�") },
		{ _T("����") },
		{ _T("���") },
		{ _T("������") },
		{ _T("�ƶ�����ѹ") },
		{ _T("ҷ���ֹ��") },
		{ _T("����") },
		{ _T("��Ƶ���ͺ�") },
		{ _T("�������ͺ�") },
		{ _T("���³���") },
		{ _T("բ�߳���") },
		{ _T("���Ƶ�����") },
		{ _T("��ע") },
		{ _T("��������") },
		{ _T("������ѹ") },
		{ _T("������ɫ") },
		{ _T("�ƶ����ͺ�") },
		{ _T("��/����") },
		{ _T("��װ��/���й��") },
		{ _T("����") },
		{ _T("������") },
		{ _T("�ͻ�����") },
		{ _T("���ȼ�") },
		{ _T("���-ҵ��") },
		{ _T("���-�ƻ�") }

};

static int g_CheckBoxPos[][4] = {
		{ 80 * 1 + 80 * 0, 40 * 1, 100, 20 }, //{ _T("��ͬ��") },
		{ 80 * 2 + 80 * 1, 40 * 1, 100, 20 }, //{ _T("�ͻ�����") },
		{ 80 * 3 + 80 * 2, 40 * 1, 100, 20 }, //{ _T("����ͺ�") },
		{ 80 * 4 + 80 * 3, 40 * 1, 100, 20 }, //{ _T("����") },
		{ 0, 0, 0, 0 },						  //{ _T("���") },
		{ 0, 0, 0, 0 },						  //{ _T("������") },
		{ 80 * 1 + 80 * 0, 40 * 2, 100, 20 }, //{ _T("�ƶ�����ѹ") },
		{ 80 * 2 + 80 * 1, 40 * 2, 100, 20 }, //{ _T("ҷ���ֹ��") },
		{ 80 * 3 + 80 * 2, 40 * 2, 100, 20 }, //{ _T("����") },
		{ 80 * 4 + 80 * 3, 40 * 2, 100, 20 }, //{ _T("��Ƶ���ͺ�") },
		{ 80 * 1 + 80 * 0, 40 * 3, 100, 20 }, //{ _T("�������ͺ�") },
		{ 80 * 2 + 80 * 1, 40 * 3, 100, 20 }, //{ _T("���³���") },
		{ 80 * 3 + 80 * 2, 40 * 3, 100, 20 }, //{ _T("բ�߳���") },
		{ 80 * 4 + 80 * 3, 40 * 3, 100, 20 }, //{ _T("���Ƶ�����") },
		{ 80 * 1 + 80 * 0, 40 * 4, 100, 20 }, //{ _T("��ע") },
		{ 80 * 2 + 80 * 1, 40 * 4, 100, 20 }, //{ _T("��������") },
		{ 80 * 3 + 80 * 2, 40 * 4, 100, 20 }, //{ _T("������ѹ") },
		{ 80 * 4 + 80 * 3, 40 * 4, 100, 20 }, //{ _T("������ɫ") },
		{ 80 * 1 + 80 * 0, 40 * 5, 100, 20 }, //{ _T("�ƶ����ͺ�") },
		{ 80 * 2 + 80 * 1, 40 * 5, 100, 20 }, //{ _T("��/����") },
		{ 80 * 3 + 80 * 2, 40 * 5, 100, 20 }, //{ _T("��װ��/���й��") }, ,
		{ 80 * 4 + 80 * 3, 40 * 5, 100, 20 }, //{ _T("����") },
		{ 80 * 1 + 80 * 0, 40 * 6, 100, 20 }, //{ _T("������") },
		{ 80 * 2 + 80 * 1, 40 * 6, 100, 20 }, //{ _T("�ͻ�����") },
		{ 0, 0, 0, 0 },						  //{ _T("���ȼ�") },
		{ 80 * 3 + 80 * 2, 40 * 6, 100, 20 }, //{ _T("���-ҵ��") },
		{ 80 * 4 + 80 * 3, 40 * 6, 100, 20 }, //{ _T("���-�ƻ�") }
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

	m_checkboxSelectAll = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_SELECTALL, _T("ȫѡ"), _T("Microsoft YaHei"), 12);
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