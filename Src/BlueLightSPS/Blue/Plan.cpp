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
	m_lpHttp->Post(traceSession(url), (int)promise, attr);
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
	m_lpHttp->Post(traceSession(url), (int)promise, attr);
	return *promise;
}
