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

	bool DeleteSync(IntArray& rows);
	CPromise<bool>& Delete(IntArray& rows);

	bool ApproveSync(ApproveType type, IntArray& rows);
	CPromise<bool>& Approve(ApproveType type, IntArray& rows);

	bool UnapproveSync(ApproveType type, IntArray& rows);
	CPromise<bool>& Unapprove(ApproveType type, IntArray& rows);

	void Import(LPCTSTR lpFileName, ImportResult_t& ret);

private:
	bool doApproveSync(CString& url, IntArray& rows);
	CPromise<bool>& doApprove(CString& url, IntArray& rows);
	LPCTSTR ToString(ApproveType type);
	LPCTSTR ToString(bool approved);


};

