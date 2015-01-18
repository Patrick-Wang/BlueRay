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

		MPZLXX,	//���Ƶ�����

		ZJDY,	//������ѹ

		ZJYS,	//������ɫ

		ZDQXH,	//�ƶ����ͺ�

		BZXDTGG,// ��װ��/���й��

		ZZS,	// ������

		KHQY	// �ͻ�����

	};
	CItem();
	~CItem();

	bool QuerySync(ItemType type, StringArray& retArray);
	CPromise<StringArray>& Query(ItemType type);
private:
	bool toURL(ItemType type, CString& url);
};

