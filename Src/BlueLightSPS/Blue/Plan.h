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
	CPromise<bool>& Export(LPCTSTR lpFileName, CJsonQueryParam& jqParam);
	CPromise<bool>& TemplateExport(LPCTSTR lpFileName, CJsonQueryParam& jqParam);
	CPromise<bool>& BzjhTemplateExport(LPCTSTR lpFileName, CJsonQueryParam& jqParam);
	CPromise<bool>& Update(IntArray& rows, StringArray& record);
	CPromise<StringArray>& Approve(ApproveType type, IntArray& rows);
	CPromise<StringArray>& Unapprove(ApproveType type, IntArray& rows);
	bool GetTcbhSync(LPCTSTR zzs, CString& tcbh);
	bool GetCcbhSync(LPCTSTR zzs, CString& ccbh);
	bool ValidateTcbhSync(LPCTSTR tcbh, bool& bRet);
	bool ValidateCcbhSync(LPCTSTR ccbh, bool& bRet);
private:
	CPromise<StringArray>& doApprove(CString& url, IntArray& rows);
};

