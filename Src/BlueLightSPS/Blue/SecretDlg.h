#pragma once
#include "afxwin.h"
#include "BSStatic.h"

// CSecretDlg dialog

class CSecretDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecretDlg)

public:
	CSecretDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSecretDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SECRET };
	CString& getSecret(){
		return m_strPsw;
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnBnClickedOk();
	CEdit m_editSecret;
	CString m_strPsw;
	CBSStatic m_bsPsw;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
};
