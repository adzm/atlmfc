// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include <afxwinverapi.h>

// This file contains implementations of wrappers for methods used
// in MFC that are only available in later versions of Windows.

// When the minimum supported version of Windows is increased, the
// implementations of these methods just call the real Windows APIs.

#if _MFC_NTDDI_MIN >= NTDDI_VISTA
#pragma comment(lib, "propsys.lib")
#endif

#if _MFC_NTDDI_MIN >= NTDDI_WIN7
#pragma comment(lib, "dwmapi.lib")
#endif

// Wrappers for Win32 APIs that are only supported on higher versions of Windows

int _AfxGetLocaleInfoEx(LPCWSTR lpLocaleName, LCTYPE LCType, LPWSTR lpLCData, int cchData)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return GetLocaleInfoEx(lpLocaleName, LCType, lpLCData, cchData);
#else
	// use GetLocaleInfoEx if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", GetLocaleInfoEx, pfGetLocaleInfoEx)
	{
		return (*pfGetLocaleInfoEx)(lpLocaleName, LCType, lpLCData, cchData);
	}

	// ...otherwise fall back to using GetLocaleInfo.
	return GetLocaleInfoW(_AtlDownlevelLocaleNameToLCID(lpLocaleName), LCType, lpLCData, cchData);
#endif
}

#define COPYLCIDSTRINGTOARRAY(lcid, str, strarray, strarraylen, currentlen, currentpos, pnumlangs) \
	_AtlDownlevelLCIDToLocaleName(lcid, str, _countof(str)); \
	currentlen = wcslen(str); \
	wcscpy_s(strarray + currentpos, strarraylen - currentpos, str); \
	currentpos += currentlen + 1; \
	*pnumlangs++;

BOOL _AfxGetThreadPreferredUILanguages(__in DWORD dwFlags, __out PULONG pulNumLanguages, __out_opt PZZWSTR pwszLanguagesBuffer, __inout PULONG pcchLanguagesBuffer)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return GetThreadPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
#else
	// use GetThreadPreferredUILanguages if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", GetThreadPreferredUILanguages, pfGetThreadPreferredUILanguages)
	{
		return (*pfGetThreadPreferredUILanguages)(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
	}

	// ...otherwise fall back to using other methods to get the UI language.
	LANGID langid = 0;
	int nPrimaryLang = 0, nSubLang = 0;
	LCID lcid = 0;
	WCHAR wszLocale[7];
	size_t nCurrentLen = 0, nCurrentPos = 0;
	*pulNumLanguages = 0;

	// First get the user's UI languages
	langid = GetUserDefaultUILanguage();
	nPrimaryLang = PRIMARYLANGID(langid);
	nSubLang = SUBLANGID(langid);

	lcid = MAKELCID(MAKELANGID(nPrimaryLang, nSubLang), SORT_DEFAULT);
	COPYLCIDSTRINGTOARRAY(lcid, wszLocale, pwszLanguagesBuffer, *pcchLanguagesBuffer, nCurrentLen, nCurrentPos, pulNumLanguages);

	lcid = MAKELCID(MAKELANGID(nPrimaryLang, SUBLANG_NEUTRAL), SORT_DEFAULT);
	COPYLCIDSTRINGTOARRAY(lcid, wszLocale, pwszLanguagesBuffer, *pcchLanguagesBuffer, nCurrentLen, nCurrentPos, pulNumLanguages);

	// Then get the system's default UI languages
	langid = GetSystemDefaultUILanguage();
	nPrimaryLang = PRIMARYLANGID(langid);
	nSubLang = SUBLANGID(langid);

	lcid = MAKELCID(MAKELANGID(nPrimaryLang, nSubLang), SORT_DEFAULT);
	COPYLCIDSTRINGTOARRAY(lcid, wszLocale, pwszLanguagesBuffer, *pcchLanguagesBuffer, nCurrentLen, nCurrentPos, pulNumLanguages);

	lcid = MAKELCID(MAKELANGID(nPrimaryLang, SUBLANG_NEUTRAL), SORT_DEFAULT);
	COPYLCIDSTRINGTOARRAY(lcid, wszLocale, pwszLanguagesBuffer, *pcchLanguagesBuffer, nCurrentLen, nCurrentPos, pulNumLanguages);

	lcid = LOCALE_SYSTEM_DEFAULT;
	COPYLCIDSTRINGTOARRAY(lcid, wszLocale, pwszLanguagesBuffer, *pcchLanguagesBuffer, nCurrentLen, nCurrentPos, pulNumLanguages);

	// Ensure that the list is double-NULL-terminated
	pwszLanguagesBuffer[nCurrentPos] = 0;

	return TRUE;
#endif
}

