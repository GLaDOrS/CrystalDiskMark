﻿/*---------------------------------------------------------------------------*/
//       Author : hiyohiyo
//         Mail : hiyohiyo@crystalmark.info
//          Web : https://crystalmark.info/
//      License : The MIT License
/*---------------------------------------------------------------------------*/

#pragma once

#include "CommonFx.h"
#include <atlimage.h>

class CDialogFx : public CDialog
{
public:
	CDialogFx(UINT dlgResouce, CWnd* pParent = NULL);
	virtual ~CDialogFx();

	// Dialog
	virtual BOOL Create(UINT nIDTemplate, CWnd* dlgWnd, UINT menuId, CWnd* pParentWnd = NULL);

protected:
	// Dialog
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void PostNcDestroy();
	virtual void UpdateDialogSize();
	virtual void SetClientSize(int sizeX, int sizeY, DWORD menuLine = 0);
	virtual void UpdateBackground(BOOL resize = FALSE);
	virtual void OnOK();
	virtual void OnCancel();

	// Zoom
	DWORD ChangeZoomType(DWORD zoomType);

	// Theme
	BOOL IsHighContrast();

	// Utility
	virtual CString IP(CString imageName);
	CString i18n(CString section, CString key, BOOL inEnglish = FALSE);
	void OpenUrl(CString url);
	void SetLayeredWindow(HWND hWnd, BYTE alpha);

	// MessageMap
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnUpdateDialogSize(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDpiChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisplayChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSysColorChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEnterSizeMove(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnExitSizeMove(WPARAM wParam, LPARAM lParam);

protected:
	// Dialog
	BOOL m_bInitializing;
	BOOL m_bDpiChanging;
	BOOL m_bShowWindow;
	BOOL m_bModelessDlg;
	BOOL m_bHighContrast;
	BOOL m_bBkImage;
	UINT m_MenuId;
	CWnd* m_ParentWnd;
	CWnd* m_DlgWnd;
	CString m_Ini;
	HACCEL m_hAccelerator;
	BOOL m_bDrag;
	CString m_FontFace;
	int m_FontScale;
	double m_FontRatio;

	int m_MaxSizeX;
	int m_MinSizeX;
	int m_MaxSizeY;
	int m_MinSizeY;

	// Zoom
	int m_Dpi;
	DWORD m_ZoomType;
	double m_ZoomRatio;

	// Color for SubClass
	COLORREF m_LabelText;
	COLORREF m_MeterText;
	COLORREF m_ComboText;
	COLORREF m_ComboTextSelected;
	COLORREF m_ComboBk;
	COLORREF m_ComboBkSelected;
	COLORREF m_ButtonText;
	COLORREF m_EditText;
	COLORREF m_EditBk;
	COLORREF m_ListText1;
	COLORREF m_ListText2;
	COLORREF m_ListTextSelected;
	COLORREF m_ListBk1;
	COLORREF m_ListBk2;
	COLORREF m_ListBkSelected;
	COLORREF m_ListLine1;
	COLORREF m_ListLine2;
	COLORREF m_Glass;

	BYTE     m_ComboAlpha;
	BYTE     m_EditAlpha;
	BYTE     m_GlassAlpha;

	BYTE     m_CharacterPosition;

	// Theme for SubClass
	int m_OffsetX;
	CString m_ThemeDir;
	CString m_CurrentTheme;
	CString m_DefaultTheme;
	CString m_ParentTheme1;
	CString m_ParentTheme2;

	// Language for SubClass
	CString m_LangDir;
	CString m_CurrentLang;
	CString m_CurrentLangPath;
	CString m_DefaultLangPath;
	CString m_BackgroundName;

	// Class
	CBitmap m_BkBitmap;
	CDC		m_BkDC;
	CImage  m_BkImage;
	CBrush  m_BrushDlg;
};
