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
#include "afxribbonconstructor.h"
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCRibbonConstructor::CMFCRibbonConstructor(const CMFCRibbonInfo& info) : m_Info(info)
{
}

CMFCRibbonConstructor::~CMFCRibbonConstructor()
{
}

CMFCRibbonPanel* CMFCRibbonConstructor::CreatePanel(CMFCRibbonCategory& category, const CMFCRibbonInfo::XPanel& info) const
{
	HICON hIcon = NULL;
	if (info.m_nImageIndex != -1)
	{
		hIcon = const_cast<CMFCToolBarImages&>(GetInfo().GetRibbonBar().m_Images.m_Image).ExtractIcon(info.m_nImageIndex);
	}

	return category.AddPanel(info.m_strName, hIcon);
}

CMFCRibbonCategory* CMFCRibbonConstructor::CreateCategory(CMFCRibbonBar& bar, const CMFCRibbonInfo::XCategory& info) const
{
	return bar.AddCategory(info.m_strName, 0, 0, GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesSmall), GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesLarge));
}

CMFCRibbonCategory* CMFCRibbonConstructor::CreateCategoryContext(CMFCRibbonBar& bar, const CMFCRibbonInfo::XContext& infoContext, const CMFCRibbonInfo::XCategory& info) const
{
	return bar.AddContextCategory(info.m_strName, infoContext.m_strText, infoContext.m_ID.m_Value, infoContext.m_Color, 0, 0, GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesSmall), GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesLarge));
}

CMFCRibbonMainPanel* CMFCRibbonConstructor::CreateCategoryMain(CMFCRibbonBar& bar, const CMFCRibbonInfo::XCategoryMain& info) const
{
	return bar.AddMainCategory(info.m_strName, 0, 0, GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesSmall), GetInfo().GetImageSize(CMFCRibbonInfo::e_ImagesLarge));
}

CMFCRibbonApplicationButton* CMFCRibbonConstructor::CreateApplicationButton(CMFCRibbonBar& bar) const
{
	bar.m_bAutoDestroyMainButton = TRUE;
	bar.SetApplicationButton(new CMFCRibbonApplicationButton, CSize(45, 45));

	return bar.GetApplicationButton();
}

void CMFCRibbonConstructor::ConstructRibbonBar(CMFCRibbonBar& bar) const
{
	const CMFCRibbonInfo::XRibbonBar& infoBar = GetInfo().GetRibbonBar();

	CMFCRibbonPanel::m_nNextPanelID = (UINT)-10;
	bar.EnableToolTips (infoBar.m_bToolTip, infoBar.m_bToolTipDescr);
	bar.EnableKeyTips (infoBar.m_bKeyTips);
	bar.EnablePrintPreview(infoBar.m_bPrintPreview);
	CMFCRibbonFontComboBox::m_bDrawUsingFont = infoBar.m_bDrawUsingFont;

	if (infoBar.m_btnMain != NULL)
	{
		CMFCRibbonApplicationButton* btnMain = bar.GetApplicationButton();
		if (btnMain == NULL)
		{
			btnMain = CreateApplicationButton(bar);
		}

		if (btnMain != NULL)
		{
			ConstructElement(*btnMain, *infoBar.m_btnMain);
		}
	}

	if (infoBar.m_MainCategory != NULL)
	{
		ConstructCategoryMain(bar, *infoBar.m_MainCategory);
	}

	ConstructTabElements(bar, infoBar);

	int i = 0;
	for(i = 0; i < infoBar.m_arCategories.GetSize(); i++)
	{
		const CMFCRibbonInfo::XCategory& infoCategory = *(const CMFCRibbonInfo::XCategory*)infoBar.m_arCategories[i];

		CMFCRibbonCategory* pCategory = CreateCategory(bar, infoCategory);
		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);
			ConstructCategory(*pCategory, infoCategory);
		}
	}

	for(i = 0; i < infoBar.m_arContexts.GetSize(); i++)
	{
		const CMFCRibbonInfo::XContext* context = infoBar.m_arContexts[i];
		for(int j = 0; j < context->m_arCategories.GetSize(); j++)
		{
			const CMFCRibbonInfo::XCategory& infoCategory = *(const CMFCRibbonInfo::XCategory*)context->m_arCategories[j];

			CMFCRibbonCategory* pCategory = CreateCategoryContext(bar, *context, infoCategory);
			if (pCategory != NULL)
			{
				ASSERT_VALID(pCategory);
				ConstructCategory(*pCategory, infoCategory);
			}
		}
	}

	ConstructQATElements(bar, infoBar);
}

