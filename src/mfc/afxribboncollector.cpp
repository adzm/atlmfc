// This MFC Library source code supports the Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "afxribboncollector.h"

#include "afxribboncategory.h"
#include "afxribboncombobox.h"
#include "afxribbonpalettegallery.h"
#include "afxribbonlabel.h"
#include "afxribbonundobutton.h"
#include "afxribboncolorbutton.h"
#include "afxribbonlinkctrl.h"
#include "afxribboncheckbox.h"
#include "afxribbonslider.h"
#include "afxribbonprogressbar.h"
#include "afxribbonmainpanel.h"
#include "afxdrawmanager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace AfxRibbonCollector
{

	class CMemoryDC
	{
	public:
		CMemoryDC() : m_pOldBitmap(NULL), m_Size(0, 0)
		{
		}

		void CreateDC()
		{
			if (m_DC.GetSafeHdc() != NULL)
			{
				return;
			}

			HDC hDC = ::GetDC(NULL);

			HDC hNewDC = ::CreateCompatibleDC(hDC);
			if (hNewDC != NULL)
			{
				m_DC.Attach(hNewDC);
			}

			::ReleaseDC(NULL, hDC);
		}

		void SetSize(const CSize& size)
		{
			if (m_DC.GetSafeHdc() == NULL)
			{
				CreateDC();
			}

			if (m_Bitmap.GetSafeHandle() != NULL)
			{
				if (m_Size.cx != size.cx || m_Size.cy != size.cy)
				{
					if (m_pOldBitmap != NULL)
					{
						m_DC.SelectObject(m_pOldBitmap);
					}

					m_Bitmap.DeleteObject();
				}
			}

			m_Size = size;

			if (m_Bitmap.GetSafeHandle() == NULL)
			{
				HBITMAP hbmp = CDrawingManager::CreateBitmap_32(size, NULL);
				if (hbmp != NULL)
				{
					m_Bitmap.Attach(hbmp);
					m_pOldBitmap = (CBitmap*)m_DC.SelectObject(&m_Bitmap);
				}
			}
		}

		const CSize& GetSize() const { return m_Size; }

		CDC& GetDC() { return m_DC; }
		const CDC& GetDC() const { return m_DC; }

		CBitmap& GetBitmap() { return m_Bitmap; }
		const CBitmap& GetBitmap() const { return m_Bitmap; }

	protected:
		CDC         m_DC;
		CBitmap     m_Bitmap;
		CBitmap*    m_pOldBitmap;

		CSize       m_Size;
	};

	static BOOL AddIcon(CMFCToolBarImages& images, HICON hIcon)
	{
		if (hIcon == NULL)
		{
			return FALSE;
		}

		ICONINFO ii;
		::GetIconInfo(hIcon, &ii);

		CSize size;
		{
			BITMAP bmp;
			if (::GetObject(ii.hbmColor, sizeof(BITMAP), &bmp) == 0)
			{
				ASSERT(FALSE);
				return NULL;
			}

			size.cx = bmp.bmWidth;
			size.cy = bmp.bmHeight;
		}

		CMemoryDC dcColor;
		dcColor.SetSize(size);
		::DrawIconEx(dcColor.GetDC().GetSafeHdc(), 0, 0, hIcon, size.cx, size.cy, 0, NULL, DI_NORMAL);

		BITMAP bmpColor;
		dcColor.GetBitmap().GetBitmap(&bmpColor);
		RGBQUAD* pColor = (RGBQUAD*) bmpColor.bmBits;

		BOOL bConvert = TRUE;
		for(int i = 0; i < size.cx * size.cy; i++)
		{
			if (pColor[i].rgbReserved != 0)
			{
				bConvert = FALSE;
				break;
			}
		}

		if (bConvert)
		{
			CMemoryDC dcMask;
			dcMask.SetSize(size);
			::DrawIconEx(dcMask.GetDC().GetSafeHdc(), 0, 0, hIcon, size.cx, size.cy, 0, NULL, DI_MASK);

			BITMAP bmpMask;
			dcMask.GetBitmap().GetBitmap(&bmpMask);
			RGBQUAD* pMask  = (RGBQUAD*) bmpMask.bmBits;

			if (pColor == NULL || pMask == NULL)
			{
				ASSERT(FALSE);
				return NULL;
			}

			// add alpha channel
			for(int i = 0; i < size.cx * size.cy; i++)
			{
				pColor->rgbReserved = (BYTE)(255 - pMask->rgbRed);
				pColor++;
				pMask++;
			}
		}

		BOOL bRes = FALSE;

		HBITMAP bitmap = CDrawingManager::CreateBitmap_32(dcColor.GetBitmap());
		if (bitmap != NULL)
		{
			bRes = images.AddImage(bitmap, FALSE) != -1;
			::DeleteObject(bitmap);
		}

		return bRes;
	}

};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCRibbonCollector::CMFCRibbonCollector(CMFCRibbonInfo& info, DWORD dwFlags): m_Info(info), m_dwFlags(dwFlags)
{
}

