#pragma once
#include "IHttp.h"
#include "HttpServerInterface.h"

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
	bool Update(IntArray& rows, StringArray& record);
	bool Approve(ApproveType type, IntArray& rows);
	bool Unapprove(ApproveType type, IntArray& rows);
private:
	bool doApprove(CString& url, IntArray& rows);
};

