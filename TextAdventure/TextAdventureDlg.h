
// TextAdventureDlg.h: Headerdatei
//
#pragma once
#include "ConsoleCtrl.h"


// CTextAdventureDlg-Dialogfeld

class CTextAdventureDlg : public CDialogEx
{
// Konstruktion
public:
	CTextAdventureDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXTADVENTURE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CConsoleCtrl m_ctrlConsole;
	CScrollBar m_ctrlScrollBarConsole;
};