CMFCRibbonCollector::~CMFCRibbonCollector()
{
}

void CMFCRibbonCollector::CollectRibbonBar(const CMFCRibbonBar& bar)
{
	CollectRibbonBar(bar, GetInfo().GetRibbonBar());
}

void CMFCRibbonCollector::CollectRibbonBar(const CMFCRibbonBar& bar, CMFCRibbonInfo::XRibbonBar& info)
{
	info.m_bToolTip = bar.IsToolTipEnabled();
	info.m_bToolTipDescr = bar.IsToolTipDescrEnabled();
	info.m_bKeyTips = bar.IsKeyTipEnabled();
	info.m_bPrintPreview = bar.IsPrintPreviewEnabled();
	info.m_bDrawUsingFont = CMFCRibbonFontComboBox::m_bDrawUsingFont;

	// main button
	CMFCRibbonApplicationButton* pBtnMain = bar.GetApplicationButton();
	if (pBtnMain != NULL)
	{
		info.m_btnMain = new CMFCRibbonInfo::XElementButtonApplication;
		CollectElement(*pBtnMain, *info.m_btnMain);
	}

	info.m_MainCategory = new CMFCRibbonInfo::XCategoryMain;
	CollectCategoryMain(bar, *info.m_MainCategory);

	int i = 0;

	// QAT elements
	CollectQATElements(bar, info);

	// tab elements
	CollectElement(bar.m_TabElements, info.m_TabElements);

	int index = info.m_bPrintPreview ? 1 : 0;
	int count = bar.GetCategoryCount();

	for(i = index; i < count; i++)
	{
		CMFCRibbonCategory* pCategory = bar.GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() == 0)
		{
			CMFCRibbonInfo::XCategory* pInfo = new CMFCRibbonInfo::XCategory;
			CollectCategory(*pCategory, *pInfo);
			info.m_arCategories.Add(pInfo);
		}
	}

	UINT uiContextID = 0;
	CMFCRibbonInfo::XContext* pInfoContext = NULL;
	for(i = index; i < count; i++)
	{
		CMFCRibbonCategory* pCategory = bar.GetCategory(i);
		ASSERT_VALID(pCategory);

		UINT uiID = pCategory->GetContextID();
		if (uiID != 0)
		{
			if (uiContextID != uiID)
			{
				uiContextID = uiID;
				pInfoContext = new CMFCRibbonInfo::XContext;

				CMFCRibbonContextCaption* pCaption = bar.FindContextCaption(uiContextID);
				ASSERT_VALID(pCaption);

				pInfoContext->m_strText = pCaption->GetText();
				GetID(*pCaption, pInfoContext->m_ID);
				pInfoContext->m_Color = pCaption->GetColor();

				info.m_arContexts.Add(pInfoContext);
			}

			if (pInfoContext != NULL)
			{
				CMFCRibbonInfo::XCategory* pInfo = new CMFCRibbonInfo::XCategory;
				CollectCategory(*pCategory, *pInfo);
				pInfoContext->m_arCategories.Add(pInfo);
			}
		}
	}

	// panel images
	GetRibbonBarImages(bar, info);
}

