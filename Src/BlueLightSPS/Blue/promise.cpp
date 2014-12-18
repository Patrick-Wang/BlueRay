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
