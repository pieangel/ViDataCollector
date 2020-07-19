
// ViDataCollector.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CViDataCollectorApp:
// See ViDataCollector.cpp for the implementation of this class
//

class CViDataCollectorApp : public CWinApp
{
public:
	CViDataCollectorApp();
public:
	int RegisterOCX(CString strFileName);

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CViDataCollectorApp theApp;
