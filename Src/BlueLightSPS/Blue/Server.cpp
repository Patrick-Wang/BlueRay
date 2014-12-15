#include "stdafx.h"
#include "Server.h"


CServer::CServer()
	: m_lpHttp(NULL)
{

}


void CServer::SetHttp(IHttp* lpHttp)
{
	if (NULL != m_lpHttp)
	{
		delete m_lpHttp;
		m_lpHttp = NULL;
	}
	m_lpHttp = lpHttp;
	m_clSale.resetHttp(m_lpHttp);
	m_clPlan.resetHttp(m_lpHttp);
	m_clNotification.resetHttp(m_lpHttp);
	m_clItem.resetHttp(m_lpHttp);
	m_clAccount.resetHttp(m_lpHttp);
}

CSale& CServer::GetSale()
{
	return m_clSale;
}

IHttp* CServer::GetHttp()
{
	return m_lpHttp;
}

CServer* CServer::GetInstance()
{
	if (NULL == ins)
	{
		return ins = new CServer();
	}
	return ins;
}

CServer::~CServer()
{
	if (NULL != m_lpHttp)
	{
		delete m_lpHttp;
		m_lpHttp = NULL;
	}
}

CPlan& CServer::GetPlan()
{
	return m_clPlan;
}

CNotification& CServer::GetNotification()
{
	return m_clNotification;
}

CItem& CServer::GetItem()
{
	return m_clItem;
}

CAccount& CServer::GetAccount()
{
	return m_clAccount;
}


CServer* CServer::ins;
