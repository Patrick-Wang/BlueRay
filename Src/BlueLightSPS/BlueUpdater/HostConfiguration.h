#pragma once
class CHostConfiguration
{
public:
	CHostConfiguration(CString& basePath);
	~CHostConfiguration();
	CString& getHost();
private:
	static CString m_host;
};

