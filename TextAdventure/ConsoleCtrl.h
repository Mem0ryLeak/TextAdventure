#pragma once
#include <memory>


class CConsoleCtrl : public CStatic
{

	// Konstruktion
public:
	CConsoleCtrl();
	virtual ~CConsoleCtrl();

	// Operationen
public:
	void ClearConsole();

	// Überschreibungen
protected:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

	// Implementierung
	class Impl;
	std::unique_ptr<Impl> m_pImpl;


};

