// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// STDAFX.H is the header that includes the standard includes that are used
//  for most of the project.  These are compiled into a pre-compiled header

#pragma once

#include <winsdkver.h>

#undef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER

#undef NTDDI_VERSION

#include <sdkddkver.h>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes

#if defined(_M_CEE)
#include <afxwinforms.h>
#endif
