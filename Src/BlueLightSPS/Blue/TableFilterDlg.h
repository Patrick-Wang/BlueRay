#pragma once


// CTableFilterDlg dialog

class CTableFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTableFilterDlg)

public:
	CTableFilterDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTableFilterDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_TABLEFILTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
