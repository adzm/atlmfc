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

#pragma once

#include "afxcontrolbarutil.h"

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

class CAccessibilityData;
class CMFCRibbonCategory;
class CMFCRibbonPanel;
class CMFCRibbonCmdUI;
class CMFCPopupMenu;
class CMFCRibbonButtonsGroup;
class CMFCRibbonPanelMenuBar;
class CMFCRibbonCommandsListBox;
class CMFCPopupMenu;
class CMFCRibbonQuickAccessToolBar;
class CMFCRibbonKeyTip;

class CMFCRibbonBaseElement : public CObject
{
	friend class CMFCRibbonPanel;
	friend class CMFCRibbonBar;
	friend class CMFCRibbonCmdUI;
	friend class CMFCRibbonButtonsGroup;
	friend class CMFCPopupMenu;
	friend class CMFCRibbonPanelMenuBar;
	friend class CMFCRibbonCategory;
	friend class CMFCPopupMenuBar;
	friend class CMFCRibbonQuickAccessToolBar;
	friend class CMFCRibbonGallery;
	friend class CMFCRibbonStatusBar;
	friend class CMFCRibbonCommandsListBox;
	friend class CMFCRibbonCollector;
	friend class CMFCRibbonConstructor;

	DECLARE_DYNAMIC(CMFCRibbonBaseElement)

// Construction
public:
	CMFCRibbonBaseElement();
	virtual ~CMFCRibbonBaseElement();

// Attributes
public:
	enum RibbonElementLocation
	{
		RibbonElementNotInGroup,
		RibbonElementSingleInGroup,
		RibbonElementFirstInGroup,
		RibbonElementLastInGroup,
		RibbonElementMiddleInGroup,
	};

	enum RibbonImageType
	{
		RibbonImageLarge,
		RibbonImageSmall
	};

	RibbonElementLocation GetLocationInGroup() const
	{
		return m_Location;
	}

	virtual void SetID(UINT nID);
	UINT GetID() const { return m_nID; }

	virtual void SetText(LPCTSTR lpszText);
	LPCTSTR GetText() const { return m_strText; }

	virtual void SetKeys(LPCTSTR lpszKeys, LPCTSTR lpszMenuKeys = NULL);
	LPCTSTR GetKeys() const { return m_strKeys; }
	LPCTSTR GetMenuKeys() const { return m_strMenuKeys; }

	virtual void SetTextAlwaysOnRight(BOOL bSet = TRUE);
	BOOL IsTextAlwaysOnRight() const { return m_bTextAlwaysOnRight; }

	void SetRect(CRect rect) { m_rect = rect; }
	CRect GetRect() const { return m_rect; }

	DWORD_PTR GetData() const { return m_dwData; }
	void SetData(DWORD_PTR dwData) { m_dwData = dwData; }

	BOOL IsDefaultMenuLook() const { return m_bIsDefaultMenuLook; }
	void SetDefaultMenuLook(BOOL bIsDefaultMenuLook = TRUE) { m_bIsDefaultMenuLook = bIsDefaultMenuLook; }

	virtual CString GetToolTipText() const;
	virtual CString GetDescription() const;

	virtual void SetToolTipText(LPCTSTR lpszText);
	virtual void SetDescription(LPCTSTR lpszText);

	virtual BOOL IsHighlighted() const { return m_bIsHighlighted; }
	virtual BOOL IsFocused() const { return m_bIsFocused; }
	virtual BOOL IsPressed() const { return m_bIsPressed; }
	virtual BOOL IsDisabled() const { return m_bIsDisabled; }
	virtual BOOL IsChecked() const { return m_bIsChecked; }
	virtual BOOL IsDroppedDown() const { return  m_bIsDroppedDown; }

	BOOL IsLargeMode() const { return !m_bCompactMode && !m_bIntermediateMode; }
	BOOL IsCompactMode() const { return m_bCompactMode; }
	BOOL IsIntermediateMode() const { return m_bIntermediateMode; }

	BOOL IsVisible() const { return m_bIsVisible; }
	void SetVisible(BOOL bIsVisible) { m_bIsVisible = bIsVisible; }

	virtual BOOL IsAlwaysLargeImage() const { return m_bIsAlwaysLarge; }

