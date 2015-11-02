#include "stdafx.h"
#include <ShellAPI.h>
#include "ClientUpdater.h"
#include "HostConfiguration.h"
#include "StringOutputStream.h"
#include "Version.h"
#include "FileOutputStream.h"
#include "Util.h"
ClientUpdater::ClientUpdater(HWND hWnd, CString strModulePath)
	:m_pHttp(new CWinHttpImpl(hWnd))
	, m_hWnd(hWnd)
	, m_strModulePath(strModulePath)
{

}


ClientUpdater::~ClientUpdater()
{

}

void ClientUpdater::Update()
{
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_pHttp.get(), new CBoolParser());
	std::string strServerVersion;
	class CVersionCheckListener : public CPromise<bool>::IHttpResponse{
		CONSTRUCTOR_2(CVersionCheckListener, ClientUpdater&, updater, std::string&, strServerVersion);
	public:
		virtual void OnSuccess(bool& ret){
			CVersion version(m_updater.m_strModulePath);
			CString strVersion;
			Util_Tools::Util::ANSIToUtf16LE(m_strServerVersion, strVersion);
			if (ret && version.IsNewVersion(strVersion))
			{
				HANDLE hEvent = OpenEvent(NULL, NULL, HAS_NEW_VERSION);
				if (NULL != hEvent)
				{
					SetEvent(hEvent);
				}

				bool update = true;
				HANDLE hUpdateSigns[] = { OpenEvent(NULL, NULL, NEED_UPDATE),
					OpenEvent(NULL, NULL, NEED_UPDATE) };
				if (NULL != hUpdateSigns[0] && NULL != hUpdateSigns[1])
				{
					DWORD dwRet = WaitForMultipleObjects(2, hUpdateSigns, FALSE, INFINITE);
					if (0 == dwRet - WAIT_OBJECT_0){
						update = false;
					}
		
				}
				if (update)
				{
					m_updater.BeginUpdate(strVersion);
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
	promise->then(new CVersionCheckListener(*this, strServerVersion));
	CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/version.txt";
	m_pHttp->Download(
		(LPCTSTR)url, 
		promise->GetId(),
		attr, 
		std::shared_ptr<IHttp::IOutputStream>(new CStringOutputStream(strServerVersion)));
}

void ClientUpdater::Exit()
{
	HANDLE hEvent = OpenEvent(NULL, NULL, HAS_NO_VERSION);
	if (NULL != hEvent)
	{
		SetEvent(hEvent);
	}
	::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
}

void ClientUpdater::BeginUpdate(CString& strVersion)
{
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_pHttp.get(), new CBoolParser());
	std::string strServerVersion;
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
				m_updater.Exit();
			}
		}
		virtual void OnFailed(){
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
	}
	else
	{
		promise->then(new CDownLoadListener(*this, m_bisZipExeUpdated));
		CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/zlibwapi.dll";
		m_pHttp->Download(
			(LPCTSTR)url,
			promise->GetId(),
			attr,
			std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(m_strModulePath + L"/zlibwapi.dll")));

	}

	if (PathFileExists(m_strModulePath + L"\\BlueLightPLM(" + strVersion + L").zip"))
	{
		m_bIsPackageUpdated = true;
	}
	else
	{
		promise->then(new CDownLoadListener(*this, m_bisZipExeUpdated));
		CString url = L"http://" + hostConfig.getHost() + L":8080/BlueRay/resource/package/BlueLightPLM(" + strVersion + L").zip";
		m_pHttp->Download(
			(LPCTSTR)url,
			promise->GetId(),
			attr,
			std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(m_strModulePath + L"/BlueLightPLM.zip")));
	}
	
}

void ClientUpdater::UpdateLocalFile()
{
	if (m_bisZipExeUpdated && m_bIsZipDllUpdated && m_bIsPackageUpdated){
		ShellExecute(NULL, L"open", m_strModulePath + L"/miniunz.exe", L"BlueLightPLM.zip -o", m_strModulePath, SW_HIDE);
	}
}
