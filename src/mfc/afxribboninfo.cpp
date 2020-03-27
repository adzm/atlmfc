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
#include "afxribboninfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const DWORD c_dwVersion = MAKELONG(1, 0);

static LPCTSTR s_szTag_Name                 = _T("NAME");
static LPCTSTR s_szTag_Value                = _T("VALUE");
static LPCTSTR s_szTag_Text                 = _T("TEXT");
static LPCTSTR s_szTag_ToolTip              = _T("TOOLTIP");
static LPCTSTR s_szTag_Description          = _T("DESCRIPTION");
static LPCTSTR s_szTag_Keys                 = _T("KEYS");
static LPCTSTR s_szTag_MenuKeys             = _T("KEYS_MENU");
static LPCTSTR s_szTag_ID                   = _T("ID");
static LPCTSTR s_szTag_ID_HDPI              = _T("ID_HDPI");
static LPCTSTR s_szTag_PaletteTop           = _T("PALETTE_TOP");
static LPCTSTR s_szTag_AlwaysLarge          = _T("ALWAYS_LARGE");
static LPCTSTR s_szTag_AlwaysShowDescription= _T("ALWAYS_DESCRIPTION");

static LPCTSTR s_szTag_Index                = _T("INDEX");
static LPCTSTR s_szTag_IndexSmall           = _T("INDEX_SMALL");
static LPCTSTR s_szTag_IndexLarge           = _T("INDEX_LARGE");
static LPCTSTR s_szTag_DefaultCommand       = _T("DEFAULT_COMMAND");
static LPCTSTR s_szTag_Link                 = _T("LINK");
static LPCTSTR s_szTag_Width                = _T("WIDTH");
static LPCTSTR s_szTag_Height               = _T("HEIGHT");
static LPCTSTR s_szTag_WidthFloaty          = _T("WIDTH_FLOATY");
static LPCTSTR s_szTag_SpinButtons          = _T("SPIN_BUTTONS");
static LPCTSTR s_szTag_Min                  = _T("MIN");
static LPCTSTR s_szTag_Max                  = _T("MAX");

static LPCTSTR s_szTag_EditBox              = _T("EDIT_BOX");
static LPCTSTR s_szTag_DropDownList         = _T("DROPDOWN_LIST");
static LPCTSTR s_szTag_ResizeDropDownList   = _T("DROPDOWN_LIST_RESIZE");

static LPCTSTR s_szTag_FontType             = _T("FONT_TYPE");
static LPCTSTR s_szTag_CharSet              = _T("CHAR_SET");
static LPCTSTR s_szTag_PitchAndFamily       = _T("PITCH_AND_FAMILY");

static LPCTSTR s_szTag_ButtonMode           = _T("BUTTON_MODE");
static LPCTSTR s_szTag_MenuResize           = _T("MENU_RESIZE");
static LPCTSTR s_szTag_MenuResizeVertical   = _T("MENU_RESIZE_VERTICAL");
static LPCTSTR s_szTag_IconsInRow           = _T("ICONS_IN_ROW");
static LPCTSTR s_szTag_SizeIcon             = _T("SIZE_ICON");

static LPCTSTR s_szTag_Color                = _T("COLOR");
static LPCTSTR s_szTag_SimpleButtonLook     = _T("SIMPLE_LOOK");
static LPCTSTR s_szTag_AutomaticColorBtn    = _T("AUTOMATIC_BTN");
static LPCTSTR s_szTag_OtherColorBtn        = _T("OTHER_BTN");
static LPCTSTR s_szTag_Border               = _T("BORDER");

static LPCTSTR s_szTag_Style                = _T("STYLE");
static LPCTSTR s_szTag_Pos                  = _T("POS");
static LPCTSTR s_szTag_ZoomButtons          = _T("ZOOM_BUTTONS");

static LPCTSTR s_szTag_Horiz                = _T("HORIZ");

static LPCTSTR s_szTag_AlmostLargeText      = _T("ALMOST_LARGE_TEXT");
static LPCTSTR s_szTag_Static               = _T("STATIC");

static LPCTSTR s_szTag_QATTop               = _T("QAT_TOP");
static LPCTSTR s_szTag_JustifyColumns       = _T("JUSTIFY_COLUMNS");
static LPCTSTR s_szTag_CenterColumnVert     = _T("CENTER_COLUMN_VERT");

static LPCTSTR s_szTag_Enable               = _T("ENABLE");
static LPCTSTR s_szTag_EnableToolTips       = _T("ENABLE_TOOLTIPS");
static LPCTSTR s_szTag_EnableToolTipsDescr  = _T("ENABLE_TOOLTIPS_DESCRIPTION");
static LPCTSTR s_szTag_EnableKeys           = _T("ENABLE_KEYS");
static LPCTSTR s_szTag_EnablePrintPreview   = _T("ENABLE_PRINTPREVIEW");
static LPCTSTR s_szTag_DrawUsingFont        = _T("ENABLE_DRAWUSINGFONT");

static LPCTSTR s_szTag_Label                = _T("LABEL");
static LPCTSTR s_szTag_Visible              = _T("VISIBLE");
static LPCTSTR s_szTag_Infinite             = _T("INFINITE");

static LPCTSTR s_szTag_RecentFileList       = _T("RECENT_FILE_LIST");

static LPCTSTR s_szTag_ElementName          = _T("ELEMENT_NAME");
static LPCTSTR s_szTag_Element              = _T("ELEMENT");
static LPCTSTR s_szTag_Elements             = _T("ELEMENTS");
static LPCTSTR s_szTag_ElementsExtended     = _T("ELEMENTS_EXTENDED");
static LPCTSTR s_szTag_Item                 = _T("ITEM");
static LPCTSTR s_szTag_Items                = _T("ITEMS");
static LPCTSTR s_szTag_Panel                = _T("PANEL");
static LPCTSTR s_szTag_Panels               = _T("PANELS");
static LPCTSTR s_szTag_Category             = _T("CATEGORY");
static LPCTSTR s_szTag_Categories           = _T("CATEGORIES");
static LPCTSTR s_szTag_Context              = _T("CONTEXT");
static LPCTSTR s_szTag_Contexts             = _T("CONTEXTS");
static LPCTSTR s_szTag_Group                = _T("GROUP");
static LPCTSTR s_szTag_Groups               = _T("GROUPS");
static LPCTSTR s_szTag_Button_Main          = _T("BUTTON_MAIN");
static LPCTSTR s_szTag_QAT_Elements         = _T("QAT_ELEMENTS");
static LPCTSTR s_szTag_Tab_Elements         = _T("TAB_ELEMENTS");
static LPCTSTR s_szTag_Button_Launch        = _T("BUTTON_LAUNCH");
static LPCTSTR s_szTag_CategoryMain         = _T("CATEGORY_MAIN");

static LPCTSTR s_szTag_Image                = _T("IMAGE");
static LPCTSTR s_szTag_Image_Small          = _T("IMAGE_SMALL");
static LPCTSTR s_szTag_Image_Large          = _T("IMAGE_LARGE");

static LPCTSTR s_szElementNames[] =
{
	_T("Button"),
	_T("Button_Check"),
	_T("Button_Color"),
	_T("Button_Undo"),
	_T("Button_Gallery"),
	_T("Button_LinkCtrl"),
	_T("Button_Main"),
	_T("Button_Main_Panel"),
	_T("Button_Launch"),
	_T("Label"),
	_T("Edit"),
	_T("ComboBox"),
	_T("ComboBox_Font"),
	_T("Slider"),
	_T("Progress"),
	_T("Separator"),
	_T("Group"),
	_T("Panel"),
	_T("Category"),
	_T("Context"),
	_T("Category_Main"),
	_T("QAT"),
	_T("RibbonBar")
};

