// Ex_Ctrl4SDI.h : main header file for the EX_CTRL4SDI application
//

#if !defined(AFX_EX_CTRL4SDI_H__47876E5D_F033_46C1_847F_8D4E9FDDC1CE__INCLUDED_)
#define AFX_EX_CTRL4SDI_H__47876E5D_F033_46C1_847F_8D4E9FDDC1CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIApp:
// See Ex_Ctrl4SDI.cpp for the implementation of this class
//

class CEx_Ctrl4SDIApp : public CWinApp
{
public:
	CEx_Ctrl4SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl4SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_Ctrl4SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL4SDI_H__47876E5D_F033_46C1_847F_8D4E9FDDC1CE__INCLUDED_)
