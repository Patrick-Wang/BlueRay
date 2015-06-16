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
		{ IDS_SETTING_ITEM_TABLEFILTER_GH },
		{ IDS_SETTING_ITEM_TABLEFILTER_ZZS },
		{ IDS_SETTING_ITEM_TABLEFILTER_KHQY },
		{ IDS_SETTING_ITEM_TABLEFILTER_YXJ },
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
		{ _T("��ͬ��") },
		{ _T("�ͻ�����") },
		{ _T("����ͺ�") },
		{ _T("�Ÿ�") },
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
		{ _T("ҵ�����") },
		{ _T("�ƻ����") },
		{ _T("��������") },
		{ _T("�ƻ����-ҵ��") },
		{ _T("�ƻ����-�ƻ�") },
		{ _T("��װ����") },
		{ _T("��װ���-ҵ��") },
		{ _T("��װ���-�ƻ�") },
		{ _T("��������") },
		{ _T("Ͷ�����") },
		{ _T("�������") }

};

static int g_CheckBoxPos[][4] = {
		{ 80 * 1 + 80 * 0, 40 * 1, 100, 20 }, // 		{ _T("��ͬ��") },
		{ 80 * 2 + 80 * 1, 40 * 1, 100, 20 }, // 		{ _T("�ͻ�����") },
		{ 80 * 3 + 80 * 2, 40 * 1, 100, 20 }, // 		{ _T("����ͺ�") },
		{ 80 * 4 + 80 * 3, 40 * 1, 100, 20 }, // 		{ _T("�Ÿ�") },
		{ 80 * 1 + 80 * 0, 40 * 2, 100, 20 }, // 		{ _T("����") },
		{ 80 * 2 + 80 * 1, 40 * 2, 100, 20 }, // 		{ _T("���") },
		{ 0, 0, 0, 0 },							// 		{ _T("������") },
		{ 80 * 3 + 80 * 2, 40 * 2, 100, 20 }, // 		{ _T("�ƶ�����ѹ") },
		{ 80 * 4 + 80 * 3, 40 * 2, 100, 20 }, // 		{ _T("ҷ���ֹ��") },
		{ 80 * 1 + 80 * 0, 40 * 3, 100, 20 }, // 		{ _T("����") },
		{ 80 * 2 + 80 * 1, 40 * 3, 100, 20 }, // 		{ _T("��Ƶ���ͺ�") },
		{ 80 * 3 + 80 * 2, 40 * 3, 100, 20 }, // 		{ _T("�������ͺ�") },
		{ 80 * 4 + 80 * 3, 40 * 3, 100, 20 }, // 		{ _T("���³���") },
		{ 80 * 1 + 80 * 0, 40 * 4, 100, 20 }, // 		{ _T("բ�߳���") },
		{ 80 * 2 + 80 * 1, 40 * 4, 100, 20 }, // 		{ _T("���Ƶ�����") },
		{ 80 * 3 + 80 * 2, 40 * 4, 100, 20 }, // 		{ _T("��ע") },
		{ 80 * 4 + 80 * 3, 40 * 4, 100, 20 }, // 		{ _T("��������") },
		{ 80 * 1 + 80 * 0, 40 * 5, 100, 20 }, // 		{ _T("������ѹ") },
		{ 80 * 2 + 80 * 1, 40 * 5, 100, 20 }, // 		{ _T("������ɫ") },
		{ 80 * 3 + 80 * 2, 40 * 5, 100, 20 }, // 		{ _T("�ƶ����ͺ�") },
		{ 80 * 4 + 80 * 3, 40 * 5, 100, 20 }, // 		{ _T("��/����") },
		{ 80 * 1 + 80 * 0, 40 * 6, 100, 20 }, // 		{ _T("��װ��/���й��") 
		{ 80 * 2 + 80 * 1, 40 * 6, 100, 20 }, // 		{ _T("����") },
		{ 80 * 3 + 80 * 2, 40 * 6, 100, 20 }, // 		{ _T("������") },
		{ 80 * 4 + 80 * 3, 40 * 6, 100, 20 }, // 		{ _T("�ͻ�����") },
		{ 0, 0, 0, 0 },							// 		{ _T("���ȼ�") },
		{ 0, 0, 0, 0 },							// 		{ _T("ҵ�����") },
		{ 0, 0, 0, 0 },							// 		{ _T("�ƻ����") },
		{ 80 * 1 + 80 * 0, 40 * 7, 100, 20 }, // 		{ _T("��������") },
		{ 80 * 2 + 80 * 1, 40 * 7, 100, 20 }, // 		{ _T("�ƻ����-ҵ��") },
		{ 80 * 3 + 80 * 2, 40 * 7, 100, 20 }, // 		{ _T("�ƻ����-�ƻ�") },
		{ 80 * 4 + 80 * 3, 40 * 7, 100, 20 }, // 		{ _T("��װ����") },
		{ 80 * 1 + 80 * 0, 40 * 8, 100, 20 }, // 		{ _T("��װ���-ҵ��") },
		{ 80 * 2 + 80 * 1, 40 * 8, 100, 20 }, // 		{ _T("��װ���-�ƻ�") },
		{ 80 * 3 + 80 * 2, 40 * 8, 100, 20 }, // 		{ _T("��������") },
		{ 80 * 4 + 80 * 3, 40 * 8, 100, 20 }, // 		{ _T("Ͷ�����") },
		{ 80 * 1 + 80 * 0, 40 * 9, 100, 20 }, // 		{ _T("�������") }
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

	m_checkboxSelectAll = Util_Tools::Util::CreateCheckBox(this, IDC_CHECKBOX_SELECTALL, _T("ȫѡ"), _T("Microsoft YaHei"), 12);
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