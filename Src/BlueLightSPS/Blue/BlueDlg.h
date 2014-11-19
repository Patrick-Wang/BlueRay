
// BlueDlg.h : header file
//

#pragma once
#include "BRButton.h"
#include "UILib/BSStatic.h"
#include "webview.h"
#include "afxwin.h"
#include "JQGridAPI.h"
#include "BRButtonGroup.h"
#define UM_GRID_COMPLETE WM_APP + 1
// CBlueDlg dialog
class CBlueDlg : public CDialogEx
{
// Construction
public:
	CBlueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BLUE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void OnRowChecked();
	void OnGridComplete();
	void OnGridDataLoaded();
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
	
	afx_msg void OnBnClickedSetting();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedMore();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	void OnGroupBtnSelected(CBRButton* pBrbtn);
	void OnGroupBtnUnSelected(CBRButton* pBrbtn);
private:
	CEdit m_editSearch;
	bool m_bInit;
	std::vector<std::pair<int, std::vector<CString>>> m_table;
	CBRButtonGroup m_btnGroup;
	CWebView m_webView;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
