// TableFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
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
		{ _T("��������") },
		{ _T("��ע") },

		{ _T("��������") },
		{ _T("��װ����") },
		{ _T("��������") },
		{ _T("Ͷ�����") },
		{ _T("�������") }

};

static int g_CheckBoxPos[][4] = {
		{ 80 * 1 + 65 * 0, 40 * 1, 65, 20 }, //Static_HTH,
		{ 80 * 2 + 65 * 1, 40 * 1, 65, 20 }, //Static_KHMC,
		{ 80 * 3 + 65 * 2, 40 * 1, 65, 20 }, //Static_GGBH,
		{ 80 * 4 + 65 * 3, 40 * 1, 65, 20 }, //Static_SL,
		{ 80 * 1 + 65 * 0, 40 * 2, 65, 20 }, //Static_ZC,
		{ 80 * 2 + 65 * 1, 40 * 2, 65, 20 }, //Static_DFR,
		{ 80 * 3 + 65 * 2, 40 * 2, 65, 20 }, //Static_ZDQDY,
		{ 80 * 4 + 65 * 3, 40 * 2, 65, 20 }, //Static_YYLGG,
		{ 80 * 1 + 65 * 0, 40 * 3, 65, 20 }, //Static_JF,
		{ 80 * 2 + 65 * 1, 40 * 3, 65, 20 }, //Static_BPQXH,
		{ 80 * 3 + 65 * 2, 40 * 3, 65, 20 }, //Static_BMQXH,
		{ 80 * 4 + 65 * 3, 40 * 3, 65, 20 }, //Static_DLCD,
		{ 80 * 1 + 65 * 0, 40 * 4, 65, 20 }, //Static_ZXCD,
		{ 80 * 2 + 65 * 1, 40 * 4, 65, 20 }, //Static_MPZL,
		{ 80 * 3 + 65 * 2, 40 * 4, 65, 20 }, //Static_DDRQ,
		{ 80 * 4 + 65 * 3, 40 * 4, 65, 20 },  //Static_BZ,
		{ 80 * 1 + 65 * 0, 40 * 5, 65, 20 },  //Static_SCRQ,
		{ 80 * 2 + 65 * 1, 40 * 5, 65, 20 },  //Static_BZRQ,
		{ 80 * 3 + 65 * 2, 40 * 5, 65, 20 },  //Static_FHRQ,
		{ 80 * 1 + 65 * 0, 40 * 6, 65, 20 },  //Static_TCBH,
		{ 80 * 2 + 65 * 1, 40 * 6, 65, 20 }   //Static_CCBH
};

// CTableFilterDlg dialog

IMPLEMENT_DYNAMIC(CTableFilterDlg, CDialogEx)

CTableFilterDlg::CTableFilterDlg(LPCTSTR title, CWnd* pParent /*=NULL*/)
	: CDialogEx(CTableFilterDlg::IDD, pParent)
	, m_enumPage(Page_Sale)
	, m_Title(title)
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

void CTableFilterDlg::InitPageOwner(PageIDEnum iPageID)
{
	m_enumPage = iPageID;
}

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

	//init checkbox
	for (int i = 0; i < _countof(g_CheckBoxPos); ++i)
	{
		m_aCheckBoxs[i] = Util::CreateCheckBox(this, IDC_CHECKBOX_BASE + i, g_CheckBoxCaptions[i][0], _T("Microsoft YaHei"), 12);
		m_aCheckBoxs[i]->MoveWindow(g_CheckBoxPos[i][0], g_CheckBoxPos[i][1], g_CheckBoxPos[i][2], g_CheckBoxPos[i][3]);
	}

	//init checkbox status according to the user setting

	m_aCheckBoxs[CheckBox_HTH]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_KHMC]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_GGBH]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_SL]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_ZC]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_DFR]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_ZDQDY]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_YYLGG]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_JF]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_BPQXH]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_BMQXH]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_DLCD]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_ZXCD]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_MPZL]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_DDRQ]->SetCheck(TRUE);
	m_aCheckBoxs[CheckBox_BZ]->SetCheck(TRUE);

	if (Page_Plan == m_enumPage)
	{
		m_aCheckBoxs[CheckBox_SCRQ]->SetCheck(TRUE);
		m_aCheckBoxs[CheckBox_BZRQ]->SetCheck(TRUE);
		m_aCheckBoxs[CheckBox_FHRQ]->SetCheck(TRUE);
		m_aCheckBoxs[CheckBox_TCBH]->SetCheck(TRUE);
		m_aCheckBoxs[CheckBox_CCBH]->SetCheck(TRUE);
	}
	else
	{
		m_aCheckBoxs[CheckBox_SCRQ]->SetCheck(FALSE);
		m_aCheckBoxs[CheckBox_BZRQ]->SetCheck(FALSE);
		m_aCheckBoxs[CheckBox_FHRQ]->SetCheck(FALSE);
		m_aCheckBoxs[CheckBox_TCBH]->SetCheck(FALSE);
		m_aCheckBoxs[CheckBox_CCBH]->SetCheck(FALSE);

		m_aCheckBoxs[CheckBox_SCRQ]->ShowWindow(FALSE);
		m_aCheckBoxs[CheckBox_BZRQ]->ShowWindow(FALSE);
		m_aCheckBoxs[CheckBox_FHRQ]->ShowWindow(FALSE);
		m_aCheckBoxs[CheckBox_TCBH]->ShowWindow(FALSE);
		m_aCheckBoxs[CheckBox_CCBH]->ShowWindow(FALSE);
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

	CDialogEx::OnOK();
}


void CTableFilterDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
