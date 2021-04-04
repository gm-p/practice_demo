// Ex_MDIDemoView.h : interface of the CEx_MDIDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MDIDEMOVIEW_H__D693E660_73B4_432B_AD81_74E57C6BED45__INCLUDED_)
#define AFX_EX_MDIDEMOVIEW_H__D693E660_73B4_432B_AD81_74E57C6BED45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MDIDemoView : public CView
{
protected: // create from serialization only
	CEx_MDIDemoView();
	DECLARE_DYNCREATE(CEx_MDIDemoView)

// Attributes
public:
	CEx_MDIDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIDemoView)
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
	virtual ~CEx_MDIDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MDIDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MDIDemoView.cpp
inline CEx_MDIDemoDoc* CEx_MDIDemoView::GetDocument()
   { return (CEx_MDIDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDIDEMOVIEW_H__D693E660_73B4_432B_AD81_74E57C6BED45__INCLUDED_)
