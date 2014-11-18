
// BlueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "BlueDlg.h"
#include "afxdialogex.h"
#include "resource_ids.h"
#include "Util.h"
#include "AddDlg.h"
#include "SaleAddDlg.h"
#include "colors.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBlueDlg dialog




CBlueDlg::CBlueDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlueDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CBlueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_WEBVIEW, m_webView);
	DDX_Control(pDX, IDC_EDIT_SEARCH, m_editSearch);
}

BEGIN_MESSAGE_MAP(CBlueDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_SETTINGPAGE, &CBlueDlg::OnBnClickedSetting)
	ON_BN_CLICKED(IDB_BLUE_ADD, &CBlueDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDB_BLUE_MODIFY, &CBlueDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDB_BLUE_DELETE, &CBlueDlg::OnBnClickedDelete)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()





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
	btn.MoveWindow(CRect(2, 104 + 36 * n, 235, 140 + 36 * n));
}

BOOL CBlueDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	Util::SetWindowSize(m_hWnd, 1024, 728);

	CreatePageButton(m_btnSalePage, IDB_SALEPAGE, 0, _T("���۶���"));
	CreatePageButton(m_btnPlanPage, IDB_PLANPAGE, 1, _T("�ƻ��Ų�"));
	CreatePageButton(m_btnProductionScanPage, IDB_PRODUCTIONSCANPAGE, 2, _T("����¼��"));
	CreatePageButton(m_btnNotification, IDB_NOTIFICATION, 3, _T("��������"));
	CreatePageButton(m_btnProductionDataAnalyst, IDB_PRODUCTIONDATAANALYST, 4, _T("����չʾ"));
	CreatePageButton(m_btnSettingPage, IDB_SETTINGPAGE, 5, _T("����"));

	m_bsVersion.Create(this, IDS_SOFTWARE_VERSION);
	m_bsDate.Create(this, IDS_DATA_DATE);
	m_bsPersion.Create(this, IDS_PERSION_INFO);
	m_bsIcon.Create(this, IDS_EP_LOGO);

	m_bsIcon.MoveWindow(12, 14, 84, 59);
	m_bsIcon.SetBGPictureIDs(BS_NORMAL, IDB_PNG4);

	m_bsPersion.SetBackgroundColor(COL_GRAY);
	m_bsPersion.SetBSFont(_T("Segoe UI"), 12);
	m_bsDate.SetBackgroundColor(COL_GRAY);
	m_bsDate.SetBSFont(_T("Segoe UI"), 12);
	m_bsVersion.SetBackgroundColor(COL_GRAY);
	m_bsVersion.SetBSFont(_T("Segoe UI"), 16, FALSE, TRUE);


	m_bsPersion.MoveWindow(2, 2, 48, 98);
	m_bsPersion.BringWindowToTop();
	m_bsVersion.MoveWindow(122, 33, 363 - 122, 62 - 33);
	m_bsVersion.BringWindowToTop();

	m_bsVersion.SetWindowText(_T("Management System V1.0"));
	m_bsDate.MoveWindow(890, 31, 1018 - 910, 49 - 31);
	m_bsDate.SetWindowText(_T("Date: 2014/10/30"));
	m_bsPersion.MoveWindow(730, 59, 1015 - 725, 77 - 59);
	m_bsPersion.SetWindowText(_T("Name: Patrick  Role: Manager  Department: D1"));

	m_editSearch.MoveWindow(CRect(503, 128, 741, 152));

	m_btnAdd.Create(this, IDB_BLUE_ADD);
	m_btnAdd.SetWindowText(_T("���"));
	m_btnAdd.SetBSFont(12);
	m_btnAdd.MoveWindow(CRect(277, 128, 376, 152));

	m_btnDelete.Create(this, IDB_BLUE_DELETE);
	m_btnDelete.SetWindowText(_T("ɾ��"));
	m_btnDelete.MoveWindow(CRect(398, 172, 493, 198));

	m_btnModify.Create(this, IDB_BLUE_MODIFY);
	m_btnModify.SetWindowText(_T("�޸�"));
	m_btnModify.MoveWindow(CRect(278, 172, 373, 198));

	m_btnSearch.Create(this, IDB_BLUE_SEARCH);
	m_btnSearch.SetWindowText(_T("��ѯ"));
	m_btnSearch.MoveWindow(CRect(398, 128, 493, 152));

	m_btnMore.Create(this, IDB_BLUE_MORE);
	m_btnMore.SetWindowText(_T(">"));
	m_btnMore.MoveWindow(CRect(841, 128, 871, 152));

	m_bsMoreWord.Create(this, IDB_BLUE_MOREWORD);
	m_bsMoreWord.SetWindowText(_T("����ɸѡ"));
	m_bsMoreWord.SetBSFont(_T("Segoe UI"), 12);
	m_bsMoreWord.MoveWindow(CRect(754, 128, 838, 151));



	CRect rt;
	rt.left = 254;
	rt.top = 237;
	rt.right = 994;
	rt.bottom = 728;
	m_webView.Create(NULL, NULL, WS_CHILD, rt, this, 10000, NULL);
	m_webView.ShowWindow(SW_SHOW);
	//m_webView.OpenWebBrowser();
	m_lpJsMediator = static_cast<IJSMediator*>(&m_webView);
	m_pJqGridAPI.reset(new CJQGridAPI(m_lpJsMediator));
	m_pJqGridAPI->d_OnRowChecked += std::make_pair(this, &CBlueDlg::OnRowChecked);
	CString path;

	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
	path.ReleaseBuffer();
