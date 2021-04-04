// Ex_MenuView.h : interface of the CEx_MenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MENUVIEW_H__08D1A561_F687_46AD_8FAF_B7FBED9308E2__INCLUDED_)
#define AFX_EX_MENUVIEW_H__08D1A561_F687_46AD_8FAF_B7FBED9308E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MenuView : public CView
{
protected: // create from serialization only
	CEx_MenuView();
	DECLARE_DYNCREATE(CEx_MenuView)

// Attributes
public:
	CEx_MenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuView)
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
	virtual ~CEx_MenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MenuView.cpp
inline CEx_MenuDoc* CEx_MenuView::GetDocument()
   { return (CEx_MenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENUVIEW_H__08D1A561_F687_46AD_8FAF_B7FBED9308E2__INCLUDED_)
