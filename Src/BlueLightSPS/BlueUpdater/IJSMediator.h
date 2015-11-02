#pragma once
#include <vector>
#include <oaidl.h>
class IJSMediator
{
public:

	class IJSFunction{
	public:
		virtual ~IJSFunction(){};
		virtual VARIANT Call(std::vector<VARIANT>& params) = 0;
		virtual LPCTSTR Name() = 0;
		virtual int Id() = 0;
	};

	virtual ~IJSMediator(){};
	virtual VARIANT CallJsFunction(LPCWSTR lpFunName, std::vector<VARIANT>& params) = 0;
	virtual void RegisterJsFunction(IJSFunction* jsEvent) = 0;
	virtual void UnRegisterJsFunction(IJSFunction* jsEvent) = 0;
};