	virtual void SetCompactMode(BOOL bCompactMode = TRUE)
	{
		if(!bCompactMode)
		{
			if (m_bCompactMode)
			{
				if (HasIntermediateMode())
				{
					m_bIntermediateMode = TRUE;
					m_bCompactMode = FALSE;
				}
				else
				{
					m_bIntermediateMode = FALSE;
					m_bCompactMode = FALSE;
				}
			}
		}
		else
		{
			if (m_bCompactMode)
			{
				return;
			}

			if (m_bIntermediateMode)
			{
				if (HasCompactMode())
				{
					m_bCompactMode = TRUE;
					m_bIntermediateMode = FALSE;
				}
			}
			else
			{
				if (HasIntermediateMode())
				{
					m_bCompactMode = FALSE;
					m_bIntermediateMode = TRUE;
				}
			}
		}
	}

	virtual BOOL CanBeCompacted() const
	{
		if (IsAlwaysLargeImage() || m_bCompactMode)
		{
			return FALSE;
		}

		return m_bIntermediateMode ? HasCompactMode() : HasIntermediateMode();
	}

	virtual CSize GetSize(CDC* pDC)
	{
		return m_bIntermediateMode ? 
					GetIntermediateSize(pDC) : 
				m_bCompactMode ? 
					GetCompactSize(pDC) : 
					GetRegularSize(pDC);
	}

	virtual CSize GetRegularSize(CDC* pDC) = 0;
	virtual CSize GetCompactSize(CDC* pDC) { return GetRegularSize(pDC); }
	virtual CSize GetIntermediateSize(CDC* pDC) { return GetRegularSize(pDC); }

	virtual BOOL HasLargeMode() const { return FALSE; }
	virtual BOOL HasIntermediateMode() const { return TRUE; }
	virtual BOOL HasCompactMode() const { return FALSE; }

	virtual void SetInitialMode(BOOL bOneRow = FALSE)
	{
		m_bIntermediateMode = FALSE;
		m_bCompactMode = FALSE;

		if (m_pParentGroup != NULL || bOneRow)
		{
			if (HasCompactMode())
			{
				m_bCompactMode = TRUE;
			}
			else if (HasIntermediateMode())
			{
				m_bIntermediateMode = TRUE;
			}
		}
		else
		{
			if (HasLargeMode())
			{
			}
			else if (HasIntermediateMode())
			{
				m_bIntermediateMode = TRUE;
			}
			else
			{
				m_bIntermediateMode = FALSE;
			}
		}
	}

	virtual CSize GetImageSize(RibbonImageType /*type*/) const { return CSize(0, 0); }
	virtual BOOL IsSeparator() const { return FALSE; }
	virtual BOOL IsTabStop() const { return TRUE; }
	BOOL IsShowGroupBorder() const { return m_bShowGroupBorder; }

	virtual void DrawImage(CDC* /*pDC*/, RibbonImageType /*type*/, CRect /*rectImage*/) {}

	virtual void OnAfterChangeRect(CDC* pDC);
	virtual void OnShow(BOOL /*bShow*/) {}

	virtual CMFCRibbonBaseElement* HitTest(CPoint point);

	CMFCRibbonCategory* GetParentCategory() const { return m_pParent; }
	virtual CMFCRibbonPanel* GetParentPanel() const;
	virtual CWnd* GetParentWnd() const;

	CMFCRibbonBar* GetParentRibbonBar() const { return m_pRibbonBar; }
	virtual void SetParentRibbonBar(CMFCRibbonBar* pRibbonBar) { m_pRibbonBar = pRibbonBar; }
	CMFCRibbonButtonsGroup* GetParentGroup() const { return m_pParentGroup; }

	CMFCRibbonBar* GetTopLevelRibbonBar() const;

	BOOL IsMenuMode() const;
	virtual BOOL HasMenu() const { return FALSE; }

	virtual void OnShowPopupMenu();

	virtual BOOL CanBeAddedToQuickAccessToolBar() const;
	BOOL IsQATMode() const { return m_bQuickAccessMode; }

	virtual BOOL IsWholeRowHeight() const { return FALSE; }
	virtual UINT GetNotifyID() { return m_nID; }
	virtual BOOL IsAutoRepeatMode(int& /*nDelay*/ /* ms */) const { return FALSE; }
	virtual BOOL OnAutoRepeat() { return FALSE; }

	virtual BOOL StretchToWholeRow(CDC* pDC, int nHeight);

