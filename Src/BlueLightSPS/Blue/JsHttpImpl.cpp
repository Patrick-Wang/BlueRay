#include "stdafx.h"
#include "JsHttpImpl.h"
#include "JQGridAPI.h"
#include "util.h"
#include "JsonFactory.h"
#include "JsonObjects.h"
#include <Winhttp.h>
#define WM_SUCCESS	WM_APP + 27657
#define WM_FAILED	WM_APP + 27658

typedef struct tagSuccess_t{
	int id;
	LPCTSTR ret;
}Success_t;

CComJsFun CJsHttpImpl::m_funPost(_T("onPost"));
CComJsFun CJsHttpImpl::m_funGet(_T("onGet"));

CJsHttpImpl::CJsHttpImpl(IJSMediator* lpJsMediator, CWnd* pWnd)
	: m_lpJsMediator(lpJsMediator)
	, m_pWnd(pWnd)
{
	m_funPost.d_onJsCall += std::make_pair(this, &CJsHttpImpl::OnPost);
	m_funGet.d_onJsCall += std::make_pair(this, &CJsHttpImpl::OnGet);
	m_lpJsMediator->RegisterJsFunction(&m_funPost);
	m_lpJsMediator->RegisterJsFunction(&m_funGet);
}

CJsHttpImpl::~CJsHttpImpl()
{
	m_funPost.d_onJsCall -= std::make_pair(this, &CJsHttpImpl::OnPost);
	m_funGet.d_onJsCall -= std::make_pair(this, &CJsHttpImpl::OnGet);
}

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr)
{
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);

	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	m_lpJsMediator->CallJsFunction(_T("ajaxPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);
}

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, IntArrayPtr>& mapAttr)
{
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);

	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	m_lpJsMediator->CallJsFunction(_T("ajaxPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);
}

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, StringArrayPtr>& mapAttr)
{
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);

	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	m_lpJsMediator->CallJsFunction(_T("ajaxPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);
}

void CJsHttpImpl::Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStreamIterator)
{
	if (NULL == m_lpfnOldProc){
		m_lpfnOldProc = (WNDPROC)SetWindowLong(m_pWnd->GetSafeHwnd(), GWL_WNDPROC, (LONG)&CJsHttpImpl::WindowProc);
	}

	m_lpUploadThread.reset(new std::thread(&CJsHttpImpl::DoUpload, this, lpAddr, id, mapAttr, pStreamIterator));
}

void CJsHttpImpl::Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr)
{
	CString url;
	MakeUrl(lpAddr, mapAttr, url);
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);
	
	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = url.AllocSysString();
	params.push_back(param);

	m_lpJsMediator->CallJsFunction(_T("ajaxGet"), params);

	::SysFreeString(param.bstrVal);

}

void CJsHttpImpl::Get(LPCTSTR lpAddr, int id, StringArrayPtr rest)
{
	CString url;
	MakeUrl(lpAddr, rest, url);
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);

	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = url.AllocSysString();
	params.push_back(param);

	m_lpJsMediator->CallJsFunction(_T("ajaxGet"), params);

	::SysFreeString(param.bstrVal);
}

void CJsHttpImpl::Get(LPCTSTR lpAddr, int id)
{
	std::vector<VARIANT> params;
	VARIANT param = {};
	param.vt = VT_INT;
	param.intVal = (int)this;
	params.push_back(param);

	param.vt = VT_INT;
	param.intVal = id;
	params.push_back(param);

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	m_lpJsMediator->CallJsFunction(_T("ajaxGet"), params);

	::SysFreeString(param.bstrVal);
}

VARIANT CJsHttpImpl::OnPost(int id, const std::vector<VARIANT>& params)
{
	if ((int)this == params[0].intVal){
		if (TRUE == params[1].intVal)
		{
			d_OnSuccess(params[2].intVal, (LPCTSTR)params[3].bstrVal);
		}
		else{
			d_OnFailed(params[2].intVal);
		}
	}
	return VARIANT();
}

