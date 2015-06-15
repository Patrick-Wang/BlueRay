#pragma once
#include "afxwin.h"
#include "PopupDlg.h"
#include "XMLParser.h"
#include <map>
#include "SettingManager.h"

// CTableFilterDlgForSale dialog

class CTableFilterDlgForSale : public CPopupDlg
{
	DECLARE_DYNAMIC(CTableFilterDlgForSale)

public:
	CTableFilterDlgForSale(LPCTSTR title, CWnd* pParent = NULL);   // standard constructor
	virtual ~CTableFilterDlgForSale();

	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();

	bool Initialize(CJQGridAPI* pJqGridAPI);

	// Dialog Data
	enum { IDD = IDD_DIALOG_TABLEFILTER };

	afx_msg void OnBnClickedSelectAll();

private:
	virtual void PostNcDestroy();

	void SaveColsSetting(std::vector<CString>& vecColsStatus);
	void GetColsSetting(std::vector<CString>& vecColsStatus);
	bool IsMustBeHiddenCol(int iColIndex);

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	

private:
	CButton* m_aCheckBoxs[nsSale::end];
	CJQGridAPI* m_pJqGridAPI;
	CButton* m_checkboxSelectAll;
};
