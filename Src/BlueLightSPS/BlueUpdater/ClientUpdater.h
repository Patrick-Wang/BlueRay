#pragma once

#include "IHttp.h"
#include "WinHttpImpl.h"
#include "Promise.h"

#define WM_EXIT	WM_APP + 10026

class ClientUpdater
{
public:
	ClientUpdater(HWND hWnd, CString strModulePath);
	~ClientUpdater();
	void Update();
private:
	void Exit();
	void BeginUpdate();
	void UpdateLocalFile();
private:
	auto_ptr<IHttp> m_pHttp;
	HWND m_hWnd;
	CString m_strModulePath;
	bool m_bIsPackageUpdated;
	bool m_bisZipExeUpdated;
	bool m_bIsZipDllUpdated;
	std::string m_strServerVersion;
	CString m_clServerVersion;
};

