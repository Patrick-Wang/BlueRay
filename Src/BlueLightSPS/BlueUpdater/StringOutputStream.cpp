#include "stdafx.h"
#include "StringOutputStream.h"


CStringOutputStream::CStringOutputStream(std::string& str)
	:m_str(str)
{
}


CStringOutputStream::~CStringOutputStream()
{
}

bool CStringOutputStream::write(BYTE* pStart, int length)
{
	for (int i = 0; i < length; ++i){
		m_stream << (char)(*(pStart + i));
	}
	m_size += length;
	return true;
}

int CStringOutputStream::size()
{
	return m_size;
}

void CStringOutputStream::close()
{
	m_str = m_stream.str();
	m_stream.clear();
}
