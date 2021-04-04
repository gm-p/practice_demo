// Ex_File.h : main header file for the EX_FILE application
//

#if !defined(AFX_EX_FILE_H__C56BC73F_1EBC_489B_9FAB_EB08826423A0__INCLUDED_)
#define AFX_EX_FILE_H__C56BC73F_1EBC_489B_9FAB_EB08826423A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_FileApp:
// See Ex_File.cpp for the implementation of this class
//

class CEx_FileApp : public CWinApp
{
public:
	CEx_FileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_FileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FILE_H__C56BC73F_1EBC_489B_9FAB_EB08826423A0__INCLUDED_)
