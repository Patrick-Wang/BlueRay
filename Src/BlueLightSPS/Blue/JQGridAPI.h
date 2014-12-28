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
	void HideGrid();
	int GetCurrentPage();
	int GetPageSize();
	void ShowCol(int colId);
	void HideCol(int colId);
	void HighLightRow(int rowId);
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
	void SetWidths(LPCTSTR jsonArray);
	void GetWidths(CString& strJson);
	CDelegate<void(void)> d_OnRowChecked;
	CDelegate<void(void)> d_OnGridComplete;
	CDelegate<void(int, int, int, bool)> d_OnUpdateData;

	VARIANT JSCall(int id, const std::vector<VARIANT>& params);

private:
	std::set<int> m_hideCols;
	IJSMediator* m_pMedia;
	int m_pageSize;
	static CComJsFun m_lpJsfOnChecked;
	static CComJsFun m_lpJsfOnComplete;
	static CComJsFun m_lpJsfOnUpdateData;
	BSTR m_gridName;
};

