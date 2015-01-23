#include "stdafx.h"
#include "CSVOutputStream.h"
#include "Util.h"
#include "Encoding.h"
CCVSOutputStream::CCVSOutputStream(LPCTSTR lpFileName)
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


CCVSOutputStream::~CCVSOutputStream()
{
	if (NULL != m_fp)
	{
		fclose(m_fp);
	}
}

bool CCVSOutputStream::write(BYTE* pStart, int length)
{
	if (NULL != m_fp)
	{
		CString strDest;
		CEncoding::Utf8()->GetString(pStart, length, strDest);
		std::pair<std::shared_ptr<byte>, int> buf = CEncoding::Ansi()->GetBytes((LPCTSTR)strDest, strDest.GetLength());
		fwrite(buf.first.get(), 1, buf.second, m_fp);
		m_size += buf.second;
		return true;
	}
	return false;
}

int CCVSOutputStream::size()
{
	return m_size;
}
