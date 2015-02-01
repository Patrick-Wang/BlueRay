#include "stdafx.h"
#include "STDThreadPool.h"


CSTDThreadPool::CSTDThreadPool()
{
}


CSTDThreadPool::~CSTDThreadPool()
{
	for (std::map<CString, std::shared_ptr<std::thread>>::iterator it = m_mapPool.begin();
		it != m_mapPool.end(); ++it){
		it->second->detach();
	}
	m_mapPool.clear();
}


void CSTDThreadPool::Wait(GUID& threadId)
{
	CString strGUID;
	GuidFmt(strGUID, threadId);
	std::map<CString, std::shared_ptr<std::thread>>::iterator it = m_mapPool.find(strGUID);
	if (it != m_mapPool.end())
	{
		if (it->second->joinable()){
			it->second->join();
		}
	}
}

void CSTDThreadPool::Collect(GUID& threadId)
{
	CString strGUID;
	GuidFmt(strGUID, threadId);
	std::map<CString, std::shared_ptr<std::thread>>::iterator it = m_mapPool.find(strGUID);
	if (it != m_mapPool.end())
	{
		it->second->detach();
		m_mapPool.erase(it);
	}
}

void CSTDThreadPool::GuidFmt(CString& str, GUID& guid)
{
	str.Format(L"{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
		,guid.Data1
		,guid.Data2
		, guid.Data3
		, guid.Data4[0], guid.Data4[1]
		, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
		, guid.Data4[6], guid.Data4[7]);
}
