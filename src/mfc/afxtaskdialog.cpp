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

HRESULT CALLBACK TaskDialogCallback(_In_ HWND hWnd, _In_ UINT uNotification, _In_ WPARAM wParam, _In_ LPARAM lParam, _In_ LONG_PTR dwRefData)
{
	CTaskDialog *pTaskDialog = reinterpret_cast<CTaskDialog*>(dwRefData);

	ENSURE(pTaskDialog != NULL);

	HRESULT hRes = S_OK;

	switch (uNotification)
	{
		case TDN_BUTTON_CLICKED:
			// wParam = Button ID
			pTaskDialog->m_nButtonId = static_cast<int>(wParam);
			hRes = pTaskDialog->OnCommandControlClick(static_cast<int>(wParam));
			break;

		case TDN_HYPERLINK_CLICKED:
			// lParam = (LPCWSTR)pszHREF
			hRes = pTaskDialog->OnHyperlinkClick(CString(reinterpret_cast<LPCWSTR>(lParam)));
			break;

		case TDN_TIMER:
			// wParam = Milliseconds since dialog created or timer reset
			hRes = pTaskDialog->OnTimer(static_cast<long>(wParam));
			break;

		case TDN_DESTROYED:
			hRes = pTaskDialog->OnDestroy();
			pTaskDialog->m_hWnd = 0; //disable runtime
			break;

		case TDN_NAVIGATED:
			hRes = pTaskDialog->OnNavigatePage();
			break;

		case TDN_RADIO_BUTTON_CLICKED:
			// wParam = Radio Button ID
			pTaskDialog->m_nRadioId = static_cast<int>(wParam);
			hRes = pTaskDialog->OnRadioButtonClick(static_cast<int>(wParam));
			break;

		case TDN_CREATED:
			// Sending TDM_CLICK_BUTTON and TDM_CLICK_RADIO_BUTTON do under OnCreated method.
			hRes = pTaskDialog->OnCreate();
			break;

		case TDN_DIALOG_CONSTRUCTED:
			pTaskDialog->m_hWnd = hWnd;

			if (pTaskDialog->m_nFlags & TDF_SHOW_PROGRESS_BAR)
			{
				if (pTaskDialog->m_nFlags & TDF_SHOW_MARQUEE_PROGRESS_BAR)
				{
					SendMessage(hWnd, TDM_SET_PROGRESS_BAR_MARQUEE,	static_cast<WPARAM>(pTaskDialog->m_nProgressState),
							static_cast<LPARAM>(pTaskDialog->m_nProgressPos));
				}
				else
				{
					SendMessage(hWnd, TDM_SET_PROGRESS_BAR_RANGE, 0, MAKELPARAM(pTaskDialog->m_nProgressRangeMin, pTaskDialog->m_nProgressRangeMax));
					SendMessage(hWnd, TDM_SET_PROGRESS_BAR_POS, static_cast<WPARAM>(pTaskDialog->m_nProgressPos) , 0);
					SendMessage(hWnd, TDM_SET_PROGRESS_BAR_STATE, static_cast<WPARAM>(pTaskDialog->m_nProgressState), 0);
				}
			}

			if (!pTaskDialog->m_aRadioButtons.IsEmpty())
			{
				INT_PTR nCount = pTaskDialog->m_aRadioButtons.GetSize();

				for(INT_PTR i = 0; i < nCount; i++)
				{
					if (!(pTaskDialog->m_aRadioButtons[i].cState & CTaskDialog::BUTTON_ENABLED))
					{
						SendMessage(hWnd, TDM_ENABLE_RADIO_BUTTON,
							static_cast<WPARAM>(pTaskDialog->m_aRadioButtons[i].nId), static_cast<LPARAM>(FALSE));
					}
				}
			}

			if (!pTaskDialog->m_aButtons.IsEmpty())
			{
				INT_PTR nCount = pTaskDialog->m_aButtons.GetSize();

				for(INT_PTR i = 0; i < nCount; i++)
				{
					if (!(pTaskDialog->m_aButtons[i].cState & CTaskDialog::BUTTON_ENABLED))
					{

						SendMessage(hWnd, TDM_ENABLE_BUTTON,
							static_cast<WPARAM>(pTaskDialog->m_aButtons[i].nId), static_cast<LPARAM>(FALSE));
					}

					if (pTaskDialog->m_aButtons[i].cState & CTaskDialog::BUTTON_ELEVATION)
					{
						SendMessage(hWnd, TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE,
							static_cast<WPARAM>(pTaskDialog->m_aButtons[i].nId), static_cast<LPARAM>(TRUE));
					}
				}
			}

			if (pTaskDialog->m_nButtonDisabled || pTaskDialog->m_nButtonElevation)
			{
				UINT nButtonFlag = TDCBF_OK_BUTTON;

				for(int i = 0; i < pTaskDialog->GetCommonButtonCount(); i++)
				{
					if (pTaskDialog->m_nButtonDisabled & nButtonFlag)
					{
						//Make sure that button id is defined
						ENSURE(pTaskDialog->GetCommonButtonId(nButtonFlag));

						SendMessage(hWnd, TDM_ENABLE_BUTTON,
							static_cast<WPARAM>(pTaskDialog->GetCommonButtonId(nButtonFlag)), static_cast<LPARAM>(FALSE));
					}

					if (pTaskDialog->m_nButtonElevation & nButtonFlag)
					{
						//Make sure that button id is defined
						ENSURE(pTaskDialog->GetCommonButtonId(nButtonFlag));

						SendMessage(hWnd, TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE,
							static_cast<WPARAM>(pTaskDialog->GetCommonButtonId(nButtonFlag)), static_cast<LPARAM>(TRUE));
					}

					nButtonFlag <<= 1;
				}
			}

			hRes = pTaskDialog->OnInit();
			break;

		case TDN_VERIFICATION_CLICKED:
			// wParam = 1 if checkbox checked, 0 if not, lParam is unused and always 0
			pTaskDialog->m_bVerified = static_cast<BOOL>(wParam);
			hRes = pTaskDialog->OnVerificationCheckboxClick( static_cast<BOOL>(wParam));
			break;

		case TDN_HELP:
			hRes = pTaskDialog->OnHelp();
			break;

		case TDN_EXPANDO_BUTTON_CLICKED:
			// wParam = 0 (dialog is now collapsed), wParam != 0 (dialog is now expanded)
			hRes = pTaskDialog->OnExpandButtonClick(0 != wParam ? TRUE : FALSE);
			break;
	}
	return hRes;
}