int _AfxCompareStringEx(LPCWSTR lpLocaleName, DWORD dwCmpFlags, LPCWSTR lpString1, int cchCount1, LPCWSTR lpString2, int cchCount2)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return CompareStringEx(lpLocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, NULL, NULL, 0);
#else
	// use CompareStringEx if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", CompareStringEx, pfCompareStringEx)
	{
		return (*pfCompareStringEx)(lpLocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, NULL, NULL, 0);
	}

	// ...otherwise fall back to using CompareString.
	return CompareStringW(_AtlDownlevelLocaleNameToLCID(lpLocaleName), dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
#endif
}


HRESULT _AfxRegisterApplicationRestart(__in_opt PCWSTR pwzCommandline, __in DWORD dwFlags)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return RegisterApplicationRestart(pwzCommandline, dwFlags);
#else
	// use RegisterApplicationRestart if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", RegisterApplicationRestart, pfRegisterApplicationRestart)
	{
		return (*pfRegisterApplicationRestart)(pwzCommandline, dwFlags);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxRegisterApplicationRecoveryCallback(__in APPLICATION_RECOVERY_CALLBACK pRecoveryCallback, __in_opt PVOID pvParameter, __in DWORD dwPingInterval, __in DWORD dwFlags)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return RegisterApplicationRecoveryCallback(pRecoveryCallback, pvParameter, dwPingInterval, dwFlags);
#else
	// use RegisterApplicationRecoveryCallback if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", RegisterApplicationRecoveryCallback, pfRegisterApplicationRecoveryCallback)
	{
		return (*pfRegisterApplicationRecoveryCallback)(pRecoveryCallback, pvParameter, dwPingInterval, dwFlags);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxApplicationRecoveryInProgress(__out PBOOL pbCanceled)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return ApplicationRecoveryInProgress(pbCanceled);
#else
	// use ApplicationRecoveryInProgress if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", ApplicationRecoveryInProgress, pfApplicationRecoveryInProgress)
	{
		return (*pfApplicationRecoveryInProgress)(pbCanceled);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

VOID _AfxApplicationRecoveryFinished(__in BOOL bSuccess)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return ApplicationRecoveryFinished(bSuccess);
#else
	// use ApplicationRecoveryFinished if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"kernel32.dll", ApplicationRecoveryFinished, pfApplicationRecoveryFinished)
	{
		return (*pfApplicationRecoveryFinished)(bSuccess);
	}

	// ...otherwise return because there is no fallback.
#endif
}

BOOL _AfxChangeWindowMessageFilter(__in UINT message, __in DWORD dwFlag)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return ChangeWindowMessageFilter(message, dwFlag);
#else
	// use ChangeWindowMessageFilter if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"user32.dll", ChangeWindowMessageFilter, pfChangeWindowMessageFilter)
	{
		return (*pfChangeWindowMessageFilter)(message, dwFlag);
	}

	// ...otherwise return failure because the API is only needed for Vista+ feature support.
	return FALSE;
#endif
}

HRESULT _AfxSHCreateItemFromParsingName(__in PCWSTR pszPath, __in IBindCtx *pbc, __in REFIID riid, __out void **ppv)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return SHCreateItemFromParsingName(pszPath, pbc, riid, ppv);
#else
	// use SHCreateItemFromParsingName if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"shell32.dll", SHCreateItemFromParsingName, pfSHCreateItemFromParsingName)
	{
		return (*pfSHCreateItemFromParsingName)(pszPath, pbc, riid, ppv);
	}

	// ...otherwise return failure because the API is only needed for Vista+ feature support.
	return E_FAIL;
#endif
}

HRESULT _AfxSHGetKnownFolderPath(__in REFKNOWNFOLDERID rfid, __in DWORD dwFlags, __in_opt HANDLE hToken, __out PWSTR *ppszPath)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return SHGetKnownFolderPath(rfid, dwFlags, hToken, ppszPath);
#else
	// use SHGetKnownFolderPath if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"shell32.dll", SHGetKnownFolderPath, pfSHGetKnownFolderPath)
	{
		return (*pfSHGetKnownFolderPath)(rfid, dwFlags, hToken, ppszPath);
	}

	// ...otherwise return failure because the API is only needed for Vista+ feature support.
	return E_FAIL;
