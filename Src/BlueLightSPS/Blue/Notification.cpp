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
		stUnapproved.iPackBussiness = joPtr->asInt(L"packBussiness"); //���-ҵ��δ������
		stUnapproved.iPackPlan = joPtr->asInt(L"packPlan");//���-�ƻ�δ������
		stUnapproved.iPlanBussiness = joPtr->asInt(L"planBussiness");//�ƻ�-ҵ��δ������
		stUnapproved.iPlanPlan = joPtr->asInt(L"planPlan");//�ƻ�-�ƻ�δ������
		stUnapproved.iSaleBussiness = joPtr->asInt(L"saleBussiness");//����-ҵ��δ������
		stUnapproved.iSalePlan = joPtr->asInt(L"salePlan");//����-�ƻ�δ������
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
			m_stUnapproved.iPackBussiness = joPtr->asInt(L"packBussiness"); //���-ҵ��δ������
			m_stUnapproved.iPackPlan = joPtr->asInt(L"packPlan");//���-�ƻ�δ������
			m_stUnapproved.iPlanBussiness = joPtr->asInt(L"planBussiness");//�ƻ�-ҵ��δ������
			m_stUnapproved.iPlanPlan = joPtr->asInt(L"planPlan");//�ƻ�-�ƻ�δ������
			m_stUnapproved.iSaleBussiness = joPtr->asInt(L"saleBussiness");//����-ҵ��δ������
			m_stUnapproved.iSalePlan = joPtr->asInt(L"salePlan");//����-�ƻ�δ������
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
