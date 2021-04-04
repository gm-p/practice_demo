// Ex_MultiBarView.h : interface of the CEx_MultiBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MULTIBARVIEW_H__C7BD27E8_787C_426A_8F27_2B9AA9A18EF1__INCLUDED_)
#define AFX_EX_MULTIBARVIEW_H__C7BD27E8_787C_426A_8F27_2B9AA9A18EF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MultiBarView : public CView
{
protected: // create from serialization only
	CEx_MultiBarView();
	DECLARE_DYNCREATE(CEx_MultiBarView)

// Attributes
public:
	CEx_MultiBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MultiBarView)
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
	virtual ~CEx_MultiBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MultiBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MultiBarView.cpp
inline CEx_MultiBarDoc* CEx_MultiBarView::GetDocument()
   { return (CEx_MultiBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MULTIBARVIEW_H__C7BD27E8_787C_426A_8F27_2B9AA9A18EF1__INCLUDED_)
