// Ex_Tree.h : main header file for the EX_TREE application
//

#if !defined(AFX_EX_TREE_H__AC7692EB_01DB_4268_9781_D125FA9ACBF8__INCLUDED_)
#define AFX_EX_TREE_H__AC7692EB_01DB_4268_9781_D125FA9ACBF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeApp:
// See Ex_Tree.cpp for the implementation of this class
//

class CEx_TreeApp : public CWinApp
{
public:
	CEx_TreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_TreeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TREE_H__AC7692EB_01DB_4268_9781_D125FA9ACBF8__INCLUDED_)
