// Ex_SDIHelloView.h : interface of the CEx_SDIHelloView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIHELLOVIEW_H__6A757F6A_8FD5_42AD_84F0_2FFE0E96F4AE__INCLUDED_)
#define AFX_EX_SDIHELLOVIEW_H__6A757F6A_8FD5_42AD_84F0_2FFE0E96F4AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIHelloView : public CView
{
protected: // create from serialization only
	CEx_SDIHelloView();
	DECLARE_DYNCREATE(CEx_SDIHelloView)

// Attributes
public:
	CEx_SDIHelloDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIHelloView)
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
	virtual ~CEx_SDIHelloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIHelloView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_SDIHelloView.cpp
inline CEx_SDIHelloDoc* CEx_SDIHelloView::GetDocument()
   { return (CEx_SDIHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIHELLOVIEW_H__6A757F6A_8FD5_42AD_84F0_2FFE0E96F4AE__INCLUDED_)
