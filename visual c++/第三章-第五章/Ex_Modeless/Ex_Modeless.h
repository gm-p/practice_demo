// Ex_Modeless.h : main header file for the EX_MODELESS application
//

#if !defined(AFX_EX_MODELESS_H__14BBD18F_EAF1_4435_9299_43640533F555__INCLUDED_)
#define AFX_EX_MODELESS_H__14BBD18F_EAF1_4435_9299_43640533F555__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessApp:
// See Ex_Modeless.cpp for the implementation of this class
//

class CEx_ModelessApp : public CWinApp
{
public:
	CEx_ModelessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ModelessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_ModelessApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MODELESS_H__14BBD18F_EAF1_4435_9299_43640533F555__INCLUDED_)