void CMFCRibbonCollector::CollectQATElements(const CMFCRibbonBar& bar, CMFCRibbonInfo::XRibbonBar& info)
{
	const CMFCRibbonQuickAccessToolBarDefaultState& state = bar.m_QAToolbar.m_DefaultState;

	for (int i = 0; i < state.m_arCommands.GetSize(); i++)
	{
		UINT nID = state.m_arCommands[i];
		if (nID != 0)
		{
			CMFCRibbonInfo::XQAT::XQATItem item;
			item.m_ID.m_Value = nID;
			item.m_bVisible   = state.m_arVisibleState[i];
			info.m_QAT.m_arItems.Add(item);
		}
	}

	info.m_QAT.m_bOnTop = bar.m_bQuickAccessToolbarOnTop;
}

void CMFCRibbonCollector::CollectCategoryMain(const CMFCRibbonBar& bar, CMFCRibbonInfo::XCategoryMain& info)
{
	CMFCRibbonCategory* pCategory = bar.GetMainCategory();
	if (pCategory == NULL)
	{
		return;
	}

	info.m_strName = pCategory->GetName();

	if (pCategory->GetPanelCount() > 0)
	{
		CMFCRibbonMainPanel* pPanel = DYNAMIC_DOWNCAST(CMFCRibbonMainPanel, pCategory->GetPanel(0));
		if (pPanel == NULL)
		{
			return;
		}

		int i = 0;
		int count = pPanel->GetCount();

		for(i = 0; i < count; i++)
		{
			CMFCRibbonBaseElement* pElement = pPanel->GetElement(i);
			ASSERT_VALID(pElement);

			if (pElement != pPanel->m_pElemOnRight)
			{
				CMFCRibbonInfo::XElement* pElementInfo = CollectElement(*pElement);
				if (pElementInfo != NULL)
				{
					info.m_arElements.Add(pElementInfo);
				}
			}
		}

		if (pPanel->m_pElemOnRight != NULL && pPanel->m_pElemOnRight->IsKindOf(RUNTIME_CLASS(CMFCRibbonRecentFilesList)))
		{
			info.m_bRecentListEnable  = TRUE;
			info.m_strRecentListLabel = pPanel->m_pElemOnRight->GetText();
			info.m_nRecentListWidth   = pPanel->m_nRightPaneWidth;
		}
	}

	GetCategoryImages(*pCategory, info.m_SmallImages, info.m_LargeImages);
}

void CMFCRibbonCollector::CollectCategory(const CMFCRibbonCategory& category, CMFCRibbonInfo::XCategory& info)
{
	info.m_strName = category.GetName();
	info.m_strKeys = category.m_Tab.GetKeys();

	int i = 0;
	int count = category.GetPanelCount();

	for(i = 0; i < count; i++)
	{
		const CMFCRibbonPanel* pPanel = (const_cast<CMFCRibbonCategory&>(category)).GetPanel(i);
		ASSERT_VALID(pPanel);

		CMFCRibbonInfo::XPanel* pInfo = new CMFCRibbonInfo::XPanel;
		CollectPanel(*pPanel, *pInfo);
		info.m_arPanels.Add(pInfo);
	}

	// hidden element count
	if ((GetFlags() & e_CollectHiddenElements) == e_CollectHiddenElements)
	{
		const CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements = category.m_arElements;
		for(i = 0; i < (int)arElements.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pElement = arElements[i];
			if (DYNAMIC_DOWNCAST(CMFCRibbonDefaultPanelButton, pElement) == NULL)
			{
				ASSERT_VALID(pElement);

				CMFCRibbonInfo::XElement* pElementInfo = CollectElement(*pElement);
				if (pElementInfo != NULL)
				{
					info.m_arElements.Add(pElementInfo);
				}
			}
		}
	}

	GetCategoryImages(category, info);
}

void CMFCRibbonCollector::CollectPanel(const CMFCRibbonPanel& panel, CMFCRibbonInfo::XPanel& info)
{
	info.m_strName = panel.GetName();
	info.m_strKeys = ((CMFCRibbonPanel&)panel).GetDefaultButton().GetKeys();
	info.m_bJustifyColumns = panel.IsJustifyColumns();
	info.m_bCenterColumnVert = panel.IsCenterColumnVert();

	CollectElement((const_cast<CMFCRibbonPanel&>(panel)).GetLaunchButton(), info.m_btnLaunch);

	int i = 0;
	int count = panel.GetCount();

	for(i = 0; i < count; i++)
	{
		CMFCRibbonBaseElement* pElement = panel.GetElement(i);
		ASSERT_VALID(pElement);

		CMFCRibbonInfo::XElement* pElementInfo = CollectElement(*pElement);
		if (pElementInfo != NULL)
		{
			info.m_arElements.Add(pElementInfo);
		}
	}
}

