#include "stdafx.h"
#include "JsHttpImpl.h"
#include "JQGridAPI.h"
CComJsFun CJsHttpImpl::m_funPost(_T("onPost"), 6001);
CComJsFun CJsHttpImpl::m_funGet(_T("onGet"), 6002);



CJsHttpImpl::CJsHttpImpl(IJSMediator* lpJsMediator)
	: m_lpJsMediator(lpJsMediator)
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

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, LPCTSTR strData)
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

	VARIANT data = {};
	data.vt = VT_BSTR;
	data.bstrVal = ::SysAllocString(strData);

	params.push_back(data);
	
	m_lpJsMediator->CallJsFunction(_T("ajaxPost"), params);
	
	::SysFreeString(data.bstrVal);
	::SysFreeString(param.bstrVal);
}

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::vector<CString>& vecData)
{
	CString strData;
	CJQGridAPI::Join(vecData, strData);
	Post(lpAddr, id, mapAttr, (LPCTSTR)(_T("[") + strData + _T("]")));
}

void CJsHttpImpl::Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::vector<int>& vecData)
{
	CString strData;
	CJQGridAPI::Join(vecData, strData);
	Post(lpAddr, id, mapAttr, (LPCTSTR)(_T("[") + strData + _T("]")));

}

void CJsHttpImpl::Get(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr)
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

VARIANT CJsHttpImpl::OnPost(int id, const std::vector<VARIANT>& params)
{
	if ((int)this == params[0].intVal){
		if (TRUE == params[1].intVal)
		{
			d_OnSuccess(params[2].intVal, CString(params[3].bstrVal));
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
			d_OnSuccess(params[2].intVal, CString(params[3].bstrVal));
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


