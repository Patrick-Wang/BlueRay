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
	void ShowCol(int colId);
	void HideCol(int colId);
	void ShowRow(int rowId);
	void HideRow(int rowId);
	int AddRow(const std::vector<CString>& rowData);
	void AddRow(int id, const std::vector<CString>& rowData);
	void DelRow(int rowId);
	int GetCurRow();
	int GetRowCount();
	int GetRowId(int index);
	void Refresh();
	void GetRow(int rowId, std::vector<CString>& rowData);
	void GetRow(int rowId, CString& rowData);
	void SetRow(int rowId, const std::vector<CString>& rowData);
	void SetCell(int rowId, int colIndex, const CString& data);
	void GetCheckedRows(std::vector<int>& checkedRows);
	void SetWidths(LPCTSTR jsonArray);
	void GetWidths(CString& strJson);
	CDelegate<void(void)> d_OnRowChecked;
	CDelegate<void(void)> d_OnGridComplete;

	VARIANT JSCall(int id, const std::vector<VARIANT>& params);

private:
	std::set<int> m_hideCols;
	IJSMediator* m_pMedia;
	static CComJsFun m_lpJsfOnChecked;
	static CComJsFun m_lpJsfOnComplete;
	BSTR m_gridName;
};