void CMFCRibbonConstructor::ConstructCategoryMain(CMFCRibbonBar& bar, const CMFCRibbonInfo::XCategoryMain& info) const
{
	CMFCRibbonMainPanel* pPanel = CreateCategoryMain(bar, info);
	ASSERT_VALID(pPanel);

	CMFCRibbonCategory* pCategory = bar.GetMainCategory();
	ASSERT_VALID(pCategory);

	const_cast<CMFCToolBarImages&>(info.m_SmallImages.m_Image).CopyTo(pCategory->GetSmallImages());
	const_cast<CMFCToolBarImages&>(info.m_LargeImages.m_Image).CopyTo(pCategory->GetLargeImages());

	int i = 0;
	for(i = 0; i < info.m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElement = CreateElement(*(const CMFCRibbonInfo::XElement*)info.m_arElements[i]);

		if (pElement != NULL)
		{
			ASSERT_VALID(pElement);

			if (info.m_arElements[i]->GetElementType() == CMFCRibbonInfo::e_TypeButton_MainPanel)
			{
				pPanel->AddToBottom((CMFCRibbonMainPanelButton*)pElement);
			}
			else
			{
				pPanel->Add(pElement);
			}
		}
	}

	if (info.m_bRecentListEnable)
	{
		pPanel->AddRecentFilesList(info.m_strRecentListLabel, info.m_nRecentListWidth);
	}
}

void CMFCRibbonConstructor::ConstructCategory(CMFCRibbonCategory& category, const CMFCRibbonInfo::XCategory& info) const
{
	const_cast<CMFCToolBarImages&>(info.m_SmallImages.m_Image).CopyTo(category.GetSmallImages());
	const_cast<CMFCToolBarImages&>(info.m_LargeImages.m_Image).CopyTo(category.GetLargeImages());

	category.SetKeys(info.m_strKeys);

	int i = 0;
	for(i = 0; i < info.m_arPanels.GetSize(); i++)
	{
		const CMFCRibbonInfo::XPanel& infoPanel = *(const CMFCRibbonInfo::XPanel*)info.m_arPanels[i];

		CMFCRibbonPanel* pPanel = CreatePanel(category, infoPanel);
		if (pPanel != NULL)
		{
			ASSERT_VALID(pPanel);
			ConstructPanel(*pPanel, infoPanel);
		}
	}

	for(i = 0; i < info.m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElement = CreateElement(*(const CMFCRibbonInfo::XElement*)info.m_arElements[i]);

		if (pElement != NULL)
		{
			ASSERT_VALID(pElement);
			category.AddHidden(pElement);
		}
	}
}

void CMFCRibbonConstructor::ConstructPanel(CMFCRibbonPanel& panel, const CMFCRibbonInfo::XPanel& info) const
{
	panel.SetKeys(info.m_strKeys);
	panel.SetJustifyColumns(info.m_bJustifyColumns);
	panel.SetCenterColumnVert(info.m_bCenterColumnVert);

	ConstructElement(panel.GetLaunchButton(), info.m_btnLaunch);

	int i = 0;
	for(i = 0; i < info.m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElement = CreateElement(*(const CMFCRibbonInfo::XElement*)info.m_arElements[i]);

		if (pElement != NULL)
		{
			ASSERT_VALID(pElement);

			CMFCRibbonSeparator* pSeparator = DYNAMIC_DOWNCAST(CMFCRibbonSeparator, pElement);
			if (pSeparator)
			{
				panel.AddSeparator();
				delete pSeparator;
			}
			else
			{
				panel.Add(pElement);
			}
		}
	}
}

void CMFCRibbonConstructor::ConstructQATElements(CMFCRibbonBar& bar, const CMFCRibbonInfo::XRibbonBar& info) const
{
	const CMFCRibbonInfo::XQAT::XArrayQATItem& items = info.m_QAT.m_arItems;

	CMFCRibbonQuickAccessToolBarDefaultState qatState;

	int count = (int)items.GetSize();
	for(int i = 0; i < count; i++)
	{
		qatState.AddCommand(items[i].m_ID.m_Value, items[i].m_bVisible);
	}

	bar.SetQuickAccessDefaultState(qatState);
	bar.SetQuickAccessToolbarOnTop(info.m_QAT.m_bOnTop);
}

