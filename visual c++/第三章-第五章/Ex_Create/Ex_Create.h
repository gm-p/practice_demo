// Ex_Create.h : main header file for the EX_CREATE application
//

#if !defined(AFX_EX_CREATE_H__924E0DDF_9F10_4AAD_8F7F_54D1466C8222__INCLUDED_)
#define AFX_EX_CREATE_H__924E0DDF_9F10_4AAD_8F7F_54D1466C8222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_CreateApp:
// See Ex_Create.cpp for the implementation of this class
//

class CEx_CreateApp : public CWinApp
{
public:
	CEx_CreateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CreateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_CreateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CREATE_H__924E0DDF_9F10_4AAD_8F7F_54D1466C8222__INCLUDED_)
