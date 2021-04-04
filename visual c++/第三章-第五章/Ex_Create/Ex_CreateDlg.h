// Ex_CreateDlg.h : header file
//

#if !defined(AFX_EX_CREATEDLG_H__62315646_2CC1_4973_B30F_75A04A23A8C2__INCLUDED_)
#define AFX_EX_CREATEDLG_H__62315646_2CC1_4973_B30F_75A04A23A8C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_CreateDlg dialog

class CEx_CreateDlg : public CDialog
{
// Construction
public:
	CButton m_btnWnd;
	CEx_CreateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_CreateDlg)
	enum { IDD = IDD_EX_CREATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CreateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_CreateDlg)
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

#endif // !defined(AFX_EX_CREATEDLG_H__62315646_2CC1_4973_B30F_75A04A23A8C2__INCLUDED_)
