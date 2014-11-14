#pragma once

#include <vector>

#include "Delegate.h"
class CMenuManager;

class IMenu
{
public:
	virtual void ShowMenu(int iX, int iY) = 0;
	virtual void ShowMenu(void) = 0;	//Show the menu in the latest place
	virtual void HideMenu(void) = 0;
	virtual BOOL IsMenuShow(void) = 0;
	virtual void Command(int iCmdID, __in void* pArg, __out void* pRet)
    {
        UNREFERENCED_PARAMETER(iCmdID);
        UNREFERENCED_PARAMETER(pArg);
        UNREFERENCED_PARAMETER(pRet);
    };
	virtual void OnMenuNotify(int iMenuID, BOOL bShow)
	{
		d_OnMenuShowHide(iMenuID, bShow);
	}
	virtual ~IMenu(){}
	CDelegate<void(int iMenuID, BOOL bShow)>	d_OnMenuShowHide;	
};

typedef struct tagMenuInfo_t
{
	int iMenuID;
	IMenu* pMenu;
}MenuInfo_t;


typedef struct tagBroadRetValue_t
{
	int iMenuID;
	BOOL bRet;
}BroadRetValue_t;

class CMenuManager
{
public:
	CMenuManager(void);
	~CMenuManager(void);
	void RegMenu(int iMenuID, IMenu* pMenu);
	void UnRegMenu(int iMenuID);
	void ShowMenu(int iMenuID, int iX, int iY);
	void ShowMenuMutex(int iMenuID, int iX, int iY);
	void ShowMenuMutex(int iMenuID);
	void ShowMenu(int iMenuID);
	void HideMenu(int iMenuID);
	BOOL IsMenuShow(int iMenuID);
	void HideAllMenu(std::vector<int>& vecExclude);
	void ShowAllMenu(std::vector<int>& vecExclude);
	void HideAllMenu(void);
	void ShowAllMenu(void);
	int GetMenuCount(void);
	IMenu* GetMenu(int iMenuID);
	BOOL Command(int iMenuID, int iCmdID, __in void* pArg, __out void* pRet );
	void BroadCast(int iCmdID, __in void* pArg, __out std::vector<BroadRetValue_t>& RetVec);
	void OnMenuShowHide(int iMenuId, BOOL bShow);

	CDelegate<void(int iMenuID, BOOL bShow)>	d_OnMenuShowHide;	

protected:
	std::vector<MenuInfo_t>  m_vecMenuInfo;
};

