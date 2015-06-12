// VBARunner.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "VBARunner.h"
#include "com_vbarunner_VBAExcel.h"
#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorksheet.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"
#include <comutil.h>
#include "LogFile.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CVBARunnerApp

BEGIN_MESSAGE_MAP(CVBARunnerApp, CWinApp)
END_MESSAGE_MAP()
#define WM_VBA_SERVICE_START	(WM_APP + 15982) 
#define WM_VBA_SERVICE_STOP		(WM_APP + 15983)

// CVBARunnerApp construction

CVBARunnerApp::CVBARunnerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CVBARunnerApp object

CVBARunnerApp theApp;


// CVBARunnerApp initialization

BOOL CVBARunnerApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//CApplication ExcelApp;
//CWorkbooks books;
//CWorkbook book;
//CWorksheets sheets;
//CWorksheet sheet;
//CRange range;


wchar_t* jstringTostring(JNIEnv* env, jstring jstr)
{
	wchar_t* rtn = NULL;
	jboolean jc = false;
	return (wchar_t*)env->GetStringChars(jstr, &jc);
	/*jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-16le");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
	rtn = (wchar_t*)malloc(alen + 2);
	memcpy(rtn, ba, alen);
	rtn[alen] = 0;
	rtn[alen + 1] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;*/
}




JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_start(JNIEnv * jvm, jobject obj)
{
	HWND hWnd = ::FindWindow(NULL, L"VBARunnerService");

	::SendMessage(hWnd, WM_VBA_SERVICE_START, NULL, NULL);
	//::CoInitialize(NULL);
	//DWORD dw = GetLastError();
	//Log(L"CoInitialize %d", dw);
	//if (!ExcelApp.CreateDispatch(_T("Excel.Application"), NULL))
	//{
	//	dw = GetLastError();
	//	Log(L"CoInitialize %d", dw);
	//	
	//}
}

JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_stop(JNIEnv * jvm, jobject obj)
{
	HWND hWnd = ::FindWindow(NULL, L"VBARunnerService");
	::SendMessage(hWnd, WM_VBA_SERVICE_STOP, NULL, NULL);
}

JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_runVBABarcode(JNIEnv * jvm, jobject obj, jstring jsonObj, jstring guid)
{
	CString strJson = jstringTostring(jvm, jsonObj);
	CString strGuid = jstringTostring(jvm, guid);
	strGuid = CString("Global\\") + strGuid;
	strJson += L"#" + strGuid;
	HWND hWnd = ::FindWindow(NULL, L"VBARunnerService");
	COPYDATASTRUCT stCpData = {};
	stCpData.cbData = 2 * strJson.GetLength();
	stCpData.lpData = (LPTSTR)(LPCTSTR)strJson;
	stCpData.dwData = 0;
	Log(L"path %d %s", stCpData.cbData, strJson);
	
	::SendMessage(hWnd, WM_COPYDATA, (WPARAM)::GetDesktopWindow(), (LPARAM)&stCpData);
	
	HANDLE h = OpenEvent(EVENT_ALL_ACCESS, NULL, strGuid);
	Log(L"h %d", h);
	WaitForSingleObject(h, INFINITE);

	//Log(L"path %s", str);
	//LPDISPATCH lpDisp = ExcelApp.get_Workbooks();
	//Log(L"get_Workbooks %d", lpDisp);
	//books.AttachDispatch(lpDisp);
	//Log(L"get_Workbooks AttachDispatch OK");

	//lpDisp = books.Open(str,
	//	vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
	//	vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
	//	vtMissing, vtMissing, vtMissing, vtMissing);
	//Log(L"Open %d", lpDisp);
	//sheets.AttachDispatch(book.get_Worksheets());

	//jboolean jb = false;
	//int count = jvm->GetArrayLength(shts);
	//Log(L"count %d", count);
	////Log(L"count %d", count);
	//jint* jias = jvm->GetIntArrayElements(shts, &jb);
	//jint* jiar = jvm->GetIntArrayElements(rows, &jb);
	//jint* jiac = jvm->GetIntArrayElements(cols, &jb);

	//for (size_t i = 0; i < count; i++)
	//{
	//	Log(L"sheet %d", jias[i] + 1);
	//	lpDisp = sheets.get_Item(COleVariant((short)(jias[i] + 1)));
	//	sheet.AttachDispatch(lpDisp);
	//	wchar_t pos[3] = {};
	//	pos[0] = L'A' + jiac[i];
	//	pos[1] = L'1' + jiar[i];
	//	AfxMessageBox(pos);
	//	lpDisp = sheet.get_Range(_variant_t(pos), _variant_t(pos));
	//	range.AttachDispatch(lpDisp);
	//	VARIANT var = range.get_Value2();
	//	range.put_Value2(var);
	//}

	//book.Save();

	//sheet.ReleaseDispatch();
	//sheets.ReleaseDispatch();
	//book.Close(_variant_t(VARIANT_FALSE), _variant_t(str), _variant_t(VARIANT_FALSE));

	//book.ReleaseDispatch();
	//books.Close();
	//books.ReleaseDispatch();
}