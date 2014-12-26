#pragma once
#include "IHttp.h"
#include "JsonParser.h"
#include "JsonType.h"
#include "JsonObjects.h"
#include "JsonType.h"
#include "HttpServerInterface.h"
#include "Promise.h"


class CSale : public CHttpServerInterface
{
public:
	enum ApproveType{
		PLAN,
		BUSINESS,
		ALL
	};

	CSale();
	~CSale();

	CPromise<PageData_t>& Query(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc);
	CPromise<PageData_t>& Query(int page, int rows, int colIndex, bool bAsc);

	CPromise<PageData_t>& Search(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc, LPCTSTR strKeyword);
	CPromise<PageData_t>& Search(int page, int rows, int colIndex, bool bAsc, LPCTSTR strKeyword);

	CPromise<PageData_t>& Search(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc, std::vector<CString>& strKeywords);
	CPromise<PageData_t>& Search(int page, int rows, int colIndex, bool bAsc, std::vector<CString>& strKeywords);

	bool QuerySync(table& htxxs);
	CPromise<table>& Query();

	bool QuerySync(ApproveType type, bool approved, table& htxxs);
	CPromise<table>& Query(ApproveType type, bool approved);

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

private:
	bool doApproveSync(CString& url, IntArray& rows);
	CPromise<bool>& doApprove(CString& url, IntArray& rows);
	LPCTSTR ToString(ApproveType type);
	LPCTSTR ToString(bool approved);


};

