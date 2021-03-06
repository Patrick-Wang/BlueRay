///////////////////////////////////////////////////////////
// Description : Write Log for VES Extent COM
// Date : 2009/01/13
// Author : SNDC-zheng.shy
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LogFile.h"
#include <atlstr.h>
#ifndef DEBUG_LOG_FILE
using namespace ATL;
#include <fstream>

///////////////////////////////////////////////////////////
// Write Log Text to file
//////////////////////////////////////////////////////////
void LogFile(CString strFileName , CString strMsg)
{		
	using namespace std;
	CString strLogPath(_T("E:\\LOG\\"));

	if (strFileName.IsEmpty())
	{
#ifdef LOG_ADVANCEDMODE
		CString strProcess;
		DWORD dwSize = GetModuleFileName(NULL, strProcess.GetBuffer(MAX_PATH), MAX_PATH);
		strProcess.ReleaseBuffer();
		if (dwSize)
		{
			int iIndex = strProcess.ReverseFind(_T('\\'));
			int iPos = strProcess.GetLength() - iIndex - 1;
			strLogPath.Append(strProcess.Right(iPos));
			strLogPath.AppendFormat(_T("_%d.txt"), GetCurrentProcessId());
		}
#else
		strLogPath.Append(DEFAULT_LOG_FILENAME);
#endif
	}
	else
	{
		strLogPath.Append(strFileName);
	}
	
	wofstream fsLogFile(strLogPath, ios_base::app);
	if (fsLogFile.is_open())
	{
		SYSTEMTIME stCurrentTime;
		::SecureZeroMemory(&stCurrentTime, sizeof(SYSTEMTIME));
		::GetLocalTime(&stCurrentTime);
		
		//Log current time: Hour:Minute:Second:Millisecond YourLogText
		fsLogFile.width(2);
		fsLogFile << stCurrentTime.wHour << _T(":");
		fsLogFile << stCurrentTime.wMinute << _T(":");
		fsLogFile << stCurrentTime.wSecond << _T(":");
		fsLogFile.width(3);
		fsLogFile << stCurrentTime.wMilliseconds<< _T(" => ");
		fsLogFile.width();
#ifdef LOG_ADVANCEDMODE
		fsLogFile << _T("ProcessId = ") << GetCurrentProcessId();
		fsLogFile << _T(" ThreadId = ") << GetCurrentThreadId() << endl;
#endif
		fsLogFile<< strMsg.GetString() << endl;
#ifdef LOG_ADVANCEDMODE
		fsLogFile<<endl;
#endif
		fsLogFile.close();
	}
}

///////////////////////////////////////////////////////////
// Log with user custom format text
///////////////////////////////////////////////////////////
void Log(CString strFormat, ...)
{
	CString strFileName;
	CString strMsg;
	va_list argList;
	va_start(argList, strFormat);
	strMsg.FormatV(strFormat, argList);
	va_end(argList);
	LogFile(strFileName, strMsg);
}

///////////////////////////////////////////////////////////
// Log with special path and format
///////////////////////////////////////////////////////////
void LogWithPath(CString strFileName, CString strFormat, ...)
{
	CString strMsg;
	va_list argList;
	va_start(argList, strFormat);
	strMsg.FormatV(strFormat, argList);
	va_end(argList);
	LogFile(strFileName, strMsg);
}

#else
void Log(...)
{

}
void LogWithPath(...)
{

}

#endif // DEBUG_LOG_FILE