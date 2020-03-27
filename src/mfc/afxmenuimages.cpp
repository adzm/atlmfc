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
#include "afxmenuimages.h"
#include "afxribbonres.h"
#include "afxglobals.h"

static const COLORREF clrTransparent = RGB(255, 0, 255);
static const int nImageWidth = 9;
static const int nImageHeight = 9;

CMFCToolBarImages CMenuImages::m_ImagesBlack(TRUE);
CMFCToolBarImages CMenuImages::m_ImagesDkGray(TRUE);
CMFCToolBarImages CMenuImages::m_ImagesGray(TRUE);
CMFCToolBarImages CMenuImages::m_ImagesLtGray(TRUE);
CMFCToolBarImages CMenuImages::m_ImagesWhite(TRUE);
CMFCToolBarImages CMenuImages::m_ImagesBlack2(TRUE);

BOOL CMenuImages::m_bInitializing = FALSE;

BOOL __stdcall CMenuImages::Initialize()
{
	if (m_bInitializing)
	{
		return FALSE;
	}

	if (m_ImagesBlack.IsValid())
	{
		return TRUE;
	}

	m_bInitializing = TRUE;

	m_ImagesBlack.Initialize();
	m_ImagesDkGray.Initialize();
	m_ImagesGray.Initialize();
	m_ImagesLtGray.Initialize();
	m_ImagesWhite.Initialize();
	m_ImagesBlack2.Initialize();

	m_ImagesBlack.SetImageSize(CSize(nImageWidth, nImageHeight));
	if (!m_ImagesBlack.Load(GetGlobalData()->Is32BitIcons() ? IDB_AFXBARRES_MENU_IMAGES24 : IDB_AFXBARRES_MENU_IMAGES))
	{
		TRACE(_T("CMenuImages. Can't load menu images %x\n"), IDB_AFXBARRES_MENU_IMAGES);
		m_bInitializing = FALSE;
		return FALSE;
	}

	if (m_ImagesBlack.IsRTL())
	{
		m_ImagesBlack.Mirror();
	}

	m_ImagesBlack.SetTransparentColor(clrTransparent);

	CreateCopy(m_ImagesGray, RGB(128, 128, 128));
	CreateCopy(m_ImagesDkGray, RGB(72, 72, 72));
	CreateCopy(m_ImagesLtGray, RGB(192, 192, 192));
	CreateCopy(m_ImagesWhite, RGB(255, 255, 255));
	CreateCopy(m_ImagesBlack2, RGB(0, 0, 0));

	if (m_ImagesBlack.IsValid())
	{
		double dblScale = GetGlobalData()->GetRibbonImageScale();
		if (dblScale != 1.0)
		{
			m_ImagesBlack.SmoothResize(dblScale);
			m_ImagesGray.SmoothResize(dblScale);
			m_ImagesDkGray.SmoothResize(dblScale);
			m_ImagesLtGray.SmoothResize(dblScale);
			m_ImagesWhite.SmoothResize(dblScale);
			m_ImagesBlack2.SmoothResize(dblScale);
		}
	}

	m_bInitializing = FALSE;
	return TRUE;
}

CSize __stdcall CMenuImages::Size()
{
	if (m_bInitializing)
	{
		CSize size(nImageWidth, nImageHeight);

		double dblScale = GetGlobalData()->GetRibbonImageScale();
		if (dblScale != 1.0)
		{
			size.cx = (int)(.5 + size.cx * dblScale);
			size.cy = (int)(.5 + size.cy * dblScale);
		}

		return size;
	}

	Initialize ();
	return m_ImagesBlack.GetImageSize();
}

void __stdcall CMenuImages::Draw(CDC* pDC, IMAGES_IDS id, const CPoint& ptImage, CMenuImages::IMAGE_STATE state, const CSize& sizeImage/* = CSize(0, 0)*/)
{
	if (!Initialize())
	{
		return;
	}

	CAfxDrawState ds;

	CMFCToolBarImages& images = (state == ImageBlack) ? m_ImagesBlack : (state == ImageGray) ? m_ImagesGray :
		(state == ImageDkGray) ? m_ImagesDkGray : (state == ImageLtGray) ? m_ImagesLtGray : (state == ImageWhite) ? m_ImagesWhite : m_ImagesBlack2;

	images.PrepareDrawImage(ds, sizeImage);
	images.Draw(pDC, ptImage.x, ptImage.y, id);
	images.EndDrawImage(ds);
}

void __stdcall CMenuImages::Draw(CDC* pDC, IMAGES_IDS id, const CRect& rectImage, CMenuImages::IMAGE_STATE state, const CSize& sizeImageDest/* = CSize(0, 0)*/)
{
	const CSize sizeImage = (sizeImageDest == CSize(0, 0)) ? Size() : sizeImageDest;

	CPoint ptImage(rectImage.left +(rectImage.Width() - sizeImage.cx) / 2 +((rectImage.Width() - sizeImage.cx) % 2),
		rectImage.top +(rectImage.Height() - sizeImage.cy) / 2 +((rectImage.Height() - sizeImage.cy) % 2));

	Draw(pDC, id, ptImage, state, sizeImageDest);
}

void __stdcall CMenuImages::CleanUp()
{
	if (m_bInitializing)
	{
		return;
	}

	if (m_ImagesBlack.GetCount() > 0)
	{
		m_ImagesBlack.Clear();
		m_ImagesGray.Clear();
		m_ImagesDkGray.Clear();
		m_ImagesLtGray.Clear();
		m_ImagesWhite.Clear();
		m_ImagesBlack2.Clear();
	}
}

void __stdcall CMenuImages::CreateCopy(CMFCToolBarImages& images, COLORREF clr)
{
	m_ImagesBlack.CopyTo(images);
	images.MapTo3dColors(TRUE, RGB(0, 0, 0), clr);
}

void __stdcall CMenuImages::SetColor(CMenuImages::IMAGE_STATE state, COLORREF color)
{
	Initialize();

	CMFCToolBarImages imagesTmp;

	imagesTmp.SetImageSize (CSize (nImageWidth, nImageHeight));
	imagesTmp.Load(GetGlobalData()->Is32BitIcons() ? IDB_AFXBARRES_MENU_IMAGES24 : IDB_AFXBARRES_MENU_IMAGES);
	imagesTmp.SetTransparentColor(clrTransparent);

	if (imagesTmp.IsRTL())
	{
		CMFCToolBarImages::MirrorBitmap(imagesTmp.m_hbmImageWell, imagesTmp.GetImageSize().cx);
	}

	CMFCToolBarImages& images = (state == ImageBlack) ? m_ImagesBlack : (state == ImageGray) ? m_ImagesGray :
		(state == ImageDkGray) ? m_ImagesDkGray : (state == ImageLtGray) ? m_ImagesLtGray : (state == ImageWhite) ? m_ImagesWhite : m_ImagesBlack2;

	if (color != (COLORREF)-1)
	{
		imagesTmp.MapTo3dColors(TRUE, RGB(0, 0, 0), color);
	}

	if (!m_bInitializing)
	{
		imagesTmp.SmoothResize(GetGlobalData()->GetRibbonImageScale());
	}

	images.Clear();
	imagesTmp.CopyTo(images);
}


