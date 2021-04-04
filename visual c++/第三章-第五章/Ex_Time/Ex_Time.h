// Ex_Time.h : main header file for the EX_TIME application
//

#if !defined(AFX_EX_TIME_H__1CD2C1BF_92F4_4849_B07B_2A94FB5EBB54__INCLUDED_)
#define AFX_EX_TIME_H__1CD2C1BF_92F4_4849_B07B_2A94FB5EBB54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_TimeApp:
// See Ex_Time.cpp for the implementation of this class
//

class CEx_TimeApp : public CWinApp
{
public:
	CEx_TimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_TimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TIME_H__1CD2C1BF_92F4_4849_B07B_2A94FB5EBB54__INCLUDED_)
