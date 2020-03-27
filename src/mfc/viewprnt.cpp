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



/////////////////////////////////////////////////////////////////////////////
// Printing Dialog

class CPrintingDialog : public CDialog
{
public:
	enum { IDD = AFX_IDD_PRINTDLG };
	CPrintingDialog::CPrintingDialog(CWnd* pParent)
		{
			Create(CPrintingDialog::IDD, pParent);      // modeless !
			_afxWinState->m_bUserAbort = FALSE;
		}
	virtual ~CPrintingDialog() { }

	virtual BOOL OnInitDialog();
	virtual void OnCancel();
};

BOOL CALLBACK _AfxAbortProc(HDC, int)
{
	_AFX_WIN_STATE* pWinState = _afxWinState;
	MSG msg;
	while (!pWinState->m_bUserAbort &&
		::PeekMessage(&msg, NULL, NULL, NULL, PM_NOREMOVE))
	{
		if( !AfxPumpMessage() )
			return FALSE;   // terminate if WM_QUIT received
	}
	return !pWinState->m_bUserAbort;
}

BOOL CPrintingDialog::OnInitDialog()
{
	SetWindowText(AfxGetAppName());
	CenterWindow();
	return CDialog::OnInitDialog();
}

void CPrintingDialog::OnCancel()
{
	_afxWinState->m_bUserAbort = TRUE;  // flag that user aborted print
	CDialog::OnCancel();
}

/////////////////////////////////////////////////////////////////////////////
// CView printing commands

BOOL CView::DoPreparePrinting(CPrintInfo* pInfo)
{
	ASSERT(pInfo != NULL);
	ASSERT(pInfo->m_pPD != NULL);

	if (pInfo->m_pPD->m_pd.nMinPage > pInfo->m_pPD->m_pd.nMaxPage)
		pInfo->m_pPD->m_pd.nMaxPage = pInfo->m_pPD->m_pd.nMinPage;

	// don't prompt the user if we're doing print preview, printing directly,
	// or printing via IPrint and have been instructed not to ask

	CWinApp* pApp = AfxGetApp();
	if (pInfo->m_bPreview || pInfo->m_bDirect ||
		(pInfo->m_bDocObject && !(pInfo->m_dwFlags & PRINTFLAG_PROMPTUSER)))
	{
		if (pInfo->m_pPD->m_pd.hDC == NULL)
		{
			// if no printer set then, get default printer DC and create DC without calling
			//   print dialog.
			if (!pApp->GetPrinterDeviceDefaults(&pInfo->m_pPD->m_pd))
			{
				// bring up dialog to alert the user they need to install a printer.
				if (!pInfo->m_bDocObject || (pInfo->m_dwFlags & PRINTFLAG_MAYBOTHERUSER))
					if (pApp->DoPrintDialog(pInfo->m_pPD) != IDOK)
						return FALSE;
			}

			if (pInfo->m_pPD->m_pd.hDC == NULL)
			{
				// call CreatePrinterDC if DC was not created by above
				if (pInfo->m_pPD->CreatePrinterDC() == NULL)
					return FALSE;
			}
		}

		// set up From and To page range from Min and Max
		pInfo->m_pPD->m_pd.nFromPage = (WORD)pInfo->GetMinPage();
		pInfo->m_pPD->m_pd.nToPage = (WORD)pInfo->GetMaxPage();
	}
	else
	{
		// otherwise, bring up the print dialog and allow user to change things
		// preset From-To range same as Min-Max range
		pInfo->m_pPD->m_pd.nFromPage = (WORD)pInfo->GetMinPage();
		pInfo->m_pPD->m_pd.nToPage = (WORD)pInfo->GetMaxPage();

		if (pApp->DoPrintDialog(pInfo->m_pPD) != IDOK)
			return FALSE;       // do not print
	}

	ASSERT(pInfo->m_pPD != NULL);
	ASSERT(pInfo->m_pPD->m_pd.hDC != NULL);
	if (pInfo->m_pPD->m_pd.hDC == NULL)
		return FALSE;

	pInfo->m_nNumPreviewPages = pApp->m_nNumPreviewPages;
	ENSURE(pInfo->m_strPageDesc.LoadString(AFX_IDS_PREVIEWPAGEDESC));
	return TRUE;
}

