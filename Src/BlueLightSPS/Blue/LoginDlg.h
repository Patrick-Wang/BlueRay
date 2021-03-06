#pragma once
#include "BRButton.h"
#include "UILib/BSStatic.h"
#include "afxwin.h"
#include "WebView.h"
#include "IHttp.h"
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
	void InitWebView();
	DECLARE_MESSAGE_MAP()
	CBRButton m_btnVPN;
	CBRButton m_btnForgetPassword;
	CBRButton m_btnLogin;
	CBSStatic m_bsVersion;
	CBSStatic m_bsUserName;
	CBSStatic m_bsPassword;
	CBSStatic m_bsLogo;
	CBSStatic m_bsCopyright;;
	CWebView m_webHttpView;
	HICON m_hIcon;
	CBRButton m_btnClose;
	CBRButton m_btnMin;

	CEdit m_editUserName;
	CComboBox *m_combUserName;
	CEdit m_editPsw;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnCloseClicked();
	afx_msg void OnBnMinmumClicked();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLogin();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNcDestroy();
};
