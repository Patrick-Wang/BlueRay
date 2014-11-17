#pragma once
#include "BRButton.h"
#include "UILib/BSStatic.h"
#include "afxwin.h"

// CLoginDlg dialog

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLoginDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CBRButton m_btnVPN;
	CBRButton m_btnForgetPassword;
	CBRButton m_btnLogin;
	CBSStatic m_bsVersion;
	CBSStatic m_bsUserName;
	CBSStatic m_bsPassword;
	CBSStatic m_bsLogo;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLogin();
	CEdit m_editUserName;
	CEdit m_editPsw;
};
