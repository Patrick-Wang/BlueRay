#pragma once
#include "IMessageStation.h"
#include <mutex>
#include <map>

#define WM_THREADCORESPONDENT	WM_APP + 3215

typedef struct ThreadWindowReference_t
{
	int ref;
	HWND hWnd;
}ThreadWindowReference;

template<typename RType>
class CThreadCorrespondentBase
{
public:
	CThreadCorrespondentBase(IMessageStation<RType>* lpMsgStation)
		: m_lpMsgStation(lpMsgStation)
		, m_dwThreadId(GetCurrentThreadId())
		, m_hWnd(NULL)
	{
		m_mutex.lock();
		std::map<DWORD, ThreadWindowReference>::iterator it = m_threadWndMap.find(m_dwThreadId);
		if (it != m_threadWndMap.end())
		{
			++(it->second.ref);
		}
		m_mutex.unlock();
	}

	virtual ~CThreadCorrespondentBase()
	{
		m_mutex.lock();
		std::map<DWORD, ThreadWindowReference>::iterator it = m_threadWndMap.find(m_dwThreadId);
		if (it != m_threadWndMap.end())
		{
			--(it->second.ref);
			if (0 == it->second.ref)
			{
				DestroyWindow(it->second.hWnd);
				m_threadWndMap.erase(it);
			}
		}
		m_mutex.unlock();
	}

protected:

	void UpdateWnd()
	{
		HWND hWnd = NULL;
		m_mutex.lock();
		std::map<DWORD, ThreadWindowReference>::iterator it = m_threadWndMap.find(m_dwThreadId);
		if (it != m_threadWndMap.end())
		{
			m_hWnd = it->second.hWnd;
		}
		else
		{
			if (NULL == m_atom)
			{
				RegisterClass();
			}

			m_hWnd = CreateWindow(m_szWindowClass, NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, GetModuleHandle(NULL), NULL);
			ThreadWindowReference& twr = m_threadWndMap[m_dwThreadId];
			twr.ref = 1;
			twr.hWnd = m_hWnd;
		}
		m_mutex.unlock();
	}

	virtual WNDPROC GetWndProc() = 0;

	void RegisterClass()
	{
		GUID guid = {};
		::CoCreateGuid(&guid);
		wsprintf(m_szWindowClass, L"{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
			, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
			, guid.Data4[6], guid.Data4[7]);

		WNDCLASSEX wcex = {};
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = GetWndProc();
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = GetModuleHandle(NULL);
		wcex.hIcon = NULL;
		wcex.hCursor = NULL;
		wcex.hbrBackground = NULL;
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = m_szWindowClass;
		wcex.hIconSm = NULL;
		m_atom = RegisterClassEx(&wcex);
	}

	IMessageStation<RType>* m_lpMsgStation;
	DWORD m_dwThreadId;
	HWND m_hWnd;
	static std::mutex m_mutex;
	static std::map<DWORD, ThreadWindowReference> m_threadWndMap;
	static ATOM m_atom;
	static TCHAR m_szWindowClass[100];
};

template<typename RType>
std::map<DWORD, ThreadWindowReference> CThreadCorrespondentBase<RType>::m_threadWndMap;
template<typename RType>
std::mutex CThreadCorrespondentBase<RType>::m_mutex;
template<typename RType>
ATOM CThreadCorrespondentBase<RType>::m_atom = NULL;
template<typename RType>
TCHAR CThreadCorrespondentBase<RType>::m_szWindowClass[100] = {};



template<typename RType>
class MessageStationLPARAM
{
public:
	UINT uMsg;
	IMessageStation<RType>* pMsgStation;
	LPARAM lParam;
	RType result;
};

template<>
class MessageStationLPARAM < void >
{
public:
	UINT uMsg;
	IMessageStation<void>* pMsgStation;
	LPARAM lParam;
};

template<typename RType>
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
template<>
LRESULT CALLBACK WindowProc<void>(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);


template<typename RType>
class CThreadCorrespondent : public CThreadCorrespondentBase<RType>
{
public:
	CThreadCorrespondent(IMessageStation<RType>* lpMsgStation)
		: CThreadCorrespondentBase<RType>(lpMsgStation)
	{}

	RType Send(UINT uMsg, WPARAM wparam, LPARAM lParam)
	{
		MessageStationLPARAM<RType> msl = {
			uMsg, m_lpMsgStation, lParam, RType()
		};

		if (NULL != m_lpMsgStation)
		{
			if (m_hWnd == NULL)
			{
				UpdateWnd();
			}
			::SendMessage(m_hWnd, WM_THREADCORESPONDENT, wparam, (LPARAM)&(msl));
		}
		return msl.result;
	}

protected:
	virtual WNDPROC GetWndProc(){
		return WindowProc < RType > ;
	}
};

template<>
class CThreadCorrespondent<void> : public CThreadCorrespondentBase <void>
{
public:
	CThreadCorrespondent(IMessageStation<void>* lpMsgStation)
		: CThreadCorrespondentBase(lpMsgStation)
	{}

	void Send(UINT uMsg, WPARAM wparam, LPARAM lParam)
	{
		MessageStationLPARAM<void> msl = {
			uMsg, m_lpMsgStation, lParam
		};

		if (NULL != m_lpMsgStation)
		{
			if (m_hWnd == NULL)
			{
				UpdateWnd();
			}
			::SendMessage(m_hWnd, WM_THREADCORESPONDENT, wparam, (LPARAM)&(msl));
		}
	}
protected:
	virtual WNDPROC GetWndProc(){
		return WindowProc < void > ;
	}
};
