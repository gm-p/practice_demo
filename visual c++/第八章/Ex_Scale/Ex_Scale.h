// Ex_Scale.h : main header file for the EX_SCALE application
//

#if !defined(AFX_EX_SCALE_H__B084C010_58DA_42FA_8B74_EA061A55F721__INCLUDED_)
#define AFX_EX_SCALE_H__B084C010_58DA_42FA_8B74_EA061A55F721__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleApp:
// See Ex_Scale.cpp for the implementation of this class
//

class CEx_ScaleApp : public CWinApp
{
public:
	CEx_ScaleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ScaleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_ScaleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SCALE_H__B084C010_58DA_42FA_8B74_EA061A55F721__INCLUDED_)
