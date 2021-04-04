// Ex_Cursor.h : main header file for the EX_CURSOR application
//

#if !defined(AFX_EX_CURSOR_H__6986C8C2_E971_46ED_AB73_8B4C834676BD__INCLUDED_)
#define AFX_EX_CURSOR_H__6986C8C2_E971_46ED_AB73_8B4C834676BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorApp:
// See Ex_Cursor.cpp for the implementation of this class
//

class CEx_CursorApp : public CWinApp
{
public:
	CEx_CursorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CursorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_CursorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CURSOR_H__6986C8C2_E971_46ED_AB73_8B4C834676BD__INCLUDED_)
