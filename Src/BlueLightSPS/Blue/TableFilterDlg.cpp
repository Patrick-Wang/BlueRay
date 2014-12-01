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
		{ _T("���-ҵ��") },
		{ _T("���-�ƻ�") },
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

IMPLEMENT_DYNAMIC(CTableFilterDlg, CDialogEx)

CTableFilterDlg::CTableFilterDlg(LPCTSTR title, CJQGridAPI* pJqGridAPI, PageIDEnum pageID, CWnd* pParent /*=NULL*/)
	: CDialogEx(CTableFilterDlg::IDD, pParent)
	, m_enumPage(pageID)
	, m_Title(title)
	, m_pJqGridAPI(pJqGridAPI)
{

}

CTableFilterDlg::~CTableFilterDlg()
{
}

void CTableFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CTableFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTableFilterDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTableFilterDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTableFilterDlg message handlers

BOOL CTableFilterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	Util::SetClientSize(m_hWnd, 837, 421);
	SetWindowText(m_Title);

	m_btnOK.MoveWindow(556, 366, 114, 30);
	m_btnOK.SetWindowText(_T("ȷ��"));

	m_btnCancel.MoveWindow(690, 366, 114, 30);
	m_btnCancel.SetWindowText(_T("ȡ��"));
	
	CenterWindow();

	//init check box according to user setting
	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i] = Util::CreateCheckBox(this, IDC_CHECKBOX_BASE + i, g_CheckBoxCaptions[i][0], _T("Microsoft YaHei"), 12);
		m_aCheckBoxs[i]->MoveWindow(g_CheckBoxPos[i][0], g_CheckBoxPos[i][1], g_CheckBoxPos[i][2], g_CheckBoxPos[i][3]);

		m_aCheckBoxs[i]->SetCheck(TRUE);

		//if ( setting false )
		//{
		//	m_aCheckBoxs[i]->ShowWindow(FALSE);
		//}

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

void CTableFilterDlg::OnBnClickedOk()
{
	//save user settings

	//update table

	for (int i = 0; i < _countof(m_aCheckBoxs); ++i)
	{
		if (!m_aCheckBoxs[i]->GetCheck())
		{
			m_pJqGridAPI->HideCol(i);
		}
		else
		{
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

	CDialogEx::OnOK();
}


void CTableFilterDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
