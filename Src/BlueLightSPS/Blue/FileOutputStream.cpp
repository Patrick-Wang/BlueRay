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
	
	if (NULL == m_fp)
	{
		throw std::exception("本地文件创建失败");
	}

}


CFileOutputStream::~CFileOutputStream()
{
	if (NULL != m_fp)
	{
		fclose(m_fp);
	}
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
