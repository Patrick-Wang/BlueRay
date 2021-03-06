#pragma once
#include "afxwin.h"
#include "PopupDlg.h"
#include "XMLParser.h"
#include <map>
#include "SettingManager.h"

enum PageIDEnum
{
	Page_Sale,
	Page_Plan,
	Page_Scan,
	Page_Notification_Sale,
	Page_Notification_Plan
};

// CTableFilterDlg dialog

class CTableFilterDlg : public CPopupDlg
{
	DECLARE_DYNAMIC(CTableFilterDlg)

public:
	CTableFilterDlg(LPCTSTR title, CWnd* pParent = NULL);   // standard constructor
	virtual ~CTableFilterDlg();

	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();

	bool Initialize(CJQGridAPI* pJqGridAPI, PageIDEnum pageID);

	// Dialog Data
	enum { IDD = IDD_DIALOG_TABLEFILTER };

	afx_msg void OnBnClickedSelectAll();

private:
	virtual void PostNcDestroy();

	void SaveColsSetting(std::vector<CString>& vecColsStatus);
	void GetColsSetting(std::vector<CString>& vecColsStatus);
	int AdjustColsAndCalculateIgnoreItemsNumber();

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	

private:

	CButton* m_aCheckBoxs[nsTableFilter::end];
	PageIDEnum m_enumPage;

	CJQGridAPI* m_pJqGridAPI;

	CButton* m_checkboxSelectAll;

	static const int m_breakPointOfPlanPage = nsTableFilter::scrq;
};
