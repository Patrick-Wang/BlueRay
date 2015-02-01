#include "stdafx.h"
#include "CSVParser.h"
#include <iostream>
#include <fstream>
#include "Encoding.h"
#include "FileInputStream.h"
#include "FileOutputStream.h"
// split: split line into fields
void CCSVParser::split(CString& line, std::vector<CString>& fields)
{
	if (line.IsEmpty())
		return;

	CString field;
	int iCurent = 0;
	int iNext = 0;
	int ilen = line.GetLength();
	do {
		if (iCurent < ilen && line[iCurent] == _T('"')){
			iNext = advquoted(line, field, ++iCurent);    // skip quote
		}
		else{
			iNext = advplain(line, field, iCurent);
		}

		fields.push_back(field);
		iCurent = iNext + 1;
	} while (iNext < ilen);
}

// advquoted: quoted field; return index of next separator
int CCSVParser::advquoted(const CString& line, CString& field, int iCurrent)
{
	field = _T("");
	int j = iCurrent;
	int iLen = line.GetLength();
	for (; j < iLen; j++)
	{
		if (line[j] == _T('"') && line[++j] != _T('"'))
		{
			int k = line.Find(m_strSep, j);
			if (k < 0){    // no separator found
				k = iLen;
			}
			for (k -= j; k-- > 0;){
				field += line[j++];
			}
			break;
		}
		field += line[j];
	}
	return j;
}

// advplain: unquoted field; return index of next separator
int CCSVParser::advplain(const CString& line, CString& field, int iCurrent)
{
	// look for separator
	int index = line.Find(m_strSep, iCurrent);

	if (index < 0)      {         // none found
		index = line.GetLength();
	}
	field = line.Mid(iCurrent, index - iCurrent);
	return index;
}

void CCSVParser::parse(LPCTSTR lpPath)
{
	readFile(lpPath, m_strCSV);
	index = 0;
	iStart = 0;
}

void CCSVParser::readFile(LPCTSTR lpPath, CString& strCSV)
{
	int iBufSize = 1024 * 4;
	CFileInputStream pFile(lpPath, iBufSize);
	int iStart = 0;
	int iCount = 0;
	std::auto_ptr<BYTE> pBuf(new BYTE[pFile.size()]);
	while ((iCount = pFile.next()) > 0)
	{
		memcpy_s(pBuf.get() + iStart, iCount, pFile.value(), iCount);
		iStart += iCount;
	}
	CEncoding::Ansi()->GetString(pBuf.get(), iStart, strCSV);

	//CFileOutputStream fo(L"log1");
	//fo.write((BYTE*)(LPCTSTR)strCSV, strCSV.GetLength() * 2);
	//CFileOutputStream fo2(L"log2");
	//fo2.write(pBuf.get(), pFile.size());
}

bool CCSVParser::next(vector<CString>& fields)
{
	CString strLine;

	if ((index = GetLine(m_strCSV, iStart)) >= 0)
	{
		strLine = m_strCSV.Mid(iStart, index - iStart);
		iStart = index + 1;
		split(strLine, fields);
		return true;
	}

	return false;
}

int CCSVParser::GetLine(CString& line, int start)
{
	for (int i = start, len = line.GetLength(); i < len; ++i)
	{
		if (line[i] == _T('"'))
		{
			int j = i + 1;
			for (; j < len; ++j)
			{
				if (line[j] == _T('"') && line[++j] != _T('"'))
				{
					i = j;
					break;
				}
			}
			if (j != i)
			{
				i = len - 1;
			}
		}
		

		if (line[i] == _T('\n'))
		{
			return i;
		}
	}
	return -1;
}
