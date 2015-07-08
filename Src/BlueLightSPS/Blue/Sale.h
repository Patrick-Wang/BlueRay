#pragma once
#include "IHttp.h"
#include "JsonParser.h"
#include "JsonType.h"
#include "JsonObjects.h"
#include "JsonType.h"
#include "HttpServerInterface.h"
#include "Promise.h"
#include "JsonQueryParam.h"


class CSale : public CHttpServerInterface, public CJsonQueryParam::IApproveTypeTranslator
{
public:
	enum ApproveType{
		PLAN,
		BUSINESS
	};

	CSale();
	~CSale();

	typedef struct tagImportResult_t{
		int iTotal;
		int iSucceed;
		int iFailed;
	}ImportResult_t;

	CPromise<PageData_t>& Query(
		int page,
		int rows,
		CJsonQueryParam& jqParam);
	
	LPCTSTR Translate(int type);

	CPromise<bool>& Export(LPCTSTR lpFileName, CJsonQueryParam& jqParam);

	bool AddSync(StringArray& record, int& id);
	CPromise<int>& Add(StringArray& record);

	bool UpdateSync(IntArray& rows, StringArray& record);
	CPromise<bool>& Update(IntArray& rows, StringArray& record);

	bool DeleteSync(IntArray& rows, LPCTSTR psw);
	CPromise<bool>& Delete(IntArray& rows, LPCTSTR psw);

	//bool ApproveSync(ApproveType type, IntArray& rows);
	CPromise<StringArray>& Approve(ApproveType type, IntArray& rows);

	//bool UnapproveSync(ApproveType type, IntArray& rows);
	CPromise<StringArray>& Unapprove(ApproveType type, IntArray& rows);

	CPromise<ImportResult_t>& Import(LPCTSTR lpFileName);

	bool isHtIDUsed(LPCTSTR lpHtID);

private:
	bool doApproveSync(CString& url, IntArray& rows);
	CPromise<StringArray>& doApprove(CString& url, IntArray& rows);
	LPCTSTR ToString(ApproveType type);
	LPCTSTR ToString(bool approved);


};

