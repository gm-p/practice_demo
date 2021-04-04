// Ex_Etched.h : main header file for the EX_ETCHED application
//

#if !defined(AFX_EX_ETCHED_H__CBA8A55C_E8C0_4D42_9D5A_8DF53B8FADB6__INCLUDED_)
#define AFX_EX_ETCHED_H__CBA8A55C_E8C0_4D42_9D5A_8DF53B8FADB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_EtchedApp:
// See Ex_Etched.cpp for the implementation of this class
//

class CEx_EtchedApp : public CWinApp
{
public:
	CEx_EtchedApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_EtchedApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_EtchedApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ETCHED_H__CBA8A55C_E8C0_4D42_9D5A_8DF53B8FADB6__INCLUDED_)