IMPLEMENT_DYNAMIC(CTaskDialog, CObject);

CTaskDialog::CTaskDialog(_In_ const CString& strContent, _In_ const CString& strMainInstruction,
		_In_ const CString& strTitle, _In_ int nCommonButtons /* = TDCBF_YES_BUTTON | TDCBF_NO_BUTTON */,
		_In_ int nTaskDialogOptions /* = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS */,
		_In_ const CString& strFooter /* = _T("") */)
	: CObject()
	, m_hWnd(NULL)
	, m_nCommonButton(nCommonButtons)
	, m_nButtonDisabled(0)
	, m_nButtonElevation(0)
	, m_nFlags(nTaskDialogOptions)
	, m_nWidth(0)
	, m_nDefaultCommandControl(0)
	, m_nDefaultRadioButton(0)
	, m_strContent(strContent)
	, m_strMainInstruction(strMainInstruction)
	, m_strTitle(strTitle)
	, m_strFooter(strFooter)
	, m_strVerification(_T(""))
	, m_strInformation(_T(""))
	, m_strExpand(_T(""))
	, m_strCollapse(_T(""))
	, m_nProgressRangeMin(CTaskDialog::PROGRESS_BAR_MIN)
	, m_nProgressRangeMax(CTaskDialog::PROGRESS_BAR_MAX)
	, m_nProgressState(PBST_NORMAL)
	, m_nProgressPos(CTaskDialog::PROGRESS_BAR_MIN)
	, m_bVerified(FALSE)
	, m_nRadioId(0)
	, m_nButtonId(0)
{
	m_mainIcon.pszIcon = NULL;
	m_footerIcon.pszIcon = NULL;

	if (m_nFlags & TDF_VERIFICATION_FLAG_CHECKED)
	{
		m_bVerified = TRUE;
	}
}

CTaskDialog::CTaskDialog(_In_ const CString& strContent, _In_ const CString& strMainInstruction,
		_In_ const CString& strTitle, _In_ int nIDCommandControlsFirst, _In_ int nIDCommandControlsLast,
		_In_ int nCommonButtons, _In_ int nTaskDialogOptions /* = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS */,
		_In_ const CString& strFooter /* = _T("") */)
	: CObject()
	, m_hWnd(NULL)
	, m_nCommonButton(nCommonButtons)
	, m_nButtonDisabled(0)
	, m_nButtonElevation(0)
	, m_nFlags(nTaskDialogOptions)
	, m_nWidth(0)
	, m_nDefaultCommandControl(0)
	, m_nDefaultRadioButton(0)
	, m_strContent(strContent)
	, m_strMainInstruction(strMainInstruction)
	, m_strTitle(strTitle)
	, m_strFooter(strFooter)
	, m_strVerification(_T(""))
	, m_strInformation(_T(""))
	, m_strExpand(_T(""))
	, m_strCollapse(_T(""))
	, m_nProgressRangeMin(CTaskDialog::PROGRESS_BAR_MIN)
	, m_nProgressRangeMax(CTaskDialog::PROGRESS_BAR_MAX)
	, m_nProgressState(PBST_NORMAL)
	, m_nProgressPos(CTaskDialog::PROGRESS_BAR_MIN)
	, m_bVerified(FALSE)
	, m_nRadioId(0)
	, m_nButtonId(0)
{
	m_mainIcon.pszIcon = NULL;
	m_footerIcon.pszIcon = NULL;

	if (m_nFlags & TDF_VERIFICATION_FLAG_CHECKED)
	{
		m_bVerified = TRUE;
	}

	LoadCommandControls(nIDCommandControlsFirst, nIDCommandControlsLast);
}

