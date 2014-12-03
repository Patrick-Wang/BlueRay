#pragma once
#include "ControlPanel.h"
#include "JQGridAPI.h"
#include "IHttp.h"
class CBRPanel :
	public CControlPanel
{
public:
	CBRPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp);
	~CBRPanel();
	bool IsUpdated();
	void HasUpdate();
	void Updated();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnHttpSuccess(int id, LPCTSTR resp) = 0;
	virtual void OnHttpFailed(int id) = 0;
	virtual void OnRowChecked() = 0;
	std::vector < std::pair<int, StringArray>>& StringToTable(CString& json2DemArray, std::vector < std::pair<int, StringArray>>& table);
	StringArray& ToStringArray(IntArray& src, StringArray& dest);
protected:
	std::auto_ptr<CJQGridAPI> m_pJqGridAPI;
	IHttp* m_pHttp;
	bool m_bHasUpdate;
};

