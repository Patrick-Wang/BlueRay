#pragma once

class CTempCleaner
{
public:
	CTempCleaner(std::vector<CString>& refList, int col)
		: m_refList(refList)
		, m_iCol(col)
	{
		if (refList.size() > col)
		{
			m_rawData = refList[col];
			refList[col].Empty();
		}
		
	};

	~CTempCleaner(){
		if (m_refList.size() > m_iCol)
		{
			m_refList[m_iCol] = m_rawData;
		}
	}
private:
	std::vector<CString>& m_refList;
	CString m_rawData;
	int m_iCol;
};

