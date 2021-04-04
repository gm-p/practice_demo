// Ex_RectView.h : interface of the CEx_RectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECTVIEW_H__1526636A_D04A_460B_B22F_638322BE631E__INCLUDED_)
#define AFX_EX_RECTVIEW_H__1526636A_D04A_460B_B22F_638322BE631E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_RectDoc;
class CEx_RectView : public CFormView
{
protected: // create from serialization only
	CEx_RectView();
	DECLARE_DYNCREATE(CEx_RectView)

public:
	//{{AFX_DATA(CEx_RectView)
	enum { IDD = IDD_EX_RECT_FORM };
	CSpinButtonCtrl	m_SpinY;
	CSpinButtonCtrl	m_SpinX;
	int		m_CoorX;
	int		m_CoorY;
	//}}AFX_DATA

// Attributes
public:
	CEx_RectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_RectView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bEditOK;
	virtual ~CEx_RectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_RectView)
	afx_msg void OnChangeEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_RectView.cpp
inline CEx_RectDoc* CEx_RectView::GetDocument()
   { return (CEx_RectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECTVIEW_H__1526636A_D04A_460B_B22F_638322BE631E__INCLUDED_)
