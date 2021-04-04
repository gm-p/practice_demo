// Ex_BMPView.h : interface of the CEx_BMPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_BMPVIEW_H__043C2382_0BC1_4232_8157_3CCCD0056721__INCLUDED_)
#define AFX_EX_BMPVIEW_H__043C2382_0BC1_4232_8157_3CCCD0056721__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_BMPView : public CView
{
protected: // create from serialization only
	CEx_BMPView();
	DECLARE_DYNCREATE(CEx_BMPView)

// Attributes
public:
	CEx_BMPDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_BMPView)
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
	virtual ~CEx_BMPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_BMPView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_BMPView.cpp
inline CEx_BMPDoc* CEx_BMPView::GetDocument()
   { return (CEx_BMPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_BMPVIEW_H__043C2382_0BC1_4232_8157_3CCCD0056721__INCLUDED_)
