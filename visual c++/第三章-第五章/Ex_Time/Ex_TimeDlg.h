// Ex_TimeDlg.h : header file
//

#if !defined(AFX_EX_TIMEDLG_H__6E510FF6_38B3_46EB_8980_12CC8EED2CDA__INCLUDED_)
#define AFX_EX_TIMEDLG_H__6E510FF6_38B3_46EB_8980_12CC8EED2CDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_TimeDlg dialog

class CEx_TimeDlg : public CDialog
{
// Construction
public:
	CEx_TimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_TimeDlg)
	enum { IDD = IDD_EX_TIME_DIALOG };
	CDateTimeCtrl	m_dtCtrl;
	CMonthCalCtrl	m_mnCtrl;
	CString	m_strData;
	BOOL	m_bTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_TimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TIMEDLG_H__6E510FF6_38B3_46EB_8980_12CC8EED2CDA__INCLUDED_)