CMFCRibbonInfo::XElement* CMFCRibbonCollector::CollectElement(const CMFCRibbonBaseElement& element)
{
	CMFCRibbonInfo::XElement* info = NULL;

	if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonButtonsGroup)))
	{
		CMFCRibbonInfo::XElementGroup* pNewInfo = new CMFCRibbonInfo::XElementGroup;
		info = pNewInfo;

		CollectElement(element, *info);
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonLabel)))
	{
		CMFCRibbonInfo::XElementLabel* pNewInfo = new CMFCRibbonInfo::XElementLabel;
		info = pNewInfo;

		CollectBaseElement(element, *info);
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonFontComboBox)))
	{
		CMFCRibbonInfo::XElementFontComboBox* pNewInfo = new CMFCRibbonInfo::XElementFontComboBox;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonFontComboBox* pElement = (const CMFCRibbonFontComboBox*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_nWidth = pElement->GetWidth(FALSE);
		pNewInfo->m_nWidthFloaty = pElement->GetWidth(TRUE);
		pNewInfo->m_bHasEditBox = pElement->HasEditBox();
		pNewInfo->m_bResizeDropDownList = pElement->IsResizeDropDownList();
		pNewInfo->m_strValue = pElement->GetEditText();

		pNewInfo->m_nFontType = pElement->GetFontType();
		pNewInfo->m_nCharSet = pElement->GetCharSet();
		pNewInfo->m_nPitchAndFamily = pElement->GetPitchAndFamily();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonComboBox)))
	{
		CMFCRibbonInfo::XElementComboBox* pNewInfo = new CMFCRibbonInfo::XElementComboBox;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonComboBox* pElement = (const CMFCRibbonComboBox*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_nWidth = pElement->GetWidth(FALSE);
		pNewInfo->m_nWidthFloaty = pElement->GetWidth(TRUE);
		pNewInfo->m_bHasEditBox = pElement->HasEditBox();
		pNewInfo->m_bResizeDropDownList = pElement->IsResizeDropDownList();
		pNewInfo->m_strValue = pElement->GetEditText();

		int i = 0;
		int count = (int)pElement->GetCount();

		for(i = 0; i < count; i++)
		{
			pNewInfo->m_arItems.Add(pElement->GetItem(i));
		}
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonEdit)))
	{
		CMFCRibbonInfo::XElementEdit* pNewInfo = new CMFCRibbonInfo::XElementEdit;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonEdit* pElement = (const CMFCRibbonEdit*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_nWidth = pElement->GetWidth(FALSE);
		pNewInfo->m_nWidthFloaty = pElement->GetWidth(TRUE);
		if (pElement->HasSpinButtons())
		{
			pNewInfo->m_bHasSpinButtons = TRUE;
			pNewInfo->m_nMin = pElement->GetRangeMin();
			pNewInfo->m_nMax = pElement->GetRangeMax();
		}
		pNewInfo->m_strValue = pElement->GetEditText();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonUndoButton)))
	{
		CMFCRibbonInfo::XElementButtonUndo* pNewInfo = new CMFCRibbonInfo::XElementButtonUndo;
		info = pNewInfo;

		CollectBaseElement(element, *info, FALSE);

		const CMFCRibbonUndoButton* pElement = (const CMFCRibbonUndoButton*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_bIsButtonMode = pElement->IsButtonMode();
		pNewInfo->m_bEnableMenuResize = pElement->IsMenuResizeEnabled();
		pNewInfo->m_bMenuResizeVertical = pElement->IsMenuResizeVertical();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonColorButton)))
	{
		CMFCRibbonInfo::XElementButtonColor* pNewInfo = new CMFCRibbonInfo::XElementButtonColor;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonColorButton* pElement = (const CMFCRibbonColorButton*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_bIsButtonMode = pElement->IsButtonMode();
		pNewInfo->m_bEnableMenuResize = pElement->IsMenuResizeEnabled();
		pNewInfo->m_bMenuResizeVertical = pElement->IsMenuResizeVertical();
		pNewInfo->m_nIconsInRow = pElement->GetIconsInRow();

		pNewInfo->m_clrColor = pElement->GetColor();

		pNewInfo->m_strAutomaticBtnLabel = pElement->m_strAutomaticButtonLabel;
		pNewInfo->m_strAutomaticBtnToolTip = pElement->m_strAutomaticButtonToolTip;
		pNewInfo->m_clrAutomaticBtnColor = pElement->m_ColorAutomatic;
		pNewInfo->m_bAutomaticBtnOnTop = pElement->m_bIsAutomaticButtonOnTop;
		pNewInfo->m_bAutomaticBtnBorder = pElement->m_bIsAutomaticButtonBorder;

		pNewInfo->m_strOtherBtnLabel = pElement->m_strOtherButtonLabel;
		pNewInfo->m_strOtherBtnToolTip = pElement->m_strOtherButtonToolTip;

		pNewInfo->m_sizeIcon = pElement->GetColorBoxSize();
		pNewInfo->m_bSimpleButtonLook = pElement->IsSimpleButtonLook();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonGallery)))
	{
		CMFCRibbonInfo::XElementButtonGallery* pNewInfo = new CMFCRibbonInfo::XElementButtonGallery;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonGallery* pElement = (const CMFCRibbonGallery*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_bIsButtonMode = pElement->IsButtonMode();
		pNewInfo->m_bEnableMenuResize = pElement->IsMenuResizeEnabled();
		pNewInfo->m_bMenuResizeVertical = pElement->IsMenuResizeVertical();
		pNewInfo->m_nIconsInRow = pElement->GetIconsInRow ();

		GetElementImages(*pElement, pNewInfo->m_Images);

		if (pNewInfo->m_Images.m_Image.GetCount() > 0)
		{
			pNewInfo->m_sizeIcon = pNewInfo->m_Images.m_Image.GetImageSize();
		}
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonLinkCtrl)))
	{
		CMFCRibbonInfo::XElementButtonLinkCtrl* pNewInfo = new CMFCRibbonInfo::XElementButtonLinkCtrl;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonLinkCtrl* pElement = (const CMFCRibbonLinkCtrl*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_strLink = pElement->GetLink();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonCheckBox)))
	{
		CMFCRibbonInfo::XElementButtonCheck* pNewInfo = new CMFCRibbonInfo::XElementButtonCheck;
		info = pNewInfo;

		CollectBaseElement(element, *info);
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonMainPanelButton)))
	{
		CMFCRibbonInfo::XElementButtonMainPanel* pNewInfo = new CMFCRibbonInfo::XElementButtonMainPanel;
		info = pNewInfo;

		CollectBaseElement(element, *info);
	}	
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonButton)))
	{
		CMFCRibbonInfo::XElementButton* pNewInfo = new CMFCRibbonInfo::XElementButton;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonButton* pElement = (const CMFCRibbonButton*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_bIsAlwaysShowDescription = pElement->m_bAlwaysShowDescription;
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonSlider)))
	{
		CMFCRibbonInfo::XElementSlider* pNewInfo = new CMFCRibbonInfo::XElementSlider;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonSlider* pElement = (const CMFCRibbonSlider*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_nWidth = pElement->GetWidth();
		pNewInfo->m_bZoomButtons = pElement->HasZoomButtons();
		pNewInfo->m_nMin = pElement->GetRangeMin();
		pNewInfo->m_nMax = pElement->GetRangeMax();
		pNewInfo->m_nPos = pElement->GetPos();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonProgressBar)))
	{
		CMFCRibbonInfo::XElementProgressBar* pNewInfo = new CMFCRibbonInfo::XElementProgressBar;
		info = pNewInfo;

		CollectBaseElement(element, *info);

		const CMFCRibbonProgressBar* pElement = (const CMFCRibbonProgressBar*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_nWidth = pElement->GetWidth();
		pNewInfo->m_nMin = pElement->GetRangeMin();
		pNewInfo->m_nMax = pElement->GetRangeMax();
		pNewInfo->m_nPos = pElement->GetPos();
		pNewInfo->m_bInfinite = pElement->IsInfiniteMode();
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonSeparator)))
	{
		CMFCRibbonInfo::XElementSeparator* pNewInfo = new CMFCRibbonInfo::XElementSeparator;
		info = pNewInfo;

		const CMFCRibbonSeparator* pElement = (const CMFCRibbonSeparator*)&element;
		ASSERT_VALID(pElement);

		pNewInfo->m_bIsHoriz = pElement->IsHorizontal();
	}

	return info;
}

