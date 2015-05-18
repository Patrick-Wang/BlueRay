#include "stdafx.h"
#include "Plan.h"
#include "CommonDefine.h"
#include "Server.h"
#include "CSVStream.h"
#include "FileOutputStream.h"
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


CPromise<StringArray>& CPlan::Approve(ApproveType type, IntArray& rows)
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

CPromise<StringArray>& CPlan::Unapprove(ApproveType type, IntArray& rows)
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

CPromise<StringArray>& CPlan::doApprove(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CPromise<StringArray>* promise = CPromise<StringArray>::MakePromise(m_lpHttp, new CStringArrayParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

bool CPlan::ValidateTcbhSync(LPCTSTR tcbh, bool& bRet)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/validate"), IDS_HOST_NAME);
	CString strRet;
	std::map<CString, CString> mapAttr;
	mapAttr[L"item"] = L"tcbh";
	mapAttr[L"value"] = tcbh;
	if (m_lpHttp->SyncGet(url, mapAttr, strRet)){
		bRet = (_tcscmp(strRet, L"true") == 0);
		return true;
	}
	return false;
}

bool CPlan::ValidateCcbhSync(LPCTSTR ccbh, bool& bRet)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/validate"), IDS_HOST_NAME);
	CString strRet;
	std::map<CString, CString> mapAttr;
	mapAttr[L"item"] = L"ccbh";
	mapAttr[L"value"] = ccbh;
	if (m_lpHttp->SyncGet(url, mapAttr, strRet)){
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

CPromise<bool>& CPlan::Export(LPCTSTR lpFileName, CJsonQueryParam& jqParam)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/export"),
		IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	std::map<CString, CString> attr;
	CString base64;
	CString rawData;
	jqParam.toJson(rawData, this);
	Util_Tools::Util::base64_encode((unsigned char*)(LPCTSTR)rawData, rawData.GetLength() * 2, base64);
	attr[L"query"] = base64;
	m_lpHttp->Download(url, promise->GetId(), attr, std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(lpFileName)));
	return *promise;
}

CPromise<bool>& CPlan::TemplateExport(LPCTSTR lpFileName, CJsonQueryParam& jqParam)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/template/export"),
		IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	std::map<CString, CString> attr;
	CString base64;
	CString rawData;
	jqParam.toJson(rawData, this);
	Util_Tools::Util::base64_encode((unsigned char*)(LPCTSTR)rawData, rawData.GetLength() * 2, base64);
	attr[L"query"] = base64;
	m_lpHttp->Download(url, promise->GetId(), attr, std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(lpFileName)));
	return *promise;

}

bool CPlan::GetTcbhSync(CString& tcbh)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/getbh/tcbh"),
		IDS_HOST_NAME);
	return m_lpHttp->SyncGet(url, tcbh);
}

bool CPlan::GetCcbhSync(CString& ccbh)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/plan/getbh/ccbh"),
		IDS_HOST_NAME);
	return m_lpHttp->SyncGet(url, ccbh);
}
