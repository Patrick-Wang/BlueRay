#pragma once
#include "Util.h"
class CUser
{
public:
	CString& GetUserName();
	CString& GetToken();
	void SetToken(CString& strToken);
	TO_BE_SINGLETON(CUser)
private:
	CString m_strUsrName;
	CString m_strToken;
};

