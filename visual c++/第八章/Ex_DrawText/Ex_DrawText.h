// Ex_DrawText.h : main header file for the EX_DRAWTEXT application
//

#if !defined(AFX_EX_DRAWTEXT_H__1749BA56_AD15_4FD2_99C1_14D890B1B481__INCLUDED_)
#define AFX_EX_DRAWTEXT_H__1749BA56_AD15_4FD2_99C1_14D890B1B481__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextApp:
// See Ex_DrawText.cpp for the implementation of this class
//

class CEx_DrawTextApp : public CWinApp
{
public:
	CEx_DrawTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DrawTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_DrawTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DRAWTEXT_H__1749BA56_AD15_4FD2_99C1_14D890B1B481__INCLUDED_)
