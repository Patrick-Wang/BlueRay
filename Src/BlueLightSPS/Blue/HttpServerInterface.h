#pragma once
#include "IHttp.h"
#include "Util.h"
#include "JsonObjects.h"
#include "Promise.h"

typedef struct tagPageData_t{
	int total;
	int page;
	int records;
	table rows;
	CString rawData;
}PageData_t;


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