void CMFCRibbonCollector::CollectElement(const CMFCRibbonBaseElement& element, CMFCRibbonInfo::XElement& info)
{
	if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Application && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonApplicationButton)))
	{
		CollectBaseElement(element, info);

		CMFCRibbonInfo::XElementButtonApplication& infoElement = (CMFCRibbonInfo::XElementButtonApplication&)info;

		GetElementImages(element, infoElement.m_Image);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Launch && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonLaunchButton)))
	{
		CollectBaseElement(element, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeGroup && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonButtonsGroup)))
	{
		const CMFCRibbonButtonsGroup* pElement = (const CMFCRibbonButtonsGroup*)&element;
		CMFCRibbonInfo::XElementGroup& infoElement = (CMFCRibbonInfo::XElementGroup&)info;

		int count = pElement->GetCount();
		if (count > 0)
		{
			GetElementImages(*pElement, infoElement.m_Images);

			for(int i = 0; i < count; i++)
			{
				CMFCRibbonInfo::XElement* pElementInfo = CollectElement(*pElement->GetButton(i));
				if (pElementInfo != NULL)
				{
					infoElement.m_arButtons.Add(pElementInfo);
				}
			}
		}
	}
	else
	{
		ASSERT(FALSE);
	}
}

void CMFCRibbonCollector::CollectBaseElement(const CMFCRibbonBaseElement& element, CMFCRibbonInfo::XElement& info, BOOL bSubItems)
{
	info.m_strText = element.GetText();
	if ((GetFlags() & e_CollectUpdatedToolInfo) == e_CollectUpdatedToolInfo)
	{
		((CMFCRibbonBaseElement&)element).UpdateTooltipInfo();
	}
	info.m_strToolTip = element.m_strToolTip;
	info.m_strDescription = element.GetDescription();
	info.m_strKeys = element.GetKeys();
	info.m_strMenuKeys = element.GetMenuKeys();

	GetID(element, info.m_ID);

	const CMFCRibbonButton* pButton = DYNAMIC_DOWNCAST(CMFCRibbonButton, &element);
	if (pButton != NULL)
	{
		CMFCRibbonInfo::XElementButton& infoButton = (CMFCRibbonInfo::XElementButton&)info;

		infoButton.m_nSmallImageIndex = pButton->GetImageIndex(FALSE);
		infoButton.m_nLargeImageIndex = pButton->GetImageIndex(TRUE);
		infoButton.m_bIsAlwaysLarge = pButton->IsAlwaysLargeImage();
		infoButton.m_bIsDefaultCommand = pButton->IsDefaultCommand();

		if (bSubItems)
		{
			const CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& subAr = pButton->GetSubItems();

			int i = 0;
			int count = (int)subAr.GetSize();

			for(i = 0; i < count; i++)
			{
				CMFCRibbonBaseElement* pSubItem = (CMFCRibbonBaseElement*)subAr[i];
				ASSERT_VALID(pSubItem);

				CMFCRibbonInfo::XElement* pElementInfo = CollectElement(*pSubItem);
				if (pElementInfo != NULL)
				{
					pElementInfo->m_bIsOnPaletteTop = pSubItem->m_bIsOnPaletteTop;
					infoButton.m_arSubItems.Add(pElementInfo);
				}
			}
		}
	}
}