VARIANT CJsHttpImpl::OnGet(int id, const std::vector<VARIANT>& params)
{
	if ((int)this == params[0].intVal){
		if (TRUE == params[1].intVal)
		{
			d_OnSuccess(params[2].intVal, (LPCTSTR)params[3].bstrVal);
		}
		else{
			d_OnFailed(params[2].intVal);
		}
	}
	return VARIANT();
}

void CJsHttpImpl::MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& url)
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

void CJsHttpImpl::MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url)
{
	url = lpAddr;
	for (int i = 0; i < rest->size(); ++i)
	{
		url += _T("/") + (*rest)[i];
	}
}

void CJsHttpImpl::AsJson(std::map<CString, CString>& mapAttr, CString& strJson)
{
	strJson = _T("{");
	for (std::map<CString, CString>::iterator it = mapAttr.begin(); it != mapAttr.end();)
	{
		strJson += it->first;
		strJson += _T(":\"");
		strJson += it->second + _T("\"");
		if ((++it) != mapAttr.end())
		{
			strJson += _T(",");
		}
	}
	strJson += _T("}");
}



Json::JsonArray* createArray(std::vector<int>& arr){
	Json::JsonArray* jarray = Json::JsonFactory::createArray();
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		jarray->add(Json::JsonFactory::createInt(*it));
	}
	return jarray;
}

Json::JsonArray* createArray(std::vector<CString>& arr){
	Json::JsonArray* jarray = Json::JsonFactory::createArray();
	for (std::vector<CString>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		jarray->add(Json::JsonFactory::createString((Json::json_char*)it->GetBuffer()));
		it->ReleaseBuffer();
	}
	return jarray;
}

void CJsHttpImpl::AsJson(std::map<CString, StringArrayPtr>& mapAttr, CString& strJson)
{
	std::auto_ptr<Json::JsonObject> pJsObj(Json::JsonFactory::createObject());
	for (std::map<CString, StringArrayPtr>::iterator it = mapAttr.begin();
		it != mapAttr.end();
		++it)
	{
		pJsObj->add((LPTSTR)(LPCTSTR)it->first, createArray(*(it->second)));
	}
	Json::json_stringstream jstream;
	pJsObj->asJson(jstream);
	strJson = jstream.str().c_str();
}

void CJsHttpImpl::AsJson(std::map<CString, IntArrayPtr>& mapAttr, CString& strJson)
{
	std::auto_ptr<Json::JsonObject> pJsObj(Json::JsonFactory::createObject());
	for (std::map<CString, IntArrayPtr>::iterator it = mapAttr.begin();
		it != mapAttr.end(); 
		++it)
	{
		pJsObj->add((LPTSTR)(LPCTSTR)it->first, createArray(*(it->second)));
	}
	Json::json_stringstream jstream;
	pJsObj->asJson(jstream);
	strJson = jstream.str().c_str();
}

bool CJsHttpImpl::SyncPost(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret)
{
	VARIANT vtRet = {};

	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);

	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;
}

bool CJsHttpImpl::SyncPost(LPCTSTR lpAddr, std::map<CString, IntArrayPtr>& mapAttr, CString& ret)
{
	VARIANT vtRet = {};

	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);

	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;
}

bool CJsHttpImpl::SyncPost(LPCTSTR lpAddr, std::map<CString, StringArrayPtr>& mapAttr, CString& ret)
{
	VARIANT vtRet = {};

	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);

	CString strData;
	AsJson(mapAttr, strData);
	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = strData.AllocSysString();

	params.push_back(data);

	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncPost"), params);

	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);

	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;
}

bool CJsHttpImpl::SyncGet(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret)
{
	VARIANT vtRet = {};

	CString url;
	MakeUrl(lpAddr, mapAttr, url);
	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = url.AllocSysString();
	params.push_back(param);

	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncGet"), params);

	::SysFreeString(param.bstrVal);

	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;
}

bool CJsHttpImpl::SyncGet(LPCTSTR lpAddr, StringArrayPtr rest, CString& ret)
{
	VARIANT vtRet = {};

	CString url;
	MakeUrl(lpAddr, rest, url);
	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = url.AllocSysString();
	params.push_back(param);

	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncGet"), params);

	::SysFreeString(param.bstrVal);

	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;
}

