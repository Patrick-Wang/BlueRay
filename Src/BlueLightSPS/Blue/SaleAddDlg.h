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
		CString htbh;	//��ͬ��
		int khmc;		//�ͻ�����
		int ggbh;		//����ͺ�
		CString sl;		//����
		int zc;			//���
		int dfr;		//������
		int zdqdy;		//�ƶ�����ѹ
		int yylgg;		//ҷ���ֹ��
		int jf;			//����
		int bpqxh;		//��Ƶ���ͺ�
		int bmqxh;		//�������ͺ�
		CString dlcd;	//���³���
		CString zxcd;	//բ�߳���
		int mpzl;		//���Ƶ�����
		CString ddrq;	//��������
		CString bz;		//��ע
		int zjdy;		//������ѹ
		int zjys;		//������ɫ
		int zdqxh;		//�ƶ����ͺ�
		int zyz;		//��/����
		int bzxdtgg;	//��װ��/���й��
		CString gh;		//����
		int zzs;		//������
		int khqy;		//�ͻ�����
		int yxj;		//���ȼ�

		tagOption_t(){
			htbh = OPT_FALSE;			//��ͬ��
			khmc = OPT_FALSE_INT;		//�ͻ�����
			ggbh = OPT_FALSE_INT;		//����ͺ�
			sl = OPT_FALSE;				//����
			zc = OPT_FALSE_INT;			//���
			dfr = OPT_FALSE_INT;		//������
			zdqdy = OPT_FALSE_INT;		//�ƶ�����ѹ
			yylgg = OPT_FALSE_INT;		//ҷ���ֹ��
			jf = OPT_FALSE_INT;			//����
			bpqxh = OPT_FALSE_INT;		//��Ƶ���ͺ�
			bmqxh = OPT_FALSE_INT;		//�������ͺ�
			dlcd = OPT_FALSE;			//���³���
			zxcd = OPT_FALSE;			//բ�߳���
			mpzl = OPT_FALSE_INT;		//���Ƶ�����
			ddrq = OPT_DATE_NULL;			//��������
			bz = OPT_FALSE;				//��ע
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