static BOOL ReadID(const CString& strTag, CMFCRibbonInfo::XID& id, CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bRet = TRUE;

	CMFCRibbonInfo::XRibbonInfoParser* pParserID = NULL;
	rParser.Read(strTag, &pParserID);
	if (pParserID != NULL)
	{
		bRet = id.Read(*pParserID);
		delete pParserID;
	}

	return bRet;
}

static BOOL WriteID(const CString& strTag, CMFCRibbonInfo::XID& id, CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bRet = TRUE;

	if (!id.IsEmpty())
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserID = NULL;
		rParser.Add(strTag, &pParserID);
		if (pParserID != NULL)
		{
			bRet = id.Write(*pParserID);
			delete pParserID;
		}
	}

	return bRet;
}

static BOOL ReadImage(const CString& strTag, CMFCRibbonInfo::XImage& image, CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bRet = TRUE;

	CMFCRibbonInfo::XRibbonInfoParser* pParserImage = NULL;
	rParser.Read(strTag, &pParserImage);
	if (pParserImage != NULL)
	{
		bRet = image.Read(*pParserImage);
		delete pParserImage;
	}

	return bRet;
}

static BOOL WriteImage(const CString& strTag, CMFCRibbonInfo::XImage& image, CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bRet = TRUE;

	if (!image.IsEmpty())
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserImage = NULL;
		rParser.Add(strTag, &pParserImage);
		if (pParserImage != NULL)
		{
			bRet = image.Write(*pParserImage);
			delete pParserImage;
		}
	}

	return bRet;
}


LPCTSTR __stdcall CMFCRibbonInfo::ElementNameFromType(CMFCRibbonInfo::XElementType type)
{
	if (CMFCRibbonInfo::e_TypeFirst < type && type <= CMFCRibbonInfo::e_TypeLast)
	{
		return s_szElementNames[type];
	}

	return NULL;
}

CMFCRibbonInfo::XElementType __stdcall CMFCRibbonInfo::ElementTypeFromName(const CString& name)
{
	CMFCRibbonInfo::XElementType type = CMFCRibbonInfo::e_TypeFirst;

	if (!name.IsEmpty())
	{
		for (int i = 0; i < _countof(s_szElementNames); i++)
		{
			if (name.CompareNoCase(s_szElementNames[i]) == 0)
			{
				type = (CMFCRibbonInfo::XElementType)i;
				break;
			}
		}
	}

	return type;
}

CMFCRibbonInfo::XInfoError::XInfoError()
{
	Empty();
}

CMFCRibbonInfo::XInfoError::~XInfoError()
{
}

void CMFCRibbonInfo::XInfoError::Empty()
{
	m_Error    = e_ErrorNone;
	m_nLine    = -1;
	m_nLinePos = -1;
	m_strDescription.Empty();
}

void CMFCRibbonInfo::XInfoError::SetError(CMFCRibbonInfo::XInfoError::XError error, const CString& strDescription, long nLine, long nLinePos)
{
	Empty();

	m_Error          = error;
	m_strDescription = strDescription;
	m_nLine          = nLine;
	m_nLinePos       = nLinePos;
}


CMFCRibbonInfo::XID::XID()
: m_Value(0)
{
}

CMFCRibbonInfo::XID::~XID()
{
}


CMFCRibbonInfo::XImage::XImage()
{
}

CMFCRibbonInfo::XImage::~XImage()
{
}

CMFCRibbonInfo::XBase::XBase(XElementType type)
: m_ElementType(type)
{
}

CMFCRibbonInfo::XBase::~XBase()
{
}

CMFCRibbonInfo::XElement::XElement(XElementType type)
: CMFCRibbonInfo::XBase(type), m_bIsOnPaletteTop(FALSE), m_bIsAlwaysLarge(FALSE)
{
}

CMFCRibbonInfo::XElement::~XElement()
{
}

CMFCRibbonInfo::XElementSeparator::XElementSeparator()
: CMFCRibbonInfo::XElement(CMFCRibbonInfo::e_TypeSeparator), m_bIsHoriz(FALSE)
{
}

CMFCRibbonInfo::XElementSeparator::~XElementSeparator()
{
}

CMFCRibbonInfo::XElementGroup::XElementGroup()
: CMFCRibbonInfo::XElement(CMFCRibbonInfo::e_TypeGroup)
{
}

CMFCRibbonInfo::XElementGroup::~XElementGroup()
{
	for (INT_PTR i = 0; i < m_arButtons.GetSize(); i++)
	{
		if (m_arButtons[i] != NULL)
		{
			delete m_arButtons[i];
		}
	}
}

CMFCRibbonInfo::XElementButton::XElementButton(XElementType type)
: CMFCRibbonInfo::XElement(type), m_nSmallImageIndex(-1), m_nLargeImageIndex(-1), m_bIsDefaultCommand(TRUE)
{
}

CMFCRibbonInfo::XElementButton::XElementButton()
: CMFCRibbonInfo::XElement(CMFCRibbonInfo::e_TypeButton), m_nSmallImageIndex(-1), m_nLargeImageIndex(-1), m_bIsDefaultCommand(TRUE), m_bIsAlwaysShowDescription(FALSE)
{
}

CMFCRibbonInfo::XElementButton::~XElementButton()
{
	for (INT_PTR i = 0; i < m_arSubItems.GetSize(); i++)
	{
		if (m_arSubItems[i] != NULL)
		{
			delete m_arSubItems[i];
		}
	}
}

CMFCRibbonInfo::XElementLabel::XElementLabel()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeLabel)
{
}

CMFCRibbonInfo::XElementLabel::~XElementLabel()
{
}

CMFCRibbonInfo::XElementButtonCheck::XElementButtonCheck()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_Check)
{
}

CMFCRibbonInfo::XElementButtonCheck::~XElementButtonCheck()
{
}

CMFCRibbonInfo::XElementButtonLinkCtrl::XElementButtonLinkCtrl()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_LinkCtrl)
{
}

CMFCRibbonInfo::XElementButtonLinkCtrl::~XElementButtonLinkCtrl()
{
}

CMFCRibbonInfo::XElementEdit::XElementEdit(XElementType type)
: CMFCRibbonInfo::XElementButton(type), m_nWidth(0), m_nWidthFloaty(0), m_bHasSpinButtons(FALSE), m_nMin(INT_MAX), m_nMax(INT_MAX)
{
}

CMFCRibbonInfo::XElementEdit::XElementEdit()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeEdit), m_nWidth(0), m_nWidthFloaty(0), m_bHasSpinButtons(FALSE), m_nMin(INT_MAX), m_nMax(INT_MAX)
{
}

CMFCRibbonInfo::XElementEdit::~XElementEdit()
{
}

CMFCRibbonInfo::XElementComboBox::XElementComboBox(XElementType type)
: CMFCRibbonInfo::XElementEdit(type), m_bHasEditBox(FALSE), m_bHasDropDownList(TRUE), m_bResizeDropDownList(TRUE)
{
	m_nWidth = 108;
}

CMFCRibbonInfo::XElementComboBox::XElementComboBox()
: CMFCRibbonInfo::XElementEdit(CMFCRibbonInfo::e_TypeComboBox), m_bHasEditBox(FALSE), m_bHasDropDownList(TRUE), m_bResizeDropDownList(TRUE)
{
	m_nWidth = 108;
}

CMFCRibbonInfo::XElementComboBox::~XElementComboBox()
{
}

CMFCRibbonInfo::XElementFontComboBox::XElementFontComboBox()
: CMFCRibbonInfo::XElementComboBox(CMFCRibbonInfo::e_TypeComboBox_Font), m_nFontType(DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE), m_nCharSet(DEFAULT_CHARSET), m_nPitchAndFamily(DEFAULT_PITCH)
{
	m_bHasEditBox = TRUE;
}

CMFCRibbonInfo::XElementFontComboBox::~XElementFontComboBox()
{
}

CMFCRibbonInfo::XElementButtonGallery::XGalleryGroup::XGalleryGroup()
: m_nItems (0)
{
}

