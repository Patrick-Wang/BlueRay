#ifndef __XMLParser_H__
#define __XMLParser_H__

#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi")
#import <msxml6.dll>

#define ISFAILED(Status) (S_OK != (HRESULT)(Status))

enum tagERR_DEFINE_Enum
{
    ERR_OK = 0x00,
    ERR_FAILED_TO_INIT_DOM,
    ERR_FAILED_TO_RELEASE_DOM,
    ERR_FAILED_TO_LOAD_XML,
    ERR_FAILED_TO_SAVE_XML,
    ERR_FAILED_TO_QUREY_NODE,
    ERR_FAILED_TO_CREATE_NODE,
    ERR_FAILED_TO_CREATE_ATTR,
    ERR_FAILED_TO_SET_ATTR,
    ERR_FAILED_TO_VALIDATE,
    ERR_FAILED_TO_LOAD_SCHEMA,
    ERR_FAILED_TO_FIND_ATRRIBUTE,
    ERR_FAILED_TO_SET_NODE,
    ERR_FAILED_TO_GET_NODE,
    ERR_FAILED_TO_LOAD_XSD,
    ERR_FAILED_TO_NEWXML,
    ERR_NODE
};


//////////////////////////////////////////////////////////////////////////
//CXMLParser

class CXMLParser
{
public:
    CXMLParser(void);
    ~CXMLParser(void);
    int Initialize(void);
    int Uninitialize(void);
    int ReInitialize();

    MSXML2::IXMLDOMNodePtr CreateChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                            const CString& strName,
                                            const VARIANT& vData);
    MSXML2::IXMLDOMNodePtr CreateChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode,
                                            const CString& strName,
                                            const CString& strData);

    int CXMLParser::CreateAttribute(const MSXML2::IXMLDOMNodePtr& pNode,
                                    const CString& strName,
                                    const VARIANT& vData);
    int CreateAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                        const CString& strName,
                        const CString& strData);

    int GetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, CString& strData);
    int GetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, VARIANT& vData);

    int SetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, VARIANT vData);
    int SetNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode, const CString& strData);

    int GetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode,
                         const CString& strName,
                         CString& strData);
    int GetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode, CString& strName, VARIANT& vData);

    int SetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode, const CString& strName, const CString& strData);
    int SetNodeAttribute(const MSXML2::IXMLDOMNodePtr& pParentNode, const CString& strName, const VARIANT& vData);

    int GetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                         const CString& strNodeName,
                         CString& strData);
    int GetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                         const CString& strNodeName,
                         VARIANT& vData);

    int SetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                         const CString& strNodeName,
                         const CString& strData);
    int SetChildNodeData(const MSXML2::IXMLDOMNodePtr& pParentNode,
                         const CString& strNodeName,
                         const VARIANT& vData);
	
	int DelSingleChildNode(const MSXML2::IXMLDOMNodePtr& pParentNode, MSXML2::IXMLDOMNodePtr& pSingleChildNode);

    MSXML2::IXMLDOMNodePtr CreateRoot(const CString& strRoot);

    MSXML2::IXMLDOMNodePtr QueryRootNode();
    MSXML2::IXMLDOMNodePtr QueryNode(const MSXML2::IXMLDOMNodePtr& pSrcNode,
        const CString& strNodeName);

    int SetXSDFilePath(const CString& strXSDFilePath);

    int Validate();     // validate the xml by schema

    int LoadXML(CString XMLFileName);
	int LoadXMLFromString(CString XMLFileContent);
	int LoadXMLByStream(ATL::CComPtr<IStream> pStream);
	int GetXMLFileContent(CString &XMLFileContent);
	int SaveXML(CString XMLFileName);

private:
    MSXML2::IXMLDOMDocument2Ptr m_pXMLDom;
    BOOL m_bParserInitialized;
    //CString m_strXMLFileName;
    CString m_strXSDFileName;
	CString m_strNamespaceURI;
    BOOL m_bIsComInitializeSuccess;

};

#endif
