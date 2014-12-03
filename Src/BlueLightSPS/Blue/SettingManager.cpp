#include "StdAfx.h"
#include "SettingManager.h"
#include "CommonDefine.h"
#include "Util.h"

static CString strPath = _T("");

CSettingManager::CSettingManager(void)
	: m_bParserInitialized(false)
{
}

bool CSettingManager::Initialize()
{
	bool bRet(false);

	try
	{
		do
		{
			if (!m_bParserInitialized)
			{
				m_objXMLParser.Initialize();
				m_bParserInitialized = true;
			}

			if (!Util_Tools::Util::GetExpandPath(IDS_SETTING_LOCATION, strPath))
			{
				break;
			}

			strPath += IDS_SETTING_FILENAME;
			if (!PathFileExists(strPath))
			{
				if (!Util_Tools::Util::MakeDir(strPath))
				{
					break;
				}

				//create file

				m_pSettingRootNode = m_objXMLParser.CreateRoot(IDS_SETTING_ITEM_ROOT);
				if (NULL == m_pSettingRootNode)
				{
					break;
				}

				m_pTableFilterNode = m_objXMLParser.CreateChildNode(m_pSettingRootNode, IDS_SETTING_ITEM_TABLEFILTER, _T(""));
				if (NULL == m_pTableFilterNode)
				{
					break;
				}

				m_pTableFilterNodeForSale = m_objXMLParser.CreateChildNode(m_pTableFilterNode, IDS_SETTING_ITEM_TABLEFILTER_SALE, _T(""));
				if (NULL == m_pTableFilterNodeForSale)
				{
					break;
				}

				m_pTableFilterNodeForPlan = m_objXMLParser.CreateChildNode(m_pTableFilterNode, IDS_SETTING_ITEM_TABLEFILTER_PLAN, _T(""));
				if (NULL == m_pTableFilterNodeForPlan)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pNode = NULL;

				//Sale page
				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_HTH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_KHMC, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_GGBH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_SL, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_ZC, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_DFR, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_ZDQDY, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_YYLGG, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_JF, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_BPQXH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_BMQXH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_DLCD, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_ZXCD, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_MPZL, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_BZ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_DDRQ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_SHYW, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForSale, IDS_SETTING_ITEM_TABLEFILTER_SHJH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}


				//Plan page
				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_HTH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_KHMC, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_GGBH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_SL, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_ZC, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_DFR, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_ZDQDY, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_YYLGG, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_JF, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BPQXH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BMQXH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_DLCD, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_ZXCD, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_MPZL, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BZ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_DDRQ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_SHYW, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_SHJH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_SCRQ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_JHSHYW, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_JHSHJH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BZRQ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BZSHYW, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_BZSHJH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_FHRQ, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				pNode = m_objXMLParser.CreateChildNode(m_pTableFilterNodeForPlan, IDS_SETTING_ITEM_TABLEFILTER_TCBH, IDS_SETTING_ITEM_TABLEFILTER_DEFAULTVALUE);
				if (NULL == pNode)
				{
					break;
				}

				int iRet = m_objXMLParser.SaveXML(strPath);
				if (ERR_OK != iRet)
				{
					break;
				}
			}
			else
			{
				int iRet = m_objXMLParser.LoadXML(strPath);
				if (ERR_OK != iRet)
				{
					break;
				}

				m_pSettingRootNode = m_objXMLParser.QueryRootNode();
				if (NULL == m_pSettingRootNode)
				{
					break;
				}

				m_pTableFilterNode = m_objXMLParser.QueryNode(m_pSettingRootNode, IDS_SETTING_ITEM_TABLEFILTER);
				if (NULL == m_pTableFilterNode)
				{
					break;
				}

				m_pTableFilterNodeForSale = m_objXMLParser.QueryNode(m_pTableFilterNode, IDS_SETTING_ITEM_TABLEFILTER_SALE);
				if (NULL == m_pTableFilterNode)
				{
					break;
				}

				m_pTableFilterNodeForPlan = m_objXMLParser.QueryNode(m_pTableFilterNode, IDS_SETTING_ITEM_TABLEFILTER_PLAN);
				if (NULL == m_pTableFilterNode)
				{
					break;
				}
			}

			bRet = true;

		} while (false);
	}
	catch (...)
	{

	}

	return bRet;
}

void CSettingManager::UnInitialize()
{
	if (m_bParserInitialized)
	{
		m_bParserInitialized = false;
		m_objXMLParser.Uninitialize();
	}
}

bool CSettingManager::SetTableFilterSettingForSale(LPCTSTR lpSettingName, LPCTSTR lpIsSelected)
{
	bool bRet = false;

	do
	{
		if (!m_bParserInitialized)
		{
			break;
		}

		if (NULL == m_pTableFilterNodeForSale)
		{
			break;
		}

		int iRet = m_objXMLParser.SetChildNodeData(m_pTableFilterNodeForSale, lpSettingName, lpIsSelected);
		if (ERR_OK != iRet)
		{
			break;
		}

		iRet = m_objXMLParser.SaveXML(strPath);
		if (ERR_OK != iRet)
		{
			break;
		}

		bRet = true;

	} while (false);

	return bRet;
}


bool CSettingManager::GetTableFilterSettingForSale(LPCTSTR lpSettingName, CString& lpIsSelected)
{
	bool bRet = false;

	do
	{
		if (!m_bParserInitialized)
		{
			break;
		}

		if (NULL == m_pTableFilterNodeForSale)
		{
			break;
		}

		int iRet = m_objXMLParser.GetChildNodeData(m_pTableFilterNodeForSale, lpSettingName, lpIsSelected);
		if (ERR_OK != iRet)
		{
			break;
		}

		bRet = true;

	} while (false);

	return bRet;
}


bool CSettingManager::SetTableFilterSettingForPlan(LPCTSTR lpSettingName, LPCTSTR lpIsSelected)
{
	bool bRet = false;

	do
	{
		if (!m_bParserInitialized)
		{
			break;
		}

		if (NULL == m_pTableFilterNodeForPlan)
		{
			break;
		}

		int iRet = m_objXMLParser.SetChildNodeData(m_pTableFilterNodeForPlan, lpSettingName, lpIsSelected);
		if (ERR_OK != iRet)
		{
			break;
		}

		iRet = m_objXMLParser.SaveXML(strPath);
		if (ERR_OK != iRet)
		{
			break;
		}

		bRet = true;

	} while (false);

	return bRet;
}


bool CSettingManager::GetTableFilterSettingForPlan(LPCTSTR lpSettingName, CString& lpIsSelected)
{
	bool bRet = false;

	do
	{
		if (!m_bParserInitialized)
		{
			break;
		}

		if (NULL == m_pTableFilterNodeForPlan)
		{
			break;
		}

		int iRet = m_objXMLParser.GetChildNodeData(m_pTableFilterNodeForPlan, lpSettingName, lpIsSelected);
		if (ERR_OK != iRet)
		{
			break;
		}

		bRet = true;

	} while (false);

	return bRet;
}
