// Ex_Member.h : main header file for the EX_MEMBER application
//

#if !defined(AFX_EX_MEMBER_H__2EBAC47D_A985_4626_AAB8_D91338AC6746__INCLUDED_)
#define AFX_EX_MEMBER_H__2EBAC47D_A985_4626_AAB8_D91338AC6746__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MemberApp:
// See Ex_Member.cpp for the implementation of this class
//

class CEx_MemberApp : public CWinApp
{
public:
	CEx_MemberApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MemberApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_MemberApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MEMBER_H__2EBAC47D_A985_4626_AAB8_D91338AC6746__INCLUDED_)