void CMFCRibbonCollector::GetID(const CMFCRibbonBaseElement& element, CMFCRibbonInfo::XID& info)
{
	info.m_Value = element.GetID();

	if (info.m_Value == -1 || info.m_Value == 0)
	{
		const CMFCRibbonContextCaption* pCaption = DYNAMIC_DOWNCAST(CMFCRibbonContextCaption, &element);
		if (pCaption != NULL)
		{
			info.m_Value = pCaption->GetContextID();
		}
	}

	if (info.m_Value == -1)
	{
		info.m_Value = 0;
	}
}

void CMFCRibbonCollector::GetRibbonBarImages(const CMFCRibbonBar& bar, CMFCRibbonInfo::XRibbonBar& info)
{
	if ((GetFlags() & e_CollectRibbonBarIcons) == 0)
	{
		return;
	}

	CMFCToolBarImages images;
	images.SetImageSize(GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesSmall));
	images.SetTransparentColor((COLORREF)-1);
	images.SetPreMultiplyAutoCheck();

	int nImageIndex = 0;

	CMFCRibbonButtonsGroup& group = (CMFCRibbonButtonsGroup&)(bar.m_TabElements);

	int count = group.GetCount();
	int i = 0;

	for(i = 0; i < count; i++)
	{
		CMFCRibbonButton* pButton = DYNAMIC_DOWNCAST(CMFCRibbonButton, group.GetButton(i));
		if (pButton != NULL)
		{
			HICON hIcon = pButton->GetIcon();
			if (hIcon != NULL)
			{
				if (AfxRibbonCollector::AddIcon(images, hIcon))
				{
					((CMFCRibbonInfo::XElementButton*)info.m_TabElements.m_arButtons[i])->m_nSmallImageIndex = nImageIndex;
					nImageIndex++;
				}
			}
		}
	}

	int index = info.m_bPrintPreview ? 1 : 0;
	int nCategory = 0;
	count = bar.GetCategoryCount();

	for(i = index; i < count; i++)
	{
		CMFCRibbonCategory* pCategory = bar.GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() != 0)
		{
			continue;
		}

		for(int j = 0; j < pCategory->GetPanelCount(); j++)
		{
			CMFCRibbonPanel* pPanel = pCategory->GetPanel(j);
			ASSERT_VALID(pPanel);

			HICON hIcon = ((CMFCRibbonDefaultPanelButton&)pPanel->GetDefaultButton()).m_hIcon;
			if (hIcon != NULL)
			{
				if (AfxRibbonCollector::AddIcon(images, hIcon))
				{
					info.m_arCategories[nCategory]->m_arPanels[j]->m_nImageIndex = nImageIndex;
					nImageIndex++;
				}
			}
		}

		nCategory++;
	}

	int nContext = -1;
	UINT nContextID = 0;
	nCategory = 0;
	for(i = index; i < count; i++)
	{
		CMFCRibbonCategory* pCategory = bar.GetCategory(i);

		UINT nID = pCategory->GetContextID();
		if (nID == 0)
		{
			continue;
		}

		if (nID != nContextID)
		{
			nContextID = nID;
			nContext++;
			nCategory = 0;
		}

		for(int j = 0; j < pCategory->GetPanelCount(); j++)
		{
			CMFCRibbonPanel* pPanel = pCategory->GetPanel(j);
			ASSERT_VALID(pPanel);

			HICON hIcon = ((CMFCRibbonDefaultPanelButton&)pPanel->GetDefaultButton()).m_hIcon;
			if (hIcon != NULL)
			{
				if (AfxRibbonCollector::AddIcon(images, hIcon))
				{
					info.m_arContexts[nContext]->m_arCategories[nCategory]->m_arPanels[j]->m_nImageIndex = nImageIndex;
					nImageIndex++;
				}
			}
		}

		nCategory++;
	}

	if (images.IsValid() && images.GetCount() > 0)
	{
		CollectImageInfo(images, info.m_Images, FALSE);
	}
}