void CMFCRibbonConstructor::ConstructTabElements(CMFCRibbonBar& bar, const CMFCRibbonInfo::XRibbonBar& info) const
{
	int i = 0;
	for(i = 0; i < info.m_TabElements.m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElement = CreateElement(*(const CMFCRibbonInfo::XElement*)info.m_TabElements.m_arButtons[i]);
		if (pElement != NULL)
		{
			CMFCRibbonButton* pButton = DYNAMIC_DOWNCAST(CMFCRibbonButton, pElement);
			if (pButton != NULL && pButton->GetImageIndex(FALSE) != -1)
			{
				SetIcon(*pButton, CMFCRibbonBaseElement::RibbonImageLarge, GetInfo().GetRibbonBar().m_Images.m_Image, FALSE);
			}

			ASSERT_VALID(pElement);
			bar.AddToTabs(pElement);
		}
	}
}

void CMFCRibbonConstructor::ConstructElement(CMFCRibbonBaseElement& element, const CMFCRibbonInfo::XElement& info) const
{
	if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Application && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonApplicationButton)))
	{
		ConstructBaseElement(element, info);

		const CMFCRibbonInfo::XElementButtonApplication& infoElement = (const CMFCRibbonInfo::XElementButtonApplication&)info;

		CMFCRibbonApplicationButton* pElement = (CMFCRibbonApplicationButton*)&element;
		ASSERT_VALID(pElement);

		const_cast<CMFCToolBarImages&>(infoElement.m_Image.m_Image).CopyTo(pElement->m_Image);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Launch && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonLaunchButton)))
	{
		ConstructBaseElement(element, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeGroup && element.IsKindOf(RUNTIME_CLASS(CMFCRibbonButtonsGroup)))
	{
		const CMFCRibbonInfo::XElementGroup& infoElement = (const CMFCRibbonInfo::XElementGroup&)info;

		CMFCRibbonButtonsGroup* pElement = (CMFCRibbonButtonsGroup*)&element;
		ASSERT_VALID(pElement);

		const_cast<CMFCToolBarImages&>(infoElement.m_Images.m_Image).CopyTo(pElement->m_Images);

		for(int i = 0; i < infoElement.m_arButtons.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pButton = CreateElement(*(const CMFCRibbonInfo::XElement*)infoElement.m_arButtons[i]);

			if (pButton != NULL)
			{
				ASSERT_VALID(pButton);
				pElement->AddButton(pButton);
			}
		}
	}
	else
	{
		ASSERT(FALSE);
	}
}

void CMFCRibbonConstructor::SetID(CMFCRibbonBaseElement& element, const CMFCRibbonInfo::XID& info) const
{
	element.SetID(info.m_Value);
}

void CMFCRibbonConstructor::SetIcon(CMFCRibbonButton& element, CMFCRibbonBaseElement::RibbonImageType type, const CMFCToolBarImages& images, BOOL bLargeIcon/* = FALSE*/) const
{
	CMFCRibbonButton* pButton = (CMFCRibbonButton*)&element;

	HICON* pIcon = &pButton->m_hIconSmall;
	if (type == CMFCRibbonBaseElement::RibbonImageLarge)
	{
		pIcon = &pButton->m_hIcon;
	}

	if (*pIcon != NULL && pButton->m_bAutoDestroyIcon)
	{
		::DestroyIcon(*pIcon);
		*pIcon = NULL;
	}

	*pIcon = const_cast<CMFCToolBarImages&>(images).ExtractIcon(pButton->GetImageIndex(bLargeIcon));
	pButton->m_bAutoDestroyIcon = TRUE;
	pButton->m_bAlphaBlendIcon  = TRUE;

	pButton->SetImageIndex(-1, bLargeIcon);
}

