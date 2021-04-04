#if !defined(AFX_LESSDLG_H__0765F605_0F49_49C3_A96E_7BB733D7B8BC__INCLUDED_)
#define AFX_LESSDLG_H__0765F605_0F49_49C3_A96E_7BB733D7B8BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LessDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLessDlg dialog

class CLessDlg : public CDialog
{
// Construction
public:
	CLessDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLessDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLessDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LESSDLG_H__0765F605_0F49_49C3_A96E_7BB733D7B8BC__INCLUDED_)
