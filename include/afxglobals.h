// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once

#include "afxwin.h"
#include "afxcontrolbarutil.h"

#include "afxaccessibility.h"
#include <oleacc.h>

#if (NTDDI_VERSION >= NTDDI_WIN7)
#include <shobjidl.h>
#endif

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

/////////////////////////////////////////////////////////////////////////////
// Auxiliary System/Screen metrics

typedef enum AFX_DOCK_TYPE
{
	DT_UNDEFINED = 0,    // inherit from application
	DT_IMMEDIATE = 1,    // control bar torn off immediately and follows the mouse
	DT_STANDARD  = 2,    // user drags a frame
	DT_SMART     = 0x80  // smart docking style
};

// autohide sliding modes
static const UINT AFX_AHSM_MOVE    = 1;
static const UINT AFX_AHSM_STRETCH = 2;

#define AFX_AUTOHIDE_LEFT   0x0001
#define AFX_AUTOHIDE_RIGHT  0x0002
#define AFX_AUTOHIDE_TOP    0x0004
#define AFX_AUTOHIDE_BOTTOM 0x0008

typedef HANDLE AFX_HPAINTBUFFER;  // handle to a buffered paint context

typedef HRESULT (__stdcall * DRAWTHEMEPARENTBACKGROUND)(HWND hWnd, HDC hdc,const RECT *pRec);

typedef enum _AFX_BP_BUFFERFORMAT
{
	AFX_BPBF_COMPATIBLEBITMAP,    // Compatible bitmap
	AFX_BPBF_DIB,                 // Device-independent bitmap
	AFX_BPBF_TOPDOWNDIB,          // Top-down device-independent bitmap
	AFX_BPBF_TOPDOWNMONODIB       // Top-down monochrome device-independent bitmap
} AFX_BP_BUFFERFORMAT;

typedef struct _AFX_BP_PAINTPARAMS
{
	DWORD                       cbSize;
	DWORD                       dwFlags; // BPPF_ flags
	const RECT *                prcExclude;
	const BLENDFUNCTION *       pBlendFunction;
} AFX_BP_PAINTPARAMS;

typedef HRESULT (__stdcall * BUFFEREDPAINTINIT)(VOID);
typedef HRESULT (__stdcall * BUFFEREDPAINTUNINIT)(VOID);
typedef AFX_HPAINTBUFFER (__stdcall * BEGINBUFFEREDPAINT)(HDC hdcTarget, const RECT* rcTarget, AFX_BP_BUFFERFORMAT dwFormat, AFX_BP_PAINTPARAMS *pPaintParams, HDC *phdc);
typedef HRESULT (__stdcall * ENDBUFFEREDPAINT)(AFX_HPAINTBUFFER hBufferedPaint, BOOL fUpdateTarget);

typedef struct _AFX_MARGINS {
	int cxLeftWidth;
	int cxRightWidth;
	int cyTopHeight;
	int cyBottomHeight;
} AFX_MARGINS;

typedef HRESULT (__stdcall * DWMEXTENDFRAMEINTOCLIENTAREA)(HWND hWnd, const AFX_MARGINS* pMargins);
typedef HRESULT (__stdcall * DWMDEFWINDOWPROC)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT *plResult);
typedef HRESULT (__stdcall * DWMISCOMPOSITIONENABLED)(BOOL* pfEnabled);

typedef int (WINAPI *AFX_DTT_CALLBACK_PROC)(HDC hdc, LPWSTR pszText, int cchText, LPRECT prc, UINT dwFlags, LPARAM lParam);

typedef struct _AFX_DTTOPTS {
	DWORD dwSize;
	DWORD dwFlags;
	COLORREF crText;
	COLORREF crBorder;
	COLORREF crShadow;
	int iTextShadowType;
	POINT ptShadowOffset;
	int nBorderSize;
	int iFontPropId;
	int iColorPropId;
	int iStateId;
	BOOL fApplyOverlay;
	int iGlowSize;
	AFX_DTT_CALLBACK_PROC pfnDrawTextCallback;
	LPARAM lParam;
} AFX_DTTOPTS;

