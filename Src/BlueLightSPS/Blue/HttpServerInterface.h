#pragma once
#include "IHttp.h"
#include "Util.h"
#include "JsonObjects.h"
class CHttpServerInterface
{
public:
	CHttpServerInterface();
	virtual ~CHttpServerInterface();
	static std::vector < std::pair<int, StringArray>>& toArray(std::shared_ptr < Json::JsonArray > jarr, std::vector < std::pair<int, StringArray>>& htxxs);
	static StringArray& toArray(IntArray& src, StringArray& dest);
	CString& traceSession(CString& url);
protected:
	void resetHttp(IHttp* lpHttp);
	IHttp* m_lpHttp;
	friend class CServer;
};

