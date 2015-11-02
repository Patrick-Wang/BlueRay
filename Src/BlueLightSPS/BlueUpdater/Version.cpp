#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include "Util.h"
#include "Version.h"
using namespace std;

void split(const wstring& src, const wstring& separator, std::vector<wstring>& dest)
{
	wstring str = src;
	wstring substring;
	wstring::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == string::npos) return;
		}
	} while (index != string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}

CVersion::CVersion(CString& basePath)
{
	if (m_curVersion.empty())
	{
		std::string strPath;
		Util_Tools::Util::Utf16leToANSI(basePath, strPath);
		strPath += "\\version.txt";
		if (PathFileExistsA(strPath.c_str())){
			std::ifstream infile(strPath);
			string temp;
			getline(infile, temp);
			CString version;
			Util_Tools::Util::ANSIToUtf16LE(temp, version);
			wstring sep(L".");
			split(wstring(version), sep, m_curVersion);
		}	
	}
}


CVersion::~CVersion()
{

}

bool CVersion::IsNewVersion(CString& version)
{
	wstring str((LPCTSTR)version);
	wstring sep(L".");
	std::vector<wstring> dest;
	split(str, sep, dest);
	if (Compare(m_curVersion, dest) >= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int CVersion::Compare(std::vector<wstring>& ver1, std::vector<wstring>& ver2)
{
	int ver1Val = 0;
	int ver2Val = 0;
	int ver1Size = ver1.size();
	int ver2Size = ver2.size();
	for (int i = 0; i < ver2Size && i < ver1Size; ++i)
	{
		ver1Val = _tstoi(ver1[i].c_str());
		ver2Val = _tstoi(ver2[i].c_str());
		if (ver1Val > ver2Val)
		{
			return 1;
		}
		else if (ver1Val < ver2Val)
		{
			return -1;
		}
	}
	if (ver1Size > ver2Size)
	{
		return 1;
	}
	else if(ver1Size < ver2Size)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

std::vector<std::wstring> CVersion::m_curVersion;
