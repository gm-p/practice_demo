// Ex_CursorView.h : interface of the CEx_CursorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CURSORVIEW_H__E3C95FE5_D0FD_48D1_96F0_6F20F4E05082__INCLUDED_)
#define AFX_EX_CURSORVIEW_H__E3C95FE5_D0FD_48D1_96F0_6F20F4E05082__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_CursorView : public CView
{
protected: // create from serialization only
	CEx_CursorView();
	DECLARE_DYNCREATE(CEx_CursorView)

// Attributes
public:
	CEx_CursorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CursorView)
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
	virtual ~CEx_CursorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_CursorView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_CursorView.cpp
inline CEx_CursorDoc* CEx_CursorView::GetDocument()
   { return (CEx_CursorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CURSORVIEW_H__E3C95FE5_D0FD_48D1_96F0_6F20F4E05082__INCLUDED_)
