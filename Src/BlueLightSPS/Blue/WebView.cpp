#include "stdafx.h"
#include "WebView.h"


CWebView::CWebView()
{
}


CWebView::~CWebView()
{
}

HWND CWebView::GetHWND()
{
	return m_hWnd;
}

BEGIN_MESSAGE_MAP(CWebView, CWnd)
	ON_WM_CREATE()
//	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


int CWebView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
#ifndef _DEBUG
	GetWebBrowser2()->put_Silent(VARIANT_TRUE);
#endif // !_DEBUG
	OpenWebBrowser();
	return 0;
}

VARIANT CWebView::CallJsFunction(LPCWSTR lpFun, std::vector<VARIANT>& params)
{
	LPCWSTR lpObjName = L"window";
	VARIANT* pps = new VARIANT[params.size()];
	VARIANT ret = {};
	std::copy_n(params.rbegin(), params.size(), pps);
	
	//��ȡwindow
	IDispatch *pHtmlWindow = GetHtmlWindow();

	////��ȡobject
	//CVariant obj;
	//CWebBrowserBase::GetProperty(pHtmlWindow, (LPOLESTR)lpObjName, &obj);

	InvokeMethod(pHtmlWindow, (LPOLESTR)lpFun, &ret, pps, params.size());
	return ret;
}

void CWebView::RegisterJsFunction(IJSFunction* jsEvent)
{
	if (NULL != jsEvent)
	{
		m_jsEventsMap[jsEvent->Id()] = jsEvent;
		m_jsEventsMap2[jsEvent->Name()] = jsEvent;
	}
}

void CWebView::UnRegisterJsFunction(IJSFunction* jsEvent)
{
	if (NULL != jsEvent)
	{
		m_jsEventsMap.erase(jsEvent->Id());
		m_jsEventsMap2.erase(jsEvent->Name());
	}
}

HRESULT _stdcall CWebView::GetIDsOfNames(
	REFIID riid,
	OLECHAR FAR* FAR* rgszNames,
	unsigned int cNames,
	LCID lcid,
	DISPID FAR* rgDispId
	)
{
	CString name((LPWSTR)*rgszNames);
	if (m_jsEventsMap2.find(name) != m_jsEventsMap2.end())
	{
		*rgDispId = (DISPID)m_jsEventsMap2[name]->Id();
	}
	return S_OK;
}

HRESULT _stdcall CWebView::Invoke(
	DISPID dispIdMember,
	REFIID riid,
	LCID lcid,
	WORD wFlags,
	DISPPARAMS* pDispParams,
	VARIANT* pVarResult,
	EXCEPINFO* pExcepInfo,
	unsigned int* puArgErr
	)
{
	if (m_jsEventsMap.find(dispIdMember) != m_jsEventsMap.end())
	{
		std::vector<VARIANT> args;
		if (pDispParams != NULL){
			for (int i = pDispParams->cArgs - 1; i >= 0; --i)
			{
				args.push_back(pDispParams->rgvarg[i]);
			}
		}
		VARIANT vr = m_jsEventsMap[dispIdMember]->Call(args);
		if (NULL != pVarResult){
			*pVarResult = vr;
		}
		return S_OK;
	}
	else{
		return __super::Invoke(dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
	}
	
}
HRESULT STDMETHODCALLTYPE CWebView::GetExternal(IDispatch **ppDispatch)
{
	*ppDispatch = this;
	return S_OK;
}

//void CWebView::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	__super::OnRButtonUp(nFlags, point);
//}


BOOL CWebView::PreTranslateMessage(MSG* pMsg)
{
	if (WM_RBUTTONUP == pMsg->message)
	{
		return TRUE;
	}

	return __super::PreTranslateMessage(pMsg);
}

void CWebView::OnDocumentCompleted()
{
	d_OnDomComplete();
}


