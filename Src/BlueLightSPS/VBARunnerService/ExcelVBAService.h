#pragma once
#include <vector>
#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorksheet.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"

class ExcelVBAService
{
public:
	ExcelVBAService();
	~ExcelVBAService();
	static void Start();
	static void Stop();
	static void updateCell(CString& path,
		std::vector<int>& shts,
		std::vector<int>& rows,
		std::vector<int>& cols);

};

