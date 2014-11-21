
// BlueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blue.h"
#include "BlueDlg.h"
#include "afxdialogex.h"
#include "resource_ids.h"
#include "Util.h"
#include "AddDlg.h"
#include "SaleAddDlg.h"
#include "colors.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define TM_TIME_COUNT	10

// CBlueDlg dialog


#define NAVIGATE_WIDTH	150
#define RIGHT_AREA_LEFT	(NAVIGATE_WIDTH + 15)

CBlueDlg::CBlueDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlueDlg::IDD, pParent)
	, m_bInit(true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_table.resize(16);
	for (int i = 0; i < m_table.size(); ++i)
	{
		CString csHTH;
		csHTH.Format(_T("000000%02d"), i+1);
		if (i%2 == 0)
		{
			m_table[i].second.push_back(csHTH);
			m_table[i].second.push_back(_T("浙江怡达"));
			m_table[i].second.push_back(_T("U1.0ES-H"));
			m_table[i].second.push_back(_T("1"));
			m_table[i].second.push_back(_T("BNN"));
			m_table[i].second.push_back(_T("是"));
			m_table[i].second.push_back(_T("DC110V"));
			m_table[i].second.push_back(_T("480*6*12*18"));
			m_table[i].second.push_back(_T("无"));
			m_table[i].second.push_back(_T("富士"));
			m_table[i].second.push_back(_T("海1387"));
			m_table[i].second.push_back(_T("8米"));
			m_table[i].second.push_back(_T("5米"));
			m_table[i].second.push_back(_T("蓝光英文铭牌"));
			m_table[i].second.push_back(_T("原点值"));
			m_table[i].second.push_back(_T("2014/08/15"));
		}
		else
		{
			m_table[i].second.push_back(csHTH);
			m_table[i].second.push_back(_T("中原智能"));
			m_table[i].second.push_back(_T("S1.6D-H"));
			m_table[i].second.push_back(_T("1"));
			m_table[i].second.push_back(_T("RC"));
			m_table[i].second.push_back(_T("否"));
			m_table[i].second.push_back(_T("DC220V"));
			m_table[i].second.push_back(_T("325*5*8*12"));
			m_table[i].second.push_back(_T("有"));
			m_table[i].second.push_back(_T("CV"));
			m_table[i].second.push_back(_T("海1387"));
			m_table[i].second.push_back(_T("10米配"));
			m_table[i].second.push_back(_T("5米"));
			m_table[i].second.push_back(_T("蓝光铭牌"));
			m_table[i].second.push_back(_T("D型"));
			m_table[i].second.push_back(_T("2014/11/15"));
		}

	}
}

void CBlueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_WEBVIEW, m_webView);
	DDX_Control(pDX, IDC_EDIT_SEARCH, m_editSearch);
}

BEGIN_MESSAGE_MAP(CBlueDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_SETTINGPAGE, &CBlueDlg::OnBnClickedSetting)
	ON_BN_CLICKED(IDB_BLUE_ADD, &CBlueDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDB_BLUE_MODIFY, &CBlueDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDB_BLUE_DELETE, &CBlueDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDB_BLUE_SEARCH, &CBlueDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDB_BLUE_MORE, &CBlueDlg::OnBnClickedMore)
	ON_MESSAGE_VOID(UM_GRID_COMPLETE, CBlueDlg::OnGridDataLoaded)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()





void CBlueDlg::CreatePageButton(CBRButton& btn, UINT id, int n, LPCTSTR text)
{
	btn.Create(this, id);
	btn.SetTextAlign(DT_VCENTER | DT_SINGLELINE);
	btn.SetWindowText(text);
	btn.SetBSFont(14, FALSE, TRUE);
	btn.EnableBorder(false);
	btn.SetTextColor(enumBSBtnState::BS_NORMAL, COL_BLACK);
	btn.SetTextColor(enumBSBtnState::BS_HOVER, COL_BLACK);
	btn.SetTextColor(enumBSBtnState::BS_CLICK, COL_WHITE);
	btn.SetColorInside(enumBSBtnState::BS_NORMAL, COL_WHITE);
	btn.SetColorInside(enumBSBtnState::BS_HOVER, COL_GRAY);
	btn.SetColorInside(enumBSBtnState::BS_CLICK, COL_DARK_GRAY);
	btn.MoveWindow(CRect(5, 104 + 36 * n, NAVIGATE_WIDTH - 2, 140 + 36 * n));
	m_btnGroup.AddButton(&btn);
}

