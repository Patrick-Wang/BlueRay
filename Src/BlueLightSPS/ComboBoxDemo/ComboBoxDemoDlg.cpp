
// ComboBoxDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBoxDemo.h"
#include "ComboBoxDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CComboBoxDemoDlg dialog



CComboBoxDemoDlg::CComboBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CComboBoxDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_box);
}

BEGIN_MESSAGE_MAP(CComboBoxDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CComboBoxDemoDlg::OnCbnSelchangeCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CComboBoxDemoDlg::OnCbnDropdownCombo1)
	ON_CBN_CLOSEUP(IDC_COMBO1, &CComboBoxDemoDlg::OnCbnCloseupCombo1)
	ON_CBN_EDITCHANGE(IDC_COMBO1, &CComboBoxDemoDlg::OnCbnEditchangeCombo1)
END_MESSAGE_MAP()


// CComboBoxDemoDlg message handlers

BOOL CComboBoxDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_values.push_back(L"ninffewww");
	m_values.push_back(L"aadfeww");
	m_values.push_back(L"affeewsdfeww");
	m_values.push_back(L"ÄàÄ×");
	m_values.push_back(L"ÄúºÃ");
	updateValues();
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CComboBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboBoxDemoDlg::OnPaint()
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
HCURSOR CComboBoxDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CComboBoxDemoDlg::OnCbnSelchangeCombo1()
{
	
}


void CComboBoxDemoDlg::OnCbnDropdownCombo1()
{
	SendMessage(WM_SETCURSOR, 0, 0);
}


void CComboBoxDemoDlg::OnCbnCloseupCombo1()
{
	updateValues();
}

void CComboBoxDemoDlg::updateValues()
{
	int count = m_box.GetCount();
	for (int i = 0; i < count; ++i)
	{
		m_box.DeleteString(0);
	}

	for (int i = 0; i < m_values.size(); ++i)
	{
		m_box.AddString(m_values[i]);
	}
}


void CComboBoxDemoDlg::OnCbnEditchangeCombo1()
{
	CString text;
	m_box.GetWindowText(text);
	if (text.IsEmpty())
	{
		updateValues();
	}
	else
	{
		std::vector<CString> tmpVals;
		for (int i = 0; i < m_values.size(); ++i)
		{
			if (m_values[i].Find(text) >= 0)
			{
				tmpVals.push_back(m_values[i]);
			}
		}

		int count = m_box.GetCount();
		for (int i = 0; i < count; ++i)
		{
			m_box.DeleteString(0);
		}

		for (int i = 0; i < tmpVals.size(); ++i)
		{
			m_box.AddString(tmpVals[i]);
		}
	}
	m_box.ShowDropDown(TRUE);
}
