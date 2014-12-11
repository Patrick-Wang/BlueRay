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

void CUser::SetToken(CString& strToken)
{
	m_strToken = strToken;
}
