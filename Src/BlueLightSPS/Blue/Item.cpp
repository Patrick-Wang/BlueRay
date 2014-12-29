#include "stdafx.h"
#include "Item.h"
#include "CommonDefine.h"
#include "Util.h"
CItem::CItem()
{
}


CItem::~CItem()
{
}



bool CItem::QuerySync(ItemType type, StringArray& retArray)
{
	CString url;
	switch (type)
	{
	case CItem::KHXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/khxx"), IDS_HOST_NAME);
		break;
	case CItem::CPGGXHXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/cpggxhxx"), IDS_HOST_NAME);
		break;
	case CItem::ZCXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/zcxx"), IDS_HOST_NAME);
		break;
	case CItem::ZDQDYFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/zdqdyflxx"), IDS_HOST_NAME);
		break;
	case CItem::YYLGGFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/yylggflxx"), IDS_HOST_NAME);
		break;
	case CItem::BPQXHFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/bpqxhflxx"), IDS_HOST_NAME);
		break;
	case CItem::BMQXHFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/bmqxhflxx"), IDS_HOST_NAME);
		break;
	case CItem::MPZLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/mpzlxx"), IDS_HOST_NAME);
		break;
	default:
		break;
	}

	CString strJson;
	if (m_lpHttp->SyncGet(traceSession(url), strJson)){
		std::vector<CString> vec;
		Util_Tools::Util::Split(strJson, _T(','), retArray);
		return true;
	}
	return false;
}

CPromise<StringArray> CItem::Query(ItemType type)
{
	CString url;
	switch (type)
	{
	case CItem::KHXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/khxx"), IDS_HOST_NAME);
		break;
	case CItem::CPGGXHXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/cpggxhxx"), IDS_HOST_NAME);
		break;
	case CItem::ZCXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/zcxx"), IDS_HOST_NAME);
		break;
	case CItem::ZDQDYFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/zdqdyflxx"), IDS_HOST_NAME);
		break;
	case CItem::YYLGGFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/yylggflxx"), IDS_HOST_NAME);
		break;
	case CItem::BPQXHFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/bpqxhflxx"), IDS_HOST_NAME);
		break;
	case CItem::BMQXHFLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/bmqxhflxx"), IDS_HOST_NAME);
		break;
	case CItem::MPZLXX:
		url.Format(_T("http://%s:8080/BlueRay/itemquery/mpzlxx"), IDS_HOST_NAME);
		break;
	default:
		break;
	}

	class CItemQueryParser : public CPromise<StringArray>::IRespParser{
	public:
		virtual StringArray& OnParse(LPCTSTR strJson){
			Util_Tools::Util::Split(CString(strJson), _T(','), m_vec);
			return m_vec;
		}
	private:
		std::vector<CString> m_vec;
	};
	CPromise<StringArray>* promise = CPromise<StringArray>::MakePromise(m_lpHttp, new CItemQueryParser());
	m_lpHttp->Get(traceSession(url), promise->GetId());
	return *promise;
}
