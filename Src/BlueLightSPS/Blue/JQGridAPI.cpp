#include "stdafx.h"
#include "JQGridAPI.h"
#define ONROWCHECKED 12345
#define ONGRIDCOMPLETE 12346

CJQGridAPI::CJQGridAPI(IJSMediator* pMedia)
	: m_pMedia(pMedia)
{
	m_lpJsfOnChecked.reset(new CJsFun(_T("onRowChecked"), ONROWCHECKED));
	m_pMedia->RegisterJsFunction(m_lpJsfOnChecked.get());
	m_lpJsfOnChecked->m_dFun += std::make_pair(this, &CJQGridAPI::JSCall);

	m_lpJsfOnComplete.reset(new CJsFun(_T("onGridComplete"), ONGRIDCOMPLETE));
	m_pMedia->RegisterJsFunction(m_lpJsfOnComplete.get());
	m_lpJsfOnComplete->m_dFun += std::make_pair(this, &CJQGridAPI::JSCall);
}


CJQGridAPI::~CJQGridAPI()
{
}

int CJQGridAPI::AddRow(const std::vector<CString>& rowData)
{
		CString strArray;
		Join(rowData, strArray);
		VARIANT vt;
		vt.vt = VT_BSTR;
		vt.bstrVal = strArray.AllocSysString();
		std::vector<VARIANT> params;
		params.push_back(vt);
		VARIANT vtRet = m_pMedia->CallJsFunction(_T("addRowData"), params);
		::SysFreeString(vt.bstrVal);
		if (VT_I4 == vtRet.vt)
		{
			return vtRet.intVal;
		}
		return -1;
}

void CJQGridAPI::DelRow(int rowId)
{
	VARIANT vt;
	vt.vt = VT_I4;
	vt.intVal = rowId;
	std::vector<VARIANT> params;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("delRowData"), params);
}

int CJQGridAPI::GetCurRow()
{
	std::vector<VARIANT> params;
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
	Split(result, _T(','), rowData);
}

void CJQGridAPI::GetRow(int rowId, CString& rowData)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	VARIANT ret = m_pMedia->CallJsFunction(_T("getRowData"), params);
	if (VT_BSTR == ret.vt)
	{
		rowData = ret.bstrVal;
	}
}

void CJQGridAPI::Split(CString& src, TCHAR split, std::vector<CString>& retData)
{
	int start = 0;
	int index = src.Find(split);
	while (index > 0)
	{
		retData.push_back(src.Mid(start, index - start));
		start = index + 1;
		index = src.Find(split, start);
	}
	if (!src.IsEmpty())
	{
		retData.push_back(src.Mid(start));
	}
}

void CJQGridAPI::Split(CString& src, TCHAR split, std::vector<int>& retData)
{
	int start = 0;
	int index = src.Find(split);
	while (index > 0)
	{
		retData.push_back(_tstoi(src.Mid(start, index - start)));
		start = index + 1;
		index = src.Find(split, start);
	}
	if (!src.IsEmpty())
	{
		retData.push_back(_tstoi(src.Mid(start)));
	}
}

void CJQGridAPI::Join(const std::vector<CString>& data, CString& dest)
{
	for (int i = 0, len = data.size(); i < len; ++i)
	{
		dest += data[i];
		if (i + 1 < len)
		{
			dest += _T(",");
		}
	}
}

void CJQGridAPI::SetRow(int rowId, const std::vector<CString>& rowData)
{
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	CString strArray;
	Join(rowData, strArray);
	vt.vt = VT_BSTR;
	vt.bstrVal = strArray.AllocSysString();
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setRowData"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::GetCheckedRows(std::vector<int>& checkedRows)
{
	std::vector<VARIANT> params;

	VARIANT ret = m_pMedia->CallJsFunction(_T("getSelectedRows"), params);
	if (VT_BSTR == ret.vt)
	{		
		CString result = ret.bstrVal;
		Split(result, _T(','), checkedRows);
	}

}

void CJQGridAPI::SetCell(int rowId, int colIndex, const CString& data)
{
	std::vector<VARIANT> params;
	VARIANT vt;
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
	if (ONROWCHECKED == id)
	{
		d_OnRowChecked();
	}
	else if (ONGRIDCOMPLETE == id)
	{
		d_OnGridComplete();
	}
	return ret;
}

int CJQGridAPI::GetRowCount()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
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
