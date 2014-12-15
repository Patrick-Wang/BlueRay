#pragma once
#include "HttpServerInterface.h"

class CAccount : public CHttpServerInterface
{
public:
	CAccount();
	~CAccount();
	bool Login(CString& usrName, CString& psw);
};