BOOL CBlueDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(TM_TIME_COUNT, 1000, NULL);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);   // 获得工作区大小
	MoveWindow(rt.left, rt.top, rt.Width(), rt.Height());
	//SetWindowPos(NULL, rt.left, rt.top, rt.Width(), rt.Height(), SW_SHOW);
	//Util::SetWindowSize(m_hWnd, 1024, 728);
	m_btnGroup.d_onSelected += std::make_pair(this, &CBlueDlg::OnGroupBtnSelected);
	m_btnGroup.d_onUnSelected += std::make_pair(this, &CBlueDlg::OnGroupBtnUnSelected);
	CreatePageButton(m_btnSalePage, IDB_SALEPAGE, 0, _T(" 销售订单"));
	CreatePageButton(m_btnPlanPage, IDB_PLANPAGE, 1, _T(" 计划排产"));
	CreatePageButton(m_btnProductionScanPage, IDB_PRODUCTIONSCANPAGE, 2, _T(" 生产录入"));
	CreatePageButton(m_btnNotification, IDB_NOTIFICATION, 3, _T(" 待办事项"));
	CreatePageButton(m_btnProductionDataAnalyst, IDB_PRODUCTIONDATAANALYST, 4, _T(" 报表展示"));
	CreatePageButton(m_btnSettingPage, IDB_SETTINGPAGE, 5, _T(" 设置"));

	m_bsVersion.Create(this, IDS_SOFTWARE_VERSION);
	m_bsVersion.SetBackgroundColor(COL_GRAY);
	m_bsVersion.SetBSFont(_T("Microsoft YaHei"), 24, FALSE, TRUE);
	m_bsVersion.SetTextAlign(DT_LEFT | DT_SINGLELINE);
	m_bsVersion.SetWindowText(_T("蓝光集团生产管控平台"));
	m_bsVersion.MoveWindow(90, 25, 600 - 122, 62 - 33);

	CRect clientRect;
	GetClientRect(clientRect);
	m_bsDate.Create(this, IDS_DATA_DATE);
	m_bsDate.SetBackgroundColor(COL_GRAY);
	m_bsDate.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsDate.SetTextAlign(DT_VCENTER | DT_SINGLELINE | DT_RIGHT | DT_WORD_ELLIPSIS);
	m_bsDate.MoveWindow(clientRect.right - 210, 31, 200, 20);

	m_bsPersion.Create(this, IDS_PERSION_INFO);
	m_bsPersion.SetBackgroundColor(COL_GRAY);
	m_bsPersion.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsPersion.SetWindowText(_T("用户名: Admin    角色: 管理员    部门: 蓝光集团"));
	m_bsPersion.SetTextAlign(DT_VCENTER | DT_SINGLELINE | DT_RIGHT | DT_WORD_ELLIPSIS);
	m_bsPersion.MoveWindow(clientRect.right - 400, 59, 390, 20);

	m_bsIcon.Create(this, IDS_EP_LOGO);
	m_bsIcon.SetBGPictureIDs(BS_NORMAL, IDB_LOGO);
	m_bsIcon.MoveWindow(12, 10, 64, 64);

	int delta = 277 - (RIGHT_AREA_LEFT + 15);

	m_editSearch.MoveWindow(493 - delta, 130, 240, 20);

	m_btnAdd.Create(this, IDB_BLUE_ADD);
	m_btnAdd.SetWindowText(_T("添加"));
	m_btnAdd.SetBSFont(12);
	m_btnAdd.MoveWindow(277 - delta, 128, 90, 25);

	m_btnDelete.Create(this, IDB_BLUE_DELETE);
	m_btnDelete.SetWindowText(_T("删除"));
	m_btnDelete.MoveWindow(383 - delta, 172, 90, 25);

	m_btnModify.Create(this, IDB_BLUE_MODIFY);
	m_btnModify.SetWindowText(_T("修改"));
	m_btnModify.MoveWindow(278 - delta, 172, 90, 25);

	m_btnSearch.Create(this, IDB_BLUE_SEARCH);
	m_btnSearch.SetWindowText(_T("查询"));
	m_btnSearch.MoveWindow(383 - delta, 128, 90, 25);

	m_btnMore.Create(this, IDB_BLUE_MORE);
	m_btnMore.SetWindowText(_T(">"));
	m_btnMore.MoveWindow(826 - delta, 128, 30, 25);

	m_bsMoreWord.Create(this, IDB_BLUE_MOREWORD);
	m_bsMoreWord.SetWindowText(_T("更多筛选"));
	m_bsMoreWord.SetBSFont(_T("Microsoft YaHei"), 12);
	m_bsMoreWord.MoveWindow(CRect(739 - delta, 128, 823 - delta, 151));

	m_pJqGridAPI.reset(new CJQGridAPI(static_cast<IJSMediator*>(&m_webView)));
	m_pJqGridAPI->d_OnRowChecked += std::make_pair(this, &CBlueDlg::OnRowChecked);
	m_pJqGridAPI->d_OnGridComplete += std::make_pair(this, &CBlueDlg::OnGridComplete);

	GetClientRect(rt);
	rt.left = RIGHT_AREA_LEFT;
	rt.top = 237;
	rt.right -= 10;
	rt.bottom -= 10;
	m_webView.Create(NULL, NULL, WS_CHILD, rt, this, 10000, NULL);
	m_webView.ShowWindow(SW_SHOW);

	CString path;
	GetModuleFileName(AfxGetInstanceHandle(), path.GetBuffer(MAX_PATH), MAX_PATH);
	path.ReleaseBuffer();
