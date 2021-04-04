// Ex_SDIHello.h : main header file for the EX_SDIHELLO application
//

#if !defined(AFX_EX_SDIHELLO_H__3CFCFE95_B9B0_45EA_8B01_E8749D3C3D61__INCLUDED_)
#define AFX_EX_SDIHELLO_H__3CFCFE95_B9B0_45EA_8B01_E8749D3C3D61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloApp:
// See Ex_SDIHello.cpp for the implementation of this class
//

class CEx_SDIHelloApp : public CWinApp
{
public:
	CEx_SDIHelloApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIHelloApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_SDIHelloApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIHELLO_H__3CFCFE95_B9B0_45EA_8B01_E8749D3C3D61__INCLUDED_)
