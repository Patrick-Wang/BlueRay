#pragma once
#include <map>
#include <vector>
#include "Delegate.h"

typedef std::vector<int> IntArray;
typedef std::vector<CString> StringArray;
typedef IntArray* IntArrayPtr;
typedef StringArray* StringArrayPtr;

class IHttp
{
public:
	virtual ~IHttp(){};
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, IntArrayPtr>& mapAttr) = 0;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, StringArrayPtr>& mapAttr) = 0;
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr) = 0;
	virtual void Get(LPCTSTR lpAddr, int id, StringArrayPtr rest) = 0;
	virtual void Get(LPCTSTR lpAddr, int id) = 0;
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret) = 0;
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, IntArrayPtr>& mapAttr, CString& ret) = 0;
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, StringArrayPtr>& mapAttr, CString& ret) = 0;
	virtual bool SyncGet(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret) = 0;
	virtual bool SyncGet(LPCTSTR lpAddr, StringArrayPtr rest, CString& ret) = 0;
	virtual bool SyncGet(LPCTSTR lpAddr, CString& ret) = 0;
	CDelegate<void(int, LPCTSTR)> d_OnSuccess;
	CDelegate<void(int)> d_OnFailed;
};


