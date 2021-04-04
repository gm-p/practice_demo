// Ex_Menu.h : main header file for the EX_MENU application
//

#if !defined(AFX_EX_MENU_H__4E6E0ED4_31BC_4067_9E2B_7A20AB2F5E31__INCLUDED_)
#define AFX_EX_MENU_H__4E6E0ED4_31BC_4067_9E2B_7A20AB2F5E31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuApp:
// See Ex_Menu.cpp for the implementation of this class
//

class CEx_MenuApp : public CWinApp
{
public:
	CEx_MenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENU_H__4E6E0ED4_31BC_4067_9E2B_7A20AB2F5E31__INCLUDED_)
