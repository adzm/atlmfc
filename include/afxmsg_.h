// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Do not include this file directly (included by AFXWIN.H)

#pragma once

/////////////////////////////////////////////////////////////////////////////

// Entries in a message map (a 'AFX_MSGMAP_ENTRY') table can be of 9 formats
//
// 1) control notification message (i.e. in response to WM_COMMAND)
//      WM_COMMAND, nNotifyCode, nControlID, nControlID, signature type, parameterless member function
//      (eg: WM_COMMAND, LBN_SELCHANGE, IDC_LISTBOX, AfxSig_vv, ... )
// 2) control notification message range (i.e. in response to WM_COMMAND)
//      WM_COMMAND, nNotifyCode, nControlIDFirst, nControlIDLast, signature type, parameterless member function
//      (eg: WM_COMMAND, LBN_SELCHANGE, IDC_LISTBOX1, IDC_LISTBOX5, AfxSig_vw, ... )
// 3) WM_NOTIFY notification
//      WM_NOTIFY, nNotifyCode, nControlID, nControlID, signature type, ...)
// 3) Update Command UI
//      -1, 0, nControlID, 0, signature Unknown, parameterless member function
// 4) Update Command UI Range
//      -1, 0, nControlIDFirst, nControlIDLast, signature Unknown, parameterless member function
// 5) menu/accelerator notification message (i.e. special case of first format)
//      WM_COMMAND, 0, nID, 0, signature type, parameterless member function
//      (eg: WM_COMMAND, 0, IDM_FILESAVE, 0, AfxSig_vv, ... )
// 6) menu/accelerator notification message range
//      WM_COMMAND, 0, nIDFirst, nIDLast, signature type, parameterless member function
//      (eg: WM_COMMAND, 0, IDM_FILE_MRU1, IDM_FILE_MRU4, AfxSig_vw, ... )
// 7) constant windows message
//      nMessage, 0, 0, 0, signature type, member function
//      (eg: WM_PAINT, 0, ...)
// 8) variable windows message (using RegisterWindowMessage)
//      0xC000, 0, 0, 0, &nMessage, special member function
//
// The end of the message map is marked with a special value
//      0, 0, AfxSig_end, 0
/////////////////////////////////////////////////////////////////////////////

// Naming scheme:
// <signature> -> AfxSig_<ReturnType>_<WPARAMType>_<LPARAMType>
// <ReturnType> -> b (BOOL)
//                 h (HANDLE)
//                 v (void)
//                 i (int)
//                 l (LRESULT)
// <WPARAMType> ->                  
// Naming scheme:
// b - BOOL
// D - CDC*
// W - CWnd*
// w - UINT
// h - handle
// i - int
// s - LPTSTR
// v - void
// l - LPARAM
// M - CMenu*
// p - CPoint
// POS - WINDOWPOS*
// CALC - NCCALCSIZE_PARAMS*
// NMHDR - NMHDR*
// HELPINFO - HELPINFO*
// SIZING - LPRECT
// cmdui - CCmdUI*
// CDS - COPYDATASTRUCT*
// s - short
// by - byte

enum AfxSig
{
	AfxSig_end = 0,     // [marks end of message map]

	AfxSig_b_D_v,				// BOOL (CDC*)
	AfxSig_b_b_v,				// BOOL (BOOL)
	AfxSig_b_u_v,				// BOOL (UINT)
	AfxSig_b_h_v,				// BOOL (HANDLE)
	AfxSig_b_W_uu,				// BOOL (CWnd*, UINT, UINT)
	AfxSig_b_W_COPYDATASTRUCT,				// BOOL (CWnd*, COPYDATASTRUCT*)
	AfxSig_b_v_HELPINFO,		// BOOL (LPHELPINFO);
	AfxSig_CTLCOLOR,			// HBRUSH (CDC*, CWnd*, UINT)
	AfxSig_CTLCOLOR_REFLECT,	// HBRUSH (CDC*, UINT)
	AfxSig_i_u_W_u,				// int (UINT, CWnd*, UINT)  // ?TOITEM
	AfxSig_i_uu_v,				// int (UINT, UINT)
	AfxSig_i_W_uu,				// int (CWnd*, UINT, UINT)
	AfxSig_i_v_s,				// int (LPTSTR)
	AfxSig_l_w_l,				// LRESULT (WPARAM, LPARAM)
	AfxSig_l_uu_M,				// LRESULT (UINT, UINT, CMenu*)
	AfxSig_v_b_h,				// void (BOOL, HANDLE)
	AfxSig_v_h_v,				// void (HANDLE)
	AfxSig_v_h_h,				// void (HANDLE, HANDLE)
	AfxSig_v_v_v,				// void ()
	AfxSig_v_u_v,				// void (UINT)
	AfxSig_v_u_u,				// void (UINT, UINT)
	AfxSig_v_uu_v,				// void (UINT, UINT)
	AfxSig_v_v_ii,				// void (int, int)
	AfxSig_v_u_uu,				// void (UINT, UINT, UINT)
	AfxSig_v_u_ii,				// void (UINT, int, int)
	AfxSig_v_u_W,				// void (UINT, CWnd*)
	AfxSig_i_u_v,				// int (UINT)
	AfxSig_u_u_v,				// UINT (UINT)
	AfxSig_b_v_v,				// BOOL ()
	AfxSig_v_w_l,				// void (WPARAM, LPARAM)
	AfxSig_MDIACTIVATE,			// void (BOOL, CWnd*, CWnd*)
	AfxSig_v_D_v,				// void (CDC*)
	AfxSig_v_M_v,				// void (CMenu*)
	AfxSig_v_M_ub,				// void (CMenu*, UINT, BOOL)
	AfxSig_v_W_v,				// void (CWnd*)
	AfxSig_v_v_W,				// void (CWnd*)
	AfxSig_v_W_uu,				// void (CWnd*, UINT, UINT)
	AfxSig_v_W_p,				// void (CWnd*, CPoint)
	AfxSig_v_W_h,				// void (CWnd*, HANDLE)
	AfxSig_C_v_v,				// HCURSOR ()
	AfxSig_ACTIVATE,			// void (UINT, CWnd*, BOOL)
	AfxSig_SCROLL,				// void (UINT, UINT, CWnd*)
	AfxSig_SCROLL_REFLECT,		// void (UINT, UINT)
	AfxSig_v_v_s,				// void (LPTSTR)
	AfxSig_v_u_cs,				// void (UINT, LPCTSTR)
	AfxSig_OWNERDRAW,			// void (int, LPTSTR) force return TRUE
	AfxSig_i_i_s,				// int (int, LPTSTR)
	AfxSig_u_v_p,				// UINT (CPoint)
	AfxSig_u_v_v,				// UINT ()
	AfxSig_v_b_NCCALCSIZEPARAMS,		// void (BOOL, NCCALCSIZE_PARAMS*)
	AfxSig_v_v_WINDOWPOS,			// void (WINDOWPOS*)
	AfxSig_v_uu_M,				// void (UINT, UINT, HMENU)
	AfxSig_v_u_p,				// void (UINT, CPoint)
	AfxSig_SIZING,				// void (UINT, LPRECT)
	AfxSig_MOUSEWHEEL,			// BOOL (UINT, short, CPoint)
	AfxSig_MOUSEHWHEEL,			// void (UINT, short, CPoint)
	AfxSigCmd_v,				// void ()
	AfxSigCmd_b,				// BOOL ()
	AfxSigCmd_RANGE,			// void (UINT)
	AfxSigCmd_EX,				// BOOL (UINT)
	AfxSigNotify_v,				// void (NMHDR*, LRESULT*)
	AfxSigNotify_b,				// BOOL (NMHDR*, LRESULT*)
	AfxSigNotify_RANGE,			// void (UINT, NMHDR*, LRESULT*)
	AfxSigNotify_EX,			// BOOL (UINT, NMHDR*, LRESULT*)
	AfxSigCmdUI,				// void (CCmdUI*)
	AfxSigCmdUI_RANGE,			// void (CCmdUI*, UINT)
	AfxSigCmd_v_pv,				// void (void*)
	AfxSigCmd_b_pv,				// BOOL (void*)
	AfxSig_l,				// LRESULT ()
	AfxSig_l_p,				// LRESULT (CPOINT)	
	AfxSig_u_W_u,				// UINT (CWnd*, UINT)
	AfxSig_v_u_M,				// void (UINT, CMenu* )
	AfxSig_u_u_M,				// UINT (UINT, CMenu* )
	AfxSig_u_v_MENUGETOBJECTINFO,		// UINT (MENUGETOBJECTINFO*)
	AfxSig_v_M_u,				// void (CMenu*, UINT)
	AfxSig_v_u_LPMDINEXTMENU,		// void (UINT, LPMDINEXTMENU)
	AfxSig_APPCOMMAND,			// void (CWnd*, UINT, UINT, UINT)
	AfxSig_RAWINPUT,			// void (UINT, HRAWINPUT)
	AfxSig_u_u_u,				// UINT (UINT, UINT)
	AfxSig_MOUSE_XBUTTON,			// void (UINT, UINT, CPoint)
	AfxSig_MOUSE_NCXBUTTON,			// void (short, UINT, CPoint)
	AfxSig_INPUTLANGCHANGE,			// void (BYTE, UINT)
	AfxSig_v_u_hkl,					// void (UINT, HKL)
	AfxSig_INPUTDEVICECHANGE,		// void (unsigned short)
// Old
	AfxSig_bD = AfxSig_b_D_v,      // BOOL (CDC*)
	AfxSig_bb = AfxSig_b_b_v,      // BOOL (BOOL)
	AfxSig_bWww = AfxSig_b_W_uu,    // BOOL (CWnd*, UINT, UINT)
	AfxSig_hDWw = AfxSig_CTLCOLOR,    // HBRUSH (CDC*, CWnd*, UINT)
	AfxSig_hDw = AfxSig_CTLCOLOR_REFLECT,     // HBRUSH (CDC*, UINT)
	AfxSig_iwWw = AfxSig_i_u_W_u,    // int (UINT, CWnd*, UINT)
	AfxSig_iww = AfxSig_i_uu_v,     // int (UINT, UINT)
	AfxSig_iWww = AfxSig_i_W_uu,    // int (CWnd*, UINT, UINT)
	AfxSig_is = AfxSig_i_v_s,      // int (LPTSTR)
	AfxSig_lwl = AfxSig_l_w_l,     // LRESULT (WPARAM, LPARAM)
	AfxSig_lwwM = AfxSig_l_uu_M,    // LRESULT (UINT, UINT, CMenu*)
	AfxSig_vv = AfxSig_v_v_v,      // void (void)

