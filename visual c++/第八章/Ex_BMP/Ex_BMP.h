// Ex_BMP.h : main header file for the EX_BMP application
//

#if !defined(AFX_EX_BMP_H__78D10954_ADC3_4BE0_B12D_D1375525A9CD__INCLUDED_)
#define AFX_EX_BMP_H__78D10954_ADC3_4BE0_B12D_D1375525A9CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPApp:
// See Ex_BMP.cpp for the implementation of this class
//

class CEx_BMPApp : public CWinApp
{
public:
	CEx_BMPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_BMPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_BMPApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_BMP_H__78D10954_ADC3_4BE0_B12D_D1375525A9CD__INCLUDED_)
