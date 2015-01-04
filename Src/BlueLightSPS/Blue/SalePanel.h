#pragma once
#include "Sale.h"
#include "BRPanel.h"
#include "BRButton.h"
#include "BSStatic.h"
#include "JQGridAPI.h"
#include "IHttp.h"
#include "TableFilterDlg.h"
#include "SaleAddDlg.h"

class CSalePanel :
	public CBRPanel
{
public:
	CSalePanel(CJQGridAPI* pJqGridAPI);
	~CSalePanel();

	void OnRowChecked();
	void OnGridComplete();
	//void OnHttpSuccess(int id, LPCTSTR resp);
	//void OnHttpFailed(int id);
	void OnSaleDlgGetModifyOption(CSaleAddDlg& dlg);
	void HighLight();

protected:
	void OnExprotClicked();
	virtual void OnInitData();
	virtual void OnInitChilds();
	void OnUpdateData(int page, int rows, int colIndex, bool bAsc);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedTableFilter();
	afx_msg void OnBnClickedMore();

	afx_msg void OnBnClickedReApproveBusiness();
	afx_msg void OnBnClickedReApprovePlan();
	afx_msg void OnCbnSelchangeProductionStatus();

	void OnLoadDataSuccess();
	void OnDelDataSuccess();
	void OnModifyDataSuccess(std::vector<CString>& newData);
	void OnAddDataSuccess(int id, std::vector<CString>& data);
	void OnApproveDataSuccess();

private:
	CBRButton* m_btnAdd;
	CBRButton* m_btnSearch;
	CBRButton* m_btnModify;
	CBRButton* m_btnDelete;
	CBRButton* m_btnMore;
	CBRButton* m_btnTableFilter;
	CBRButton* m_btnReApproveForBusiness;
	CBRButton* m_btnReApproveForPlan;
	CBSStatic* m_bsMoreWord;
	CEdit* m_editSearch;

	CBSStatic* m_bsDateRange;
	CBSStatic* m_bsMiddleLine;
	CDateTimeCtrl* m_dtcSearchFrom;
	CDateTimeCtrl* m_dtcSearchTo;

	int m_iCountBtnOfReApprove;

	std::vector<std::pair<int, std::vector<CString>>> m_table;
	std::vector<CString> m_cacheRow;
	CTableFilterDlg m_tableFilterDlg;
	CComboBox* m_comboProductionStatus;
	
	enum enumProductionStatusForSale
	{
		ProductionStatus_All,
		ProductionStatus_ToBeApprove,
		ProductionStatus_Approving,
		ProductionStatus_Approved
	};

	DECLARE_MESSAGE_MAP()
	
	void ShowReApproveBusinessBtn(BOOL bShow);
	void ShowReApprovePlanBtn(BOOL bShow);
	void ShowReApproveBtns();
	void OnReApproveSuccess(CSale::ApproveType type);
	void FilterTableByStatus(enumProductionStatusForSale productionStatus, CJsonQueryParam &sqp);
	void MakeBasicSearchCondition(CJsonQueryParam &sqp);

public:
	afx_msg void OnNcDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnDestroy();

};

