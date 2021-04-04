// Ex_ResearchDlg.h : header file
//

#if !defined(AFX_EX_RESEARCHDLG_H__1F2F64C3_F7CB_4A40_A049_9295D5AABDF8__INCLUDED_)
#define AFX_EX_RESEARCHDLG_H__1F2F64C3_F7CB_4A40_A049_9295D5AABDF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_ResearchDlg dialog

class CEx_ResearchDlg : public CDialog
{
// Construction
public:
	CEx_ResearchDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_ResearchDlg)
	enum { IDD = IDD_EX_RESEARCH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ResearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_ResearchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RESEARCHDLG_H__1F2F64C3_F7CB_4A40_A049_9295D5AABDF8__INCLUDED_)
