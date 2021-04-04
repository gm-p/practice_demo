// Ex_ArrayDoc.h : interface of the CEx_ArrayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ARRAYDOC_H__CF67D923_3F77_4563_B638_524C9E8F8F8E__INCLUDED_)
#define AFX_EX_ARRAYDOC_H__CF67D923_3F77_4563_B638_524C9E8F8F8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ArrayDoc : public CDocument
{
protected: // create from serialization only
	CEx_ArrayDoc();
	DECLARE_DYNCREATE(CEx_ArrayDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ArrayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CStringArray m_strContents;
	virtual ~CEx_ArrayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ArrayDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ARRAYDOC_H__CF67D923_3F77_4563_B638_524C9E8F8F8E__INCLUDED_)