CTaskDialog::~CTaskDialog()
{

}

void CTaskDialog::LoadCommandControls(_In_ int nIDCommandControlsFirst, _In_ int nIDCommandControlsLast)
{
	ENSURE(nIDCommandControlsFirst <= nIDCommandControlsLast);
	ENSURE(nIDCommandControlsFirst >= 0 && nIDCommandControlsLast >= 0);

	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	CString strTmp;
	m_aButtons.RemoveAll();

	for(int i = nIDCommandControlsFirst; i <= nIDCommandControlsLast; i++)
	{
		if (!strTmp.LoadString(i))
		{
			continue;
		}

		AddCommandControl(i, strTmp);
	}
}

void CTaskDialog::LoadRadioButtons(_In_ int nIDRadioButtonsFirst, _In_ int nIDRadioButtonsLast)
{
	ENSURE(nIDRadioButtonsFirst <= nIDRadioButtonsLast);
	ENSURE(nIDRadioButtonsFirst >= 0 && nIDRadioButtonsLast >= 0);

	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	CString strTmp;
	m_aRadioButtons.RemoveAll();

	for(int i = nIDRadioButtonsFirst; i <= nIDRadioButtonsLast; i++)
	{
		if (!strTmp.LoadString(i))
		{
			continue;
		}

		AddRadioButton(i, strTmp);
	}
}

void CTaskDialog::SetWindowTitle(_In_ const CString& strTitle)
{
	m_strTitle = strTitle;

	if (m_hWnd != NULL)
	{
		SetWindowText(m_hWnd, m_strTitle.GetString());
	}
}

void CTaskDialog::SetMainInstruction(_In_ const CString& strMainInstruction)
{
	m_strMainInstruction = strMainInstruction;
	Notify(TDM_SET_ELEMENT_TEXT, TDE_MAIN_INSTRUCTION, reinterpret_cast<LPARAM>(m_strMainInstruction.GetString()));
}

void CTaskDialog::SetContent(_In_ const CString& strContent)
{
	m_strContent = strContent;
	Notify(TDM_SET_ELEMENT_TEXT, TDE_CONTENT, reinterpret_cast<LPARAM>(m_strContent.GetString()));
}

void CTaskDialog::SetMainIcon(_In_ HICON hMainIcon)
{
	ENSURE(hMainIcon != NULL);

	// If the icon was initially set by HICON, allow only HICON setter method after the window has been created.
	ENSURE(NULL == m_hWnd || m_nFlags & TDF_USE_HICON_MAIN);

	m_mainIcon.hIcon = hMainIcon;
	m_nFlags |= TDF_USE_HICON_MAIN;

	Notify(TDM_UPDATE_ICON, TDIE_ICON_MAIN, reinterpret_cast<LPARAM>(m_mainIcon.hIcon));
}

void CTaskDialog::SetMainIcon(_In_ LPCWSTR lpszMainIcon)
{
	ENSURE(lpszMainIcon != NULL);

	// If the icon was initially set by LPWSTR, allow only LPWSTR setter method after the window has been created.
	ENSURE(NULL == m_hWnd || !(m_nFlags & TDF_USE_HICON_MAIN));

	m_mainIcon.pszIcon = lpszMainIcon;
	m_nFlags &= ~TDF_USE_HICON_MAIN;

	Notify(TDM_UPDATE_ICON, TDIE_ICON_MAIN, reinterpret_cast<LPARAM>(m_mainIcon.pszIcon));
}

void CTaskDialog::SetFooterIcon(_In_ HICON hFooterIcon)
{
	ENSURE(hFooterIcon != NULL);

	// If the icon was initially set by HICON, allow only HICON setter method after the window has been created.
	ENSURE(NULL == m_hWnd || m_nFlags & TDF_USE_HICON_FOOTER);

	m_footerIcon.hIcon = hFooterIcon;
	m_nFlags |= TDF_USE_HICON_FOOTER;

	Notify(TDM_UPDATE_ICON, TDIE_ICON_FOOTER, reinterpret_cast<LPARAM>(m_footerIcon.hIcon));
}

