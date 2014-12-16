#pragma once
#include <WTypes.h>
#include "IHttp.h"
#include <memory>
#include "User.h"


template<typename _T1>
class CPromise{

};

#define MAKE_PROMISE(T, success) \
template<>\
class CPromise<T>\
{\
public:\
class IHttpResponse {\
public:\
	   virtual void OnSuccess(T stret) = 0; \
	   virtual void OnFailed() = 0; \
	   virtual ~IHttpResponse(){}; \
}; \
	static CPromise* MakePromise(IHttp* pHttp){\
		return new CPromise(pHttp);\
	}\
	~CPromise(){\
		if (NULL != m_lpHttp)\
		{\
			m_lpHttp->d_OnSuccess -= std::make_pair(this, &CPromise::OnSuccess);\
			m_lpHttp->d_OnFailed -= std::make_pair(this, &CPromise::OnFailed);\
		}\
	}\
private:\
	CPromise(IHttp* pHttp) : m_lpHttp(pHttp){\
		if (NULL != m_lpHttp)\
		{\
			m_lpHttp->d_OnSuccess += std::make_pair(this, &CPromise::OnSuccess);\
			m_lpHttp->d_OnFailed += std::make_pair(this, &CPromise::OnFailed);\
		}\
	}\
public:\
	CPromise& then(IHttpResponse* resp){\
		m_resps.push_back(std::shared_ptr<IHttpResponse>(resp)); \
		return *this;\
	}\
protected:\
	void OnSuccess(int id, LPCTSTR strRet){\
		if ((int)this == id)\
		{\
			for (int i = 0, len = m_resps.size(); i < len; ++i)\
			{\
				success(m_resps[i].get(), strRet);\
			}\
			delete this;\
		}\
	}\
	void OnFailed(int id){\
		if ((int)this == id)\
		{\
			for (int i = 0, len = m_resps.size(); i < len; ++i)\
			{\
				m_resps[i]->OnFailed();\
			}\
			delete this;\
		}\
	}\
	IHttp* m_lpHttp;\
	std::vector<std::shared_ptr<IHttpResponse>> m_resps; \
};

template < typename _Ty > 
class CHolder{
public:
	CHolder(_Ty handle) : m_handle(handle){}
	virtual ~CHolder(){}
protected:
	_Ty m_handle;
};


#define CONSTRUCTOR_1(name, ty1, arg1) \
public:\
	name(ty1 arg1):m_##arg1(arg1){}\
private:\
	ty1 m_##arg1;

#define CONSTRUCTOR_2(name, ty1, arg1, ty2, arg2) \
public:\
	name(ty1 arg1, ty2 arg2):m_##arg1(arg1), m_##arg2(arg2){}\
private:\
	ty1 m_##arg1;\
	ty2 m_##arg2;

extern CUser* StringToUser(LPCTSTR strJson);
#define USER_SUCCESS(resp, strRet) \
	resp->OnSuccess(StringToUser(strRet))

MAKE_PROMISE(CUser*, USER_SUCCESS)


#define STRING_SUCCESS(resp, strRet) \
	resp->OnSuccess(0 == _tcscmp(strRet, L"success"))

MAKE_PROMISE(bool, STRING_SUCCESS)