#ifdef _DEBUG
	path.Replace(_T("Debug\\Blue.exe"), _T("BlueTable\\sale.html"));
#else
	path.Replace(_T("Blue.exe"), _T("sale.html"));
#endif
	VARIANT url;
	url.vt = VT_BSTR;
	url.bstrVal = (BSTR)::SysAllocString(path);
	m_webView.OpenURL(&url);
	m_btnDelete.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	//m_webBrowser.Navigate(_T("C:\\Users\\SUN\\Desktop\\WebBrowser���ر�����Դ - Games - ����԰.html"), NULL, NULL, NULL, NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
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



void CBlueDlg::OnBnClickedSetting()
{

}


BOOL CBlueDlg::OnEraseBkgnd(CDC* pDC)
{

	// TODO: Add your message handler code here and/or call default
	BOOL ret = __super::OnEraseBkgnd(pDC);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 1024, 728), COL_WHITE);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 1024, 84), COL_GRAY);
	CBSObject::DrawRect(pDC->m_hDC, CRect(254, 102, 995, 218), COL_BLACK, 2);
	CBSObject::DrawRect(pDC->m_hDC, CRect(0, 102, 237, 727), COL_GRAY, 2);
	CBSObject::DrawLine(pDC->m_hDC, CPoint(-1, 84), CPoint(1024, 84), COL_BLACK, 2);
	return ret;
}


int CBlueDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void CBlueDlg::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("Add new item"));
	if (IDOK == dlg.DoModal()){
		m_pJqGridAPI->AddRow(dlg.GetResult());
	}

}

void CBlueDlg::OnBnClickedModify()
{
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt;
	CSaleAddDlg dlg(_T("Modify item"));
	std::vector<int> checkedRows;
	std::vector<CString> rowData;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		m_pJqGridAPI->GetRow(checkedRows[i], rowData);
		if (pstOpt.get() == NULL)
		{
			pstOpt.reset(new CSaleAddDlg::Option_t(rowData));
		}
		else
		{
			pstOpt->Merge(rowData);
		}
	}
	dlg.SetOption(pstOpt.get());
	if (IDOK == dlg.DoModal()){
		const std::vector<CString>& result = dlg.GetResult();
		for (int j = result.size() - 1; j >= 0; --j)
		{
			if (result[j] != OPT_FALSE)
			{
				for (int i = checkedRows.size() - 1; i >= 0; --i)
				{
					m_pJqGridAPI->SetCell(i, j, result[j]);
				}
			}
		}
	}
}

void CBlueDlg::OnBnClickedDelete()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		m_pJqGridAPI->DelRow(checkedRows[i]);
	}
	OnRowChecked();
}

void CBlueDlg::OnRowChecked()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	if (checkedRows.empty())
	{
		m_btnDelete.EnableWindow(FALSE);
		m_btnModify.EnableWindow(FALSE);
	}
	else{
		m_btnDelete.EnableWindow(TRUE);
		m_btnModify.EnableWindow(TRUE);
	}
}