typedef HRESULT (__stdcall * DRAWTHEMETEXTEX)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCWSTR pszText, int iCharCount, DWORD dwFlags, LPRECT pRect, const AFX_DTTOPTS *pOptions);

typedef HRESULT (WINAPI * D2D1MAKEROTATEMATRIX)(FLOAT angle, D2D1_POINT_2F center, D2D1_MATRIX_3X2_F *matrix);

class CMFCToolBarImages;

struct AFX_GLOBAL_DATA
{
	friend class CMemDC;

	BOOL m_bUseSystemFont;	// Use system font for menu/toolbar/ribbons
	BOOL m_bInSettingChange;

	// solid brushes with convenient gray colors and system colors
	HBRUSH hbrBtnHilite, hbrBtnShadow;
	HBRUSH hbrWindow;

	// color values of system colors used for CToolBar
	COLORREF clrBtnFace, clrBtnShadow, clrBtnHilite;
	COLORREF clrBtnText, clrWindowFrame;
	COLORREF clrBtnDkShadow, clrBtnLight;
	COLORREF clrGrayedText;
	COLORREF clrHilite;
	COLORREF clrTextHilite;
	COLORREF clrHotLinkNormalText;
	COLORREF clrHotLinkHoveredText;
	COLORREF clrHotLinkVisitedText;

	COLORREF clrBarWindow;
	COLORREF clrBarFace;
	COLORREF clrBarShadow, clrBarHilite;
	COLORREF clrBarDkShadow, clrBarLight;
	COLORREF clrBarText;

	COLORREF clrWindow;
	COLORREF clrWindowText;

	COLORREF clrCaptionText;
	COLORREF clrMenuText;
	COLORREF clrActiveCaption;
	COLORREF clrInactiveCaption;
	COLORREF clrInactiveCaptionText;
	///<summary>
	/// Specifies gradient color of active caption. Generally used for docking panes. </summary>
	COLORREF clrActiveCaptionGradient;
	///<summary>
	/// Specifies gradient color of inactive active caption. Generally used for docking panes. </summary>
	COLORREF clrInactiveCaptionGradient;

	COLORREF clrActiveBorder;
	COLORREF clrInactiveBorder;

	CBrush brBtnFace;
	CBrush brHilite;
	CBrush brLight;
	CBrush brBlack;
	CBrush brActiveCaption;
	CBrush brInactiveCaption;
	CBrush brWindow;

	CBrush brBarFace;

	CPen penHilite;
	CPen penBarFace;
	CPen penBarShadow;

	// Library cursors:
	HCURSOR m_hcurStretch;
	HCURSOR m_hcurStretchVert;
	HCURSOR m_hcurHand;
	HCURSOR m_hcurSizeAll;
	HCURSOR m_hcurMoveTab;
	HCURSOR m_hcurNoMoveTab;

	HCURSOR GetHandCursor();

	HICON m_hiconTool;
	HICON m_hiconLink;
	HICON m_hiconColors;

	// Shell icon sizes:
	CSize m_sizeSmallIcon;

	// Toolbar and menu fonts:
	CFont fontRegular;
	CFont fontTooltip;
	CFont fontBold;
	CFont fontDefaultGUIBold;
	CFont fontUnderline;
	CFont fontDefaultGUIUnderline;
	CFont fontVert;
	CFont fontVertCaption;
	CFont fontSmall;
	CFont fontMarlett;	// Standard Windows menu symbols
	CRect m_rectVirtual;

	BOOL  bIsWindowsVista;
	///<summary>
	/// Indicates whether the application is being executed under Windows 7 OS or higher</summary>
	BOOL  bIsWindows7;
	BOOL  bDisableAero;
	BOOL  bIsRemoteSession;

	BOOL  m_bIsBlackHighContrast;
	BOOL  m_bIsWhiteHighContrast;
	BOOL  m_bUseBuiltIn32BitIcons;
	BOOL  m_bMenuAnimation;
	BOOL  m_bMenuFadeEffect;
	BOOL  m_bIsRTL;
	BOOL  m_bEnableAccessibility;

