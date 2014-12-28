#include "stdafx.h"
#include "JsonFactory.h"
#include "Sale.h"
#include "CommonDefine.h"
#include "User.h"
#include "Server.h"
CSale::CSale()
{

}

CSale::~CSale()
{
}

//bool CSale::QuerySync(std::vector < std::pair<int, StringArray>>& htxxs)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/query/all/none"), IDS_HOST_NAME);
//	CString strJson;
//	if (m_lpHttp->SyncGet(url, strJson)){
//		Json::JsonParser jparser;
//		std::shared_ptr < Json::JsonArray > jarr((Json::JsonArray*)jparser.Parse((LPTSTR)(LPCTSTR)strJson, strJson.GetLength()));
//		try
//		{
//			toArray(jarr, htxxs);
//			return true;
//		}
//		catch (std::exception& e)
//		{
//		}
//		
//	}
//	return false;
//}
//
//bool CSale::QuerySync(ApproveType type, bool approved, std::vector < std::pair<int, StringArray>>& htxxs)
//{
//	CString url;
//	switch (type)
//	{
//	case CSale::PLAN:
//		url.Format(_T("http://%s:8080/BlueRay/sale/query/plan/%s"), IDS_HOST_NAME, approved ? L"approved" : L"unapproved");
//		break;
//	case CSale::BUSINESS:
//		url.Format(_T("http://%s:8080/BlueRay/sale/query/business/%s"), IDS_HOST_NAME, approved ? L"approved" : L"unapproved");
//		break;
//	default:
//		break;
//	}
//	
//	CString strJson;
//	if (m_lpHttp->SyncGet(url, strJson)){
//		Json::JsonParser jparser;
//		std::shared_ptr < Json::JsonArray > jarr((Json::JsonArray*)jparser.Parse((LPTSTR)(LPCTSTR)strJson, strJson.GetLength()));
//		try
//		{
//			toArray(jarr, htxxs);
//			return true;
//		}
//		catch (std::exception& e)
//		{
//		}
//	}
//	return false;
//}



