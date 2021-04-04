// Ex_SDIArchive.h : main header file for the EX_SDIARCHIVE application
//

#if !defined(AFX_EX_SDIARCHIVE_H__9358E60F_7F3D_46A3_BD0F_BBCC174526A0__INCLUDED_)
#define AFX_EX_SDIARCHIVE_H__9358E60F_7F3D_46A3_BD0F_BBCC174526A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveApp:
// See Ex_SDIArchive.cpp for the implementation of this class
//

class CEx_SDIArchiveApp : public CWinApp
{
public:
	CEx_SDIArchiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIArchiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_SDIArchiveApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIARCHIVE_H__9358E60F_7F3D_46A3_BD0F_BBCC174526A0__INCLUDED_)
