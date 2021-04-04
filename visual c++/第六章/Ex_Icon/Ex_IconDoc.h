// Ex_IconDoc.h : interface of the CEx_IconDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ICONDOC_H__49735BB0_E7FA_483D_8670_438E62ACDD88__INCLUDED_)
#define AFX_EX_ICONDOC_H__49735BB0_E7FA_483D_8670_438E62ACDD88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_IconDoc : public CDocument
{
protected: // create from serialization only
	CEx_IconDoc();
	DECLARE_DYNCREATE(CEx_IconDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_IconDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_IconDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_IconDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ICONDOC_H__49735BB0_E7FA_483D_8670_438E62ACDD88__INCLUDED_)
