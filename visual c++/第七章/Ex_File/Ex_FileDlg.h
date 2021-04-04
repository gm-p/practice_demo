// Ex_FileDlg.h : header file
//

#if !defined(AFX_EX_FILEDLG_H__752B77A6_2B51_470D_A6EF_7651F985EE73__INCLUDED_)
#define AFX_EX_FILEDLG_H__752B77A6_2B51_470D_A6EF_7651F985EE73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_FileDlg dialog

class CEx_FileDlg : public CDialog
{
// Construction
public:
	CEx_FileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_FileDlg)
	enum { IDD = IDD_EX_FILE_DIALOG };
	CString	m_strTitle;
	CString	m_strContent;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_FileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FILEDLG_H__752B77A6_2B51_470D_A6EF_7651F985EE73__INCLUDED_)
