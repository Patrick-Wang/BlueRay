#include "stdafx.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "Promise.h"
#include "Account.h"

CUser* StringToUser(LPCTSTR strJson)
{
	return CAccount::StringToUser(strJson);
}