	virtual BOOL OnDrawMenuImage(CDC* pDC, CRect rect)
	{
		DrawImage(pDC, RibbonImageSmall, rect);
		return TRUE;
	}

	CMFCRibbonBaseElement*	GetOriginal() const { return m_pOriginal; }

	virtual BOOL SetACCData(CWnd* pParent, CAccessibilityData& data);

	/// <summary>
	/// Indicates whether the parent element has keyboard focus</summary>
	/// <returns> 
	/// TRUE if the ribbon element is focused; otherwise FALSE.</returns>
	virtual BOOL HasFocus() const {	return FALSE; }

// Overrides
public:
	virtual void SetParentCategory(CMFCRibbonCategory* pParent);
	virtual void CopyFrom(const CMFCRibbonBaseElement& src);
	virtual void SetParentMenu(CMFCRibbonPanelMenuBar* pMenuBar);
	virtual void SetOriginal(CMFCRibbonBaseElement* pOriginal);

	virtual int AddToListBox(CMFCRibbonCommandsListBox* pWndListBox, BOOL bDeep);
	virtual void OnDrawOnList(CDC* pDC, CString strText, int nTextOffset, CRect rect, BOOL bIsSelected, BOOL bHighlighted);

	virtual void OnDraw(CDC* pDC) = 0;
	virtual void OnCalcTextSize(CDC* /*pDC*/) {}
	virtual void CleanUpSizes() {}

	virtual BOOL CanBeStretched() {
		return TRUE;
	}

	virtual BOOL CanBeStretchedHorizontally() { return FALSE; }
	virtual void StretchHorizontally() { ASSERT(FALSE); }
	virtual BOOL IsAlignByColumn() const { return TRUE; }

	virtual void ClosePopupMenu();
	virtual CMFCRibbonBaseElement* Find(const CMFCRibbonBaseElement* pElement);
	virtual CMFCRibbonBaseElement* FindByID(UINT uiCmdID);
	virtual CMFCRibbonBaseElement* FindByData(DWORD_PTR dwData);
	virtual CMFCRibbonBaseElement* FindByOriginal(CMFCRibbonBaseElement* pOriginal);
	virtual void UpdateTooltipInfo();

	virtual BOOL OnAddToQAToolbar(CMFCRibbonQuickAccessToolBar& qat);
	virtual UINT GetQuickAccessToolBarID() const { return m_nID; }

	virtual void Redraw();
	virtual void DestroyCtrl() {}

	virtual CMFCRibbonBaseElement* GetPressed();
	virtual CMFCRibbonBaseElement* GetDroppedDown();
	virtual CMFCRibbonBaseElement* GetHighlighted();
	virtual CMFCRibbonBaseElement* GetFocused();

	virtual void OnDrawKeyTip(CDC* pDC, const CRect& rect, BOOL bIsMenu);
	virtual CSize GetKeyTipSize(CDC* pDC);
	virtual CRect GetKeyTipRect(CDC* /*pDC*/, BOOL /*bIsMenu*/)	{	return CRect(0, 0, 0, 0);	}
	virtual BOOL OnKey(BOOL bIsMenuKey);
	virtual void AddToKeyList(CArray<CMFCRibbonKeyTip*,CMFCRibbonKeyTip*>& arElems);
	virtual BOOL OnMenuKey(UINT /*nUpperChar*/)	{	return FALSE;	}

	virtual void GetElementsByID(UINT uiCmdID, CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);

