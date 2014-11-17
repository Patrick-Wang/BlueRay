#pragma once
#include "resource.h"
#include "BRButton.h"
#include <vector>
// CAddDlg dialog

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(LPCTSTR title, CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_ITEMINFO };
	const std::vector<CString>& GetResult() const;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnOKClicked();
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	virtual BOOL OnInitDialog();
private:
	CString m_Title;
	CBRButton m_btnOK;
	CBRButton m_btnCancel;
protected:
	std::vector<CString> m_vecResult;
	
};
