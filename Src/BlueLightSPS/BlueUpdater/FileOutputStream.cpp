#include "stdafx.h"
#include "FileOutputStream.h"
#include "Util.h"
#include "Encoding.h"

CFileOutputStream::CFileOutputStream(LPCTSTR lpFileName)
	: m_fp(NULL)
	, m_size(0)
	, m_strFile(lpFileName)
	, m_bCreated(false)
	, m_bUsed(false)
{
	if (NULL != lpFileName)
	{
		Util_Tools::Util::MakeDir(lpFileName);
		if (!::PathFileExists(lpFileName))
		{
			m_bCreated = true;
		}
		_tfopen_s(&m_fp, lpFileName, L"wb");
		//m_fp = CreateFile(lpFileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL);
	}
	
	if (NULL == m_fp)
	{
		throw std::exception("本地文件创建失败");
	}

}


CFileOutputStream::~CFileOutputStream()
{
	close();
	if (m_bCreated && !m_bUsed)
	{
		DeleteFile(m_strFile);
	}
}

bool CFileOutputStream::write(BYTE* pStart, int length)
{
	if (NULL != m_fp)
	{
		m_bUsed = true;
		fwrite(pStart, 1, length, m_fp);
		/*int curWritten = 0;
		DWORD dwWritten = 0;
		while (curWritten < length && WriteFile(m_fp, pStart + curWritten, length, &dwWritten, NULL))
		{
		curWritten += dwWritten;
		}*/
		
		m_size += length;
		return true;
	}
	return false;
}

int CFileOutputStream::size()
{
	return m_size;
}

void CFileOutputStream::close()
{
	if (NULL != m_fp)
	{
		//CloseHandle(m_fp);
		_fclose_nolock(m_fp);
		m_fp = NULL;
	}
}
