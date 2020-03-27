// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#include "StdAfx.H"

#pragma warning( disable: 4073 )  // initializers put in library initialization area

namespace ATL
{

#pragma init_seg( lib )

#ifdef _DEBUG

CTraceCategory atlTraceGeneral(_T("atlTraceGeneral"));
CTraceCategory atlTraceCOM(_T("atlTraceCOM"));
CTraceCategory atlTraceQI(_T("atlTraceQI"));
CTraceCategory atlTraceRegistrar(_T("atlTraceRegistrar"));
CTraceCategory atlTraceRefcount(_T("atlTraceRefcount"));
CTraceCategory atlTraceWindowing(_T("atlTraceWindowing"));
CTraceCategory atlTraceControls(_T("atlTraceControls"));
CTraceCategory atlTraceHosting(_T("atlTraceHosting"));
CTraceCategory atlTraceDBClient(_T("atlTraceDBClient"));
CTraceCategory atlTraceDBProvider(_T("atlTraceDBProvider"));
CTraceCategory atlTraceSnapin(_T("atlTraceSnapin"));
CTraceCategory atlTraceNotImpl(_T("atlTraceNotImpl"));
CTraceCategory atlTraceAllocation(_T("atlTraceAllocation"));
CTraceCategory atlTraceException(_T("atlTraceException"));
CTraceCategory atlTraceTime(_T("atlTraceTime"));
CTraceCategory atlTraceCache(_T("atlTraceCache"));
CTraceCategory atlTraceStencil(_T("atlTraceStencil"));
CTraceCategory atlTraceString(_T("atlTraceString"));
CTraceCategory atlTraceMap(_T("atlTraceMap"));
CTraceCategory atlTraceUtil(_T("atlTraceUtil"));
CTraceCategory atlTraceSecurity(_T("atlTraceSecurity"));
CTraceCategory atlTraceSync(_T("atlTraceSync"));
CTraceCategory atlTraceISAPI(_T("atlTraceISAPI"));

#pragma warning( disable: 4995 )  // Ignore #pragma deprecated warnings
CTraceCategory atlTraceUser(_T("atlTraceUser"));
CTraceCategory atlTraceUser2(_T("atlTraceUser2"));
CTraceCategory atlTraceUser3(_T("atlTraceUser3"));
CTraceCategory atlTraceUser4(_T("atlTraceUser4"));

#endif

};  // namespace ATL
