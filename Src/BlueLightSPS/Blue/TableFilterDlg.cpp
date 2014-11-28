// TableFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "TableFilterDlg.h"
#include "afxdialogex.h"


// CTableFilterDlg dialog

IMPLEMENT_DYNAMIC(CTableFilterDlg, CDialogEx)

CTableFilterDlg::CTableFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTableFilterDlg::IDD, pParent)
{

}

CTableFilterDlg::~CTableFilterDlg()
{
}

void CTableFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTableFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// CTableFilterDlg message handlers
