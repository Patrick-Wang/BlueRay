#pragma once
#include "PopupDlg.h"
#include "UILib/BSStatic.h"
#include "IHttp.h"
#include "SettingManager.h"

#define OPT_DATE_NULL _T("")
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
class CSaleAddDlg :	public CPopupDlg
{
public:
	typedef struct tagOption_t{
		CString htbh;	//合同号
		int khmc;		//客户名称
		int ggbh;		//规格型号
		CString sl;		//数量
		int zc;			//轴承
		int dfr;		//单复绕
		int zdqdy;		//制动器电压
		int yylgg;		//曳引轮规格
		int jf;			//机房
		int bpqxh;		//变频器型号
		int bmqxh;		//编码器型号
		CString dlcd;	//电缆长度
		CString zxcd;	//闸线长度
		int mpzl;		//铭牌等资料
		CString ddrq;	//订单日期
		CString bz;		//备注
		int zjdy;		//主机电压
		int zjys;		//主机颜色
		int zdqxh;		//制动器型号
		int zyz;		//左/右置
		int bzxdtgg;	//包装箱/底托规格
		CString gh;		//工号
		int zzs;		//制造商
		int khqy;		//客户区域
		int yxj;		//优先级

		tagOption_t(){
			htbh = OPT_FALSE;			//合同号
			khmc = OPT_FALSE_INT;		//客户名称
			ggbh = OPT_FALSE_INT;		//规格型号
			sl = OPT_FALSE;				//数量
			zc = OPT_FALSE_INT;			//轴承
			dfr = OPT_FALSE_INT;		//单复绕
			zdqdy = OPT_FALSE_INT;		//制动器电压
			yylgg = OPT_FALSE_INT;		//曳引轮规格
			jf = OPT_FALSE_INT;			//机房
			bpqxh = OPT_FALSE_INT;		//变频器型号
			bmqxh = OPT_FALSE_INT;		//编码器型号
			dlcd = OPT_FALSE;			//电缆长度
			zxcd = OPT_FALSE;			//闸线长度
			mpzl = OPT_FALSE_INT;		//铭牌等资料
			ddrq = OPT_DATE_NULL;			//订单日期
			bz = OPT_FALSE;				//备注
			zjdy = OPT_FALSE_INT;
			zjys = OPT_FALSE_INT;
			zdqxh = OPT_FALSE_INT;
			zyz = OPT_FALSE_INT;
			bzxdtgg = OPT_FALSE_INT;
			zzs = OPT_FALSE_INT;
			khqy = OPT_FALSE_INT;
			yxj = OPT_FALSE_INT;
			gh = OPT_FALSE;
		}

		tagOption_t(std::vector<CString>& data){
			do
			{
				std::vector<CString>::iterator it = data.begin();
				do_get(data, it, htbh);
				do_get_int(data, it, CombId::Comb_KHMC, khmc);
				do_get_int(data, it, CombId::Comb_GGBH, ggbh);
				do_get(data, it, sl);
				do_get_int(data, it, CombId::Comb_ZC, zc);
				do_get_int(data, it, CombId::Comb_DFR, dfr);
				do_get_int(data, it, CombId::Comb_ZDQDY, zdqdy);
				do_get_int(data, it, CombId::Comb_YYLGG, yylgg);
				do_get_int(data, it, CombId::Comb_JF, jf);
				do_get_int(data, it, CombId::Comb_BPQXH, bpqxh);
				do_get_int(data, it, CombId::Comb_BMQXH, bmqxh);
				do_get(data, it, dlcd);
				do_get(data, it, zxcd);
				do_get_int(data, it, CombId::Comb_MPZL, mpzl);
				do_get(data, it, bz);
				do_get(data, it, ddrq);
				do_get_int(data, it, CombId::Comb_ZJDY, zjdy);
				do_get_int(data, it, CombId::Comb_ZJYS, zjys);
				do_get_int(data, it, CombId::Comb_ZDQXH, zdqxh);
				do_get_int(data, it, CombId::Comb_ZYZ, zyz);
				do_get_int(data, it, CombId::Comb_BZXDTGG, bzxdtgg);
				do_get(data, it, gh);
				do_get_int(data, it, CombId::Comb_ZZS, zzs);
				do_get_int(data, it, CombId::Comb_KHQY, khqy);
				do_get_int(data, it, CombId::Comb_YXJ, yxj);

			} while (false);
		}
		void Merge(std::vector<CString>& data){
			do 
			{
				std::vector<CString>::iterator it = data.begin();
				do_get_merge(data, it, htbh);
				do_get_int_merge(data, it, CombId::Comb_KHMC, khmc);
				do_get_int_merge(data, it, CombId::Comb_GGBH, ggbh);
				do_get_merge(data, it, sl);
				do_get_int_merge(data, it, CombId::Comb_ZC, zc);
				do_get_int_merge(data, it, CombId::Comb_DFR, dfr);
				do_get_int_merge(data, it, CombId::Comb_ZDQDY, zdqdy);
				do_get_int_merge(data, it, CombId::Comb_YYLGG, yylgg);
				do_get_int_merge(data, it, CombId::Comb_JF, jf);
				do_get_int_merge(data, it, CombId::Comb_BPQXH, bpqxh);
				do_get_int_merge(data, it, CombId::Comb_BMQXH, bmqxh);
				do_get_merge(data, it, dlcd);
				do_get_merge(data, it, zxcd);
				do_get_int_merge(data, it, CombId::Comb_MPZL, mpzl);
				do_get_merge(data, it, bz);
				do_get_merge(data, it, ddrq);

				do_get_int_merge(data, it, CombId::Comb_ZJDY, zjdy);
				do_get_int_merge(data, it, CombId::Comb_ZJYS, zjys);
				do_get_int_merge(data, it, CombId::Comb_ZDQXH, zdqxh);
				do_get_int_merge(data, it, CombId::Comb_ZYZ, zyz);
				do_get_int_merge(data, it, CombId::Comb_BZXDTGG, bzxdtgg);
				do_get_merge(data, it, gh);
				do_get_int_merge(data, it, CombId::Comb_ZZS, zzs);
				do_get_int_merge(data, it, CombId::Comb_KHQY, khqy);
				do_get_int_merge(data, it, CombId::Comb_YXJ, yxj);

			} while (false);
		}
	}Option_t;


