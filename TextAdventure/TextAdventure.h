
// TextAdventure.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CTextAdventureApp:
// Siehe TextAdventure.cpp für die Implementierung dieser Klasse
//

class CTextAdventureApp : public CWinApp
{
public:
	CTextAdventureApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CTextAdventureApp theApp;
