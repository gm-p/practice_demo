// Ex_ScaleView.h : interface of the CEx_ScaleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SCALEVIEW_H__4797186B_AE7B_4FB1_8FC1_0BF56FD7F128__INCLUDED_)
#define AFX_EX_SCALEVIEW_H__4797186B_AE7B_4FB1_8FC1_0BF56FD7F128__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ScaleView : public CView
{
protected: // create from serialization only
	CEx_ScaleView();
	DECLARE_DYNCREATE(CEx_ScaleView)

// Attributes
public:
	CEx_ScaleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ScaleView)
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
	virtual ~CEx_ScaleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ScaleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ScaleView.cpp
inline CEx_ScaleDoc* CEx_ScaleView::GetDocument()
   { return (CEx_ScaleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SCALEVIEW_H__4797186B_AE7B_4FB1_8FC1_0BF56FD7F128__INCLUDED_)