CMFCRibbonInfo::XElementButtonGallery::XGalleryGroup::~XGalleryGroup()
{
}

CMFCRibbonInfo::XElementButtonGallery::XElementButtonGallery(XElementType type)
: CMFCRibbonInfo::XElementButton(type), m_bIsButtonMode(TRUE), m_bEnableMenuResize(FALSE), m_bMenuResizeVertical(FALSE), m_nIconsInRow(-1), m_sizeIcon(0, 0)
{
}

CMFCRibbonInfo::XElementButtonGallery::XElementButtonGallery()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_Gallery), m_bIsButtonMode(TRUE), m_bEnableMenuResize(FALSE), m_bMenuResizeVertical(FALSE), m_nIconsInRow(-1), m_sizeIcon(0, 0)
{
}

CMFCRibbonInfo::XElementButtonGallery::~XElementButtonGallery()
{
	for (INT_PTR i = 0; i < m_arGroups.GetSize(); i++)
	{
		if (m_arGroups[i] != NULL)
		{
			delete m_arGroups[i];
		}
	}
}

CMFCRibbonInfo::XElementButtonColor::XElementButtonColor()
: CMFCRibbonInfo::XElementButtonGallery(CMFCRibbonInfo::e_TypeButton_Color), m_clrColor(RGB(0, 0, 0)), m_bSimpleButtonLook(FALSE), m_clrAutomaticBtnColor(RGB (0, 0, 0)), m_bAutomaticBtnOnTop(TRUE), m_bAutomaticBtnBorder(FALSE)
{
	m_sizeIcon    = CSize(22, 22);
	m_nIconsInRow = 5;
}

CMFCRibbonInfo::XElementButtonColor::~XElementButtonColor()
{
}

CMFCRibbonInfo::XElementButtonUndo::XElementButtonUndo()
: CMFCRibbonInfo::XElementButtonGallery(CMFCRibbonInfo::e_TypeButton_Undo)
{
}

CMFCRibbonInfo::XElementButtonUndo::~XElementButtonUndo()
{
}

CMFCRibbonInfo::XElementButtonLaunch::XElementButtonLaunch()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_Launch)
{
}

CMFCRibbonInfo::XElementButtonLaunch::~XElementButtonLaunch()
{
}

CMFCRibbonInfo::XElementButtonApplication::XElementButtonApplication()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_Application)
{
}

CMFCRibbonInfo::XElementButtonApplication::~XElementButtonApplication()
{
}

CMFCRibbonInfo::XElementButtonMainPanel::XElementButtonMainPanel()
: CMFCRibbonInfo::XElementButton(CMFCRibbonInfo::e_TypeButton_MainPanel)
{
}

CMFCRibbonInfo::XElementButtonMainPanel::~XElementButtonMainPanel()
{
}

CMFCRibbonInfo::XElementSlider::XElementSlider()
: CMFCRibbonInfo::XElement(CMFCRibbonInfo::e_TypeSlider), m_dwStyle(0), m_nWidth(100), m_nMin(0), m_nMax(100), m_nPos(0), m_bZoomButtons(FALSE)
{
}

CMFCRibbonInfo::XElementSlider::~XElementSlider()
{
}

CMFCRibbonInfo::XElementProgressBar::XElementProgressBar()
: CMFCRibbonInfo::XElement(CMFCRibbonInfo::e_TypeProgress), m_nWidth(100), m_nHeight(22), m_nMin(0), m_nMax(100), m_nPos(0), m_bInfinite(FALSE)
{
}

CMFCRibbonInfo::XElementProgressBar::~XElementProgressBar()
{
}

CMFCRibbonInfo::XPanel::XPanel()
: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypePanel), m_nImageIndex(-1), m_bJustifyColumns(FALSE), m_bCenterColumnVert(FALSE)
{
}

CMFCRibbonInfo::XPanel::~XPanel()
{
	for (INT_PTR i = 0; i < m_arElements.GetSize(); i++)
	{
		if (m_arElements[i] != NULL)
		{
			delete m_arElements[i];
		}
	}
}

CMFCRibbonInfo::XCategory::XCategory()
: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypeCategory)
{
}

CMFCRibbonInfo::XCategory::~XCategory()
{
	INT_PTR i = 0;
	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		if (m_arPanels[i] != NULL)
		{
			delete m_arPanels[i];
		}
	}

	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		if (m_arElements[i] != NULL)
		{
			delete m_arElements[i];
		}
	}
}

CMFCRibbonInfo::XContext::XContext()
: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypeContext), m_Color(AFX_CategoryColor_None)
{
}

CMFCRibbonInfo::XContext::~XContext()
{
	for (INT_PTR i = 0; i < m_arCategories.GetSize(); i++)
	{
		if (m_arCategories[i] != NULL)
		{
			delete m_arCategories[i];
		}
	}
}

CMFCRibbonInfo::XCategoryMain::XCategoryMain()
: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypeCategoryMain), m_bRecentListEnable(FALSE), m_nRecentListWidth(300)
{
}

CMFCRibbonInfo::XCategoryMain::~XCategoryMain()
{
	for (INT_PTR i = 0; i < m_arElements.GetSize(); i++)
	{
		if (m_arElements[i] != NULL)
		{
			delete m_arElements[i];
		}
	}
}

CMFCRibbonInfo::XQAT::XQATItem::XQATItem()
: m_bVisible(TRUE)
{
}

CMFCRibbonInfo::XQAT::XQATItem::~XQATItem()
{
}

CMFCRibbonInfo::XQAT::XQAT()
: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypeQAT), m_bOnTop(TRUE)
{
}

CMFCRibbonInfo::XQAT::~XQAT()
{
	m_arItems.RemoveAll();
}


INT_PTR CMFCRibbonInfo::XQAT::AddItem(const CMFCRibbonInfo::XQAT::XQATItem& rItem)
{
	return m_arItems.Add(rItem);
}

CMFCRibbonInfo::XRibbonBar::XRibbonBar()
	: CMFCRibbonInfo::XBase(CMFCRibbonInfo::e_TypeRibbonBar)
	, m_bToolTip(TRUE)
	, m_bToolTipDescr(TRUE)
	, m_bKeyTips(TRUE)
	, m_bPrintPreview(TRUE)
	, m_bDrawUsingFont(FALSE)
	, m_MainCategory(NULL)
	, m_btnMain(NULL)
{
}

CMFCRibbonInfo::XRibbonBar::~XRibbonBar()
{
	if (m_btnMain != NULL)
	{
		delete m_btnMain;
	}

	if (m_MainCategory != NULL)
	{
		delete m_MainCategory;
	}

	INT_PTR i = 0;
	for (i = 0; i < m_arCategories.GetSize(); i++)
	{
		if (m_arCategories[i] != NULL)
		{
			delete m_arCategories[i];
		}
	}

	for (i = 0; i < m_arContexts.GetSize(); i++)
	{
		if (m_arContexts[i] != NULL)
		{
			delete m_arContexts[i];
		}
	}
}

BOOL CMFCRibbonInfo::XID::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bResult = rParser.ReadString(s_szTag_Name, m_Name);

	UINT nValue = m_Value;
	if (rParser.ReadUInt(s_szTag_Value, nValue))
	{
		bResult = TRUE;
	}
	m_Value = (UINT)nValue;

	return bResult;
}

BOOL CMFCRibbonInfo::XID::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	BOOL bResult = rParser.WriteString(s_szTag_Name, m_Name);
	if (rParser.WriteUInt(s_szTag_Value, m_Value, 0))
	{
		bResult = TRUE;
	}

	return bResult;
}


BOOL CMFCRibbonInfo::XImage::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!ReadID(s_szTag_ID, m_ID, rParser))
	{
		return rParser.ReadValue(m_ID.m_Name);
	}

	ReadID(s_szTag_ID_HDPI, m_ID_HDPI, rParser);

	return TRUE;
}

