// This MFC Library source code supports the Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "afxribboninfoloader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const double s_dblHDPI = 1.5;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCRibbonInfoLoader::CMFCRibbonInfoLoader(CMFCRibbonInfo& info): m_Info(info), m_hInstance(NULL)
{
}

CMFCRibbonInfoLoader::~CMFCRibbonInfoLoader()
{
}

BOOL CMFCRibbonInfoLoader::Load(UINT uiResID, LPCTSTR lpszResType, HINSTANCE hInstance)
{
	return Load(MAKEINTRESOURCE(uiResID), lpszResType, hInstance);
}

BOOL CMFCRibbonInfoLoader::Load(LPCTSTR lpszResID, LPCTSTR lpszResType, HINSTANCE hInstance)
{
	if (lpszResID == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (lpszResType == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	BOOL bRes = FALSE;

	if (hInstance == NULL)
	{
		hInstance = AfxFindResourceHandle(lpszResID, lpszResType);
	}

	if (hInstance == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	m_hInstance = hInstance;
	HRSRC hRsrc = ::FindResource(m_hInstance, lpszResID, lpszResType);

	if (hRsrc == NULL)
	{
		return FALSE;
	}

	DWORD nLength = ::SizeofResource(m_hInstance, hRsrc);
	if (nLength == 0)
	{
		return FALSE;
	}

	HGLOBAL hGlobal = ::LoadResource(m_hInstance, hRsrc);
	if (hGlobal == NULL)
	{
		return FALSE;
	}

	bRes = LoadFromBuffer((LPBYTE)::LockResource(hGlobal), nLength);

	::UnlockResource(hGlobal);
	::FreeResource(hGlobal);

	return bRes;
}

BOOL CMFCRibbonInfoLoader::LoadFromBuffer(LPCTSTR lpszBuffer)
{
	if (lpszBuffer == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return LoadFromBuffer((LPBYTE)lpszBuffer, (UINT)(_tcslen(lpszBuffer) * sizeof(TCHAR)));
}

BOOL CMFCRibbonInfoLoader::LoadFromBuffer(LPBYTE lpBuffer, UINT nSize)
{
	if (lpBuffer == NULL || nSize == 0)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (m_Info.Read(lpBuffer, nSize))
	{
		CMFCRibbonInfo::XArrayImages images;
		m_Info.GetArrayImages(images);

		CMFCRibbonInfo::XImage* pMainImage = NULL;
		if (m_Info.GetRibbonBar().m_btnMain != NULL)
		{
			pMainImage = &m_Info.GetRibbonBar().m_btnMain->m_Image;
		}

		int i = 0;
		for(i = 0; i < images.GetSize(); i++)
		{
			if (!LoadImage(*images[i], images[i] == pMainImage))
			{
				ASSERT(FALSE);
			}
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonInfoLoader::LoadImage(const CMFCRibbonInfo::XID& id, CMFCToolBarImages& image, BOOL bSingle)
{
	if (id.IsEmpty())
	{
		return TRUE;
	}

	if (id.m_Value > 0)
	{
		image.Load(id.m_Value, m_hInstance);
	}

	if (!image.IsValid() && !id.m_Name.IsEmpty())
	{
		image.LoadStr(id.m_Name, m_hInstance);
	}

	if (image.IsValid())
	{
		if (bSingle)
		{
			image.SetSingleImage();
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonInfoLoader::LoadImage(CMFCRibbonInfo::XImage& image, BOOL bSingle)
{
	image.m_Image.Clear();

	if (image.m_ID.IsEmpty())
	{
		return TRUE;
	}

	double dblScale = afxGlobalData.GetRibbonImageScale();
	if (dblScale >= s_dblHDPI)
	{
		if (LoadImage(image.m_ID_HDPI, image.m_Image, bSingle))
		{
			if (image.m_Image.IsValid())
			{
				if (!bSingle)
				{
					CSize sizeHDPI(image.m_Image.GetImageSize());
					sizeHDPI.cx = (int)(sizeHDPI.cx * s_dblHDPI);
					sizeHDPI.cy = (int)(sizeHDPI.cy * s_dblHDPI);
					image.m_Image.SetImageSize(sizeHDPI);
				}

				dblScale /= s_dblHDPI;
			}
		}
	}

	if (!image.m_Image.IsValid())
	{
		LoadImage(image.m_ID, image.m_Image, bSingle);
	}

	if (image.m_Image.IsValid() && dblScale > 1.0)
	{
		if (image.m_Image.GetBitsPerPixel() < 32)
		{
			image.m_Image.ConvertTo32Bits(afxGlobalData.clrBtnFace);
		}

		image.m_Image.SetTransparentColor(afxGlobalData.clrBtnFace);
		image.m_Image.SmoothResize(dblScale);
	}

	return image.m_Image.IsValid();
}
