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
	bool Start();
	void Stop();
	void updateCell(CString& path,
		std::vector<int>& shts,
		std::vector<int>& rows,
		std::vector<int>& cols);
private:
	bool m_bStarted;
	CApplication ExcelApp;
	CWorkbooks books;
	CWorkbook book;
	CWorksheets sheets;
	CWorksheet sheet;
	CRange range;
};

