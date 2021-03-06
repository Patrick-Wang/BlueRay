///////////////////////////////////////////////
// Description : Write Log for VES Extent COM
// Date : 2009/01/13
// Author : SNDC-zheng.shy
///////////////////////////////////////////////
#ifndef COMMONUTILS_LOGFILE_H
#define COMMONUTILS_LOGFILE_H

///////////////////////////////////////////////////////////
// Add definition macro DEBUG_LOG_FILE in project
// [Properties]->[Configuration]->[C/C++]->[Preprocessor]->[Preprocessor Definitions]
//
// Notice! This must be defined in [Unicode Release with Log] only!!!
//
// Default Log Path is: C:\VES LOG\VESDefault.txt
///////////////////////////////////////////////////////////
// Log with user custom format text
// e.g.:
// Log(_T("some text"));
// Log(_T("%d,%f"),intA,floatB)
///////////////////////////////////////////////////////////
// Log with special path and format
// e.g.:
// LogWithPath(_T("VESXXX.txt"),_T("some text"));
// LogWithPath(_T("VESXXX.txt"),_T("%d,%f"),intA,floatB);
///////////////////////////////////////////////////////////

#ifndef DEBUG_LOG_FILE

#define LOG_ADVANCEDMODE

#define DEFAULT_LOG_FILENAME _T("VESDefault.txt")  //set your default log path here: "VESXXX.txt"

#include <atlstr.h>

void Log(CString strFormat, ...);
void LogWithPath(CString strFileName, CString strFormat, ...);

#else
void Log(...);
void LogWithPath(...);
#endif

#endif // COMMONUTILS_LOGFILE_H