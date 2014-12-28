#pragma once

#include <vector>
#include "IHttp.h"
//{
//approve : [{
//	type : bussiness / plan,
//	approved : true/false
//}],
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

class CJsonQueryParam
{
public:
	typedef struct tagBasicSearchCondition_t{
		LPCTSTR lpText;
		bool exact;
	}BasicSearchCondition_t;

	typedef struct tagDateSearchCondition_t{
		LPCTSTR startDate;
		LPCTSTR endDate;
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
	void AddApproveCondition(int type, bool approved);
	void AddAdvancedCondition(StringArrayPtr pac);
	void toJson(CString& json, IApproveTypeTranslator* translator);
private:
	BasicSearchCondition_t* m_pbsc;
	DateSearchCondition_t* m_pdsc;
	std::vector<SortCondition_t> m_scs;
	std::vector<ApproveCondition_t> m_acs;
	StringArrayPtr m_pAdvanced;
};

