// Ex_SDIHelloDoc.h : interface of the CEx_SDIHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIHELLODOC_H__A5704D48_25CD_475B_A8AC_EF55FF8AB8E0__INCLUDED_)
#define AFX_EX_SDIHELLODOC_H__A5704D48_25CD_475B_A8AC_EF55FF8AB8E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIHelloDoc : public CDocument
{
protected: // create from serialization only
	CEx_SDIHelloDoc();
	DECLARE_DYNCREATE(CEx_SDIHelloDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIHelloDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SDIHelloDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIHelloDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIHELLODOC_H__A5704D48_25CD_475B_A8AC_EF55FF8AB8E0__INCLUDED_)