#endif
}

BOOL _AfxInitNetworkAddressControl()
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return InitNetworkAddressControl();
#else
	// use InitNetworkAddressControl if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"shell32.dll", InitNetworkAddressControl, pfInitNetworkAddressControl)
	{
		return (*pfInitNetworkAddressControl)();
	}

	// ...otherwise return failure because there is no fallback.
	return FALSE;
#endif
}

HRESULT _AfxDrawThemeTextEx(__in HTHEME hTheme, __in HDC hdc, __in int iPartId, __in int iStateId, __in LPCWSTR pszText, __in int iCharCount, __in DWORD dwFlags, __inout LPRECT pRect, __in const DTTOPTS *pOptions)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return DrawThemeTextEx(hTheme, hdc, iPartId, iStateId, pszText, iCharCount, dwFlags, pRect, pOptions);
#else
	// use DrawThemeTextEx if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"uxtheme.dll", DrawThemeTextEx, pfDrawThemeTextEx)
	{
		return (*pfDrawThemeTextEx)(hTheme, hdc, iPartId, iStateId, pszText, iCharCount, dwFlags, pRect, pOptions);
	}

	// ...otherwise fall back to using DrawThemeText.
	return DrawThemeText(hTheme, hdc, iPartId, iStateId, pszText, iCharCount, dwFlags, 0, pRect);
#endif
}

