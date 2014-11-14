
// BlueDlg.h : header file
//

#pragma once
#include "UILib/BSButton.h"
#include "UILib/BSStatic.h"
#include "webview.h"
#include "afxwin.h"
// CBlueDlg dialog
class CBlueDlg : public CDialogEx, public IJSMediator::IJSFunction
{
// Construction
public:
	CBlueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BLUE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	virtual VARIANT Call(std::vector<VARIANT>& params);
	virtual LPCTSTR Name();
	virtual int Id();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void CreatePageButton(CBSButton& pb, UINT id, int n, LPCTSTR text);
	CBSStatic m_bsVersion;
	CBSStatic m_bsDate;
	CBSStatic m_bsPersion;
	CBSStatic m_bsIcon;
	CBSButton m_bsSalePage;
	CBSButton m_bsPlanPage;
	CBSButton m_bsProductionScanPage;
	CBSButton m_bsNotification;
	CBSButton m_bsProductionDataAnalyst;
	CBSButton m_bsSettingPage;
	
	CBSButton m_bsAdd;
	CBSButton m_bsSearch;
	CBSButton m_bsModify;
	CBSButton m_bsDelete;
	CBSButton m_bsMore;
	CBSStatic m_bsMoreWord;


public:
	CWebView m_webView;
	IJSMediator* m_lpJsMediator;
	afx_msg void OnBnClickedTest();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedModify();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEdit m_editSearch;
};
