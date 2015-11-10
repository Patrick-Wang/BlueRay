#pragma once
#include "IHttp.h"
#include <thread>
#include "ThreadPool.h"
class CWinHttpImpl :
	public IHttp
{
public:
	CWinHttpImpl();
	~CWinHttpImpl();
	static void SetThreadWindow(HWND hWnd);
	virtual void Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStream);
	virtual void Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream) ;
protected:
	void OnThreadComplete(GUID* pThreadId);
	void DoUpload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IInputStream> pStream, GUID guid);
	void DoDownload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IOutputStream> pStream, GUID guid);
	void MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& attr, CString& url);
	void MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url);
	
	static LRESULT CALLBACK WindowProc(
		_In_  HWND hwnd,
		_In_  UINT uMsg,
		_In_  WPARAM wParam,
		_In_  LPARAM lParam
	);
private:
	CThreadPool m_threadPool;
	static WNDPROC m_lpfnOldProc;
	static std::vector<CWinHttpImpl*> m_instances;
	static HWND m_pWnd;
};