HRESULT _AfxBufferedPaintInit(void)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return BufferedPaintInit();
#else
	// use BufferedPaintInit if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"uxtheme.dll", BufferedPaintInit, pfBufferedPaintInit)
	{
		return (*pfBufferedPaintInit)();
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxBufferedPaintUnInit(void)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return BufferedPaintUnInit();
#else
	// use BufferedPaintUnInit if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"uxtheme.dll", BufferedPaintUnInit, pfBufferedPaintUnInit)
	{
		return (*pfBufferedPaintUnInit)();
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HPAINTBUFFER _AfxBeginBufferedPaint(HDC hdcTarget, const RECT *prcTarget, BP_BUFFERFORMAT dwFormat, __in BP_PAINTPARAMS *pPaintParams, __out HDC *phdc)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return BeginBufferedPaint(hdcTarget, prcTarget, dwFormat, pPaintParams, phdc);
#else
	// use BeginBufferedPaint if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"uxtheme.dll", BeginBufferedPaint, pfBeginBufferedPaint)
	{
		return (*pfBeginBufferedPaint)(hdcTarget, prcTarget, dwFormat, pPaintParams, phdc);
	}

	// ...otherwise return failure because there is no fallback.
	return NULL;
#endif
}

HRESULT _AfxEndBufferedPaint(HPAINTBUFFER hBufferedPaint, BOOL fUpdateTarget)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return EndBufferedPaint(hBufferedPaint, fUpdateTarget);
#else
	// use EndBufferedPaint if it is available (only on Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"uxtheme.dll", EndBufferedPaint, pfEndBufferedPaint)
	{
		return (*pfEndBufferedPaint)(hBufferedPaint, fUpdateTarget);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

BOOL _AfxDwmDefWindowProc(__in HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, __out LRESULT *plResult)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return DwmDefWindowProc(hwnd, msg, wParam, lParam, plResult);
#else
	// use DwmDefWindowProc if it is available (only on Vista+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmDefWindowProc, pfDwmDefWindowProc)
	{
		return (*pfDwmDefWindowProc)(hwnd, msg, wParam, lParam, plResult);
	}

	// ...otherwise return failure because there is no fallback.
	return FALSE;
#endif
}

HRESULT _AfxDwmExtendFrameIntoClientArea(HWND hWnd, __in const MARGINS *pMarInset)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return DwmExtendFrameIntoClientArea(hWnd, pMarInset);
#else
	// use DwmExtendFrameIntoClientArea if it is available (only on Vista+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmExtendFrameIntoClientArea, pfDwmExtendFrameIntoClientArea)
	{
		return (*pfDwmExtendFrameIntoClientArea)(hWnd, pMarInset);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxDwmIsCompositionEnabled(__out BOOL *pfEnabled)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return DwmIsCompositionEnabled(pfEnabled);
#else
	// use DwmIsCompositionEnabled if it is available (only on Vista+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmIsCompositionEnabled, pfDwmIsCompositionEnabled)
	{
		return (*pfDwmIsCompositionEnabled)(pfEnabled);
	}

	// ...otherwise set flag to indicate that composition is disabled.
	*pfEnabled = FALSE;
	return S_OK;
#endif
}

HRESULT _AfxDwmSetWindowAttribute(HWND hwnd, DWORD dwAttribute, __in LPCVOID pvAttribute, DWORD cbAttribute)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return DwmSetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);
#else
	// use DwmSetWindowAttribute if it is available (only on Vista+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmSetWindowAttribute, pfDwmSetWindowAttribute)
	{
		return (*pfDwmSetWindowAttribute)(hwnd, dwAttribute, pvAttribute, cbAttribute);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxDwmSetIconicThumbnail(__in HWND hwnd, __in HBITMAP hbmp, __in DWORD dwSITFlags)
{
#if _MFC_NTDDI_MIN >= NTDDI_WIN7
	return DwmSetIconicThumbnail(hwnd, hbmp, dwSITFlags);
#else
	// use DwmSetIconicThumbnail if it is available (only on Windows 7+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmSetIconicThumbnail, pfDwmSetIconicThumbnail)
	{
		return (*pfDwmSetIconicThumbnail)(hwnd, hbmp, dwSITFlags);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxDwmInvalidateIconicBitmaps(__in HWND hwnd)
{
#if _MFC_NTDDI_MIN >= NTDDI_WIN7
	return DwmInvalidateIconicBitmaps(hwnd);
#else
	// use DwmInvalidateIconicBitmaps if it is available (only on Windows 7+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmInvalidateIconicBitmaps, pfDwmInvalidateIconicBitmaps)
	{
		return (*pfDwmInvalidateIconicBitmaps)(hwnd);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxDwmSetIconicLivePreviewBitmap(HWND hwnd, HBITMAP hbmp, __in_opt POINT *pptClient, DWORD dwSITFlags)
{
#if _MFC_NTDDI_MIN >= NTDDI_WIN7
	return DwmSetIconicLivePreviewBitmap(hwnd, hbmp, pptClient, dwSITFlags);
#else
	// use DwmSetIconicLivePreviewBitmap if it is available (only on Windows 7+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"dwmapi.dll", DwmSetIconicLivePreviewBitmap, pfDwmSetIconicLivePreviewBitmap)
	{
		return (*pfDwmSetIconicLivePreviewBitmap)(hwnd, hbmp, pptClient, dwSITFlags);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

HRESULT _AfxPSGetPropertyDescriptionListFromString(__in LPCWSTR pszPropList, __in REFIID riid, __out void **ppv)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return PSGetPropertyDescriptionListFromString(pszPropList, riid, ppv);
#else
	// use PSGetPropertyDescriptionListFromString if it is available (only on Vista+)...
	IFDYNAMICLOADCACHEDFUNCTIONFORMFC(L"propsys.dll", PSGetPropertyDescriptionListFromString, pfPSGetPropertyDescriptionListFromString)
	{
		return (*pfPSGetPropertyDescriptionListFromString)(pszPropList, riid, ppv);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}

BOOL _AfxIsTaskDialogSupported()
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return TRUE;
#else
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"comctl32.dll", TaskDialogIndirect, pfTaskDialogIndirect)
	{
		return TRUE;
	}

	return FALSE;
#endif
}

HRESULT _AfxTaskDialogIndirect(_In_ const TASKDIALOGCONFIG *pTaskConfig, _Out_opt_ int *pnButton, _Out_opt_ int *pnRadioButton, _Out_opt_ BOOL *pfVerificationFlagChecked)
{
#if _MFC_NTDDI_MIN >= NTDDI_VISTA
	return TaskDialogIndirect(pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);
#else
	// use TaskDialogIndirect if it is available (only on Windows Vista+)...
	IFDYNAMICGETCACHEDFUNCTIONFORMFC(L"comctl32.dll", TaskDialogIndirect, pfTaskDialogIndirect)
	{
		return (*pfTaskDialogIndirect)(pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);
	}

	// ...otherwise return failure because there is no fallback.
	return E_FAIL;
#endif
}
