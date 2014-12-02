#pragma once
#include "afxwin.h"
#include "PopupDlg.h"
#include <map>

enum PageIDEnum
{
	Page_Sale,
	Page_Plan,
	Page_Scan
};

// CTableFilterDlg dialog

class CTableFilterDlg : public CPopupDlg
{
	DECLARE_DYNAMIC(CTableFilterDlg)

public:
	CTableFilterDlg(LPCTSTR title, CJQGridAPI* pJqGridAPI, PageIDEnum pageID, CWnd* pParent = NULL);   // standard constructor
	virtual ~CTableFilterDlg();

	//afx_msg void OnBnClickedOk();
	//afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();

	// Dialog Data
	enum { IDD = IDD_DIALOG_TABLEFILTER };

private:
	virtual void PostNcDestroy();

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

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

	//CString m_Title;
	CJQGridAPI* m_pJqGridAPI;

	static const int m_breakPointOfPlanPage = CheckBox_BZ;
	
//public:
//	CButton m_btnOK;
//	CButton m_btnCancel;
};
