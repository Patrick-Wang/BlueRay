#pragma once
#include <memory>
#include <set>
#include "JSExecutor.h"
#include "UILib/Delegate.h"
#include "ComJsFun.h"

class CJQGridAPI
{
public:
	CJQGridAPI(IJSMediator* pMedia, LPCTSTR lpGrid);
	~CJQGridAPI();
	const std::set<int>& getHiddenCols();
	void ShowGrid();
	void CancelSort();
	void HideGrid();
	int GetCurrentPage();
	int GetGridPageSize();
	static void SetPageSize(int pageSize);
	static int GetPageSize();
	void ShowCol(int colId);
	void HideCol(int colId);
	void HighLightRow(int rowId);
	void HighLightCell(int rowId, int colId);
	void SetCellColor(int rowId, int colId, int r, int g, int b);
	void SetRowBgColor(int rowId, int r, int g, int b);
	void SetRowFgColor(int rowId, int r, int g, int b);
	void DisableSelect(int rowId);
	void EnableSelect(int rowId);
	void GetDisabledRows(std::vector<int>& disabledRows);
	void ShowRow(int rowId);
	void HideRow(int rowId);
	int AddRow(const std::vector<CString>& rowData);
	void AddRow(int id, const std::vector<CString>& rowData);
	void DelRow(int rowId);
	int GetCurRow();
	int GetRowCount();
	int GetRowId(int index);
	void Refresh();
	void Refresh(CString& strJson);
	void GetRow(int rowId, std::vector<CString>& rowData);
	void GetRow(int rowId, CString& rowData);
	void SetRow(int rowId, const std::vector<CString>& rowData);
	void SetCell(int rowId, int colIndex, const CString& data);
	void GetCheckedRows(std::vector<int>& checkedRows);
	void SetChecked(int rowId, bool bCheck);
	void SetWidths(LPCTSTR jsonArray);
	void GetWidths(CString& strJson);
	CDelegate<void(void)> d_OnRowChecked;
	CDelegate<void(void)> d_OnGridComplete;
	CDelegate<void(int, int, int, bool)> d_OnUpdateData;
	CDelegate<void(void)> d_OnExportClicked;
	CDelegate<void(void)> d_OnImportClicked;
	CDelegate<void(void)> d_OnTemplateExportClicked;
	CDelegate<void(void)> d_OnBzjhTemplateExportClicked;
	CDelegate<void(void)> d_OnScjhTemplateExportClicked;
	CDelegate<void(void)> d_OnZzjhTemplateExportClicked;
	CDelegate<void(void)> d_OnZzgzkTemplateExportClicked;
	CDelegate<void(void)> d_OnZdqPqTemplateExportClicked;
	CDelegate<void(void)> d_OnZxdTemplateExportClicked;
	VARIANT JSCall(int id, const std::vector<VARIANT>& params);
private:
	std::set<int> m_hideCols;
	IJSMediator* m_pMedia;
	static int m_pageSize;
	static CComJsFun m_JsfnOnChecked;
	static CComJsFun m_JsfnOnComplete;
	static CComJsFun m_JsfnOnUpdateData;
	static CComJsFun m_JsfnOnExportClicked;
	static CComJsFun m_JsfnOnImportClicked;
	static CComJsFun m_JsfnOnTemplateExportClicked;
	static CComJsFun  m_JsfnOnBzjhTemplateExportClicked;
	static CComJsFun  m_JsfnOnScjhTemplateExportClicked;
	static CComJsFun  m_JsfnOnZzjhTemplateExportClicked;
	static CComJsFun  m_JsfnOnZzgzkTemplateExportClicked;
	static CComJsFun  m_JsfnOnZdqPqTemplateExportClicked;
	static CComJsFun  m_JsfnOnZxdTemplateExportClicked;
	BSTR m_gridName;
};

