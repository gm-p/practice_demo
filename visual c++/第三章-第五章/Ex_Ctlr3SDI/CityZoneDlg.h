#if !defined(AFX_CITYZONEDLG_H__82E05C51_C67A_4B28_9358_3804C6BDDBE5__INCLUDED_)
#define AFX_CITYZONEDLG_H__82E05C51_C67A_4B28_9358_3804C6BDDBE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CityZoneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCityZoneDlg dialog

class CCityZoneDlg : public CDialog
{
// Construction
public:
	BOOL IsValidate();
	CCityZoneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCityZoneDlg)
	enum { IDD = IDD_CITYZONE };
	CComboBox	m_ComboBox;
	CString	m_strCity;
	CString	m_strZone;
	CString	m_strZip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCityZoneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCityZoneDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonChange();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CITYZONEDLG_H__82E05C51_C67A_4B28_9358_3804C6BDDBE5__INCLUDED_)
