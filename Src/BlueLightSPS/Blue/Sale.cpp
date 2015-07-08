#include "stdafx.h"
#include "JsonFactory.h"
#include "Sale.h"
#include "CommonDefine.h"
#include "User.h"
#include "Server.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "Encoding.h"
#include "CSVParser.h"
#include "CSVStream.h"
#include "JsonObjects.h"
CSale::CSale()
{

}

CSale::~CSale()
{
}



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
	m_lpHttp->SyncPost(traceSession(url), attr, strRet);
	return strRet.Compare(L"success") == 0;
}

bool CSale::DeleteSync(IntArray& rows, LPCTSTR psw)
{
	std::map<CString, StringArrayPtr> attr;
	StringArray tmpRows;
	toArray(rows, tmpRows);
	StringArray pswRows;
	pswRows.push_back(psw);
	attr[_T("psw")] = &pswRows;
	attr[_T("del")] = &tmpRows;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
	CString strRet;
	m_lpHttp->SyncPost(traceSession(url), attr, strRet);
	return strRet.Compare(L"success") == 0;
}
//
//bool CSale::ApproveSync(ApproveType type, IntArray& rows)
//{
//	CString url;
//	switch (type)
//	{
//	case CSale::PLAN:
//		url.Format(_T("http://%s:8080/BlueRay/sale/approve/plan"), IDS_HOST_NAME);
//		break;
//	case CSale::BUSINESS:
//		url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
//		break;
//	default:
//		break;
//	}
//	return doApproveSync(url, rows);
//}

//bool CSale::UnapproveSync(ApproveType type, IntArray& rows)
//{
//	CString url;
//	switch (type)
//	{
//	case CSale::PLAN:
//		url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/plan"), IDS_HOST_NAME);
//		break;
//	case CSale::BUSINESS:
//		url.Format(_T("http://%s:8080/BlueRay/sale/approve/business"), IDS_HOST_NAME);
//		break;
//	default:
//		break;
//	}
//
//	return doApproveSync(url, rows  );
//}

bool CSale::doApproveSync(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CString strRet;
	m_lpHttp->SyncPost(traceSession(url), attr, strRet);
	return strRet.Compare(L"success") == 0;
}


CPromise<PageData_t>& CSale::Query(int page, int rows, CJsonQueryParam& jqParam)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/pagequery/%d/%d/1"),
		IDS_HOST_NAME,
		rows,
		page);
	CPromise<PageData_t>* promise = CPromise<PageData_t>::MakePromise(m_lpHttp, new CPageDataParser());
	CString base64;
	CString rawData;
	jqParam.toJson(rawData, this);
	Util_Tools::Util::base64_encode((unsigned char*)(LPCTSTR)rawData, rawData.GetLength() * 2, base64);
	std::map<CString, CString> attr;
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

CPromise<bool>& CSale::Delete(IntArray& rows, LPCTSTR psw)
{
	std::map<CString, StringArrayPtr> attr;
	StringArray tmpRows;
	toArray(rows, tmpRows);
	StringArray pswRows;
	pswRows.push_back(psw);
	attr[_T("psw")] = &pswRows;
	attr[_T("del")] = &tmpRows;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/delete"), IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<StringArray>& CSale::Approve(ApproveType type, IntArray& rows)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/approve/%s"), IDS_HOST_NAME, Translate(type));
	return doApprove(url, rows);
}

CPromise<StringArray>& CSale::doApprove(CString& url, IntArray& rows)
{
	std::map<CString, IntArrayPtr> attr;
	attr[_T("rows")] = &rows;
	CPromise<StringArray>* promise = CPromise<StringArray>::MakePromise(m_lpHttp, new CStringArrayParser());
	m_lpHttp->Post(traceSession(url), promise->GetId(), attr);
	return *promise;
}

CPromise<StringArray>& CSale::Unapprove(ApproveType type, IntArray& rows)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/unapprove/%s"), IDS_HOST_NAME, Translate(type));
	return doApprove(traceSession(url), rows);
}


LPCTSTR CSale::ToString(bool approved)
{
	return approved ? L"approved" : L"unapproved";
}

LPCTSTR CSale::Translate(int type)
{
	switch (type)
	{
	case CSale::PLAN:
		return L"plan";
	case CSale::BUSINESS:
		return L"business";
	}
	return NULL;
}

CPromise<bool>& CSale::Export(LPCTSTR lpFileName, CJsonQueryParam& jqParam)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/export"),
		IDS_HOST_NAME);
	CPromise<bool>* promise = CPromise<bool>::MakePromise(m_lpHttp, new CBoolParser());
	std::map<CString, CString> attr;
	CString base64;
	CString rawData;
	jqParam.toJson(rawData, this);
	Util_Tools::Util::base64_encode((unsigned char*)(LPCTSTR)rawData, rawData.GetLength() * 2, base64);
	attr[L"query"] = base64;
	m_lpHttp->Download(traceSession(url), promise->GetId(), attr, std::shared_ptr<IHttp::IOutputStream>(new CFileOutputStream(lpFileName)));
	return *promise;
}

int FindReturn(BYTE* pBufCopy, int len){
	for (int i = 0; i < len - 1; ++i)
	{
		if ('\r' == pBufCopy[i] && '\n' == pBufCopy[i + 1])
		{
			return i;
		}
	}
	return -1;
}
//
//void CSale::Import(LPCTSTR lpFileName, ImportResult_t& ret)
//{
//	CCSVParser csvParser;
//	csvParser.parse(lpFileName);
//	StringArray strArray;
//	int id = 0;
//	SecureZeroMemory(&ret, sizeof(ret));
//	while (csvParser.next(strArray))
//	{
//		++ret.iTotal;
//		if (AddSync(strArray, id))
//		{
//			++ret.iSucceed;
//		}
//		else
//		{
//			++ret.iFailed;
//		}
//		strArray.clear();
//	}
//}

CPromise<CSale::ImportResult_t>& CSale::Import(LPCTSTR lpFileName)
{
	class CImportParser : public CPromise<ImportResult_t>::IRespParser{
	public:
		virtual ImportResult_t& OnParse(LPCTSTR strRet){
			Json::JsonParser jparser;
			std::auto_ptr<Json::JsonObject> jp((Json::JsonObject*)jparser.Parse((LPTSTR)strRet));
			m_ret.iTotal = jp->asInt(L"total");
			m_ret.iSucceed = jp->asInt(L"succeed");
			m_ret.iFailed = jp->asInt(L"failed");
			return m_ret;
		}
	private:
		ImportResult_t m_ret;
	};
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/import"),
		IDS_HOST_NAME);
	CPromise<ImportResult_t>* promise = CPromise<ImportResult_t>::MakePromise(m_lpHttp, new CImportParser());
	std::map<CString, CString> attr;
	m_lpHttp->Upload(
		traceSession(url), 
		promise->GetId(), 
		attr, 
		std::shared_ptr<IHttp::IInputStream>(new CCSVInputStream(lpFileName)));
	return *promise;
}

bool CSale::isHtIDUsed(LPCTSTR lpHtID)
{
	std::map<CString, CString> attr;
	attr[_T("HtID")] = lpHtID;
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/sale/isHtIDExist"), IDS_HOST_NAME);
	CString strRet;
	m_lpHttp->SyncGet(traceSession(url), attr, strRet);
	return strRet.CompareNoCase(L"true") == 0;
}
