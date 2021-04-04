// Ex_DlgDlg.h : header file
//

#if !defined(AFX_EX_DLGDLG_H__AB0572C8_0220_41B3_BBFF_5C7F516D33BF__INCLUDED_)
#define AFX_EX_DLGDLG_H__AB0572C8_0220_41B3_BBFF_5C7F516D33BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_DlgDlg dialog

class CEx_DlgDlg : public CDialog
{
// Construction
public:
	CEx_DlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_DlgDlg)
	enum { IDD = IDD_EX_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_DlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLGDLG_H__AB0572C8_0220_41B3_BBFF_5C7F516D33BF__INCLUDED_)
