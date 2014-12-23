#pragma once
#include "IHttp.h"
#include "HttpServerInterface.h"
#include "Promise.h"
class CPlan : public CHttpServerInterface
{
public:
	enum ApproveType{
		PACK_BUSINESS,
		PACK_PLAN,
		PLAN_BUSINESS,
		PLAN_PLAN
	};

	CPlan();
	~CPlan();
	CPromise<table>& Query();
	CPromise<table>& Query(ApproveType type, bool bApproved);
	CPromise<bool>& Update(IntArray& rows, StringArray& record);
	CPromise<bool>& Approve(ApproveType type, IntArray& rows);
	CPromise<bool>& Unapprove(ApproveType type, IntArray& rows);
	bool ValidateTcbhSync(LPCTSTR tcbh, bool& bRet);
	bool ValidateCcbhSync(LPCTSTR ccbh, bool& bRet);
private:
	CPromise<bool>& doApprove(CString& url, IntArray& rows);
};

