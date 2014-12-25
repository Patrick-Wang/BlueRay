#include "stdafx.h"
#include "BRPanel.h"
#include "Util.h"

CBRPanel::CBRPanel(CJQGridAPI* pJqGridAPI, IHttp* pHttp)
	: m_pJqGridAPI(pJqGridAPI)
	, m_pHttp(pHttp)
	, m_bHasUpdate(true)
{
}


CBRPanel::~CBRPanel()
{
}
BEGIN_MESSAGE_MAP(CBRPanel, CControlPanel)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


void CBRPanel::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CControlPanel::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		m_pJqGridAPI->ShowGrid();
		m_pJqGridAPI->d_OnRowChecked += std::make_pair(this, &CBRPanel::OnRowChecked);
		m_pHttp->d_OnSuccess += std::make_pair(this, &CBRPanel::OnHttpSuccess);
		m_pHttp->d_OnFailed += std::make_pair(this, &CBRPanel::OnHttpFailed);
	}
	else
	{
		m_pJqGridAPI->HideGrid();
		m_pJqGridAPI->d_OnRowChecked -= std::make_pair(this, &CBRPanel::OnRowChecked);
		m_pHttp->d_OnSuccess -= std::make_pair(this, &CBRPanel::OnHttpSuccess);
		m_pHttp->d_OnFailed -= std::make_pair(this, &CBRPanel::OnHttpFailed);
	}

}

std::vector < std::pair<int, StringArray>>& CBRPanel::StringToTable(CString& json2DemArray, std::vector < std::pair<int, StringArray>>& table)
{
	std::vector<CString> vecTmp;
	json2DemArray.Replace(_T("],["), _T("#"));
	json2DemArray.Remove(_T('['));
	json2DemArray.Remove(_T(']'));
	json2DemArray.Remove(_T('\"'));
	Util_Tools::Util::Split(json2DemArray, _T('#'), vecTmp);
	table.clear();
	table.resize(vecTmp.size());
	for (int i = vecTmp.size() - 1; i >= 0; --i)
	{
		Util_Tools::Util::Split(vecTmp[i], _T(','), table[i].second);
		table[i].first = _tstoi(table[i].second[0]);
		table[i].second.erase(table[i].second.begin());
	}
	return table;
}

StringArray& CBRPanel::ToStringArray(IntArray& src, StringArray& dest)
{
	CString strTmp;
	dest.resize(src.size());
	for (int i = src.size() - 1; i >= 0; --i)
	{
		strTmp.Format(_T("%d"), src[i]);
		dest[i] = strTmp;
	}
	return dest;
}

void CBRPanel::HasUpdate()
{
	m_bHasUpdate = true;
}

void CBRPanel::Updated()
{
	m_bHasUpdate = false;
}

bool CBRPanel::IsUpdated()
{
	return !m_bHasUpdate;
}

void CBRPanel::OnUIPrepared()
{
	if (!IsUpdated())
	{
		Updated();
		OnInitData();
	}
}
