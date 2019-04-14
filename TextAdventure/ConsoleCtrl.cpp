#include "pch.h"
#include "ConsoleCtrl.h"
#include <gdiplus.h>

static const Gdiplus::Color COLOR_BLACK = Gdiplus::Color(255, 0, 0, 0);
static const Gdiplus::Color COLOR_TEXT = Gdiplus::Color(192, 192, 192);

static const  TCHAR consoleFontName[LF_FACESIZE] = { _T("Consola\0") };

BEGIN_MESSAGE_MAP(CConsoleCtrl, CStatic)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


class CConsoleCtrl::Impl
{

	// Operationen
public:
	void Init();

	// Attribute
public:
	BOOL m_isConsoleInitialized;
	ULONG_PTR m_tokenGdiplus;
	CDC* m_onScreenDeviceContext;
	LOGFONTW defaultFont;
};

void CConsoleCtrl::Impl::Init()
{
	m_isConsoleInitialized = FALSE;
	m_tokenGdiplus = NULL;
	m_onScreenDeviceContext = nullptr;

	// Init Font

}


CConsoleCtrl::CConsoleCtrl() : m_pImpl(new Impl)
{
	m_pImpl->Init();

	// Init GDI+ session
	Gdiplus::GdiplusStartupInput startupInput;
	Gdiplus::GdiplusStartup(&m_pImpl->m_tokenGdiplus, &startupInput, NULL);
}

CConsoleCtrl::~CConsoleCtrl()
{
	// Shutdown GDI+ session
	Gdiplus::GdiplusShutdown(m_pImpl->m_tokenGdiplus);
}

void CConsoleCtrl::OnPaint()
{
	CWnd::OnPaint();

	CRect rectClient = {};
	rectClient.NormalizeRect();
	GetClientRect(&rectClient);

	// Inhalte des OnDeviceContexts werden direkt "in den Bildschirminhalt" gezeichnet.
	m_pImpl->m_onScreenDeviceContext = GetDC();

	if (m_pImpl->m_isConsoleInitialized == FALSE)
	{
		ClearConsole();
		m_pImpl->m_isConsoleInitialized = TRUE;
	}

	// Zeichnen der Kreuznummerierung
	Gdiplus::Graphics graphicContext(m_pImpl->m_onScreenDeviceContext->m_hDC);
	CString str = _T("Microsoft");
	Gdiplus::SolidBrush textBrush(COLOR_TEXT);

	LOGFONTW logFont = {};
	logFont.lfHeight = 24;
	logFont.lfWidth = 11;
	logFont.lfWeight = 400;
	logFont.lfQuality = 5;
	memcpy_s(logFont.lfFaceName, LF_FACESIZE, consoleFontName, LF_FACESIZE);
	Gdiplus::Font titleFont(m_pImpl->m_onScreenDeviceContext->m_hDC, &logFont);

	Gdiplus::RectF layoutRect(0, 0, 500, 500);
	Gdiplus::StringFormat textAlignment;
	textAlignment.SetAlignment(Gdiplus::StringAlignmentNear);
	graphicContext.DrawString(str.GetBuffer(), str.GetLength(), &titleFont, layoutRect, &textAlignment, &textBrush);

	ReleaseDC(m_pImpl->m_onScreenDeviceContext);
}

void CConsoleCtrl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
}

void CConsoleCtrl::ClearConsole()
{
	Gdiplus::SolidBrush backgroundBrush(COLOR_BLACK);
	Gdiplus::Graphics graphicContext(m_pImpl->m_onScreenDeviceContext->m_hDC);

	CRect clientRect;
	GetClientRect(&clientRect);

	graphicContext.FillRectangle(&backgroundBrush, 0, 0, clientRect.Width(), clientRect.Height());
}