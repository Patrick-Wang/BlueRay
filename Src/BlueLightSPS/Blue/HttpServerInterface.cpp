#include "stdafx.h"
#include "HttpServerInterface.h"


CHttpServerInterface::CHttpServerInterface()
{
}


CHttpServerInterface::~CHttpServerInterface()
{
}

void CHttpServerInterface::resetHttp(IHttp* lpHttp)
{
	m_lpHttp = lpHttp;
}


std::vector < std::pair<int, StringArray>>& CHttpServerInterface::toArray(std::shared_ptr < Json::JsonArray > jarr, std::vector < std::pair<int, StringArray>>& htxxs)
{
	Json::JsonArray::JsonItems& arrItems = jarr->items();
	htxxs.resize(arrItems.size());
	for (int i = 0; i < arrItems.size(); ++i)
	{
		Json::JsonArray& jarrTmp = jarr->asArray(i);
		Json::JsonArray::JsonItems& arrItemsTmp = jarrTmp.items();
		htxxs[i].first = _tstoi(jarrTmp.asString(0).c_str());
		for (int j = 1; j < arrItemsTmp.size(); ++j)
		{
			htxxs[i].second.push_back(jarrTmp.asString(j).c_str());
		}
	}
	return htxxs;
}

StringArray& CHttpServerInterface::toArray(IntArray& src, StringArray& dest)
{
	CString strTmp;
	dest.resize(src.size());
	for (int i = src.size() - 1; i >= 0; --i)
	{
		strTmp.Format(_T("%d"), src[i]);
		dest[i] = strTmp;
	}
	return dest;
}