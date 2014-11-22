#include "stdafx.h"
#include "AdoDBConnector.h"


CAdoDBConnector::CAdoDBConnector(Configuration_t* pConfig)
	: m_pConfig(pConfig)
{
	m_pConnection.CreateInstance(__uuidof(Connection));
}


CAdoDBConnector::~CAdoDBConnector()
{
	if (m_pConnection){
		m_pConnection->Close();
		m_pConnection = NULL;
	}
}

void CAdoDBConnector::Open()
{
	try
	{
		m_pConnection->ConnectionTimeout = 10;                          //��������ʱ��
		_bstr_t strConn;
		GetConnectionString(strConn);
		if (0 != strConn.length())
		{
			m_pConnection->Open(strConn, m_pConfig->strUserName, m_pConfig->strPassword, adModeReadWrite);///����MySql���ݿ�(���Գɹ�)
		}
	}
	catch (_com_error e)                                              //��׽�쳣
	{
		AfxMessageBox(e.ErrorMessage());
	}
}

void CAdoDBConnector::GetConnectionString(_bstr_t& strConn)
{
	if (NULL != m_pConfig.get())
	{
		strConn = _T("DSN=") + m_pConfig->strDSName
			+ _T(";server=") + m_pConfig->strAddress
			+ _T(";database=") + m_pConfig->strDBName;			 
	}
	
}

void CAdoDBConnector::Close()
{
	if (m_pConnection){
		m_pConnection->Close();
	}
}