	AfxSig_vw = AfxSig_v_u_v,      // void (UINT)
	AfxSig_vww = AfxSig_v_u_u,     // void (UINT, UINT)
	AfxSig_vww2 = AfxSig_v_uu_v,    // void (UINT, UINT) // both come from wParam
	AfxSig_vvii = AfxSig_v_v_ii,    // void (int, int) // wParam is ignored
	AfxSig_vwww = AfxSig_v_u_uu,    // void (UINT, UINT, UINT)
	AfxSig_vwii = AfxSig_v_u_ii,    // void (UINT, int, int)
	AfxSig_vwl = AfxSig_v_w_l,     // void (UINT, LPARAM)
	AfxSig_vbWW = AfxSig_MDIACTIVATE,    // void (BOOL, CWnd*, CWnd*)
	AfxSig_vD = AfxSig_v_D_v,      // void (CDC*)
	AfxSig_vM = AfxSig_v_M_v,      // void (CMenu*)
	AfxSig_vMwb = AfxSig_v_M_ub,    // void (CMenu*, UINT, BOOL)

	AfxSig_vW = AfxSig_v_W_v,      // void (CWnd*)
	AfxSig_vWww = AfxSig_v_W_uu,    // void (CWnd*, UINT, UINT)
	AfxSig_vWp = AfxSig_v_W_p,     // void (CWnd*, CPoint)
	AfxSig_vWh = AfxSig_v_W_h,     // void (CWnd*, HANDLE)
	AfxSig_vwW = AfxSig_v_u_W,     // void (UINT, CWnd*)
	AfxSig_vwWb = AfxSig_ACTIVATE,    // void (UINT, CWnd*, BOOL)
	AfxSig_vwwW = AfxSig_SCROLL,    // void (UINT, UINT, CWnd*)
	AfxSig_vwwx = AfxSig_SCROLL_REFLECT,    // void (UINT, UINT)
	AfxSig_vs = AfxSig_v_v_s,      // void (LPTSTR)
	AfxSig_vOWNER = AfxSig_OWNERDRAW,  // void (int, LPTSTR), force return TRUE
	AfxSig_iis = AfxSig_i_i_s,     // int (int, LPTSTR)
	AfxSig_wp = AfxSig_u_v_p,      // UINT (CPoint)
	AfxSig_wv = AfxSig_u_v_v,      // UINT (void)
	AfxSig_vPOS = AfxSig_v_v_WINDOWPOS,    // void (WINDOWPOS*)
	AfxSig_vCALC = AfxSig_v_b_NCCALCSIZEPARAMS,   // void (BOOL, NCCALCSIZE_PARAMS*)
	AfxSig_vNMHDRpl = AfxSigNotify_v,    // void (NMHDR*, LRESULT*)
	AfxSig_bNMHDRpl = AfxSigNotify_b,    // BOOL (NMHDR*, LRESULT*)
	AfxSig_vwNMHDRpl = AfxSigNotify_RANGE,   // void (UINT, NMHDR*, LRESULT*)
	AfxSig_bwNMHDRpl = AfxSigNotify_EX,   // BOOL (UINT, NMHDR*, LRESULT*)
	AfxSig_bHELPINFO = AfxSig_b_v_HELPINFO,   // BOOL (HELPINFO*)
	AfxSig_vwSIZING = AfxSig_SIZING,    // void (UINT, LPRECT) -- return TRUE

	// signatures specific to CCmdTarget
	AfxSig_cmdui = AfxSigCmdUI,   // void (CCmdUI*)
	AfxSig_cmduiw = AfxSigCmdUI_RANGE,  // void (CCmdUI*, UINT)
	AfxSig_vpv = AfxSigCmd_v_pv,     // void (void*)
	AfxSig_bpv = AfxSigCmd_b_pv,     // BOOL (void*)

	// Other aliases (based on implementation)
	AfxSig_vwwh = AfxSig_v_uu_M,                // void (UINT, UINT, HMENU)
	AfxSig_vwp = AfxSig_v_u_p,                 // void (UINT, CPoint)
	AfxSig_bw = AfxSig_b_u_v,      // BOOL (UINT)
	AfxSig_bh = AfxSig_b_h_v,      // BOOL (HANDLE)
	AfxSig_iw = AfxSig_i_u_v,      // int (UINT)
	AfxSig_ww = AfxSig_u_u_v,      // UINT (UINT)
	AfxSig_bv = AfxSig_b_v_v,      // BOOL (void)
	AfxSig_hv = AfxSig_C_v_v,      // HANDLE (void)
	AfxSig_vb = AfxSig_vw,      // void (BOOL)
	AfxSig_vbh = AfxSig_v_b_h,    // void (BOOL, HANDLE)
	AfxSig_vbw = AfxSig_vww,    // void (BOOL, UINT)
	AfxSig_vhh = AfxSig_v_h_h,    // void (HANDLE, HANDLE)
	AfxSig_vh = AfxSig_v_h_v,      // void (HANDLE)
	AfxSig_viSS = AfxSig_vwl,   // void (int, STYLESTRUCT*)
	AfxSig_bwl = AfxSig_lwl,
	AfxSig_vwMOVING = AfxSig_vwSIZING,  // void (UINT, LPRECT) -- return TRUE

	AfxSig_vW2 = AfxSig_v_v_W,                 // void (CWnd*) (CWnd* comes from lParam)
	AfxSig_bWCDS = AfxSig_b_W_COPYDATASTRUCT,               // BOOL (CWnd*, COPYDATASTRUCT*)
	AfxSig_bwsp = AfxSig_MOUSEWHEEL,                // BOOL (UINT, short, CPoint)
	AfxSig_vws = AfxSig_v_u_cs,
};

/////////////////////////////////////////////////////////////////////////////
// Command notifications for CCmdTarget notifications

#define CN_COMMAND              0               // void ()
#define CN_UPDATE_COMMAND_UI    ((UINT)(-1))    // void (CCmdUI*)
#define CN_EVENT                ((UINT)(-2))    // OLE event
#define CN_OLECOMMAND           ((UINT)(-3))    // OLE document command
#define CN_OLE_UNREGISTER       ((UINT)(-4))    // OLE unregister
// > 0 are control notifications
// < 0 are for MFC's use

