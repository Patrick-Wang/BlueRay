// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "PopupDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "resource_ids.h"
#include "UILib/BSObject.h"
#include "colors.h"
// CAddDlg dialog

IMPLEMENT_DYNAMIC(CPopupDlg, CDialogEx)


CPopupDlg::CPopupDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CDialogEx(CPopupDlg::IDD, pParent)
	, m_Title(title)
{

}


CPopupDlg::~CPopupDlg()
{
}

void CPopupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPopupDlg, CDialogEx)
//	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SALE_ADD_BTN_CANCEL, &CPopupDlg::OnCancel)
	ON_BN_CLICKED(IDC_SALE_ADD_BTN_OK, &CPopupDlg::OnOK)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CAddDlg message handlers


BOOL CPopupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Util_Tools::Util::SetClientSize(m_hWnd, 837, 471);
	SetWindowText(m_Title);
	m_btnOK.Create(this, IDC_SALE_ADD_BTN_OK);
	m_btnOK.MoveWindow(556, 416, 114, 30);

	m_btnOK.SetWindowText(_T("确定"));
	m_btnCancel.Create(this, IDC_SALE_ADD_BTN_CANCEL);

	m_btnCancel.MoveWindow(690, 416, 114, 30);
	m_btnCancel.SetWindowText(_T("取消"));
	// TODO:  Add extra initialization here
		return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//BOOL CPopupDlg::OnEraseBkgnd(CDC* pDC)
//{
//
//	// TODO: Add your message handler code here and/or call default
//	//BOOL ret = __super::OnEraseBkgnd(pDC);
//	//CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 837, 421), COL_WHITE);
//	return TRUE;
//}


int CPopupDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

//void CPopupDlg::OnOKClicked()
//{
//	CDialogEx::OnOK();
//}

const std::vector<CString>& CPopupDlg::GetResult() const
{
	return m_vecResult;
}


BOOL CPopupDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		OnOK();
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


HBRUSH CPopupDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	pDC->SetBkColor(COL_WHITE);           //设置黑色的背景  
	return  ::CreateSolidBrush(COL_WHITE);

	// TODO:  Return a different brush if the default is not desired
	//return hbr;
}
