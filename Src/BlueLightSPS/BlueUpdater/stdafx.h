// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <atlstr.h>
using namespace ATL;

#define HAS_NEW_VERSION	L"Global\\blueHasNewVersion"
#define HAS_NO_VERSION	L"Global\\blueHasNoVersion"
#define NEED_UPDATE	L"Global\\blueNeedUpdate"
#define NOT_UPDATE	L"Global\\blueNotUpdate"
// TODO: reference additional headers your program requires here
