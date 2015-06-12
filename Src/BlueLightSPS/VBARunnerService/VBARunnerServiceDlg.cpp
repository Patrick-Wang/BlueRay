
// VBARunnerServiceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VBARunnerService.h"
#include "VBARunnerServiceDlg.h"
#include "afxdialogex.h"
#include "ExcelVBAService.h"
#include "JsonFactory.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_VBA_SERVICE_START	(WM_APP + 15982) 
#define WM_VBA_SERVICE_STOP		(WM_APP + 15983)
#define WM_HANDLE_MAP		(WM_APP + 15984)
// CVBARunnerServiceDlg dialog



CVBARunnerServiceDlg::CVBARunnerServiceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVBARunnerServiceDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVBARunnerServiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVBARunnerServiceDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_COPYDATA()
END_MESSAGE_MAP()


// CVBARunnerServiceDlg message handlers

BOOL CVBARunnerServiceDlg::OnInitDialog()
{
	SetWindowText(L"VBARunnerService");
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	MoveWindow(0, 0, 0, 0, 0);
	// TODO: Add extra initialization here
	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVBARunnerServiceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVBARunnerServiceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void JsonArray2Vector(Json::JsonArray& ja, std::vector<int>& vec){
	for (size_t i = 0; i < ja.size(); i++)
	{
		vec.push_back(ja.asInt(i));
	}
}

BOOL CVBARunnerServiceDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	if (pCopyDataStruct != NULL)
	{
		LPCTSTR pszText = (LPCTSTR)(pCopyDataStruct->lpData);
		DWORD dwLength = (DWORD)(pCopyDataStruct->cbData);
		LPTSTR szRecvText = new TCHAR[dwLength / 2 + 1];
		SecureZeroMemory(szRecvText, dwLength + 2);
		memcpy(szRecvText, pszText, dwLength);
		CString data = szRecvText;
		delete[] szRecvText;
		int index = data.ReverseFind(L'#');
		CString id = data.Right(data.GetLength() - index - 1);
		HANDLE h = CreateEvent(NULL, TRUE, FALSE, id);
		ResetEvent(h);
		m_handlMap[h] = data.Left(index);
		PostMessage(WM_HANDLE_MAP);
	}

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}


LRESULT CVBARunnerServiceDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_VBA_SERVICE_START:
		//ExcelVBAService::Start();
		break;
	case WM_VBA_SERVICE_STOP:
		//ExcelVBAService::Stop();
		break;
	case WM_HANDLE_MAP:
	{
		for (std::map<HANDLE, CString>::iterator it = m_handlMap.begin(); it != m_handlMap.end(); ++it)
		{
			Json::JsonParser parser;
			std::shared_ptr<Json::JsonObject> jo((Json::JsonObject*)parser.Parse((LPTSTR)(LPCTSTR)it->second));
			CString path = jo->asString(L"path").c_str();
			Json::JsonArray& cells(jo->asArray(L"cells"));
			std::vector<int> sheets;
			std::vector<int> rows;
			std::vector<int> cols;
			JsonArray2Vector(cells.asArray(0), sheets);
			JsonArray2Vector(cells.asArray(1), rows);
			JsonArray2Vector(cells.asArray(2), cols);
			ExcelVBAService::updateCell(path, sheets, rows, cols);
			SetEvent(it->first);
			CloseHandle(it->first);
		}
		m_handlMap.clear();
	
	}
		break;
	default:
		break;
	}

	return CDialogEx::WindowProc(message, wParam, lParam);
}
