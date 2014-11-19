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
		Comb_ZC,
		Comb_DFR, 
		Comb_ZDQDY,
		Comb_YYLGG,
		Comb_JF,
		Comb_BPQXH,
		Comb_BMQXH,
		Comb_MPZL,
		//Comb_DLCD,
		//Comb_ZXCD,
		Comb_END
	};

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
			ddrq = OPT_FALSE;			//��������
			bz = OPT_FALSE;				//��ע
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
				do_get(data, it, ddrq);
				do_get(data, it, bz);

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
				do_get_merge(data, it, ddrq);
				do_get_merge(data, it, bz);

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
		Static_END
	};

	enum EditId{
		Edit_HTH,
		Edit_SL,
		Edit_DLCD,
		Edit_ZXCD,
		Edit_DDRQ,
		Edit_BZ,
		Edit_END
	};

public:
	virtual BOOL OnInitDialog();
	static const std::vector<std::vector<CString>>& GetDropList();
protected:
	virtual void OnOKClicked();
private:
	Option_t* m_lpOption;
	static std::vector<std::vector<CString>> m_DropList;
	CBSStatic* m_aStatics[StaticId::Static_END];
	CComboBox* m_aCombs[CombId::Comb_END];
	CEdit* m_aEdits[EditId::Edit_END];
	virtual void PostNcDestroy();
};

