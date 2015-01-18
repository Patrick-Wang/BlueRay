#pragma once
//Host

#ifdef _DEBUG
#define IDS_HOST_NAME             _T("localhost")
#else
#define IDS_HOST_NAME             _T("192.168.104.2")
#endif

//user setting location

#define IDS_SETTING_FILENAME				_T("\\setting.xml")
#define IDS_SETTING_ROOT_APPFOLDER			_T("\\BlueLightPLM")
#define IDS_SETTING_ROOT_SETTINGFOLDER		_T("\\settings")
#define IDS_SETTING_ROOT_FOLDER				_T("%appdata%")
#define IDS_SETTING_LOCATION				_T("%appdata%\\BlueLightPLM\\settings\\")

//setting item define

#define IDS_SETTING_ITEM_ROOT			_T("Settings")
#define IDS_SETTING_ITEM_TABLEFILTER	_T("TabFilter")
#define IDS_SETTING_ITEM_TABLEFILTER_SALE	_T("Sale")
#define IDS_SETTING_ITEM_TABLEFILTER_PLAN	_T("Plan")
#define IDS_SETTING_ITEM_TABLEFILTER_NOTIFICATION	_T("Notification")
#define IDS_SETTING_ITEM_COL_WIDTH	_T("ColWidths")


#define IDS_SETTING_ITEM_TABLEFILTER_HTH		_T("HTH")
#define IDS_SETTING_ITEM_TABLEFILTER_KHMC		_T("KHMC")
#define IDS_SETTING_ITEM_TABLEFILTER_GGBH		_T("GGBH")
#define IDS_SETTING_ITEM_TABLEFILTER_SL			_T("SL")
#define IDS_SETTING_ITEM_TABLEFILTER_ZC			_T("ZC")
#define IDS_SETTING_ITEM_TABLEFILTER_DFR		_T("DFR")
#define IDS_SETTING_ITEM_TABLEFILTER_ZDQDY		_T("ZDQDY")
#define IDS_SETTING_ITEM_TABLEFILTER_YYLGG		_T("YYLGG")
#define IDS_SETTING_ITEM_TABLEFILTER_JF			_T("JF")
#define IDS_SETTING_ITEM_TABLEFILTER_BPQXH		_T("BPQXH")
#define IDS_SETTING_ITEM_TABLEFILTER_BMQXH		_T("BMQXH")
#define IDS_SETTING_ITEM_TABLEFILTER_DLCD		_T("DLCD")
#define IDS_SETTING_ITEM_TABLEFILTER_ZXCD		_T("ZXCD")
#define IDS_SETTING_ITEM_TABLEFILTER_MPZL		_T("MPZL")
#define IDS_SETTING_ITEM_TABLEFILTER_BZ			_T("BZ")
#define IDS_SETTING_ITEM_TABLEFILTER_DDRQ		_T("DDRQ")
#define IDS_SETTING_ITEM_TABLEFILTER_SHYW		_T("SHYW")
#define IDS_SETTING_ITEM_TABLEFILTER_SHJH		_T("SHJH")
#define IDS_SETTING_ITEM_TABLEFILTER_SCRQ		_T("SCRQ")
#define IDS_SETTING_ITEM_TABLEFILTER_JHSHYW		_T("JHSHYW")
#define IDS_SETTING_ITEM_TABLEFILTER_JHSHJH		_T("JHSHJH")
#define IDS_SETTING_ITEM_TABLEFILTER_BZRQ		_T("BZRQ")
#define IDS_SETTING_ITEM_TABLEFILTER_BZSHYW		_T("BZSHYW")
#define IDS_SETTING_ITEM_TABLEFILTER_BZSHJH		_T("BZSHJH")
#define IDS_SETTING_ITEM_TABLEFILTER_FHRQ		_T("FHRQ")
#define IDS_SETTING_ITEM_TABLEFILTER_TCBH		_T("TCBH")
#define IDS_SETTING_ITEM_TABLEFILTER_CCBH		_T("CCBH")

#define IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE			IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED
#define IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED			_T("1")
#define IDS_SETTING_ITEM_TABLEFILTER_VALUE_UNCHECKED		_T("0")

#define SALE_PRIORITY_COL	18
#define PLAN_PRIORITY_COL	25

namespace nsSale{

enum Column_en{
	hth,	//��ͬ��"
	khmc,	//�ͻ�����"
	ggxh,	//����ͺ�"
	sl,	//����"
	zc,	//���"
	dfr,	//������"
	zdqdy,	//�ƶ�����ѹ"
	yylgg,	//ҷ���ֹ��"
	jf,	//����"
	bpqxh,	//��Ƶ���ͺ�"
	bmqxh,	//�������ͺ�"
	dlcd,	//���³���"
	zxcd,	//բ�߳���"
	mpzl,	//���Ƶ�����"
	bz,	//��ע"
	ddrq,	//��������"
	zjdy,	//������ѹ
	zjys,	//������ɫ
	zdqxh,	//�ƶ����ͺ�
	zyz,	// ��/����
	bzxdtgg,// ��װ��/���й��
	gh,	// ����
	zzs,	// ������
	khqy,	// �ͻ�����
	ywsh,	//���-ҵ��
	jhsh,	//���-�ƻ�"
	yxj	//���ȼ�"
};

}

namespace nsPlan{

	enum Column_en{
		hth,	//��ͬ��"
		khmc,	//�ͻ�����"
		ggxh,	//����ͺ�"
		sl,	//����"
		zc,	//���"
		dfr,	//������"
		zdqdy,	//�ƶ�����ѹ"
		yylgg,	//ҷ���ֹ��"
		jf,	//����"
		bpqxh,	//��Ƶ���ͺ�"
		bmqxh,	//�������ͺ�"
		dlcd,	//���³���"
		zxcd,	//բ�߳���"
		mpzl,	//���Ƶ�����"
		bz,	//��ע"
		ddrq,	//��������"
		zjdy,	//������ѹ
		zjys,	//������ɫ
		zdqxh,	//�ƶ����ͺ�
		zyz,	// ��/����
		bzxdtgg,// ��װ��/���й��
		gh,	// ����
		zzs,	// ������
		khqy,	// �ͻ�����
		scrq,	//��������"
		jhshyw,	//�ƻ����-ҵ��"
		jhshjh,	//�ƻ����-�ƻ�"
		bzrq,	//��װ����"
		bzshyw,	//��װ���-ҵ��"
		bzshjh,	//��װ���-�ƻ�"
		fhrq,	//��������"
		tcbh,	//Ͷ�����"
		ccbh,	//�������"
		yxj	//���ȼ�"
	};
}


#define DEFINE_SALE_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	name.AddSortCondition(nsSale::Column_en::ddrq, false); \
	name.AddSortCondition(nsSale::Column_en::yxj, true);

#define DEFINE_PLAN_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	name.AddSortCondition(nsPlan::Column_en::ddrq, false); \
	name.AddSortCondition(nsPlan::Column_en::yxj, true);//sort for yxj 