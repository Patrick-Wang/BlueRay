#pragma once
//Host
extern CString g_strHostName;

#define IDS_HOST_NAME             (LPCTSTR)g_strHostName

#define IDS_VERSION_NUMBER	 _T("1.0.0.11030")
//user setting location

#define IDS_SETTING_FILENAME				_T("\\user_setting.xml")
#define IDS_SETTING_FILENAME_ALL			_T("\\setting.xml")
#define IDS_SETTING_ROOT_APPFOLDER			_T("\\BlueLightPLM")
#define IDS_SETTING_ROOT_SETTINGFOLDER		_T("\\settings")
#define IDS_SETTING_ROOT_FOLDER				_T("%appdata%")
#define IDS_SETTING_LOCATION				_T("%appdata%\\BlueLightPLM\\settings\\")
#define IDS_SETTING_LOCATION_WITHOUTSLASH				_T("%appdata%\\BlueLightPLM\\settings")

//setting item define

#define IDS_SETTING_ITEM_ROOT			_T("Settings")
#define IDS_SETTING_ITEM_TABLEFILTER	_T("TabFilter")
#define IDS_SETTING_ITEM_TABLEFILTER_SALE	_T("Sale")
#define IDS_SETTING_ITEM_TABLEFILTER_PLAN	_T("Plan")
#define IDS_SETTING_ITEM_TABLEFILTER_NOTIFICATIONSALE	_T("NotificationSale")
#define IDS_SETTING_ITEM_TABLEFILTER_NOTIFICATIONPLAN	_T("NotificationPlan")
#define IDS_SETTING_ITEM_COL_WIDTH	_T("ColWidths")
#define IDS_SETTING_ITEM_USERS	_T("Users")
#define IDS_SETTING_ITEM_LASTLOGINUSER	_T("LastLoginUser")
#define IDS_SETTING_ITEM_DEFAULTVALUE	_T("DefaultValue")
#define IDS_SETTING_ITEM_DEFAULT_SALEADD	_T("SaleAdd")


#define IDS_SETTING_ITEM_TABLEFILTER_HTH		_T("HTH")
#define IDS_SETTING_ITEM_TABLEFILTER_KHMC		_T("KHMC")
#define IDS_SETTING_ITEM_TABLEFILTER_GGBH		_T("GGBH")
#define IDS_SETTING_ITEM_TABLEFILTER_CG		_T("CG")
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

#define IDS_SETTING_ITEM_TABLEFILTER_ZJDY 		_T("ZJDY")
#define IDS_SETTING_ITEM_TABLEFILTER_ZJYS 		_T("ZJYS")
#define IDS_SETTING_ITEM_TABLEFILTER_ZDQXH		_T("ZDQXH")
#define IDS_SETTING_ITEM_TABLEFILTER_ZYZ		_T("ZYZ")
#define IDS_SETTING_ITEM_TABLEFILTER_BZXDTGG	_T("BZXDTGG")
#define IDS_SETTING_ITEM_TABLEFILTER_ZZS		_T("ZZS")
#define IDS_SETTING_ITEM_TABLEFILTER_KHQY		_T("KHQY")
#define IDS_SETTING_ITEM_TABLEFILTER_YXJ		_T("YXJ")
#define IDS_SETTING_ITEM_TABLEFILTER_GH			_T("GH")

#define IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE			IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED
#define IDS_SETTING_ITEM_TABLEFILTER_VALUE_CHECKED			_T("1")
#define IDS_SETTING_ITEM_TABLEFILTER_VALUE_UNCHECKED		_T("0")

#define IDS_COMMON_YES		_T("Y")
#define IDS_COMMON_NO		_T("N")

//#define SALE_PRIORITY_COL	18
//#define PLAN_PRIORITY_COL	25

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
	yxj,	//���ȼ�"
	ywsh,	//���-ҵ��
	jhsh,	//���-�ƻ�"
	end,
	ywshrq = end,
	jhshrq,
};

}

namespace nsPlan{

	enum Column_en{
		hth,	//��ͬ��"
		khmc,	//�ͻ�����"
		ggxh,	//����ͺ�"
		cg,
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
		yxj,	//���ȼ�"
		scrq,	//��������"
		jhshyw,	//�ƻ����-ҵ��"
		jhshjh,	//�ƻ����-�ƻ�"
		bzrq,	//��װ����"
		bzshyw,	//��װ���-ҵ��"
		bzshjh,	//��װ���-�ƻ�"
		fhrq,	//��������"
		tcbh,	//Ͷ�����"
		ccbh,	//�������"
		end
	};
}

namespace nsNotification{

	enum Column_en{
		hth,	//��ͬ��"
		khmc,	//�ͻ�����"
		ggxh,	//����ͺ�"
		cg,		//�Ÿ�
		sl,		//����"
		zc,		//���"
		dfr,	//������"
		zdqdy,	//�ƶ�����ѹ"
		yylgg,	//ҷ���ֹ��"
		jf,		//����"
		bpqxh,	//��Ƶ���ͺ�"
		bmqxh,	//�������ͺ�"
		dlcd,	//���³���"
		zxcd,	//բ�߳���"
		mpzl,	//���Ƶ�����"
		bz,		//��ע"
		ddrq,	//��������"
		zjdy,	//������ѹ
		zjys,	//������ɫ
		zdqxh,	//�ƶ����ͺ�
		zyz,	// ��/����
		bzxdtgg,// ��װ��/���й��
		gh,		// ����
		zzs,	// ������
		khqy,	// �ͻ�����
		yxj,	//���ȼ�"
		ywsh,	//ҵ�����
		jhsh,	//�ƻ����
		scrq,	//��������"
		jhshyw,	//�ƻ����-ҵ��"
		jhshjh,	//�ƻ����-�ƻ�"
		bzrq,	//��װ����"
		bzshyw,	//��װ���-ҵ��"
		bzshjh,	//��װ���-�ƻ�"
		fhrq,	//��������"
		tcbh,	//Ͷ�����"
		ccbh,	//�������"

