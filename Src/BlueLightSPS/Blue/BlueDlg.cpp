
// BlueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "Blue.h"
#include "BlueDlg.h"
#include "afxdialogex.h"
#include "resource_ids.h"
#include "Util.h"
#include "PopupDlg.h"
#include "SaleAddDlg.h"
#include "colors.h"
#include "JsHttpImpl.h"
#include "PlanPanel.h"
#include "ProductPanel.h"
#include "NotificationPanel.h"
#include "User.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define TM_TIME_COUNT	10
#define TM_INITUI	11
// CBlueDlg dialog


#define NAVIGATE_WIDTH	150
#define RIGHT_AREA_LEFT	(NAVIGATE_WIDTH + 15)
#define JSFN_ONGETROWNUM 12350


#define GRID_NAME_SALE	_T("sale")
#define GRID_NAME_PLAN	_T("plan")
#define GRID_NAME_PRODUCT	_T("product")
#define GRID_NAME_NOTIFICATION	_T("notification")
#define LAST_GRID	GRID_NAME_NOTIFICATION

CBlueDlg::CBlueDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlueDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBlueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_WEBVIEW, m_webView);
}

BEGIN_MESSAGE_MAP(CBlueDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_MESSAGE_VOID(WM_SALE_UPDATED, CBlueDlg::OnSaleChanged)
	//ON_BN_CLICKED(IDB_SETTINGPAGE, &CBlueDlg::OnBnClickedSetting)
	//ON_BN_CLICKED(IDB_PLANPAGE, &CBlueDlg::OnBnClickedPlan)
	ON_BN_CLICKED(IDC_MIN, &CBlueDlg::OnBnMinmumClicked)
	ON_BN_CLICKED(IDC_CLOSE, &CBlueDlg::OnBnCloseClicked)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



void CBlueDlg::OnBnCloseClicked(){
	SendMessage(WM_CLOSE);
}
void CBlueDlg::OnBnMinmumClicked(){
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CBlueDlg::CreatePageButton(CBRButton& btn, UINT id, int n, LPCTSTR text)
{
	btn.Create(this, id);
	btn.SetTextAlign(DT_VCENTER | DT_SINGLELINE);
	btn.SetWindowText(text);
	btn.SetBSFont(14, FALSE, TRUE);
	btn.EnableBorder(false);
	btn.SetTextColor(enumBSBtnState::BS_NORMAL, COL_BLACK);
	btn.SetTextColor(enumBSBtnState::BS_HOVER, COL_BLACK);
	btn.SetTextColor(enumBSBtnState::BS_CLICK, COL_WHITE);
	btn.SetColorInside(enumBSBtnState::BS_NORMAL, COL_WHITE);
	btn.SetColorInside(enumBSBtnState::BS_HOVER, COL_GRAY);
	btn.SetColorInside(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);
	btn.MoveWindow(CRect(5, 104 + 36 * n, NAVIGATE_WIDTH - 2, 140 + 36 * n));
	m_btnGroup.AddButton(&btn);
}

BOOL CBlueDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CServer::GetInstance()->SetHttp(new CJsHttpImpl(&m_webView, this));
	
	static_cast<IJSMediator*>(&m_webView)->RegisterJsFunction(&m_jsfnOnGetRowNum);
	m_jsfnOnGetRowNum.d_onJsCall += std::make_pair(this, &CBlueDlg::JSCall);
	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);
	Util_Tools::Util::SetWindowSize(m_hWnd, rt.Width(), rt.Height());
	//InitWebView();
	

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
	m_btnMin.SetColorBorder(enumBSBtnState::BS_CLICK, COL_LIGHT_GRAY);
	m_btnMin.SetColorInside(enumBSBtnState::BS_NORMAL, COL_GRAY);
	m_btnMin.SetColorInside(enumBSBtnState::BS_HOVER, COL_WHITE);
	m_btnMin.SetColorInside(enumBSBtnState::BS_CLICK, COL_LIGHT_GRAY);


	//SetWindowPos(NULL, rt.left, rt.top, rt.Width(), rt.Height(), SW_SHOW);

	m_btnGroup.d_onSelected += std::make_pair(this, &CBlueDlg::OnGroupBtnSelected);
	m_btnGroup.d_onUnSelected += std::make_pair(this, &CBlueDlg::OnGroupBtnUnSelected);

	CreatePageButton(m_btnSalePage, IDC_SALEPAGE, 0, _T(" 销售订单"));
	CreatePageButton(m_btnPlanPage, IDC_PLANPAGE, 1, _T(" 计划排产"));
	CreatePageButton(m_btnProductionScanPage, IDC_PRODUCTIONSCANPAGE, 2, _T(" 生产录入"));
	CreatePageButton(m_btnNotification, IDC_NOTIFICATION, 3, _T(" 待办事项"));
	CreatePageButton(m_btnProductionDataAnalyst, IDC_PRODUCTIONDATAANALYST, 4, _T(" 报表展示"));
	CreatePageButton(m_btnSettingPage, IDC_SETTINGPAGE, 5, _T(" 设置"));

	m_bsVersion.Create(this, IDS_SOFTWARE_VERSION);
	m_bsVersion.SetBackgroundColor(COL_GRAY);
	m_bsVersion.SetBSFont(_T("Microsoft YaHei"), 24, FALSE, TRUE);
	m_bsVersion.SetTextAlign(DT_LEFT | DT_SINGLELINE);
	m_bsVersion.SetWindowText(_T("蓝光集团生产管控平台"));
	m_bsVersion.MoveWindow(90, 25, 600 - 122, 62 - 33);

	CRect clientRect;
	GetClientRect(clientRect);
	m_bsDate.Create(this, IDS_DATA_DATE);
	m_bsDate.SetBackgroundColor(COL_GRAY);
	m_bsDate.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsDate.SetTextAlign(DT_VCENTER | DT_SINGLELINE | DT_RIGHT | DT_WORD_ELLIPSIS);
	m_bsDate.MoveWindow(clientRect.right - 210, 31, 200, 20);

	m_bsPersion.Create(this, IDS_PERSION_INFO);
	m_bsPersion.SetBackgroundColor(COL_GRAY);
	m_bsPersion.SetBSFont(_T("Microsoft YaHei"), 12);

	CString userInfo;
	CUser* usr = CUser::GetInstance();
	userInfo.Format(_T("用户名: %s    角色: %s    部门: %s"), usr->GetUserName(), usr->GetRole(), usr->GetDepartment());

	m_bsPersion.SetWindowText(userInfo);
	m_bsPersion.SetTextAlign(DT_VCENTER | DT_SINGLELINE | DT_RIGHT | DT_WORD_ELLIPSIS);
	m_bsPersion.MoveWindow(clientRect.right - 400, 59, 390, 20);

	m_bsIcon.Create(this, IDS_EP_LOGO);
	m_bsIcon.SetBGPictureIDs(BS_NORMAL, IDB_LOGO);
	m_bsIcon.MoveWindow(12, 10, 64, 64);

	m_pLastGrid.reset(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView), LAST_GRID));
	m_pLastGrid->d_OnGridComplete += std::make_pair(this, &CBlueDlg::OnGridDataLoaded);

	CPermission& perm = CUser::GetInstance()->GetPermission();
	if (perm.getSale())
	{
		m_btnGroup.OnClicked(&m_btnSalePage);
	}
	else if (perm.getPlan())
	{
		m_btnGroup.OnClicked(&m_btnPlanPage);
	}
	else
	{
		m_btnGroup.OnClicked(&m_btnNotification);
	}

	SetTimer(TM_TIME_COUNT, 1000, NULL);
	SetTimer(TM_INITUI, 50, NULL);
	OnTimer(TM_TIME_COUNT);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CBlueDlg::OnGridDataLoaded()
{
	m_pLastGrid->d_OnGridComplete -= std::make_pair(this, &CBlueDlg::OnGridDataLoaded);
	CRect clientRect;
	GetClientRect(clientRect);
	CRect rtCtrlPanel(RIGHT_AREA_LEFT, 102, clientRect.Width() - 10, 218);
	m_pPanelMap[IDC_SALEPAGE].reset(new CSalePanel(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView), GRID_NAME_SALE)));
	m_pPanelMap[IDC_SALEPAGE]->Create(this, IDP_SALE);
	m_pPanelMap[IDC_SALEPAGE]->SetWindowPos(NULL, rtCtrlPanel.left, rtCtrlPanel.top, rtCtrlPanel.Width(), rtCtrlPanel.Height(), SWP_HIDEWINDOW);
	
	m_pPanelMap[IDC_PLANPAGE].reset(new CPlanPanel(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView), GRID_NAME_PLAN)));
	m_pPanelMap[IDC_PLANPAGE]->Create(this, IDP_PLAN);
	m_pPanelMap[IDC_PLANPAGE]->SetWindowPos(NULL, rtCtrlPanel.left, rtCtrlPanel.top, rtCtrlPanel.Width(), rtCtrlPanel.Height(), SWP_HIDEWINDOW);

	m_pPanelMap[IDC_PRODUCTIONSCANPAGE].reset(new CProductPanel(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView), GRID_NAME_PRODUCT)));
	m_pPanelMap[IDC_PRODUCTIONSCANPAGE]->Create(this, IDP_PRODUCT);
	m_pPanelMap[IDC_PRODUCTIONSCANPAGE]->SetWindowPos(NULL, rtCtrlPanel.left, rtCtrlPanel.top, rtCtrlPanel.Width(), rtCtrlPanel.Height(), SWP_HIDEWINDOW);

	m_pPanelMap[IDC_NOTIFICATION].reset(new CNotificationPanel(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView), GRID_NAME_NOTIFICATION)));
	m_pPanelMap[IDC_NOTIFICATION]->Create(this, IDP_NOTIFICATION);
	m_pPanelMap[IDC_NOTIFICATION]->SetWindowPos(NULL, rtCtrlPanel.left, rtCtrlPanel.top, rtCtrlPanel.Width(), rtCtrlPanel.Height(), SWP_HIDEWINDOW);

	CPermission& perm = CUser::GetInstance()->GetPermission();
	if (perm.getSale())
	{
		m_pPanelMap[IDC_SALEPAGE]->ShowWindow(SW_SHOW);
	}
	else if (perm.getPlan())
	{
		m_pPanelMap[IDC_PLANPAGE]->ShowWindow(SW_SHOW);
	}
	else
	{
		m_pPanelMap[IDC_NOTIFICATION]->ShowWindow(SW_SHOW);
	}

	m_pLastGrid.release();
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBlueDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}



}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBlueDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//
//void CBlueDlg::OnBnClickedSetting()
//{
//
//}


