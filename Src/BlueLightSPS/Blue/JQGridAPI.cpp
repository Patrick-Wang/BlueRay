#include "stdafx.h"

#include "JsonParser.h"

#include "JsonObjects.h"

#include "JsonFactory.h"

#include "JQGridAPI.h"


#include "Util.h"

CComJsFun CJQGridAPI::m_JsfnOnTemplateExportClicked(_T("onTemplateExportClicked"));
CComJsFun CJQGridAPI::m_JsfnOnExportClicked(_T("onExportClicked"));
CComJsFun CJQGridAPI::m_JsfnOnImportClicked(_T("onImportClicked"));
CComJsFun CJQGridAPI::m_JsfnOnUpdateData(_T("onUpdate"));
CComJsFun CJQGridAPI::m_JsfnOnChecked(_T("onRowChecked"));
CComJsFun CJQGridAPI::m_JsfnOnComplete(_T("onGridComplete"));
int CJQGridAPI::m_pageSize = 0;

CJQGridAPI::CJQGridAPI(IJSMediator* pMedia, LPCTSTR lpGrid)
	: m_pMedia(pMedia)
	, m_gridName(::SysAllocString(lpGrid))
{
	ASSERT(pMedia != NULL);
	ASSERT(lpGrid != NULL);

	m_pMedia->RegisterJsFunction(&m_JsfnOnChecked);
	m_JsfnOnChecked.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	m_pMedia->RegisterJsFunction(&m_JsfnOnComplete);
	m_JsfnOnComplete.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	m_pMedia->RegisterJsFunction(&m_JsfnOnUpdateData);
	m_JsfnOnUpdateData.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	m_pMedia->RegisterJsFunction(&m_JsfnOnExportClicked);
	m_JsfnOnExportClicked.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	m_pMedia->RegisterJsFunction(&m_JsfnOnTemplateExportClicked);
	m_JsfnOnTemplateExportClicked.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

	m_pMedia->RegisterJsFunction(&m_JsfnOnImportClicked);
	m_JsfnOnImportClicked.d_onJsCall += std::make_pair(this, &CJQGridAPI::JSCall);

}


CJQGridAPI::~CJQGridAPI()
{
	if (NULL != m_gridName)
	{
		::SysFreeString(m_gridName);
	}

	m_JsfnOnChecked.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_JsfnOnComplete.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_JsfnOnUpdateData.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_JsfnOnExportClicked.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_JsfnOnTemplateExportClicked.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
	m_JsfnOnImportClicked.d_onJsCall -= std::make_pair(this, &CJQGridAPI::JSCall);
}

int CJQGridAPI::AddRow(const std::vector<CString>& rowData)
{
	std::auto_ptr<Json::JsonArray> pRows(Json::JsonFactory::createArray());
	for (int i = 0; i < rowData.size(); ++i)
	{
		pRows->add(Json::JsonFactory::createString((LPTSTR)(LPCTSTR)rowData[i]));
	}
	Json::json_stringstream jstream;
	pRows->asJson(jstream);

	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(jstream.str().c_str());
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
	std::auto_ptr<Json::JsonArray> pRows(Json::JsonFactory::createArray());
	for (int i = 0; i < rowData.size(); ++i)
	{
		pRows->add(Json::JsonFactory::createString((LPTSTR)(LPCTSTR)rowData[i]));
	}
	Json::json_stringstream jstream;
	pRows->asJson(jstream);

	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = id;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(jstream.str().c_str());
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

	Json::JsonParser parser;
	std::auto_ptr<Json::JsonArray> row((Json::JsonArray*)parser.Parse((LPTSTR)(LPCTSTR)result));
	for (int i = 0; i < row->size(); ++i)
	{
		rowData.push_back(row->asString(i).c_str());
	}
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
	std::auto_ptr<Json::JsonArray> pRows(Json::JsonFactory::createArray());
	for (int i = 0; i < rowData.size(); ++i)
	{
		pRows->add(Json::JsonFactory::createString((LPTSTR)(LPCTSTR)rowData[i]));
	}
	Json::json_stringstream jstream;
	pRows->asJson(jstream);


	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_BSTR;
	vt.bstrVal = ::SysAllocString(jstream.str().c_str());
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setRowData"), params);
	::SysFreeString(vt.bstrVal);
}

