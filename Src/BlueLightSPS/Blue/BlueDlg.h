
// BlueDlg.h : header file
//

#pragma once
#include "BRButton.h"
#include "UILib/BSStatic.h"
#include "webview.h"
#include "afxwin.h"
#include "JQGridAPI.h"
#include "BRButtonGroup.h"
#include "IHttp.h"
#include "SalePanel.h"
#include <memory>
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

	//void OnGridDataLoaded();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	void InitWebView();
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
	
	


public:
	//afx_msg void OnBnClickedSetting();
	//afx_msg void OnBnClickedPlan();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	void OnGroupBtnSelected(CBRButton* pBrbtn);
	void OnGroupBtnUnSelected(CBRButton* pBrbtn);
	void OnGridDataLoaded();
private:
	
	//bool m_bInit;
	
	CBRButtonGroup m_btnGroup;
	CWebView m_webView;
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
	std::map<UINT, std::shared_ptr<CControlPanel>> m_pPanelMap;
	std::auto_ptr<IHttp> m_pHttp;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void OnWebComplete();

private:
	CDelegate<void(void)> d_OnGridLoaded;
};
