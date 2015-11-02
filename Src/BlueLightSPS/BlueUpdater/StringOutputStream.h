#pragma once
#include "IHttp.h"
#include <vector>
#include <sstream>
class CStringOutputStream :
	public IHttp::IOutputStream
{
public:
	CStringOutputStream(std::string& str);
	virtual ~CStringOutputStream();
	virtual bool write(BYTE* pStart, int length);
	virtual int size();
	virtual void close();
private:
	int m_size;
	std::string& m_str;
	std::ostringstream m_stream;
};

