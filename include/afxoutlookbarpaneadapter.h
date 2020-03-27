// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#include "afxcontrolbarutil.h"
#include "afxdockablepaneadapter.h"

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCOutlookBarPaneAdapter window

class CMFCOutlookBarPaneAdapter : public CDockablePaneAdapter
{
	DECLARE_SERIAL(CMFCOutlookBarPaneAdapter)
// Construction
public:
	CMFCOutlookBarPaneAdapter();

// Implementation
public:
	virtual ~CMFCOutlookBarPaneAdapter();

protected:
	//{{AFX_MSG(CMFCOutlookBarPaneAdapter)
	afx_msg void OnNcDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
