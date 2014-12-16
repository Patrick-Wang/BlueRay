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
	CPromise<bool>& Update(IntArray& rows, StringArray& record);
	CPromise<bool>& Approve(ApproveType type, IntArray& rows);
	CPromise<bool>& Unapprove(ApproveType type, IntArray& rows);
private:
	CPromise<bool>& doApprove(CString& url, IntArray& rows);
};

