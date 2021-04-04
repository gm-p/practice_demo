// Ex_SDIView.h : interface of the CEx_SDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIVIEW_H__FCB9C36D_A335_4ADF_825F_168E21AEB88B__INCLUDED_)
#define AFX_EX_SDIVIEW_H__FCB9C36D_A335_4ADF_825F_168E21AEB88B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIView : public CView
{
protected: // create from serialization only
	CEx_SDIView();
	DECLARE_DYNCREATE(CEx_SDIView)

// Attributes
public:
	CEx_SDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDlgFirst();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_SDIView.cpp
inline CEx_SDIDoc* CEx_SDIView::GetDocument()
   { return (CEx_SDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIVIEW_H__FCB9C36D_A335_4ADF_825F_168E21AEB88B__INCLUDED_)
