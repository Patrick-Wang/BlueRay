#pragma once
#include <map>
#include <vector>
#include <memory>
#include "UILib/Delegate.h"

typedef std::vector<int> IntArray;
typedef std::vector<CString> StringArray;
typedef IntArray* IntArrayPtr;
typedef StringArray* StringArrayPtr;

class IHttp
{
public:
	class IInputStream{
	public :
		virtual BYTE* value() = 0;
		virtual int next() = 0;
		virtual int size() = 0;
		virtual ~IInputStream(){};
	};

	class IOutputStream{
	public:
		virtual bool write(BYTE* pStart, int length) = 0;
		virtual int size() = 0;
		virtual void close() = 0;
		virtual ~IOutputStream(){};
	};

	virtual ~IHttp(){};
	virtual void Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStream) = 0;
	virtual void Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream) = 0;

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


