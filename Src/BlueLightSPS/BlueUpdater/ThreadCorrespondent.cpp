#include "stdafx.h"
#include "ThreadCorrespondent.h"

template<typename RType>
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	if (WM_THREADCORESPONDENT == uMsg)
	{
		MessageStationLPARAM<RType>* pMsl = (MessageStationLPARAM<RType>*)lParam;
		if (NULL != pMsl)
		{
			IMessageStation<RType>* lpMS = pMsl->pMsgStation;
			if (NULL != lpMS)
			{
				pMsl->result = lpMS->OnMessage(pMsl->uMsg, wParam, pMsl->lParam);
			}
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

template<>
LRESULT CALLBACK WindowProc<void>(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	if (WM_THREADCORESPONDENT == uMsg)
	{
		MessageStationLPARAM<void>* pMsl = (MessageStationLPARAM<void>*)lParam;
		if (NULL != pMsl)
		{
			IMessageStation<void>* lpMS = pMsl->pMsgStation;
			if (NULL != lpMS)
			{
				lpMS->OnMessage(pMsl->uMsg, wParam, pMsl->lParam);
			}
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
