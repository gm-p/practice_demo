// Ex_SDIArchiveView.h : interface of the CEx_SDIArchiveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIARCHIVEVIEW_H__221B89F5_F686_4F44_B7E0_DBED8926C9FB__INCLUDED_)
#define AFX_EX_SDIARCHIVEVIEW_H__221B89F5_F686_4F44_B7E0_DBED8926C9FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIArchiveView : public CView
{
protected: // create from serialization only
	CEx_SDIArchiveView();
	DECLARE_DYNCREATE(CEx_SDIArchiveView)

// Attributes
public:
	CEx_SDIArchiveDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIArchiveView)
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
	virtual ~CEx_SDIArchiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIArchiveView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_SDIArchiveView.cpp
inline CEx_SDIArchiveDoc* CEx_SDIArchiveView::GetDocument()
   { return (CEx_SDIArchiveDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIARCHIVEVIEW_H__221B89F5_F686_4F44_B7E0_DBED8926C9FB__INCLUDED_)
