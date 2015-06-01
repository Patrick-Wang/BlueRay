#pragma once
#include "PopupDlg.h"
#include "UILib/BSStatic.h"
#include "IHttp.h"

#define OPT_FALSE _T("-1")
#define OPT_FALSE_INT -1
#define do_get(data, it, dest) \
if (data.end() == it)\
{\
break;\
}\
dest = *it;\
if (data.end() == ++it)\
{\
break;\
}

#define do_get_merge(data, it, dest) \
if (data.end() == it)\
{\
break;\
}\
if (dest != OPT_FALSE && dest != *it)\
{\
	dest = OPT_FALSE;\
}\
if (data.end() == ++it)\
{\
break;\
}

#define do_get_int(data, it, drops, dest) \
if (data.end() == it)\
{\
break;\
}\
{\
std::vector<CString>::const_iterator itRet = std::find(CPlanAddDlg::GetDropList()[drops].begin(), CPlanAddDlg::GetDropList()[drops].end(), *it); \
if (itRet != CPlanAddDlg::GetDropList()[drops].end())\
{\
dest = itRet - CPlanAddDlg::GetDropList()[drops].begin(); \
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
if (data.end() == it)\
{\
break;\
}\
if(OPT_FALSE_INT != dest){\
	std::vector<CString>::const_iterator itRet = std::find(CPlanAddDlg::GetDropList()[drops].begin(), CPlanAddDlg::GetDropList()[drops].end(), *it);\
	if (itRet != CPlanAddDlg::GetDropList()[drops].end())\
							{\
		if ((itRet - CPlanAddDlg::GetDropList()[drops].begin()) != dest)\
														{\
			dest = OPT_FALSE_INT;\
														}\
							}\
}\
if (data.end() == ++it)\
{\
break;\
}

class CPlanAddDlg : public CPopupDlg
{
public:

	typedef struct tagOption_t{
		CString htbh;	//合同号
		CString khmc;	//客户名称
		CString ggbh;	//规格型号
		CString sl;		//数量
		CString zc;		//轴承
		CString dfr;	//单复绕
		CString zdqdy;	//制动器电压
		CString yylgg;	//曳引轮规格
		CString jf;		//机房
		CString bpqxh;	//变频器型号
		CString bmqxh;	//编码器型号
		CString dlcd;	//电缆长度
		CString zxcd;	//闸线长度
		CString mpzl;	//铭牌等资料
		CString ddrq;	//订单日期
		CString bz;		//备注

		CString zjdy;		//主机电压
		CString zjys;		//主机颜色
		CString zdqxh;		//制动器型号
		CString zyz;		//左/右置
		CString bzxdtgg;	//包装箱/底托规格
		CString gh;		//工号
		CString zzs;		//制造商
		CString khqy;		//客户区域
		CString yxj;		//优先级

		CString scrq;	//生产日期
		CString jhywsh;	//计划审核-业务
		CString jhjhsh;	//计划审核-计划
		CString bzrq;	//包装日期
		CString bzywsh;	//包装审核-业务
		CString bzjhsh;	//包装审核-计划
		CString fhrq;	//发货日期
		CString tcbh;	//投产编号
		CString ccbh;	//出厂编号

		int zc_forPlan; //轴承 供planner修改用
		CString bz_forPlan; //备注 供planner修改用

		tagOption_t(){
			htbh = OPT_FALSE;			//合同号
			khmc = OPT_FALSE;		//客户名称
			ggbh = OPT_FALSE;		//规格型号
			sl = OPT_FALSE;				//数量
			zc = OPT_FALSE;			//轴承
			dfr = OPT_FALSE;		//单复绕
			zdqdy = OPT_FALSE;		//制动器电压
			yylgg = OPT_FALSE;		//曳引轮规格
			jf = OPT_FALSE;			//机房
			bpqxh = OPT_FALSE;		//变频器型号
			bmqxh = OPT_FALSE;		//编码器型号
			dlcd = OPT_FALSE;			//电缆长度
			zxcd = OPT_FALSE;			//闸线长度
			mpzl = OPT_FALSE;		//铭牌等资料
			ddrq = OPT_FALSE;			//订单日期
			bz = OPT_FALSE;				//备注

			zjdy = OPT_FALSE;
			zjys = OPT_FALSE;
			zdqxh = OPT_FALSE;
			zyz = OPT_FALSE;
			bzxdtgg = OPT_FALSE;
			zzs = OPT_FALSE;
			khqy = OPT_FALSE;
			yxj = OPT_FALSE;
			gh = OPT_FALSE;

			scrq = OPT_FALSE;	//生产日期
			jhywsh = OPT_FALSE;	//计划审核-业务
			jhjhsh = OPT_FALSE;	//计划审核-计划
			bzrq = OPT_FALSE;	//包装日期
			bzywsh = OPT_FALSE;	//包装审核-业务
			bzjhsh = OPT_FALSE;	//包装审核-计划
			fhrq = OPT_FALSE;	//发货日期
			tcbh = OPT_FALSE;	//投产编号
			ccbh = OPT_FALSE;	//出厂编号

			zc_forPlan = OPT_FALSE_INT; //轴承 for plan
			bz_forPlan = OPT_FALSE; //轴承 for plan
		}

		tagOption_t(std::vector<CString>& data){
			do
			{
				std::vector<CString>::iterator it = data.begin();
				do_get(data, it, htbh);
				do_get(data, it, khmc);
				do_get(data, it, ggbh);
				do_get(data, it, sl);
				do_get(data, it, zc);
				do_get(data, it, dfr);
				do_get(data, it, zdqdy);
				do_get(data, it, yylgg);
				do_get(data, it, jf);
				do_get(data, it, bpqxh);
				do_get(data, it, bmqxh);
				do_get(data, it, dlcd);
				do_get(data, it, zxcd);
				do_get(data, it, mpzl);
				do_get(data, it, bz);
				do_get(data, it, ddrq);

				do_get(data, it, zjdy);
				do_get(data, it, zjys);
				do_get(data, it, zdqxh);
				do_get(data, it, zyz);
				do_get(data, it, bzxdtgg);
				do_get(data, it, gh);
				do_get(data, it, zzs);
				do_get(data, it, khqy);
				do_get(data, it, yxj);

				do_get(data, it, scrq);
				
				do_get(data, it, jhywsh);
				do_get(data, it, jhjhsh);

				do_get(data, it, bzrq);

				do_get(data, it, bzywsh);
				do_get(data, it, bzjhsh);
				
				do_get(data, it, fhrq);
				do_get(data, it, tcbh);
				do_get(data, it, ccbh);

				do_get_int(data, it, CombId::Comb_ZC_ForPlan, zc_forPlan);
				do_get(data, it, bz_forPlan);

			} while (false);
		}
		void Merge(std::vector<CString>& data){
			do
			{
				std::vector<CString>::iterator it = data.begin();
				do_get_merge(data, it, htbh);
				do_get_merge(data, it, khmc);
				do_get_merge(data, it, ggbh);
				do_get_merge(data, it, sl);
				do_get_merge(data, it, zc);
				do_get_merge(data, it, dfr);
				do_get_merge(data, it, zdqdy);
				do_get_merge(data, it, yylgg);
				do_get_merge(data, it, jf);
				do_get_merge(data, it, bpqxh);
				do_get_merge(data, it, bmqxh);
				do_get_merge(data, it, dlcd);
				do_get_merge(data, it, zxcd);
				do_get_merge(data, it, mpzl);
				do_get_merge(data, it, bz);
				do_get_merge(data, it, ddrq);

				do_get_merge(data, it, zjdy);
				do_get_merge(data, it, zjys);
				do_get_merge(data, it, zdqxh);
				do_get_merge(data, it, zyz);
				do_get_merge(data, it, bzxdtgg);
				do_get_merge(data, it, gh);
				do_get_merge(data, it, zzs);
				do_get_merge(data, it, khqy);
				do_get_merge(data, it, yxj);

				do_get_merge(data, it, scrq);

				do_get_merge(data, it, jhywsh);
				do_get_merge(data, it, jhjhsh);
				
				do_get_merge(data, it, bzrq);
				
				do_get_merge(data, it, bzywsh);
				do_get_merge(data, it, bzjhsh);

				do_get_merge(data, it, fhrq);
				do_get_merge(data, it, tcbh);
				do_get_merge(data, it, ccbh);

				do_get_int_merge(data, it, CombId::Comb_ZC_ForPlan, zc_forPlan);
				do_get_merge(data, it, bz_forPlan);

			} while (false);
		}
	}Option_t;


	CPlanAddDlg(LPCTSTR title, CWnd* pParent = NULL);
	~CPlanAddDlg();
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

		Static_SCRQ,
		Static_BZRQ,
		Static_FHRQ,
		Static_TCBH,
		Static_CCBH,

		Static_ZC_ForPlan,
		Static_BZ_ForPlan,

		Static_END
	};

	enum StaticId2{
		Static2_HTH,
		Static2_KHMC,
		Static2_GGBH,
		Static2_SL,
		Static2_ZC,
		Static2_DFR,
		Static2_ZDQDY,
		Static2_YYLGG,
		Static2_JF,
		Static2_BPQXH,
		Static2_BMQXH,
		Static2_DLCD,
		Static2_ZXCD,
		Static2_MPZL,
		Static2_DDRQ,
		Static2_BZ,

		Static2_ZJDY,
		Static2_ZJYS,
		Static2_ZDQXH,
		Static2_ZYZ,
		Static2_BZXDTGG,
		Static2_ZZS,
		Static2_KHQY,
		Static2_YXJ,
		Static2_GH,

		Static2_END
	};

	enum EditId{
		Edit_TCBH,
		Edit_CCBH,
		Edit_BZ_ForPlan,
		Edit_END
	};

	enum DatePickerId{
		DatePicker_SCRQ,
		DatePicker_BZRQ,
		DatePicker_FHRQ,
		DatePicker_END
	};

	enum CombId{
		Comb_ZC_ForPlan,
		Comb_END
	};

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void ConfigPlanBtns(bool scrq, bool bzrq);
	void DisableBHEdits(BOOL tcbh, BOOL ccbh);
	void OnHttpSuccess(int id, LPCTSTR resp);
	void OnHttpFailed(int id);
	static const std::vector<std::vector<CString>>& GetDropList();
	CDelegate<void(CPlanAddDlg&)> d_GetOption;
	afx_msg void OnNcDestroy();

protected:
	virtual void OnOK();
	void InitCtrlData();
	void GetText(CComboBox* pComboBox, CombId comId, CString& text);
	void SetText(CComboBox* pComboBox, CombId comId, CString& text);

private:
	//std::auto_ptr<Option_t> m_lpOption;
	Option_t* m_lpOption;
	static std::vector<std::vector<CString>> m_DropList;
	static int m_iRef;
	CBSStatic* m_aStatics[StaticId::Static_END];
	CBSStatic* m_aStaticsToShow[StaticId2::Static2_END];
	CEdit* m_aEdits[EditId::Edit_END];
	CDateTimeCtrl* m_aDatePickers[DatePickerId::DatePicker_END];
	CComboBox* m_aCombs[CombId::Comb_END];

	CBRButton* m_btnNewIDForSCRQ;
	CBRButton* m_btnNewIDForBZRQ;

	bool m_bEnablePlanBtnForSCRQ;
	bool m_bEnablePlanBtnForBZRQ;

	bool m_bEnablePlanEditForTCBH;
	bool m_bEnablePlanEditForCCBH;

	virtual void PostNcDestroy();
	void InitHttpInstance();
	void OnLoadComboDataSuccess(int id, CString strValList);
	afx_msg void OnBnClickedNewIDForSCRQ();
	afx_msg void OnBnClickedNewIDForBZRQ();

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
};

