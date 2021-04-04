// Ex_ListDoc.h : interface of the CEx_ListDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_LISTDOC_H__74EF4B2F_EFC9_4111_9A18_FEB782AA549A__INCLUDED_)
#define AFX_EX_LISTDOC_H__74EF4B2F_EFC9_4111_9A18_FEB782AA549A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ListDoc : public CDocument
{
protected: // create from serialization only
	CEx_ListDoc();
	DECLARE_DYNCREATE(CEx_ListDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ListDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ListDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ListDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_LISTDOC_H__74EF4B2F_EFC9_4111_9A18_FEB782AA549A__INCLUDED_)
