// Ex_MemberDlg.h : header file
//

#if !defined(AFX_EX_MEMBERDLG_H__D7284CFB_C98F_433C_917D_51584074EA4E__INCLUDED_)
#define AFX_EX_MEMBERDLG_H__D7284CFB_C98F_433C_917D_51584074EA4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_MemberDlg dialog

class CEx_MemberDlg : public CDialog
{
// Construction
public:
	CEx_MemberDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_MemberDlg)
	enum { IDD = IDD_EX_MEMBER_DIALOG };
	CButton	m_btnWnd;
	CString	m_strEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MemberDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_MemberDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MEMBERDLG_H__D7284CFB_C98F_433C_917D_51584074EA4E__INCLUDED_)
