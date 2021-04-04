#if !defined(AFX_CITYDLG_H__6F66FDA2_4405_4326_AFC4_A4C5D34B1179__INCLUDED_)
#define AFX_CITYDLG_H__6F66FDA2_4405_4326_AFC4_A4C5D34B1179__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CityDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCityDlg dialog

class CCityDlg : public CDialog
{
// Construction
public:
	BOOL IsValidate();
	CCityDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCityDlg)
	enum { IDD = IDD_CITYZIP };
	CListBox	m_ListBox;
	CString	m_strCity;
	DWORD	m_dwZipCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCityDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCityDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CITYDLG_H__6F66FDA2_4405_4326_AFC4_A4C5D34B1179__INCLUDED_)