void CTaskDialog::SetFooterIcon(_In_ LPCWSTR lpszFooterIcon)
{
	ENSURE(lpszFooterIcon != NULL);

	// If the icon was initially set by LPWSTR, allow only LPWSTR setter method after the window has been created.
	ENSURE(NULL == m_hWnd || !(m_nFlags & TDF_USE_HICON_FOOTER));

	m_footerIcon.pszIcon = lpszFooterIcon;
	m_nFlags &= ~TDF_USE_HICON_FOOTER;

	Notify(TDM_UPDATE_ICON, TDIE_ICON_FOOTER, reinterpret_cast<LPARAM>(m_footerIcon.pszIcon));
}

void CTaskDialog::SetFooterText(_In_ const CString& strFooterText)
{
	m_strFooter = strFooterText;
	Notify(TDM_SET_ELEMENT_TEXT, TDE_FOOTER, reinterpret_cast<LPARAM>(m_strFooter.GetString()));
}

void CTaskDialog::SetVerificationCheckboxText(_In_ const CString& strVerificationText)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_strVerification = strVerificationText;
}

void CTaskDialog::SetExpansionArea(_In_ const CString& strExpandedInformation, _In_ const CString& strCollapsedLabel /* = _T("") */, _In_ const CString& strExpandedLabel /* = _T("") */)
{
	m_strCollapse = strCollapsedLabel;
	m_strExpand = strExpandedLabel;
	m_strInformation = strExpandedInformation;

	Notify(TDM_SET_ELEMENT_TEXT, TDE_EXPANDED_INFORMATION, reinterpret_cast<LPARAM>(m_strInformation.GetString()));
}

void CTaskDialog::SetDialogWidth(_In_ int nWidth /* = 0 */)
{
	ENSURE(nWidth >= 0);

	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_nWidth = nWidth;
}

void CTaskDialog::SetCommonButtons(_In_ int nButtonMask, _In_ int nDisabledButtonMask /* = 0 */, _In_ int nElevationButtonMask /* = 0 */)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_nCommonButton = nButtonMask;

	// Verify disabled command controls
	ENSURE(0 == nDisabledButtonMask || nButtonMask & nDisabledButtonMask);

	m_nButtonDisabled = nDisabledButtonMask;

	// Verify definiton of elevation
	ENSURE(0 == nElevationButtonMask || nButtonMask & nElevationButtonMask);

	m_nButtonElevation = nElevationButtonMask;
}

void CTaskDialog::SetCommonButtonOptions(_In_ int nDisabledButtonMask, _In_ int nElevationButtonMask /* = 0 */)
{
	UINT nButtonFlag = TDCBF_OK_BUTTON;

	for (int i = 0; i < GetCommonButtonCount(); i++)
	{
		if (nButtonFlag & m_nCommonButton)
		{
			int nCommonButtonId = GetCommonButtonId(nButtonFlag);
			INT_PTR nCommandCtrlIndex = GetButtonIndex(nCommonButtonId, m_aButtons);

			BOOL bEnabled = nDisabledButtonMask & nButtonFlag ? FALSE : TRUE;
			BOOL bRequiresElevation = nElevationButtonMask & nButtonFlag ? TRUE : FALSE;

			if (nCommandCtrlIndex != -1)
			{
				if (bEnabled)
				{
					m_aButtons[nCommandCtrlIndex].cState |= CTaskDialog::BUTTON_ENABLED;
				}
				else
				{
					m_aButtons[nCommandCtrlIndex].cState &= ~CTaskDialog::BUTTON_ENABLED;
				}

				if (bRequiresElevation)
				{
					m_aButtons[nCommandCtrlIndex].cState |= CTaskDialog::BUTTON_ELEVATION;
				}
				else
				{
					m_aButtons[nCommandCtrlIndex].cState &= ~CTaskDialog::BUTTON_ELEVATION;
				}
			}

			Notify(TDM_ENABLE_BUTTON, static_cast<WPARAM>(nCommonButtonId), static_cast<LPARAM>(bEnabled));
			Notify(TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE, static_cast<WPARAM>(nCommonButtonId), static_cast<LPARAM>(bRequiresElevation));
		}
		else
		{
			// Don't disable buttons which are not defined
			ENSURE(0 == nDisabledButtonMask || !(nDisabledButtonMask & nButtonFlag));

			// Don't elevate buttons which are not defined
			ENSURE(0 == nElevationButtonMask || !(nElevationButtonMask & nButtonFlag));
		}

		nButtonFlag <<= 1;
	}

	m_nButtonDisabled = nDisabledButtonMask;
	m_nButtonElevation = nElevationButtonMask;
}

void CTaskDialog::AddCommandControl(_In_ int nCommandControlID, _In_ const CString& strCaption, _In_ BOOL bEnabled /* = TRUE */, _In_ BOOL bRequiresElevation /* = FALSE */)
{
	ENSURE(nCommandControlID > 0);
	ENSURE(!strCaption.IsEmpty());

	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_aButtons.Add(CTaskDialogButton(nCommandControlID, strCaption,
		((bEnabled ? CTaskDialog::BUTTON_ENABLED : 0) | (bRequiresElevation ? CTaskDialog::BUTTON_ELEVATION : 0))));
}

