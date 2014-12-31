#pragma once
#include "IJSMediator.h"
#include "Delegate.h"
class CComJsFun :
	public IJSMediator::IJSFunction{
public:
	CComJsFun(LPCTSTR lpName)
		: m_name(lpName){
	}

	VARIANT Call(std::vector<VARIANT>& params){
		return d_onJsCall((int)this, params);
	}

	LPCTSTR Name(){
		return m_name;
	}

	int Id(){
		return (int)this;
	}

	CDelegate<VARIANT(int, const std::vector<VARIANT>&)> d_onJsCall;

private:
	CString m_name;
};