	BOOL m_bUnderlineKeyboardShortcuts;
	BOOL m_bSysUnderlineKeyboardShortcuts;

	BOOL m_bRefreshAutohideBars;

	int   m_nBitsPerPixel;
	int   m_nDragFrameThicknessFloat;
	int   m_nDragFrameThicknessDock;
	int   m_nAutoHideToolBarSpacing;
	int   m_nAutoHideToolBarMargin;
	int   m_nCoveredMainWndClientAreaPercent;
	int   m_nMaxToolTipWidth;
	int   m_nShellAutohideBars;

// Implementation
	AFX_GLOBAL_DATA();
	~AFX_GLOBAL_DATA();

	void UpdateSysColors();
	void UpdateFonts();
	void OnSettingChange();

	BOOL SetMenuFont(LPLOGFONT lpLogFont, BOOL bHorz);

	int GetTextHeight(BOOL bHorz = TRUE)
	{
		return bHorz ? m_nTextHeightHorz : m_nTextHeightVert;
	}

	int GetTextWidth(BOOL bHorz = TRUE)
	{
		return bHorz ? m_nTextWidthHorz : m_nTextWidthVert;
	}

	double GetRibbonImageScale()
	{
		return m_bIsRibbonImageScale ? m_dblRibbonImageScale : 1.;
	}

	void EnableRibbonImageScale(BOOL bEnable = TRUE)
	{
		m_bIsRibbonImageScale = bEnable;
	}

	BOOL IsRibbonImageScaleEnabled()
	{
		return m_bIsRibbonImageScale;
	}

	BOOL IsWindowsThemingDrawParentBackground() const
	{
		return m_pfDrawThemeBackground != NULL;
	}

	BOOL DrawParentBackground(CWnd* pWnd, CDC* pDC, LPRECT lpRect = NULL);
	void CleanUp();

	COLORREF GetColor(int nColor);

	BOOL SetLayeredAttrib(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
	BOOL IsWindowsLayerSupportAvailable() const
	{
		return TRUE;
	}

	BOOL Is32BitIcons() const
	{
		return m_bUseBuiltIn32BitIcons && m_nBitsPerPixel >= 16 && !m_bIsBlackHighContrast && !m_bIsWhiteHighContrast;
	}

	BOOL IsHighContrastMode() const
	{
		return m_bIsWhiteHighContrast || m_bIsBlackHighContrast;
	}

	BOOL IsAccessibilitySupport() const
	{
		return m_bEnableAccessibility;
	}

	/// <summary>
	/// Determines positions of Shell auto hide bars.</summary>
	/// <returns> An integer value with encoded flags that specify positions of auto hide bars.
	/// It may combine the following values: AFX_AUTOHIDE_BOTTOM, AFX_AUTOHIDE_TOP, AFX_AUTOHIDE_LEFT, 
	/// AFX_AUTOHIDE_RIGHT.</returns>
	int GetShellAutohideBars()
	{
		if (m_bRefreshAutohideBars)
		{
			m_bRefreshAutohideBars = FALSE;

			APPBARDATA abd;
			ZeroMemory(&abd, sizeof(APPBARDATA));
			abd.cbSize = sizeof(APPBARDATA);

			abd.uEdge = ABE_BOTTOM;
			if (SHAppBarMessage(ABM_GETAUTOHIDEBAR, &abd))
			{
				m_nShellAutohideBars |= AFX_AUTOHIDE_BOTTOM;
			}

			abd.uEdge = ABE_TOP;
			if (SHAppBarMessage(ABM_GETAUTOHIDEBAR, &abd))
			{
				m_nShellAutohideBars |= AFX_AUTOHIDE_TOP;
			}

			abd.uEdge = ABE_LEFT;
			if (SHAppBarMessage(ABM_GETAUTOHIDEBAR, &abd))
			{
				m_nShellAutohideBars |= AFX_AUTOHIDE_LEFT;
			}

			abd.uEdge = ABE_RIGHT;
			if (SHAppBarMessage(ABM_GETAUTOHIDEBAR, &abd))
			{
				m_nShellAutohideBars |= AFX_AUTOHIDE_RIGHT;
			}
		}

		return m_nShellAutohideBars;
	}

	void EnableAccessibilitySupport(BOOL bEnable = TRUE);

	CString RegisterWindowClass(LPCTSTR lpszClassNamePrefix);
	BOOL ExcludeTag(CString& strBuffer, LPCTSTR lpszTag, CString& strTag, BOOL bIsCharsList = FALSE);

	BOOL DwmExtendFrameIntoClientArea(HWND hWnd, AFX_MARGINS* pMargins);
	LRESULT DwmDefWindowProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);
	BOOL DwmIsCompositionEnabled();

