#if !defined(AFX_INPUTDLG_H__4176158F_91B5_43C4_8F60_207D54C644B8__INCLUDED_)
#define AFX_INPUTDLG_H__4176158F_91B5_43C4_8F60_207D54C644B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog

class CInputDlg : public CDialog
{
// Construction
public:
	CInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputDlg)
	enum { IDD = IDD_INPUT };
	CSpinButtonCtrl	m_spinScore3;
	CSpinButtonCtrl	m_spinScore2;
	CSpinButtonCtrl	m_spinScore1;
	CString	m_strName;
	CString	m_strNO;
	float	m_fScore1;
	float	m_fScore2;
	float	m_fScore3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinS1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__4176158F_91B5_43C4_8F60_207D54C644B8__INCLUDED_)
