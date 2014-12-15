#pragma once
#include "IHttp.h"
#include "HttpServerInterface.h"

class CItem : public CHttpServerInterface
{
public:
	enum ItemType{
		KHXX,//客户名称

		CPGGXHXX,//规格型号

		ZCXX,	//轴承

		ZDQDYFLXX,//制动器电压

		YYLGGFLXX,	//曳引轮规格

		BPQXHFLXX,	//变频器型号


		BMQXHFLXX,	//编码器型号

		MPZLXX	//铭牌等资料

	};
	CItem();
	~CItem();

	bool Query(ItemType type, StringArray& retArray);

};

