#include "stdafx.h"
#include "User.h"

CUser::CUser(){
}

bool CUser::Initialize()
{
	return true;
}

void CUser::UnInitialize()
{

}

CString& CUser::GetUserName()
{
	return m_strUsrName;
}

CString& CUser::GetToken()
{
	return m_strToken;
}

void CUser::SetToken(LPCTSTR strToken)
{
	m_strToken = strToken;
}

CPermission& CUser::GetPermission()
{
	return m_clPermisssion;
}

CString& CUser::GetDepartment()
{
	return m_strDepartment;
}

CString& CUser::GetRole()
{
	return m_strRole;
}

void CUser::SetDepartment(LPCTSTR strDepartment)
{
	m_strDepartment = strDepartment;
}

void CUser::SetRole(LPCTSTR strRole)
{
	m_strRole = strRole;
}

void CUser::SetUserName(LPCTSTR strUserName)
{
	m_strUsrName = strUserName;
}
