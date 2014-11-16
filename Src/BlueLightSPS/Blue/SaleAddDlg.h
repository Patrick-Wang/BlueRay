#pragma once
#include "AddDlg.h"
#include "UILib/BSStatic.h"
class CSaleAddDlg :	public CAddDlg
{
public:
	CSaleAddDlg(LPCTSTR title, CWnd* pParent = NULL);
	~CSaleAddDlg();
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
	CFont* m_pfont;
	CComboBox* m_aCombs[CombId::END];
	virtual void PostNcDestroy();
};

