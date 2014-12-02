#ifndef __SETTINGMANAGER_H__
#define __SETTINGMANAGER_H__

#include "XMLParser.h"
#include "CommonDefine.h"

class CSettingManager
{
public:
	CSettingManager(void);
	virtual ~CSettingManager(void);

public:
	bool SetTableFilterSettingForSale(LPCTSTR lpSettingName, LPCTSTR lpIsSelected);
	bool GetTableFilterSettingForSale(LPCTSTR lpSettingName, CString& lpIsSelected);
	bool SetTableFilterSettingForPlan(LPCTSTR lpSettingName, LPCTSTR lpIsSelected);
	bool GetTableFilterSettingForPlan(LPCTSTR lpSettingName, CString& lpIsSelected);

private:
	bool Initialize();
	bool Uninitialize();

private:
	CXMLParser m_objXMLParser;
	MSXML2::IXMLDOMNodePtr m_pSettingRootNode;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNode;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNodeForSale;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNodeForPlan;
	bool m_bParserInitialized;
};

#endif