#pragma once
#include "IJSMediator.h"
class CJSExecutor
{
public:
	CJSExecutor(IJSMediator* lpJsMedia);
	~CJSExecutor();
	CString Execute(LPCTSTR lpFunName, CString& param);
	void Execute(LPCTSTR lpFunName);
private:
	IJSMediator* m_lpJsMedia;
};

