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
#include <process.h>
#include <afxmt.h>
#include <mmsystem.h>

#include "afxsound.h"
#include "afxpopupmenu.h"

#pragma comment (lib,"winmm") // PlaySound

static int g_nSoundState = AFX_SOUND_NOT_STARTED;
static HANDLE g_hThreadSound = NULL;
static const int nThreadDelay = 5;

#pragma comment(lib, "winmm.lib")

void _cdecl AFXSoundThreadProc(LPVOID)
{
	const DWORD dwFlags = (SND_SYNC | SND_NODEFAULT | SND_ALIAS | SND_NOWAIT);
	int nIdleCount = 0;  // loop iterations since last sound played

	while (g_nSoundState != AFX_SOUND_TERMINATE)
	{
		switch (g_nSoundState)
		{
		case AFX_SOUND_MENU_COMMAND:
			::PlaySound(_T("MenuCommand"), NULL, dwFlags);
			g_nSoundState = AFX_SOUND_IDLE;
			nIdleCount = 0;
			break;

		case AFX_SOUND_MENU_POPUP:
			::PlaySound(_T("MenuPopup"), NULL, dwFlags);
			g_nSoundState = AFX_SOUND_IDLE;
			nIdleCount = 0;
			break;

		case AFX_SOUND_IDLE:
			nIdleCount++;
			break;
		}

		// We want to avoid waking up the CPU from an idle state--this wastes
		// energy/battery, so kill the thread after a period of inactivity. An
		// idle count of 2000 results in approximately 30 seconds of idle time.
		if (nIdleCount == 2000)
		{
			g_nSoundState = AFX_SOUND_TERMINATE;
		}

		::Sleep(nThreadDelay);
	}

	::PlaySound(NULL, NULL, SND_PURGE);
	g_nSoundState = AFX_SOUND_NOT_STARTED;
	g_hThreadSound = NULL;

	_endthread();
}

void AFXPlaySystemSound(int nSound)
{
	if (!CMFCPopupMenu::IsMenuSound())
	{
		return;
	}

	if (g_nSoundState == AFX_SOUND_NOT_STARTED)
	{
		if (nSound == AFX_SOUND_TERMINATE)
		{
			return;
		}

		static CCriticalSection cs;
		cs.Lock();

		ENSURE(g_hThreadSound == NULL);

		// Initialize sound thread:
		g_hThreadSound = (HANDLE) ::_beginthread(AFXSoundThreadProc, 0, NULL);
		if (g_hThreadSound > 0 && g_hThreadSound != (HANDLE) -1)
		{
			::SetThreadPriority(g_hThreadSound, THREAD_PRIORITY_BELOW_NORMAL);
			g_nSoundState = nSound;
		}
		else
		{
			g_hThreadSound = NULL;
		}

		cs.Unlock();
	}
	else
	{
		g_nSoundState = nSound;
		if (g_nSoundState == AFX_SOUND_TERMINATE)
		{
			// Terminate sound thread:
			g_hThreadSound = NULL;
		}
	}
}
