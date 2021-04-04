// Ex_Ctlr3SDI.h : main header file for the EX_CTLR3SDI application
//

#if !defined(AFX_EX_CTLR3SDI_H__3E3C688E_4956_41BF_9141_3C8D097DBC68__INCLUDED_)
#define AFX_EX_CTLR3SDI_H__3E3C688E_4956_41BF_9141_3C8D097DBC68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIApp:
// See Ex_Ctlr3SDI.cpp for the implementation of this class
//

class CEx_Ctlr3SDIApp : public CWinApp
{
public:
	CEx_Ctlr3SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctlr3SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_Ctlr3SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTLR3SDI_H__3E3C688E_4956_41BF_9141_3C8D097DBC68__INCLUDED_)
