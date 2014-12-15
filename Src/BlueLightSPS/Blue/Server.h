#pragma once

#include "IHttp.h"
#include "Sale.h"
#include "Notification.h"
#include "Item.h"
#include "Plan.h"
#include "Account.h"
class CServer
{
private:
	CServer();
public:
	~CServer();
	void SetHttp(IHttp* lpHttp);
	IHttp* GetHttp();
	CSale& GetSale();
	CPlan& GetPlan();
	CNotification& GetNotification();
	CItem& GetItem();
	CAccount& GetAccount();
	static CServer* GetInstance();
private:
	static CServer* ins;
	IHttp* m_lpHttp;
	CNotification m_clNotification;
	CItem m_clItem;
	CSale m_clSale;
	CPlan m_clPlan;
	CAccount m_clAccount;
};

