#if !defined(AFX_TEXTVIEW_H__4C840F7D_6093_45B3_80DF_2A3A286C604E__INCLUDED_)
#define AFX_TEXTVIEW_H__4C840F7D_6093_45B3_80DF_2A3A286C604E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTextView : public CFormView
{
protected:
	CTextView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTextView)

// Form Data
public:
	//{{AFX_DATA(CTextView)
	enum { IDD = IDD_TEXTVIEW_FORM };
	CString	m_strText;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTextView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTVIEW_H__4C840F7D_6093_45B3_80DF_2A3A286C604E__INCLUDED_)
