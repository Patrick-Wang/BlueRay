#include "stdafx.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "Promise.h"
#include "Account.h"
#include "HttpServerInterface.h"

CUser* StringToUser(LPCTSTR strJson)
{
	return CAccount::StringToUser(strJson);
}

extern void toArray(LPCTSTR strJson, table& tb){
	Json::JsonParser parser;
	CHttpServerInterface::toArray(std::shared_ptr<Json::JsonArray>((Json::JsonArray*)(parser.Parse((LPTSTR)strJson))), tb);
}