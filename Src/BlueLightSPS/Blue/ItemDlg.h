#pragma once


// CAddDlg dialog

class CItemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CItemDlg)

public:
	CItemDlg(LPCTSTR title, CWnd* pParent = NULL);   // standard constructor
	virtual ~CItemDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_ITEMINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	virtual BOOL OnInitDialog();
private:
	CString m_Title;
};
