#if !defined(AFX_ONEDLG_H__F82FF833_4F19_47C4_828C_B0599160F56C__INCLUDED_)
#define AFX_ONEDLG_H__F82FF833_4F19_47C4_828C_B0599160F56C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// oneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ConeDlg dialog

class ConeDlg : public CDialog
{
// Construction
public:
	ConeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ConeDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ConeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ConeDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONEDLG_H__F82FF833_4F19_47C4_828C_B0599160F56C__INCLUDED_)
