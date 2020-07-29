
// SimpleDlg.h : main header file for the SimpleDlg application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSimpleDlgApp:
// See SimpleDlg.cpp for the implementation of this class
//

class CSimpleDlgApp : public CWinAppEx
{
public:
	CSimpleDlgApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimpleDlgApp theApp;
