
/**
 *  解析完的数据放到data这个二维数组中，通过getData(int m,int n)
 *  获取数据
 **/

#ifndef _CSVPARSE_
#define _CSVPARSE_

#include <vector>


using namespace std;
class CCSVParser {
    
public:
    CCSVParser(LPCTSTR sep = _T(","))
		: m_strSep(sep) {}
private:
	CString m_strSep;  // separator characters
	CString m_strCSV;
	int index;
	int iStart;
	int advplain(const CString& line, CString& field, int iCurrent);
	int advquoted(const CString& line, CString& field, int iCurrent);
	void readFile(LPCTSTR lpPath, CString& strCSV);
	void split(CString& line, vector<CString>& fields);
public: 
    void parse(LPCTSTR lpPath);
	bool next(vector<CString>& line);

};

#endif