BOOL CMFCRibbonInfo::XImage::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	WriteID(s_szTag_ID, m_ID, rParser);
	WriteID(s_szTag_ID_HDPI, m_ID_HDPI, rParser);

	return TRUE;
}


CMFCRibbonInfo::XBase* __stdcall CMFCRibbonInfo::XBase::CreateFromType(CMFCRibbonInfo::XElementType type)
{
	CMFCRibbonInfo::XBase* base = NULL;

	switch (type)
	{
	case CMFCRibbonInfo::e_TypePanel:
		base = new CMFCRibbonInfo::XPanel;
		break;
	case CMFCRibbonInfo::e_TypeCategoryMain:
		base = new CMFCRibbonInfo::XCategoryMain;
		break;
	case CMFCRibbonInfo::e_TypeCategory:
		base = new CMFCRibbonInfo::XCategory;
		break;
	case CMFCRibbonInfo::e_TypeRibbonBar:
		base = new CMFCRibbonInfo::XRibbonBar;
		break;
	case CMFCRibbonInfo::e_TypeQAT:
		base = new CMFCRibbonInfo::XQAT;
		break;
	case CMFCRibbonInfo::e_TypeContext:
		base = new CMFCRibbonInfo::XContext;
		break;
	default:
		base = CMFCRibbonInfo::XElement::CreateFromType(type);
		break;
	}

	return base;
}

CMFCRibbonInfo::XBase* __stdcall CMFCRibbonInfo::XBase::CreateFromTag(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XBase* base = NULL;

	CString strElementName;
	rParser.ReadString(s_szTag_ElementName, strElementName);

	if (!strElementName.IsEmpty())
	{
		base = CMFCRibbonInfo::XBase::CreateFromType(CMFCRibbonInfo::ElementTypeFromName(strElementName));
		if (base != NULL)
		{
			base->Read(rParser);
		}
	}

	return base;
}

BOOL CMFCRibbonInfo::XBase::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	LPCTSTR szName = CMFCRibbonInfo::ElementNameFromType(m_ElementType);
	if (szName != NULL)
	{
		return rParser.WriteString(s_szTag_ElementName, szName);
	}

	return TRUE;
}

CMFCRibbonInfo::XElement* __stdcall CMFCRibbonInfo::XElement::CreateFromType(CMFCRibbonInfo::XElementType type)
{
	CMFCRibbonInfo::XElement* element = NULL;

	switch (type)
	{
	case CMFCRibbonInfo::e_TypeButton:
		element = new CMFCRibbonInfo::XElementButton;
		break;
	case CMFCRibbonInfo::e_TypeButton_Check:
		element = new CMFCRibbonInfo::XElementButtonCheck;
		break;
	case CMFCRibbonInfo::e_TypeButton_Color:
		element = new CMFCRibbonInfo::XElementButtonColor;
		break;
	case CMFCRibbonInfo::e_TypeButton_Undo:
		element = new CMFCRibbonInfo::XElementButtonUndo;
		break;
	case CMFCRibbonInfo::e_TypeButton_Gallery:
		element = new CMFCRibbonInfo::XElementButtonGallery;
		break;
	case CMFCRibbonInfo::e_TypeButton_LinkCtrl:
		element = new CMFCRibbonInfo::XElementButtonLinkCtrl;
		break;
	case CMFCRibbonInfo::e_TypeButton_Application:
		element = new CMFCRibbonInfo::XElementButtonApplication;
		break;
	case CMFCRibbonInfo::e_TypeButton_MainPanel:
		element = new CMFCRibbonInfo::XElementButtonMainPanel;
		break;
	case CMFCRibbonInfo::e_TypeButton_Launch:
		element = new CMFCRibbonInfo::XElementButtonLaunch;
		break;
	case CMFCRibbonInfo::e_TypeLabel:
		element = new CMFCRibbonInfo::XElementLabel;
		break;
	case CMFCRibbonInfo::e_TypeEdit:
		element = new CMFCRibbonInfo::XElementEdit;
		break;
	case CMFCRibbonInfo::e_TypeComboBox:
		element = new CMFCRibbonInfo::XElementComboBox;
		break;
	case CMFCRibbonInfo::e_TypeComboBox_Font:
		element = new CMFCRibbonInfo::XElementFontComboBox;
		break;
	case CMFCRibbonInfo::e_TypeSlider:
		element = new CMFCRibbonInfo::XElementSlider;
		break;
	case CMFCRibbonInfo::e_TypeProgress:
		element = new CMFCRibbonInfo::XElementProgressBar;
		break;
	case CMFCRibbonInfo::e_TypeSeparator:
		element = new CMFCRibbonInfo::XElementSeparator;
		break;
	case CMFCRibbonInfo::e_TypeGroup:
		element = new CMFCRibbonInfo::XElementGroup;
		break;
	}

	return element;
}

BOOL CMFCRibbonInfo::XElement::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	ReadID(s_szTag_ID, m_ID, rParser);

	rParser.ReadString(s_szTag_Text, m_strText);
	rParser.ReadString(s_szTag_ToolTip, m_strToolTip);
	rParser.ReadString(s_szTag_Description, m_strDescription);
	rParser.ReadString(s_szTag_Keys, m_strKeys);
	rParser.ReadString(s_szTag_MenuKeys, m_strMenuKeys);
	rParser.ReadBool(s_szTag_PaletteTop, m_bIsOnPaletteTop);
	rParser.ReadBool(s_szTag_AlwaysLarge, m_bIsAlwaysLarge);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElement::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	WriteID(s_szTag_ID, m_ID, rParser);

	rParser.WriteString(s_szTag_Text, m_strText);
	rParser.WriteString(s_szTag_ToolTip, m_strToolTip);
	rParser.WriteString(s_szTag_Description, m_strDescription);
	rParser.WriteString(s_szTag_Keys, m_strKeys);
	rParser.WriteString(s_szTag_MenuKeys, m_strMenuKeys);
	rParser.WriteBool(s_szTag_PaletteTop, m_bIsOnPaletteTop, FALSE);
	rParser.WriteBool(s_szTag_AlwaysLarge, m_bIsAlwaysLarge, FALSE);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementSeparator::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadBool(s_szTag_Horiz, m_bIsHoriz);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementSeparator::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteBool(s_szTag_Horiz, m_bIsHoriz, FALSE);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementGroup::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Read(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pElements->ReadCollection(s_szTag_Element, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XElement* pElement = (XElement*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pElement != NULL)
					{
						m_arButtons.Add(pElement);
					}
				}
			}

			delete pList;
		}

		delete pElements;
	}

	ReadImage(s_szTag_Image, m_Images, rParser);

	return m_arButtons.GetSize() > 0;
}

BOOL CMFCRibbonInfo::XElementGroup::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (m_arButtons.GetSize() == 0)
	{
		return TRUE;
	}

	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	WriteImage(s_szTag_Image, m_Images, rParser);

	BOOL bResult = FALSE;

	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Add(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		bResult = TRUE;

		for (INT_PTR i = 0; i < m_arButtons.GetSize(); i++)
		{
			CMFCRibbonInfo::XRibbonInfoParser* pElement = NULL;
			pElements->Add(s_szTag_Element, &pElement);
			if (pElement != NULL)
			{
				if (!m_arButtons[i]->Write(*pElement))
				{
					bResult = FALSE;
				}

				delete pElement;
			}
			else
			{
				bResult = FALSE;
			}
		}

		delete pElements;
	}

	return bResult;
}

