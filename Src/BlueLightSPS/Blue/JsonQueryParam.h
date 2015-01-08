#pragma once

#include <vector>
#include <map>
#include "IHttp.h"
//{
//approve : [[{
//	type : bussiness / plan,
//	approved : true/false
//}],[{
//	type : bussiness / plan,
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
//	advancedQyery : [{
//		group : [{
//					item : {
//						col: 1/2/3,
//						param: string
//					}
//					and : true/false
//		},{
//			item : {
//						col: 1/2/3,
//						param: string
//					}
//			and : true/false
//		},{
//			group: [{
//				item : {
//						col: 1/2/3,
//						param: string
//					}
//				and : true/false
//			}],
//		}],
//	},{
//				item : {
//						col: 1/2/3,
//						param: string
//					}
//				and : true/false
//			}]
//},
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


class CAdvanceQuery{
	typedef struct tagQueryCondition_t{
		std::shared_ptr<CAdvanceQuery> pAdvanceQuery;
		bool bIsAnd;
	}QueryCondition_t;
public:
	CAdvanceQuery(int index, LPCTSTR param);
	~CAdvanceQuery();
	CAdvanceQuery& and(CAdvanceQuery* advanceQuery);
	CAdvanceQuery& or(CAdvanceQuery* advanceQuery);
	CAdvanceQuery& pack();
	void toJson(CString& json);
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
	void toJson(CString& json, IApproveTypeTranslator* translator);
private:
	BasicSearchCondition_t* m_pbsc;
	DateSearchCondition_t* m_pdsc;
	std::vector<SortCondition_t> m_scs;
	std::map<int, std::vector<ApproveCondition_t>> m_acsMap;
	StringArrayPtr m_pAdvanced;
};

