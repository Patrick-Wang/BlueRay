#include "stdafx.h"
#include <ShellAPI.h>
#include "ClientUpdater.h"
#include "HostConfiguration.h"
#include "StringOutputStream.h"
#include "Version.h"
#include "FileOutputStream.h"
#include "Util.h"
ClientUpdater::ClientUpdater(HWND hWnd, CString strModulePath)
	: m_pHttp(new CWinHttpImpl())
	, m_hWnd(hWnd)
	, m_strModulePath(strModulePath)
{
	CWinHttpImpl::SetThreadWindow(hWnd);
}


ClientUpdater::~ClientUpdater()
{

}

void ClientUpdater::Update()
{
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_pHttp.get(), new CBoolParser());

	class CVersionCheckListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CVersionCheckListener, ClientUpdater&, updater, std::string&, strServerVersion);
	public:
		virtual void OnSuccess(bool& ret){
			CVersion version(m_updater.m_strModulePath);
			Util_Tools::Util::ANSIToUtf16LE(m_strServerVersion, m_updater.m_clServerVersion);
			if (ret && version.IsNewVersion(m_updater.m_clServerVersion))
			{
				HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, HAS_NEW_VERSION);
				if (NULL != hEvent)
				{
					//MessageBox(NULL, L"", L"HAS_NEW_VERSION", MB_OK);
					SetEvent(hEvent);
				}


				bool update = true;
				HANDLE hUpdateSigns[] = { OpenEvent(EVENT_ALL_ACCESS, FALSE, NEED_UPDATE),
					OpenEvent(EVENT_ALL_ACCESS, FALSE, NOT_UPDATE) };
				if (NULL != hUpdateSigns[0] && NULL != hUpdateSigns[1])
				{
					//MessageBox(NULL, L"", L"NEED_UPDATE  NOT_UPDATE", MB_OK);
					DWORD dwRet = WaitForMultipleObjects(2, hUpdateSigns, FALSE, INFINITE);
					if (1 == dwRet - WAIT_OBJECT_0){
						update = false;
					}
		
				}
				if (update)
				{
					m_updater.BeginUpdate();
				}
				else{
					m_updater.Exit();
				}
			}
			else{
				m_updater.Exit();
			}
		}
		virtual void OnFailed(){
			m_updater.Exit();
		}
	};

	CHostConfiguration hostConfig(m_strModulePath);
	std::map<CString, CString> attr;
	promise->then(new CVersionCheckListener(*this, m_strServerVersion));
	CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/version.txt";
	m_pHttp->Download(
		(LPCTSTR)url, 
		promise->GetId(),
		attr, 
		std::shared_ptr<IHttp::IOutputStream>(new CStringOutputStream(m_strServerVersion)));
}

void ClientUpdater::Exit()
{
	HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, HAS_NO_VERSION);
	if (NULL != hEvent)
	{
		SetEvent(hEvent);
	}
	PostMessage(m_hWnd, WM_CLOSE, 0, 0);
}

void ClientUpdater::BeginUpdate()
{
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_pHttp.get(), new CBoolParser());
	class CDownLoadListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CDownLoadListener, ClientUpdater&, updater, bool&, isUpdated);
	public:
		virtual void OnSuccess(bool& ret){
			CVersion version(m_updater.m_strModulePath);
			if (ret)
			{
				m_isUpdated = true;
				m_updater.UpdateLocalFile();
			}
			else
			{
				MessageBox(m_updater.m_hWnd, L"文件下载失败！", L"更新", MB_OK | MB_ICONWARNING);
				m_updater.Exit();
			}
		}
		virtual void OnFailed(){
			MessageBox(m_updater.m_hWnd, L"网络异常，系统更新失败！", L"更新", MB_OK | MB_ICONWARNING);
			m_updater.Exit();
		}
	};

	CHostConfiguration hostConfig(m_strModulePath);
	std::map<CString, CString> attr;


	m_bIsPackageUpdated = false;
	m_bIsZipDllUpdated = false;
	m_bisZipExeUpdated = false;
	if (PathFileExists(m_strModulePath + L"\\miniunz.exe"))
	{
		m_bisZipExeUpdated = true;
		UpdateLocalFile();
	}
	else
	{
		promise->then(new CDownLoadListener(*this, m_bisZipExeUpdated));
		CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/miniunz.exe";
		m_pHttp->Download(
			(LPCTSTR)url,
			promise->GetId(),
			attr,
			std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(m_strModulePath + L"/miniunz.exe")));
	}

	if (PathFileExists(m_strModulePath + L"\\zlibwapi.dll"))
	{
		m_bIsZipDllUpdated = true;
		UpdateLocalFile();
	}
	else
	{
		promise->then(new CDownLoadListener(*this, m_bIsZipDllUpdated));
		CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/zlibwapi.dll";
		m_pHttp->Download(
			(LPCTSTR)url,
			promise->GetId(),
			attr,
			std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(m_strModulePath + L"/zlibwapi.dll")));

	}

	if (PathFileExists(m_strModulePath + L"\\BlueLightPLM(" + m_clServerVersion + L").zip"))
	{
		m_bIsPackageUpdated = true;
		UpdateLocalFile();
	}
	else
	{
		promise->then(new CDownLoadListener(*this, m_bIsPackageUpdated));
		CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/BlueLightPLM(" + m_clServerVersion + L").zip";
		m_pHttp->Download(
			(LPCTSTR)url,
			promise->GetId(),
			attr,
			std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(m_strModulePath + L"/BlueLightPLM(" + m_clServerVersion + L").zip")));
	}
	
}

void ClientUpdater::UpdateLocalFile()
{
	if (m_bisZipExeUpdated && m_bIsZipDllUpdated && m_bIsPackageUpdated){
		CString strFile = m_strModulePath + L"\\miniunz.exe";
		CString strParam = m_strModulePath + L"\\BlueLightPLM(" + m_clServerVersion + L").zip -o";
		SHELLEXECUTEINFO ShExecInfo = { 0 };
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = (LPCTSTR)strFile;
		ShExecInfo.lpParameters = (LPCTSTR)strParam;
		ShExecInfo.lpDirectory = (LPCTSTR)m_strModulePath;
		ShExecInfo.nShow = SW_HIDE;
		ShExecInfo.hInstApp = NULL;
		ShellExecuteEx(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		DeleteFile(m_strModulePath + L"\\BlueLightPLM(" + m_clServerVersion + L").zip");
		MessageBox(NULL, L"系统更新成功！", L"更新", MB_OK | MB_SYSTEMMODAL | MB_SETFOREGROUND | MB_ICONINFORMATION);
		Exit();
	}
}
