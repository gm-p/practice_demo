// Ex_ModelessView.h : interface of the CEx_ModelessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MODELESSVIEW_H__3ECD2F78_9B0B_4173_BDE5_748C7B262F7F__INCLUDED_)
#define AFX_EX_MODELESSVIEW_H__3ECD2F78_9B0B_4173_BDE5_748C7B262F7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ModelessView : public CView
{
protected: // create from serialization only
	CEx_ModelessView();
	DECLARE_DYNCREATE(CEx_ModelessView)

// Attributes
public:
	CEx_ModelessDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ModelessView)
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
	virtual ~CEx_ModelessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ModelessView)
	afx_msg void OnDlgModeless();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ModelessView.cpp
inline CEx_ModelessDoc* CEx_ModelessView::GetDocument()
   { return (CEx_ModelessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MODELESSVIEW_H__3ECD2F78_9B0B_4173_BDE5_748C7B262F7F__INCLUDED_)
