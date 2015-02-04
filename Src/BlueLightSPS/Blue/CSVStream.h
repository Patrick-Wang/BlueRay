#pragma once
#include "IHttp.h"
#include "CSVParser.h"
class CCSVOutputStream :
	public IHttp::IOutputStream
{
public:
	CCSVOutputStream(LPCTSTR lpFileName);
	~CCSVOutputStream();
	virtual bool write(BYTE* pStart, int length);
	virtual int size();
private:
	FILE* m_fp;
	int m_size;
};

class CCSVInputStream :
	public IHttp::IInputStream
{
public:
	CCSVInputStream(LPCTSTR lpFileName);
	~CCSVInputStream();
	virtual BYTE* value();
	virtual int next();
	virtual int size();
private:
	void Parse();
	void GetJson(CString& strJson);
private:
	int m_size;
	int m_next;
	CCSVParser m_csvParser;
	std::auto_ptr<BYTE> m_buf;
};

