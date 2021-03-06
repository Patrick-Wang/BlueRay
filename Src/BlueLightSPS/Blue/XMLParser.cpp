#include "StdAfx.h"
#include "XMLParser.h"

LPCTSTR gszXMLDocNS = _T("");

void CStringToVariant(const CString& strData, VARIANT& vData)
{
    CComBSTR clComBSTR(strData);
    switch (vData.vt)
    {
    case VT_I2:
        {
			vData.iVal = static_cast<SHORT>(_wtoi(strData));
        }
        break;

    case VT_I4:
        {
            vData.lVal = _wtol(strData);
        }
        break;

    case VT_R4:
        {
			vData.fltVal = static_cast<SHORT>(_wtof(strData));
        }
        break;

    case VT_R8:
        {
            vData.dblVal = _wtof(strData);
        }
        break;

    case VT_BOOL:
        {
			vData.boolVal = static_cast<SHORT>(_wtoi(strData));
        }
        break;

    case VT_BSTR:
        {
            vData.bstrVal = clComBSTR.Copy();
        }
        break;

    default:
        {
            VariantClear(&vData);
        }
        break;
    }
}

CString VariantToCString(VARIANT var)
{
    CString strValue;
    _variant_t clVar_t;
    _bstr_t clBstr_t;
    switch (var.vt)
    {
    case VT_EMPTY:
        {
            strValue = _T("");
        }
        break;

    case VT_UI1:
        {
            strValue.Format(_T("%d"), var.bVal);
        }
        break;

    case VT_I2:
        {
            strValue.Format(_T("%d"), var.iVal);
        }
        break;

    case VT_I4:
        {
            strValue.Format(_T("%d"), var.lVal);
        }
        break;

    case VT_R4:
        {
            strValue.Format(_T("%f"), var.fltVal);
        }
        break;

    case VT_R8:
        {
            strValue.Format(_T("%f"), var.dblVal);
        }
        break;

    case VT_BSTR:
        {
            clVar_t = var;
            clBstr_t = clVar_t;
            strValue.Format(_T("%s"), (TCHAR*)clBstr_t);
        }
        break;

    case VT_NULL:
        {
            strValue = _T("");
        }
        break;

    case VT_BOOL:
        {
            strValue.Format(_T("%d"), var.boolVal);
        }
        break;

    default:
        {
            strValue = _T("");
        }
        break;
    }
    return strValue;
}

CXMLParser::CXMLParser(void)
    : m_bParserInitialized(FALSE)
    , m_bIsComInitializeSuccess(FALSE)
{
	Initialize();
}

CXMLParser::~CXMLParser(void)
{
    if (m_bParserInitialized)
    {
        Uninitialize();
        m_bParserInitialized = FALSE;
    }
}

int CXMLParser::Initialize(void)
{
    int iRet = ERR_OK;
    if (!m_bParserInitialized)
    {
        try
        {
            HRESULT hr = CoInitialize(NULL);
            if (S_OK == hr)
            {
                m_bIsComInitializeSuccess = TRUE;
            }
            hr = m_pXMLDom.CreateInstance(__uuidof(MSXML2::DOMDocument60));
            if (ISFAILED(hr))
            {
                iRet = ERR_FAILED_TO_INIT_DOM;
            }
            else
            {
                m_pXMLDom->async = VARIANT_FALSE; // default - true,
                m_pXMLDom->put_preserveWhiteSpace(VARIANT_TRUE);
                m_bParserInitialized = TRUE;
            }
        }
        catch(...)
        {
            iRet = ERR_FAILED_TO_INIT_DOM;
        }
    }
    return iRet;
}

