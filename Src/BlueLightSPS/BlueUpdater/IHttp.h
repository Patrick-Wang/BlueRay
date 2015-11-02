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

	CDelegate<void(int, LPCTSTR)> d_OnSuccess;
	CDelegate<void(int)> d_OnFailed;
};


