
// BlueDlg.h : header file
//

#pragma once
#include "BRButton.h"
#include "UILib/BSStatic.h"
#include "webview.h"
#include "afxwin.h"
#include "JQGridAPI.h"
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
	void CreatePageButton(CBRButton& pb, UINT id, int n, LPCTSTR text);
	CBSStatic m_bsVersion;
	CBSStatic m_bsDate;
	CBSStatic m_bsPersion;
	CBSStatic m_bsIcon;
	CBRButton m_btnSalePage;
	CBRButton m_btnPlanPage;
	CBRButton m_btnProductionScanPage;
	CBRButton m_btnNotification;
	CBRButton m_btnProductionDataAnalyst;
	CBRButton m_btnSettingPage;
	
	CBRButton m_btnAdd;
	CBRButton m_btnSearch;
	CBRButton m_btnModify;
	CBRButton m_btnDelete;
	CBRButton m_btnMore;
	CBSStatic m_bsMoreWord;


public:
	CWebView m_webView;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
	IJSMediator* m_lpJsMediator;
	afx_msg void OnBnClickedTest();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEdit m_editSearch;
};
