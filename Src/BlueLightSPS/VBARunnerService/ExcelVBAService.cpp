#include "stdafx.h"
#include "ExcelVBAService.h"
#include "COLEObjects.h"
#include "COLEObject.h"
#include "JsonFactory.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "JsonType.h"
#include "Cnterior.h"
#include "CommonDefine.h"
static CApplication ExcelApp;
static CWorkbooks books;
static CWorkbook book;
static CWorksheets sheets;
static CWorksheet sheet;
static CRange range;
static Cnterior nterior;




class ExporterUtil {
public:
	static int CompareNoCase(Json::json_string& s1, LPCTSTR s2){
		return CString(s2).CompareNoCase(s1.c_str());
	}

	static bool validatePlanHighlight(nsPlan::Column_en col, Json::JsonArray& row){
		CString ggxh = row.asString(nsPlan::ggxh).c_str();
		if (GGisS(ggxh)){
			if (0 == CompareNoCase(row.asString(nsPlan::zdqdy), L"220v") &&
				0 != CompareNoCase(row.asString(nsPlan::zdqxh), L"DZE-14EB2")){
				if (col == nsPlan::zdqxh || col == nsPlan::zdqdy){
					return true;
				}
			}
			else if (0 == CompareNoCase(row.asString(nsPlan::zdqdy), L"DC110v") &&
				0 != CompareNoCase(row.asString(nsPlan::zdqxh), L"DZE-14EA")){
				if (col == nsPlan::zdqxh || col == nsPlan::zdqdy){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::yylgg), L"400*5*10*16")){
				if (col == nsPlan::yylgg){
					return true;
				}
			}
		}
		else if (GGisTA(ggxh)){
			if (0 != CompareNoCase(row.asString(nsPlan::zdqdy), L"DC110v")){
				if (col == nsPlan::zdqdy){
					return true;
				}
			}

			if (0 == CompareNoCase(row.asString(nsPlan::zdqxh), L"WYT-TA.3£¨10»É£©")){
				if (col == nsPlan::zdqxh){
					return true;
				}
			}
			else if (0 == CompareNoCase(row.asString(nsPlan::zdqxh), L"WYT-TA.3£¨12»É£©")){
				if (col == nsPlan::zdqxh){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::yylgg), L"400*5*10*16")){
				if (col == nsPlan::yylgg){
					return true;
				}
			}
		}
		else if (GGisU(ggxh)){
			if (0 != CompareNoCase(row.asString(nsPlan::zdqdy), L"DC110v")){
				if (col == nsPlan::zdqdy){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::zjdy), L"AC380V")){
				if (col == nsPlan::zjdy){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::yylgg), L"480*7*12*18")){
				if (col == nsPlan::yylgg){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::jf), L"ÓÐ")){
				if (col == nsPlan::jf){
					return true;
				}
			}

			if (0 != CompareNoCase(row.asString(nsPlan::bmqxh), L"º£1387")){
				if (col == nsPlan::bmqxh){
					return true;
				}
			}
		}
		return false;
	}


};

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
		LPDISPATCH lpDisp = sheets.get_Item(_variant_t(short(1)));
		sheet.AttachDispatch(lpDisp);
		sheet.Activate();
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
	int id = _tstoi(row.asString(0).c_str());
	row.erase(0);
	getGgxhType(row.asString(nsPlan::Column_en::ggxh), tempalteMap, strType);
	LPDISPATCH lpDisp = sheets.get_Item(COleVariant(strType));
	sheet.AttachDispatch(lpDisp);
	sheet.Copy(vtMissing, _variant_t(sheets.get_Item(_variant_t(sheets.get_Count()))));
	lpDisp = sheets.get_Item(_variant_t(sheets.get_Count()));
	sheet.AttachDispatch(lpDisp);
	CString col;
	Json::JsonObject& sheetMap = tempalteMap.asObject((LPTSTR)(LPCTSTR)strType);
	Json::json_string empty(L"");
	bool highLight = false;
	bool highLightTmp = false;
	for (int i = 0, len = row.size(); i < len; ++i)
	{
		col.Format(L"col_%d", i + 1);
		if (sheetMap.isValid((LPTSTR)(LPCTSTR)col))
		{
			Json::JsonArray& cells = sheetMap.asArray((LPTSTR)(LPCTSTR)col);

			if (row.typeOf(i) == Json::JsonTypeTag::jnull)
			{
				row.items()[i].reset(Json::JsonFactory::createString(L""));
			}
			highLightTmp = ExporterUtil::validatePlanHighlight((nsPlan::Column_en)i, row);
			if (highLightTmp)
			{
				highLight = true;
			}
			UpdateCells(cells, row.asString(i), highLightTmp);
		}
	}
	if (highLight)
	{
		CString pos("A1");
		lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
		range.AttachDispatch(lpDisp);
		nterior.AttachDispatch(range.get_Interior());
		nterior.put_Color(COleVariant((long)RGB(255, 242, 0)));
	}
	//sheet.Activate();
}

nsPlan::Column_en ExcelVBAService::getCol(Json::json_string& strCol)
{
	int index = strCol.find(L'#');
	Json::json_string strNum = strCol.substr(index + 1);
	return (nsPlan::Column_en)_tstoi(strNum.c_str());
}

void ExcelVBAService::UpdateCells(Json::JsonArray& cells, Json::json_string& value, bool bHighlight)
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
		if (bHighlight)
		{
			nterior.AttachDispatch(range.get_Interior());
			nterior.put_Color(COleVariant((long)RGB(255, 242, 0)));
			//nterior.put_ColorIndex(COleVariant((long)RGB(255, 242, 0)));
		}
	}
}
