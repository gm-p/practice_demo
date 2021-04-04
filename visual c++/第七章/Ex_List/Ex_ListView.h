// Ex_ListView.h : interface of the CEx_ListView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_LISTVIEW_H__30CA9DF7_0AD1_4AB5_A843_F04985EC77F7__INCLUDED_)
#define AFX_EX_LISTVIEW_H__30CA9DF7_0AD1_4AB5_A843_F04985EC77F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ListView : public CListView
{
protected: // create from serialization only
	CEx_ListView();
	DECLARE_DYNCREATE(CEx_ListView)

// Attributes
public:
	CEx_ListDoc* GetDocument();

// Operations
public:
	CImageList m_ImageList;
	CImageList m_ImageListSmall;
	CStringArray m_strArray;
	void SetCtrlStyle(HWND hWnd,DWORD dwNewStyle)
	{
		DWORD dwOldStyle;
		dwOldStyle=GetWindowLong(hWnd,GWL_STYLE);
		if((dwOldStyle&LVS_TYPEMASK)!=dwNewStyle)
		{
			dwOldStyle &=~LVS_TYPEMASK;
			dwNewStyle|=dwOldStyle;
			SetWindowLong(hWnd,GWL_STYLE,dwNewStyle);
		}
	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ListView)
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
	virtual ~CEx_ListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ListView)
	afx_msg void OnViewChange();
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ListView.cpp
inline CEx_ListDoc* CEx_ListView::GetDocument()
   { return (CEx_ListDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_LISTVIEW_H__30CA9DF7_0AD1_4AB5_A843_F04985EC77F7__INCLUDED_)