#define ON_COMMAND(id, memberFxn) \
	{ WM_COMMAND, CN_COMMAND, (WORD)id, (WORD)id, AfxSigCmd_v, \
		static_cast<AFX_PMSG> (memberFxn) },
		// ON_COMMAND(id, OnBar) is the same as
		//   ON_CONTROL(0, id, OnBar) or ON_BN_CLICKED(0, id, OnBar)

#define ON_COMMAND_RANGE(id, idLast, memberFxn) \
	{ WM_COMMAND, CN_COMMAND, (WORD)id, (WORD)idLast, AfxSigCmd_RANGE, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(UINT) > \
		(memberFxn)) },
		// ON_COMMAND_RANGE(id, idLast, OnBar) is the same as
		//   ON_CONTROL_RANGE(0, id, idLast, OnBar)

#define ON_COMMAND_EX(id, memberFxn) \
	{ WM_COMMAND, CN_COMMAND, (WORD)id, (WORD)id, AfxSigCmd_EX, \
		(AFX_PMSG) \
		(static_cast< BOOL (AFX_MSG_CALL CCmdTarget::*)(UINT) > \
		(memberFxn)) },

#define ON_COMMAND_EX_RANGE(id, idLast, memberFxn) \
	{ WM_COMMAND, CN_COMMAND, (WORD)id, (WORD)idLast, AfxSigCmd_EX, \
		(AFX_PMSG) \
		(static_cast< BOOL (AFX_MSG_CALL CCmdTarget::*)(UINT) > \
		(memberFxn)) },

// update ui's are listed as WM_COMMAND's so they get routed like commands
#define ON_UPDATE_COMMAND_UI(id, memberFxn) \
	{ WM_COMMAND, CN_UPDATE_COMMAND_UI, (WORD)id, (WORD)id, AfxSigCmdUI, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(CCmdUI*) > \
		(memberFxn)) },

#define ON_UPDATE_COMMAND_UI_RANGE(id, idLast, memberFxn) \
	{ WM_COMMAND, CN_UPDATE_COMMAND_UI, (WORD)id, (WORD)idLast, AfxSigCmdUI, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(CCmdUI*) > \
		(memberFxn)) },

#define ON_NOTIFY(wNotifyCode, id, memberFxn) \
	{ WM_NOTIFY, (WORD)(int)wNotifyCode, (WORD)id, (WORD)id, AfxSigNotify_v, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(NMHDR*, LRESULT*) > \
		(memberFxn)) },

#define ON_NOTIFY_RANGE(wNotifyCode, id, idLast, memberFxn) \
	{ WM_NOTIFY, (WORD)(int)wNotifyCode, (WORD)id, (WORD)idLast, AfxSigNotify_RANGE, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(UINT, NMHDR*, LRESULT*) > \
		(memberFxn)) },

#define ON_NOTIFY_EX(wNotifyCode, id, memberFxn) \
	{ WM_NOTIFY, (WORD)(int)wNotifyCode, (WORD)id, (WORD)id, AfxSigNotify_EX, \
		(AFX_PMSG) \
		(static_cast< BOOL (AFX_MSG_CALL CCmdTarget::*)(UINT, NMHDR*, LRESULT*) > \
		(memberFxn)) },

#define ON_NOTIFY_EX_RANGE(wNotifyCode, id, idLast, memberFxn) \
	{ WM_NOTIFY, (WORD)(int)wNotifyCode, (WORD)id, (WORD)idLast, AfxSigNotify_EX, \
		(AFX_PMSG) \
		(static_cast< BOOL (AFX_MSG_CALL CCmdTarget::*)(UINT, NMHDR*, LRESULT*) > \
		(memberFxn)) },

// for general controls
#define ON_CONTROL(wNotifyCode, id, memberFxn) \
	{ WM_COMMAND, (WORD)wNotifyCode, (WORD)id, (WORD)id, AfxSigCmd_v, \
		(static_cast< AFX_PMSG > (memberFxn)) },

#define ON_CONTROL_RANGE(wNotifyCode, id, idLast, memberFxn) \
	{ WM_COMMAND, (WORD)wNotifyCode, (WORD)id, (WORD)idLast, AfxSigCmd_RANGE, \
		(AFX_PMSG) \
		(static_cast< void (AFX_MSG_CALL CCmdTarget::*)(UINT) > (memberFxn)) },

#define WM_REFLECT_BASE 0xBC00

// for control notification reflection
#define ON_CONTROL_REFLECT(wNotifyCode, memberFxn) \
	{ WM_COMMAND+WM_REFLECT_BASE, (WORD)wNotifyCode, 0, 0, AfxSigCmd_v, \
		(static_cast<AFX_PMSG> (memberFxn)) },

#define ON_CONTROL_REFLECT_EX(wNotifyCode, memberFxn) \
	{ WM_COMMAND+WM_REFLECT_BASE, (WORD)wNotifyCode, 0, 0, AfxSigCmd_b, \
		(AFX_PMSG) \
		(static_cast<BOOL (AFX_MSG_CALL CCmdTarget::*)(void)> (memberFxn)) },

#define ON_NOTIFY_REFLECT(wNotifyCode, memberFxn) \
	{ WM_NOTIFY+WM_REFLECT_BASE, (WORD)(int)wNotifyCode, 0, 0, AfxSigNotify_v, \
		(AFX_PMSG) \
		(static_cast<void (AFX_MSG_CALL CCmdTarget::*)(NMHDR*, LRESULT*) > \
		(memberFxn)) },

#define ON_NOTIFY_REFLECT_EX(wNotifyCode, memberFxn) \
	{ WM_NOTIFY+WM_REFLECT_BASE, (WORD)(int)wNotifyCode, 0, 0, AfxSigNotify_b, \
		(AFX_PMSG) \
		(static_cast<BOOL (AFX_MSG_CALL CCmdTarget::*)(NMHDR*, LRESULT*) > \
		(memberFxn)) },

#define ON_UPDATE_COMMAND_UI_REFLECT(memberFxn) \
	{ WM_COMMAND+WM_REFLECT_BASE, (WORD)CN_UPDATE_COMMAND_UI, 0, 0, AfxSigCmdUI, \
		(AFX_PMSG) \
		(static_cast<void (AFX_MSG_CALL CCmdTarget::*)(CCmdUI*) > \
		(memberFxn)) },

/////////////////////////////////////////////////////////////////////////////
// Message map tables for Windows messages

#define ON_WM_CREATE() \
	{ WM_CREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG) (AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT) > ( &ThisClass :: OnCreate)) },

#define ON_WM_COPYDATA() \
	{ WM_COPYDATA, 0, 0, 0, AfxSig_bWCDS, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(CWnd*, COPYDATASTRUCT*) > ( &ThisClass :: OnCopyData)) },

#define ON_WM_DESTROY() \
	{ WM_DESTROY, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnDestroy)) },

#define ON_WM_MOVE() \
	{ WM_MOVE, 0, 0, 0, AfxSig_vvii, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, int) > ( &ThisClass :: OnMove)) },

#define ON_WM_SIZE() \
	{ WM_SIZE, 0, 0, 0, AfxSig_vwii, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, int, int) > ( &ThisClass :: OnSize)) },

#define ON_WM_ACTIVATE() \
	{ WM_ACTIVATE, 0, 0, 0, AfxSig_vwWb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*, BOOL) > ( &ThisClass :: OnActivate)) },

#define ON_WM_SETFOCUS() \
	{ WM_SETFOCUS, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*) > ( &ThisClass :: OnSetFocus)) },

#define ON_WM_KILLFOCUS() \
	{ WM_KILLFOCUS, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*) > ( &ThisClass :: OnKillFocus)) },

#define ON_WM_ENABLE() \
	{ WM_ENABLE, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnEnable)) },

#define ON_WM_HELPINFO() \
	{ WM_HELP, 0, 0, 0, AfxSig_bHELPINFO, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(HELPINFO*) > ( &ThisClass :: OnHelpInfo)) },

#define ON_WM_PAINT() \
	{ WM_PAINT, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnPaint)) },

#define ON_WM_SYNCPAINT() \
	{ WM_SYNCPAINT, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnSyncPaint)) },

#define ON_WM_CLOSE() \
	{ WM_CLOSE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnClose)) },

