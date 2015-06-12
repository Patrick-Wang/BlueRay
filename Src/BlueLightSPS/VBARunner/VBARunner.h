// VBARunner.h : main header file for the VBARunner DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVBARunnerApp
// See VBARunner.cpp for the implementation of this class
//

class CVBARunnerApp : public CWinApp
{
public:
	CVBARunnerApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