BOOL CBlueDlg::OnEraseBkgnd(CDC* pDC)
{

	// TODO: Add your message handler code here and/or call default
	BOOL ret = __super::OnEraseBkgnd(pDC);
	CRect rtClient;
	GetClientRect(rtClient);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 84, rtClient.Width(), rtClient.Height()), COL_WHITE);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, rtClient.Width(), 84), COL_GRAY);
	CBSObject::DrawRect(pDC->m_hDC, CRect(RIGHT_AREA_LEFT, 102, rtClient.Width() - 10, 218), COL_BLACK, 2);
	CBSObject::DrawRect(pDC->m_hDC, CRect(3, 102, NAVIGATE_WIDTH, rtClient.Height() - 10), COL_GRAY, 2);
	CBSObject::DrawLine(pDC->m_hDC, CPoint(-1, 84), CPoint(rtClient.Width(), 84), COL_BLACK, 2);
	return ret;
}


int CBlueDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}


BOOL CBlueDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	if (nCode == BN_CLICKED)
	{
		m_btnGroup.OnClicked(static_cast<CBRButton*>(GetDlgItem(nID)));
	}
	return CDialogEx::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CBlueDlg::OnGroupBtnSelected(CBRButton* pBrbtn)
{
	if (NULL != pBrbtn)
	{
		pBrbtn->SetColorInside(enumBSBtnState::BS_NORMAL, COL_LIGHT_GRAY);
		CString text;
		pBrbtn->GetWindowText(text);
		pBrbtn->SetWindowText(text + _T(">>"));
		if (m_pPanelMap.find(pBrbtn->GetDlgCtrlID()) != m_pPanelMap.end())
		{
			m_pPanelMap[pBrbtn->GetDlgCtrlID()]->ShowWindow(SW_SHOW);
			m_pPanelMap[pBrbtn->GetDlgCtrlID()]->HasUpdate();
		}
	}
}

