// Ex_TreeView.h : interface of the CEx_TreeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TREEVIEW_H__DCE7A94B_123A_4B0B_8498_EDD65339B47A__INCLUDED_)
#define AFX_EX_TREEVIEW_H__DCE7A94B_123A_4B0B_8498_EDD65339B47A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TreeView : public CTreeView
{
protected: // create from serialization only
	CEx_TreeView();
	DECLARE_DYNCREATE(CEx_TreeView)

// Attributes
public:
	CEx_TreeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TreeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetFoldItemPath(HTREEITEM hItem);
	void InsertFoldItem(HTREEITEM hItem,CString strPath);
	CString m_strPath;
	CImageList m_ImageList;
	virtual ~CEx_TreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_TreeView.cpp
inline CEx_TreeDoc* CEx_TreeView::GetDocument()
   { return (CEx_TreeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TREEVIEW_H__DCE7A94B_123A_4B0B_8498_EDD65339B47A__INCLUDED_)