int CXMLParser::ReInitialize()
{
    int iRet = ERR_OK;
    try
    {
        MSXML2::IXMLDOMNodePtr pChildNode;
        MSXML2::IXMLDOMNodeListPtr pNodeList;
        MSXML2::IXMLDOMNodePtr(m_pXMLDom)->get_childNodes(&pNodeList);
        if (NULL != pNodeList)
        {
            pChildNode = pNodeList->nextNode();
            while (pChildNode != NULL)
            {
                MSXML2::IXMLDOMNodePtr(m_pXMLDom)->removeChild(pChildNode);
                pChildNode = pNodeList->nextNode();
            }
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_RELEASE_DOM;
    }
    return iRet;
}

int CXMLParser::Uninitialize(void)
{
    int iRet = ERR_OK;
    if ( m_bParserInitialized )
    {
        try
        {
            m_pXMLDom.Release();
            m_bParserInitialized = FALSE;
        }
        catch(...)
        {
            iRet = ERR_FAILED_TO_RELEASE_DOM;
        }

        if (m_bIsComInitializeSuccess)
        {
            CoUninitialize();
            m_bIsComInitializeSuccess = FALSE;
        }
    }
    return iRet;
}

int CXMLParser::LoadXML(CString XMLFileName)
{
    int iRet = ERR_OK;
    if ( m_bParserInitialized )
    {
        try
        {
            if (VARIANT_TRUE != m_pXMLDom->load(XMLFileName.GetBuffer()))
            {
                iRet = ERR_FAILED_TO_LOAD_XML;
            }
            else
            {
            }
        }
        catch( ... )
        {
            iRet = ERR_FAILED_TO_LOAD_XML;
        }
    }
    else
    {
        iRet = ERR_FAILED_TO_INIT_DOM;
    }
    return iRet;
}

int CXMLParser::LoadXMLByStream(CComPtr<IStream> pStream)
{
	int iRet = ERR_OK;
	if ( m_bParserInitialized )
	{
		try
		{
			CComBSTR bstrFileContent;
			bstrFileContent.ReadFromStream(pStream);
			if (VARIANT_TRUE != m_pXMLDom->loadXML((BSTR)bstrFileContent))
			{
				iRet = ERR_FAILED_TO_LOAD_XML;
			}
			else
			{
			}
		}
		catch( ... )
		{
			iRet = ERR_FAILED_TO_LOAD_XML;
		}
	}
	else
	{
		iRet = ERR_FAILED_TO_INIT_DOM;
	}
	return iRet;
}

int CXMLParser::LoadXMLFromString(CString XMLFileContent)
{
	int iRet = ERR_OK;
	if ( m_bParserInitialized )
	{
		try
		{
			if (VARIANT_TRUE != m_pXMLDom->loadXML(XMLFileContent.GetBuffer()))
			{
				iRet = ERR_FAILED_TO_LOAD_XML;
			}
		}
		catch( ... )
		{
			iRet = ERR_FAILED_TO_LOAD_XML;
		}
	}
	else
	{
		iRet = ERR_FAILED_TO_INIT_DOM;
	}
	return iRet;
}

int CXMLParser::GetXMLFileContent(CString &strXmlContent)
{
	int iRet = ERR_OK;
	if ( m_bParserInitialized )
	{
		try
		{
			CComBSTR bstrXMLContent = NULL;
			if (S_OK != m_pXMLDom->get_xml((BSTR*)&bstrXMLContent))
			{
				iRet = ERR_FAILED_TO_LOAD_XML;
			}
			strXmlContent = (LPCTSTR)bstrXMLContent;
		}
		catch( ... )
		{
			iRet = ERR_FAILED_TO_LOAD_XML;
		}
	}
	else
	{
		iRet = ERR_FAILED_TO_INIT_DOM;
	}
	return iRet;
}

int CXMLParser::SaveXML(CString XMLFileName)
{
    int iRet = ERR_OK;
    if ( m_bParserInitialized )
    {
        try
        {
            HRESULT hr = m_pXMLDom->save(XMLFileName.GetBuffer());
            if (ISFAILED(hr))
            {
                iRet = ERR_FAILED_TO_SAVE_XML;
            }
            else
            {
            }
        }
        catch(...)
        {
            iRet = ERR_FAILED_TO_SAVE_XML;
        }
    }
    else
    {
        iRet = ERR_FAILED_TO_INIT_DOM;
    }
    return iRet;
}

int CXMLParser::Validate()
{
    int iRet = ERR_OK;
    try
    {
        MSXML2::IXMLDOMParseErrorPtr pXMLError = NULL;
        MSXML2::IXMLDOMSchemaCollection2Ptr pSchemaCache = NULL;
        HRESULT hr = pSchemaCache.CreateInstance(__uuidof(MSXML2::XMLSchemaCache60));
        if ( ISFAILED(hr) ) 
        {
            iRet = ERR_FAILED_TO_LOAD_SCHEMA;
        }
        else
        {
            if (m_strXSDFileName.IsEmpty())
            {
                iRet = ERR_FAILED_TO_LOAD_SCHEMA;
            }
            else
            {
                hr = pSchemaCache->add(gszXMLDocNS, m_strXSDFileName.AllocSysString());
                m_pXMLDom->schemas = pSchemaCache.GetInterfacePtr();
				m_pXMLDom->async = false;
				m_pXMLDom->validateOnParse = true;

                pXMLError = m_pXMLDom->validate();
                if ((const wchar_t*)pXMLError->reason)
                {
                    iRet = ERR_FAILED_TO_VALIDATE;
                }
            }
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_VALIDATE;
    }
    return iRet;
}

MSXML2::IXMLDOMNodePtr CXMLParser::QueryRootNode()
{
    MSXML2::IXMLDOMElementPtr pElement = NULL;
    if ( m_bParserInitialized )
    {
        try
        {
            HRESULT hr = m_pXMLDom->get_documentElement(&pElement);
            if (ISFAILED(hr))
            {
            }
            else
            {
            }
        }
        catch(...)
        {
        }
    }
    return (pElement);
}

MSXML2::IXMLDOMNodePtr CXMLParser::QueryNode(const MSXML2::IXMLDOMNodePtr& pSrcNode,
                                             const CString& strNodeName)
{
    MSXML2::IXMLDOMNodePtr pDesNode;
    CComBSTR clBSTR(strNodeName);
    if (m_bParserInitialized)
    {
        try
        {
            pDesNode = pSrcNode->selectSingleNode(BSTR(clBSTR));
        }
        catch(...)
        {
            pDesNode = NULL;
        }
    }
    return pDesNode;
}

MSXML2::IXMLDOMNodePtr CXMLParser::CreateChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                                   const CString& strName,
                                                   const CString& strData)
{
    MSXML2::IXMLDOMNodePtr	pNewNode;
    MSXML2::IXMLDOMNodePtr  pRetNode;
    CComBSTR clComBSTRData(strData);
    try
    {
        CComBSTR clComBSTR(strName); 
        pNewNode = m_pXMLDom->createElement(BSTR(clComBSTR));
        if (NULL == pNewNode)
        {
            throw 1;
        }
        else
        {
            pNewNode->put_text(clComBSTRData);
            pRetNode = pParentNode->appendChild(pNewNode);
        }
    }
    catch(...)
    {
        pRetNode = NULL;
    }
    return pRetNode;
}

MSXML2::IXMLDOMNodePtr CXMLParser::CreateChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                                   const CString& strName,
                                                   const VARIANT& vData)
{
    MSXML2::IXMLDOMNodePtr pNewNode;
    MSXML2::IXMLDOMNodePtr pRetNode;
    try
    {
        CComBSTR clComBSTR(strName);
        pNewNode = m_pXMLDom->createElement(BSTR(clComBSTR));
        if (NULL == pNewNode)
        {
            throw 1;
        }
        else
        {
            if (vData.vt != VT_EMPTY)
            {
                pNewNode->put_nodeTypedValue(vData);
            }
            else
            {
                pNewNode->put_text(_T("\n\t"));
            }
            pRetNode = pParentNode->appendChild(pNewNode); 

        }//end if
    }
    catch(...)
    {
        pRetNode = NULL;
    }
    return pRetNode;
}