	BOOL DrawTextOnGlass(HTHEME hTheme, CDC* pDC, int iPartId, int iStateId, CString strText,
		CRect rect, DWORD dwFlags, int nGlowSize = 0, COLORREF clrText = (COLORREF)-1);

	BOOL Resume();
	BOOL GetNonClientMetrics (NONCLIENTMETRICS& info);

#if (WINVER >= 0x0600)
	/// <summary>
	/// Creates and initializes a Shell item object from a parsing name.</summary>
	/// <param name="pszPath">[in] A pointer to a display name.</param> 
	/// <param name="pbc">A pointer to a bind context that controls the parsing operation.</param> 
	/// <param name="riid">A reference to an interface ID.</param> 
	/// <param name="ppv">[out] When this function returns, contains the interface pointer requested in riid. This will typically be IShellItem or IShellItem2.</param> 
	/// <returns>Returns S_OK if successful, or an error value otherwise. </returns>
	HRESULT ShellCreateItemFromParsingName(PCWSTR pszPath, IBindCtx *pbc, REFIID riid, void **ppv);
#endif

#if (NTDDI_VERSION >= NTDDI_WIN7)
	/// <summary>
	/// Creates and stores in the global data a pointer to ITaskBarList interface.</summary>
	/// <returns>A pointer to ITaskbarList interface if creation of a task bar list object succeeds, or NULL if creation fails or current
	/// Operation System is less than Windows 7.</returns>
	ITaskbarList  *GetITaskbarList();

	/// <summary>
	/// Creates and stores in the global data a pointer to ITaskBarList3 interface.</summary>
	/// <returns>A pointer to ITaskbarList3 interface if creation creation of a task bar list object succeeds, or NULL if creation fails or current
	/// Operation System is less than Windows 7.</returns>
	ITaskbarList3 *GetITaskbarList3();

	/// <summary>
	/// Releases interfaces obtained through GetITaskbarList and GetITaskbarList3 methods.</summary>
	void ReleaseTaskBarRefs();
#endif

	/// <summary>
	/// Initializes D2D, DirectWrite and WIC factories. This method should be called prior to initialization of the main window .</summary>
	/// <returns> 
	/// Returns TRUE if the factories were intilalizrd, FALSE - otherwise</returns>
	/// <param name="d2dFactoryType">The threading model of the D2D factory and the resources it creates.</param>
	/// <param name="writeFactoryType">A value that specifies whether the write factory object will be shared or isolated</param>
	BOOL InitD2D(D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED, DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);

	/// <summary>
	/// Determines whether the D2D was initialized</summary>
	/// <returns> 
	/// TRUE if D2D was initialized; otherwise FALSE.</returns>
	BOOL IsD2DInitialized() const
	{
		return m_bD2DInitialized;
	}

	/// <summary>
	/// Returns a pointer to ID2D1Factory interface stored in the global data. If this interface is not initialized yet, it will be created with the default parameters.</summary>
	/// <returns>A pointer to ID2D1Factory interface if creation of a factory succeeds, or NULL if creation fails or current
	/// Operation System don't have D2D support.</returns>
	ID2D1Factory* GetDirect2dFactory()	{ InitD2D(); return m_pDirect2dFactory; }

	/// <summary>
	/// Returns a pointer to IDWriteFactory interface stored in the global data. If this interface is not initialized yet, it will be created with the default parameters.</summary>
	/// <returns>A pointer to IDWriteFactory interface if creation of a factory succeeds, or NULL if creation fails or current
	/// Operation System don't have DirectWrite support.</returns>
	IDWriteFactory* GetWriteFactory()	{ InitD2D(); return m_pWriteFactory; }

