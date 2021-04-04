// Ex_Ctlr3SDIView.h : interface of the CEx_Ctlr3SDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTLR3SDIVIEW_H__240866F1_2122_4D22_8D18_0176403264E9__INCLUDED_)
#define AFX_EX_CTLR3SDIVIEW_H__240866F1_2122_4D22_8D18_0176403264E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctlr3SDIView : public CView
{
protected: // create from serialization only
	CEx_Ctlr3SDIView();
	DECLARE_DYNCREATE(CEx_Ctlr3SDIView)

// Attributes
public:
	CEx_Ctlr3SDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctlr3SDIView)
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
	virtual ~CEx_Ctlr3SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctlr3SDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_Ctlr3SDIView.cpp
inline CEx_Ctlr3SDIDoc* CEx_Ctlr3SDIView::GetDocument()
   { return (CEx_Ctlr3SDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTLR3SDIVIEW_H__240866F1_2122_4D22_8D18_0176403264E9__INCLUDED_)
