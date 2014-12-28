#include "stdafx.h"
#include "JsonQueryParam.h"
#include "JsonFactory.h"
#include "JsonObjects.h"

CJsonQueryParam::CJsonQueryParam()
	: m_pbsc(NULL)
	, m_pdsc(NULL)
	, m_pAdvanced(NULL)
{
}


CJsonQueryParam::~CJsonQueryParam()
{
	if (NULL != m_pbsc)
	{
		delete m_pbsc;
		m_pbsc = NULL;
	}
	if (NULL != m_pdsc)
	{
		delete m_pdsc;
		m_pdsc = NULL;
	}
	
}

void CJsonQueryParam::SetBasicSearchCondition(LPCTSTR searchText, bool exact)
{
	if (NULL != m_pbsc)
	{
		delete m_pbsc;
		m_pbsc = NULL;
	}

	m_pbsc = new BasicSearchCondition_t;
	m_pbsc->lpText = searchText;
	m_pbsc->exact = exact;
}

void CJsonQueryParam::SetDateSearchCondition(LPCTSTR startDate, LPCTSTR endDate)
{
	if (NULL != m_pdsc)
	{
		delete m_pdsc;
		m_pdsc = NULL;
	}

	m_pdsc = new DateSearchCondition_t;
	m_pdsc->startDate = startDate;
	m_pdsc->endDate = endDate;
}

void CJsonQueryParam::AddSortCondition(int col, bool asc)
{
	SortCondition_t sc;
	sc.col = col;
	sc.asc = asc;
	m_scs.push_back(sc);
}

void CJsonQueryParam::AddApproveCondition(int type, bool approved)
{
	ApproveCondition_t ac;
	ac.approved = approved;
	ac.type = type;
	m_acs.push_back(ac);
}

void CJsonQueryParam::AddAdvancedCondition(StringArrayPtr pac)
{
	m_pAdvanced = pac;
}

void CJsonQueryParam::toJson(CString& json, IApproveTypeTranslator* translator)
{
	std::shared_ptr<Json::JsonObject> jquery((Json::JsonObject*)(Json::JsonFactory::createObject()));
	if (NULL != m_pbsc || NULL != m_pdsc || NULL != m_pAdvanced){
		Json::JsonObject& jSearch = jquery->add(L"search", Json::JsonFactory::createObject()).asObject(L"search");
		if (NULL != m_pbsc)
		{
			Json::JsonObject& jBasic = jSearch.add(L"basic", Json::JsonFactory::createObject()).asObject(L"basic");
			jBasic.add(L"text", Json::JsonFactory::createString((Json::json_char*)m_pbsc->lpText));
			jBasic.add(L"exact", Json::JsonFactory::createBool(m_pbsc->exact));
		}

		if (NULL != m_pdsc)
		{
			Json::JsonObject& jDate = jSearch.add(L"date", Json::JsonFactory::createObject()).asObject(L"date");
			jDate.add(L"startDate", Json::JsonFactory::createString((Json::json_char*)m_pdsc->startDate));
			jDate.add(L"endDate", Json::JsonFactory::createString((Json::json_char*)m_pdsc->endDate));
		}

		if (NULL != m_pAdvanced)
		{
			Json::JsonArray& jAdvance = jSearch.add(L"advanced", Json::JsonFactory::createArray()).asArray(L"advanced");
			for (int i = 0, len = m_pAdvanced->size(); i < len; ++i){
				jAdvance.add(Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)m_pAdvanced->at(i)));
			}
		}
	}

	if (!m_acs.empty() && NULL != translator){
		LPCTSTR approveType = NULL;
		Json::JsonArray& jApprove = jquery->add(L"approve", Json::JsonFactory::createArray()).asArray(L"approve");
		for (int i = 0, len = m_acs.size(); i < len; ++i){
			approveType = translator->Translate(m_acs.at(i).type);
			if (NULL != approveType)
			{
				Json::JsonObject& jApproveItem = jApprove.add(Json::JsonFactory::createObject()).asObject(i);
				jApproveItem.add(L"type", Json::JsonFactory::createString((Json::json_char*)approveType));
				jApproveItem.add(L"approved", Json::JsonFactory::createBool(m_acs.at(i).approved));
			}
		}
	}

	if (!m_scs.empty()){
		Json::JsonArray& jSort = jquery->add(L"sort", Json::JsonFactory::createArray()).asArray(L"sort");
		for (int i = 0, len = m_scs.size(); i < len; ++i){
			Json::JsonObject& jSortItem = jSort.add(Json::JsonFactory::createObject()).asObject(i);
			jSortItem.add(L"col", Json::JsonFactory::createInt(m_scs.at(i).col));
			jSortItem.add(L"order", Json::JsonFactory::createBool(m_scs.at(i).asc));
		}
	}

	Json::json_stringstream jss;
	jquery->asJson(jss);
	json = jss.str().c_str();
}
