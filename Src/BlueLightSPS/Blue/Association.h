#pragma once
#include <thread>
#include "Util.h"
#include <map>
class CAssociation
{
	TO_BE_SINGLETON(CAssociation);
public:
	const std::vector<CString>* find(LPCTSTR kh, LPCTSTR gg);

private:
	void LoadAssociation();

private:
	std::shared_ptr<std::thread> m_lpLoadThread;
	std::map<CString, std::vector<CString>> m_assoMap;
};