void CMFCRibbonConstructor::ConstructBaseElement(CMFCRibbonBaseElement& element, const CMFCRibbonInfo::XElement& info) const
{
	element.SetText(info.m_strText);
	element.SetToolTipText(info.m_strToolTip);
	element.SetDescription(info.m_strDescription);
	element.SetKeys(info.m_strKeys, info.m_strMenuKeys);

	SetID(element, info.m_ID);

	CMFCRibbonButton* pButton = DYNAMIC_DOWNCAST(CMFCRibbonButton, &element);
	if (pButton != NULL)
	{
		const CMFCRibbonInfo::XElementButton& infoElement = (const CMFCRibbonInfo::XElementButton&)info;

		if (pButton->GetIcon(FALSE) == NULL && pButton->GetIcon(TRUE) == NULL)
		{
			pButton->SetImageIndex(infoElement.m_nSmallImageIndex, FALSE);
			pButton->SetImageIndex(infoElement.m_nLargeImageIndex, TRUE);
		}
		pButton->SetAlwaysLargeImage(info.m_bIsAlwaysLarge);
		pButton->SetDefaultCommand(infoElement.m_bIsDefaultCommand);

		CMFCRibbonGallery* pButtonGallery = DYNAMIC_DOWNCAST(CMFCRibbonGallery, pButton);
		if (pButtonGallery != NULL)
		{
			for(int i = 0; i < infoElement.m_arSubItems.GetSize(); i++)
			{
				CMFCRibbonBaseElement* pSubItem = CreateElement(*(const CMFCRibbonInfo::XElement*)infoElement.m_arSubItems[i]);
				if (pSubItem != NULL)
				{
					pButtonGallery->AddSubItem(pSubItem, -1, infoElement.m_bIsOnPaletteTop);
				}
			}
		}
		else
		{
			for(int i = 0; i < infoElement.m_arSubItems.GetSize(); i++)
			{
				CMFCRibbonBaseElement* pSubItem = CreateElement(*(const CMFCRibbonInfo::XElement*)infoElement.m_arSubItems[i]);
				if (pSubItem != NULL)
				{
					pButton->AddSubItem(pSubItem);

					if (pSubItem->GetID() >= AFX_IDM_WINDOW_FIRST && pSubItem->GetID() <= AFX_IDM_WINDOW_LAST)
					{
						pButton->m_bIsWindowsMenu = TRUE;
					}
				}
			}
		}
	}
}

