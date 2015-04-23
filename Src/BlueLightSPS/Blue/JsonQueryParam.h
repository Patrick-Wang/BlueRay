#pragma once

#include <vector>
#include <map>
#include "JsonObjects.h"
#include "IHttp.h"
//{
//approve : [[{
//	type : business / plan,
//	approved : true/false
//}],[{
//	type : business / plan,
//	approved : true/false
//}]],
//search : {
//	advanced : [],
//	basic : {
//		text : searchtext,
//		exact : true/false
//	},
//	date : {
//		startDate : 
//		endDate : 
//	}
//	"united": [
//	{
//		"col": 1,
//			"param" : "1111"
//	},
//	{
//		"and": true
//	},
//	{
//		"group": [
//		{
//			"col": 2,
//				"param" : "123"
//		},
//		{
//			"and": false
//		},
//		{
//			"col": 3,
//			"param" : "1243"
//		}
//		]
//	},
//	{
//		"and": false
//	},
//	{
//		"col": 8,
//		"param" : "123"
//	}
//],
//sort : [
//    {
//    	col : index,
//    	order : true/false
//    },
//    {
//    	col : index,
//    	order : true/false
//    }
//]
//}

#define UQ(col, param)	CUnitedQuery::Create(col, param)

class CUnitedQuery{
	typedef struct tagQueryCondition_t{
		std::shared_ptr<CUnitedQuery> pAdvanceQuery;
		bool bIsAnd;
	}QueryCondition_t;
private:
	CUnitedQuery(int index, LPCTSTR param);
public:
	static CUnitedQuery& Create(int index, LPCTSTR param);
	
	~CUnitedQuery();
	CUnitedQuery& and(CUnitedQuery& advanceQuery);
	CUnitedQuery& or(CUnitedQuery& advanceQuery);
	CUnitedQuery& group();
	Json::JsonArray* toJson();
private:
	int m_iPack;
	int m_iColIndex;
	CString m_strParam;
	std::vector<QueryCondition_t*> m_vecQuerys;
};


class CJsonQueryParam
{
public:
	typedef struct tagBasicSearchCondition_t{
		CString lpText;
		bool exact;
	}BasicSearchCondition_t;

	typedef struct tagDateSearchCondition_t{
		CString startDate;
		CString endDate;
	}DateSearchCondition_t;

	typedef struct tagSortCondition_t{
		int col;
		bool asc;
	}SortCondition_t;

	typedef struct tagApproveCondition_t{
		int type;
		bool approved;
	}ApproveCondition_t;

	class IApproveTypeTranslator{
	public:
		virtual ~IApproveTypeTranslator(){};
		virtual LPCTSTR Translate(int type) = 0;
	};

	CJsonQueryParam();
	~CJsonQueryParam();
	void SetBasicSearchCondition(LPCTSTR searchText, bool exact);
	void SetDateSearchCondition(LPCTSTR startDate, LPCTSTR endDate);
	void AddSortCondition(int col, bool asc);
	void AddApproveCondition(int type, bool approved, int group = 0);
	void SetAdvancedCondition(StringArrayPtr pac);
	void SetUnitedQuery(CUnitedQuery& uq);
	void toJson(CString& json, IApproveTypeTranslator* translator);
private:
	BasicSearchCondition_t* m_pbsc;
	DateSearchCondition_t* m_pdsc;
	std::vector<SortCondition_t> m_scs;
	std::map<int, std::vector<ApproveCondition_t>> m_acsMap;
	StringArrayPtr m_pAdvanced;
	std::shared_ptr<CUnitedQuery> m_pAq;
};

