#pragma once
#include <WTypes.h>
#include "IHttp.h"
#include <memory>

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

#define CONSTRUCTOR_3(name, ty1, arg1, ty2, arg2, ty3, arg3) \
public:\
	name(ty1 arg1, ty2 arg2, ty3 arg3):m_##arg1(arg1), m_##arg2(arg2), m_##arg3(arg3){}\
private:\
	ty1 m_##arg1;\
	ty2 m_##arg2;\
	ty3 m_##arg3;

template<typename _T>
class CPromise
{
public:
	class IHttpResponse {
	public:
		virtual void OnSuccess(_T& ret) = 0;
		virtual void OnFailed() = 0;
		virtual ~IHttpResponse(){};
	};

	class IRespParser {
	public:
		virtual _T& OnParse(LPCTSTR strRet) = 0;
		virtual ~IRespParser(){};
	};

	static CPromise* MakePromise(IHttp* pHttp, IRespParser* pRespParser){
		return new CPromise(pHttp, pRespParser);
	}
	~CPromise(){

		if (NULL != m_lpHttp)
		{
			m_lpHttp->d_OnSuccess -= std::make_pair(this, &CPromise::OnSuccess);
			m_lpHttp->d_OnFailed -= std::make_pair(this, &CPromise::OnFailed);
		}
	}

	int GetId(){
		return (int)this;
	}

private:
	CPromise(IHttp* pHttp, IRespParser* pRespParser) 
		: m_lpHttp(pHttp)
		, m_pRespParser(pRespParser){

		if (NULL != m_lpHttp)
		{
			m_lpHttp->d_OnSuccess += std::make_pair(this, &CPromise::OnSuccess);
			m_lpHttp->d_OnFailed += std::make_pair(this, &CPromise::OnFailed);
		}
	}
private:
	std::auto_ptr<IRespParser> m_pRespParser;
public:
	CPromise& then(IHttpResponse* resp){
		m_resps.push_back(std::shared_ptr<IHttpResponse>(resp));
		return *this;
	}
protected:
	void OnSuccess(int id, LPCTSTR strRet){
		if ((int)this == id)
		{
			_T& val = m_pRespParser->OnParse(strRet);
			for (int i = 0, len = m_resps.size(); i < len; ++i)
			{
				m_resps[i]->OnSuccess(val);
			}
			delete this;
		}
	}
	void OnFailed(int id){

		if ((int)this == id)
		{
			for (int i = 0, len = m_resps.size(); i < len; ++i)
			{
				m_resps[i]->OnFailed();
			}
			delete this;
		}
	}
	IHttp* m_lpHttp;
	std::vector<std::shared_ptr<IHttpResponse>> m_resps;
};

class CBoolParser : public CPromise<bool>::IRespParser
{
public:
	virtual bool& OnParse(LPCTSTR strRet){
		m_bRet = (0 == _tcscmp(L"success", strRet));
		return m_bRet;
	}
private:
	bool m_bRet;
};

class CIntParser : public CPromise<int>::IRespParser{
public:
	virtual int& OnParse(LPCTSTR strJson){
		m_ret = _tstoi(strJson);
		return m_ret;
	}
private:
	int m_ret;
};

