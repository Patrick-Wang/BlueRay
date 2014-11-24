#pragma once
#include "JSExecutor.h"
#include "UILib/Delegate.h"
#include "ComJsFun.h"

class CJQGridAPI
{
public:
	CJQGridAPI(IJSMediator* pMedia);
	~CJQGridAPI();
	void ShowGrid(LPCTSTR gridName);
	void HideGrid(LPCTSTR gridName);
	void ShowRow(int rowId);
	void HideRow(int rowId);
	int AddRow(const std::vector<CString>& rowData);
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
	CDelegate<void(void)> d_OnRowChecked;
	CDelegate<void(void)> d_OnGridComplete;

	VARIANT JSCall(int id, const std::vector<VARIANT>& params);

	static void Split(CString& src, TCHAR split, std::vector<CString>& retData);
	static void Split(CString& src, TCHAR split, std::vector<int>& retData);
	static void Join(const std::vector<CString>& retData, CString& dest);
private:
	IJSMediator* m_pMedia;
	std::auto_ptr<CComJsFun> m_lpJsfOnChecked;
	std::auto_ptr<CComJsFun> m_lpJsfOnComplete;
};

