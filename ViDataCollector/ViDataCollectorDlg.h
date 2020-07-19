
// ViDataCollectorDlg.h : header file
//

#pragma once

#include <string>
#include <memory>
#define REQ_TIMER 100
class VtProgressDlg;

// CViDataCollectorDlg dialog
class CViDataCollectorDlg : public CDialogEx
{
// Construction
public:
	CViDataCollectorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIDATACOLLECTOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void ClearAllResources();
	// 로그인 후에 필요한 과정들을 수행한다.
	void StartProcess();
	void StartTimer(int milisecond);
	void StopTimer();
	void HideProgress();

private:
	bool _Init = false;

	void ReadConfig();
	std::string _FleWathPath;
	bool _EnableFileWatch = false;
	std::shared_ptr<VtProgressDlg> ProgressDlg = nullptr;
public:
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
