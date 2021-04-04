// Ex_DySplitView.h : interface of the CEx_DySplitView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DYSPLITVIEW_H__DEEDFE8F_48D2_4BBA_973A_E72DB1D045C2__INCLUDED_)
#define AFX_EX_DYSPLITVIEW_H__DEEDFE8F_48D2_4BBA_973A_E72DB1D045C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DySplitView : public CView
{
protected: // create from serialization only
	CEx_DySplitView();
	DECLARE_DYNCREATE(CEx_DySplitView)

// Attributes
public:
	CEx_DySplitDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DySplitView)
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
	virtual ~CEx_DySplitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DySplitView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_DySplitView.cpp
inline CEx_DySplitDoc* CEx_DySplitView::GetDocument()
   { return (CEx_DySplitDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DYSPLITVIEW_H__DEEDFE8F_48D2_4BBA_973A_E72DB1D045C2__INCLUDED_)