bool CSale::AddSync(StringArray& record, int& id)
{

	std::map<CString, StringArrayPtr> attr;
	attr[_T("add")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/add/"), IDS_HOST_NAME);
	CString strId;
	if (m_lpHttp->SyncPost(traceSession(url), attr, strId)){
		id = _tstoi(strId);
		return true;
	}
	return false;
}

bool CSale::UpdateSync(IntArray& rows, StringArray& record)
{
	std::map<CString, StringArrayPtr> attr;
	StringArray tmpRows;

	toArray(rows, tmpRows);

	attr[_T("rows")] = &tmpRows;
	attr[_T("data")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/modify"), IDS_HOST_NAME);
	CString strRet;
	m_lpHttp->SyncPost(url, attr, strRet);
	return strRet.Compare(L"success") == 0;
}

bool CSale::DeleteSync(IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("del")] = &rows;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
	CString strRet;
	m_lpHttp->SyncPost(traceSession(url), attr, strRet);
	return strRet.Compare(L"success") == 0;
}

bool CSale::ApproveSync(ApproveType type, IntArray& rows)
{
	CString url;
	switch (type)
	{
	case CSale::PLAN:
		url.Format(_T("http://%s:8080/BlueRay/sale/approve/plan"), IDS_HOST_NAME);
		break;
	case CSale::BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
		break;
	default:
		break;
	}
	return doApproveSync(url, rows);
}

bool CSale::UnapproveSync(ApproveType type, IntArray& rows)
{
	CString url;
	switch (type)
	{
	case CSale::PLAN:
		url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/plan"), IDS_HOST_NAME);
		break;
	case CSale::BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
		break;
	default:
		break;
	}

	return doApproveSync(url, rows  );
}

bool CSale::doApproveSync(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CString strRet;
	m_lpHttp->SyncPost(traceSession(url), attr, strRet);
	return strRet.Compare(L"success") == 0;
}

//CPromise<table>& CSale::Query()
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/query/all/none"), IDS_HOST_NAME);
//	CPromise<table>* promise = CPromise<table>::MakePromise(m_lpHttp, new CQueryParser());
//	m_lpHttp->Get(url, promise->GetId());
//	return *promise;
//}
//
//CPromise<table>& CSale::Query(ApproveType type, bool approved)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/query/%s/%s"),
//		IDS_HOST_NAME,
//		ToString(type),
//		ToString(approved));
//	CPromise<table>* promise = CPromise<table>::MakePromise(m_lpHttp, new CQueryParser());
//	m_lpHttp->Get(url, promise->GetId());
//	return *promise;
//}

//CPromise<PageData_t>& CSale::Query(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/pagequery/%s/%s/%d/%d/1/%d/%s"),
//		IDS_HOST_NAME,
//		ToString(type),
//		ToString(approved),
//		rows,
//		page,
//		colIndex,
//		Util_Tools::Util::ToString(bAsc));
//	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
//	m_lpHttp->Get(url, promise->GetId());
//	return *promise;
//}
//
//CPromise<PageData_t>& CSale::Query(int page, int rows, int colIndex, bool bAsc)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/pagequery/all/none/%d/%d/1/%d/%s"),
//		IDS_HOST_NAME,
//		rows,
//		page,
//		colIndex,
//		bAsc ? L"true" : L"false");
//	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
//	m_lpHttp->Get(url, promise->GetId());
//	return *promise;
//}


CPromise<PageData_t>& CSale::Query(int page, int rows, 
	std::vector<ApproveCondition_t>* pApproveCondition /*= NULL*/, 
	BasicSearchCondition_t* pBasicSearch /*= NULL*/, DateSearchCondition_t* pDateSearch /*= NULL*/, 
	StringArrayPtr pAdvanceSearch /*= NULL*/, 
	std::vector<SortCondition_t>* pSorter /*= NULL*/)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/pagequery/%d/%d/1"),
		IDS_HOST_NAME,
		rows,
		page);
	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
	std::shared_ptr<Json::JsonObject> jquery((Json::JsonObject*)(Json::JsonFactory::createObject()));
	if (NULL != pBasicSearch || NULL != pDateSearch || NULL != pAdvanceSearch){
		Json::JsonObject& jSearch = jquery->add(L"search", Json::JsonFactory::createObject()).asObject(L"search");
		if (NULL != pBasicSearch)
		{
			Json::JsonObject& jBasic = jSearch.add(L"basic", Json::JsonFactory::createObject()).asObject(L"basic");
			jBasic.add(L"text", Json::JsonFactory::createString((Json::json_char*)pBasicSearch->lpText));
			jBasic.add(L"exact", Json::JsonFactory::createBool(pBasicSearch->exact));
		}

		if (NULL != pDateSearch)
		{
			Json::JsonObject& jDate = jSearch.add(L"date", Json::JsonFactory::createObject()).asObject(L"date");
			jDate.add(L"startDate", Json::JsonFactory::createString((Json::json_char*)pDateSearch->startDate));
			jDate.add(L"endDate", Json::JsonFactory::createString((Json::json_char*)pDateSearch->endDate));
		}

		if (NULL != pAdvanceSearch)
		{
			Json::JsonArray& jAdvance = jSearch.add(L"advanced", Json::JsonFactory::createArray()).asArray(L"advanced");
			for (int i = 0; i < pAdvanceSearch->size(); ++i){
				jAdvance.add(Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)pAdvanceSearch->at(i)));
			}
		}
	}
	if (NULL != pApproveCondition){
		Json::JsonArray& jApprove = jquery->add(L"approve", Json::JsonFactory::createArray()).asArray(L"approve");
		for (int i = 0; i < pApproveCondition->size(); ++i){
			Json::JsonObject& jApproveItem = jApprove.add(Json::JsonFactory::createObject()).asObject(i);
			jApproveItem.add(L"type", Json::JsonFactory::createString((Json::json_char*)ToString((ApproveType)pApproveCondition->at(i).type)));
			jApproveItem.add(L"approve", Json::JsonFactory::createBool(pApproveCondition->at(i).approved));
		}
	}
	

	if (NULL != pSorter){
		Json::JsonArray& jSort = jquery->add(L"sort", Json::JsonFactory::createArray()).asArray(L"sort");
		
		for (int i = 0; i < pSorter->size(); ++i){
			Json::JsonObject& jSortItem = jSort.add(Json::JsonFactory::createObject()).asObject(i);
			jSortItem.add(L"col", Json::JsonFactory::createInt(pSorter->at(i).col));
			jSortItem.add(L"order", Json::JsonFactory::createBool(pSorter->at(i).asc));
		}
	}

	Json::json_stringstream jss;
	jquery->asJson(jss);

	std::map<CString, CString> attr;
	std:wstring str = jss.str();
	CString base64;
	Util_Tools::Util::base64_encode((unsigned char*)str.c_str(), str.length() * 2, base64);
	attr[L"query"] = base64;

	m_lpHttp->Post(url, promise->GetId(), attr);
	return *promise;
}

