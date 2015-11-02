#include "stdafx.h"
#include "UpdaterProxy.h"

#define HAS_NEW_VERSION	L"Global\\blueHasNewVersion"
#define HAS_NO_VERSION	L"Global\\blueHasNoVersion"
#define NEED_UPDATE	L"Global\\blueNeedUpdate"
#define NOT_UPDATE	L"Global\\blueNotUpdate"

CUpdaterProxy::CUpdaterProxy()
{
	CString path;
	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
	path.ReleaseBuffer();
	CString basePath = path.Left(path.ReverseFind(L'\\'));

	if (PathFileExists(basePath + L"\\BlueUpdater.exe"))
	{
		if (PathFileExists(basePath + L"\\OnlineSetup.exe"))
		{
			DeleteFile(basePath + L"\\OnlineSetup.exe");
		}
		_trename(basePath + L"\\BlueUpdater.exe", basePath + L"\\OnlineSetup.exe");
	}

	CString validatorPath = basePath + L"\\OnlineSetup.exe";
	if (PathFileExists(validatorPath))
	{
		SHELLEXECUTEINFO ShExecInfo = { 0 };
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = validatorPath;
		ShExecInfo.lpParameters = L"";
		ShExecInfo.lpDirectory = basePath;
		ShExecInfo.nShow = SW_HIDE;
		ShExecInfo.hInstApp = NULL;
		ShellExecuteEx(&ShExecInfo);
		hHasVersionSigns[2] = ShExecInfo.hProcess;
		hUpdate = CreateEvent(NULL, FALSE, FALSE, NEED_UPDATE);
		hNotUpdate = CreateEvent(NULL, FALSE, FALSE, NOT_UPDATE);
		hHasVersionSigns[0] = CreateEvent(NULL, FALSE, FALSE, HAS_NEW_VERSION);
		hHasVersionSigns[1] = CreateEvent(NULL, FALSE, FALSE, HAS_NO_VERSION);
	}
	
}


CUpdaterProxy::~CUpdaterProxy()
{
	CloseHandle(hUpdate);
	CloseHandle(hNotUpdate);
	CloseHandle(hHasVersionSigns[0]);
	CloseHandle(hHasVersionSigns[1]);
}

bool CUpdaterProxy::HasNewVersion()
{
	if (NULL != hHasVersionSigns[0] && NULL != hHasVersionSigns[1])
	{
		DWORD dwRet = WaitForMultipleObjects(2, hHasVersionSigns, FALSE, INFINITE);
		if (0 == dwRet - WAIT_OBJECT_0){
			return true;
		}
	}
	return false;
}

void CUpdaterProxy::DoUpdate()
{
	SetEvent(hUpdate);
}

void CUpdaterProxy::CancelUpdate()
{
	SetEvent(hNotUpdate);
}
