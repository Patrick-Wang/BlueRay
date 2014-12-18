#include "stdafx.h"
#include "Notification.h"
#include "CommonDefine.h"
#include "JsonObjects.h"
#include "JsonParser.h"
CNotification::CNotification()
{
}


CNotification::~CNotification()
{
}


bool CNotification::GetUnapprovedSync(Unapproved_t& stUnapproved)
{
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/notification/unapproved"), IDS_HOST_NAME);
	CString strJson;
	if (m_lpHttp->SyncGet(traceSession(url), strJson)){
		Json::JsonParser parser;
		std::shared_ptr<Json::JsonObject> joPtr((Json::JsonObject*)parser.Parse((LPTSTR)(LPCTSTR)strJson));
		stUnapproved.iPackBussiness = joPtr->asInt(L"packBussiness"); //打包-业务未审批数
		stUnapproved.iPackPlan = joPtr->asInt(L"packPlan");//打包-计划未审批数
		stUnapproved.iPlanBussiness = joPtr->asInt(L"planBussiness");//计划-业务未审批数
		stUnapproved.iPlanPlan = joPtr->asInt(L"planPlan");//计划-计划未审批数
		stUnapproved.iSaleBussiness = joPtr->asInt(L"saleBussiness");//销售-业务未审批数
		stUnapproved.iSalePlan = joPtr->asInt(L"salePlan");//销售-计划未审批数
		return true;
	}
	return false;
}

CPromise<CNotification::Unapproved_t>& CNotification::GetUnapproved()
{
	class CLoginParser : public CPromise<CNotification::Unapproved_t>::IRespParser{
	public:
		virtual CNotification::Unapproved_t& OnParse(LPCTSTR strJson){
			Json::JsonParser parser;
			std::shared_ptr<Json::JsonObject> joPtr((Json::JsonObject*)parser.Parse((LPTSTR)(LPCTSTR)strJson));
			m_stUnapproved.iPackBussiness = joPtr->asInt(L"packBussiness"); //打包-业务未审批数
			m_stUnapproved.iPackPlan = joPtr->asInt(L"packPlan");//打包-计划未审批数
			m_stUnapproved.iPlanBussiness = joPtr->asInt(L"planBussiness");//计划-业务未审批数
			m_stUnapproved.iPlanPlan = joPtr->asInt(L"planPlan");//计划-计划未审批数
			m_stUnapproved.iSaleBussiness = joPtr->asInt(L"saleBussiness");//销售-业务未审批数
			m_stUnapproved.iSalePlan = joPtr->asInt(L"salePlan");//销售-计划未审批数
			return m_stUnapproved;
		}
	private:
		CNotification::Unapproved_t m_stUnapproved;
	};
	CString url;
	url.Format(_T("http://%s:8080/BlueRay/notification/unapproved"), IDS_HOST_NAME);
	CPromise<CNotification::Unapproved_t>* promise = CPromise<CNotification::Unapproved_t>::MakePromise(m_lpHttp, new CLoginParser());
	m_lpHttp->Get(traceSession(url), promise->GetId());
	return *promise;
}
