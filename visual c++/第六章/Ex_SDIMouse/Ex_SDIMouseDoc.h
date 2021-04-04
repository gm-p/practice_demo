// Ex_SDIMouseDoc.h : interface of the CEx_SDIMouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIMOUSEDOC_H__008D78DA_7182_4C26_B243_70763B78C2E6__INCLUDED_)
#define AFX_EX_SDIMOUSEDOC_H__008D78DA_7182_4C26_B243_70763B78C2E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIMouseDoc : public CDocument
{
protected: // create from serialization only
	CEx_SDIMouseDoc();
	DECLARE_DYNCREATE(CEx_SDIMouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIMouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SDIMouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIMouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIMOUSEDOC_H__008D78DA_7182_4C26_B243_70763B78C2E6__INCLUDED_)
