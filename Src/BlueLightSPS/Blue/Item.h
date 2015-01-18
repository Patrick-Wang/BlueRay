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

		MPZLXX,	//铭牌等资料

		ZJDY,	//主机电压

		ZJYS,	//主机颜色

		ZDQXH,	//制动器型号

		BZXDTGG,// 包装箱/底托规格

		ZZS,	// 制造商

		KHQY	// 客户区域

	};
	CItem();
	~CItem();

	bool QuerySync(ItemType type, StringArray& retArray);
	CPromise<StringArray>& Query(ItemType type);
private:
	bool toURL(ItemType type, CString& url);
};

