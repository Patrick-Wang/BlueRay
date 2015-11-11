#pragma once
#include "IHttp.h"
#include <thread>
#include "ThreadPool.h"
#include "IMessageStation.h"
#include "ThreadCorrespondent.h"
class CWinHttpImpl :
	public IHttp
{
public:
	CWinHttpImpl();
	~CWinHttpImpl();
	virtual void Upload(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IInputStream> pStream);
	virtual void Download(LPCTSTR lpAddr, int id, std::map<CString, CString>& mapAttr, std::shared_ptr<IOutputStream> pStream) ;
//protected:
//	virtual void OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	void OnThreadComplete(GUID* pThreadId);
	void DoUpload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IInputStream> pStream, GUID guid);
	void DoDownload(CString lpAddr, int id, std::map<CString, CString> mapAttr, std::shared_ptr<IOutputStream> pStream, GUID guid);
	void MakeUrl(LPCTSTR lpAddr, std::map<CString, CString>& attr, CString& url);
	void MakeUrl(LPCTSTR lpAddr, StringArrayPtr rest, CString& url);
private:
	//CThreadCorrespondent<void> m_correspondent;
	CThreadPool m_threadPool;
	CDelegate<void(GUID*)> d_OnThreadComplete;
	//static WNDPROC m_lpfnOldProc;
	//static std::vector<CWinHttpImpl*> m_instances;
	//static HWND m_pWnd;
};

