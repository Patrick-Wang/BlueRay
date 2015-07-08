// SecretDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "SecretDlg.h"
#include "afxdialogex.h"
#include "BSObject.h"
#include "colors.h"
// CSecretDlg dialog

IMPLEMENT_DYNAMIC(CSecretDlg, CDialogEx)

CSecretDlg::CSecretDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecretDlg::IDD, pParent)
{

}

CSecretDlg::~CSecretDlg()
{
}

void CSecretDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SECRET, m_editSecret);
}


BEGIN_MESSAGE_MAP(CSecretDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSecretDlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CSecretDlg message handlers


void CSecretDlg::OnBnClickedOk()
{
	m_editSecret.GetWindowText(m_strPsw);
	CDialogEx::OnOK();
}


BOOL CSecretDlg::OnEraseBkgnd(CDC* pDC)
{
	BOOL ret = __super::OnEraseBkgnd(pDC);
	CRect rtClient;
	GetClientRect(rtClient);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, rtClient.Width(), 93), COL_WHITE);
	//CBSObject::FillRect(pDC->m_hDC, CRect(0, 93, rtClient.Width(), rtClient.Height()), COL_GRAY);
	//CBSObject::DrawText(pDC->m_hDC, CRect(0, 0, rtClient.Width(), 93), CString(L"«Î ‰»Î√‹¬Î"));
	return ret;
}


BOOL CSecretDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_bsPsw.Create(this, 556287);
	m_bsPsw.SetWindowText(L"«Î ‰»Î√‹¬Î:");
	m_bsPsw.SetBackgroundColor(COL_WHITE);
	m_bsPsw.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPsw.MoveWindow(30, 38, 90, 18);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
