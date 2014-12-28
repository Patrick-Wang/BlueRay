#include "stdafx.h"
#include "Plan.h"
#include "CommonDefine.h"
#include "Server.h"

CPlan::CPlan()
{
}


CPlan::~CPlan()
{
}



CPromise<bool>& CPlan::Update(IntArray& rows, StringArray& record)
{
	std::map<CString, StringArrayPtr> attr;
	StringArray tmpRows;

	toArray(rows, tmpRows);

	attr[_T("rows")] = &tmpRows;
	attr[_T("data")] = &record;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/update"), IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}


CPromise<bool>& CPlan::Approve(ApproveType type, IntArray& rows)
{
	CString url;
	switch (type)
	{
	case CPlan::PACK_BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/business"), IDS_HOST_NAME);
		break;
	case CPlan::PACK_PLAN:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/pack/plan"), IDS_HOST_NAME);
		break;
	case CPlan::PLAN_BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/business"), IDS_HOST_NAME);
		break;
	case CPlan::PLAN_PLAN:
		url.Format(_T("http://%s:8080/BlueRay/plan/approve/plan"), IDS_HOST_NAME);
		break;
	default:
		break;
	}
	return doApprove(url, rows);
}

CPromise<bool>& CPlan::Unapprove(ApproveType type, IntArray& rows)
{
	CString url;
	switch (type)
	{
	case CPlan::PACK_BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/pack/business"), IDS_HOST_NAME);
		break;
	case CPlan::PACK_PLAN:
		url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/pack/plan"), IDS_HOST_NAME);
		break;
	case CPlan::PLAN_BUSINESS:
		url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/business"), IDS_HOST_NAME);
		break;
	case CPlan::PLAN_PLAN:
		url.Format(_T("http://%s:8080/BlueRay/plan/unapprove/plan"), IDS_HOST_NAME);
		break;
	default:
		break;
	}

	return doApprove(url, rows);
}

CPromise<bool>& CPlan::doApprove(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

bool CPlan::ValidateTcbhSync(LPCTSTR tcbh, bool& bRet)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/validate/tcbh/%s"), IDS_HOST_NAME, tcbh);
	CString strRet;
	if (m_lpHttp->SyncGet(url, strRet)){
		bRet = (_tcscmp(strRet, L"true") == 0);
		return true;
	}
	return false;
}

bool CPlan::ValidateCcbhSync(LPCTSTR ccbh, bool& bRet)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/validate/ccbh/%s"), IDS_HOST_NAME, ccbh);
	CString strRet;
	if (m_lpHttp->SyncGet(url, strRet)){
		bRet = (_tcscmp(strRet, L"true") == 0);
		return true;
	}
	return false;
}

LPCTSTR CPlan::Translate(int type)
{
	switch (type)
	{
	case CPlan::PACK_BUSINESS:
		return L"pack_business";
	case CPlan::PACK_PLAN:
		return L"pack_plan";
	case CPlan::PLAN_BUSINESS:
		return L"business";
	case CPlan::PLAN_PLAN:
		return L"plan";
	}
	return NULL;
}

CPromise<PageData_t>& CPlan::Query(int page, int rows, CJsonQueryParam& jqp)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/pagequery/%d/%d/1"),
		IDS_HOST_NAME,
		rows,
		page);
	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
	CString base64;
	CString rawData;
	jqp.toJson(rawData, this);
	Util_Tools::Util::base64_encode((unsigned char*)(LPCTSTR)rawData, rawData.GetLength() * 2, base64);
	std::map<CString, CString> attr;
	attr[L"query"] = base64;

	m_lpHttp->Post(url, promise->GetId(), attr);
	return *promise;
}
