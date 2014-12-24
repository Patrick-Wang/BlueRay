#include "stdafx.h"

#include "JsonParser.h"

#include "JsonObjects.h"

#include "JQGridAPI.h"

#include "Util.h"


#define ONROWCHECKED 12345
#define ONGRIDCOMPLETE 12346

CJQGridAPI::CJQGridAPI(IJSMediator* pMedia, LPCTSTR lpGrid)
	: m_pMedia(pMedia)
	, m_gridName(::SysAllocString(lpGrid))
{
	ASSERT(pMedia != NULL);
	ASSERT(lpGrid != NULL);
	//m_lpJsfOnChecked.reset(new CComJsFun(_T("onRowChecked"), ONROWCHECKED));
	m_pMedia->RegisterJsFunction(&m_lpJsfOnChecked);
	m_lpJsfOnChecked.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	//m_lpJsfOnComplete.reset(new CComJsFun(_T("onGridComplete"), ONGRIDCOMPLETE));
	m_pMedia->RegisterJsFunction(&m_lpJsfOnComplete);
	m_lpJsfOnComplete.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);
}


CJQGridAPI::~CJQGridAPI()
{
	if (NULL != m_gridName)
	{
		::SysFreeString(m_gridName);
	}

	m_lpJsfOnChecked.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_lpJsfOnComplete.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
}

int CJQGridAPI::AddRow(const std::vector<CString>& rowData)
{
	CString strArray;
	Util_Tools::Util::Join(rowData, strArray);
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = strArray.AllocSysString();
	params.push_back(vt);
	VARIANT vtRet = m_pMedia->CallJsFunction(_T("addRowData"), params);
	::SysFreeString(vt.bstrVal);
	if (VT_I4 == vtRet.vt)
	{
		return vtRet.intVal;
	}
	return -1;
}

void CJQGridAPI::AddRow(int id, const std::vector<CString>& rowData)
{
	CString strArray;
	Util_Tools::Util::Join(rowData, strArray);
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = id;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = strArray.AllocSysString();
	params.push_back(vt);
	VARIANT vtRet = m_pMedia->CallJsFunction(_T("addRowDataById"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::DelRow(int rowId)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;

	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("delRowData"), params);
}

int CJQGridAPI::GetCurRow()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	VARIANT vtRet = m_pMedia->CallJsFunction(_T("getSelRow"), params);
	if (VT_I4 == vtRet.vt)
	{
		return vtRet.intVal;
	}
	return -1;
}

void CJQGridAPI::GetRow(int rowId, std::vector<CString>& rowData)
{
	CString result;
	GetRow(rowId, result);
	Util_Tools::Util::Split(result, _T(','), rowData);
}

void CJQGridAPI::GetRow(int rowId, CString& rowData)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	VARIANT ret = m_pMedia->CallJsFunction(_T("getRowData"), params);
	if (VT_BSTR == ret.vt)
	{
		rowData = ret.bstrVal;
	}
}

void CJQGridAPI::SetRow(int rowId, const std::vector<CString>& rowData)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	CString strArray;
	Util_Tools::Util::Join(rowData, strArray);
	vt.vt = VT_BSTR;
	vt.bstrVal = strArray.AllocSysString();
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setRowData"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::GetCheckedRows(std::vector<int>& checkedRows)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	VARIANT ret = m_pMedia->CallJsFunction(_T("getSelectedRows"), params);
	if (VT_BSTR == ret.vt)
	{
		CString result = ret.bstrVal;
		Util_Tools::Util::Split(result, _T(','), checkedRows);
	}

}

void CJQGridAPI::SetCell(int rowId, int colIndex, const CString& data)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = colIndex;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = data.AllocSysString();
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setCellData"), params);
	::SysFreeString(vt.bstrVal);
}

VARIANT CJQGridAPI::JSCall(int id, const std::vector<VARIANT>& params)
{
	VARIANT ret = {};
	ASSERT(!params.empty());
	if (0 == _tcscmp(params[0].bstrVal, m_gridName))
	{
		if (ONROWCHECKED == id)
		{
			d_OnRowChecked();
		}
		else if (ONGRIDCOMPLETE == id)
		{
			d_OnGridComplete();
		}
	}
	return ret;
}

int CJQGridAPI::GetRowCount()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt = m_pMedia->CallJsFunction(_T("getRowCount"), params);
	if (VT_I4 == vt.vt)
	{
		return vt.intVal;
	}
	return -1;
}

void CJQGridAPI::ShowRow(int rowId)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(_T("true"));
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("showHideRow"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::HideRow(int rowId)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(_T("false"));
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("showHideRow"), params);
	::SysFreeString(vt.bstrVal);
}

int CJQGridAPI::GetRowId(int index)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = index;
	params.push_back(vt);
	vt = m_pMedia->CallJsFunction(_T("getRowId"), params);
	if (vt.vt == VT_I4)
	{
		return vt.intVal;
	}
	return -1;
}

void CJQGridAPI::Refresh()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("reload"), params);
}

void CJQGridAPI::HideGrid()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("hideGrid"), params);
}

void CJQGridAPI::ShowGrid()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("showGrid"), params);
}

void CJQGridAPI::ShowCol(int colId)
{
	if (m_hideCols.find(colId) != m_hideCols.end()){
		m_hideCols.erase(colId);
		std::vector<VARIANT> params;
		VARIANT vt = {};
		vt.vt = VT_BSTR;
		vt.bstrVal = m_gridName;
		params.push_back(vt);
		vt.vt = VT_I4;
		vt.intVal = colId;
		params.push_back(vt);
		m_pMedia->CallJsFunction(_T("showCol"), params);
	}
}

void CJQGridAPI::HideCol(int colId)
{
	if (m_hideCols.find(colId) == m_hideCols.end()){
		m_hideCols.insert(colId);
		std::vector<VARIANT> params;
		VARIANT vt = {};
		vt.vt = VT_BSTR;
		vt.bstrVal = m_gridName;
		params.push_back(vt);
		vt.vt = VT_I4;
		vt.intVal = colId;
		params.push_back(vt);
		m_pMedia->CallJsFunction(_T("hideCol"), params);
	}
}

const std::set<int>& CJQGridAPI::getHiddenCols()
{
	return m_hideCols;
}

void CJQGridAPI::SetWidths(LPCTSTR  jsonArray)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(jsonArray);
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setWidths"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::GetWidths(CString& strJson)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	
	vt = m_pMedia->CallJsFunction(_T("getWidths"), params);
	if (VT_BSTR == vt.vt)
	{
		strJson = vt.bstrVal;
	}
}

CComJsFun CJQGridAPI::m_lpJsfOnComplete(_T("onRowChecked"), ONROWCHECKED);

CComJsFun CJQGridAPI::m_lpJsfOnChecked(_T("onGridComplete"), ONGRIDCOMPLETE);