#ifdef _DEBUG
	path.Replace(_T("Debug\\BlueLightPLM.exe"), _T("BlueTable\\sale.html"));
#else
	path.Replace(_T("BlueLightPLM.exe"), _T("sale.html"));
#endif
	VARIANT url;
	url.vt = VT_BSTR;
	url.bstrVal = (BSTR)::SysAllocString(path);
	m_webView.OpenURL(&url);


	m_btnDelete.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	m_btnGroup.OnClicked(&m_btnSalePage);
	OnTimer(TM_TIME_COUNT);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBlueDlg::OnPaint()
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
HCURSOR CBlueDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBlueDlg::OnBnClickedSetting()
{

}


BOOL CBlueDlg::OnEraseBkgnd(CDC* pDC)
{

	// TODO: Add your message handler code here and/or call default
	BOOL ret = __super::OnEraseBkgnd(pDC);
	CRect rtClient;
	GetClientRect(rtClient);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 84, rtClient.Width(), rtClient.Height()), COL_WHITE);
	CBSObject::FillRect(pDC->m_hDC, CRect(0, 0, rtClient.Width(), 84), COL_GRAY);
	CBSObject::DrawRect(pDC->m_hDC, CRect(RIGHT_AREA_LEFT, 102, rtClient.Width() - 10, 218), COL_BLACK, 2);
	CBSObject::DrawRect(pDC->m_hDC, CRect(3, 102, NAVIGATE_WIDTH, rtClient.Height() - 10), COL_GRAY, 2);
	CBSObject::DrawLine(pDC->m_hDC, CPoint(-1, 84), CPoint(rtClient.Width(), 84), COL_BLACK, 2);
	return ret;
}


int CBlueDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->dwExStyle |= WS_CLIPCHILDREN;
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void CBlueDlg::OnBnClickedAdd()
{
	CSaleAddDlg dlg(_T("添加"));
	if (IDOK == dlg.DoModal()){
		m_table.push_back(std::make_pair(
			m_pJqGridAPI->AddRow(dlg.GetResult()),
			dlg.GetResult()));
	}

}

void CBlueDlg::OnBnClickedModify()
{
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt;
	CSaleAddDlg dlg(_T("修改"));
	std::vector<int> checkedRows;
	std::vector<CString>* pRowData = NULL;
	m_pJqGridAPI->GetCheckedRows(checkedRows);

	std::vector<int> checkedRowTableMap;
	checkedRowTableMap.resize(checkedRows.size(), -1);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		pRowData = NULL;
		for (int j = 0; i < m_table.size(); ++j)
		{
			if (m_table[j].first == checkedRows[i])
			{
				checkedRowTableMap[i] = j;
				pRowData = &(m_table[j].second);
				break;
			}
		}

		if (NULL != pRowData)
		{
			if (pstOpt.get() == NULL)
			{
				pstOpt.reset(new CSaleAddDlg::Option_t(*pRowData));
			}
			else
			{
				pstOpt->Merge(*pRowData);
			}
		}
	}
	dlg.SetOption(pstOpt.get());
	if (IDOK == dlg.DoModal()){
		const std::vector<CString>& result = dlg.GetResult();
		for (int j = result.size() - 1; j >= 0; --j)
		{
			if (!result[j].IsEmpty())
			{
				for (int i = checkedRows.size() - 1; i >= 0; --i)
				{
					if (checkedRowTableMap[i] >= 0)
					{
						m_table[checkedRowTableMap[i]].second[j] = result[j];
					}
					m_pJqGridAPI->SetCell(checkedRows[i], j + 1, result[j]);
				}
			}
		}
	}
}

