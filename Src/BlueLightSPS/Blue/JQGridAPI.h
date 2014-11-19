#pragma once
#include "JSExecutor.h"
#include "UILib/Delegate.h"
class CJsFun :
	public IJSMediator::IJSFunction{
public:
	CJsFun(LPCTSTR lpName, int id)
		: m_name(lpName)
		, m_Id(id){
	}

	VARIANT Call(std::vector<VARIANT>& params){
		return m_dFun(m_Id, params);
	}

	LPCTSTR Name(){
		return m_name;
	}

	int Id(){
		return m_Id;
	}

	CDelegate<VARIANT(int, const std::vector<VARIANT>&)> m_dFun;

private:
	int m_Id;
	CString m_name;
};

class CJQGridAPI
{
public:
	CJQGridAPI(IJSMediator* pMedia);
	~CJQGridAPI();
	void ShowRow(int rowId);
	void HideRow(int rowId);
	int AddRow(const std::vector<CString>& rowData);
	void DelRow(int rowId);
	int GetCurRow();
	int GetRowCount();
	int GetRowId(int index);
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
	std::auto_ptr<CJsFun> m_lpJsfOnChecked;
	std::auto_ptr<CJsFun> m_lpJsfOnComplete;
};

