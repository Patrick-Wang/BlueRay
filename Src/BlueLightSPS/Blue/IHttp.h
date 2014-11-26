#pragma once
#include <map>
#include <vector>
#include "Delegate.h"
class IHttp
{
public:
	virtual ~IHttp(){};
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, LPCTSTR strData) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::vector<CString>& vecData) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr, std::vector<int>& vecData) = 0;
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString> mapAttr) = 0;
	CDelegate<void(int, CString&)> d_OnSuccess;
	CDelegate<void(int)> d_OnFailed;
};