void CTaskDialog::AddRadioButton(_In_ int nRadioButtonID, _In_ const CString& strCaption, _In_ BOOL bEnabled /* = TRUE */)
{
	ENSURE(nRadioButtonID > 0);
	ENSURE(!strCaption.IsEmpty());

	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_aRadioButtons.Add(CTaskDialogButton(nRadioButtonID, strCaption, (bEnabled ? CTaskDialog::BUTTON_ENABLED : 0)));
}

void CTaskDialog::SetProgressBarRange(_In_ int nRangeMin, _In_ int nRangeMax)
{
	ENSURE(nRangeMin < nRangeMax);

	// Progress bar cannot be defined after the window has been created.
	ENSURE(NULL == m_hWnd || (!(m_nFlags & TDF_SHOW_MARQUEE_PROGRESS_BAR) && (m_nFlags & TDF_SHOW_PROGRESS_BAR)));

	m_nProgressRangeMin = nRangeMin;
	m_nProgressRangeMax = nRangeMax;

	m_nFlags &= ~TDF_SHOW_MARQUEE_PROGRESS_BAR;
	m_nFlags |= TDF_SHOW_PROGRESS_BAR;

	Notify(TDM_SET_PROGRESS_BAR_RANGE, 0, MAKELPARAM(m_nProgressRangeMin, m_nProgressRangeMax));
}

void CTaskDialog::SetProgressBarPosition(_In_ int nProgressPos)
{
	ENSURE(m_nProgressRangeMin <= nProgressPos && nProgressPos <= m_nProgressRangeMax);

	// Progress bar cannot be defined after the window has been created.
	ENSURE(NULL == m_hWnd || (!(m_nFlags & TDF_SHOW_MARQUEE_PROGRESS_BAR) && (m_nFlags & TDF_SHOW_PROGRESS_BAR)));

	m_nProgressPos = nProgressPos;
	m_nFlags &= ~TDF_SHOW_MARQUEE_PROGRESS_BAR;
	m_nFlags |= TDF_SHOW_PROGRESS_BAR;

	Notify(TDM_SET_PROGRESS_BAR_POS, static_cast<WPARAM>(m_nProgressPos) , 0);
}

void CTaskDialog::SetProgressBarState(_In_ int nState /* = PBST_NORMAL */)
{
	//Progress bar cannot be defined after the window has been created.
	ENSURE(NULL == m_hWnd || (!(m_nFlags & TDF_SHOW_MARQUEE_PROGRESS_BAR) && (m_nFlags & TDF_SHOW_PROGRESS_BAR)));

	m_nProgressState = nState;
	m_nFlags &= ~TDF_SHOW_MARQUEE_PROGRESS_BAR;
	m_nFlags |= TDF_SHOW_PROGRESS_BAR;

	Notify(TDM_SET_PROGRESS_BAR_STATE, static_cast<WPARAM>(m_nProgressState), 0);
}

void CTaskDialog::SetProgressBarMarquee(_In_ BOOL bEnabled /* = TRUE */, _In_ int nMarqueeSpeed /* = 0 */)
{
	ENSURE(nMarqueeSpeed >= 0);

	// Marquee cannot be defined after the window has been created.
	ENSURE(NULL == m_hWnd || ((m_nFlags & TDF_SHOW_MARQUEE_PROGRESS_BAR) && (m_nFlags & TDF_SHOW_PROGRESS_BAR)));

	m_nProgressState = bEnabled;
	m_nProgressPos = nMarqueeSpeed;

	m_nFlags |= TDF_SHOW_PROGRESS_BAR | TDF_SHOW_MARQUEE_PROGRESS_BAR;

	Notify(TDM_SET_PROGRESS_BAR_MARQUEE, static_cast<WPARAM>(m_nProgressState), static_cast<LPARAM>(m_nProgressPos));
}

void CTaskDialog::SetOptions(_In_ int nOptionFlag)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_nFlags = nOptionFlag;

	if (m_nFlags & TDF_VERIFICATION_FLAG_CHECKED)
	{
		m_bVerified = TRUE;
	}
}

int CTaskDialog::GetOptions() const
{
	return m_nFlags;
}

BOOL CTaskDialog::GetVerificationCheckboxState() const
{
	return m_bVerified;
}

int CTaskDialog::GetSelectedRadioButtonID() const
{
	return m_nRadioId;
}

int CTaskDialog::GetSelectedCommandControlID() const
{
	return m_nButtonId;
}

