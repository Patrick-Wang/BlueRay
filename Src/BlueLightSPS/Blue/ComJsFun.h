#pragma once
#include "IJSMediator.h"
#include "Delegate.h"
class CComJsFun :
	public IJSMediator::IJSFunction{
public:
	CComJsFun(LPCTSTR lpName, int id)
		: m_name(lpName)
		, m_Id(id){
	}

	VARIANT Call(std::vector<VARIANT>& params){
		return d_onJsCall(m_Id, params);
	}

	LPCTSTR Name(){
		return m_name;
	}

	int Id(){
		return m_Id;
	}

	CDelegate<VARIANT(int, const std::vector<VARIANT>&)> d_onJsCall;

private:
	int m_Id;
	CString m_name;
};

