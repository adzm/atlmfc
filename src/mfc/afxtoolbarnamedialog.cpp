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
#include "afxtoolbarnamedialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCToolBarNameDialog dialog


CMFCToolBarNameDialog::CMFCToolBarNameDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCToolBarNameDialog::IDD, pParent)
{
	m_strToolbarName = _T("");
}


void CMFCToolBarNameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOk);
	DDX_Text(pDX, IDC_AFXBARRES_TOOLBAR_NAME, m_strToolbarName);
}


BEGIN_MESSAGE_MAP(CMFCToolBarNameDialog, CDialog)
	ON_EN_UPDATE(IDC_AFXBARRES_TOOLBAR_NAME, &CMFCToolBarNameDialog::OnUpdateToolbarName)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCToolBarNameDialog message handlers

void CMFCToolBarNameDialog::OnUpdateToolbarName()
{
	UpdateData();
	m_btnOk.EnableWindow(!m_strToolbarName.IsEmpty());
}

BOOL CMFCToolBarNameDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (AfxGetMainWnd() != NULL && (AfxGetMainWnd()->GetExStyle() & WS_EX_LAYOUTRTL))
	{
		ModifyStyleEx(0, WS_EX_LAYOUTRTL);
	}

	m_btnOk.EnableWindow(!m_strToolbarName.IsEmpty());
	return TRUE;  // return TRUE unless you set the focus to a control
}


