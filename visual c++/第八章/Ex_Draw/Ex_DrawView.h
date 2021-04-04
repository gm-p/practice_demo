// Ex_DrawView.h : interface of the CEx_DrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DRAWVIEW_H__EA4DC6B5_AF88_4FB8_8649_6D092ED9CED3__INCLUDED_)
#define AFX_EX_DRAWVIEW_H__EA4DC6B5_AF88_4FB8_8649_6D092ED9CED3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DrawView : public CView
{
protected: // create from serialization only
	CEx_DrawView();
	DECLARE_DYNCREATE(CEx_DrawView)

// Attributes
public:
	CEx_DrawDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DrawView)
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
	void DrawScore(CDC *pDC,float *fScore,int nNum);
	virtual ~CEx_DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DrawView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_DrawView.cpp
inline CEx_DrawDoc* CEx_DrawView::GetDocument()
   { return (CEx_DrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DRAWVIEW_H__EA4DC6B5_AF88_4FB8_8649_6D092ED9CED3__INCLUDED_)
