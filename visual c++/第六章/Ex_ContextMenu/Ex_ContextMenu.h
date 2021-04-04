// Ex_ContextMenu.h : main header file for the EX_CONTEXTMENU application
//

#if !defined(AFX_EX_CONTEXTMENU_H__C89E298E_0133_47B0_BE3F_6556636F66D4__INCLUDED_)
#define AFX_EX_CONTEXTMENU_H__C89E298E_0133_47B0_BE3F_6556636F66D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuApp:
// See Ex_ContextMenu.cpp for the implementation of this class
//

class CEx_ContextMenuApp : public CWinApp
{
public:
	CEx_ContextMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ContextMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_ContextMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CONTEXTMENU_H__C89E298E_0133_47B0_BE3F_6556636F66D4__INCLUDED_)
