#pragma once
#include <string>
#include <vector>

class CVersion
{
public:
	CVersion(CString& basePath);
	~CVersion();
	bool IsNewVersion(CString& version);
private:
	int Compare(vector<std::wstring>& ver1, std::vector<std::wstring>& ver2);
private:
	static std::vector<std::wstring> m_curVersion;
};

