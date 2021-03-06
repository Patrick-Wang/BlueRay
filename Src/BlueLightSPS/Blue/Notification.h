#pragma once

#include "HttpServerInterface.h"
#include "Promise.h"
class CNotification : public CHttpServerInterface
{

public:
	typedef struct tagUnapproved_t{
		int iSaleBussiness = 0;
		int iSalePlan = 0;
		int iPlanBussiness = 0;
		int iPlanPlan = 0;
		int iPackBussiness = 0;
		int iPackPlan = 0;
	}Unapproved_t;


	CNotification();
	~CNotification();

	bool GetUnapprovedSync(Unapproved_t& stUnapproved);
	CPromise<Unapproved_t>& GetUnapproved();

};

