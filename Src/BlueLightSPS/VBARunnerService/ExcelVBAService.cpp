#include "stdafx.h"
#include "ExcelVBAService.h"
#include "COLEObjects.h"
#include "COLEObject.h"

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

void ExcelVBAService::updateCell(CString& path, std::vector<int>& shts, std::vector<int>& rows, std::vector<int>& cols)
{
	LPDISPATCH lpDisp = ExcelApp.get_Workbooks();
	books.AttachDispatch(lpDisp);
	

	lpDisp = books.Open(path,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
		vtMissing, vtMissing, vtMissing, vtMissing);
	book.AttachDispatch(lpDisp);

	sheets.AttachDispatch(book.get_Worksheets());
	CString pos;
	for (size_t i = 0; i < shts.size(); i++)
	{
		int sc = shts[i];
		lpDisp = sheets.get_Item(COleVariant((short)(sc + 1)));
		
		sheet.AttachDispatch(lpDisp);
		//lpDisp = sheet.OLEObjects(vtMissing);
		//COLEObjects oleOjbs;
		//oleOjbs.AttachDispatch(lpDisp);
		//COLEObject oleObj;
		//lpDisp = oleOjbs.Item(_variant_t(L"BarCodeCtrl1"));
		//oleObj.AttachDispatch(lpDisp);
		pos.Format(L"%c%d", (L'A' + cols[i]), (1 + rows[i]));
		//oleObj.put_Enabled(TRUE);
		//oleObj.put_LinkedCell(pos);
		
		lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
		range.AttachDispatch(lpDisp);
		VARIANT var = range.get_Value2();
		range.put_NumberFormatLocal(_variant_t(L"@"));
		range.put_Value2(var);
		sheet.Copy(vtMissing, _variant_t(sheets.get_Item(_variant_t(sheets.get_Count()))));
		sheet.Activate();
	}
	book.put_CheckCompatibility(FALSE);
	book.Save();

	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	book.Close(_variant_t(VARIANT_FALSE), _variant_t(path), _variant_t(VARIANT_FALSE));

	book.ReleaseDispatch();
	books.Close();
	books.ReleaseDispatch();
}
