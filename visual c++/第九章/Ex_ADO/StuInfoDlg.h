#if !defined(AFX_STUINFODLG_H__691CDF22_F2F8_4554_B458_258D2B0ED3EB__INCLUDED_)
#define AFX_STUINFODLG_H__691CDF22_F2F8_4554_B458_258D2B0ED3EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	CStuInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_STUINFO };
	CString	m_strno;
	CString	m_strCno;
	float	m_score;
	float	m_credit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__691CDF22_F2F8_4554_B458_258D2B0ED3EB__INCLUDED_)
