#pragma once
#include <vector>
#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorksheet.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"
#include <memory>
#include "JsonFactory.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "JsonType.h"
#include "CommonDefine.h"
class ExcelVBAService
{
public:
	ExcelVBAService();
	~ExcelVBAService();
	bool Start();
	void Stop();
	//void updateCell(CString& path,
	//	std::vector<int>& shts,
	//	std::vector<int>& rows,
	//	std::vector<int>& cols);
	void UpdateTemplate(std::shared_ptr<Json::JsonObject> jsonTemplate);
private:
	void UpdateSheet(Json::JsonArray& row, Json::JsonObject& tempalteMap);
	void UpdateCells(Json::JsonArray& cells, Json::json_string& value, bool bHighlight);
	void LoadExcel(LPCTSTR lpPath);
	void ReleaseExcel(LPCTSTR lpPath);
	nsPlan::Column_en getCol(Json::json_string& strCol);
private:
	bool m_bStarted;
	CApplication ExcelApp;
	CWorkbooks books;
	CWorkbook book;
	CWorksheets sheets;
	CWorksheet sheet;
	CRange range;
};

