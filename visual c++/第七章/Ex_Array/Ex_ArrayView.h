// Ex_ArrayView.h : interface of the CEx_ArrayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ARRAYVIEW_H__48892B2F_B2E3_4076_9C9C_F4FCE84264A6__INCLUDED_)
#define AFX_EX_ARRAYVIEW_H__48892B2F_B2E3_4076_9C9C_F4FCE84264A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ArrayView : public CView
{
protected: // create from serialization only
	CEx_ArrayView();
	DECLARE_DYNCREATE(CEx_ArrayView)

// Attributes
public:
	CEx_ArrayDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ArrayView)
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
	virtual ~CEx_ArrayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ArrayView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ArrayView.cpp
inline CEx_ArrayDoc* CEx_ArrayView::GetDocument()
   { return (CEx_ArrayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ARRAYVIEW_H__48892B2F_B2E3_4076_9C9C_F4FCE84264A6__INCLUDED_)
