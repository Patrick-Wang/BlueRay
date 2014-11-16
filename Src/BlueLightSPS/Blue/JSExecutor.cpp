#include "stdafx.h"
#include "JSExecutor.h"



CJSExecutor::CJSExecutor(IJSMediator* lpJsMedia)
	: m_lpJsMedia(lpJsMedia)
{

}


CJSExecutor::~CJSExecutor()
{
}

CString CJSExecutor::Execute(LPCTSTR lpFunName, CString& param)
{
	CString result;
	if (NULL != m_lpJsMedia)
	{
		VARIANT vt;
		vt.vt = VT_BSTR;
		vt.bstrVal = param.AllocSysString();
		std::vector<VARIANT> params;
		params.push_back(vt);
		VARIANT ret = m_lpJsMedia->CallJsFunction(lpFunName, params);
		if (VT_BSTR == ret.vt)
		{
			result = ret.bstrVal;
		}
	}
	return result;
}

void CJSExecutor::Execute(LPCTSTR lpFunName)
{
	if (NULL != m_lpJsMedia)
	{
		std::vector<VARIANT> params;
		VARIANT ret = m_lpJsMedia->CallJsFunction(lpFunName, params);
	}
}