int CXMLParser::CreateAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                const CString& strName,
                                const CString& strData)
{
    int iRet = ERR_OK;
    VARIANT vData;
    VariantInit(&vData);
    vData.vt = VT_BSTR;
    CStringToVariant(strData, vData);
    iRet = CreateAttribute(pParentNode, strName, vData);
    VariantClear(&vData);
    return iRet;
}

int CXMLParser::CreateAttribute(const MSXML2::IXMLDOMNodePtr& pNode,
                                const CString& strName,
                                const VARIANT& vData)
{
    int iRet = ERR_OK;
    try
    {
        CComBSTR clComBSTR(strName); 
        MSXML2::IXMLDOMAttributePtr pAttrbute = m_pXMLDom->createAttribute(BSTR(clComBSTR));
        if (NULL == pAttrbute)
        {
            iRet = ERR_FAILED_TO_CREATE_ATTR;
        }
        else
        {
            MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap;
            HRESULT hr = pNode->get_attributes(&pAttrMap);
            if (ISFAILED(hr))
            {
                iRet = ERR_FAILED_TO_CREATE_ATTR;
            }
            else
            {
                MSXML2::IXMLDOMNodePtr pNewNode;
                hr = pAttrbute->put_nodeTypedValue(vData);
                if (ISFAILED(hr))
                {
                    iRet = ERR_FAILED_TO_CREATE_ATTR;
                }
                pNewNode = pAttrMap->setNamedItem(pAttrbute);
        }
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_CREATE_ATTR;
    }
    return iRet;
}

int CXMLParser::GetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, VARIANT& vData)
{
	CString strData;
	int iRet = GetNodeData(pParentNode, strData);
	if (ERR_OK == iRet)
	{
		CStringToVariant(strData, vData);
		if (VT_EMPTY == vData.vt)
		{
			iRet = ERR_FAILED_TO_GET_NODE;
		}
	}
	return iRet;
}

