#pragma once
#include "afxwin.h"

enum PageIDEnum
{
	Page_Sale,
	Page_Plan,
	Page_Scan
};

// CTableFilterDlg dialog

class CTableFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTableFilterDlg)

public:
	CTableFilterDlg(LPCTSTR title, CWnd* pParent = NULL);   // standard constructor
	virtual ~CTableFilterDlg();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	virtual BOOL OnInitDialog();
	void InitPageOwner(PageIDEnum iPageID);

	// Dialog Data
	enum { IDD = IDD_DIALOG_TABLEFILTER };

private:
	virtual void PostNcDestroy();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


private:
	enum CheckBox_Id{
		CheckBox_HTH,
		CheckBox_KHMC,
		CheckBox_GGBH,
		CheckBox_SL,
		CheckBox_ZC,
		CheckBox_DFR,
		CheckBox_ZDQDY,
		CheckBox_YYLGG,
		CheckBox_JF,
		CheckBox_BPQXH,
		CheckBox_BMQXH,
		CheckBox_DLCD,
		CheckBox_ZXCD,
		CheckBox_MPZL,
		CheckBox_DDRQ,
		CheckBox_BZ,
		CheckBox_SCRQ,
		CheckBox_BZRQ,
		CheckBox_FHRQ,
		CheckBox_TCBH,
		CheckBox_CCBH,
		CheckBox_END
	};

	CButton* m_aCheckBoxs[CheckBox_Id::CheckBox_END];
	PageIDEnum m_enumPage;

	CString m_Title;

public:
	CButton m_btnOK;
	CButton m_btnCancel;
};
