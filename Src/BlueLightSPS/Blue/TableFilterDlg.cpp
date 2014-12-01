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
		{ _T("订单日期") },
		{ _T("备注") },

		{ _T("生产日期") },
		{ _T("包装日期") },
		{ _T("发货日期") },
		{ _T("投产编号") },
		{ _T("出厂编号") }

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
	m_btnOK.SetWindowText(_T("确定"));

	m_btnCancel.MoveWindow(690, 366, 114, 30);
	m_btnCancel.SetWindowText(_T("取消"));
	
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
