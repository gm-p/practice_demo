// Ex_FormView.h : interface of the CEx_FormView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_FORMVIEW_H__A33B31AE_8BE9_4F12_8F9D_97748F91F18A__INCLUDED_)
#define AFX_EX_FORMVIEW_H__A33B31AE_8BE9_4F12_8F9D_97748F91F18A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_FormView : public CView
{
protected: // create from serialization only
	CEx_FormView();
	DECLARE_DYNCREATE(CEx_FormView)

// Attributes
public:
	CEx_FormDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FormView)
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
	virtual ~CEx_FormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_FormView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_FormView.cpp
inline CEx_FormDoc* CEx_FormView::GetDocument()
   { return (CEx_FormDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FORMVIEW_H__A33B31AE_8BE9_4F12_8F9D_97748F91F18A__INCLUDED_)