BOOL CMFCRibbonInfo::XElementButton::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Read(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pElements->ReadCollection(s_szTag_Element, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XElement* pElement = (XElement*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pElement != NULL)
					{
						m_arSubItems.Add(pElement);
					}
				}
			}

			delete pList;
		}

		delete pElements;
	}

	rParser.ReadInt(s_szTag_IndexSmall, m_nSmallImageIndex);
	rParser.ReadInt(s_szTag_IndexLarge, m_nLargeImageIndex);
	rParser.ReadBool(s_szTag_DefaultCommand, m_bIsDefaultCommand);
	rParser.ReadBool(s_szTag_AlwaysShowDescription, m_bIsAlwaysShowDescription);

	return XElement::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButton::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElement::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteInt(s_szTag_IndexSmall, m_nSmallImageIndex, -1);
	rParser.WriteInt(s_szTag_IndexLarge, m_nLargeImageIndex, -1);
	rParser.WriteBool(s_szTag_DefaultCommand, m_bIsDefaultCommand, TRUE);

	if (GetElementType() == CMFCRibbonInfo::e_TypeButton)
	{
		rParser.WriteBool(s_szTag_AlwaysShowDescription, m_bIsAlwaysShowDescription, FALSE);
	}

	CString strElements;

	if (m_arSubItems.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
		rParser.Add(s_szTag_Elements, &pElements);
		if (pElements != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arSubItems.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pElement = NULL;
				pElements->Add(s_szTag_Element, &pElement);
				if (pElement != NULL)
				{
					if (!m_arSubItems[i]->Write(*pElement))
					{
						bResult = FALSE;
					}

					delete pElement;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pElements;
		}

		return bResult;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementLabel::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementLabel::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Write(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonCheck::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonCheck::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Write(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonLinkCtrl::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadString(s_szTag_Link, m_strLink);

	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonLinkCtrl::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementButton::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteString(s_szTag_Link, m_strLink);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementEdit::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadInt(s_szTag_Width, m_nWidth);
	rParser.ReadInt(s_szTag_WidthFloaty, m_nWidthFloaty);
	rParser.ReadBool(s_szTag_SpinButtons, m_bHasSpinButtons);
	if (m_bHasSpinButtons)
	{
		rParser.ReadInt(s_szTag_Min, m_nMin);
		rParser.ReadInt(s_szTag_Max, m_nMax);
	}
	rParser.ReadString(s_szTag_Value, m_strValue);

	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementEdit::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementButton::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteInt(s_szTag_Width, m_nWidth, 0);
	rParser.WriteInt(s_szTag_WidthFloaty, m_nWidthFloaty, 0);
	rParser.WriteBool(s_szTag_SpinButtons, m_bHasSpinButtons, FALSE);
	if (m_bHasSpinButtons)
	{
		rParser.WriteInt(s_szTag_Min, m_nMin, INT_MAX);
		rParser.WriteInt(s_szTag_Max, m_nMax, INT_MAX);
	}
	rParser.WriteString(s_szTag_Value, m_strValue);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementComboBox::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pItems = NULL;
	rParser.Read(s_szTag_Items, &pItems);
	if (pItems != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pItems->ReadCollection(s_szTag_Item, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					CString strItem;
					if (pListItem->ReadValue(strItem))
					{
						m_arItems.Add(strItem);
					}
				}
			}

			delete pList;
		}

		delete pItems;
	}

	rParser.ReadBool(s_szTag_EditBox, m_bHasEditBox);
	rParser.ReadBool(s_szTag_DropDownList, m_bHasDropDownList);
	rParser.ReadBool(s_szTag_ResizeDropDownList, m_bResizeDropDownList);
    rParser.ReadString(s_szTag_Value, m_strValue);

	return XElementEdit::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementComboBox::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementEdit::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteBool(s_szTag_EditBox, m_bHasEditBox, FALSE);
	rParser.WriteBool(s_szTag_DropDownList, m_bHasDropDownList, TRUE);
	rParser.WriteBool(s_szTag_ResizeDropDownList, m_bResizeDropDownList, TRUE);
    rParser.WriteString(s_szTag_Value, m_strValue);

	if (m_arItems.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pItems = NULL;
		rParser.Add(s_szTag_Items, &pItems);
		if (pItems != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arItems.GetSize(); i++)
			{
				pItems->WriteString(s_szTag_Item, m_arItems[i], m_arItems[i] + _T("_"));
			}

			delete pItems;
		}

		return bResult;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementFontComboBox::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadInt(s_szTag_FontType, m_nFontType);

	int nValue = m_nCharSet;
	rParser.ReadInt(s_szTag_CharSet, nValue);
	m_nCharSet = (BYTE)nValue;

	nValue = m_nPitchAndFamily;
	rParser.ReadInt(s_szTag_PitchAndFamily, nValue);
	m_nPitchAndFamily = (BYTE)nValue;

	return XElementComboBox::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementFontComboBox::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementComboBox::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteInt(s_szTag_FontType, m_nFontType, DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE);
	rParser.WriteInt(s_szTag_CharSet, m_nCharSet, DEFAULT_CHARSET);
	rParser.WriteInt(s_szTag_PitchAndFamily, m_nPitchAndFamily, DEFAULT_PITCH);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonGallery::XGalleryGroup::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadString(s_szTag_Name, m_strName);
	rParser.ReadInt(s_szTag_Items, m_nItems);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonGallery::XGalleryGroup::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.WriteString(s_szTag_Name, m_strName);
	rParser.WriteInt(s_szTag_Items, m_nItems, 0);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonGallery::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadBool(s_szTag_ButtonMode, m_bIsButtonMode);
	rParser.ReadBool(s_szTag_MenuResize, m_bEnableMenuResize);
	rParser.ReadBool(s_szTag_MenuResizeVertical, m_bMenuResizeVertical);
	rParser.ReadInt (s_szTag_IconsInRow, m_nIconsInRow);
	rParser.ReadSize(s_szTag_SizeIcon, m_sizeIcon);

	if (ReadImage(s_szTag_Image, m_Images, rParser))
	{
		m_Images.m_Image.SetImageSize(m_sizeIcon);
	}

	CMFCRibbonInfo::XRibbonInfoParser* pGroups = NULL;
	rParser.Read(s_szTag_Groups, &pGroups);
	if (pGroups != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pGroups->ReadCollection(s_szTag_Group, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XGalleryGroup* pGroup = new XGalleryGroup;
					if (pGroup != NULL)
					{
						if (pGroup->Read(*pListItem))
						{
							m_arGroups.Add(pGroup);
						}
						else
						{
							delete pGroup;
						}
					}
				}
			}

			delete pList;
		}

		delete pGroups;
	}

	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonGallery::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementButton::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteBool(s_szTag_ButtonMode, m_bIsButtonMode, TRUE);
	rParser.WriteBool(s_szTag_MenuResize, m_bEnableMenuResize, FALSE);
	rParser.WriteBool(s_szTag_MenuResizeVertical, m_bMenuResizeVertical, FALSE);
	rParser.WriteInt (s_szTag_IconsInRow, m_nIconsInRow, -1);
	rParser.WriteSize(s_szTag_SizeIcon, m_sizeIcon, CSize(0, 0));

	WriteImage(s_szTag_Image, m_Images, rParser);

	if (m_arGroups.GetSize() > 0)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pGroups = NULL;
		rParser.Add(s_szTag_Groups, &pGroups);
		if (pGroups != NULL)
		{
			for (INT_PTR i = 0; i < m_arGroups.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pGroup = NULL;
				pGroups->Add(s_szTag_Group, &pGroup);
				if (pGroup != NULL)
				{
					m_arGroups[i]->Write(*pGroup);
					delete pGroup;
				}
			}

			delete pGroups;
		}
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonColor::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadColor(s_szTag_Color, m_clrColor);
	rParser.ReadBool(s_szTag_SimpleButtonLook, m_bSimpleButtonLook);

	CMFCRibbonInfo::XRibbonInfoParser* pBtn = NULL;
	rParser.Read(s_szTag_AutomaticColorBtn, &pBtn);
	if (pBtn != NULL)
	{
		pBtn->ReadString(s_szTag_Label, m_strAutomaticBtnLabel);
		pBtn->ReadString(s_szTag_ToolTip, m_strAutomaticBtnToolTip);
		pBtn->ReadColor(s_szTag_Color, m_clrAutomaticBtnColor);
		pBtn->ReadBool(s_szTag_PaletteTop, m_bAutomaticBtnOnTop);
		pBtn->ReadBool(s_szTag_Border, m_bAutomaticBtnBorder);

		delete pBtn;
		pBtn = NULL;
	}

	rParser.Read(s_szTag_OtherColorBtn, &pBtn);
	if (pBtn != NULL)
	{
		pBtn->ReadString(s_szTag_Label, m_strOtherBtnLabel);
		pBtn->ReadString(s_szTag_ToolTip, m_strOtherBtnToolTip);

		delete pBtn;
		pBtn = NULL;
	}

	return XElementButtonGallery::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonColor::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementButtonGallery::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteColor(s_szTag_Color, m_clrColor, RGB(0, 0, 0));
	rParser.WriteBool(s_szTag_SimpleButtonLook, m_bSimpleButtonLook, FALSE);

	CMFCRibbonInfo::XRibbonInfoParser* pBtn = NULL;
	rParser.Add(s_szTag_AutomaticColorBtn, &pBtn);
	if (pBtn != NULL)
	{
		pBtn->WriteString(s_szTag_Label, m_strAutomaticBtnLabel);
		pBtn->WriteString(s_szTag_ToolTip, m_strAutomaticBtnToolTip);
		pBtn->WriteColor(s_szTag_Color, m_clrAutomaticBtnColor, RGB(0, 0, 0));
		pBtn->WriteBool(s_szTag_PaletteTop, m_bAutomaticBtnOnTop, TRUE);
		pBtn->WriteBool(s_szTag_Border, m_bAutomaticBtnBorder, FALSE);

		delete pBtn;
		pBtn = NULL;
	}

	rParser.Add(s_szTag_OtherColorBtn, &pBtn);
	if (pBtn != NULL)
	{
		pBtn->WriteString(s_szTag_Label, m_strOtherBtnLabel);
		pBtn->WriteString(s_szTag_ToolTip, m_strOtherBtnToolTip);

		delete pBtn;
		pBtn = NULL;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonUndo::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButtonGallery::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonUndo::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButtonGallery::Write(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonLaunch::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonLaunch::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Write(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonApplication::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	ReadImage(s_szTag_Image, m_Image, rParser);

	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonApplication::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElementButton::Write(rParser))
	{
		return FALSE;
	}

	WriteImage(s_szTag_Image, m_Image, rParser);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementButtonMainPanel::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementButtonMainPanel::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	return XElementButton::Write(rParser);
}

BOOL CMFCRibbonInfo::XElementSlider::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	int nValue = (int)m_dwStyle;
	rParser.ReadInt(s_szTag_Style, nValue);
	m_dwStyle = (DWORD)nValue;

	rParser.ReadInt(s_szTag_Width, m_nWidth);
	rParser.ReadInt(s_szTag_Min, m_nMin);
	rParser.ReadInt(s_szTag_Max, m_nMax);
	rParser.ReadInt(s_szTag_Pos, m_nPos);
	m_nPos = min(max(m_nMin, m_nPos), m_nMax);
	rParser.ReadBool(s_szTag_ZoomButtons, m_bZoomButtons);

	return XElement::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementSlider::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElement::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteUInt(s_szTag_Style, m_dwStyle, 0);
	rParser.WriteInt(s_szTag_Width, m_nWidth, 100);
	rParser.WriteInt(s_szTag_Min, m_nMin, 0);
	rParser.WriteInt(s_szTag_Max, m_nMax, 100);
	rParser.WriteInt(s_szTag_Pos, m_nPos, m_nMin);
	rParser.WriteBool(s_szTag_ZoomButtons, m_bZoomButtons, FALSE);

	return TRUE;
}

