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
		CString htbh;	//��ͬ��
		CString khmc;	//�ͻ�����
		CString ggbh;	//����ͺ�
		CString sl;		//����
		CString zc;		//���
		CString dfr;	//������
		CString zdqdy;	//�ƶ�����ѹ
		CString yylgg;	//ҷ���ֹ��
		CString jf;		//����
		CString bpqxh;	//��Ƶ���ͺ�
		CString bmqxh;	//�������ͺ�
		CString dlcd;	//���³���
		CString zxcd;	//բ�߳���
		CString mpzl;	//���Ƶ�����
		CString ddrq;	//��������
		CString bz;		//��ע

		CString zjdy;		//������ѹ
		CString zjys;		//������ɫ
		CString zdqxh;		//�ƶ����ͺ�
		CString zyz;		//��/����
		CString bzxdtgg;	//��װ��/���й��
		CString gh;		//����
		CString zzs;		//������
		CString khqy;		//�ͻ�����
		CString yxj;		//���ȼ�

		CString scrq;	//��������
		CString jhywsh;	//�ƻ����-ҵ��
		CString jhjhsh;	//�ƻ����-�ƻ�
		CString bzrq;	//��װ����
		CString bzywsh;	//��װ���-ҵ��
		CString bzjhsh;	//��װ���-�ƻ�
		CString fhrq;	//��������
		CString tcbh;	//Ͷ�����
		CString ccbh;	//�������

		int zc_forPlan; //��� ��planner�޸���
		CString bz_forPlan; //��ע ��planner�޸���

		tagOption_t(){
			htbh = OPT_FALSE;			//��ͬ��
			khmc = OPT_FALSE;		//�ͻ�����
			ggbh = OPT_FALSE;		//����ͺ�
			sl = OPT_FALSE;				//����
			zc = OPT_FALSE;			//���
			dfr = OPT_FALSE;		//������
			zdqdy = OPT_FALSE;		//�ƶ�����ѹ
			yylgg = OPT_FALSE;		//ҷ���ֹ��
			jf = OPT_FALSE;			//����
			bpqxh = OPT_FALSE;		//��Ƶ���ͺ�
			bmqxh = OPT_FALSE;		//�������ͺ�
			dlcd = OPT_FALSE;			//���³���
			zxcd = OPT_FALSE;			//բ�߳���
			mpzl = OPT_FALSE;		//���Ƶ�����
			ddrq = OPT_FALSE;			//��������
			bz = OPT_FALSE;				//��ע

			zjdy = OPT_FALSE;
			zjys = OPT_FALSE;
			zdqxh = OPT_FALSE;
			zyz = OPT_FALSE;
			bzxdtgg = OPT_FALSE;
			zzs = OPT_FALSE;
			khqy = OPT_FALSE;
			yxj = OPT_FALSE;
			gh = OPT_FALSE;

			scrq = OPT_FALSE;	//��������
			jhywsh = OPT_FALSE;	//�ƻ����-ҵ��
			jhjhsh = OPT_FALSE;	//�ƻ����-�ƻ�
			bzrq = OPT_FALSE;	//��װ����
			bzywsh = OPT_FALSE;	//��װ���-ҵ��
			bzjhsh = OPT_FALSE;	//��װ���-�ƻ�
			fhrq = OPT_FALSE;	//��������
			tcbh = OPT_FALSE;	//Ͷ�����
			ccbh = OPT_FALSE;	//�������

			zc_forPlan = OPT_FALSE_INT; //��� for plan
			bz_forPlan = OPT_FALSE; //��� for plan
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

