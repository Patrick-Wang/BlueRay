#include "StdAfx.h"
#include <algorithm>
#include "MenuManager.h"


CMenuManager::CMenuManager(void)
{
}


CMenuManager::~CMenuManager(void)
{
}


void CMenuManager::RegMenu( int iMenuID, IMenu* pMenu )
{
	if (NULL != pMenu)
	{
		MenuInfo_t stMenuInfo = {iMenuID, pMenu};
		m_vecMenuInfo.push_back(stMenuInfo);
		pMenu->d_OnMenuShowHide += make_pair(this, &CMenuManager::OnMenuShowHide);
	}
}




void CMenuManager::ShowMenu( int iMenuID, int iX, int iY )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].iMenuID == iMenuID)
			{
				m_vecMenuInfo[ui].pMenu->ShowMenu(iX, iY);
				break;
			}
		}
	}
}

void CMenuManager::ShowMenu( int iMenuID )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].iMenuID == iMenuID)
			{
				m_vecMenuInfo[ui].pMenu->ShowMenu();
				break;
			}
		}
	}
}

void CMenuManager::UnRegMenu( int iMenuID )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (iMenuID == m_vecMenuInfo[ui].iMenuID)
		{
			m_vecMenuInfo[ui].pMenu->d_OnMenuShowHide -= make_pair(this, &CMenuManager::OnMenuShowHide);
			m_vecMenuInfo.erase(m_vecMenuInfo.begin() + ui);
			break;
		}
	}
}

void CMenuManager::HideMenu( int iMenuID )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].iMenuID == iMenuID)
			{
				m_vecMenuInfo[ui].pMenu->HideMenu();
				break;
			}
		}
	}
}

BOOL CMenuManager::IsMenuShow( int iMenuID )
{
	BOOL bRet = FALSE;
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].iMenuID == iMenuID)
			{
				bRet = m_vecMenuInfo[ui].pMenu->IsMenuShow();
				break;
			}
		}
	}
	return bRet;
}

void CMenuManager::HideAllMenu( std::vector<int>& vecExclude )
{
	std::vector<int>::iterator pIt;
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].pMenu->IsMenuShow())
			{
				pIt = std::find(vecExclude.begin(), vecExclude.end(), m_vecMenuInfo[ui].iMenuID);
				if (pIt == vecExclude.end())
				{
					m_vecMenuInfo[ui].pMenu->HideMenu();
				}
			}
		}
	}
}

void CMenuManager::HideAllMenu( void )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (m_vecMenuInfo[ui].pMenu->IsMenuShow())
			{
				m_vecMenuInfo[ui].pMenu->HideMenu();
			}
		}
	}
}

void CMenuManager::ShowAllMenu( std::vector<int>& vecExclude )
{
    UNREFERENCED_PARAMETER(vecExclude);
}

void CMenuManager::ShowAllMenu( void )
{
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (NULL != m_vecMenuInfo[ui].pMenu)
		{
			if (!m_vecMenuInfo[ui].pMenu->IsMenuShow())
			{
				m_vecMenuInfo[ui].pMenu->ShowMenu();
			}
		}
	}
}

int CMenuManager::GetMenuCount( void )
{
	return (int)m_vecMenuInfo.size();
}


BOOL CMenuManager::Command(int iMenuID, int iCmdID, __in void* pArg, __out void* pRet )
{
	BOOL bRet = FALSE;
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (iMenuID == m_vecMenuInfo[ui].iMenuID)
		{
			if (m_vecMenuInfo[ui].pMenu)
			{
				m_vecMenuInfo[ui].pMenu->Command(iCmdID, pArg, pRet);
				bRet = TRUE;
			}
			break;
		}
	}
	return bRet;
}

void CMenuManager::ShowMenuMutex( int iMenuID, int iX, int iY )
{
	std::vector<int> vecMenu;
	vecMenu.push_back(iMenuID);
	HideAllMenu(vecMenu);
	ShowMenu(iMenuID, iX, iY);
}

void CMenuManager::ShowMenuMutex( int iMenuID )
{
	std::vector<int> vecMenu;
	vecMenu.push_back(iMenuID);
	HideAllMenu(vecMenu);
	ShowMenu(iMenuID);
}

IMenu* CMenuManager::GetMenu( int iMenuID )
{
	IMenu* pRet = NULL;
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (iMenuID == m_vecMenuInfo[ui].iMenuID)
		{
			pRet = m_vecMenuInfo[ui].pMenu;
			break;
		}
	}
	return pRet;
}

void CMenuManager::BroadCast( int iCmdID, __in void* pArg,  __out std::vector<BroadRetValue_t>& RetVec)
{
	BroadRetValue_t stBroadRet = {0};
	for (UINT ui = 0; ui < m_vecMenuInfo.size(); ++ui)
	{
		if (m_vecMenuInfo[ui].pMenu)
		{
			stBroadRet.iMenuID = m_vecMenuInfo[ui].iMenuID;
			m_vecMenuInfo[ui].pMenu->Command(iCmdID, pArg, &(stBroadRet.bRet));
			RetVec.push_back(stBroadRet);
		}
	}

}

void CMenuManager::OnMenuShowHide( int iMenuId, BOOL bShow )
{
	d_OnMenuShowHide(iMenuId, bShow);
}


