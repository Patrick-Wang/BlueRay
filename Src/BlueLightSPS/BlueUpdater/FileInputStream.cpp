#include "stdafx.h"
#include "FileInputStream.h"


CFileInputStream::CFileInputStream(LPCTSTR lpFileName, int iBufSize)
	: m_fp(NULL)
	, m_size(0)
	, m_iBufSize(iBufSize)
	, m_iCur(0)
	, pBuffer(NULL)
{
	if (NULL != lpFileName)
	{
		_tfopen_s(&m_fp, lpFileName, L"rb");
	}

	if (NULL == m_fp)
	{
		throw std::exception("读取本地文件失败");
	}
	else
	{
		fseek(m_fp, 0, SEEK_END);
		m_size = ftell(m_fp);
		fseek(m_fp, 0, SEEK_SET);
		pBuffer = new BYTE[m_iBufSize];
	}
}


CFileInputStream::~CFileInputStream()
{
	if (NULL != m_fp)
	{
		_fclose_nolock(m_fp);
	}
	if (NULL != pBuffer)
	{
		delete[] pBuffer;
	}
}

BYTE* CFileInputStream::value()
{
	return pBuffer;
}

int CFileInputStream::next()
{
	int iReadCount = m_iBufSize;
	if (m_iCur < m_size)
	{
		if ((m_size - m_iCur) >= m_iBufSize)
		{
			iReadCount = m_iBufSize;
		}
		else
		{
			iReadCount = m_size - m_iCur;
		}
		m_iCur += iReadCount;
		fread_s(pBuffer, m_iBufSize, 1, iReadCount, m_fp);
		return iReadCount;
	}
	else
	{
		return -1;
	}
}

int CFileInputStream::size()
{
	return m_size;
}