void CBlueDlg::OnGroupBtnUnSelected(CBRButton* pBrbtn)
{
	if (NULL != pBrbtn)
	{
		pBrbtn->SetColorInside(enumBSBtnState::BS_NORMAL, COL_WHITE);
		CString text;
		pBrbtn->GetWindowText(text);
		text.Replace(_T(">>"), _T(""));
		pBrbtn->SetWindowText(text);
		if (m_pPanelMap.find(pBrbtn->GetDlgCtrlID()) != m_pPanelMap.end())
		{
			m_pPanelMap[pBrbtn->GetDlgCtrlID()]->ShowWindow(SW_HIDE);
		}
	}
}


void CBlueDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TM_TIME_COUNT == nIDEvent)
	{
		CTime now = CTime::GetCurrentTime();
		CString time = now.Format(_T("%Y/%m/%d %X"));

		m_bsDate.SetWindowText(_T("当前时间: ") + time);
	}
	else if (TM_INITUI == nIDEvent){
		KillTimer(nIDEvent);
		InitWebView();
	}
	else
	{
		CDialogEx::OnTimer(nIDEvent);
	}
}


BOOL CBlueDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CBlueDlg::OnWebComplete()
{

	//m_pHttp->Post(_T("http://www.baidu.com"), std::map<CString, CString>(), _T("asdf"));
}