#define ON_WM_QUERYENDSESSION() \
	{ WM_QUERYENDSESSION, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryEndSession)) },

#define ON_WM_QUERYOPEN() \
	{ WM_QUERYOPEN, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryOpen)) },

#define ON_WM_ERASEBKGND() \
	{ WM_ERASEBKGND, 0, 0, 0, AfxSig_bD, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(CDC*) > ( &ThisClass :: OnEraseBkgnd)) },

#define ON_WM_SYSCOLORCHANGE() \
	{ WM_SYSCOLORCHANGE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnSysColorChange)) },

#define ON_WM_ENDSESSION() \
	{ WM_ENDSESSION, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnEndSession)) },

#if(_WIN32_WINNT >= 0x0501)

#define ON_WM_WTSSESSION_CHANGE() \
	{ WM_WTSSESSION_CHANGE, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnSessionChange)) },

#else

#define ON_WM_WTSSESSION_CHANGE() \
	__pragma(message("WM_WTSSESSION_CHANGE requires _WIN32_WINNT to be >= 0x501")) \
	{ WM_WTSSESSION_CHANGE, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnSessionChange)) },

#endif

#define ON_WM_SHOWWINDOW() \
	{ WM_SHOWWINDOW, 0, 0, 0, AfxSig_vbw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL, UINT) > ( &ThisClass :: OnShowWindow)) },

#define ON_WM_CTLCOLOR() \
	{ WM_CTLCOLOR, 0, 0, 0, AfxSig_hDWw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< HBRUSH (AFX_MSG_CALL CWnd::*)(CDC*, CWnd*, UINT)>  ( &ThisClass :: OnCtlColor)) },

#define ON_WM_CTLCOLOR_REFLECT() \
	{ WM_CTLCOLOR+WM_REFLECT_BASE, 0, 0, 0, AfxSig_hDw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< HBRUSH (AFX_MSG_CALL CWnd::*)(CDC*, UINT) > ( &ThisClass :: CtlColor)) },

#define ON_WM_SETTINGCHANGE() \
	{ WM_SETTINGCHANGE, 0, 0, 0, AfxSig_vws, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPCTSTR) > ( &ThisClass :: OnSettingChange)) },

#define ON_WM_WININICHANGE() \
	{ WM_WININICHANGE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(LPCTSTR) > ( &ThisClass :: OnWinIniChange)) },

#define ON_WM_DEVMODECHANGE() \
	{ WM_DEVMODECHANGE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(LPTSTR) > ( &ThisClass :: OnDevModeChange)) },

#define ON_WM_ACTIVATEAPP() \
	{ WM_ACTIVATEAPP, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL, DWORD) > ( &ThisClass :: OnActivateApp)) },

#define ON_WM_FONTCHANGE() \
	{ WM_FONTCHANGE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnFontChange)) },

#define ON_WM_TIMECHANGE() \
	{ WM_TIMECHANGE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnTimeChange)) },

#define ON_WM_CANCELMODE() \
	{ WM_CANCELMODE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnCancelMode)) },

#define ON_WM_SETCURSOR() \
	{ WM_SETCURSOR, 0, 0, 0, AfxSig_bWww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT) > ( &ThisClass :: OnSetCursor)) },

#define ON_WM_MOUSEACTIVATE() \
	{ WM_MOUSEACTIVATE, 0, 0, 0, AfxSig_iWww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT) > ( &ThisClass :: OnMouseActivate)) },

#define ON_WM_CHILDACTIVATE() \
	{ WM_CHILDACTIVATE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnChildActivate)) },

#define ON_WM_GETMINMAXINFO() \
	{ WM_GETMINMAXINFO, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(MINMAXINFO*) > ( &ThisClass :: OnGetMinMaxInfo)) },

#define ON_WM_ICONERASEBKGND() \
	{ WM_ICONERASEBKGND, 0, 0, 0, AfxSig_vD, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CDC*) > ( &ThisClass :: OnIconEraseBkgnd)) },

#define ON_WM_SPOOLERSTATUS() \
	{ WM_SPOOLERSTATUS, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnSpoolerStatus)) },

#define ON_WM_DRAWITEM() \
	{ WM_DRAWITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, LPDRAWITEMSTRUCT) > ( &ThisClass :: OnDrawItem)) },

#define ON_WM_DRAWITEM_REFLECT() \
	{ WM_DRAWITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(LPDRAWITEMSTRUCT) > ( &ThisClass :: DrawItem)) },

#define ON_WM_MEASUREITEM() \
	{ WM_MEASUREITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, LPMEASUREITEMSTRUCT) > ( &ThisClass :: OnMeasureItem)) },

#define ON_WM_MEASUREITEM_REFLECT() \
	{ WM_MEASUREITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(LPMEASUREITEMSTRUCT) > ( &ThisClass :: MeasureItem)) },

#define ON_WM_DELETEITEM() \
	{ WM_DELETEITEM, 0, 0, 0, AfxSig_vOWNER, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, LPDELETEITEMSTRUCT) > ( &ThisClass :: OnDeleteItem)) },

#define ON_WM_DELETEITEM_REFLECT() \
	{ WM_DELETEITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vs, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(LPDELETEITEMSTRUCT) > ( &ThisClass :: DeleteItem)) },

#define ON_WM_CHARTOITEM() \
	{ WM_CHARTOITEM, 0, 0, 0, AfxSig_iwWw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(UINT, CListBox*, UINT) > ( &ThisClass :: OnCharToItem)) },

#define ON_WM_CHARTOITEM_REFLECT() \
	{ WM_CHARTOITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_iww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: CharToItem)) },

#define ON_WM_VKEYTOITEM() \
	{ WM_VKEYTOITEM, 0, 0, 0, AfxSig_iwWw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(UINT, CListBox*, UINT) > ( &ThisClass :: OnVKeyToItem)) },

#define ON_WM_VKEYTOITEM_REFLECT() \
	{ WM_VKEYTOITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_iww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: VKeyToItem)) },

#define ON_WM_QUERYDRAGICON() \
	{ WM_QUERYDRAGICON, 0, 0, 0, AfxSig_hv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< HCURSOR (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryDragIcon)) },

#define ON_WM_COMPAREITEM() \
	{ WM_COMPAREITEM, 0, 0, 0, AfxSig_iis, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(int, LPCOMPAREITEMSTRUCT) > ( &ThisClass :: OnCompareItem)) },

#define ON_WM_COMPAREITEM_REFLECT() \
	{ WM_COMPAREITEM+WM_REFLECT_BASE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< int (AFX_MSG_CALL CWnd::*)(LPCOMPAREITEMSTRUCT) > ( &ThisClass :: CompareItem)) },

#define ON_WM_COMPACTING() \
	{ WM_COMPACTING, 0, 0, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT) > ( &ThisClass :: OnCompacting)) },

#define ON_WM_NCCREATE() \
	{ WM_NCCREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT) > ( &ThisClass :: OnNcCreate)) },

#define ON_WM_NCDESTROY() \
	{ WM_NCDESTROY, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnNcDestroy)) },

#define ON_WM_NCCALCSIZE() \
	{ WM_NCCALCSIZE, 0, 0, 0, AfxSig_vCALC, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL, NCCALCSIZE_PARAMS*) > ( &ThisClass :: OnNcCalcSize)) },

#define ON_WM_NCHITTEST() \
	{ WM_NCHITTEST, 0, 0, 0, AfxSig_l_p, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(CPoint) > (&ThisClass :: OnNcHitTest)) },

#define ON_WM_NCPAINT() \
	{ WM_NCPAINT, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnNcPaint)) },

#define ON_WM_NCACTIVATE() \
	{ WM_NCACTIVATE, 0, 0, 0, AfxSig_bb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnNcActivate)) },

#define ON_WM_GETDLGCODE() \
	{ WM_GETDLGCODE, 0, 0, 0, AfxSig_wv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnGetDlgCode)) },

#define ON_WM_NCMOUSEMOVE() \
	{ WM_NCMOUSEMOVE, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcMouseMove)) },

#define ON_WM_NCMOUSEHOVER() \
	{ WM_NCMOUSEHOVER, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcMouseHover)) },

#define ON_WM_NCMOUSELEAVE() \
	{ WM_NCMOUSELEAVE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnNcMouseLeave)) },

