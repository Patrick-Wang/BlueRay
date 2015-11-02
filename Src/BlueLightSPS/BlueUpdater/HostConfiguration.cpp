#include "stdafx.h"
#include "HostConfiguration.h"
#include <string>
#include <fstream>



CString CHostConfiguration::m_host;


CHostConfiguration::CHostConfiguration(CString& basePath)
{
	if (m_host.IsEmpty())
	{
		CString path = basePath + _T("\\ipconfig.txt");
		if (PathFileExists(path)){

			std::wfstream infile(path);
			std::wstring temp;
			std::getline(infile, temp);
			m_host = temp.c_str();
		}
		else
		{
			m_host = L"localhost";
		}
	}
	
}


CHostConfiguration::~CHostConfiguration()
{
}

CString& CHostConfiguration::getHost()
{
	return m_host;
}