CMFCRibbonBaseElement* CMFCRibbonConstructor::CreateElement(const CMFCRibbonInfo::XElement& info) const
{
	CMFCRibbonBaseElement* pElement = NULL;

	int i = 0;

	if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Application)
	{
		const CMFCRibbonInfo::XElementButtonApplication& infoElement = (const CMFCRibbonInfo::XElementButtonApplication&)info;

		CMFCRibbonApplicationButton* pNewElement = new CMFCRibbonApplicationButton(infoElement.m_Image.m_Image.GetImageWell());
		pElement = pNewElement;

		ConstructElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Launch)
	{
		CMFCRibbonLaunchButton* pNewElement = new CMFCRibbonLaunchButton;
		pElement = pNewElement;

		ConstructElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeGroup)
	{
		CMFCRibbonButtonsGroup* pNewElement = new CMFCRibbonButtonsGroup;
		pElement = pNewElement;

		ConstructElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeLabel)
	{
		const CMFCRibbonInfo::XElementLabel& infoElement = (const CMFCRibbonInfo::XElementLabel&)info;

		CMFCRibbonLabel* pNewElement = new CMFCRibbonLabel(infoElement.m_strText, infoElement.m_bIsAlwaysLarge);
		pElement = pNewElement;
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeComboBox_Font)
	{
		const CMFCRibbonInfo::XElementFontComboBox& infoElement = (const CMFCRibbonInfo::XElementFontComboBox&)info;

		CMFCRibbonFontComboBox* pNewElement = new CMFCRibbonFontComboBox(infoElement.m_ID.m_Value, infoElement.m_nFontType, infoElement.m_nCharSet, infoElement.m_nPitchAndFamily, infoElement.m_nWidth);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		if (infoElement.m_nWidthFloaty > 0)
		{
			pNewElement->SetWidth(infoElement.m_nWidthFloaty, TRUE);
		}
		((CMFCRibbonFontComboBox*)pNewElement)->m_bHasEditBox = infoElement.m_bHasEditBox;
		pNewElement->EnableDropDownListResize(infoElement.m_bResizeDropDownList);

		BOOL bDontNotify = ((CMFCRibbonEdit*)pNewElement)->m_bDontNotify;
		((CMFCRibbonEdit*)pNewElement)->m_bDontNotify = TRUE;
		if (!infoElement.m_strValue.IsEmpty())
		{
			if (!pNewElement->SelectItem(infoElement.m_strValue) && infoElement.m_bHasEditBox)
			{
				pNewElement->SetEditText(infoElement.m_strValue);
			}
		}
		((CMFCRibbonEdit*)pNewElement)->m_bDontNotify = bDontNotify;
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeComboBox)
	{
		const CMFCRibbonInfo::XElementComboBox& infoElement = (const CMFCRibbonInfo::XElementComboBox&)info;

		CMFCRibbonComboBox* pNewElement = new CMFCRibbonComboBox(infoElement.m_ID.m_Value, infoElement.m_bHasEditBox, infoElement.m_nWidth, infoElement.m_strText, infoElement.m_nSmallImageIndex);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		if (infoElement.m_nWidthFloaty > 0)
		{
			pNewElement->SetWidth(infoElement.m_nWidthFloaty, TRUE);
		}

		pNewElement->EnableDropDownListResize(infoElement.m_bResizeDropDownList);

		for(i = 0; i < infoElement.m_arItems.GetSize(); i++)
		{
			pNewElement->AddItem(infoElement.m_arItems[i]);
		}

		BOOL bDontNotify = ((CMFCRibbonEdit*)pNewElement)->m_bDontNotify;
		((CMFCRibbonEdit*)pNewElement)->m_bDontNotify = TRUE;
		if (!infoElement.m_strValue.IsEmpty())
		{
			if (!pNewElement->SelectItem(infoElement.m_strValue) && infoElement.m_bHasEditBox)
			{
				pNewElement->SetEditText(infoElement.m_strValue);
			}
		}
		((CMFCRibbonEdit*)pNewElement)->m_bDontNotify = bDontNotify;
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeEdit)
	{
		const CMFCRibbonInfo::XElementEdit& infoElement = (const CMFCRibbonInfo::XElementEdit&)info;

		CMFCRibbonEdit* pNewElement = new CMFCRibbonEdit(infoElement.m_ID.m_Value, infoElement.m_nWidth, infoElement.m_strText, infoElement.m_nSmallImageIndex);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		if (infoElement.m_nWidthFloaty > 0)
		{
			pNewElement->SetWidth(infoElement.m_nWidthFloaty, TRUE);
		}

		if (infoElement.m_bHasSpinButtons)
		{
			pNewElement->EnableSpinButtons(infoElement.m_nMin, infoElement.m_nMax);
		}

		BOOL bDontNotify = pNewElement->m_bDontNotify;
		pNewElement->m_bDontNotify = TRUE;
		pNewElement->SetEditText(infoElement.m_strValue);
		pNewElement->m_bDontNotify = bDontNotify;
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Undo)
	{
		const CMFCRibbonInfo::XElementButtonUndo& infoElement = (const CMFCRibbonInfo::XElementButtonUndo&)info;

		CMFCRibbonUndoButton* pNewElement = new CMFCRibbonUndoButton(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_nSmallImageIndex, infoElement.m_nLargeImageIndex);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		pNewElement->SetButtonMode(infoElement.m_bIsButtonMode);
		pNewElement->EnableMenuResize(infoElement.m_bEnableMenuResize, infoElement.m_bMenuResizeVertical);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Color)
	{
		const CMFCRibbonInfo::XElementButtonColor& infoElement = (const CMFCRibbonInfo::XElementButtonColor&)info;

		CMFCRibbonColorButton* pNewElement = new CMFCRibbonColorButton(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_bSimpleButtonLook, infoElement.m_nSmallImageIndex, infoElement.m_nLargeImageIndex, infoElement.m_clrColor);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		pNewElement->EnableAutomaticButton(infoElement.m_strAutomaticBtnLabel.IsEmpty() ? NULL : (LPCTSTR)infoElement.m_strAutomaticBtnLabel, infoElement.m_clrAutomaticBtnColor, !infoElement.m_strAutomaticBtnLabel.IsEmpty(), infoElement.m_strAutomaticBtnToolTip, infoElement.m_bAutomaticBtnOnTop, infoElement.m_bAutomaticBtnBorder);
		pNewElement->EnableOtherButton(infoElement.m_strOtherBtnLabel.IsEmpty() ? NULL : (LPCTSTR)infoElement.m_strOtherBtnLabel, infoElement.m_strOtherBtnToolTip);
		pNewElement->SetColorBoxSize(infoElement.m_sizeIcon);
		pNewElement->SetButtonMode(infoElement.m_bIsButtonMode);
		pNewElement->EnableMenuResize(infoElement.m_bEnableMenuResize, infoElement.m_bMenuResizeVertical);
		pNewElement->SetIconsInRow (infoElement.m_nIconsInRow);

		if (infoElement.m_arGroups.GetSize() == 0)
		{
			if (!infoElement.m_bIsButtonMode)
			{
				pNewElement->AddGroup(_T(""), (int)pNewElement->m_Colors.GetSize());
				pNewElement->m_bHasGroups = TRUE;
			}
		}
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Gallery)
	{
		const CMFCRibbonInfo::XElementButtonGallery& infoElement = (const CMFCRibbonInfo::XElementButtonGallery&)info;

		CMFCRibbonGallery* pNewElement = new CMFCRibbonGallery(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_nSmallImageIndex, infoElement.m_nLargeImageIndex);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		pNewElement->SetButtonMode(infoElement.m_bIsButtonMode);
		pNewElement->EnableMenuResize(infoElement.m_bEnableMenuResize, infoElement.m_bMenuResizeVertical);
		pNewElement->SetIconsInRow (infoElement.m_nIconsInRow);

		pNewElement->Clear();
		const_cast<CMFCToolBarImages&>(infoElement.m_Images.m_Image).CopyTo(pNewElement->m_imagesPalette);
		pNewElement->m_nIcons = pNewElement->m_imagesPalette.GetCount();
		pNewElement->CreateIcons();
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_LinkCtrl)
	{
		const CMFCRibbonInfo::XElementButtonLinkCtrl& infoElement = (const CMFCRibbonInfo::XElementButtonLinkCtrl&)info;

		CMFCRibbonLinkCtrl* pNewElement = new CMFCRibbonLinkCtrl(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_strLink);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_Check)
	{
		const CMFCRibbonInfo::XElementButtonCheck& infoElement = (const CMFCRibbonInfo::XElementButtonCheck&)info;

		CMFCRibbonCheckBox* pNewElement = new CMFCRibbonCheckBox(infoElement.m_ID.m_Value, infoElement.m_strText);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton_MainPanel)
	{
		const CMFCRibbonInfo::XElementButtonMainPanel& infoElement = (const CMFCRibbonInfo::XElementButtonMainPanel&)info;

		CMFCRibbonMainPanelButton* pNewElement = new CMFCRibbonMainPanelButton(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_nSmallImageIndex);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeButton)
	{
		const CMFCRibbonInfo::XElementButton& infoElement = (const CMFCRibbonInfo::XElementButton&)info;

		CMFCRibbonButton* pNewElement = new CMFCRibbonButton(infoElement.m_ID.m_Value, infoElement.m_strText, infoElement.m_nSmallImageIndex, infoElement.m_nLargeImageIndex, infoElement.m_bIsAlwaysShowDescription);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeSlider)
	{
		const CMFCRibbonInfo::XElementSlider& infoElement = (const CMFCRibbonInfo::XElementSlider&)info;

		CMFCRibbonSlider* pNewElement = new CMFCRibbonSlider(infoElement.m_ID.m_Value, infoElement.m_nWidth);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		pNewElement->SetZoomButtons(infoElement.m_bZoomButtons);
		pNewElement->SetRange(infoElement.m_nMin, infoElement.m_nMax);
		pNewElement->SetPos(infoElement.m_nPos, FALSE);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeProgress)
	{
		const CMFCRibbonInfo::XElementProgressBar& infoElement = (const CMFCRibbonInfo::XElementProgressBar&)info;

		CMFCRibbonProgressBar* pNewElement = new CMFCRibbonProgressBar(infoElement.m_ID.m_Value, infoElement.m_nWidth, infoElement.m_nHeight);
		pElement = pNewElement;

		ConstructBaseElement(*pElement, info);

		pNewElement->SetRange(infoElement.m_nMin, infoElement.m_nMax);
		pNewElement->SetPos(infoElement.m_nPos, FALSE);
		pNewElement->SetInfiniteMode(infoElement.m_bInfinite);
	}
	else if (info.GetElementType() == CMFCRibbonInfo::e_TypeSeparator)
	{
		const CMFCRibbonInfo::XElementSeparator& infoElement = (const CMFCRibbonInfo::XElementSeparator&)info;

		CMFCRibbonSeparator* pSeparator = new CMFCRibbonSeparator(infoElement.m_bIsHoriz);
		pElement = pSeparator;
	}

	return pElement;
}