#define ON_WM_NCLBUTTONDOWN() \
	{ WM_NCLBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcLButtonDown)) },

#define ON_WM_NCLBUTTONUP() \
	{ WM_NCLBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcLButtonUp)) },

#define ON_WM_NCLBUTTONDBLCLK() \
	{ WM_NCLBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcLButtonDblClk)) },

#define ON_WM_NCRBUTTONDOWN() \
	{ WM_NCRBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcRButtonDown)) },

#define ON_WM_NCRBUTTONUP() \
	{ WM_NCRBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcRButtonUp)) },

#define ON_WM_NCRBUTTONDBLCLK() \
	{ WM_NCRBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcRButtonDblClk)) },

#define ON_WM_NCMBUTTONDOWN() \
	{ WM_NCMBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcMButtonDown)) },

#define ON_WM_NCMBUTTONUP() \
	{ WM_NCMBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcMButtonUp)) },

#define ON_WM_NCMBUTTONDBLCLK() \
	{ WM_NCMBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnNcMButtonDblClk)) },

#if(_WIN32_WINNT >= 0x0500)

#define ON_WM_NCXBUTTONDOWN() \
	{ WM_NCXBUTTONDOWN, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonDown)) },

#define ON_WM_NCXBUTTONUP() \
	{ WM_NCXBUTTONUP, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonUp)) },

#define ON_WM_NCXBUTTONDBLCLK() \
	{ WM_NCXBUTTONDBLCLK, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonDblClk)) },

#else

#define ON_WM_NCXBUTTONDOWN() \
	__pragma(message("WM_NCXBUTTONDOWN requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_NCXBUTTONDOWN, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonDown)) },

#define ON_WM_NCXBUTTONUP() \
	__pragma(message("WM_NCXBUTTONUP requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_NCXBUTTONUP, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonUp)) },

#define ON_WM_NCXBUTTONDBLCLK() \
	__pragma(message("WM_NCXBUTTONDBLCLK requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_NCXBUTTONDBLCLK, 0, 0, 0, AfxSig_MOUSE_NCXBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(short, UINT, CPoint) > ( &ThisClass :: OnNcXButtonDblClk)) },

#endif

#define ON_WM_KEYDOWN() \
	{ WM_KEYDOWN, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnKeyDown)) },

#define ON_WM_KEYUP() \
	{ WM_KEYUP, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnKeyUp)) },

#define ON_WM_HOTKEY() \
	{ WM_HOTKEY, 0, 0, 0, AfxSig_v_u_uu, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnHotKey)) },

#define ON_WM_CHAR() \
	{ WM_CHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnChar)) },

#if(_WIN32_WINNT >= 0x0501)

#define ON_WM_UNICHAR() \
	{ WM_UNICHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnUniChar)) },

#else

#define ON_WM_UNICHAR() \
	__pragma(message("WM_UNICHAR requires _WIN32_WINNT to be >= 0x501")) \
	{ WM_UNICHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnUniChar)) },

#endif

#define ON_WM_DEADCHAR() \
	{ WM_DEADCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnDeadChar)) },

#define ON_WM_SYSKEYDOWN() \
	{ WM_SYSKEYDOWN, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnSysKeyDown)) },

#define ON_WM_SYSKEYUP() \
	{ WM_SYSKEYUP, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnSysKeyUp)) },

#define ON_WM_SYSCHAR() \
	{ WM_SYSCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast<void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnSysChar)) },

#define ON_WM_SYSDEADCHAR() \
	{ WM_SYSDEADCHAR, 0, 0, 0, AfxSig_vwww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, UINT) > ( &ThisClass :: OnSysDeadChar)) },

#define ON_WM_SYSCOMMAND() \
	{ WM_SYSCOMMAND, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM) > ( &ThisClass :: OnSysCommand)) },

#define ON_WM_INPUTLANGCHANGE() \
	{ WM_INPUTLANGCHANGE, 0, 0, 0, AfxSig_INPUTLANGCHANGE, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BYTE, UINT) > ( &ThisClass :: OnInputLangChange)) },

#define ON_WM_INPUTLANGCHANGEREQUEST() \
	{ WM_INPUTLANGCHANGEREQUEST, 0, 0, 0, AfxSig_v_u_hkl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, HKL) > ( &ThisClass :: OnInputLangChangeRequest)) },

#if(_WIN32_WINNT >= 0x0500)

#define ON_WM_APPCOMMAND() \
	{ WM_APPCOMMAND, 0, 0, 0, AfxSig_APPCOMMAND, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT, UINT) > ( &ThisClass :: OnAppCommand)) },

#else

#define ON_WM_APPCOMMAND() \
	__pragma(message("WM_APPCOMMAND requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_APPCOMMAND, 0, 0, 0, AfxSig_APPCOMMAND, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT, UINT) > ( &ThisClass :: OnAppCommand)) },

#endif

#if(_WIN32_WINNT >= 0x0501)

#define ON_WM_INPUT() \
	{ WM_INPUT, 0, 0, 0, AfxSig_RAWINPUT, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, HRAWINPUT) > ( &ThisClass :: OnRawInput)) },

#else

#define ON_WM_INPUT() \
	__pragma(message("WM_INPUT requires _WIN32_WINNT to be >= 0x501")) \
	{ WM_INPUT, 0, 0, 0, AfxSig_RAWINPUT, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, HRAWINPUT) > ( &ThisClass :: OnRawInput)) },

#endif /* _WIN32_WINNT >= 0x0501 */

#if(_WIN32_WINNT >= 0x0600)

#define ON_WM_INPUT_DEVICE_CHANGE() \
	{ WM_INPUT_DEVICE_CHANGE, 0, 0, 0, AfxSig_INPUTDEVICECHANGE, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(unsigned short) > ( &ThisClass :: OnInputDeviceChange)) },

#else

#define ON_WM_INPUT_DEVICE_CHANGE() \
	__pragma(message("WM_INPUT_DEVICE_CHANGE requires _WIN32_WINNT to be >= 0x600")) \
	{ WM_INPUT_DEVICE_CHANGE, 0, 0, 0, AfxSig_INPUTDEVICECHANGE, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(unsigned short) > ( &ThisClass :: OnInputDeviceChange)) },

#endif /* _WIN32_WINNT >= 0x0600 */

#define ON_WM_TCARD() \
	{ WM_TCARD, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, DWORD) > ( &ThisClass :: OnTCard)) },

#define ON_WM_TIMER() \
	{ WM_TIMER, 0, 0, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT_PTR) > ( &ThisClass :: OnTimer)) },

#define ON_WM_HSCROLL() \
	{ WM_HSCROLL, 0, 0, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*) > ( &ThisClass :: OnHScroll)) },

#define ON_WM_HSCROLL_REFLECT() \
	{ WM_HSCROLL+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vwwx, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: HScroll)) },

#define ON_WM_VSCROLL() \
	{ WM_VSCROLL, 0, 0, 0, AfxSig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CScrollBar*) > ( &ThisClass :: OnVScroll)) },

#define ON_WM_VSCROLL_REFLECT() \
	{ WM_VSCROLL+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vwwx, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: VScroll)) },

#define ON_WM_INITMENU() \
	{ WM_INITMENU, 0, 0, 0, AfxSig_vM, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CMenu*) > ( &ThisClass :: OnInitMenu)) },

#define ON_WM_INITMENUPOPUP() \
	{ WM_INITMENUPOPUP, 0, 0, 0, AfxSig_vMwb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CMenu*, UINT, BOOL) > ( &ThisClass :: OnInitMenuPopup)) },

#define ON_WM_MENUSELECT() \
	{ WM_MENUSELECT, 0, 0, 0, AfxSig_vwwh, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, HMENU) > ( &ThisClass :: OnMenuSelect)) },

#define ON_WM_MENUCHAR() \
	{ WM_MENUCHAR, 0, 0, 0, AfxSig_lwwM, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(UINT, UINT, CMenu*) > ( &ThisClass :: OnMenuChar)) },

#if(WINVER >= 0x0500)

#define ON_WM_MENURBUTTONUP() \
	{ WM_MENURBUTTONUP, 0, 0, 0, AfxSig_v_u_M, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CMenu*) > ( &ThisClass :: OnMenuRButtonUp)) },

#else

