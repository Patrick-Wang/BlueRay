
// VBARunnerServiceDlg.h : header file
//

#pragma once
#include <map>
#include <windef.h>
// CVBARunnerServiceDlg dialog
class CVBARunnerServiceDlg : public CDialogEx
{
// Construction
public:
	CVBARunnerServiceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VBARUNNERSERVICE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	std::map<HANDLE, CString> m_handlMap;
public:
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