	virtual void GetElements(CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
	{
		arElements.Add(this);
	}

	virtual void GetVisibleElements(CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);

	virtual void OnRTLChanged(BOOL /*bIsRTL*/) {}

	virtual BOOL IsShowTooltipOnBottom() const { return m_pRibbonBar == NULL; }

	virtual void OnChangeMenuHighlight(CMFCRibbonPanelMenuBar* /*pPanelMenuBar*/, CMFCRibbonBaseElement* /*pHot*/)	{}
	virtual void NotifyHighlightListItem(int nIndex);

	virtual BOOL IsGalleryIcon() const { return FALSE; }

	virtual CMFCRibbonBaseElement* GetFirstTabStop()
	{
		if (IsTabStop() && !m_rect.IsRectEmpty())
		{
			return this;
		}

		return NULL;
	}

	virtual CMFCRibbonBaseElement* GetLastTabStop()
	{
		if (IsTabStop() && !m_rect.IsRectEmpty())
		{
			return this;
		}

		return NULL;
	}

protected:
	virtual void OnLButtonDown(CPoint point);
	virtual void OnLButtonUp(CPoint /*point*/) {}
	virtual void OnMouseMove(CPoint /*point*/) {}
	virtual void OnLButtonDblClk(CPoint /*point*/) {}
	virtual void OnHighlight(BOOL /*bHighlight*/) {}
	virtual void OnSetFocus(BOOL /*bSet*/) {}

	virtual void OnUpdateCmdUI(CMFCRibbonCmdUI* pCmdUI, CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	virtual BOOL NotifyControlCommand(BOOL bAccelerator, int nNotifyCode, WPARAM wParam, LPARAM lParam);

	virtual BOOL ReplaceByID(UINT uiCmdID, CMFCRibbonBaseElement* pElem);

	virtual void GetItemIDsList(CList<UINT,UINT>& lstItems) const;
	
	virtual void OnEnable(BOOL /*bEnable*/) {}
	virtual void OnCheck(BOOL /*bCheck*/) {}

	virtual int GetDropDownImageWidth() const;

	virtual BOOL OnProcessKey(UINT /*nChar*/) { return FALSE; }

// Operations
public:
	BOOL NotifyCommand(BOOL bWithDelay = FALSE);
	void PostMenuCommand(UINT uiCmdId);
	void EnableUpdateTooltipInfo(BOOL bEnable = TRUE);
	void EnableTooltipInfoShortcut(BOOL bEnable = TRUE);

protected:
	void SetDroppedDown(CMFCPopupMenu* pPopupMenu);

// Attributes
protected:
	CString m_strText;
	CString m_strKeys;
	CString m_strMenuKeys;
	CString m_strToolTip;
	CString m_strDescription;

	CRect m_rect;
	CMFCRibbonBar* m_pRibbonBar;
	CMFCRibbonCategory* m_pParent;
	CMFCRibbonBaseElement* m_pOriginal;
	CMFCRibbonButtonsGroup* m_pParentGroup;
	CMFCRibbonPanelMenuBar* m_pParentMenu;
	RibbonElementLocation m_Location;
	CMFCPopupMenu* m_pPopupMenu;

	DWORD_PTR m_dwData;

	UINT m_nID;

	int m_nRow;
	int m_nImageOffset;

	BOOL m_bTextAlwaysOnRight;
	BOOL m_bDontNotify;
	BOOL m_bCompactMode;
	BOOL m_bIntermediateMode;
	BOOL m_bFloatyMode;
	BOOL m_bQuickAccessMode;
	BOOL m_bIsHighlighted;
	BOOL m_bIsFocused;
	BOOL m_bIsPressed;
	BOOL m_bIsDisabled;
	BOOL m_bIsChecked;
	BOOL m_bIsRadio;
	BOOL m_bIsDroppedDown;
	BOOL m_bShowGroupBorder;
	BOOL m_bIsVisible;
	BOOL m_bIsDefaultMenuLook;
	BOOL m_bIsAlwaysLarge;
	BOOL m_bDrawDefaultIcon;
	BOOL m_bIsOnPaletteTop;
	BOOL m_bOnBeforeShowItemMenuIsSent;
	BOOL m_bEnableUpdateTooltipInfo;
	BOOL m_bEnableTooltipInfoShortcut;
};

class CMFCRibbonSeparator : public CMFCRibbonBaseElement
{
	DECLARE_DYNCREATE(CMFCRibbonSeparator)

public:
	CMFCRibbonSeparator(BOOL bIsHoriz = FALSE);

protected:

	virtual BOOL IsSeparator() const { return TRUE; }
	virtual BOOL IsTabStop() const { return FALSE; }

public:
	virtual int AddToListBox(CMFCRibbonCommandsListBox* pWndListBox, BOOL bDeep);
	BOOL IsHorizontal() const { return m_bIsHoriz; }

protected:
	virtual void OnDraw(CDC* pDC);
	virtual CSize GetRegularSize(CDC* pDC);
	virtual void CopyFrom(const CMFCRibbonBaseElement& src);
	virtual void OnDrawOnList(CDC* pDC, CString strText, int nTextOffset, CRect rect, BOOL bIsSelected, BOOL bHighlighted);

	BOOL m_bIsHoriz;
};

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
