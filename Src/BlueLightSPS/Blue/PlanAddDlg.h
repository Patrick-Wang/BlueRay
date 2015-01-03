#pragma once
#include "PopupDlg.h"
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

		CString scrq;	//��������
		CString jhywsh;	//�ƻ����-ҵ��
		CString jhjhsh;	//�ƻ����-�ƻ�
		CString bzrq;	//��װ����
		CString bzywsh;	//��װ���-ҵ��
		CString bzjhsh;	//��װ���-�ƻ�
		CString fhrq;	//��������
		CString tcbh;	//Ͷ�����
		CString ccbh;	//�������

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

			scrq = OPT_FALSE;	//��������

			jhywsh = OPT_FALSE;	//�ƻ����-ҵ��
			jhjhsh = OPT_FALSE;	//�ƻ����-�ƻ�

			bzrq = OPT_FALSE;	//��װ����

			bzywsh = OPT_FALSE;	//��װ���-ҵ��
			bzjhsh = OPT_FALSE;	//��װ���-�ƻ�

			fhrq = OPT_FALSE;	//��������
			tcbh = OPT_FALSE;	//Ͷ�����
			ccbh = OPT_FALSE;	//�������
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

				do_get(data, it, scrq);
				
				do_get(data, it, jhywsh);
				do_get(data, it, jhjhsh);

				do_get(data, it, bzrq);

				do_get(data, it, bzywsh);
				do_get(data, it, bzjhsh);
				
				do_get(data, it, fhrq);
				do_get(data, it, tcbh);
				do_get(data, it, ccbh);

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

				do_get_merge(data, it, scrq);

				do_get_merge(data, it, jhywsh);
				do_get_merge(data, it, jhjhsh);
				
				do_get_merge(data, it, bzrq);
				
				do_get_merge(data, it, bzywsh);
				do_get_merge(data, it, bzjhsh);

				do_get_merge(data, it, fhrq);
				do_get_merge(data, it, tcbh);
				do_get_merge(data, it, ccbh);

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
		
		Static_SCRQ,
		Static_BZRQ,
		Static_FHRQ,
		Static_TCBH,
		Static_CCBH,

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

		Static2_END
	};

	enum EditId{
		Edit_TCBH,
		Edit_CCBH,
		Edit_END
	};

	enum DatePickerId{
		DatePicker_SCRQ,
		DatePicker_BZRQ,
		DatePicker_FHRQ,
		DatePicker_END
	};

public:
	virtual BOOL OnInitDialog();
	void ConfigPlanBtns(bool scrq, bool bzrq);

protected:
	virtual void OnOK();

private:
	Option_t* m_lpOption;

	CBSStatic* m_aStatics[StaticId::Static_END];
	CBSStatic* m_aStaticsToShow[StaticId2::Static2_END];
	CEdit* m_aEdits[EditId::Edit_END];
	CDateTimeCtrl* m_aDatePickers[DatePickerId::DatePicker_END];

	bool m_bEnablePlanBtnForSCRQ;
	bool m_bEnablePlanBtnForBZRQ;

	virtual void PostNcDestroy();
};