void CTaskDialog::SetCommandControlOptions(_In_ int nCommandControlID, _In_ BOOL bEnabled, _In_ BOOL bRequiresElevation /* = FALSE */)
{
	INT_PTR nIdx = GetButtonIndex(nCommandControlID, m_aButtons);
	ENSURE(nIdx != -1);

	if (nIdx != -1)
	{
		if (bEnabled)
		{
			m_aButtons[nIdx].cState |= CTaskDialog::BUTTON_ENABLED;
		}
		else
		{
			m_aButtons[nIdx].cState &= ~CTaskDialog::BUTTON_ENABLED;
		}

		if (bRequiresElevation)
		{
			m_aButtons[nIdx].cState |= CTaskDialog::BUTTON_ELEVATION;
		}
		else
		{
			m_aButtons[nIdx].cState &= ~CTaskDialog::BUTTON_ELEVATION;
		}
	}

	int nButtonFlag = GetCommonButtonFlag(nCommandControlID);

	if (nButtonFlag != 0)
	{
		if (bEnabled)
		{
			m_nButtonDisabled &= ~nButtonFlag;
		}
		else
		{
			m_nButtonDisabled |= nButtonFlag;
		}

		if (bRequiresElevation)
		{
			m_nButtonElevation |= CTaskDialog::BUTTON_ELEVATION;
		}
		else
		{
			m_nButtonElevation &= ~CTaskDialog::BUTTON_ELEVATION;
		}
	}

	Notify(TDM_ENABLE_BUTTON, static_cast<WPARAM>(nCommandControlID), static_cast<LPARAM>(bEnabled));
	Notify(TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE, static_cast<WPARAM>(nCommandControlID), static_cast<LPARAM>(bRequiresElevation));
}

BOOL CTaskDialog::IsCommandControlEnabled(_In_ int nCommandControlID) const
{
	INT_PTR nIdx = GetButtonIndex(nCommandControlID, m_aButtons);
	int nButtonFlag = GetCommonButtonFlag(nCommandControlID);

	ENSURE(nIdx != -1 || nButtonFlag & m_nCommonButton);

	if (-1 != nIdx)
	{
		return (m_aButtons[nIdx].cState & CTaskDialog::BUTTON_ENABLED ? TRUE : FALSE);
	}
	else
	{
		return (m_nButtonDisabled & nButtonFlag ? FALSE : TRUE);
	}
}

void CTaskDialog::ClickCommandControl(_In_ int nCommandControlID) const
{
	ENSURE(GetButtonIndex(nCommandControlID, m_aButtons) != -1 || GetCommonButtonFlag(nCommandControlID) & m_nCommonButton);

	Notify(TDM_CLICK_BUTTON, static_cast<WPARAM>(nCommandControlID) , 0);
}

void CTaskDialog::SetDefaultCommandControl(_In_ int nCommandControlID)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	ENSURE(GetButtonIndex(nCommandControlID, m_aButtons) != -1 || GetCommonButtonFlag(nCommandControlID) & m_nCommonButton);

	m_nDefaultCommandControl = nCommandControlID;
}

void CTaskDialog::RemoveAllCommandControls()
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_aButtons.RemoveAll();
}

void CTaskDialog::SetRadioButtonOptions(_In_ int nRadioButtonID, _In_ BOOL bEnabled)
{
	INT_PTR nIdx = GetButtonIndex(nRadioButtonID, m_aRadioButtons);
	ENSURE(nIdx != -1);

	if (bEnabled)
	{
		m_aRadioButtons[nIdx].cState |= CTaskDialog::BUTTON_ENABLED;
	}
	else
	{
		m_aRadioButtons[nIdx].cState &= ~CTaskDialog::BUTTON_ENABLED;
	}

	Notify(TDM_ENABLE_RADIO_BUTTON, static_cast<WPARAM>(nRadioButtonID), static_cast<LPARAM>(bEnabled));
}

void CTaskDialog::ClickRadioButton(_In_ int nRadioButtonID) const
{
	ENSURE(GetButtonIndex(nRadioButtonID, m_aRadioButtons) != -1);

	Notify(TDM_CLICK_RADIO_BUTTON, static_cast<WPARAM>(nRadioButtonID), 0);
}

BOOL CTaskDialog::IsRadioButtonEnabled(_In_ int nRadioButtonID) const
{
	INT_PTR nIdx = GetButtonIndex(nRadioButtonID, m_aRadioButtons);
	ENSURE(nIdx != -1);

	return (m_aRadioButtons[nIdx].cState & CTaskDialog::BUTTON_ENABLED) ? TRUE : FALSE;
}

void CTaskDialog::SetDefaultRadioButton(_In_ int nRadioButtonID)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	ENSURE(GetButtonIndex(nRadioButtonID, m_aRadioButtons) != -1);

	m_nDefaultRadioButton = nRadioButtonID;
}

void CTaskDialog::RemoveAllRadioButtons()
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	m_aRadioButtons.RemoveAll();
}