void CJQGridAPI::GetCheckedRows(std::vector<int>& checkedRows)
{
	checkedRows.clear();
	std::vector<VARIANT> params;
	VARIANT vt;
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	VARIANT ret = m_pMedia->CallJsFunction(_T("getSelectedRows"), params);
	if (VT_BSTR == ret.vt)
	{
		Json::JsonParser parser;
		std::auto_ptr<Json::JsonArray> rows((Json::JsonArray*)parser.Parse(ret.bstrVal));
		for (int i = 0; i < rows->size(); ++i)
		{
			checkedRows.push_back(_tstoi(rows->asString(i).c_str()));
		}
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
		if ((int)&m_JsfnOnChecked == id)
		{
			d_OnRowChecked();
		}
		else if ((int)&m_JsfnOnComplete == id)
		{
			d_OnGridComplete();
		}
		else if ((int)&m_JsfnOnUpdateData == id)
		{
			d_OnUpdateData(params[1].intVal, params[2].intVal, params[3].intVal, params[4].boolVal);
		}
		else if ((int)&m_JsfnOnExportClicked == id)
		{
			d_OnExportClicked();
		}
		else if ((int)&m_JsfnOnTemplateExportClicked == id)
		{
			d_OnTemplateExportClicked();
		}
		else if ((int)&m_JsfnOnImportClicked == id)
		{
			d_OnImportClicked();
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
//
//void CJQGridAPI::ShowRow(int rowId)
//{
//	std::vector<VARIANT> params;
//	VARIANT vt = {};
//	vt.vt = VT_BSTR;
//	vt.bstrVal = m_gridName;
//	params.push_back(vt);
//	vt.vt = VT_I4;
//	vt.intVal = rowId;
//	params.push_back(vt);
//	vt.vt = VT_BSTR;
//	vt.bstrVal = ::SysAllocString(_T("true"));
//	params.push_back(vt);
//	m_pMedia->CallJsFunction(_T("showHideRow"), params);
//	::SysFreeString(vt.bstrVal);
//}
//
//void CJQGridAPI::HideRow(int rowId)
//{
//	std::vector<VARIANT> params;
//	VARIANT vt = {};
//	vt.vt = VT_BSTR;
//	vt.bstrVal = m_gridName;
//	params.push_back(vt);
//	vt.vt = VT_I4;
//	vt.intVal = rowId;
//	params.push_back(vt);
//	vt.vt = VT_BSTR;
//	vt.bstrVal = ::SysAllocString(_T("false"));
//	params.push_back(vt);
//	m_pMedia->CallJsFunction(_T("showHideRow"), params);
//	::SysFreeString(vt.bstrVal);
//}

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

void CJQGridAPI::Refresh(CString& strJson)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.bstrVal = strJson.AllocSysString();
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("update"), params);
	::SysFreeString(vt.bstrVal);
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

int CJQGridAPI::GetCurrentPage()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);

	vt = m_pMedia->CallJsFunction(_T("curPage"), params);
	if (VT_I4 == vt.vt)
	{
		return vt.intVal;
	}
	return 0;
}

int CJQGridAPI::GetGridPageSize()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);

	vt = m_pMedia->CallJsFunction(_T("rowNum"), params);
	if (VT_I4 == vt.vt)
	{
		return vt.intVal;
	}
	return 0;
}

void CJQGridAPI::HighLightRow(int rowId)
{
	SetRowFgColor(rowId, 237, 28, 36);
}

void CJQGridAPI::DisableSelect(int rowId)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("disableSelect"), params);

}

void CJQGridAPI::EnableSelect(int rowId)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("enableSelect"), params);
}

void CJQGridAPI::GetDisabledRows(std::vector<int>& disabledRows)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt = m_pMedia->CallJsFunction(_T("getDisabledRows"), params);
	if (vt.vt == VT_BSTR)
	{
		Json::JsonParser parser;
		std::auto_ptr<Json::JsonArray> disableRows((Json::JsonArray*)parser.Parse(vt.bstrVal));
		for (int i = 0; i < disableRows->size(); ++i)
		{
			disabledRows.push_back(_tstoi(disableRows->asString(i).c_str()));
		}
	}
}

void CJQGridAPI::SetRowBgColor(int rowId, int r, int g, int b)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = r;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = g;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = b;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setRowBgColor"), params);
}

void CJQGridAPI::SetRowFgColor(int rowId, int r, int g, int b)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = r;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = g;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = b;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setRowFgColor"), params);
}

int CJQGridAPI::GetPageSize()
{
	return m_pageSize;
}

void CJQGridAPI::SetPageSize(int pageSize)
{
	m_pageSize = pageSize;
}

void CJQGridAPI::SetChecked(int rowId, bool bCheck)
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	vt.vt = VT_I4;
	vt.intVal = rowId;
	params.push_back(vt);
	vt.vt = VT_BOOL;
	vt.boolVal = bCheck ? VARIANT_TRUE : VARIANT_FALSE;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("setSelect"), params);
}

void CJQGridAPI::CancelSort()
{
	std::vector<VARIANT> params;
	VARIANT vt = {};
	vt.vt = VT_BSTR;
	vt.bstrVal = m_gridName;
	params.push_back(vt);
	m_pMedia->CallJsFunction(_T("cancelSort"), params);

}

//void CJQGridAPI::UncheckedAll()
//{
//	std::vector<VARIANT> params;
//	VARIANT vt = {};
//	vt.vt = VT_BSTR;
//	vt.bstrVal = m_gridName;
//	params.push_back(vt);
//	m_pMedia->CallJsFunction(_T("cleanSelectedRow"), params);
//}



