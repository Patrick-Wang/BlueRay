#pragma once
#include <map>
#include <vector>
#include "Delegate.h"
class IHttp
{
public:
	virtual ~IHttp(){};
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, std::vector<int>*>& mapAttr) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, std::vector<CString>*>& mapAttr) = 0;
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr) = 0;
	CDelegate<void(int, LPCTSTR)> d_OnSuccess;
	CDelegate<void(int)> d_OnFailed;
};