bool CJsHttpImpl::SyncGet(LPCTSTR lpAddr, CString& ret)
{
	std::vector<VARIANT> params;
	VARIANT param = {};

	param.vt = VT_BSTR;
	param.bstrVal = ::SysAllocString(lpAddr);
	params.push_back(param);
	VARIANT vtRet = {};
	vtRet = m_lpJsMediator->CallJsFunction(_T("ajaxSyncGet"), params);

	::SysFreeString(param.bstrVal);
	if (VT_BSTR == vtRet.vt)
	{
		ret = vtRet.bstrVal;
		return true;
	}
	return false;

}

void CJsHttpImpl::DoUpload(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IInputStream> pStreamIterator)
{
	Success_t success;
	success.id = id;
	LPSTR pszData = "WinHttpWriteData Example";
	DWORD dwBytesWritten = 0;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS,
		0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect(hSession, L"localhost",
		8080, 0);

	// Create an HTTP Request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest(hConnect, L"POST",
		lpAddr,
		NULL, WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		0);

	// Send a Request.
	if (hRequest)
		bResults = WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS,
		0, WINHTTP_NO_REQUEST_DATA, 0,
		(DWORD)pStreamIterator->size(), 0);

	int len = 0;

	while (bResults && 0 < (len = pStreamIterator->next())){
		bResults = WinHttpWriteData(hRequest, pStreamIterator->value(),
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

		// Free the memory allocated to the buffer.
		delete[] pszOutBuffer;

		// This condition should never be reached since WinHttpQueryDataAvailable
		// reported that there are bits to read.
		if (!dwDownloaded)
			break;

	} while (dwSize > 0);

	// Report any errors.
	if (!bResults)
		m_pWnd->SendMessage(WM_FAILED, (WPARAM)this, (LPARAM)&success);
	else
	{

	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);

}

LRESULT CALLBACK CJsHttpImpl::WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SUCCESS:
		((CJsHttpImpl*)wParam)->d_OnSuccess(((Success_t*)lParam)->id, ((Success_t*)lParam)->ret);
		break;
	case WM_FAILED:
		((CJsHttpImpl*)wParam)->d_OnFailed(((Success_t*)lParam)->id);
		break;
	default:
		break;
	}
	return m_lpfnOldProc(hwnd, uMsg, wParam, lParam);
}

void CJsHttpImpl::Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream)
{
	if (NULL == m_lpfnOldProc){
		m_lpfnOldProc = (WNDPROC)SetWindowLong(m_pWnd->GetSafeHwnd(), GWL_WNDPROC, (LONG)&CJsHttpImpl::WindowProc);
	}
	try
	{
		if (m_lpDownloadThread.get() != NULL){
			m_lpDownloadThread->join();
		}
		m_lpDownloadThread.reset(new std::thread(&CJsHttpImpl::DoDownload, this, lpAddr, id, mapAttr, pStream));
	}
	catch (std::exception e)
	{
		int k = 0;
	}
	
}

void CJsHttpImpl::DoDownload(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IOutputStream> pStream)
{
	Success_t success;
	success.id = id;
	LPSTR pszData = "WinHttpWriteData Example";
	DWORD dwBytesWritten = 0;
	BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	CString strUrl = lpAddr;
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

	// Send a Request.
	if (hRequest)
		bResults = WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS,
		0, WINHTTP_NO_REQUEST_DATA, 0,
		0, 0);

	int len = 0;

	//while (bResults && 0 < (len = pStreamIterator->next())){
	//	bResults = WinHttpWriteData(hRequest, pStreamIterator->value(),
	//		(DWORD)len,
	//		&dwBytesWritten);
	//}
	//DWORD dwErr = GetLastError();

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

	pStream.reset();

	if (!bResults){
		m_pWnd->SendMessage(WM_FAILED, (WPARAM)this, (LPARAM)&success);
	}
	else
	{
		success.ret = L"success";
		m_pWnd->SendMessage(WM_SUCCESS, (WPARAM)this, (LPARAM)&success);
	}

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
}

WNDPROC CJsHttpImpl::m_lpfnOldProc = NULL;


