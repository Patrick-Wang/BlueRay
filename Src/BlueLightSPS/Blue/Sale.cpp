#include "stdafx.h"
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


bool CSale::Query(std::vector < std::pair<int, StringArray>>& htxxs)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/query/all/none"), IDS_HOST_NAME);
	CString strJson;
	if (m_lpHttp->SyncGet(url, strJson)){
		Json::JsonParser jparser;
		std::shared_ptr < Json::JsonArray > jarr((Json::JsonArray*)jparser.Parse((LPTSTR)(LPCTSTR)strJson, strJson.GetLength()));
		try
		{
			toArray(jarr, htxxs);
			return true;
		}
		catch (std::exception& e)
		{
		}
		
	}
	return false;
}

bool CSale::Query(ApproveType type, bool approved, std::vector < std::pair<int, StringArray>>& htxxs)
{
	CString url;
	switch (type)
	{
	case CSale::PLAN:
		url.Format(_T("http://%s:8080/BlueRay/sale/query/plan/%s"), IDS_HOST_NAME, approved ? L"approved" : L"unapproved");
		break;
	case CSale::BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/sale/query/business/%s"), IDS_HOST_NAME, approved ? L"approved" : L"unapproved");
		break;
	default:
		break;
	}
	
	CString strJson;
	if (m_lpHttp->SyncGet(url, strJson)){
		Json::JsonParser jparser;
		std::shared_ptr < Json::JsonArray > jarr((Json::JsonArray*)jparser.Parse((LPTSTR)(LPCTSTR)strJson, strJson.GetLength()));
		try
		{
			toArray(jarr, htxxs);
			return true;
		}
		catch (std::exception& e)
		{
		}
	}
	return false;
}



bool CSale::Add(StringArray& record, int& id)
{

	std::map<CString, StringArrayPtr> attr;
	attr[_T("add")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/add/;jsessionid=%s"), IDS_HOST_NAME, (LPCTSTR)CUser::GetInstance()->GetToken());
	CString strJson;
	if (m_lpHttp->SyncPost(url, attr, strJson)){
		id = _tstoi(strJson);
		return true;
	}
	return false;
}

bool CSale::Update(IntArray& rows, StringArray& record)
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

bool CSale::Delete(IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("del")] = &rows;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
	CString strRet;
	m_lpHttp->SyncPost(url, attr, strRet);
	return strRet.Compare(L"success") == 0;
}

bool CSale::Approve(ApproveType type, IntArray& rows)
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
	return doApprove(url, rows);
}

bool CSale::Unapprove(ApproveType type, IntArray& rows)
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

	return doApprove(url, rows);
}

bool CSale::doApprove(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CString strRet;
	m_lpHttp->SyncPost(url, attr, strRet);
	return strRet.Compare(L"success") == 0;
}