	/// <summary>
	/// Returns a pointer to IWICImagingFactory interface stored in the global data. If this interface is not initialized yet, it will be created with the default parameters.</summary>
	/// <returns>A pointer to IWICImagingFactory interface if creation of a factory succeeds, or NULL if creation fails or current
	/// Operation System don't have WIC support.</returns>
	IWICImagingFactory* GetWICFactory()	{ InitD2D(); return m_pWicFactory; }

	/// <summary>
	/// Creates a rotation transformation that rotates by the specified angle about the specified point.</summary>
	/// <returns>Returns S_OK if successful, or an error value otherwise. </returns>
	/// <param name="angle">The clockwise rotation angle, in degrees.</param>
	/// <param name="center">The point about which to rotate.</param>
	/// <param name="matrix">When this method returns, contains the new rotation transformation. You must allocate storage for this parameter.</param>
	HRESULT D2D1MakeRotateMatrix(FLOAT angle, D2D1_POINT_2F center, D2D1_MATRIX_3X2_F *matrix)
	{
		return m_pfD2D1MakeRotateMatrix == NULL ? E_FAIL : (*m_pfD2D1MakeRotateMatrix)(angle, center, matrix);
	}

protected:

	void UpdateTextMetrics();
	HBITMAP CreateDitherBitmap(HDC hDC);

	int m_nTextHeightHorz;
	int m_nTextHeightVert;
	int m_nTextWidthHorz;
	int m_nTextWidthVert;

	double m_dblRibbonImageScale;
	BOOL   m_bIsRibbonImageScale;
	BOOL   m_bBufferedPaintInited;

	HINSTANCE m_hinstUXThemeDLL;
	HINSTANCE m_hinstDwmapiDLL;

	DRAWTHEMEPARENTBACKGROUND    m_pfDrawThemeBackground;
	DRAWTHEMETEXTEX              m_pfDrawThemeTextEx;
	BUFFEREDPAINTINIT            m_pfBufferedPaintInit;
	BUFFEREDPAINTUNINIT          m_pfBufferedPaintUnInit;
	BEGINBUFFEREDPAINT           m_pfBeginBufferedPaint;
	ENDBUFFEREDPAINT             m_pfEndBufferedPaint;
	DWMEXTENDFRAMEINTOCLIENTAREA m_pfDwmExtendFrameIntoClientArea;
	DWMDEFWINDOWPROC             m_pfDwmDefWindowProc;
	DWMISCOMPOSITIONENABLED      m_pfDwmIsCompositionEnabled;

#if (NTDDI_VERSION >= NTDDI_WIN7)
	BOOL m_bComInitialized;
	BOOL m_bTaskBarInterfacesAvailable;
	ITaskbarList*  m_pTaskbarList;
	ITaskbarList3* m_pTaskbarList3;
#endif

	void ReleaseD2DRefs();

	AFX_IMPORT_DATA static HINSTANCE m_hinstD2DDLL;
	AFX_IMPORT_DATA static HINSTANCE m_hinstDWriteDLL;

	AFX_IMPORT_DATA static ID2D1Factory* m_pDirect2dFactory;
	AFX_IMPORT_DATA static IDWriteFactory* m_pWriteFactory;
	AFX_IMPORT_DATA static IWICImagingFactory* m_pWicFactory;

	AFX_IMPORT_DATA static D2D1MAKEROTATEMATRIX m_pfD2D1MakeRotateMatrix;

	AFX_IMPORT_DATA static BOOL m_bD2DInitialized;
};

AFX_IMPORT_DATA extern AFX_GLOBAL_DATA afxGlobalData;

#define AFX_IMAGE_MARGIN 4

// MFC Control bar compatibility
#define AFX_CX_BORDER   1
#define AFX_CY_BORDER   1

#define AFX_CX_GRIPPER  3
#define AFX_CY_GRIPPER  3
#define AFX_CX_BORDER_GRIPPER 2
#define AFX_CY_BORDER_GRIPPER 2

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
