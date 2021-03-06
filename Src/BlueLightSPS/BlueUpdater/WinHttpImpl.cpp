#include "stdafx.h"
#include "WinHttpImpl.h"
#include <Winhttp.h>
#include "Encoding.h"
#define WM_SUCCESS	WM_APP + 27657
#define WM_FAILED	WM_APP + 27658
#define WM_THREAD_COMPLETE	WM_APP + 27659

typedef struct tagSuccess_t{
	int id;
	CString ret;
}Success_t;

//HWND CWinHttpImpl::m_pWnd;
//std::vector<CWinHttpImpl*> CWinHttpImpl::m_instances;
//WNDPROC CWinHttpImpl::m_lpfnOldProc = NULL;

CWinHttpImpl::CWinHttpImpl()
{
	//m_instances.push_back(this);
	d_OnThreadComplete += std::make_pair(this, &CWinHttpImpl::OnThreadComplete);
}

CWinHttpImpl::~CWinHttpImpl()
{
	d_OnThreadComplete -= std::make_pair(this, &CWinHttpImpl::OnThreadComplete);
	//std::vector<CWinHttpImpl*>::iterator result = find(m_instances.begin(), m_instances.end(), this);
	//if (result != m_instances.end())
	//{
	//	m_instances.erase(result);
	//}
}


void CWinHttpImpl::MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& url)
{
	for (std::map<CString, CString>::iterator it = mapAttr.begin(); it != mapAttr.end(); ++it)
	{
		if (url.IsEmpty())
		{
			url += _T("?") + it->first + "=" + it->second;
		}
		else
		{
			url += _T("&") + it->first + "=" + it->second;
		}
	}
	url = lpAddr + url;
}

void CWinHttpImpl::MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url)
{
	url = lpAddr;
	for (int i = 0; i < rest->size(); ++i)
	{
		url += _T("/") + (*rest)[i];
	}
}


void CWinHttpImpl::DoUpload(CString strUrl, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IInputStream> pStream, GUID guid)
{
	DWORD dwBytesWritten = 0;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	strUrl.Replace(L"http://", L"");
	int index = strUrl.Find(_T("/"));
	CString strHostPort = strUrl.Left(index);
	strUrl = strUrl.Right(strUrl.GetLength() - index - 1);
	index = strHostPort.Find(_T(":"));
	CString strHost = strHostPort.Left(index);
	int port = _tstoi(strHostPort.Right(strHostPort.GetLength() - index - 1));


	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS,
		0);

	WinHttpSetTimeouts(hSession, 0, 0, 0, 0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect(hSession, strHost,
		port, 0);


	// Create an HTTP Request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest(hConnect, L"POST",
		strUrl,
		NULL, WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		0);

	// Send a Request.
	if (hRequest)
		bResults = WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS,
		0, WINHTTP_NO_REQUEST_DATA, 0,
		(DWORD)pStream->size(), 0);

	int len = 0;

	while (bResults && 0 < (len = pStream->next())){
		bResults = WinHttpWriteData(hRequest, pStream->value(),
			(DWORD)len,
			&dwBytesWritten);
	}

	DWORD dwErr = GetLastError();

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, NULL);
	DWORD dwSize;
	BYTE* pszOutBuffer;
	DWORD dwDownloaded;
	CStringA ret;
	do
	{
		// Check for available data.
		dwSize = 0;
		if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
		{
			bResults = FALSE;
			break;
		}

		// No more available data.
		if (!dwSize)
			break;

		// Allocate space for the buffer.
		pszOutBuffer = new BYTE[dwSize + 1];
		if (!pszOutBuffer)
		{
			bResults = FALSE;
			break;
		}

		// Read the Data.
		ZeroMemory(pszOutBuffer, dwSize + 1);

		if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer,
			dwSize, &dwDownloaded))
		{
			bResults = FALSE;
			break;
		}

		ret += (char*)pszOutBuffer;

		// Free the memory allocated to the buffer.
		delete[] pszOutBuffer;

		// This condition should never be reached since WinHttpQueryDataAvailable
		// reported that there are bits to read.
		if (!dwDownloaded)
			break;

	} while (dwSize > 0);

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);

	d_OnThreadComplete(&guid, true);
	//m_correspondent.Send(WM_THREAD_COMPLETE, (WPARAM)this, (LPARAM)pGuid);
	//Success_t* pSuccess = new Success_t();
	//pSuccess->id = id;
	if (!bResults){
		d_OnFailed(id, true);
		//m_correspondent.Send(WM_FAILED, (WPARAM)this, (LPARAM)pSuccess);
	}
	else
	{
		CString utf16Ret;
		CEncoding::Utf8()->GetString((unsigned char*)(LPCSTR)ret, utf16Ret);
		d_OnSuccess(id, utf16Ret, true);
		//pSuccess->ret = L"success";
		//m_correspondent.Send(WM_SUCCESS, (WPARAM)this, (LPARAM)pSuccess);
	}

	//m_correspondent.Send(WM_THREAD_COMPLETE, (WPARAM)this, (LPARAM)pGuid);

	//Success_t* pSuccess = new Success_t();
	//pSuccess->id = id;
	//if (!bResults)
	//	m_correspondent.Send(WM_FAILED, (WPARAM)this, (LPARAM)pSuccess);
	//else
	//{
	//	CString utf16Ret;
	//	CEncoding::Utf8()->GetString((unsigned char*)(LPCSTR)ret, utf16Ret);
	//	pSuccess->ret = (LPCTSTR)utf16Ret;
	//	m_correspondent.Send(WM_SUCCESS, (WPARAM)this, (LPARAM)pSuccess);
	//}
}

