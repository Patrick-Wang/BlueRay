#include "stdafx.h"
#include "JsHttpImpl.h"
#include "JQGridAPI.h"
#include "util.h"
#include "JsonFactory.h"
#include "JsonObjects.h"
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
		jarray->add(Json::JsonFactory::create(*it));
	}
	return jarray;
}

Json::JsonArray* createArray(std::vector<CString>& arr){
	Json::JsonArray* jarray = Json::JsonFactory::createArray();
	for (std::vector<CString>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		jarray->add(Json::JsonFactory::create((Json::json_char*)it->GetBuffer()));
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


