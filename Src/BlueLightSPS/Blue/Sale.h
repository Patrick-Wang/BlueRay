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
		BUSINESS
	};

	CSale();
	~CSale();
	bool QuerySync(table& htxxs);
	CPromise<table>& Query();
	bool QuerySync(ApproveType type, bool approved, std::vector < std::pair<int, StringArray>>& htxxs);
	bool Add(StringArray& record, int& id);
	bool Update(IntArray& rows, StringArray& record);
	bool Delete(IntArray& rows);
	bool Approve(ApproveType type, IntArray& rows);
	bool Unapprove(ApproveType type, IntArray& rows);
private:
	bool doApprove(CString& url, IntArray& rows);
	

};