#define ON_WM_MENURBUTTONUP() \
	__pragma(message("WM_MENURBUTTONUP requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_MENURBUTTONUP, 0, 0, 0, AfxSig_v_u_M, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CMenu*) > ( &ThisClass :: OnMenuRButtonUp)) },

#endif

#define ON_WM_MENUDRAG() \
	{ WM_MENUDRAG, 0, 0, 0, AfxSig_u_u_M, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(UINT, CMenu*) > ( &ThisClass :: OnMenuDrag)) },

#define ON_WM_MENUGETOBJECT() \
	{ WM_MENUGETOBJECT, 0, 0, 0, AfxSig_u_v_MENUGETOBJECTINFO, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(MENUGETOBJECTINFO*) > ( &ThisClass :: OnMenuGetObject)) },

#define ON_WM_UNINITMENUPOPUP() \
	{ WM_UNINITMENUPOPUP, 0, 0, 0, AfxSig_v_M_u, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CMenu*, UINT) > ( &ThisClass :: OnUnInitMenuPopup)) },

#define ON_WM_NEXTMENU() \
	{ WM_NEXTMENU, 0, 0, 0, AfxSig_v_u_LPMDINEXTMENU, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPMDINEXTMENU) > ( &ThisClass :: OnNextMenu)) },

#define ON_WM_ENTERIDLE() \
	{ WM_ENTERIDLE, 0, 0, 0, AfxSig_vwW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CWnd*) > ( &ThisClass :: OnEnterIdle)) },

#define ON_WM_MOUSEMOVE() \
	{ WM_MOUSEMOVE, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnMouseMove)) },

#define ON_WM_MOUSEHOVER() \
	{ WM_MOUSEHOVER, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnMouseHover)) },

#define ON_WM_MOUSELEAVE() \
	{ WM_MOUSELEAVE, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnMouseLeave)) },

#define ON_WM_MOUSEWHEEL() \
	{ WM_MOUSEWHEEL, 0, 0, 0, AfxSig_bwsp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(UINT, short, CPoint) > ( &ThisClass :: OnMouseWheel)) },

#if (_WIN32_WINNT >= 0x0600)

#define ON_WM_MOUSEHWHEEL() \
	{ WM_MOUSEHWHEEL, 0, 0, 0, AfxSig_MOUSEHWHEEL, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, short, CPoint) > ( &ThisClass :: OnMouseHWheel)) },

#else

#define ON_WM_MOUSEHWHEEL() \
	__pragma(message("WM_MOUSEHWHEEL requires _WIN32_WINNT to be >= 0x600")) \
	{ WM_MOUSEHWHEEL, 0, 0, 0, AfxSig_MOUSEHWHEEL, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, short, CPoint) > ( &ThisClass :: OnMouseHWheel)) },

#endif

#define ON_WM_LBUTTONDOWN() \
	{ WM_LBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnLButtonDown)) },

#define ON_WM_LBUTTONUP() \
	{ WM_LBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnLButtonUp)) },

#define ON_WM_LBUTTONDBLCLK() \
	{ WM_LBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnLButtonDblClk)) },

#define ON_WM_RBUTTONDOWN() \
	{ WM_RBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnRButtonDown)) },

#define ON_WM_RBUTTONUP() \
	{ WM_RBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnRButtonUp)) },

#define ON_WM_RBUTTONDBLCLK() \
	{ WM_RBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnRButtonDblClk)) },

#define ON_WM_MBUTTONDOWN() \
	{ WM_MBUTTONDOWN, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnMButtonDown)) },

#define ON_WM_MBUTTONUP() \
	{ WM_MBUTTONUP, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnMButtonUp)) },

#define ON_WM_MBUTTONDBLCLK() \
	{ WM_MBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > ( &ThisClass :: OnMButtonDblClk)) },

#if (_WIN32_WINNT >= 0x0500)

#define ON_WM_XBUTTONDOWN() \
	{ WM_XBUTTONDOWN, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonDown)) },

#define ON_WM_XBUTTONUP() \
	{ WM_XBUTTONUP, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonUp)) },

#define ON_WM_XBUTTONDBLCLK() \
	{ WM_XBUTTONDBLCLK, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonDblClk)) },

#else

#define ON_WM_XBUTTONDOWN() \
	__pragma(message("WM_XBUTTONDOWN requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_XBUTTONDOWN, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonDown)) },

#define ON_WM_XBUTTONUP() \
	__pragma(message("WM_XBUTTONUP requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_XBUTTONUP, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonUp)) },

#define ON_WM_XBUTTONDBLCLK() \
	__pragma(message("WM_XBUTTONDBLCLK requires _WIN32_WINNT to be >= 0x500")) \
	{ WM_XBUTTONDBLCLK, 0, 0, 0, AfxSig_MOUSE_XBUTTON, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT, CPoint) > ( &ThisClass :: OnXButtonDblClk)) },

#endif

#define ON_WM_PARENTNOTIFY() \
	{ WM_PARENTNOTIFY, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast<void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM) > ( &ThisClass :: OnParentNotify)) },

#define ON_WM_PARENTNOTIFY_REFLECT() \
	{ WM_PARENTNOTIFY+WM_REFLECT_BASE, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPARAM) > ( &ThisClass :: ParentNotify)) },

#define ON_WM_NOTIFYFORMAT() \
	{ WM_NOTIFYFORMAT, 0, 0, 0, AfxSig_u_W_u, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(CWnd*, UINT) > ( &ThisClass :: OnNotifyFormat)) },

#define ON_WM_MDIACTIVATE() \
	{ WM_MDIACTIVATE, 0, 0, 0, AfxSig_vbWW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL, CWnd*, CWnd*) > ( &ThisClass :: OnMDIActivate)) },
#define ON_WM_RENDERFORMAT() \
	{ WM_RENDERFORMAT, 0, 0, 0, AfxSig_vw, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT) > ( &ThisClass :: OnRenderFormat)) },

#define ON_WM_RENDERALLFORMATS() \
	{ WM_RENDERALLFORMATS, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnRenderAllFormats)) },

#define ON_WM_DESTROYCLIPBOARD() \
	{ WM_DESTROYCLIPBOARD, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnDestroyClipboard)) },

#define ON_WM_DRAWCLIPBOARD() \
	{ WM_DRAWCLIPBOARD, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnDrawClipboard)) },

#define ON_WM_PAINTCLIPBOARD() \
	{ WM_PAINTCLIPBOARD, 0, 0, 0, AfxSig_vWh, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, HGLOBAL) > ( &ThisClass :: OnPaintClipboard)) },

#define ON_WM_VSCROLLCLIPBOARD() \
	{ WM_VSCROLLCLIPBOARD, 0, 0, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT) > ( &ThisClass :: OnVScrollClipboard)) },

#define ON_WM_CONTEXTMENU() \
	{ WM_CONTEXTMENU, 0, 0, 0, AfxSig_vWp, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, CPoint) > ( &ThisClass :: OnContextMenu)) },

#define ON_WM_SIZECLIPBOARD() \
	{ WM_SIZECLIPBOARD, 0, 0, 0, AfxSig_vWh, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, HGLOBAL)> ( &ThisClass :: OnSizeClipboard)) },

#define ON_WM_ASKCBFORMATNAME() \
	{ WM_ASKCBFORMATNAME, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPTSTR) > ( &ThisClass :: OnAskCbFormatName)) },

#define ON_WM_CHANGECBCHAIN() \
	{ WM_CHANGECBCHAIN, 0, 0, 0, AfxSig_vhh, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(HWND, HWND) > ( &ThisClass :: OnChangeCbChain)) },

#define ON_WM_HSCROLLCLIPBOARD() \
	{ WM_HSCROLLCLIPBOARD, 0, 0, 0, AfxSig_vWww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*, UINT, UINT) > ( &ThisClass :: OnHScrollClipboard)) },

#if(_WIN32_WINNT >= 0x0600)

#define ON_WM_CLIPBOARDUPDATE() \
	{ WM_CLIPBOARDUPDATE, 0, 0, 0, AfxSig_v_v_v, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnClipboardUpdate)) },

#else

#define ON_WM_CLIPBOARDUPDATE() \
	__pragma(message("WM_CLIPBOARDUPDATE requires _WIN32_WINNT to be >= 0x0600")) \
	{ WM_CLIPBOARDUPDATE, 0, 0, 0, AfxSig_v_v_v, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnClipboardUpdate)) },

#endif /* _WIN32_WINNT >= 0x0600 */

