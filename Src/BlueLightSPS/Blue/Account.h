#pragma once
#include "HttpServerInterface.h"
#include "User.h"
#include "Promise.h"


class CAccount : public CHttpServerInterface
{
public:
	CAccount();
	~CAccount();
	bool LoginSync(CString& usrName, CString& psw);
	CPromise<CUser*>& Login(CString& usrName, CString& psw);
	static CUser* StringToUser(LPCTSTR strJson);
};

