#pragma once
#include <memory>

#import "C:\Program Files\common files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF") 


class CAdoDBConnector
{
public:
	typedef struct tagConfiguration_t{
		_bstr_t strDSName;
		_bstr_t strDBName;
		_bstr_t strAddress;
		_bstr_t strUserName;
		_bstr_t strPassword;
	}Configuration_t;

	CAdoDBConnector(Configuration_t* pConfig);
	~CAdoDBConnector();
	void Open();
	void Close();
private:
	void GetConnectionString(_bstr_t& strConn);
private:
	_ConnectionPtr m_pConnection;
	std::auto_ptr<Configuration_t> m_pConfig;
};

