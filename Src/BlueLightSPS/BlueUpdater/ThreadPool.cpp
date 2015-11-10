#include "stdafx.h"
#include "ThreadPool.h"


CThreadPool::CThreadPool()
{
}


CThreadPool::~CThreadPool()
{
	for (std::map<GUID, std::shared_ptr<std::thread>>::iterator it = m_mapPool.begin();
		it != m_mapPool.end(); ++it){
		if (it->second->joinable()){
			it->second->join();
		}
	}
	m_mapPool.clear();
}


void CThreadPool::Wait(GUID& threadId)
{
	std::map<GUID, std::shared_ptr<std::thread>>::iterator it = m_mapPool.find(threadId);
	if (it != m_mapPool.end())
	{
		if (it->second->joinable()){
			it->second->join();
		}
	}
}

void CThreadPool::Collect(GUID& threadId)
{
	std::map<GUID, std::shared_ptr<std::thread>>::iterator it = m_mapPool.find(threadId);
	if (it != m_mapPool.end())
	{
		it->second->detach();
		m_mapPool.erase(it);
	}
}