// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "AddDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "resource_ids.h"
#include "UILib/BSObject.h"
#include "colors.h"
// CAddDlg dialog

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)


CAddDlg::CAddDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CDialogEx(CAddDlg::IDD, pParent)
	, m_Title(title)
{

}


CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDB_ADD_CANCEL, &CAddDlg::OnCancel)
	ON_BN_CLICKED(IDB_ADD_OK, &CAddDlg::OnOKClicked)
END_MESSAGE_MAP()


// CAddDlg message handlers


BOOL CAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Util::SetClientSize(m_hWnd, 837, 421);
	SetWindowText(m_Title);
	m_btnOK.Create(this, IDB_ADD_OK);
	m_btnOK.MoveWindow(556, 366, 114, 30);
	m_btnOK.SetWindowText(_T("ȷ��"));
	m_btnCancel.Create(this, IDB_ADD_CANCEL);
	m_btnCancel.MoveWindow(690, 366, 114, 30);
	m_btnCancel.SetWindowText(_T("ȡ��"));
	// TODO:  Add extra initialization here
		return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CAddDlg::OnEraseBkgnd(CDC* pDC)
{

	// TODO: Add your message handler code here and/or call default
	//BOOL ret = __super::OnEraseBkgnd(pDC);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 837, 421), COL_WHITE);
	return TRUE;
}


int CAddDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void CAddDlg::OnOKClicked()
{
	CDialogEx::OnOK();
}

const std::vector<CString>& CAddDlg::GetResult() const
{
	return m_vecResult;
}


BOOL CAddDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
