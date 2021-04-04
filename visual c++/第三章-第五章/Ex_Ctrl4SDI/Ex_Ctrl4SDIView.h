// Ex_Ctrl4SDIView.h : interface of the CEx_Ctrl4SDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTRL4SDIVIEW_H__7A8D1FFE_7F1D_4C99_B83D_F7A37C91CA58__INCLUDED_)
#define AFX_EX_CTRL4SDIVIEW_H__7A8D1FFE_7F1D_4C99_B83D_F7A37C91CA58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctrl4SDIView : public CView
{
protected: // create from serialization only
	CEx_Ctrl4SDIView();
	DECLARE_DYNCREATE(CEx_Ctrl4SDIView)

// Attributes
public:
	CEx_Ctrl4SDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl4SDIView)
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
	virtual ~CEx_Ctrl4SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctrl4SDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_Ctrl4SDIView.cpp
inline CEx_Ctrl4SDIDoc* CEx_Ctrl4SDIView::GetDocument()
   { return (CEx_Ctrl4SDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL4SDIVIEW_H__7A8D1FFE_7F1D_4C99_B83D_F7A37C91CA58__INCLUDED_)
