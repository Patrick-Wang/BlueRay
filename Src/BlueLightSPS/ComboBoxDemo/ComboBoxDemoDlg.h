
// ComboBoxDemoDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <vector>

// CComboBoxDemoDlg dialog
class CComboBoxDemoDlg : public CDialogEx
{
// Construction
public:
	CComboBoxDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_COMBOBOXDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void updateValues();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnCbnCloseupCombo1();
	CComboBox m_box;
	std::vector<CString> m_values;
	afx_msg void OnCbnEditchangeCombo1();
};
