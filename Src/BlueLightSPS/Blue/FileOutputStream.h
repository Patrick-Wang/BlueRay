#pragma once
#include "IHttp.h"
class CFileOutputStream :
	public IHttp::IOutputStream
{
public:
	CFileOutputStream(LPCTSTR lpFileName);
	~CFileOutputStream();
	virtual bool write(BYTE* pStart, int length);
	virtual int size();
private:
	FILE* m_fp;
	int m_size;
};

