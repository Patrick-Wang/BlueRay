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
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, std::vector<int>*>& mapAttr);
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, std::vector<CString>*>& mapAttr);
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr);

protected:
	VARIANT OnPost(int id, const std::vector<VARIANT>& params);
	VARIANT OnGet(int id, const std::vector<VARIANT>& params);
	void MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& attr, CString& url);
	void AsJson(std::map<CString, CString>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, std::vector<int>*>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, std::vector<CString>*>& mapAttr, CString& strJson);
private:
	IJSMediator* m_lpJsMediator;
	//std::pair<CJsHttpImpl&, VARIANT(int, const std::vector<VARIANT>&)> m_post;
	//std::pair<CJsHttpImpl&, VARIANT(int, const std::vector<VARIANT>&)> m_get;
	static CComJsFun m_funPost;
	static CComJsFun m_funGet;
};

