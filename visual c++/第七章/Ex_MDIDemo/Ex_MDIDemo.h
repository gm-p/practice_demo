// Ex_MDIDemo.h : main header file for the EX_MDIDEMO application
//

#if !defined(AFX_EX_MDIDEMO_H__2210F9E8_0CA7_478D_9018_ACD842F46B3B__INCLUDED_)
#define AFX_EX_MDIDEMO_H__2210F9E8_0CA7_478D_9018_ACD842F46B3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoApp:
// See Ex_MDIDemo.cpp for the implementation of this class
//

class CEx_MDIDemoApp : public CWinApp
{
public:
	CEx_MDIDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MDIDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDIDEMO_H__2210F9E8_0CA7_478D_9018_ACD842F46B3B__INCLUDED_)