//LRESULT CALLBACK CWinHttpImpl::WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
//{
//	std::vector<CWinHttpImpl*>::iterator result = find(m_instances.begin(), m_instances.end(), ((CWinHttpImpl*)wParam));
//	if (result != m_instances.end())
//	{
//		(*result)->d_OnSuccess(((Success_t*)lParam)->id, ((Success_t*)lParam)->ret);
//	}
//
//
//	return m_lpfnOldProc(hwnd, uMsg, wParam, lParam);
//}

void CWinHttpImpl::Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream)
{
	//if (NULL == m_lpfnOldProc){
	//	m_lpfnOldProc = (WNDPROC)SetWindowLong(m_pWnd, GWL_WNDPROC, (LONG)&CWinHttpImpl::WindowProc);
	//}
	try
	{
		GUID guid = {};
		CString url = lpAddr;
		m_threadPool.RunThread(guid, &CWinHttpImpl::DoDownload, this, url, id, mapAttr, pStream);
		//if (m_lpDownloadThread.get() != NULL){
		//	m_lpDownloadThread->join();
		//}
		//
		//m_lpDownloadThread.reset(new std::thread(&CWinHttpImpl::DoDownload, this, url, id, mapAttr, pStream));
	}
	catch (std::exception e)
	{
		int k = 0;
	}

}

