// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "resource_ids.h"
#include "Util.h"
#include "colors.h"
// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CLoginDlg::IDD, pParent)
, m_btnVPN(TRUE)
, m_btnForgetPassword(TRUE)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editUserName);
	DDX_Control(pDX, IDC_EDIT_PSW, m_editPsw);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDB_LOGIN, &CLoginDlg::OnBnClickedLogin)
END_MESSAGE_MAP()


// CLoginDlg message handlers


int CLoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


BOOL CLoginDlg::OnEraseBkgnd(CDC* pDC)
{
	BOOL bRet = CDialogEx::OnEraseBkgnd(pDC);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 1024, 728), COL_GRAY);
	return bRet;
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Util::SetWindowSize(m_hWnd, 1024, 728);
	m_btnVPN.Create(this, IDB_VPN); 
	m_btnVPN.SetWindowText(_T("VPN/proxy setting >>"));
	m_btnVPN.MoveWindow(695, 452, 130, 24);
	m_btnVPN.SetBackgroundColor(COL_GRAY);

	m_btnForgetPassword.Create(this, IDB_FORGET_PSW);
	m_btnForgetPassword.SetWindowText(_T("Forgot password >>"));
	m_btnForgetPassword.MoveWindow(835, 452, 130, 24);
	m_btnForgetPassword.SetBackgroundColor(COL_GRAY);

	m_btnLogin.Create(this, IDB_LOGIN);
	m_btnLogin.SetWindowText(_T("Login"));
	m_btnLogin.SetBSFont(12, FALSE, TRUE);
	m_btnLogin.MoveWindow(893, 361, 97, 67);


	m_bsVersion.Create(this, IDB_LOGIN_VERSION);
	m_bsVersion.SetTextColor(COL_BLACK);
	m_bsVersion.SetWindowText(_T("Management System V1.0"));
	m_bsVersion.SetBSFont(_T("Segoe UI"), 16, FALSE, TRUE);
	m_bsVersion.MoveWindow(296, 173, 285, 45);


	m_bsUserName.Create(this, IDB_LOGIN_USERNAME);
	m_bsUserName.SetTextColor(COL_BLACK);
	m_bsUserName.SetBSFont(_T("Segoe UI"), 12);
	m_bsUserName.MoveWindow(613, 361, 82, 24);
	m_bsUserName.SetWindowText(_T("User name"));


	m_bsPassword.Create(this, IDB_LOGIN_PSW);
	m_bsPassword.SetTextColor(COL_BLACK);
	m_bsPassword.SetBSFont(_T("Segoe UI"), 12);
	m_bsPassword.MoveWindow(613, 404, 82, 24);
	m_bsPassword.SetWindowText(_T("Password"));

	m_bsLogo.Create(this, IDB_LOGIN_LOGO);
	m_bsLogo.SetBGPictureID(IDB_PNG4);
	m_bsLogo.MoveWindow(91,101, 171, 164);

	m_editPsw.MoveWindow(696, 362, 181, 26);
	m_editUserName.MoveWindow(696, 405, 181, 26);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnBnClickedLogin()
{
	OnOK();
}
