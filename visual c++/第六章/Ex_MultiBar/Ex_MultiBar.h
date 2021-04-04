// Ex_MultiBar.h : main header file for the EX_MULTIBAR application
//

#if !defined(AFX_EX_MULTIBAR_H__713F98A3_90DF_400E_9838_6D7A4607C90D__INCLUDED_)
#define AFX_EX_MULTIBAR_H__713F98A3_90DF_400E_9838_6D7A4607C90D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarApp:
// See Ex_MultiBar.cpp for the implementation of this class
//

class CEx_MultiBarApp : public CWinApp
{
public:
	CEx_MultiBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MultiBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MultiBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MULTIBAR_H__713F98A3_90DF_400E_9838_6D7A4607C90D__INCLUDED_)
