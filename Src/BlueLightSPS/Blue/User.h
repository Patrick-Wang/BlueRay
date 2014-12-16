#pragma once
#include "Util.h"
#include "Permission.h"
class CUser
{
public:
	CString& GetUserName();
	CString& GetToken();
	CPermission& GetPermission();
	CString& GetDepartment();
	CString& GetRole();
	void SetToken(LPCTSTR strToken);
	void SetUserName(LPCTSTR strUserName);
	void SetDepartment(LPCTSTR strDepartment);
	void SetRole(LPCTSTR strRole);
	TO_BE_SINGLETON(CUser)
private:
	CString m_strUsrName;
	CString m_strToken;
	CString m_strDepartment;
	CString m_strRole;
	CPermission m_clPermisssion;
};

