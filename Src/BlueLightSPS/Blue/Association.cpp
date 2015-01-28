#include "stdafx.h"
#include "Association.h"
#include "CSVParser.h"

CAssociation::CAssociation()
{
}

bool CAssociation::Initialize()
{
	bool bRet(true);
	m_lpLoadThread.reset(new std::thread(&CAssociation::LoadAssociation, this));
	return true;
}

void CAssociation::UnInitialize()
{
	if (m_lpLoadThread.get() != NULL){
		m_lpLoadThread->detach();
	}
}

void CAssociation::LoadAssociation()
{
	try
	{
		CCSVParser csvParser;
		csvParser.parse(_T("association.csv"));
		std::vector<CString> fields;
		CString key;
		while (csvParser.next(fields))
		{
			key = fields[0] + fields[1];
			fields.erase(fields.begin());
			fields.erase(fields.begin());
			m_assoMap[key] = fields;
			fields.clear();
		}
	}
	catch (std::exception& e)
	{
		
	}
}

const std::vector<CString>* CAssociation::find(LPCTSTR kh, LPCTSTR gg)
{
	CString key = kh;
	key += gg;
	if (m_lpLoadThread.get() != NULL){
		m_lpLoadThread->join();
		m_lpLoadThread.reset();
	}
	std::map<CString, std::vector<CString>>::iterator it = m_assoMap.find(key);
	if (it != m_assoMap.end())
	{
		return &(it->second);
	}
	return NULL;
}
