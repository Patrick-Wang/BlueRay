#pragma once
#include "AddDlg.h"
#include "UILib/BSStatic.h"
#define OPT_FALSE _T("-1")
#define OPT_FALSE_INT -1
#define do_get(data, it, dest) \
dest = *it;\
if (data.end() == ++it)\
{\
break;\
}

#define do_get_merge(data, it, dest) \
if (dest != OPT_FALSE && dest != *it)\
{\
	dest = OPT_FALSE;\
}\
if (data.end() == ++it)\
{\
break;\
}

#define do_get_int(data, it, drops, dest) \
				{\
std::vector<CString>::const_iterator itRet = std::find(CSaleAddDlg::GetDropList()[drops].begin(), CSaleAddDlg::GetDropList()[drops].end(), *it); \
if (itRet != CSaleAddDlg::GetDropList()[drops].end())\
{\
dest = itRet - CSaleAddDlg::GetDropList()[drops].begin(); \
}\
else{\
		dest = OPT_FALSE_INT; \
}\
}\
if (data.end() == ++it)\
{\
break; \
}

#define do_get_int_merge(data, it, drops, dest) \
if(OPT_FALSE_INT != dest){\
	std::vector<CString>::const_iterator itRet = std::find(CSaleAddDlg::GetDropList()[drops].begin(), CSaleAddDlg::GetDropList()[drops].end(), *it);\
	if (itRet != CSaleAddDlg::GetDropList()[drops].end())\
			{\
		if ((itRet - CSaleAddDlg::GetDropList()[drops].begin()) != dest)\
						{\
			dest = OPT_FALSE_INT;\
						}\
			}\
}\
if (data.end() == ++it)\
{\
break;\
}
class CSaleAddDlg :	public CAddDlg
{
public:
	enum CombId{
		Comb_KHMC,
		Comb_GGBH,
		Comb_DFR,
		Comb_ZDQDY,
		Comb_YYLGG,
		Comb_JF,
		Comb_BPQXH,
		Comb_BMQXH,
		Comb_DLCD,
		Comb_ZXCD,
		Comb_END
	};

	typedef struct tagOption_t{
		CString htbh;	//合同号
		int khmc;		//客户名称
		int ggbh;		//规格型号
		CString sl;			//数量
						//轴承
		int dfr;		//单复绕
		int zdqdy;		//制动器电压
		int yylgg;		//曳引轮规格
		int jf;			//机房
		int bpqxh;		//变频器型号
		int bmqxh;		//编码器型号
		int dlcd;		//电缆长度
		int zxcd;		//闸线长度
		CString mpzl;	//铭牌等资料
		CString bz;		//备注
						//订单日期

		tagOption_t(){
			htbh = OPT_FALSE;	//合同号
			khmc = OPT_FALSE_INT;		//客户名称
			ggbh = OPT_FALSE_INT;		//规格型号
			sl = OPT_FALSE;			//数量
			//轴承
			dfr = OPT_FALSE_INT;		//单复绕
			zdqdy = OPT_FALSE_INT;		//制动器电压
			yylgg = OPT_FALSE_INT;		//曳引轮规格
			jf = OPT_FALSE_INT;			//机房
			bpqxh = OPT_FALSE_INT;		//变频器型号
			bmqxh = OPT_FALSE_INT;		//编码器型号
			dlcd = OPT_FALSE_INT;		//电缆长度
			zxcd = OPT_FALSE_INT;		//闸线长度
			mpzl = OPT_FALSE;	//铭牌等资料
			bz = OPT_FALSE;		//备注
		}

		tagOption_t(std::vector<CString>& data){
			do
			{
				std::vector<CString>::iterator it = data.begin();
				do_get(data, it, htbh);
				do_get_int(data, it, CombId::Comb_KHMC, khmc);
				do_get_int(data, it, CombId::Comb_KHMC, ggbh);
				do_get(data, it, sl);
				do_get_int(data, it, CombId::Comb_DFR, dfr);
				do_get_int(data, it, CombId::Comb_ZDQDY, zdqdy);
				do_get_int(data, it, CombId::Comb_YYLGG, yylgg);
				do_get_int(data, it, CombId::Comb_JF, jf);
				do_get_int(data, it, CombId::Comb_BPQXH, bpqxh);
				do_get_int(data, it, CombId::Comb_BMQXH, bmqxh);
				do_get_int(data, it, CombId::Comb_DLCD, dlcd);
				do_get_int(data, it, CombId::Comb_ZXCD, zxcd);
				do_get(data, it, mpzl);
				do_get(data, it, bz);

			} while (false);
		}
		void Merge(std::vector<CString>& data){
			do 
			{
				std::vector<CString>::iterator it = data.begin();
				do_get_merge(data, it, htbh);
				do_get_int_merge(data, it, CombId::Comb_KHMC, khmc);
				do_get_int_merge(data, it, CombId::Comb_KHMC, ggbh);
				do_get_merge(data, it, sl);
				do_get_int_merge(data, it, CombId::Comb_DFR, dfr);
				do_get_int_merge(data, it, CombId::Comb_ZDQDY, zdqdy);
				do_get_int_merge(data, it, CombId::Comb_YYLGG, yylgg);
				do_get_int_merge(data, it, CombId::Comb_JF, jf);
				do_get_int_merge(data, it, CombId::Comb_BPQXH, bpqxh);
				do_get_int_merge(data, it, CombId::Comb_BMQXH, bmqxh);
				do_get_int_merge(data, it, CombId::Comb_DLCD, dlcd);
				do_get_int_merge(data, it, CombId::Comb_ZXCD, zxcd);
				do_get_merge(data, it, mpzl);
				do_get_merge(data, it, bz);
			} while (false);
		}
	}Option_t;


	CSaleAddDlg(LPCTSTR title, CWnd* pParent = NULL);
	~CSaleAddDlg();
	void SetOption(Option_t* lpOpt);
private:
	enum ItemId{
		Item_HTH,
		Item_KHMC,
		Item_GGBH,
		Item_SL,
		Item_ZC,
		Item_DFR,
		Item_ZDQDY,
		Item_YYLGG,
		Item_JF,
		Item_BPQXH,
		Item_BMQXH,
		Item_DLCD,
		Item_ZXCD,
		Item_MPZL,
		Item_DDRQ,
		Item_BZ,
		Item_END
	};

	

public:
	virtual BOOL OnInitDialog();
	static const std::vector<std::vector<CString>>& GetDropList();
protected:
	virtual void OnOKClicked();
private:
	Option_t* m_lpOption;
	CFont* m_pfont;
	static std::vector<std::vector<CString>> m_DropList;
	CBSStatic* m_aStatics[ItemId::Item_END];
	CComboBox* m_aCombs[CombId::Comb_END];
	CEdit m_htbhEdit;
	CEdit m_slEdit;
	CEdit m_mpzlEdit;
	CEdit m_bzEdit;
	CFont* m_lpFont;
	
	virtual void PostNcDestroy();
};

