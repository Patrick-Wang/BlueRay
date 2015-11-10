#pragma once
#include <thread>
#include <map>
#include <memory>

inline bool operator < (const GUID& g1, const GUID& g2){
	return
		(g1.Data1 < g2.Data1) ||
		(g1.Data1 == g2.Data1 && g1.Data2 < g2.Data2) ||
		(g1.Data1 == g2.Data1 && g1.Data2 == g2.Data2 && g1.Data3 < g2.Data3) ||
		(g1.Data1 == g2.Data1 && g1.Data2 == g2.Data2 && g1.Data3 == g2.Data3 &&
		memcmp(g1.Data4, g2.Data4, 8) < 0);
}


class CThreadPool
{
public:
	CThreadPool();
	~CThreadPool();
	template<class _Fn,
	class... _Args>
	bool RunThread(GUID& threadId, _Fn _Fx, _Args... _Ax){
		if (S_OK == ::CoCreateGuid(&threadId)){
			m_mapPool[threadId].reset(new std::thread(_Fx, _Ax..., threadId));
			return true;
		}
		return false;
	}
	void Wait(GUID& threadId);
	void Collect(GUID& threadId);
private:
	std::map<GUID, std::shared_ptr<std::thread>> m_mapPool;
};

