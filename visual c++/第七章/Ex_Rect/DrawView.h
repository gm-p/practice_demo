#if !defined(AFX_DRAWVIEW_H__C874EAF8_6F2D_43CE_BFD8_D43EA64F1DE2__INCLUDED_)
#define AFX_DRAWVIEW_H__C874EAF8_6F2D_43CE_BFD8_D43EA64F1DE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawView view

class CDrawView : public CView
{
protected:
	CDrawView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDrawView)

// Attributes
public:
	CPoint m_ptDraw;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDrawView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWVIEW_H__C874EAF8_6F2D_43CE_BFD8_D43EA64F1DE2__INCLUDED_)
