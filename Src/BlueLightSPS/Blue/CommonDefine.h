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
	hth,	//合同号"
	khmc,	//客户名称"
	ggxh,	//规格型号"
	sl,	//数量"
	zc,	//轴承"
	dfr,	//单复绕"
	zdqdy,	//制动器电压"
	yylgg,	//曳引轮规格"
	jf,	//机房"
	bpqxh,	//变频器型号"
	bmqxh,	//编码器型号"
	dlcd,	//电缆长度"
	zxcd,	//闸线长度"
	mpzl,	//铭牌等资料"
	bz,	//备注"
	ddrq,	//订单日期"
	zjdy,	//主机电压
	zjys,	//主机颜色
	zdqxh,	//制动器型号
	zyz,	// 左/右置
	bzxdtgg,// 包装箱/底托规格
	gh,	// 工号
	zzs,	// 制造商
	khqy,	// 客户区域
	ywsh,	//审核-业务
	jhsh,	//审核-计划"
	yxj	//优先级"
};

}

namespace nsPlan{

	enum Column_en{
		hth,	//合同号"
		khmc,	//客户名称"
		ggxh,	//规格型号"
		sl,	//数量"
		zc,	//轴承"
		dfr,	//单复绕"
		zdqdy,	//制动器电压"
		yylgg,	//曳引轮规格"
		jf,	//机房"
		bpqxh,	//变频器型号"
		bmqxh,	//编码器型号"
		dlcd,	//电缆长度"
		zxcd,	//闸线长度"
		mpzl,	//铭牌等资料"
		bz,	//备注"
		ddrq,	//订单日期"
		zjdy,	//主机电压
		zjys,	//主机颜色
		zdqxh,	//制动器型号
		zyz,	// 左/右置
		bzxdtgg,// 包装箱/底托规格
		gh,	// 工号
		zzs,	// 制造商
		khqy,	// 客户区域
		scrq,	//生产日期"
		jhshyw,	//计划审核-业务"
		jhshjh,	//计划审核-计划"
		bzrq,	//包装日期"
		bzshyw,	//包装审核-业务"
		bzshjh,	//包装审核-计划"
		fhrq,	//发货日期"
		tcbh,	//投产编号"
		ccbh,	//出厂编号"
		yxj	//优先级"
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