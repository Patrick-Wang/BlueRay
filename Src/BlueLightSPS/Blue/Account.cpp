#include "stdafx.h"
#include "JsonParser.h"
#include "JsonObjects.h"
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
	CString userInfo;
	if (m_lpHttp->SyncGet(url, userInfo) && 0 != userInfo.Compare(L"error"))
	{
		Json::JsonParser jParser;
		std::auto_ptr<Json::JsonObject> jObj((Json::JsonObject*)jParser.Parse((LPTSTR)(LPCTSTR)userInfo, userInfo.GetLength()));
		CUser* usr = CUser::GetInstance();
		usr->SetToken(jObj->asString(L"session").c_str());
		Json::JsonObject& jUsr = jObj->asObject(L"usr");
		Json::JsonObject& jPerm = jObj->asObject(L"perm");
		
		usr->SetUserName(jUsr.asString(L"name").c_str());
		usr->SetDepartment(jUsr.asString(L"department").c_str());
		usr->SetRole(jUsr.asString(L"role").c_str());

		CPermission& perm = usr->GetPermission();
		perm.setJhbzjhsh(jPerm.asBool(L"jhbzjhsh"));
		perm.setJhbzywsh(jPerm.asBool(L"jhbzywsh"));
		perm.setJhjhsh(jPerm.asBool(L"jhjhsh"));
		perm.setJhywsh(jPerm.asBool(L"jhywsh"));
		perm.setXsjhsh(jPerm.asBool(L"xsjhsh"));
		perm.setXsywsh(jPerm.asBool(L"xsywsh"));

		return true;
	}
	else
	{
		return false;
	}
}