void CView::OnFilePrint()
{
	// get default print info
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL);    // must be set

	if (LOWORD(GetCurrentMessage()->wParam) == ID_FILE_PRINT_DIRECT)
	{
		CCommandLineInfo* pCmdInfo = AfxGetApp()->m_pCmdInfo;

		if (pCmdInfo != NULL)
		{
			if (pCmdInfo->m_nShellCommand == CCommandLineInfo::FilePrintTo)
			{
				printInfo.m_pPD->m_pd.hDC = ::CreateDC(pCmdInfo->m_strDriverName,
					pCmdInfo->m_strPrinterName, pCmdInfo->m_strPortName, NULL);
				if (printInfo.m_pPD->m_pd.hDC == NULL)
				{
					AfxMessageBox(AFX_IDP_FAILED_TO_START_PRINT);
					return;
				}
			}
		}

		printInfo.m_bDirect = TRUE;
	}

	if (OnPreparePrinting(&printInfo))
	{
		// hDC must be set (did you remember to call DoPreparePrinting?)
		ASSERT(printInfo.m_pPD->m_pd.hDC != NULL);

		// gather file to print to if print-to-file selected
		CString strOutput;
		if (printInfo.m_pPD->m_pd.Flags & PD_PRINTTOFILE && !printInfo.m_bDocObject)
		{
			// construct CFileDialog for browsing
			CString strDef(MAKEINTRESOURCE(AFX_IDS_PRINTDEFAULTEXT));
			CString strPrintDef(MAKEINTRESOURCE(AFX_IDS_PRINTDEFAULT));
			CString strFilter(MAKEINTRESOURCE(AFX_IDS_PRINTFILTER));
			CString strCaption(MAKEINTRESOURCE(AFX_IDS_PRINTCAPTION));
			CFileDialog dlg(FALSE, strDef, strPrintDef,
				OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, strFilter, NULL, 0);
			dlg.m_ofn.lpstrTitle = strCaption;

			if (dlg.DoModal() != IDOK)
				return;

			// set output device to resulting path name
			strOutput = dlg.GetPathName();
		}

		// set up document info and start the document printing process
		CString strTitle;
		CDocument* pDoc = GetDocument();
		if (pDoc != NULL)
			strTitle = pDoc->GetTitle();
		else
			EnsureParentFrame()->GetWindowText(strTitle);
		DOCINFO docInfo;
		memset(&docInfo, 0, sizeof(DOCINFO));
		docInfo.cbSize = sizeof(DOCINFO);
		docInfo.lpszDocName = strTitle;
		CString strPortName;
		if (strOutput.IsEmpty())
		{
			docInfo.lpszOutput = NULL;
			strPortName = printInfo.m_pPD->GetPortName();
		}
		else
		{
			docInfo.lpszOutput = strOutput;
			AfxGetFileTitle(strOutput,
				strPortName.GetBuffer(_MAX_PATH), _MAX_PATH);
		}

		// setup the printing DC
		CDC dcPrint;
		if (!printInfo.m_bDocObject)
		{
			dcPrint.Attach(printInfo.m_pPD->m_pd.hDC);  // attach printer dc
			dcPrint.m_bPrinting = TRUE;
		}
		OnBeginPrinting(&dcPrint, &printInfo);

		if (!printInfo.m_bDocObject)
			dcPrint.SetAbortProc(_AfxAbortProc);

		// disable main window while printing & init printing status dialog
		// Store the Handle of the Window in a temp so that it can be enabled 
		// once the printing is finished
		CWnd * hwndTemp = AfxGetMainWnd();
		hwndTemp->EnableWindow(FALSE);
		CPrintingDialog dlgPrintStatus(this);

		CString strTemp;
		dlgPrintStatus.SetDlgItemText(AFX_IDC_PRINT_DOCNAME, strTitle);
		dlgPrintStatus.SetDlgItemText(AFX_IDC_PRINT_PRINTERNAME,
			printInfo.m_pPD->GetDeviceName());
		dlgPrintStatus.SetDlgItemText(AFX_IDC_PRINT_PORTNAME, strPortName);
		dlgPrintStatus.ShowWindow(SW_SHOW);
		dlgPrintStatus.UpdateWindow();

		// start document printing process
		if (!printInfo.m_bDocObject)
		{
			printInfo.m_nJobNumber = dcPrint.StartDoc(&docInfo);
			if (printInfo.m_nJobNumber == SP_ERROR)
			{
				// enable main window before proceeding
				hwndTemp->EnableWindow(TRUE);

				// cleanup and show error message
				OnEndPrinting(&dcPrint, &printInfo);
				dlgPrintStatus.DestroyWindow();
				dcPrint.Detach();   // will be cleaned up by CPrintInfo destructor
				AfxMessageBox(AFX_IDP_FAILED_TO_START_PRINT);
				return;
			}
		}

		// Guarantee values are in the valid range
		UINT nEndPage = printInfo.GetToPage();
		UINT nStartPage = printInfo.GetFromPage();

		if (nEndPage < printInfo.GetMinPage())
			nEndPage = printInfo.GetMinPage();
		if (nEndPage > printInfo.GetMaxPage())
			nEndPage = printInfo.GetMaxPage();

		if (nStartPage < printInfo.GetMinPage())
			nStartPage = printInfo.GetMinPage();
		if (nStartPage > printInfo.GetMaxPage())
			nStartPage = printInfo.GetMaxPage();

		int nStep = (nEndPage >= nStartPage) ? 1 : -1;
		nEndPage = (nEndPage == 0xffff) ? 0xffff : nEndPage + nStep;

		VERIFY(strTemp.LoadString(AFX_IDS_PRINTPAGENUM));

		// If it's a doc object, we don't loop page-by-page
		// because doc objects don't support that kind of levity.

		BOOL bError = FALSE;
		if (printInfo.m_bDocObject)
		{
			OnPrepareDC(&dcPrint, &printInfo);
			OnPrint(&dcPrint, &printInfo);
		}
		else
		{
			// begin page printing loop
			for (printInfo.m_nCurPage = nStartPage;
				printInfo.m_nCurPage != nEndPage; printInfo.m_nCurPage += nStep)
			{
				OnPrepareDC(&dcPrint, &printInfo);

				// check for end of print
				if (!printInfo.m_bContinuePrinting)
					break;

				// write current page
				TCHAR szBuf[80];
				ATL_CRT_ERRORCHECK_SPRINTF(_sntprintf_s(szBuf, _countof(szBuf), _countof(szBuf) - 1, strTemp, printInfo.m_nCurPage));
				
				dlgPrintStatus.SetDlgItemText(AFX_IDC_PRINT_PAGENUM, szBuf);

				// set up drawing rect to entire page (in logical coordinates)
				printInfo.m_rectDraw.SetRect(0, 0,
					dcPrint.GetDeviceCaps(HORZRES),
					dcPrint.GetDeviceCaps(VERTRES));
				dcPrint.DPtoLP(&printInfo.m_rectDraw);

				// attempt to start the current page
				if (dcPrint.StartPage() < 0)
				{
					bError = TRUE;
					break;
				}

				// must call OnPrepareDC on newer versions of Windows because
				// StartPage now resets the device attributes.
				OnPrepareDC(&dcPrint, &printInfo);

				ASSERT(printInfo.m_bContinuePrinting);

				// page successfully started, so now render the page
				OnPrint(&dcPrint, &printInfo);
				if ((nStep > 0) && // pages are printed in ascending order
					(nEndPage > printInfo.GetMaxPage() + nStep)) // out off pages
				{
					// OnPrint may have set the last page
					// because the end of the document was reached.
					// The loop must not continue with the next iteration.
					nEndPage = printInfo.GetMaxPage() + nStep; 
				}

				// If the user restarts the job when it's spooling, all 
				// subsequent calls to EndPage returns < 0. The first time
				// GetLastError returns ERROR_PRINT_CANCELLED
				if (dcPrint.EndPage() < 0 && (GetLastError()!= ERROR_SUCCESS))
				{
					HANDLE hPrinter;
					if (!OpenPrinter(LPTSTR(printInfo.m_pPD->GetDeviceName().GetBuffer()), &hPrinter, NULL))
					{
						bError = TRUE;
						break;
					}

					DWORD cBytesNeeded;
					if(!GetJob(hPrinter,printInfo.m_nJobNumber,1,NULL,0,&cBytesNeeded))
					{
						if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
						{
						   bError = TRUE;
						   break;
						}
					}

					JOB_INFO_1 *pJobInfo; 					
					if((pJobInfo = (JOB_INFO_1 *)malloc(cBytesNeeded))== NULL)
					{
						bError = TRUE;
						break;
					}

					DWORD cBytesUsed;

					BOOL bRet = GetJob(hPrinter,printInfo.m_nJobNumber,1,LPBYTE(pJobInfo),cBytesNeeded,&cBytesUsed);

					DWORD dwJobStatus = pJobInfo->Status;

					free(pJobInfo);
					pJobInfo = NULL;

					// if job status is restart, just continue
					if(!bRet || !(dwJobStatus & JOB_STATUS_RESTART) )
					{
						bError = TRUE;
						break;
					}
				}

				if(!_AfxAbortProc(dcPrint.m_hDC, 0))
				{		
					bError = TRUE;
					break;
				}
			}
		}

		// cleanup document printing process
		if (!printInfo.m_bDocObject)
		{
			if (!bError)
				dcPrint.EndDoc();
			else
				dcPrint.AbortDoc();
		}

		hwndTemp->EnableWindow();    // enable main window

		OnEndPrinting(&dcPrint, &printInfo);    // clean up after printing
		dlgPrintStatus.DestroyWindow();

		dcPrint.Detach();   // will be cleaned up by CPrintInfo destructor
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintInfo helper structure

CPrintInfo::CPrintInfo()
{
	m_pPD = new CPrintDialog(FALSE, PD_ALLPAGES | PD_USEDEVMODECOPIES |
		PD_NOSELECTION);

	ASSERT(m_pPD->m_pd.hDC == NULL);

	SetMinPage(1);              // one based page numbers
	SetMaxPage(0xffff);         // unknown how many pages

	m_nCurPage = 1;
	m_nJobNumber = SP_ERROR;

	m_lpUserData = NULL;        // Initialize to no user data
	m_bPreview = FALSE;         // initialize to not preview
	m_bDirect = FALSE;          // initialize to not direct
	m_bDocObject = FALSE;       // initialize to not IPrint
	m_bContinuePrinting = TRUE; // Assume it is OK to print

	m_dwFlags = 0;
	m_nOffsetPage = 0;
}

CPrintInfo::~CPrintInfo()
{
	if (m_pPD != NULL && m_pPD->m_pd.hDC != NULL)
	{
		::DeleteDC(m_pPD->m_pd.hDC);
		m_pPD->m_pd.hDC = NULL;
	}
	delete m_pPD;
}

/////////////////////////////////////////////////////////////////////////////
