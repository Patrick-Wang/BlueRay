#pragma once
#include "IHttp.h"
#include "IJSMediator.h"
#include "ComJsFun.h"
class CJsHttpImpl :
	public IHttp
{
public:
	CJsHttpImpl(IJSMediator* lpJsMediator);
	~CJsHttpImpl();
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr);
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, IntArrayPtr>& mapAttr);
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, StringArrayPtr>& mapAttr);
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr);
	virtual void Get(LPCTSTR lpAddr, int id, StringArrayPtr rest);
	virtual void Get(LPCTSTR lpAddr, int id);
protected:
	VARIANT OnPost(int id, const std::vector<VARIANT>& params);
	VARIANT OnGet(int id, const std::vector<VARIANT>& params);
	void MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& attr, CString& url);
	void MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url);
	void AsJson(std::map<CString, CString>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, IntArrayPtr>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, StringArrayPtr>& mapAttr, CString& strJson);
private:
	IJSMediator* m_lpJsMediator;
	//std::pair<CJsHttpImpl&, VARIANT(int, const std::vector<VARIANT>&)> m_post;
	//std::pair<CJsHttpImpl&, VARIANT(int, const std::vector<VARIANT>&)> m_get;
	static CComJsFun m_funPost;
	static CComJsFun m_funGet;
};

