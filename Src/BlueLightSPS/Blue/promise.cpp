#include "stdafx.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "Promise.h"
#include "Account.h"
#include "HttpServerInterface.h"


table& CQueryParser::OnParse(LPCTSTR strJson)
{
	Json::JsonParser jparser;
	std::shared_ptr < Json::JsonArray > jarr((Json::JsonArray*)jparser.Parse((LPTSTR)strJson));
	CHttpServerInterface::toArray(jarr, m_retTable);
	return m_retTable;
}

PageData_t& CPageDataParser::OnParse(LPCTSTR strJson)
{
	m_retData.rawData = strJson;
	Json::JsonParser jp;
	std::shared_ptr<Json::JsonObject> pjo((Json::JsonObject*)(jp.Parse((LPTSTR)strJson)));
	m_retData.page = pjo->asInt(L"page");
	m_retData.records = pjo->asInt(L"records");
	m_retData.total = pjo->asInt(L"total");
	Json::JsonArray& jarows = pjo->asArray(L"rows");
	m_retData.rows.resize(jarows.size());
	for (int i = 0; i < jarows.size(); ++i)
	{
		m_retData.rows[i].first = jarows.asObject(i).asInt(L"id");
		Json::JsonArray& jarow = jarows.asObject(i).asArray(L"cell");
		for (int j = 0; j < jarow.size(); ++j)
		{
			m_retData.rows[i].second.push_back(jarow.asString(j).c_str());
		}
	}
	return m_retData;
}