CPromise<int>& CSale::Add(StringArray& record)
{
	std::map<CString, StringArrayPtr> attr;
	attr[_T("add")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/add/"), IDS_HOST_NAME);
	CPromise<int>* promise = CPromise<int>::MakePromise(m_lpHttp, new CIntParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<bool>& CSale::Update(IntArray& rows, StringArray& record)
{
	std::map<CString, StringArrayPtr> attr;
	StringArray tmpRows;
	toArray(rows, tmpRows);
	attr[_T("rows")] = &tmpRows;
	attr[_T("data")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/modify"), IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<bool>& CSale::Delete(IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("del")] = &rows;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<bool>& CSale::Approve(ApproveType type, IntArray& rows)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/approve/%s"), IDS_HOST_NAME, ToString(type));
	return doApprove(url, rows);
}

CPromise<bool>& CSale::doApprove(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<bool>& CSale::Unapprove(ApproveType type, IntArray& rows)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/%s"), IDS_HOST_NAME, ToString(type));
	return doApprove(url, rows);
}
//
//CPromise<PageData_t>& CSale::Search(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc, LPCTSTR strKeyword)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/simplepagesearch/%s/%s/%d/%d/1/%d/%s"),
//		IDS_HOST_NAME,
//		ToString(type),
//		ToString(approved),
//		rows,
//		page,
//		colIndex,
//		Util_Tools::Util::ToString(bAsc));
//	std::map<CString, CString> attr;
//	attr[L"search"] = strKeyword;
//	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
//	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
//	return *promise;
//}
//
//CPromise<PageData_t>& CSale::Search(int page, int rows, int colIndex, bool bAsc, LPCTSTR strKeyword)
//{
//	return Search(ALL, false, page, rows, colIndex, bAsc, strKeyword);
//}
//
//CPromise<PageData_t>& CSale::Search(ApproveType type, bool approved, int page, int rows, int colIndex, bool bAsc, const StringArray& strKeywords)
//{
//	CString url;
//	url.Format(_T("http://%s:8080/BlueRay/sale/pagesearch/%s/%s/%d/%d/1/%d/%s"),
//		IDS_HOST_NAME,
//		ToString(type),
//		ToString(approved),
//		rows,
//		page,
//		colIndex,
//		Util_Tools::Util::ToString(bAsc));
//	std::map<CString, StringArrayPtr> attr;
//	attr[L"search"] = const_cast<StringArray*>(&strKeywords);
//	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
//	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
//	return *promise;
//}
//
//CPromise<PageData_t>& CSale::Search(int page, int rows, int colIndex, bool bAsc, const StringArray& strKeywords)
//{
//	return Search(ALL, true, page, rows, colIndex, bAsc, strKeywords);
//}

LPCTSTR CSale::ToString(ApproveType type)
{
	switch (type)
	{
	case CSale::PLAN:
		return L"plan";
	case CSale::BUSINESS:
		return L"business";
	case CSale::ALL:
		return L"all";
	}
}

LPCTSTR CSale::ToString(bool approved)
{
	return approved ? L"approved" : L"unapproved";
}

