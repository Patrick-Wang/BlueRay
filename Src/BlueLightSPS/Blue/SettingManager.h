#ifndef __SETTINGMANAGER_H__
#define __SETTINGMANAGER_H__

#include "XMLParser.h"
#include "CommonDefine.h"
#include "Util.h"

class CSettingManager
{
	TO_BE_SINGLETON(CSettingManager);

public:
	bool SetColWidths(LPCTSTR lpSettingName, LPCTSTR jsonWidthArr);
	bool GetColWidths(LPCTSTR lpSettingName, CString& jsonWidthArr);
	bool SetTableFilterSettingForSale(LPCTSTR lpSettingName, LPCTSTR lpIsSelected);
	bool GetTableFilterSettingForSale(LPCTSTR lpSettingName, CString& lpIsSelected);
	bool SetTableFilterSettingForPlan(LPCTSTR lpSettingName, LPCTSTR lpIsSelected);
	bool GetTableFilterSettingForPlan(LPCTSTR lpSettingName, CString& lpIsSelected);
	bool SetTableFilterSettingForNotification(LPCTSTR lpSettingName, LPCTSTR lpIsSelected);
	bool GetTableFilterSettingForNotification(LPCTSTR lpSettingName, CString& lpIsSelected);
	bool GetDafaultSaleAddValue(CString& value);
	bool SetDafaultSaleAddValue(CString& value);

private:
	CXMLParser m_objXMLParser;
	MSXML2::IXMLDOMNodePtr m_pSettingRootNode;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNode;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNodeForSale;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNodeForPlan;
	MSXML2::IXMLDOMNodePtr m_pTableFilterNodeForNotification;
	MSXML2::IXMLDOMNodePtr m_pColWidthNode;
	MSXML2::IXMLDOMNodePtr m_pDefaultValueNode;
	bool m_bParserInitialized;
};

#endif