int CXMLParser::GetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, CString& strData)
{
    int iRet = ERR_OK;
    VARIANT vtype;
    VariantInit(&vtype);
    try
    {
        HRESULT hr = pParentNode->get_nodeTypedValue(&vtype);
        if (ISFAILED(hr))
        {
            iRet = ERR_FAILED_TO_GET_NODE;
        }
        else
        {
            strData = VariantToCString(vtype);
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_GET_NODE;
    }
    VariantClear(&vtype);
    return iRet;
}

int CXMLParser::SetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, const CString& strData)
{
    int iRet = ERR_OK;
    CComBSTR clComBSTR(strData);
    try
    {
        HRESULT hr = pParentNode->put_text(clComBSTR);
        if (ISFAILED(hr))
        {
            iRet = ERR_FAILED_TO_SET_NODE;
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_SET_NODE;
    }
    return iRet;
}

int CXMLParser::SetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, VARIANT vData)
{
    int iRet = ERR_OK;
    try
    {
        HRESULT hr = pParentNode->put_nodeTypedValue(vData);
        if (ISFAILED(hr))
        {
            iRet = ERR_FAILED_TO_SET_NODE;
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_SET_NODE;
    }
    return iRet;
}

int CXMLParser::GetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode, CString& strName, VARIANT& vData)
{
    int iRet = ERR_OK;
    CString strData;
    iRet = GetNodeAttribute(pParentNode, strName, strData);
    if (ERR_OK == iRet)
    {
        CStringToVariant(strData, vData);
        if (VT_EMPTY == vData.vt)
        {
            iRet = ERR_FAILED_TO_FIND_ATRRIBUTE;
        }
    }
    return iRet;
}

int CXMLParser::GetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strName,
                                 CString& strData)
{
    int iRet = ERR_OK;
    VARIANT vtype;
    VariantInit(&vtype);

    MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap;
    try
    {
        HRESULT hr = pParentNode->get_attributes(&pAttrMap);
        if (S_OK != hr)
        {
            iRet = ERR_FAILED_TO_FIND_ATRRIBUTE;
        }
        else
        {
            MSXML2::IXMLDOMNodePtr pAttrNode;
            pAttrNode = pAttrMap->getNamedItem(_bstr_t(strName));
            if (NULL == pAttrNode)
            {
                iRet = ERR_FAILED_TO_FIND_ATRRIBUTE;
            }
            else
            {
                pAttrNode->get_nodeTypedValue(&vtype);
                strData = VariantToCString(vtype);
            }
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_FIND_ATRRIBUTE;
    }
    VariantClear(&vtype);
    return iRet;
}

int CXMLParser::SetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strName,
                                 const CString& strData)
{
    VARIANT vData;
    VariantInit(&vData);
    vData.vt = VT_BSTR;
    CStringToVariant(strData, vData);
    int iRet = SetNodeAttribute(pParentNode, strName, vData);
    VariantClear(&vData);
    return iRet;
}

int CXMLParser::SetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strName,
                                 const VARIANT& vData)
{
    int iRet = ERR_OK;
    try
    {
        CComBSTR clComBSTR(strName);
        HRESULT hr = MSXML2::IXMLDOMElementPtr(pParentNode)->setAttribute(_bstr_t(clComBSTR), vData);
        if ( ISFAILED(hr) ) 
        {
            iRet = CreateAttribute(pParentNode, strName, vData);
        }
    }
    catch(...)
    {
        iRet = ERR_FAILED_TO_SET_ATTR;
    }
    return iRet;
}

