// Ex_TextView.h : interface of the CEx_TextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TEXTVIEW_H__E17D2FAB_2B39_44D5_92CA_433C016E013D__INCLUDED_)
#define AFX_EX_TEXTVIEW_H__E17D2FAB_2B39_44D5_92CA_433C016E013D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TextView : public CScrollView
{
protected: // create from serialization only
	CEx_TextView();
	DECLARE_DYNCREATE(CEx_TextView)

// Attributes
public:
	CEx_TextDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	LOGFONT m_lfText;
	virtual ~CEx_TextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TextView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_TextView.cpp
inline CEx_TextDoc* CEx_TextView::GetDocument()
   { return (CEx_TextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TEXTVIEW_H__E17D2FAB_2B39_44D5_92CA_433C016E013D__INCLUDED_)
