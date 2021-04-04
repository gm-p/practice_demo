// Ex_DySplit.h : main header file for the EX_DYSPLIT application
//

#if !defined(AFX_EX_DYSPLIT_H__364E2D63_F3EE_45E9_9D6D_A53A72058C78__INCLUDED_)
#define AFX_EX_DYSPLIT_H__364E2D63_F3EE_45E9_9D6D_A53A72058C78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitApp:
// See Ex_DySplit.cpp for the implementation of this class
//

class CEx_DySplitApp : public CWinApp
{
public:
	CEx_DySplitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DySplitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_DySplitApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DYSPLIT_H__364E2D63_F3EE_45E9_9D6D_A53A72058C78__INCLUDED_)
