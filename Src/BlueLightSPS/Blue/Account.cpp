#include "stdafx.h"
#include "Account.h"
#include "CommonDefine.h"
#include "User.h"
CAccount::CAccount()
{
}


CAccount::~CAccount()
{
}

bool CAccount::Login(CString& usrName, CString& psw)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/account/login/"), IDS_HOST_NAME);
	url += usrName + _T("/") + psw;
	CString token;
	if (m_lpHttp->SyncGet(url, token) && 0 != token.Compare(L"error"))
	{
		CUser::GetInstance()->SetToken(token);
		return true;
	}
	else
	{
		return false;
	}
}
