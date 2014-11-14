
// Blue.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Blue.h"
#include "BlueDlg.h"
#include "LoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBlueApp

BEGIN_MESSAGE_MAP(CBlueApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CBlueApp construction

void CBlueApp::ShutDownGDIPlus( void )
{
	if (m_gdiplusToken)
	{
		Gdiplus::GdiplusShutdown(m_gdiplusToken);
	}
}

void CBlueApp::StartGDIPlus( void )
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput; 
	ULONG_PTR ulGdiToken; 

	ulGdiToken = Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput,NULL);

}

CBlueApp::CBlueApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CBlueApp object

CBlueApp theApp;


// CBlueApp initialization

BOOL CBlueApp::InitInstance()
{
	StartGDIPlus();
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	CLoginDlg loginDlg;

	INT_PTR nResponse = loginDlg.DoModal();
	if (nResponse == IDOK)
	{
		CBlueDlg dlg;
		m_pMainWnd = &dlg;
		nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



int CBlueApp::ExitInstance()
{
	ShutDownGDIPlus();
	// TODO: Add your specialized code here and/or call the base class

	return CWinApp::ExitInstance();
}