		end
	};
}


#define DEFINE_SALE_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	MAKE_SALE_QUERY_PARAM(name)

#define MAKE_SALE_QUERY_PARAM(name) \
	name.AddSortCondition(nsSale::Column_en::ddrq, false); \
	name.AddSortCondition(nsSale::Column_en::khmc, true);

#define DEFINE_PLAN_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	MAKE_PLAN_QUERY_PARAM(name)

#define MAKE_PLAN_QUERY_PARAM(name) \
	name.AddSortCondition(nsPlan::Column_en::scrq, false);\
	name.AddSortCondition(nsPlan::Column_en::ggxh, true); \
	name.AddSortCondition(nsPlan::Column_en::khmc, true); \
	name.AddSortCondition(nsPlan::Column_en::tcbh, true);

#define DEFINE_NOTIFICATION_SALE_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	MAKE_SALE_QUERY_PARAM(name)

#define DEFINE_NOTIFICATION_PLAN_QUERY_PARAM(name) \
	CJsonQueryParam name;\
	MAKE_PLAN_QUERY_PARAM(name)

inline bool GGisS(CString& ggxh){
	return !ggxh.IsEmpty() && (0 == ggxh.Left(1).CompareNoCase(L"S"));
}

inline bool GGisTA(CString& ggxh){
	return ggxh.GetLength() > 1 && (0 == ggxh.Left(2).CompareNoCase(L"TA"));
}

inline bool GGisTStart(CString& ggxh){
	return !ggxh.IsEmpty() && (0 == ggxh.Left(1).CompareNoCase(L"T"));
}

inline bool GGisU(CString& ggxh){
	return !ggxh.IsEmpty() && (0 == ggxh.Left(1).CompareNoCase(L"U"));
}


#define HighlightCell(id, row, ns, pGridAPI) \
	{\
		CString& ggxh = row[ns::ggxh];\
		if (GGisS(ggxh)){\
			if (row[ns::zdqdy].CompareNoCase(L"AC220V") == 0 && row[ns::zdqxh].CompareNoCase(L"DZE-14EB2") != 0	&& !row[ns::zdqxh].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::zdqxh);\
				pGridAPI->HighLightCell(id, ns::zdqdy);\
			}\
			if (row[ns::zdqdy].CompareNoCase(L"DC110V") == 0 && row[ns::zdqxh].CompareNoCase(L"DZE-14EA") != 0 && !row[ns::zdqxh].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::zdqxh);\
				pGridAPI->HighLightCell(id, ns::zdqdy);\
			}\
			\
			if (row[ns::yylgg].CompareNoCase(L"400*5*10*16") != 0 && !row[ns::yylgg].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::yylgg);\
			}\
		}\
		if (GGisTStart(ggxh)){\
			if (row[ns::zdqdy].CompareNoCase(L"DC110v") != 0 && !row[ns::zdqdy].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::zdqdy);\
			}\
			\
			if ((row[ns::zdqxh].CompareNoCase(L"WYT-TA.3��10�ɣ�") != 0) && (row[ns::zdqxh].CompareNoCase(L"WYT-TA.3��12�ɣ�") != 0) && !row[ns::zdqxh].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::zdqxh);\
			}\
			\
			if (row[ns::yylgg].CompareNoCase(L"400*5*10*16") != 0 && !row[ns::yylgg].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::yylgg);\
			}\
		}\
		if (GGisU(ggxh)){\
			if (row[ns::zdqdy].CompareNoCase(L"DC110V") != 0 && !row[ns::zdqdy].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::zdqdy);\
			}\
			\
			if (row[ns::yylgg].CompareNoCase(L"480*7*12*18") != 0 && !row[ns::yylgg].IsEmpty()){\
				pGridAPI->HighLightCell(id, ns::yylgg);\
			}\
		}\
		if (row[ns::zjdy].CompareNoCase(L"AC380V") != 0 && !row[ns::zjdy].IsEmpty()){\
			pGridAPI->HighLightCell(id, ns::zjdy);\
		}\
		if (row[ns::jf].CompareNoCase(L"��") != 0 && !row[ns::jf].IsEmpty()){\
			pGridAPI->HighLightCell(id, ns::jf);\
		}\
		\
		if (row[ns::bmqxh].CompareNoCase(L"��1387") != 0 && !row[ns::bmqxh].IsEmpty()){\
			pGridAPI->HighLightCell(id, ns::bmqxh);\
		}\
	}

#define SaleHighlightCell(id, row, pGridAPI) HighlightCell(id, row, nsSale, pGridAPI)
#define PlanHighlightCell(id, row, pGridAPI) HighlightCell(id, row, nsPlan, pGridAPI)
#define NotificationHighlightCell(id, row, pGridAPI) HighlightCell(id, row, nsNotification, pGridAPI)