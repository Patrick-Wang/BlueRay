
// Blue.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBlueApp:
// See Blue.cpp for the implementation of this class
//

class CBlueApp : public CWinApp
{
public:
	CBlueApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	void CBlueApp::ShutDownGDIPlus( void );

	void CBlueApp::StartGDIPlus( void );

	ULONG_PTR	m_gdiplusToken;
	virtual int ExitInstance();
};

extern CBlueApp theApp;