#define ON_WM_QUERYNEWPALETTE() \
	{ WM_QUERYNEWPALETTE, 0, 0, 0, AfxSig_bv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryNewPalette)) },

#define ON_WM_PALETTECHANGED() \
	{ WM_PALETTECHANGED, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*) > ( &ThisClass :: OnPaletteChanged)) },

#define ON_WM_PALETTEISCHANGING() \
	{ WM_PALETTEISCHANGING, 0, 0, 0, AfxSig_vW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*) > ( &ThisClass :: OnPaletteIsChanging)) },

#define ON_WM_DROPFILES() \
	{ WM_DROPFILES, 0, 0, 0, AfxSig_vh, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(HDROP) > ( &ThisClass :: OnDropFiles)) },

#define ON_WM_WINDOWPOSCHANGING() \
	{ WM_WINDOWPOSCHANGING, 0, 0, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(WINDOWPOS*) > ( &ThisClass :: OnWindowPosChanging)) },

#define ON_WM_WINDOWPOSCHANGED() \
	{ WM_WINDOWPOSCHANGED, 0, 0, 0, AfxSig_vPOS, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(WINDOWPOS*) > ( &ThisClass :: OnWindowPosChanged)) },

#define ON_WM_EXITMENULOOP() \
	{ WM_EXITMENULOOP, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnExitMenuLoop)) },

#define ON_WM_ENTERMENULOOP() \
	{ WM_ENTERMENULOOP, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnEnterMenuLoop)) },

#define ON_WM_STYLECHANGED() \
	{ WM_STYLECHANGED, 0, 0, 0, AfxSig_viSS, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, LPSTYLESTRUCT) > ( &ThisClass :: OnStyleChanged)) },

#define ON_WM_STYLECHANGING() \
	{ WM_STYLECHANGING, 0, 0, 0, AfxSig_viSS, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(int, LPSTYLESTRUCT) > ( &ThisClass :: OnStyleChanging)) },

#define ON_WM_SIZING() \
	{ WM_SIZING, 0, 0, 0, AfxSig_vwSIZING, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPRECT) > ( &ThisClass :: OnSizing)) },

#define ON_WM_MOVING() \
	{ WM_MOVING, 0, 0, 0, AfxSig_vwMOVING, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, LPRECT) > ( &ThisClass :: OnMoving)) },

#define ON_WM_ENTERSIZEMOVE() \
	{ WM_ENTERSIZEMOVE, 0, 0, 0, AfxSig_v_v_v, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnEnterSizeMove)) },

#define ON_WM_EXITSIZEMOVE() \
	{ WM_EXITSIZEMOVE, 0, 0, 0, AfxSig_v_v_v, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnExitSizeMove)) },

#define ON_WM_CAPTURECHANGED() \
	{ WM_CAPTURECHANGED, 0, 0, 0, AfxSig_vW2, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(CWnd*) > ( &ThisClass :: OnCaptureChanged)) },

#define ON_WM_DEVICECHANGE() \
	{ WM_DEVICECHANGE, 0, 0, 0, AfxSig_bwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< BOOL (AFX_MSG_CALL CWnd::*)(UINT, DWORD_PTR) > ( &ThisClass :: OnDeviceChange)) },

#define ON_WM_POWERBROADCAST() \
	{ WM_POWERBROADCAST, 0, 0, 0, AfxSig_u_u_u, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnPowerBroadcast)) },

#define ON_WM_USERCHANGED() \
	{ WM_USERCHANGED, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnUserChanged)) },

#if(_WIN32_WINNT >= 0x0500 && WINVER >= 0x0500)

#define ON_WM_CHANGEUISTATE() \
	{ WM_CHANGEUISTATE, 0, 0, 0, AfxSig_vww2, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnChangeUIState)) },

#define ON_WM_UPDATEUISTATE() \
	{ WM_UPDATEUISTATE, 0, 0, 0, AfxSig_vww2, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnUpdateUIState)) },

#define ON_WM_QUERYUISTATE() \
	{ WM_QUERYUISTATE, 0, 0, 0, AfxSig_wv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryUIState)) },
#else

#define ON_WM_CHANGEUISTATE() \
	__pragma(message("WM_CHANGEUISTATE requires _WIN32_WINNT and WINVER to be >= 0x500")) \
	{ WM_CHANGEUISTATE, 0, 0, 0, AfxSig_vww2, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnChangeUIState)) },

#define ON_WM_UPDATEUISTATE() \
	__pragma(message("WM_UPDATEUISTATE requires _WIN32_WINNT and WINVER to be >= 0x500")) \
	{ WM_UPDATEUISTATE, 0, 0, 0, AfxSig_vww2, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, UINT) > ( &ThisClass :: OnUpdateUIState)) },

#define ON_WM_QUERYUISTATE() \
	__pragma(message("WM_QUERYUISTATE requires _WIN32_WINNT and WINVER to be >= 0x500")) \
	{ WM_QUERYUISTATE, 0, 0, 0, AfxSig_wv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< UINT (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnQueryUIState)) },

#endif // _WIN32_WINNT >= 0x0500 && WINVER >= 0x0500

#if(_WIN32_WINNT >= 0x0501)
#define ON_WM_THEMECHANGED() \
	{ WM_THEMECHANGED, 0, 0, 0, AfxSig_l, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnThemeChanged)) },
#else
#define ON_WM_THEMECHANGED \
	__pragma(message("ON_WM_THEMECHANGED requires _WIN32_WINNT >= 0x0501")) \
	{ WM_THEMECHANGED, 0, 0, 0, AfxSig_l, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnThemeChanged)) },
#endif	 // _WIN32_WINNT >= 0x0501

#if(_WIN32_WINNT >= 0x0600)

#define ON_WM_DWMCOMPOSITIONCHANGED() \
	{ WM_DWMCOMPOSITIONCHANGED, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnCompositionChanged)) },

#define ON_WM_DWMNCRENDERINGCHANGED() \
	{ WM_DWMNCRENDERINGCHANGED, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnNcRenderingChanged)) },

#define ON_WM_DWMCOLORIZATIONCOLORCHANGED() \
	{ WM_DWMCOLORIZATIONCOLORCHANGED, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(DWORD, BOOL) > ( &ThisClass :: OnColorizationColorChanged)) },

#define ON_WM_DWMWINDOWMAXIMIZEDCHANGE() \
	{ WM_DWMWINDOWMAXIMIZEDCHANGE, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnWindowMaximizedChanged)) },

#else

#define ON_WM_DWMCOMPOSITIONCHANGED \
	__pragma(message("WM_DWMCOMPOSITIONCHANGED requires _WIN32_WINNT >= 0x0600")) \
	{ WM_DWMCOMPOSITIONCHANGED, 0, 0, 0, AfxSig_vv, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &ThisClass :: OnCompositionChanged)) },

#define ON_WM_DWMNCRENDERINGCHANGED() \
	__pragma(message("WM_DWMNCRENDERINGCHANGED requires _WIN32_WINNT >= 0x0600")) \
	{ WM_DWMNCRENDERINGCHANGED, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnRenderingChanged)) },

#define ON_WM_DWMCOLORIZATIONCOLORCHANGED() \
	__pragma(message("WM_DWMCOLORIZATIONCOLORCHANGED requires _WIN32_WINNT >= 0x0600")) \
	{ WM_DWMCOLORIZATIONCOLORCHANGED, 0, 0, 0, AfxSig_vww, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(DWORD, BOOL) > ( &ThisClass :: OnColorizationColorChanged)) },

#define ON_WM_DWMWINDOWMAXIMIZEDCHANGE() \
	__pragma(message("WM_DWMWINDOWMAXIMIZEDCHANGE requires _WIN32_WINNT >= 0x0600")) \
	{ WM_DWMWINDOWMAXIMIZEDCHANGE, 0, 0, 0, AfxSig_vb, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void (AFX_MSG_CALL CWnd::*)(BOOL) > ( &ThisClass :: OnWindowMaximizedChanged)) },

#endif

/////////////////////////////////////////////////////////////////////////////
// Message map tables for Control Notification messages

// Static control notification codes
#define ON_STN_CLICKED(id, memberFxn) \
	ON_CONTROL(STN_CLICKED, id, memberFxn)
#define ON_STN_DBLCLK(id, memberFxn) \
	ON_CONTROL(STN_DBLCLK, id, memberFxn)