void CMFCRibbonCollector::GetCategoryImages(const CMFCRibbonCategory& category, CMFCRibbonInfo::XCategory& info)
{
	GetCategoryImages(category, info.m_SmallImages, info.m_LargeImages);

	if ((GetFlags() & e_CollectGroupImages) == 0)
	{
		return;
	}

	CMFCRibbonCategory* pCategory = (CMFCRibbonCategory*)&category;
	CMFCToolBarImages& infoSmall = info.m_SmallImages.m_Image;

	if (!infoSmall.IsValid() || infoSmall.GetCount() == 0)
	{
		infoSmall.SetImageSize(GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesSmall));
		infoSmall.SetTransparentColor((COLORREF)-1);
		infoSmall.SetPreMultiplyAutoCheck();
	}

	int nImageIndex = infoSmall.GetCount();
	for(int i = 0; i < pCategory->GetPanelCount(); i++)
	{
		CMFCRibbonPanel* pPanel = pCategory->GetPanel(i);

		for(int j = 0; j < pPanel->GetCount(); j++)
		{
			CMFCRibbonButtonsGroup* pGroup = DYNAMIC_DOWNCAST(CMFCRibbonButtonsGroup, pPanel->GetElement(j));
			if (pGroup == NULL)
			{
				continue;
			}

			CMFCToolBarImages& images = pGroup->m_Images;
			if (!images.IsValid() || images.GetCount() == 0)
			{
				continue;
			}

			CMFCRibbonInfo::XElementGroup* pElementGroup = 
				(CMFCRibbonInfo::XElementGroup*)(info.m_arPanels[i]->m_arElements[j]);

			for(int k = 0; k < pGroup->GetCount(); k++)
			{
				CMFCRibbonButton* pButton = DYNAMIC_DOWNCAST(CMFCRibbonButton, pGroup->GetButton(k));
				if (pButton == NULL)
				{
					continue;
				}

				int nImage = pButton->GetImageIndex(FALSE);
				if (nImage == -1)
				{
					continue;
				}

				((CMFCRibbonInfo::XElementButton*)pElementGroup->m_arButtons[k])->m_nSmallImageIndex = nImageIndex;

				infoSmall.AddImage(images, nImage);
				nImageIndex++;
			}
			/*
			int nImageIndex = infoSmall.m_Image.GetCount();
			for(int k = 0; k < images.GetCount(); k++)
			{
			infoSmall.m_Image.AddImage(images, k);
			}
			*/
		}
	}

	if (infoSmall.GetCount() == 0)
	{
		infoSmall.Clear();
	}
}