void CWinHttpImpl::DoDownload(CString strUrl, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IOutputStream> pStream, GUID guid)
{
	DWORD dwBytesWritten = 0;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	strUrl.Replace(L"http://", L"");
	int index = strUrl.Find(_T("/"));
	CString strHostPort = strUrl.Left(index);
	strUrl = strUrl.Right(strUrl.GetLength() - index - 1);
	index = strHostPort.Find(_T(":"));
	CString strHost = strHostPort.Left(index);
	int port = _tstoi(strHostPort.Right(strHostPort.GetLength() - index - 1));
	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS,
		0);
	//BOOL WINAPI WinHttpSetTimeouts(
	//	_In_  HINTERNET hInternet,
	//	_In_  int dwResolveTimeout,
	//	_In_  int dwConnectTimeout,
	//	_In_  int dwSendTimeout,
	//	_In_  int dwReceiveTimeout
	//	);
	WinHttpSetTimeouts(hSession, 0, 0, 0, 0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect(hSession, strHost,
		port, 0);

	// Create an HTTP Request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest(hConnect, L"GET",
		strUrl,
		NULL, WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		0);

	int len = 0;
	//CString strJson;
	//AsJson(mapAttr, strJson);
	//CEncoding* utf8 = CEncoding::Utf8();
	//std::pair<std::shared_ptr<byte>, int> buf = utf8->GetBytes(strJson);
	//dwBytesWritten = buf.second;

	// Send a Request.
	if (hRequest)
		bResults = WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS,
		0, WINHTTP_NO_REQUEST_DATA, 0,
		dwBytesWritten, 0);


	//while (bResults){
	//if (bResults)
	//{ 
	//	bResults = WinHttpWriteData(hRequest, buf.first.get(),
	//		dwBytesWritten,
	//		&dwBytesWritten);
	//}
	//}
	DWORD dwErr = GetLastError();

	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, NULL);
	DWORD dwSize;
	BYTE* pszOutBuffer;
	DWORD dwDownloaded;
	do
	{
		// Check for available data.
		dwSize = 0;
		if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
		{
			bResults = FALSE;
			break;
		}

		// No more available data.
		if (!dwSize)
			break;

		// Allocate space for the buffer.
		pszOutBuffer = new BYTE[dwSize + 1];
		if (!pszOutBuffer)
		{
			bResults = FALSE;
			break;
		}

		// Read the Data.
		ZeroMemory(pszOutBuffer, dwSize + 1);

		if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer,
			dwSize, &dwDownloaded))
		{
			bResults = FALSE;
		}

		if (bResults && !pStream->write(pszOutBuffer, dwSize))
		{
			bResults = FALSE;
		}

		// Free the memory allocated to the buffer.
		delete[] pszOutBuffer;

		// This condition should never be reached since WinHttpQueryDataAvailable
		// reported that there are bits to read.
		if (!dwDownloaded || !bResults)
			break;

	} while (dwSize > 0);
	pStream->close();
	pStream.reset();

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
	//GUID* pGuid = new GUID;
	//*pGuid = guid;
	//d_OnSuccess(id, L"success", true);
	d_OnThreadComplete(&guid, true);
	//m_correspondent.Send(WM_THREAD_COMPLETE, (WPARAM)this, (LPARAM)pGuid);
	//Success_t* pSuccess = new Success_t();
	//pSuccess->id = id;
	if (!bResults){
		d_OnFailed(id, true);
		//m_correspondent.Send(WM_FAILED, (WPARAM)this, (LPARAM)pSuccess);
	}
	else
	{
		d_OnSuccess(id, L"success", true);
		//pSuccess->ret = L"success";
		//m_correspondent.Send(WM_SUCCESS, (WPARAM)this, (LPARAM)pSuccess);
	}
}

void CWinHttpImpl::OnThreadComplete(GUID* pThreadId)
{
	if (NULL != pThreadId)
	{
		m_threadPool.Collect(*pThreadId);
	}
}

void CWinHttpImpl::Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStream)
{
	//if (NULL == m_lpfnOldProc){
	//	m_lpfnOldProc = (WNDPROC)SetWindowLong(m_pWnd, GWL_WNDPROC, (LONG)&CWinHttpImpl::WindowProc);
	//}
	GUID threadId = {};
	CString url = lpAddr;
	m_threadPool.RunThread(threadId, &CWinHttpImpl::DoUpload, this, url, id, mapAttr, pStream);
}

//
//void CWinHttpImpl::OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//		case WM_SUCCESS:
//		{
//			d_OnSuccess(((Success_t*)lParam)->id, ((Success_t*)lParam)->ret);
//			delete (Success_t*)lParam;
//		}
//		break;
//		case WM_FAILED:
//		{
//			d_OnFailed(((Success_t*)lParam)->id);
//			delete (Success_t*)lParam;
//		}
//		break;
//		case WM_THREAD_COMPLETE:
//		{
//			OnThreadComplete((GUID*)lParam);
//			delete (GUID*)lParam;
//		}
//		break;
//		default:
//		break;
//	}
//}
//
//
