// Ex_SplitSDIDoc.h : interface of the CEx_SplitSDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SPLITSDIDOC_H__CBF8E03D_FC20_4244_9D50_2CCBF56A8B23__INCLUDED_)
#define AFX_EX_SPLITSDIDOC_H__CBF8E03D_FC20_4244_9D50_2CCBF56A8B23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SplitSDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_SplitSDIDoc();
	DECLARE_DYNCREATE(CEx_SplitSDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SplitSDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SplitSDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SplitSDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SPLITSDIDOC_H__CBF8E03D_FC20_4244_9D50_2CCBF56A8B23__INCLUDED_)
