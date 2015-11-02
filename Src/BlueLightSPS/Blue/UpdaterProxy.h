#pragma once
class CUpdaterProxy
{
public:
	CUpdaterProxy();
	~CUpdaterProxy();
	bool HasNewVersion();
	void DoUpdate();
	void CancelUpdate();
private:
	HANDLE hUpdate;
	HANDLE hNotUpdate;
	HANDLE hHasVersionSigns[3];
};

