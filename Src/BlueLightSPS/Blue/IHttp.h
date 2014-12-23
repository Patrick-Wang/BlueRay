#pragma once
#include <map>
#include <vector>
#include <memory>
#include "Delegate.h"

typedef std::vector<int> IntArray;
typedef std::vector<CString> StringArray;
typedef IntArray* IntArrayPtr;
typedef StringArray* StringArrayPtr;

class IHttp
{
public:
	class IStreamIterator{
	public :
		virtual BYTE* value() = 0;
		virtual int next() = 0;
		virtual int size() = 0;
		virtual ~IStreamIterator(){};
	};


	virtual ~IHttp(){};
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IStreamIterator> pStreamIterator) = 0;
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
	CDelegate<void(int, BYTE*, int)> d_OnInStream;
	CDelegate<void(int)> d_OnFailed;
};