BOOL CMFCRibbonInfo::XElementProgressBar::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	rParser.ReadInt(s_szTag_Width, m_nWidth);
	rParser.ReadInt(s_szTag_Height, m_nHeight);
	rParser.ReadInt(s_szTag_Min, m_nMin);
	rParser.ReadInt(s_szTag_Max, m_nMax);
	rParser.ReadInt(s_szTag_Pos, m_nPos);
	m_nPos = min(max(m_nMin, m_nPos), m_nMax);
	rParser.ReadBool(s_szTag_Infinite, m_bInfinite);

	return XElement::Read(rParser);
}

BOOL CMFCRibbonInfo::XElementProgressBar::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XElement::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteInt(s_szTag_Width, m_nWidth, 100);
	rParser.WriteInt(s_szTag_Height, m_nHeight, 22);
	rParser.WriteInt(s_szTag_Min, m_nMin, 0);
	rParser.WriteInt(s_szTag_Max, m_nMax, 100);
	rParser.WriteInt(s_szTag_Pos, m_nPos, m_nMin);
	rParser.WriteBool(s_szTag_Infinite, m_bInfinite, FALSE);

	return TRUE;
}

BOOL CMFCRibbonInfo::XPanel::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Read(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pElements->ReadCollection(s_szTag_Element, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XElement* pElement = (XElement*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pElement != NULL)
					{
						m_arElements.Add(pElement);
					}
				}
			}

			delete pList;
		}

		delete pElements;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pButton = NULL;
	rParser.Read(s_szTag_Button_Launch, &pButton);
	if (pButton != NULL)
	{
		m_btnLaunch.Read(*pButton);
		delete pButton;
	}

	rParser.ReadBool(s_szTag_JustifyColumns, m_bJustifyColumns);
	rParser.ReadBool(s_szTag_CenterColumnVert, m_bCenterColumnVert);
	rParser.ReadInt(s_szTag_Index, m_nImageIndex);

	rParser.ReadString(s_szTag_Name, m_strName);
	rParser.ReadString(s_szTag_Keys, m_strKeys);

	return TRUE;
}

BOOL CMFCRibbonInfo::XPanel::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteString(s_szTag_Name, m_strName);
	rParser.WriteString(s_szTag_Keys, m_strKeys);
	rParser.WriteInt(s_szTag_Index, m_nImageIndex, -1);
	rParser.WriteBool(s_szTag_JustifyColumns, m_bJustifyColumns, FALSE);
	rParser.WriteBool(s_szTag_CenterColumnVert, m_bCenterColumnVert, FALSE);

	if (m_btnLaunch.m_ID.m_Value != 0)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pButton = NULL;
		rParser.Add(s_szTag_Button_Launch, &pButton);
		if (pButton != NULL)
		{
			m_btnLaunch.Write(*pButton);
			delete pButton;
		}
	}

	if (m_arElements.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
		rParser.Add(s_szTag_Elements, &pElements);
		if (pElements != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arElements.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pElement = NULL;
				pElements->Add(s_szTag_Element, &pElement);
				if (pElement != NULL)
				{
					if (!m_arElements[i]->Write(*pElement))
					{
						bResult = FALSE;
					}

					delete pElement;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pElements;
		}

		return bResult;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XCategory::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pPanels = NULL;
	rParser.Read(s_szTag_Panels, &pPanels);
	if (pPanels != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pPanels->ReadCollection(s_szTag_Panel, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XPanel* pPanel = (XPanel*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pPanel != NULL)
					{
						m_arPanels.Add(pPanel);
					}
				}
			}

			delete pList;
		}

		delete pPanels;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Read(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pElements->ReadCollection(s_szTag_Element, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XElement* pElement = (XElement*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pElement != NULL)
					{
						m_arElements.Add(pElement);
					}
				}
			}

			delete pList;
		}

		delete pElements;
	}

	rParser.ReadString(s_szTag_Name, m_strName);
	rParser.ReadString(s_szTag_Keys, m_strKeys);

	ReadImage(s_szTag_Image_Small, m_SmallImages, rParser);
	ReadImage(s_szTag_Image_Large, m_LargeImages, rParser);

	return TRUE;
}