void CMFCRibbonCollector::GetCategoryImages(const CMFCRibbonCategory& category, CMFCRibbonInfo::XImage& infoSmall, CMFCRibbonInfo::XImage& infoLarge)
{
	CMFCRibbonCategory* pCategory = (CMFCRibbonCategory*)&category;

	BOOL bCollectImagesID = (GetFlags() & e_CollectImagesID) == e_CollectImagesID;

	CollectImageInfo(pCategory->GetSmallImages(), infoSmall, bCollectImagesID);
	if (infoSmall.m_ID.m_Value == 0 && bCollectImagesID)
	{
		infoSmall.m_ID.m_Value = pCategory->m_uiSmallImagesResID;
	}
	CollectImageInfo(pCategory->GetLargeImages(), infoLarge, bCollectImagesID);
	if (infoLarge.m_ID.m_Value == 0 && bCollectImagesID)
	{
		infoLarge.m_ID.m_Value = pCategory->m_uiLargeImagesResID;
	}
}

void CMFCRibbonCollector::GetElementImages(const CMFCRibbonBaseElement& element, CMFCRibbonInfo::XImage& info)
{
	if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonApplicationButton)))
	{
		CMFCRibbonApplicationButton* pElement = (CMFCRibbonApplicationButton*)&element;

		CollectImageInfo(pElement->m_Image, info, (GetFlags() & e_CollectImagesID) == e_CollectImagesID);
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonButtonsGroup)) && (GetFlags() & e_CollectGroupImages) == 0)
	{
		CMFCRibbonButtonsGroup* pElement = (CMFCRibbonButtonsGroup*)&element;

		CollectImageInfo(pElement->m_Images, info, (GetFlags() & e_CollectImagesID) == e_CollectImagesID);
	}
	else if (element.IsKindOf(RUNTIME_CLASS(CMFCRibbonGallery)))
	{
		CMFCRibbonGallery* pElement = (CMFCRibbonGallery*)&element;

		CollectImageInfo(pElement->m_imagesPalette, info, (GetFlags() & e_CollectImagesID) == e_CollectImagesID);
	}
}

void CMFCRibbonCollector::CollectImageInfo(CMFCToolBarImages& ti, CMFCRibbonInfo::XImage& image, BOOL bCollectID)
{
	if (bCollectID && (ti.m_lstOrigResIds.GetCount() == 1))
	{
		POSITION pos = ti.m_lstOrigResIds.GetHeadPosition();
		if (pos != NULL)
		{
			image.m_ID.m_Value = ti.m_lstOrigResIds.GetNext(pos);
		}
	}

	ti.CopyTo(image.m_Image);
}