#define ON_STN_ENABLE(id, memberFxn) \
	ON_CONTROL(STN_ENABLE, id, memberFxn)
#define ON_STN_DISABLE(id, memberFxn) \
	ON_CONTROL(STN_DISABLE, id, memberFxn)


// Edit Control Notification Codes
#define ON_EN_SETFOCUS(id, memberFxn) \
	ON_CONTROL(EN_SETFOCUS, id, memberFxn)
#define ON_EN_KILLFOCUS(id, memberFxn) \
	ON_CONTROL(EN_KILLFOCUS, id, memberFxn)
#define ON_EN_CHANGE(id, memberFxn) \
	ON_CONTROL(EN_CHANGE, id, memberFxn)
#define ON_EN_UPDATE(id, memberFxn) \
	ON_CONTROL(EN_UPDATE, id, memberFxn)
#define ON_EN_ERRSPACE(id, memberFxn) \
	ON_CONTROL(EN_ERRSPACE, id, memberFxn)
#define ON_EN_MAXTEXT(id, memberFxn) \
	ON_CONTROL(EN_MAXTEXT, id, memberFxn)
#define ON_EN_HSCROLL(id, memberFxn) \
	ON_CONTROL(EN_HSCROLL, id, memberFxn)
#define ON_EN_VSCROLL(id, memberFxn) \
	ON_CONTROL(EN_VSCROLL, id, memberFxn)

#if(_WIN32_WINNT >= 0x0500)
#define ON_EN_ALIGN_LTR_EC(id, memberFxn) \
	ON_CONTROL(EN_ALIGN_LTR_EC, id, memberFxn)
#define ON_EN_ALIGN_RTL_EC(id, memberFxn) \
	ON_CONTROL(EN_ALIGN_RTL_EC, id, memberFxn)
#else
#define ON_EN_ALIGN_LTR_EC(id, memberFxn) \
	__pragma(message("EN_ALIGN_LTR_EC requires _WIN32_WINNT to be >= 0x0500")) \
	ON_CONTROL(EN_ALIGN_LTR_EC, id, memberFxn)
#define ON_EN_ALIGN_RTL_EC(id, memberFxn) \
	__pragma(message("EN_ALIGN_RTL_EC requires _WIN32_WINNT to be >= 0x0500")) \
	ON_CONTROL(EN_ALIGN_RTL_EC, id, memberFxn)
#endif // _WIN32_WINNT >= 0x0500

// Richedit Control Notification Codes
#define ON_EN_IMECHANGE(id, memberFxn) \
	ON_CONTROL(EN_IMECHANGE, id, memberFxn)
#define ON_EN_ALIGNLTR(id, memberFxn) \
	ON_CONTROL(EN_ALIGNLTR, id, memberFxn)
#define ON_EN_ALIGNRTL(id, memberFxn) \
	ON_CONTROL(EN_ALIGNRTL, id, memberFxn)

// Animation Control Notification Codes
#define ON_ACN_START(id, memberFxn) \
	ON_CONTROL(ACN_START, id, memberFxn)
#define ON_ACN_STOP(id, memberFxn) \
	ON_CONTROL(ACN_STOP, id, memberFxn)

// User Button Notification Codes
#define ON_BN_CLICKED(id, memberFxn) \
	ON_CONTROL(BN_CLICKED, id, memberFxn)
#define ON_BN_DOUBLECLICKED(id, memberFxn) \
	ON_CONTROL(BN_DOUBLECLICKED, id, memberFxn)
#define ON_BN_SETFOCUS(id, memberFxn) \
	ON_CONTROL(BN_SETFOCUS, id, memberFxn)
#define ON_BN_KILLFOCUS(id, memberFxn) \
	ON_CONTROL(BN_KILLFOCUS, id, memberFxn)

// old BS_USERBUTTON button notifications - obsolete in Win31
#define ON_BN_PAINT(id, memberFxn) \
	ON_CONTROL(BN_PAINT, id, memberFxn)
#define ON_BN_HILITE(id, memberFxn) \
	ON_CONTROL(BN_HILITE, id, memberFxn)
#define ON_BN_UNHILITE(id, memberFxn) \
	ON_CONTROL(BN_UNHILITE, id, memberFxn)
#define ON_BN_DISABLE(id, memberFxn) \
	ON_CONTROL(BN_DISABLE, id, memberFxn)

// Listbox Notification Codes
#define ON_LBN_ERRSPACE(id, memberFxn) \
	ON_CONTROL(LBN_ERRSPACE, id, memberFxn)
#define ON_LBN_SELCHANGE(id, memberFxn) \
	ON_CONTROL(LBN_SELCHANGE, id, memberFxn)
#define ON_LBN_DBLCLK(id, memberFxn) \
	ON_CONTROL(LBN_DBLCLK, id, memberFxn)
#define ON_LBN_SELCANCEL(id, memberFxn) \
	ON_CONTROL(LBN_SELCANCEL, id, memberFxn)
#define ON_LBN_SETFOCUS(id, memberFxn) \
	ON_CONTROL(LBN_SETFOCUS, id, memberFxn)
#define ON_LBN_KILLFOCUS(id, memberFxn) \
	ON_CONTROL(LBN_KILLFOCUS, id, memberFxn)

// Check Listbox Notification codes
#define CLBN_CHKCHANGE (40)
#define ON_CLBN_CHKCHANGE(id, memberFxn) \
	ON_CONTROL(CLBN_CHKCHANGE, id, memberFxn)

// Combo Box Notification Codes
#define ON_CBN_ERRSPACE(id, memberFxn) \
	ON_CONTROL(CBN_ERRSPACE, id, memberFxn)
#define ON_CBN_SELCHANGE(id, memberFxn) \
	ON_CONTROL(CBN_SELCHANGE, id, memberFxn)
#define ON_CBN_DBLCLK(id, memberFxn) \
	ON_CONTROL(CBN_DBLCLK, id, memberFxn)
#define ON_CBN_SETFOCUS(id, memberFxn) \
	ON_CONTROL(CBN_SETFOCUS, id, memberFxn)
#define ON_CBN_KILLFOCUS(id, memberFxn) \
	ON_CONTROL(CBN_KILLFOCUS, id, memberFxn)
#define ON_CBN_EDITCHANGE(id, memberFxn) \
	ON_CONTROL(CBN_EDITCHANGE, id, memberFxn)
#define ON_CBN_EDITUPDATE(id, memberFxn) \
	ON_CONTROL(CBN_EDITUPDATE, id, memberFxn)
#define ON_CBN_DROPDOWN(id, memberFxn) \
	ON_CONTROL(CBN_DROPDOWN, id, memberFxn)
#define ON_CBN_CLOSEUP(id, memberFxn)  \
	ON_CONTROL(CBN_CLOSEUP, id, memberFxn)
#define ON_CBN_SELENDOK(id, memberFxn)  \
	ON_CONTROL(CBN_SELENDOK, id, memberFxn)
#define ON_CBN_SELENDCANCEL(id, memberFxn)  \
	ON_CONTROL(CBN_SELENDCANCEL, id, memberFxn)

/////////////////////////////////////////////////////////////////////////////
// User extensions for message map entries

// for Windows messages
#define ON_MESSAGE(message, memberFxn) \
	{ message, 0, 0, 0, AfxSig_lwl, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > \
		(memberFxn)) },

// for Registered Windows messages
#define ON_REGISTERED_MESSAGE(nMessageVariable, memberFxn) \
	{ 0xC000, 0, 0, 0, (UINT_PTR)(UINT*)(&nMessageVariable), \
		/*implied 'AfxSig_lwl'*/ \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > \
		(memberFxn)) },

// for Thread messages
#define ON_THREAD_MESSAGE(message, memberFxn) \
	{ message, 0, 0, 0, AfxSig_vwl, \
		(AFX_PMSG)(AFX_PMSGT) \
		(static_cast< void (AFX_MSG_CALL CWinThread::*)(WPARAM, LPARAM) > \
		(memberFxn)) },

// for Registered Windows messages
#define ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn) \
	{ 0xC000, 0, 0, 0, (UINT_PTR)(UINT*)(&nMessageVariable), \
		/*implied 'AfxSig_vwl'*/ \
		(AFX_PMSG)(AFX_PMSGT) \
		(static_cast< void (AFX_MSG_CALL CWinThread::*)(WPARAM, LPARAM) > \
		(memberFxn)) },

/////////////////////////////////////////////////////////////////////////////


