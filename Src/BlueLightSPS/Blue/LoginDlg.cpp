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
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	ON_BN_CLICKED(IDC_LOGIN, &CLoginDlg::OnBnClickedLogin)
	ON_WM_KEYDOWN()
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
	CRect rt;
	GetClientRect(rt);
	CBSObject::FillRect(pDC->m_hDC, rt, COL_GRAY);
	return bRet;
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);   // 获得工作区大小
	MoveWindow(rt.left, rt.top, rt.Width(), rt.Height());
	//SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	//Util::SetWindowSize(m_hWnd, 1024, 728);
	m_btnVPN.Create(this, IDC_VPN); 
	m_btnVPN.SetWindowText(_T("VPN/代理 设置 >>"));
	m_btnVPN.MoveWindow(695, 452, 130, 24);
	m_btnVPN.SetBackgroundColor(COL_GRAY);

	m_btnForgetPassword.Create(this, IDC_FORGET_PSW);
	m_btnForgetPassword.SetWindowText(_T("忘记密码 >>"));
	m_btnForgetPassword.MoveWindow(835, 452, 130, 24);
	m_btnForgetPassword.SetBackgroundColor(COL_GRAY);

	m_btnLogin.Create(this, IDC_LOGIN);
	m_btnLogin.SetWindowText(_T("登陆"));
	m_btnLogin.SetBSFont(12, FALSE, TRUE);
	m_btnLogin.MoveWindow(893, 362, 80, 63);


	m_bsVersion.Create(this, IDC_LOGIN_VERSION);
	m_bsVersion.SetTextColor(COL_BLACK);
	m_bsVersion.SetWindowText(_T("蓝光集团生产管控平台"));
	m_bsVersion.SetBSFont(_T("Microsoft YaHei"), 32, FALSE, TRUE);
	m_bsVersion.SetTextAlign(DT_LEFT | DT_SINGLELINE);
	m_bsVersion.MoveWindow(300, 180, 450, 45);


	m_bsUserName.Create(this, IDC_LOGIN_USERNAME);
	m_bsUserName.SetTextColor(COL_BLACK);
	m_bsUserName.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsUserName.MoveWindow(613, 361, 82, 24);
	m_bsUserName.SetWindowText(_T("用户名"));


	m_bsPassword.Create(this, IDC_LOGIN_PSW);
	m_bsPassword.SetTextColor(COL_BLACK);
	m_bsPassword.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPassword.MoveWindow(613, 404, 82, 24);
	m_bsPassword.SetWindowText(_T("密码"));

	m_bsLogo.Create(this, IDC_LOGIN_LOGO);
	m_bsLogo.SetBGPictureID(IDB_LOGO);
	m_bsLogo.MoveWindow(90,120, 180, 180);

	m_editPsw.MoveWindow(696, 405, 181, 20);
	m_editUserName.MoveWindow(696, 362, 181, 20);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnBnClickedLogin()
{
	CString psw;
	m_editPsw.GetWindowText(psw);
	CString usrName;
	m_editUserName.GetWindowText(usrName);
	if (usrName.CompareNoCase(_T("admin")) == 0 && psw.CompareNoCase(_T("123456")) == 0)
	{
		OnOK();
	}
	else
	{
		MessageBox(_T("用户名或密码错误，请重新输入！"), _T("警告"), MB_OK | MB_ICONWARNING);
	}
	
}


void CLoginDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if (VK_RETURN == nChar)
	//{
	//	OnBnClickedLogin();
	//}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CLoginDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && pMsg->wParam == VK_RETURN)
	{
		OnBnClickedLogin();
		return FALSE;
	}
	else
	{
		return CDialogEx::PreTranslateMessage(pMsg);
	}
	
}