void CTaskDialog::SetVerificationCheckbox(_In_ BOOL bChecked)
{
	ENSURE(!m_strVerification.IsEmpty());

	m_bVerified = bChecked;

	if (m_bVerified)
	{
		m_nFlags |= TDF_VERIFICATION_FLAG_CHECKED;
	}
	else
	{
		m_nFlags &= ~TDF_VERIFICATION_FLAG_CHECKED;
	}

	Notify(TDM_CLICK_VERIFICATION, static_cast<WPARAM>(bChecked), 0);
}

BOOL __stdcall CTaskDialog::IsSupported()
{
	return _AfxIsTaskDialogSupported();
}

INT_PTR __stdcall CTaskDialog::ShowDialog(_In_ const CString& strContent, _In_ const CString& strMainInstruction, _In_ const CString& strTitle,
		int nIDCommandControlsFirst, _In_ int nIDCommandControlsLast,
		int nCommonButtons /* = TDCBF_YES_BUTTON | TDCBF_NO_BUTTON */,
		int nTaskDialogOptions /* = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS */,
		_In_ const CString& strFooter /* = _T("") */)
{
	CTaskDialog oTaskDialog(strContent, strMainInstruction, strTitle, nIDCommandControlsFirst, nIDCommandControlsLast, nCommonButtons, nTaskDialogOptions, strFooter);

	return oTaskDialog.DoModal();
}


void CTaskDialog::NavigateTo(_In_ CTaskDialog& oTaskDialog) const
{
	TASKDIALOGCONFIG configTaskDialog = {0};

	oTaskDialog.FillStruct(configTaskDialog);
	Notify(TDM_NAVIGATE_PAGE, 0, reinterpret_cast<LPARAM>(&configTaskDialog));
	oTaskDialog.FreeStruct(configTaskDialog);
}

void CTaskDialog::FillStruct(_Inout_ TASKDIALOGCONFIG &configTaskDialog)
{
	configTaskDialog.dwCommonButtons = m_nCommonButton;
	configTaskDialog.dwFlags = m_nFlags;

	if ((configTaskDialog.dwFlags & (TDF_USE_COMMAND_LINKS | TDF_USE_COMMAND_LINKS_NO_ICON)) && m_aButtons.IsEmpty())
	{
		configTaskDialog.dwFlags &= ~(TDF_USE_COMMAND_LINKS | TDF_USE_COMMAND_LINKS_NO_ICON);
	}

	// Ensure that there is footer field and we can set the footer icon.
	if (m_strFooter.IsEmpty() && m_footerIcon.pszIcon != NULL)
	{
		m_strFooter = _T(" ");
	}

	configTaskDialog.cxWidth = m_nWidth;

	configTaskDialog.nDefaultButton = m_nDefaultCommandControl;
	configTaskDialog.nDefaultRadioButton = m_nDefaultRadioButton;

	configTaskDialog.pszWindowTitle = m_strTitle.GetString();
	configTaskDialog.pszMainInstruction = m_strMainInstruction.GetString();
	configTaskDialog.pszContent = m_strContent.GetString();
	configTaskDialog.pszFooter = m_strFooter.GetString();

	configTaskDialog.pszExpandedInformation = m_strInformation.GetString();
	configTaskDialog.pszExpandedControlText = m_strExpand.GetString();
	configTaskDialog.pszCollapsedControlText = m_strCollapse.GetString();

	if (m_nFlags & TDF_USE_HICON_MAIN)
	{
		configTaskDialog.hMainIcon = m_mainIcon.hIcon;
	}
	else
	{
		configTaskDialog.pszMainIcon = m_mainIcon.pszIcon;
	}

	if (m_nFlags & TDF_USE_HICON_FOOTER)
	{
		configTaskDialog.hFooterIcon = m_footerIcon.hIcon;
	}
	else
	{
		configTaskDialog.pszFooterIcon = m_footerIcon.pszIcon;
	}

	if (!m_strVerification.IsEmpty())
	{
		configTaskDialog.pszVerificationText = m_strVerification.GetString();
	}
	else
	{
		configTaskDialog.dwFlags &= ~TDF_VERIFICATION_FLAG_CHECKED;
		configTaskDialog.pszVerificationText = NULL;
	}

	if (!m_aRadioButtons.IsEmpty())
	{
		configTaskDialog.pRadioButtons = GetButtonData(m_aRadioButtons);
		configTaskDialog.cRadioButtons = static_cast<UINT>(m_aRadioButtons.GetSize());
	}

	if (!m_aButtons.IsEmpty())
	{
		configTaskDialog.pButtons = GetButtonData(m_aButtons);
		configTaskDialog.cButtons = static_cast<UINT>(m_aButtons.GetSize());
	}

	configTaskDialog.lpCallbackData = reinterpret_cast<LONG_PTR>(this);
	configTaskDialog.pfCallback = TaskDialogCallback;
	configTaskDialog.cbSize =  sizeof(TASKDIALOGCONFIG);
}

