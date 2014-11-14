// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "ItemDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "resource_ids.h"
#include "UILib/BSObject.h"
// CAddDlg dialog

IMPLEMENT_DYNAMIC(CItemDlg, CDialogEx)


CItemDlg::CItemDlg(LPCTSTR title, CWnd* pParent /*= NULL*/)
	: CDialogEx(CItemDlg::IDD, pParent)
	, m_Title(title)
{

}

CItemDlg::~CItemDlg()
{
}

void CItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CItemDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CAddDlg message handlers


BOOL CItemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Util::SetWindowSize(m_hWnd, 837, 421);
	SetWindowText(m_Title);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CItemDlg::OnEraseBkgnd(CDC* pDC)
{

	// TODO: Add your message handler code here and/or call default
	//BOOL ret = __super::OnEraseBkgnd(pDC);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, 837, 421), COL_WHITE);
	return TRUE;
}


int CItemDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}