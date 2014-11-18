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

#define do_get_int(data, it, dest) \
dest = _tstoi(*it);\
if (data.end() == ++it)\
{\
break;\
}

#define do_get_int_merge(data, it, dest) \
if (dest != OPT_FALSE_INT && dest != *it)\
{\
	dest = OPT_FALSE_INT;\
}\
if (data.end() == ++it)\
{\
break;\
}
class CSaleAddDlg :	public CAddDlg
{
public:
	typedef struct tagOption_t{
		CString htbh;	//合同号
		int khmc;		//客户名称
		int ggbh;		//规格型号
		int sl;			//数量
		//轴承
		int dfr;		//单复绕
		int zdqdy;		//制动器电压
		int zylgg;		//曳引轮规格
		int jf;			//机房
		int bpqxh;		//变频器型号
		int bmqxh;		//编码器型号
		int dlcd;		//电缆长度
		int zxcd;		//闸线长度
		CString mpzl;	//铭牌等资料
		CString bz;		//备注
		//订单日期

		tagOption_t(std::vector<CString>& data){
			do
			{
				std::vector<CString>::iterator it = data.begin();
				do_get(data, it, htbh);
				do_get_int(data, it, khmc);
				do_get_int(data, it, ggbh);
				do_get_int(data, it, sl);
				do_get_int(data, it, dfr);
				do_get_int(data, it, zdqdy);
				do_get_int(data, it, zylgg);
				do_get_int(data, it, jf);
				do_get_int(data, it, bpqxh);
				do_get_int(data, it, bmqxh);
				do_get_int(data, it, dlcd);
				do_get_int(data, it, zxcd);
				do_get(data, it, mpzl);
				do_get(data, it, bz);

			} while (false);
		}
		void Merge(std::vector<CString>& data){
			do 
			{
				std::vector<CString>::iterator it = data.begin();
				do_get_merge(data, it, htbh);
				do_get_int_merge(data, it, khmc);
				do_get_int_merge(data, it, ggbh);
				do_get_int_merge(data, it, sl);
				do_get_int_merge(data, it, dfr);
				do_get_int_merge(data, it, zdqdy);
				do_get_int_merge(data, it, zylgg);
				do_get_int_merge(data, it, jf);
				do_get_int_merge(data, it, bpqxh);
				do_get_int_merge(data, it, bmqxh);
				do_get_int_merge(data, it, dlcd);
				do_get_int_merge(data, it, zxcd);
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

public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOKClicked();
private:
	Option_t* m_lpOption;
	CFont* m_pfont;
	CComboBox* m_aCombs[CombId::Comb_END];
	CBSStatic* m_aStatics[ItemId::Item_END];

	virtual void PostNcDestroy();
};

