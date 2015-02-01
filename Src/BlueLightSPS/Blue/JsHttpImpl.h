#pragma once
#include "IHttp.h"
#include "IJSMediator.h"
#include "ComJsFun.h"
#include <thread>
#include "STDThreadPool.h"
class CJsHttpImpl :
	public IHttp
{
public:
	CJsHttpImpl(IJSMediator* lpJsMediator, CWnd* pWnd = NULL);
	~CJsHttpImpl();
	virtual void Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStream);
	virtual void Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream) ;
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr);
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, IntArrayPtr>& mapAttr);
	virtual void Post(LPCTSTR lpAddr, int id, std::map<CString, StringArrayPtr>& mapAttr);
	virtual void Get(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr);
	virtual void Get(LPCTSTR lpAddr, int id, StringArrayPtr rest);
	virtual void Get(LPCTSTR lpAddr, int id);
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret);
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, IntArrayPtr>& mapAttr, CString& ret);
	virtual bool SyncPost(LPCTSTR lpAddr, std::map<CString, StringArrayPtr>& mapAttr, CString& ret);
	virtual bool SyncGet(LPCTSTR lpAddr, std::map<CString, CString>& mapAttr, CString& ret);
	virtual bool SyncGet(LPCTSTR lpAddr, StringArrayPtr rest, CString& ret);
	virtual bool SyncGet(LPCTSTR lpAddr, CString& ret);
protected:
	void OnThreadComplete(GUID* pThreadId);
	void DoUpload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IInputStream> pStream, GUID guid);
	void DoDownload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IOutputStream> pStream, GUID guid);
	VARIANT OnPost(int id, const std::vector<VARIANT>& params);
	VARIANT OnGet(int id, const std::vector<VARIANT>& params);
	void MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& attr, CString& url);
	void MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url);
	void AsJson(std::map<CString, CString>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, IntArrayPtr>& mapAttr, CString& strJson);
	void AsJson(std::map<CString, StringArrayPtr>& mapAttr, CString& strJson);
	static LRESULT CALLBACK WindowProc(
		_In_  HWND hwnd,
		_In_  UINT uMsg,
		_In_  WPARAM wParam,
		_In_  LPARAM lParam
	);
private:
	IJSMediator* m_lpJsMediator;
	CSTDThreadPool m_threadPool;
	static CComJsFun m_funPost;
	static CComJsFun m_funGet;
	static WNDPROC m_lpfnOldProc;
	CWnd* m_pWnd;
};