	CSaleAddDlg(LPCTSTR title, CWnd* pParent = NULL);
	~CSaleAddDlg();
	void SetOption(Option_t* lpOpt);

private:
	enum StaticId{
		Static_HTH,
		Static_KHMC,
		Static_GGBH,
		Static_SL,
		Static_ZC,
		Static_DFR,
		Static_ZDQDY,
		Static_YYLGG,
		Static_JF,
		Static_BPQXH,
		Static_BMQXH,
		Static_DLCD,
		Static_ZXCD,
		Static_MPZL,
		Static_DDRQ,
		Static_BZ,
		Static_ZJDY,
		Static_ZJYS,
		Static_ZDQXH,
		Static_ZYZ,
		Static_BZXDTGG,
		Static_ZZS,
		Static_KHQY,
		Static_YXJ,
		Static_GH,
		Static_END
	};

	enum CombId{
		Comb_KHMC,
		Comb_GGBH,
		Comb_ZC,
		Comb_DFR,
		Comb_ZDQDY,
		Comb_YYLGG,
		Comb_JF,
		Comb_BPQXH,
		Comb_BMQXH,
		Comb_YXJ,
		//Comb_DLCD,
		//Comb_ZXCD,
		Comb_ZJDY,
		Comb_ZJYS,
		Comb_ZDQXH,
		Comb_ZYZ,
		Comb_BZXDTGG,
		Comb_ZZS,
		Comb_KHQY,
		Comb_MPZL,
		Comb_END
	};

	enum EditId{
		Edit_HTH,
		Edit_SL,
		Edit_DLCD,
		Edit_ZXCD,
		Edit_GH,
		Edit_BZ,
		Edit_END
	};

	enum DatePickerId{
		DatePicker_DDRQ,
		DatePicker_END
	};

public:
	virtual BOOL OnInitDialog();
	void OnHttpSuccess(int id, LPCTSTR resp);
	void OnHttpFailed(int id);
	static const std::vector<std::vector<CString>>& GetDropList();
	CDelegate<void(CSaleAddDlg&)> d_GetOption;
	void SetIfUseDefaultValue(bool ifuse);
protected:
	void Assosication();
	void InitHttpInstance();
	virtual void OnOK();
	void InitCtrlData();
	void GetText(CComboBox* pComboBox, CombId comId, CString& text);
	void SetText(CComboBox* pComboBox, CombId comId, CString& text);
private:
	std::auto_ptr<Option_t> m_lpOption;
	static std::vector<std::vector<CString>> m_DropList;
	static int m_iRef;
	CBSStatic* m_aStatics[StaticId::Static_END];
	CComboBox* m_aCombs[CombId::Comb_END];
	CEdit* m_aEdits[EditId::Edit_END];
	CDateTimeCtrl* m_aDatePickers[DatePickerId::DatePicker_END];
	bool m_bIfUseDefaultValue;
private:
	void OnCbnSelchangeKhOrGg();
	virtual void PostNcDestroy();
	void OnLoadComboDataSuccess(int id, CString strValList);
public:
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
//	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
};

