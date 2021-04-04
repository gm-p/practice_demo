// Ex_Icon.h : main header file for the EX_ICON application
//

#if !defined(AFX_EX_ICON_H__AE463095_D644_47A0_B30D_7A56701FC18D__INCLUDED_)
#define AFX_EX_ICON_H__AE463095_D644_47A0_B30D_7A56701FC18D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_IconApp:
// See Ex_Icon.cpp for the implementation of this class
//

class CEx_IconApp : public CWinApp
{
public:
	CEx_IconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_IconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_IconApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ICON_H__AE463095_D644_47A0_B30D_7A56701FC18D__INCLUDED_)
