#pragma once
#include "IHttp.h"
#include "HttpServerInterface.h"
#include "Promise.h"
#include "JsonQueryParam.h"
class CPlan : public CHttpServerInterface, public CJsonQueryParam::IApproveTypeTranslator
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
	LPCTSTR Translate(int type);
	CPromise<PageData_t>& Query(
		int page,
		int rows,
		CJsonQueryParam& jqp);
	CPromise<bool>& Export(LPCTSTR lpFileName);
	CPromise<bool>& Update(IntArray& rows, StringArray& record);
	CPromise<bool>& Approve(ApproveType type, IntArray& rows);
	CPromise<bool>& Unapprove(ApproveType type, IntArray& rows);
	bool ValidateTcbhSync(LPCTSTR tcbh, bool& bRet);
	bool ValidateCcbhSync(LPCTSTR ccbh, bool& bRet);
private:
	CPromise<bool>& doApprove(CString& url, IntArray& rows);
};

