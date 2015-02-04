#include "stdafx.h"
#include "CSVStream.h"
#include "Util.h"
#include "CSVParser.h"
#include "JsonObjects.h"
#include "JsonFactory.h"
#include "Encoding.h"
CCSVOutputStream::CCSVOutputStream(LPCTSTR lpFileName)
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


CCSVOutputStream::~CCSVOutputStream()
{
	if (NULL != m_fp)
	{
		fclose(m_fp);
	}
}

bool CCSVOutputStream::write(BYTE* pStart, int length)
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

int CCSVOutputStream::size()
{
	return m_size;
}




CCSVInputStream::CCSVInputStream(LPCTSTR lpFileName)
	: m_size(-1)
	, m_next(0)
{
	m_csvParser.parse(lpFileName);
}

CCSVInputStream::~CCSVInputStream()
{

}

BYTE* CCSVInputStream::value()
{
	if (m_size < 0)
	{
		Parse();
		m_next = m_size;
	}
	return m_buf.get();
}

int CCSVInputStream::size()
{
	if (m_size < 0)
	{
		Parse();
		m_next = m_size;
	}
	return m_size;
}

int CCSVInputStream::next()
{
	int step = 1024 * 4;
	if (m_size < 0)
	{
		Parse();
		m_next = m_size;
	}
	
	if (m_next == m_size)
	{
		m_next = -1;
		return m_size;
	}
	return -1;
	//if (m_next + step > m_size){
	//	m_next = m_size;
	//	step = m_size - m_next;
	//}
	//else
	//{
	//	m_next += step;
	//}
	return m_next;
}

void CCSVInputStream::Parse()
{
	CString strJson;
	GetJson(strJson);
	m_size = strJson.GetLength() * 2 + 2;
	m_buf.reset(new BYTE[m_size]);
	memcpy_s(m_buf.get(), strJson.GetLength() * 2 + 2, 
		(LPCTSTR)strJson, strJson.GetLength() * 2 + 2);
}

void CCSVInputStream::GetJson(CString& strJson)
{
	Json::json_stringstream jstream;
	{
		StringArray row;
		std::auto_ptr<Json::JsonArray> data(Json::JsonFactory::createArray());
		Json::JsonArray* tmp = NULL;
		while (m_csvParser.next(row)){
			tmp = Json::JsonFactory::createArray();
			for (int i = 0; i < row.size(); ++i)
			{
				tmp->add(Json::JsonFactory::createString((LPTSTR)(LPCTSTR)row[i]));
			}
			data->add(tmp);
			row.clear();
		}

		data->asJson(jstream);
	}
	strJson = jstream.str().c_str();
}
