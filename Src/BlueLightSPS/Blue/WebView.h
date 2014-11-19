#pragma once
#include <map>
#include "WebBrowser.h"
#include "IJSMediator.h"



class CWebView :
	public CWnd,
	public CWebBrowserBase,
	public IJSMediator
{
public:
	CWebView();
	~CWebView();
protected:
	virtual HWND GetHWND();
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual VARIANT CallJsFunction(LPCWSTR lpFun, std::vector<VARIANT>& params);
	virtual void RegisterJsFunction(IJSFunction* jsEvent);
	HRESULT _stdcall GetIDsOfNames(REFIID riid, OLECHAR FAR* FAR* rgszNames, unsigned int cNames, LCID lcid, DISPID FAR* rgDispId);
	HRESULT _stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS FAR* pDispParams, VARIANT FAR* pVarResult, EXCEPINFO FAR* pExcepInfo, unsigned int FAR* puArgErr);
	HRESULT STDMETHODCALLTYPE GetExternal(IDispatch **ppDispatch);

private:
	std::map<int, IJSFunction*> m_jsEventsMap;
	std::map<CString, IJSFunction*> m_jsEventsMap2;
public:
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