void CBlueDlg::OnBnClickedDelete()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	for (int i = checkedRows.size() - 1; i >= 0; --i)
	{
		m_pJqGridAPI->DelRow(checkedRows[i]);
	}

	for (int i = m_table.size() - 1; i >= 0; --i)
	{
		for (int j = checkedRows.size() - 1; j >= 0; --j)
		{
			if (m_table[i].first == checkedRows[j]){
				m_table.erase(m_table.begin() + i);
				break;
			}
		}
	}

	OnRowChecked();
}

void CBlueDlg::OnRowChecked()
{
	std::vector<int> checkedRows;
	m_pJqGridAPI->GetCheckedRows(checkedRows);
	if (checkedRows.empty())
	{
		m_btnDelete.EnableWindow(FALSE);
		m_btnModify.EnableWindow(FALSE);
	}
	else{
		m_btnDelete.EnableWindow(TRUE);
		m_btnModify.EnableWindow(TRUE);
	}
}

void CBlueDlg::OnBnClickedSearch()
{
	CString searchText;
	m_editSearch.GetWindowText(searchText);
	CString rowData;
	bool bMatch = false;
	for (int i = 0; i < m_table.size(); ++i)
	{
		bMatch = false;
		for (int j = 0; j < m_table[i].second.size(); ++j)
		{
			if (searchText.IsEmpty() || m_table[i].second[j].Find(searchText) >= 0)
			{
				bMatch = true;
				break;
			}
		}
		if (!bMatch)
		{
			m_pJqGridAPI->HideRow(m_table[i].first);
		}
		else
		{
			m_pJqGridAPI->ShowRow(m_table[i].first);
		}
	}
}

void CBlueDlg::OnGridComplete()
{
	if (m_bInit)
	{
		m_bInit = false;
		for (int j = 0; j < m_table.size(); ++j)
		{
			m_table[j].first = m_pJqGridAPI->AddRow(m_table[j].second);
		}
		PostMessage(UM_GRID_COMPLETE);
	}
}

void CBlueDlg::OnBnClickedMore()
{
	CSaleAddDlg dlg(_T("高级搜索"));
	std::auto_ptr<CSaleAddDlg::Option_t> pstOpt(new CSaleAddDlg::Option_t());
	dlg.SetOption(pstOpt.get());
	if (IDOK == dlg.DoModal()){
		const std::vector<CString>& searchVals = dlg.GetResult();
		bool bMatch = true;
		for (int i = 0; i < m_table.size(); ++i)
		{
			bMatch = true;
			for (int j = 0; j < searchVals.size(); ++j)
			{
				if (!searchVals[j].IsEmpty() && m_table[i].second[j].Compare(searchVals[j]) != 0)
				{
					bMatch = false;
					break;
				}
			}

			if (!bMatch)
			{
				m_pJqGridAPI->HideRow(m_table[i].first);
			}
			else
			{
				m_pJqGridAPI->ShowRow(m_table[i].first);
			}
		}
	}
}


BOOL CBlueDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	if (nCode == BN_CLICKED)
	{
		m_btnGroup.OnClicked(static_cast<CBRButton*>(GetDlgItem(nID)));
	}
	return CDialogEx::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CBlueDlg::OnGroupBtnSelected(CBRButton* pBrbtn)
{
	if (NULL != pBrbtn)
	{
		pBrbtn->SetColorInside(enumBSBtnState::BS_NORMAL, COL_LIGHT_GRAY);
		CString text;
		pBrbtn->GetWindowText(text);
		pBrbtn->SetWindowText(text + _T(">>"));
	}
}

void CBlueDlg::OnGroupBtnUnSelected(CBRButton* pBrbtn)
{
	if (NULL != pBrbtn)
	{
		pBrbtn->SetColorInside(enumBSBtnState::BS_NORMAL, COL_WHITE);
		CString text;
		pBrbtn->GetWindowText(text);
		text.Replace(_T(">>"), _T(""));
		pBrbtn->SetWindowText(text);
	}
}


void CBlueDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (TM_TIME_COUNT == nIDEvent)
	{
		CTime now = CTime::GetCurrentTime();
		CString time = now.Format(_T("%Y/%m/%d %X"));

		m_bsDate.SetWindowText(_T("当前时间: ") + time);
	}
	else
	{
		CDialogEx::OnTimer(nIDEvent);
	}
}


BOOL CBlueDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CBlueDlg::OnGridDataLoaded()
{
	//m_pJqGridAPI->Refresh();
}
