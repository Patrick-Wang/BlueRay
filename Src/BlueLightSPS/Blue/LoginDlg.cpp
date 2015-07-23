// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "resource_ids.h"
#include "Util.h"
#include "colors.h"
#include "JsHttpImpl.h"
#include "CommonDefine.h"
#include "Account.h"
#include "Association.h"
#include "Server.h"
#include "SettingManager.h"
// CLoginDlg dialog

#define TM_INITUI	100

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

void CLoginDlg::OnNcDestroy()
{
	if (NULL != m_combUserName)
	{
		delete m_combUserName;
		m_combUserName = NULL;
	}

	__super::OnNcDestroy();
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
	ON_BN_CLICKED(IDC_MIN, &CLoginDlg::OnBnMinmumClicked)
	ON_BN_CLICKED(IDC_CLOSE, &CLoginDlg::OnBnCloseClicked)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
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
	CServer::GetInstance()->SetHttp(new CJsHttpImpl(&m_webHttpView));

	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);   // 获得工作区大小
	MoveWindow(rt.left, rt.top, rt.Width(), rt.Height());
	//SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	//Util::SetWindowSize(m_hWnd, 1024, 728);
	//m_btnVPN.Create(this, IDC_VPN); 
	//m_btnVPN.SetWindowText(_T("VPN/代理 设置 >>"));
	//m_btnVPN.MoveWindow(695, 452, 130, 24);
	//m_btnVPN.SetBackgroundColor(COL_GRAY);

	this->SetWindowTextW(_T("蓝光集团生产管控平台"));

	m_btnClose.Create(this, IDC_CLOSE);
	m_btnClose.SetWindowText(_T("×"));
	m_btnClose.MoveWindow(rt.Width() - 37, 0, 35, 25);
	m_btnClose.SetBackgroundColor(COL_GRAY);
	m_btnClose.SetBSFont(22, FALSE, TRUE);
	m_btnClose.SetColorBorder(enumBSBtnState::BS_NORMAL, COL_GRAY);
	m_btnClose.SetColorBorder(enumBSBtnState::BS_HOVER, COL_WHITE);
	m_btnClose.SetColorBorder(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);
	m_btnClose.SetColorInside(enumBSBtnState::BS_NORMAL, COL_GRAY);
	m_btnClose.SetColorInside(enumBSBtnState::BS_HOVER, COL_WHITE);
	m_btnClose.SetColorInside(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);

	m_btnMin.Create(this, IDC_MIN);
	m_btnMin.SetWindowText(_T("-"));
	m_btnMin.SetBSFont(30, FALSE, TRUE);
	m_btnMin.MoveWindow(rt.Width() - 72, 0, 35, 25);
	m_btnMin.SetBackgroundColor(COL_GRAY);
	m_btnMin.SetColorBorder(enumBSBtnState::BS_NORMAL, COL_GRAY);
	m_btnMin.SetColorBorder(enumBSBtnState::BS_HOVER, COL_WHITE);
	m_btnMin.SetColorBorder(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);
	m_btnMin.SetColorInside(enumBSBtnState::BS_NORMAL, COL_GRAY);
	m_btnMin.SetColorInside(enumBSBtnState::BS_HOVER, COL_WHITE);
	m_btnMin.SetColorInside(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);

