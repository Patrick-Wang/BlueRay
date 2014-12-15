#pragma once
#include "IHttp.h"
#include "Util.h"
#include "JsonObjects.h"
class CHttpServerInterface
{
public:
	CHttpServerInterface();
	virtual ~CHttpServerInterface();
	
	std::vector < std::pair<int, StringArray>>& toArray(std::shared_ptr < Json::JsonArray > jarr, std::vector < std::pair<int, StringArray>>& htxxs);
	StringArray& toArray(IntArray& src, StringArray& dest);

protected:
	void resetHttp(IHttp* lpHttp);
	IHttp* m_lpHttp;
	friend class CServer;
};

