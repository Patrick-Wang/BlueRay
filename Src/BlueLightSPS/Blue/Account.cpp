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

bool CAccount::LoginSync(CString& usrName, CString& psw)
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
		perm.setPlan(jPerm.asBool(L"plan"));
		perm.setSale(jPerm.asBool(L"sale"));

		return true;
	}
	else
	{
		return false;
	}
}

CPromise<CUser*>& CAccount::Login(CString& usrName, CString& psw)
{
	class CLoginParser : public CPromise<CUser*>::IRespParser{
	public:
		virtual CUser*& OnParse(LPCTSTR strRet){
			m_usr = CAccount::StringToUser(strRet);
			return m_usr;
		}
	private:
		CUser* m_usr;
	};

	CString url;
	url.Format(_T("http://%s:8080/BlueRay/account/login/"), IDS_HOST_NAME);
	url += usrName + _T("/") + psw;
	CPromise<CUser*>* promise = CPromise<CUser*>::MakePromise(m_lpHttp, new CLoginParser());
	m_lpHttp->Get(url, promise->GetId());
	return *promise;
}

CUser* CAccount::StringToUser(LPCTSTR strJson)
{
	if (0 != _tcscmp(strJson, L"error"))
	{
		Json::JsonParser jParser;
		std::auto_ptr<Json::JsonObject> jObj((Json::JsonObject*)jParser.Parse((LPTSTR)strJson));
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
		perm.setPlan(jPerm.asBool(L"plan"));
		perm.setSale(jPerm.asBool(L"sale"));
		return usr;
	}
	return NULL;
}
