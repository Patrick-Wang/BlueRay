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
		CString htbh;	//��ͬ��
		int khmc;		//�ͻ�����
		int ggbh;		//����ͺ�
		int sl;			//����
		int dfr;		//������
		int zdqdy;		//�ƶ�����ѹ
		int zylgg;		//ҷ���ֹ��
		int jf;			//����
		int bpqxh;		//��Ƶ���ͺ�
		int bmqxh;		//�������ͺ�
		int dlcd;		//���³���
		int zxcd;		//բ�߳���
		CString mpzl;	//���Ƶ�����
		CString bz;		//��ע
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
	enum CombId{
		KHMC,
		GGBH,
		DFR,
		ZDQDY,
		ZYLGG,
		JF,
		BPQXH,
		BMQXH,
		DLCD,
		ZXCD,
		END
	};
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOKClicked();
private:
	Option_t* m_lpOption;
	CFont* m_pfont;
	CComboBox* m_aCombs[CombId::END];
	virtual void PostNcDestroy();
};

