// Ex_EtchedDlg.h : header file
//

#if !defined(AFX_EX_ETCHEDDLG_H__A9182967_C89F_4EF2_A0B4_80B1A9CC7CE4__INCLUDED_)
#define AFX_EX_ETCHEDDLG_H__A9182967_C89F_4EF2_A0B4_80B1A9CC7CE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_EtchedDlg dialog

class CEx_EtchedDlg : public CDialog
{
// Construction
public:
	CEx_EtchedDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_EtchedDlg)
	enum { IDD = IDD_EX_ETCHED_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_EtchedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_EtchedDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ETCHEDDLG_H__A9182967_C89F_4EF2_A0B4_80B1A9CC7CE4__INCLUDED_)