// 	m_btnForgetPassword.Create(this, IDC_FORGET_PSW);
// 	m_btnForgetPassword.SetWindowText(_T("忘记密码 >>"));
// 	m_btnForgetPassword.MoveWindow(667, 440, 130, 24);
// 	m_btnForgetPassword.SetBackgroundColor(COL_GRAY);

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

	m_bsCopyright.Create(this, IDC_LOGIN_COPYRIGHT);
	m_bsCopyright.SetTextColor(COL_BLACK);
	CString strCopyright(_T("2015 @ 蓝光集团 .  All rights reserved.\r\n \r\n build number: "));
	m_bsCopyright.SetWindowText(strCopyright+IDS_VERSION_NUMBER);
	m_bsCopyright.SetBSFont(_T("Microsoft YaHei"), 12, FALSE, TRUE);
	m_bsCopyright.SetTextAlign(DT_CENTER | DT_SINGLELINE);
	m_bsCopyright.MoveWindow(rt.Width()/2 - 150, rt.Height() - 70, 300, 70);

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
	m_editUserName.MoveWindow(0, 0, 0, 0);
	m_combUserName = Util_Tools::Util::CreateComboBox(this, IDC_LOGIN_COMB_USERNAME, _T("Microsoft YaHei"), 12, FALSE);
	m_combUserName->MoveWindow(696, 362, 181, 18);
	m_combUserName->SetCurSel(0);

	CString rootFolder;
	Util_Tools::Util::GetExpandPath(IDS_SETTING_LOCATION, rootFolder);
	vector<CString> vecFolderNames;
	vecFolderNames.clear();
	Util_Tools::Util::FindSubFolders(rootFolder, vecFolderNames);

	CString strLastUser;
	int iCulSel = 0;
	bool bGetUser = Util_Tools::Util::GetLatestLogonUser(strLastUser);

	for (int i = 0; i < vecFolderNames.size(); i++)
	{
		if (bGetUser)
		{
			if (0 == strLastUser.CompareNoCase(vecFolderNames[i]))
			{
				iCulSel = i;
			}
		}
		m_combUserName->InsertString(i, vecFolderNames[i]);
	}

	m_combUserName->SetCurSel(iCulSel);

	SetTimer(TM_INITUI, 500, NULL);
	
//	CString path;
//	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
//	path.ReleaseBuffer();
//
//#ifndef _DEBUG
//	path.Replace(_T("BlueLightPLM.exe"), _T("test.txt"));
//	if (!PathFileExists(path))
//	{
//		g_strHostName = _T("192.168.104.253");
//	}
//#endif
	CAssociation* asso = CAssociation::GetInstance();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
void CLoginDlg::OnBnCloseClicked(){
	SendMessage(WM_CLOSE);
}
void CLoginDlg::OnBnMinmumClicked(){
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}
void CLoginDlg::OnBnClickedLogin()
{
	CString psw;
	m_editPsw.GetWindowText(psw);
	CString usrName;
	//m_editUserName.GetWindowText(usrName);
	m_combUserName->GetWindowTextW(usrName);

	class OnLoginListener : public CPromise<CUser*>::IHttpResponse{
		CONSTRUCTOR_1(OnLoginListener, CLoginDlg*, loginDlg)
	public:
		void OnSuccess(CUser*& usr)
		{
			if (NULL != usr)
			{
				Util_Tools::Util::SetLatestLogonUser(CUser::GetInstance()->GetUserName());
				m_loginDlg->OnOK();
			}
			else
			{
				m_loginDlg->MessageBox(_T("用户名或密码错误，请重新输入！"), _T("警告"), MB_OK | MB_ICONWARNING);
				m_loginDlg->EnableWindow(TRUE);
			}
		}
		void OnFailed()
		{
			m_loginDlg->MessageBox(_T("网络连接失败，请检查网络配置！"), _T("警告"), MB_OK | MB_ICONWARNING);
			m_loginDlg->EnableWindow(TRUE);
		}
	};

	CServer::GetInstance()->GetAccount().Login(usrName, psw)
		.then(new OnLoginListener(this));
	EnableWindow(FALSE);
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

void CLoginDlg::InitWebView()
{
	m_webHttpView.Create(NULL, NULL, WS_CHILD, CRect(0, 0, 0, 0), this, 10000, NULL);
	CString path;
	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
	path.ReleaseBuffer();
#ifdef _DEBUG
	path.Replace(_T("Debug\\BlueLightPLM.exe"), _T("BlueTable\\http.html"));
#else
	path.Replace(_T("BlueLightPLM.exe"), _T("http.html"));
#endif
	VARIANT url;
	url.vt = VT_BSTR;
	url.bstrVal = (BSTR)::SysAllocString(path);
	m_webHttpView.OpenURL(&url);
}



void CLoginDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TM_INITUI == nIDEvent)
	{
		KillTimer(TM_INITUI);
		InitWebView();
	}

	CDialogEx::OnTimer(nIDEvent);
}
