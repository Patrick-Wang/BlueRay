#include "stdafx.h"
#include "FileOutputStream.h"
#include "Util.h"
#include "Encoding.h"
CFileOutputStream::CFileOutputStream(LPCTSTR lpFileName)
	: m_fp(NULL)
	, m_size(0)
{
	if (NULL != lpFileName)
	{
		Util_Tools::Util::MakeDir(lpFileName);
		_tfopen_s(&m_fp, lpFileName, L"wb");
	}
	
}


CFileOutputStream::~CFileOutputStream()
{
	fclose(m_fp);
}

bool CFileOutputStream::write(BYTE* pStart, int length)
{
	if (NULL != m_fp)
	{
		fwrite(pStart, 1, length, m_fp);
		m_size += length;
		return true;
	}
	return false;
}

int CFileOutputStream::size()
{
	return m_size;
}
