#include "stdafx.h"
#include "ExcelVBAService.h"
#include "COLEObjects.h"
#include "COLEObject.h"
#include "JsonFactory.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "JsonType.h"
static CApplication ExcelApp;
static CWorkbooks books;
static CWorkbook book;
static CWorksheets sheets;
static CWorksheet sheet;
static CRange range;

ExcelVBAService::ExcelVBAService()
	: m_bStarted(false)
{
	m_bStarted = Start();
}


ExcelVBAService::~ExcelVBAService()
{
	Stop();
}

bool ExcelVBAService::Start()
{
	if (!ExcelApp.CreateDispatch(_T("Excel.Application"), NULL))
	{
		DWORD dw = GetLastError();
		//CString strError;
		//strError.Format(L"error create Excel.Application errorcode: %d", dw);
		//AfxMessageBox(strError);
		return false;
	}
	return true;
}

void ExcelVBAService::Stop()
{
	if (m_bStarted)
	{
		ExcelApp.Quit();
	}
}
//
//void ExcelVBAService::updateCell(CString& path, std::vector<int>& shts, std::vector<int>& rows, std::vector<int>& cols)
//{
//	LPDISPATCH lpDisp = ExcelApp.get_Workbooks();
//	books.AttachDispatch(lpDisp);
//	
//
//	lpDisp = books.Open(path,
//		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
//		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
//		vtMissing, vtMissing, vtMissing, vtMissing);
//	book.AttachDispatch(lpDisp);
//
//	sheets.AttachDispatch(book.get_Worksheets());
//	CString pos;
//	for (size_t i = 0; i < shts.size(); i++)
//	{
//		int sc = shts[i];
//		lpDisp = sheets.get_Item(COleVariant((short)(sc + 1)));
//		
//		sheet.AttachDispatch(lpDisp);
//		//lpDisp = sheet.OLEObjects(vtMissing);
//		//COLEObjects oleOjbs;
//		//oleOjbs.AttachDispatch(lpDisp);
//		//COLEObject oleObj;
//		//lpDisp = oleOjbs.Item(_variant_t(L"BarCodeCtrl1"));
//		//oleObj.AttachDispatch(lpDisp);
//		pos.Format(L"%c%d", (L'A' + cols[i]), (1 + rows[i]));
//		//oleObj.put_Enabled(TRUE);
//		//oleObj.put_LinkedCell(pos);
//		
//		lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
//		range.AttachDispatch(lpDisp);
//		VARIANT var = range.get_Value2();
//		range.put_NumberFormatLocal(_variant_t(L"@"));
//		range.put_Value2(var);
//
//	}
//
//}

void ExcelVBAService::UpdateTemplate(std::shared_ptr<Json::JsonObject> jsonTemplate)
{
	Json::JsonObject& tempalteMap = jsonTemplate->asObject(L"template");
	Json::json_string& templatePath = jsonTemplate->asString(L"templatePath");
	Json::JsonArray& data = jsonTemplate->asArray(L"data");
	LoadExcel(templatePath.c_str());
	try
	{
		for (int i = 0, len = data.size(); i < len; ++i)
		{
			UpdateSheet(data.asArray(i), tempalteMap);
		}
	}
	catch (...)
	{
	}
	
	ReleaseExcel(templatePath.c_str());
}

void ExcelVBAService::LoadExcel(LPCTSTR lpPath)
{
	LPDISPATCH lpDisp = ExcelApp.get_Workbooks();
	books.AttachDispatch(lpDisp);


	lpDisp = books.Open(lpPath,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing);
	book.AttachDispatch(lpDisp);

	sheets.AttachDispatch(book.get_Worksheets());
}

void ExcelVBAService::ReleaseExcel(LPCTSTR lpPath)
{
	book.put_CheckCompatibility(FALSE);
	book.Save();

	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	book.Close(_variant_t(VARIANT_FALSE), _variant_t(lpPath), _variant_t(VARIANT_FALSE));

	book.ReleaseDispatch();
	books.Close();
	books.ReleaseDispatch();
}


void getGgxhType(Json::json_string& ggxh, Json::JsonObject& tempalteMap, CString& type){
	if (ggxh.length() > 2 && tempalteMap.isValid((LPTSTR)(LPCTSTR)(type = ggxh.substr(0, 3).c_str()))) {
		return;
	}
	else if (ggxh.length() > 1 && tempalteMap.isValid((LPTSTR)(LPCTSTR)(type = ggxh.substr(0, 2).c_str()))) {
		return;
	}
	else if (ggxh.length() > 0 && tempalteMap.isValid((LPTSTR)(LPCTSTR)(type = ggxh.substr(0, 1).c_str()))) {
		return;
	}
	type.Empty();
}

void ExcelVBAService::UpdateSheet(Json::JsonArray& row, Json::JsonObject& tempalteMap)
{
	CString strType;
	getGgxhType(row.asString(PcjhColumn::ggxh), tempalteMap, strType);
	LPDISPATCH lpDisp = sheets.get_Item(COleVariant(strType));
	sheet.AttachDispatch(lpDisp);
	CString col;
	Json::JsonObject& sheetMap = tempalteMap.asObject((LPTSTR)(LPCTSTR)strType);
	Json::json_string empty(L"");
	for (int i = 1, len = row.size(); i < len; ++i)
	{
		col.Format(L"col_%d", i);
		if (sheetMap.isValid((LPTSTR)(LPCTSTR)col))
		{
			Json::JsonArray& cells = sheetMap.asArray((LPTSTR)(LPCTSTR)col);
			if (row.typeOf(i) == Json::JsonTypeTag::jnull)
			{
				UpdateCells(cells, empty );
			}
			else
			{
				UpdateCells(cells, row.asString(i));
			}
			
		}
	}
	sheet.Copy(vtMissing, _variant_t(sheets.get_Item(_variant_t(sheets.get_Count()))));
	sheet.Activate();
}

PcjhColumn ExcelVBAService::getCol(Json::json_string& strCol)
{
	int index = strCol.find(L'#');
	Json::json_string strNum = strCol.substr(index + 1);
	return (PcjhColumn)_tstoi(strNum.c_str());
}

void ExcelVBAService::UpdateCells(Json::JsonArray& cells, Json::json_string& value)
{
	CString pos;
	LPDISPATCH lpDisp = NULL;
	for (int i = 0, len = cells.size(); i < len; ++i)
	{
		Json::JsonObject& cell = cells.asObject(i);
		pos.Format(L"%s%d", cell.asString(L"col").c_str(), cell.asInt(L"row"));
		lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
		range.AttachDispatch(lpDisp);
		range.put_NumberFormatLocal(_variant_t(L"@"));
		range.put_Value2(_variant_t(value.c_str()));
	}
}
