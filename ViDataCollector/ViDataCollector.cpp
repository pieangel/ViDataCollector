
// ViDataCollector.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "ViDataCollector.h"
#include "ViDataCollectorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CViDataCollectorApp

BEGIN_MESSAGE_MAP(CViDataCollectorApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CViDataCollectorApp construction

CViDataCollectorApp::CViDataCollectorApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


int CViDataCollectorApp::RegisterOCX(CString strFileName)
{
#ifdef LOGGING
	CommsDbgLog(0, "RegisterOCX() - start");
#endif
	int			iReturn = 1;
	CString		szErrorMsg;

	strFileName.Replace("'\'", "\\");
	// Initialize OLE.
	if (FAILED(OleInitialize(NULL))) {
		AfxMessageBox("DLLRegister OleInitialize 실패");
		return 1;
	}

	SetErrorMode(SEM_FAILCRITICALERRORS);       // Make sure LoadLib fails.
												// Load the library.
	HINSTANCE hLib = LoadLibraryEx(strFileName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (hLib == NULL) {
		szErrorMsg.Format("File Name=%s, GetLastError() NO = 0x%08lx\n", strFileName, GetLastError());
		AfxMessageBox(szErrorMsg);
		iReturn = 0;
		goto CleanupOle;
	}

	HRESULT(STDAPICALLTYPE * lpDllEntryPoint)(void);
	// Find the entry point.
	(FARPROC&)lpDllEntryPoint = GetProcAddress(hLib, "DllRegisterServer");
	if (lpDllEntryPoint == NULL) {
		// 		TCHAR szExt[_MAX_EXT];
		// 		_tsplitpath(strFileName, NULL, NULL, NULL, szExt);

		TCHAR drive[255];
		TCHAR szExt[255];
		TCHAR path[MAX_PATH];
		TCHAR filename[MAX_PATH];
		_tsplitpath_s((LPTSTR)(LPCTSTR)strFileName, drive, _countof(drive), path, _countof(path), filename, _countof(filename), szExt, _countof(szExt));

		if ((_stricmp(szExt, ".dll") != 0) && (_stricmp(szExt, ".ocx") != 0)) {
			szErrorMsg.Format("File Name=%s, GetProcAddress Fail\n", strFileName);
			AfxMessageBox(szErrorMsg);
		}

		iReturn = 0;
		goto CleanupLibrary;
	}

	// Call the entry point.
	if (FAILED((*lpDllEntryPoint)())) {
		szErrorMsg.Format("File Name=%s, lpDllEntryPoint Fail\n", strFileName);
		AfxMessageBox(szErrorMsg);
		iReturn = 0;
		goto CleanupLibrary;
	}
	return iReturn;

CleanupLibrary:
	FreeLibrary(hLib);

CleanupOle:
	OleUninitialize();

#ifdef LOGGING
	CommsDbgLog(0, "RegisterOCX() - end");
#endif

	return iReturn;
}

// The one and only CViDataCollectorApp object

CViDataCollectorApp theApp;


// CViDataCollectorApp initialization

BOOL CViDataCollectorApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	// 챠트 OCX 파일 등록 처리
	TCHAR iniFileName[500] = { 0 };

	GetModuleFileName(NULL, iniFileName, MAX_PATH);
	CString path = iniFileName;
	CString fileName = path.Left(path.ReverseFind('\\') + 1);
	fileName = fileName += "HDFCommAgent.ocx";
	RegisterOCX(fileName);

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CViDataCollectorDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

