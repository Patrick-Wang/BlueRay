#pragma once
#include "IHttp.h"
class CCVSOutputStream :
	public IHttp::IOutputStream
{
public:
	CCVSOutputStream(LPCTSTR lpFileName);
	~CCVSOutputStream();
	virtual bool write(BYTE* pStart, int length);
	virtual int size();
private:
	FILE* m_fp;
	int m_size;
};