void CTaskDialog::FreeStruct(_Inout_ TASKDIALOGCONFIG &configTaskDialog)
{
	if (configTaskDialog.pButtons != NULL)
	{
		delete [] configTaskDialog.pButtons;
		configTaskDialog.pButtons = NULL;
	}

	if (configTaskDialog.pRadioButtons != NULL)
	{
		delete [] configTaskDialog.pRadioButtons;
		configTaskDialog.pRadioButtons = NULL;
	}
}


int CTaskDialog::GetCommonButtonId(_In_ int nFlag) const
{
	switch(nFlag)
	{
		case TDCBF_OK_BUTTON:
			return IDOK;
		case TDCBF_YES_BUTTON:
			return IDYES;
		case TDCBF_NO_BUTTON:
			return IDNO;
		case TDCBF_CANCEL_BUTTON:
			return IDCANCEL;
		case TDCBF_RETRY_BUTTON:
			return IDRETRY;
		case TDCBF_CLOSE_BUTTON:
			return IDCLOSE;
		default:
			return 0;
	}
}

int CTaskDialog::GetCommonButtonFlag(_In_ int nButtonId) const
{
	switch(nButtonId)
	{
		case IDOK:
			return TDCBF_OK_BUTTON;
		case IDYES:
			return TDCBF_YES_BUTTON;
		case IDNO:
			return TDCBF_NO_BUTTON;
		case IDCANCEL:
			return TDCBF_CANCEL_BUTTON;
		case IDRETRY:
			return TDCBF_RETRY_BUTTON;
		case IDCLOSE:
			return TDCBF_CLOSE_BUTTON;
		default:
			return 0;
	}
}

int CTaskDialog::GetCommonButtonCount() const
{
	//it's the amount of common buttons in commctrl.h
	return 6;
}

INT_PTR CTaskDialog::GetButtonIndex(_In_ int nId, _In_ const CTaskDialogButtonArray& oButtonArr) const
{
	INT_PTR nCount = oButtonArr.GetSize();

	for(INT_PTR i = 0; i < nCount; i++)
	{
		if (oButtonArr[i].nId == nId)
		{
			return i;
		}
	}

	return -1;
}

TASKDIALOG_BUTTON* CTaskDialog::GetButtonData(_In_ const CTaskDialog::CTaskDialogButtonArray& oButtonArr) const
{
	TASKDIALOG_BUTTON *pResult = NULL;
	INT_PTR nCount = static_cast<int>(oButtonArr.GetSize());

	pResult = new TASKDIALOG_BUTTON[nCount];

	for(INT_PTR i = 0; i < nCount; i++)
	{
		pResult[i].nButtonID = oButtonArr[i].nId;
		pResult[i].pszButtonText = oButtonArr[i].strCaption.GetString();
	}

	return pResult;
}

void CTaskDialog::Notify(_In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) const
{
	if (m_hWnd != 0)
	{
		SendMessage(m_hWnd, uMsg, wParam, lParam);
	}
}

INT_PTR CTaskDialog::DoModal(_In_ HWND hParent /* = ::GetActiveWindow() */)
{
	// This option cannot be used after the window has been created.
	ENSURE(NULL == m_hWnd);

	TASKDIALOGCONFIG configTaskDialog = {0};
	configTaskDialog.hwndParent = hParent;

	FillStruct(configTaskDialog);
	HRESULT nTaskDialogResult = _AfxTaskDialogIndirect(&configTaskDialog, &m_nButtonId, &m_nRadioId, &m_bVerified);
	FreeStruct(configTaskDialog);

	if (S_OK == nTaskDialogResult)
	{
		return static_cast<INT_PTR>(m_nButtonId);
	}
	else
	{
		return -1;
	}
}

HRESULT CTaskDialog::OnInit()
{
	return S_OK;
}

HRESULT CTaskDialog::OnDestroy()
{
	return S_OK;
}

HRESULT CTaskDialog::OnCommandControlClick(_In_ int /* nButtonId */)
{
	return S_OK;
}

HRESULT CTaskDialog::OnRadioButtonClick(_In_ int /* nRadioButtonId */)
{
	return S_OK;
}

HRESULT CTaskDialog::OnVerificationCheckboxClick(_In_ BOOL /* bChecked */)
{
	return S_OK;
}

HRESULT CTaskDialog::OnExpandButtonClick(_In_ BOOL /* bExpanded */)
{
	return S_OK;
}

HRESULT CTaskDialog::OnHyperlinkClick(_In_ const CString& strHref)
{
	ShellExecute(m_hWnd,  NULL, strHref.GetString(), NULL, NULL, SW_SHOW);
	return S_OK;
}

HRESULT CTaskDialog::OnHelp()
{
	return S_FALSE;
}

HRESULT CTaskDialog::OnTimer(_In_ long /* lTime */)
{
	return S_OK;
}

HRESULT CTaskDialog::OnNavigatePage()
{
	return S_OK;
}

HRESULT CTaskDialog::OnCreate()
{
	return S_OK;
}