//void CBlueDlg::OnBnClickedPlan()
//{
//
//}

void CBlueDlg::InitWebView()
{
	CRect rt;
	GetClientRect(rt);
	rt.left = RIGHT_AREA_LEFT;
	rt.top = 237;
	rt.right -= 10;
	rt.bottom -= 10;


	int rowHeight = rt.Height() - 28 - 23 - 19;
	int rowNumber = rowHeight / 23;
	rt.top += rowHeight - rowNumber * 23;
	
	CJQGridAPI::SetPageSize(rowNumber);

	m_webView.Create(NULL, NULL, WS_CHILD, rt, this, 10000, NULL);
	m_webView.ShowWindow(SW_SHOW);
	m_webView.d_OnDomComplete += std::make_pair(this, &CBlueDlg::OnWebComplete);
	CString path;
	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
	path.ReleaseBuffer();
#ifdef _DEBUG
	path.Replace(_T("Debug\\BlueLightPLM.exe"), _T("BlueTable\\tables.html"));
#else
	path.Replace(_T("BlueLightPLM.exe"), _T("tables.html"));
#endif
	VARIANT url;
	url.vt = VT_BSTR;
	url.bstrVal = (BSTR)::SysAllocString(path);
	m_webView.OpenURL(&url);
}

void CBlueDlg::OnSaleChanged()
{
	m_pPanelMap[IDC_PLANPAGE]->HasUpdate();
}

VARIANT CBlueDlg::JSCall(int id, const std::vector<VARIANT>& params)
{
	VARIANT vt;
	vt.vt = VT_I4;
	if ((int)&m_jsfnOnGetRowNum == id)
	{
		vt.intVal = CJQGridAPI::GetPageSize();
	}
	return vt;
}

CComJsFun CBlueDlg::m_jsfnOnGetRowNum(_T("onGetRowNum"));

