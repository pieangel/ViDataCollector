
// ViDataCollectorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ViDataCollector.h"
#include "ViDataCollectorDlg.h"
#include "afxdialogex.h"

#include "Login/VtLogInDlg.h"
#include "Archieve/VtSaveManager.h"
#include "Login/VtLoginManager.h"
#include "Config/ZmConfigManager.h"
#include "Global/VtGlobal.h"
#include "Symbol/SmMarketManager.h"
#include "Symbol/SmSymbolReader.h"
//#include "Account/VtAccountManager.h"
//#include "Account/VtAccountPasswordDlg.h"
//#include "Fund/VtFundManager.h"
//#include "Account/VtSubAccountManager.h"
#include "Task/VtProgressDlg.h"
#include "Symbol/SmSymbolManager.h"
//#include "Task/HdScheduler.h"
//#include "OrderUI/VtOrderWndHd.h"
//#include "Order/VtTotalOrderManager.h"
//#include "Order/VtFundOrderManagerSelecter.h"
//#include "Order/VtOrderManagerSelector.h"
#include "Symbol/VtRealtimeRegisterManager.h"
#include "Task/SmCallbackManager.h"
#include "Util/SmUtil.h"
#include "HdCtrl/HdClient.h"
#include "Symbol/SmSymbolReader.h"
#include "Task/ViServerDataReceiver.h"
#include "Chart/SmChartDataManager.h"
//#include "OrderUI/VtOrderWnd.h"
#include "Task/SmRealtimeHogaManager.h"
#include "Task/SmRealtimeQuoteManager.h"
#include "Symbol/SmSymbolManager.h"
#include "Database/SmMongoDBManager.h"
#include "Network/SmSessionManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CViDataCollectorDlg dialog



CViDataCollectorDlg::CViDataCollectorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIDATACOLLECTOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CViDataCollectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CViDataCollectorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CViDataCollectorDlg message handlers

BOOL CViDataCollectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//SmMongoDBManager::GetInstance();

	VtLogInDlg loginDlg(this);
	if (loginDlg.DoModal() == IDCANCEL)
	{
		ClearAllResources();
		DestroyWindow();
		return TRUE;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CViDataCollectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CViDataCollectorDlg::OnPaint()
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
HCURSOR CViDataCollectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CViDataCollectorDlg::ClearAllResources()
{
	// 증권사 이벤트를 막는다.
	HdClient::GetInstance()->Enable(false);
	// 시세 수집과 호가 수집을 멈춘다.
	SmRealtimeHogaManager::GetInstance()->Enable(false);
	SmRealtimeQuoteManager::GetInstance()->Enable(false);

	SmSessionManager::DestroyInstance();
	SmMongoDBManager::DestroyInstance();
	SmSymbolManager::DestroyInstance();
	SmRealtimeHogaManager::DestroyInstance();
	SmRealtimeQuoteManager::DestroyInstance();
	SmChartDataManager::DestroyInstance();
	ViServerDataReceiver::DestroyInstance();
	HdClient::DestroyInstance();
	SmCallbackManager::DestroyInstance();
	VtRealtimeRegisterManager::DestroyInstance();
	//VtTotalOrderManager::DestroyInstance();
	//VtOrderManagerSelector::DestroyInstance();
	//VtFundOrderManagerSelecter::DestroyInstance();

	//HdScheduler::DestroyInstance();
	//SmSymbolManager::DestroyInstance();
	//EbClient::DestroyInstance();
	VtSaveManager::DestroyInstance();
	VtLoginManager::DestroyInstance();
	SmSymbolReader::DestroyInstance();
	SmMarketManager::DestroyInstance();
	ZmConfigManager::DestroyInstance();
	//VtAccountManager::DestroyInstance();
	//VtFundManager::DestroyInstance();
	VtGlobal::DestroyInstance();
	//VtSubAccountManager::DestroyInstance();
	//SmServerDataReceiver::DestroyInstance();
}

void CViDataCollectorDlg::StartProcess()
{
	SmSymbolReader* symbol_reader = SmSymbolReader::GetInstance();
	symbol_reader->ReadMarketFile();
	symbol_reader->ReadPmFile();
	symbol_reader->ReadJmFile();

	// 서버 데이터 가져오기를 표시하는 대화 상자를 생성한다.
	ProgressDlg = std::make_shared<VtProgressDlg>();
	ProgressDlg->Create(IDD_PROGRESS, this);
	ProgressDlg->MainFrm = this;
	ProgressDlg->ShowWindow(SW_SHOW);
	ProgressDlg->SetForegroundWindow();
	ProgressDlg->BringWindowToTop();

	// 파일에서 국내 선물/옵션 상품 정보를 읽어 온다.
	//client->LoadProductInfo();


	ViServerDataReceiver* rcvr = ViServerDataReceiver::GetInstance();
	// 진행상황 표시 대화상자를 할당해 준다.
	rcvr->ProgressDlg(ProgressDlg);
	// 심볼 코드를 가져오기 시작한다.
	rcvr->StartGetDmSymbolCode();
}

void CViDataCollectorDlg::StartTimer(int milisecond)
{
	SetTimer(REQ_TIMER, milisecond, NULL);
}

void CViDataCollectorDlg::StopTimer()
{
	KillTimer(REQ_TIMER);
}

void CViDataCollectorDlg::HideProgress()
{
	if (ProgressDlg) {
		ProgressDlg->ShowWindow(SW_HIDE);
		ProgressDlg->DestroyWindow();
	}

	SmSymbolManager::GetInstance()->StartCollectData();
}

void CViDataCollectorDlg::ReadConfig()
{

}



void CViDataCollectorDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	ClearAllResources();
	CDialogEx::OnClose();
}


void CViDataCollectorDlg::OnTimer(UINT_PTR nIDEvent)
{
	ViServerDataReceiver* datRcvr = ViServerDataReceiver::GetInstance();
	datRcvr->ExecNext();

	CDialogEx::OnTimer(nIDEvent);
}
