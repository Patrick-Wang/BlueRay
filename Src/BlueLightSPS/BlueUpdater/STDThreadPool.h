#pragma once
#include <thread>
#include <map>
#include <memory>
class CSTDThreadPool
{
public:
	CSTDThreadPool();
	~CSTDThreadPool();
	template<class _Fn,
	class... _Args>
	bool RunThread(GUID& threadId, _Fn _Fx, _Args... _Ax){
		if (S_OK == ::CoCreateGuid(&threadId)){
			CString guidFmt;
			GuidFmt(guidFmt, threadId);
			m_mapPool[guidFmt].reset(new std::thread(_Fx, _Ax..., threadId));
			return true;
		}
		return false;
	}
	void Wait(GUID& threadId);
	void Collect(GUID& threadId);
private:
	void GuidFmt(CString& str, GUID& guid);
private:
	std::map<CString, std::shared_ptr<std::thread>> m_mapPool;
};

