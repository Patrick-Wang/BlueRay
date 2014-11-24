#pragma once
#include <map>
#include "Delegate.h"
class IHttp
{
public:
	virtual ~IHttp(){};
	virtual void Post(LPCTSTR lpAddr, std::map<CString, CString> mapAttr, LPCTSTR strData) = 0;
	virtual void Get(LPCTSTR lpAddr, std::map<CString, CString> mapAttr) = 0;
	CDelegate<void(CString&)> d_OnSuccess;
	CDelegate<void(int)> d_OnFailed;
};


