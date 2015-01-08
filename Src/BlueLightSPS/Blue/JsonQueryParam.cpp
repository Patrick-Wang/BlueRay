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

void CJsonQueryParam::AddApproveCondition(int type, bool approved, int group)
{
	ApproveCondition_t ac;
	ac.approved = approved;
	ac.type = type;
	m_acsMap[group].push_back(ac);
}

void CJsonQueryParam::SetAdvancedCondition(StringArrayPtr pac)
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
			jBasic.add(L"text", Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)m_pbsc->lpText));
			jBasic.add(L"exact", Json::JsonFactory::createBool(m_pbsc->exact));
		}

		if (NULL != m_pdsc)
		{
			Json::JsonObject& jDate = jSearch.add(L"date", Json::JsonFactory::createObject()).asObject(L"date");
			jDate.add(L"startDate", Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)m_pdsc->startDate));
			jDate.add(L"endDate", Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)m_pdsc->endDate));
		}

		if (NULL != m_pAdvanced)
		{
			Json::JsonArray& jAdvance = jSearch.add(L"advanced", Json::JsonFactory::createArray()).asArray(L"advanced");
			for (int i = 0, len = m_pAdvanced->size(); i < len; ++i){
				jAdvance.add(Json::JsonFactory::createString((Json::json_char*)(LPCTSTR)m_pAdvanced->at(i)));
			}
		}
	}

	if (!m_acsMap.empty() && NULL != translator){
		LPCTSTR approveType = NULL;
		Json::JsonArray& jApprove = jquery->add(L"approve", Json::JsonFactory::createArray()).asArray(L"approve");
		int k = 0;
		for (std::map<int, std::vector<ApproveCondition_t>>::iterator it = m_acsMap.begin(); it != m_acsMap.end(); ++it, ++k)
		{
			Json::JsonArray& jGroup = jApprove.add(Json::JsonFactory::createArray()).asArray(k);
			for (int i = 0, len = it->second.size(); i < len; ++i){
				approveType = translator->Translate(it->second.at(i).type);
				if (NULL != approveType)
				{
					Json::JsonObject& jApproveItem = jGroup.add(Json::JsonFactory::createObject()).asObject(i);
					jApproveItem.add(L"type", Json::JsonFactory::createString((Json::json_char*)approveType));
					jApproveItem.add(L"approved", Json::JsonFactory::createBool(it->second.at(i).approved));
				}
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

CAdvanceQuery::CAdvanceQuery(int index, LPCTSTR param)
	: m_iColIndex(index)
	, m_strParam(param)
	, m_iPack(-1)
{

}

CAdvanceQuery& CAdvanceQuery::and(CAdvanceQuery* advanceQuery)
{
	QueryCondition_t* queryCondition = new QueryCondition_t;
	queryCondition->pAdvanceQuery.reset(advanceQuery);
	queryCondition->bIsAnd = true;
	m_vecQuerys.push_back(queryCondition);
	return *this;
}

CAdvanceQuery& CAdvanceQuery::or(CAdvanceQuery* advanceQuery)
{
	QueryCondition_t* queryCondition = new QueryCondition_t;
	queryCondition->pAdvanceQuery.reset(advanceQuery);
	queryCondition->bIsAnd = false;
	m_vecQuerys.push_back(queryCondition);
	return *this;
}

CAdvanceQuery& CAdvanceQuery::pack()
{
	m_iPack = m_vecQuerys.size();
	return *this;
}

void CAdvanceQuery::toJson(CString& json)
{
	std::shared_ptr<Json::JsonObject> jquery((Json::JsonObject*)(Json::JsonFactory::createObject()));
	if (m_iPack >= 0)
	{

	}
	else
	{

	}
}

CAdvanceQuery::~CAdvanceQuery()
{
	for (int i = m_vecQuerys.size() - 1; i >= 0; --i)
	{
		delete m_vecQuerys[i];
		m_vecQuerys[i] = NULL;
	}
}
