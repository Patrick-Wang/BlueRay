#include "stdafx.h"
#include "ExcelVBAService.h"



static CApplication ExcelApp;
static CWorkbooks books;
static CWorkbook book;
static CWorksheets sheets;
static CWorksheet sheet;
static CRange range;

ExcelVBAService::ExcelVBAService()
{
}


ExcelVBAService::~ExcelVBAService()
{
}

void ExcelVBAService::Start()
{
	if (!ExcelApp.CreateDispatch(_T("Excel.Application"), NULL))
	{
		DWORD dw = GetLastError();
		AfxMessageBox(_T("����Excel������ʧ��!"));
	}
}

void ExcelVBAService::Stop()
{
	ExcelApp.Quit();
}

void ExcelVBAService::updateCell(CString& path, std::vector<int>& shts, std::vector<int>& rows, std::vector<int>& cols)
{
	LPDISPATCH lpDisp = ExcelApp.get_Workbooks();
	ExcelApp.put_Width(100);
	ExcelApp.put_Width(100);
	books.AttachDispatch(lpDisp);
	

	lpDisp = books.Open(path,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing);
	book.AttachDispatch(lpDisp);

	sheets.AttachDispatch(book.get_Worksheets());

	for (size_t i = 0; i < shts.size(); i++)
	{
		int sc = shts[i];
		lpDisp = sheets.get_Item(COleVariant((short)(sc + 1)));
		sheet.AttachDispatch(lpDisp);
		wchar_t pos[3] = {};
		pos[0] = L'A' + cols[i];
		pos[1] = L'1' + rows[i];
		lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
		range.AttachDispatch(lpDisp);
		VARIANT var = range.get_Value2();
		range.put_Value2(var);
	}

	book.Save();

	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	book.Close(_variant_t(VARIANT_FALSE), _variant_t(path), _variant_t(VARIANT_FALSE));

	book.ReleaseDispatch();
	books.Close();
	books.ReleaseDispatch();
}