int CXMLParser::SetXSDFilePath(const CString& strXSDFilePath)
{
    int iRet = ERR_FAILED_TO_LOAD_XSD;
    WIN32_FIND_DATA FileData;
    HANDLE hFile = NULL;
    hFile = ::FindFirstFile(strXSDFilePath, &FileData);
    if (!strXSDFilePath.Right(4).CompareNoCase(_T(".xsd")) && (hFile != INVALID_HANDLE_VALUE))
    {
        m_strXSDFileName = strXSDFilePath;
        iRet = ERR_OK;
    }
    ::FindClose(hFile);
    return iRet;
}

MSXML2::IXMLDOMNodePtr CXMLParser::CreateRoot(const CString& strRoot)
{
    MSXML2::IXMLDOMProcessingInstructionPtr tagPI_t;
    CComBSTR clComBSTR(_T("xml"));
    CComBSTR clComBSTRTitle(_T("version='1.0' encoding='UTF-8'"));
    MSXML2::IXMLDOMNodePtr pRetNode;
    try
    {
        tagPI_t = m_pXMLDom->createProcessingInstruction(BSTR(clComBSTR), BSTR(clComBSTRTitle));
        MSXML2::IXMLDOMNodePtr pNewNode;
        pNewNode = MSXML2::IXMLDOMNodePtr(m_pXMLDom)->appendChild(tagPI_t);
        if (NULL == pNewNode)
        {
            throw 1;
        }

        CComBSTR clComBSTRRoot(strRoot);
        pNewNode = m_pXMLDom->createElement(BSTR(clComBSTRRoot));
        pRetNode = MSXML2::IXMLDOMNodePtr(m_pXMLDom)->appendChild(pNewNode);
    }
    catch(...)
    {
        pRetNode = NULL;
    }
    return pRetNode;
}

int CXMLParser::GetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strNodeName,
                                 CString& strData)
{
	int iRet = ERR_OK;
	MSXML2::IXMLDOMNodePtr pChildNode = QueryNode(pParentNode, strNodeName);
	if (NULL == pChildNode)
	{
		iRet = ERR_FAILED_TO_QUREY_NODE;
	}
	else
	{
		iRet = GetNodeData(pChildNode, strData);
	}
	return iRet;
}

int CXMLParser::SetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strNodeName,
                                 const CString& strData)
{
	int iRet = ERR_OK;
	MSXML2::IXMLDOMNodePtr pChildNode = QueryNode(pParentNode, strNodeName);
	if (NULL == pChildNode)
	{
		pChildNode = CreateChildNode(pParentNode, strNodeName, strData);
		if (NULL == pChildNode)
		{
			iRet = ERR_FAILED_TO_CREATE_NODE;
		}
	}
	else
	{
		iRet = SetNodeData(pChildNode, strData);
	}
	return iRet;
}

int CXMLParser::SetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strNodeName,
                                 const VARIANT& vData)
{
    int iRet = ERR_OK;
    MSXML2::IXMLDOMNodePtr pChildNode = QueryNode(pParentNode, strNodeName);
    if (NULL == pChildNode)
    {
        pChildNode = CreateChildNode(pParentNode, strNodeName, vData);
        if (NULL == pChildNode)
        {
            iRet = ERR_FAILED_TO_CREATE_NODE;
        }
    }
    else
    {
        iRet = SetNodeData(pChildNode, vData);
    }
    return iRet;
}

int CXMLParser::GetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                 const CString& strNodeName,
                                 VARIANT& vData)
{
    CString strData;
    int iRet = GetChildNodeData(pParentNode, strNodeName, strData);
    if (ERR_OK == iRet)
    {
        CStringToVariant(strData, vData);
        if (VT_EMPTY == vData.vt)
        {
            iRet = ERR_FAILED_TO_QUREY_NODE;
        }
    }
    return iRet;
}

int CXMLParser::DelSingleChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode, MSXML2::IXMLDOMNodePtr& pSingleChildNode)
{
	int iRet = ERR_OK;
	MSXML2::IXMLDOMNodePtr pDeletedNode;
	if (NULL != pParentNode)
	{
		if (NULL != pSingleChildNode)
		{
			pDeletedNode = pParentNode->removeChild(pSingleChildNode);
			if (NULL == pDeletedNode)
			{
				iRet = ERR_FAILED_TO_QUREY_NODE;
			}
		}
		else
		{
			iRet = ERR_NODE;
		}
	}
	else
	{
		iRet = ERR_NODE;
	}

	return iRet;
}