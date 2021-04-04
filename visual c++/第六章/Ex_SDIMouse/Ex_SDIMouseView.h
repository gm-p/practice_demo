// Ex_SDIMouseView.h : interface of the CEx_SDIMouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIMOUSEVIEW_H__E276842B_B611_46AB_86F8_F98BEE39FE31__INCLUDED_)
#define AFX_EX_SDIMOUSEVIEW_H__E276842B_B611_46AB_86F8_F98BEE39FE31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIMouseView : public CView
{
protected: // create from serialization only
	CEx_SDIMouseView();
	DECLARE_DYNCREATE(CEx_SDIMouseView)

// Attributes
public:
	CEx_SDIMouseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIMouseView)
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
	virtual ~CEx_SDIMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIMouseView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_SDIMouseView.cpp
inline CEx_SDIMouseDoc* CEx_SDIMouseView::GetDocument()
   { return (CEx_SDIMouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIMOUSEVIEW_H__E276842B_B611_46AB_86F8_F98BEE39FE31__INCLUDED_)
