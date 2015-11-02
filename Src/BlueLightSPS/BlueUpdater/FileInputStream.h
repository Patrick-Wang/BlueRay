#pragma once
#include "IHttp.h"
class CFileInputStream :
	public IHttp::IInputStream
{
public:
	CFileInputStream(LPCTSTR lpFileName, int iBufSize);
	~CFileInputStream();
	virtual BYTE* value();
	virtual int next();
	virtual int size();
private:
	FILE* m_fp;
	int m_size;
	int m_iCur;
	int m_iBufSize;
	BYTE* pBuffer;

};

