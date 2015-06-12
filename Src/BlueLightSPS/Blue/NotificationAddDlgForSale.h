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
std::vector<CString>::const_iterator itRet = std::find(CNotificationAddDlgForSale::GetDropList()[drops].begin(), CNotificationAddDlgForSale::GetDropList()[drops].end(), *it); \
if (itRet != CNotificationAddDlgForSale::GetDropList()[drops].end())\
{\
dest = itRet - CNotificationAddDlgForSale::GetDropList()[drops].begin(); \
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
	std::vector<CString>::const_iterator itRet = std::find(CNotificationAddDlgForSale::GetDropList()[drops].begin(), CNotificationAddDlgForSale::GetDropList()[drops].end(), *it);\
	if (itRet != CNotificationAddDlgForSale::GetDropList()[drops].end())\
									{\
		if ((itRet - CNotificationAddDlgForSale::GetDropList()[drops].begin()) != dest)\
																		{\
			dest = OPT_FALSE_INT;\
																		}\
									}\
}\
if (data.end() == ++it)\
{\
break;\
}

class CNotificationAddDlgForSale : public CPopupDlg
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

		CString ywsh;	//ҵ�����
		CString jhsh;	//�ƻ����



		tagOption_t(){
			htbh = OPT_FALSE;
			khmc = OPT_FALSE;
			ggbh = OPT_FALSE;
			sl = OPT_FALSE;
			zc = OPT_FALSE;
			dfr = OPT_FALSE;
			zdqdy = OPT_FALSE;
			yylgg = OPT_FALSE;
			jf = OPT_FALSE;
			bpqxh = OPT_FALSE;
			bmqxh = OPT_FALSE;
			dlcd = OPT_FALSE;
			zxcd = OPT_FALSE;
			mpzl = OPT_FALSE;
			ddrq = OPT_FALSE;
			bz = OPT_FALSE;
			zjdy = OPT_FALSE;
			zjys = OPT_FALSE;
			zdqxh = OPT_FALSE;
			zyz = OPT_FALSE;
			bzxdtgg = OPT_FALSE;
			zzs = OPT_FALSE;
			khqy = OPT_FALSE;
			yxj = OPT_FALSE;
			gh = OPT_FALSE;
			ywsh = OPT_FALSE;
			jhsh = OPT_FALSE;

		}

		tagOption_t(std::vector<CString>& data){
			do
			{
				//���밴����ʾ˳��ͬ�������һһ��Ӧ
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
				do_get(data, it, ywsh);
				do_get(data, it, jhsh);

			} while (false);
		}
		void Merge(std::vector<CString>& data){
			do
			{
				//���밴����ʾ˳��ͬ�������һһ��Ӧ
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
				do_get_merge(data, it, ywsh);
				do_get_merge(data, it, jhsh);

			} while (false);
		}
	}Option_t;



	CNotificationAddDlgForSale(LPCTSTR title, CWnd* pParent = NULL);
	~CNotificationAddDlgForSale();
	void SetOption(Option_t* lpOpt);

private:
	enum StaticId{
		Static_HTH,
		Static_KHMC,
		Static_GGBH,
		Static_SL,
		Static_ZC,
		Static_ZDQDY,
		Static_YYLGG,
		Static_JF,
		Static_BPQXH,
		Static_BMQXH,
		Static_DLCD,
		Static_ZXCD,
		Static_MPZL,
		Static_DDRQ,

		Static_ZJDY,
		Static_ZJYS,
		Static_ZDQXH,
		Static_ZYZ,
		Static_BZXDTGG,
		Static_ZZS,
		Static_KHQY,
		Static_GH,
		Static_YWSH,
		Static_JHSH,

		Static_BZ,

		Static_END
	};


	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void OnHttpSuccess(int id, LPCTSTR resp);
	void OnHttpFailed(int id);
	static const std::vector<std::vector<CString>>& GetDropList();
	CDelegate<void(CNotificationAddDlgForSale&)> d_GetOption;
	afx_msg void OnNcDestroy();

	void SetDlgOption(BOOL bIsSalePage = FALSE);

protected:
	virtual void OnOK();
	void InitCtrlData();
// 	void GetText(CComboBox* pComboBox, CombId comId, CString& text);
// 	void SetText(CComboBox* pComboBox, CombId comId, CString& text);

private:
	//std::auto_ptr<Option_t> m_lpOption;
	Option_t* m_lpOption;
	static std::vector<std::vector<CString>> m_DropList;
	static int m_iRef;
	CBSStatic* m_aStatics[StaticId::Static_END];
	CBSStatic* m_aStaticsToShow[StaticId::Static_END];

	BOOL m_bIsSalePage;

// 	CEdit* m_aEdits[EditId::Edit_END];
// 	CDateTimeCtrl* m_aDatePickers[DatePickerId::DatePicker_END];
// 	CComboBox* m_aCombs[CombId::Comb_END];

	CBRButton* m_btnNewIDForSCRQ;
	CBRButton* m_btnNewIDForBZRQ;

	bool m_bEnablePlanBtnForSCRQ;
	bool m_bEnablePlanBtnForBZRQ;

	bool m_bEnablePlanEditForTCBH;
	bool m_bEnablePlanEditForCCBH;

	virtual void PostNcDestroy();
	void InitHttpInstance();
	void OnLoadComboDataSuccess(int id, CString strValList);

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
};

