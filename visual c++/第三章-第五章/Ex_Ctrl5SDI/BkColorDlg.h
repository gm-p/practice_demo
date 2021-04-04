#if !defined(AFX_BKCOLORDLG_H__06BEDD2E_4514_401F_951A_0A4BC96B29F3__INCLUDED_)
#define AFX_BKCOLORDLG_H__06BEDD2E_4514_401F_951A_0A4BC96B29F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BkColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBkColorDlg dialog

class CBkColorDlg : public CDialog
{
// Construction
public:
	CBrush m_Brush;
	int m_nRedValue;
	CBkColorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBkColorDlg)
	enum { IDD = IDD_COLOR };
	CSliderCtrl	m_sliderBlue;
	CSliderCtrl	m_sliderGreen;
	CScrollBar	m_scrollRed;
	int		m_nGreen;
	int		m_nBlue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBkColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBkColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BKCOLORDLG_H__06BEDD2E_4514_401F_951A_0A4BC96B29F3__INCLUDED_)
