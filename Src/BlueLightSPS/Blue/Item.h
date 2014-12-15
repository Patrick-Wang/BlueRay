#pragma once
#include "IHttp.h"
#include "HttpServerInterface.h"

class CItem : public CHttpServerInterface
{
public:
	enum ItemType{
		KHXX,//�ͻ�����

		CPGGXHXX,//����ͺ�

		ZCXX,	//���

		ZDQDYFLXX,//�ƶ�����ѹ

		YYLGGFLXX,	//ҷ���ֹ��

		BPQXHFLXX,	//��Ƶ���ͺ�


		BMQXHFLXX,	//�������ͺ�

		MPZLXX	//���Ƶ�����

	};
	CItem();
	~CItem();

	bool Query(ItemType type, StringArray& retArray);

};