BOOL CMFCRibbonInfo::XCategory::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteString(s_szTag_Name, m_strName);
	rParser.WriteString(s_szTag_Keys, m_strKeys);

	WriteImage(s_szTag_Image_Small, m_SmallImages, rParser);
	WriteImage(s_szTag_Image_Large, m_LargeImages, rParser);

	if (m_arPanels.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pPanels = NULL;
		rParser.Add(s_szTag_Panels, &pPanels);
		if (pPanels != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arPanels.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pPanel = NULL;
				pPanels->Add(s_szTag_Panel, &pPanel);
				if (pPanel != NULL)
				{
					if (!m_arPanels[i]->Write(*pPanel))
					{
						bResult = FALSE;
					}

					delete pPanel;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pPanels;
		}

		if (!bResult)
		{
			return FALSE;
		}
	}

	if (m_arElements.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
		rParser.Add(s_szTag_Elements, &pElements);
		if (pElements != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arElements.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pElement = NULL;
				pElements->Add(s_szTag_Element, &pElement);
				if (pElement != NULL)
				{
					if (!m_arElements[i]->Write(*pElement))
					{
						bResult = FALSE;
					}

					delete pElement;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pElements;
		}

		if (!bResult)
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XContext::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pCategories = NULL;
	rParser.Read(s_szTag_Categories, &pCategories);
	if (pCategories != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pCategories->ReadCollection(s_szTag_Category, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XCategory* pCategory = (XCategory*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pCategory != NULL)
					{
						m_arCategories.Add(pCategory);
					}
				}
			}

			delete pList;
		}

		delete pCategories;
	}

	ReadID(s_szTag_ID, m_ID, rParser);

	rParser.ReadString(s_szTag_Text, m_strText);

	int color = (int)AFX_CategoryColor_None;
	rParser.ReadInt(s_szTag_Color, color);
	m_Color = (AFX_RibbonCategoryColor)color;

	return TRUE;
}

BOOL CMFCRibbonInfo::XContext::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	WriteID(s_szTag_ID, m_ID, rParser);

	rParser.WriteString(s_szTag_Text, m_strText);
	rParser.WriteInt(s_szTag_Color, (int)m_Color, (int)AFX_CategoryColor_None);

	if (m_arCategories.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pCategories = NULL;
		rParser.Add(s_szTag_Categories, &pCategories);
		if (pCategories != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arCategories.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pCategory = NULL;
				pCategories->Add(s_szTag_Category, &pCategory);
				if (pCategory != NULL)
				{
					if (!m_arCategories[i]->Write(*pCategory))
					{
						bResult = FALSE;
					}

					delete pCategory;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pCategories;
		}

		return bResult;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XCategoryMain::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
	rParser.Read(s_szTag_Elements, &pElements);
	if (pElements != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pElements->ReadCollection(s_szTag_Element, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XElement* pElement = (XElement*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pElement != NULL)
					{
						m_arElements.Add(pElement);
					}
				}
			}

			delete pList;
		}

		delete pElements;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserRecent = NULL;
	rParser.Read(s_szTag_RecentFileList, &pParserRecent);
	if (pParserRecent != NULL)
	{
		pParserRecent->ReadBool(s_szTag_Enable, m_bRecentListEnable);
		pParserRecent->ReadString(s_szTag_Label, m_strRecentListLabel);
		pParserRecent->ReadInt(s_szTag_Width, m_nRecentListWidth);

		delete pParserRecent;
	}

	rParser.ReadString(s_szTag_Name, m_strName);

	ReadImage(s_szTag_Image_Small, m_SmallImages, rParser);
	ReadImage(s_szTag_Image_Large, m_LargeImages, rParser);

	return TRUE;
}

BOOL CMFCRibbonInfo::XCategoryMain::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (m_arElements.GetSize() == 0 && !m_bRecentListEnable)
	{
		return TRUE;
	}

	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteString(s_szTag_Name, m_strName);

	WriteImage(s_szTag_Image_Small, m_SmallImages, rParser);
	WriteImage(s_szTag_Image_Large, m_LargeImages, rParser);

	if (m_arElements.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pElements = NULL;
		rParser.Add(s_szTag_Elements, &pElements);
		if (pElements != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arElements.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pElement = NULL;
				pElements->Add(s_szTag_Element, &pElement);
				if (pElement != NULL)
				{
					if (!m_arElements[i]->Write(*pElement))
					{
						bResult = FALSE;
					}

					delete pElement;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pElements;
		}

		if (!bResult)
		{
			return FALSE;
		}
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserRecent = NULL;
	rParser.Add(s_szTag_RecentFileList, &pParserRecent);
	if (pParserRecent != NULL)
	{
		pParserRecent->WriteBool(s_szTag_Enable, m_bRecentListEnable, FALSE);
		pParserRecent->WriteString(s_szTag_Label, m_strRecentListLabel);
		pParserRecent->WriteInt(s_szTag_Width, m_nRecentListWidth, 300);

		delete pParserRecent;
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XQAT::XQATItem::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (ReadID(s_szTag_ID, m_ID, rParser))
	{
		rParser.ReadBool(s_szTag_Visible, m_bVisible);
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XQAT::XQATItem::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	WriteID(s_szTag_ID, m_ID, rParser);

	rParser.WriteBool(s_szTag_Visible, m_bVisible, TRUE);

	return TRUE;
}

BOOL CMFCRibbonInfo::XQAT::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pItems = NULL;
	rParser.Read(s_szTag_Items, &pItems);
	if (pItems != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pItems->ReadCollection(s_szTag_Item, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				XQATItem item;
				if (item.Read(*(pList->GetItem(i))))
				{
					m_arItems.Add(item);
				}
			}

			delete pList;
		}

		delete pItems;
	}

	rParser.ReadBool(s_szTag_QATTop, m_bOnTop);

	return TRUE;
}

BOOL CMFCRibbonInfo::XQAT::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteBool(s_szTag_QATTop, m_bOnTop, TRUE);

	if (m_arItems.GetSize() > 0)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pItems = NULL;
		rParser.Add(s_szTag_Items, &pItems);
		if (pItems != NULL)
		{
			for (INT_PTR i = 0; i < m_arItems.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pItem = NULL;
				pItems->Add(s_szTag_Item, &pItem);
				if (pItem != NULL)
				{
					m_arItems[i].Write(*pItem);
					delete pItem;
				}
			}

			delete pItems;
		}
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::XRibbonBar::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	CMFCRibbonInfo::XRibbonInfoParser* pParserButton = NULL;
	rParser.Read(s_szTag_Button_Main, &pParserButton);
	if (pParserButton != NULL)
	{
		m_btnMain = new XElementButtonApplication;
		m_btnMain->Read(*pParserButton);
		delete pParserButton;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserMainCategory = NULL;
	rParser.Read(s_szTag_CategoryMain, &pParserMainCategory);
	if (pParserMainCategory != NULL)
	{
		m_MainCategory = new XCategoryMain;
		m_MainCategory->Read(*pParserMainCategory);
		delete pParserMainCategory;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserQAT = NULL;
	rParser.Read(s_szTag_QAT_Elements, &pParserQAT);
	if (pParserQAT != NULL)
	{
		m_QAT.Read(*pParserQAT);
		delete pParserQAT;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserTab = NULL;
	rParser.Read(s_szTag_Tab_Elements, &pParserTab);
	if (pParserTab != NULL)
	{
		m_TabElements.Read(*pParserTab);
		delete pParserTab;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pContexts = NULL;
	rParser.Read(s_szTag_Contexts, &pContexts);
	if (pContexts != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pContexts->ReadCollection(s_szTag_Context, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XContext* pContext = (XContext*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pContext != NULL)
					{
						m_arContexts.Add(pContext);
					}
				}
			}

			delete pList;
		}

		delete pContexts;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pCategories = NULL;
	rParser.Read(s_szTag_Categories, &pCategories);
	if (pCategories != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParserCollection* pList = NULL;
		pCategories->ReadCollection(s_szTag_Category, &pList);
		if (pList != NULL)
		{
			for (UINT i = 0; i < pList->GetCount(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pListItem = pList->GetItem(i);
				if (pListItem != NULL)
				{
					XCategory* pCategory = (XCategory*)CMFCRibbonInfo::XBase::CreateFromTag(*pListItem);
					if (pCategory != NULL)
					{
						m_arCategories.Add(pCategory);
					}
				}
			}

			delete pList;
		}

		delete pCategories;
	}

	rParser.ReadBool(s_szTag_EnableToolTips, m_bToolTip);
	rParser.ReadBool(s_szTag_EnableToolTipsDescr, m_bToolTipDescr);
	rParser.ReadBool(s_szTag_EnableKeys, m_bKeyTips);
	rParser.ReadBool(s_szTag_EnablePrintPreview, m_bPrintPreview);
	rParser.ReadBool(s_szTag_DrawUsingFont, m_bDrawUsingFont);

	ReadImage(s_szTag_Image, m_Images, rParser);

	return TRUE;
}

BOOL CMFCRibbonInfo::XRibbonBar::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	if (!XBase::Write(rParser))
	{
		return FALSE;
	}

	rParser.WriteBool(s_szTag_EnableToolTips, m_bToolTip, TRUE);
	rParser.WriteBool(s_szTag_EnableToolTipsDescr, m_bToolTipDescr, TRUE);
	rParser.WriteBool(s_szTag_EnableKeys, m_bKeyTips, TRUE);
	rParser.WriteBool(s_szTag_EnablePrintPreview, m_bPrintPreview, TRUE);
	rParser.WriteBool(s_szTag_DrawUsingFont, m_bDrawUsingFont, FALSE);

	WriteImage(s_szTag_Image, m_Images, rParser);

	if (m_btnMain != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserButton = NULL;
		rParser.Add(s_szTag_Button_Main, &pParserButton);
		if (pParserButton != NULL)
		{
			m_btnMain->Write(*pParserButton);
			delete pParserButton;
		}
	}

	if (m_MainCategory != NULL)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserMainCategory = NULL;
		rParser.Add(s_szTag_CategoryMain, &pParserMainCategory);
		if (pParserMainCategory != NULL)
		{
			m_MainCategory->Write(*pParserMainCategory);
			delete pParserMainCategory;
		}
	}

	if (m_QAT.m_arItems.GetSize() > 0 || !m_QAT.m_bOnTop)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserQAT = NULL;
		rParser.Add(s_szTag_QAT_Elements, &pParserQAT);
		if (pParserQAT != NULL)
		{
			m_QAT.Write(*pParserQAT);
			delete pParserQAT;
		}
	}

	if (m_TabElements.m_arButtons.GetSize() > 0)
	{
		CMFCRibbonInfo::XRibbonInfoParser* pParserTab = NULL;
		rParser.Add(s_szTag_Tab_Elements, &pParserTab);
		if (pParserTab != NULL)
		{
			m_TabElements.Write(*pParserTab);
			delete pParserTab;
		}
	}

	if (m_arCategories.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pCategories = NULL;
		rParser.Add(s_szTag_Categories, &pCategories);
		if (pCategories != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arCategories.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pCategory = NULL;
				pCategories->Add(s_szTag_Category, &pCategory);
				if (pCategory != NULL)
				{
					if (!m_arCategories[i]->Write(*pCategory))
					{
						bResult = FALSE;
					}

					delete pCategory;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pCategories;
		}

		if (!bResult)
		{
			return FALSE;
		}
	}

	if (m_arContexts.GetSize() > 0)
	{
		BOOL bResult = FALSE;

		CMFCRibbonInfo::XRibbonInfoParser* pContexts = NULL;
		rParser.Add(s_szTag_Contexts, &pContexts);
		if (pContexts != NULL)
		{
			bResult = TRUE;

			for (INT_PTR i = 0; i < m_arContexts.GetSize(); i++)
			{
				CMFCRibbonInfo::XRibbonInfoParser* pContext = NULL;
				pContexts->Add(s_szTag_Context, &pContext);
				if (pContext != NULL)
				{
					if (!m_arContexts[i]->Write(*pContext))
					{
						bResult = FALSE;
					}

					delete pContext;
				}
				else
				{
					bResult = FALSE;
				}
			}

			delete pContexts;
		}

		return bResult;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCRibbonInfo::CMFCRibbonInfo()
{
	m_dwVersion                  = c_dwVersion;
	m_sizeImage[e_ImagesSmall]   = CSize(16, 16);
	m_sizeImage[e_ImagesLarge]   = CSize(32, 32);

	m_RibbonBar.m_Images.m_Image.SetImageSize(m_sizeImage [e_ImagesSmall]);
}

CMFCRibbonInfo::~CMFCRibbonInfo()
{
}

void CMFCRibbonInfo::AddElementImages(XElement& info, XArrayImages& images)
{
	XElementType type = info.GetElementType();

	if (type == e_TypeButton_Gallery)
	{
		images.Add(&((XElementButtonGallery&)info).m_Images);
	}
	else if (type == e_TypeGroup)
	{
		XElementGroup& infoGroup = (XElementGroup&)info;
		images.Add(&(infoGroup.m_Images));

		for (INT_PTR i = 0; i < infoGroup.m_arButtons.GetSize(); i++)
		{
			AddElementImages(*(infoGroup.m_arButtons[i]), images);
		}
	}

	if (type == e_TypeButton || type == e_TypeButton_Color || type == e_TypeButton_Gallery)
	{
		XElementButton& infoBtn = (XElementButton&)info;

		for (INT_PTR i = 0; i < infoBtn.m_arSubItems.GetSize(); i++)
		{
			AddElementImages(*((XElement*)(infoBtn.m_arSubItems[i])), images);
		}
	}
}

void CMFCRibbonInfo::GetArrayImages(XArrayImages& images)
{
	INT_PTR i = 0;
	INT_PTR j = 0;
	INT_PTR k = 0;

	images.RemoveAll();

	images.Add(&m_RibbonBar.m_Images);
	if (m_RibbonBar.m_btnMain != NULL)
	{
		images.Add(&m_RibbonBar.m_btnMain->m_Image);
	}
	if (m_RibbonBar.m_MainCategory != NULL)
	{
		images.Add(&m_RibbonBar.m_MainCategory->m_SmallImages);
		images.Add(&m_RibbonBar.m_MainCategory->m_LargeImages);
	}

	for (i = 0; i < m_RibbonBar.m_TabElements.m_arButtons.GetSize(); i++)
	{
		AddElementImages(*(m_RibbonBar.m_TabElements.m_arButtons[i]), images);
	}

	XArrayCategory arCategories;
	arCategories.Append(m_RibbonBar.m_arCategories);

	for (i = 0; i < m_RibbonBar.m_arContexts.GetSize(); i++)
	{
		arCategories.Append(m_RibbonBar.m_arContexts[i]->m_arCategories);
	}

	for (i = 0; i < arCategories.GetSize(); i++)
	{
		XCategory* pCategory = arCategories[i];

		images.Add(&pCategory->m_SmallImages);
		images.Add(&pCategory->m_LargeImages);

		for (j = 0; j < pCategory->m_arPanels.GetSize(); j++)
		{
			XPanel* pPanel = pCategory->m_arPanels[j];

			for (k = 0; k < pPanel->m_arElements.GetSize(); k++)
			{
				AddElementImages(*(pPanel->m_arElements[k]), images);
			}
		}
	}
}
