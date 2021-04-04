// Ex_ADODoc.h : interface of the CEx_ADODoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ADODOC_H__860DCD8C_E6CF_463E_A331_E0766348A89D__INCLUDED_)
#define AFX_EX_ADODOC_H__860DCD8C_E6CF_463E_A331_E0766348A89D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ADODoc : public CDocument
{
protected: // create from serialization only
	CEx_ADODoc();
	DECLARE_DYNCREATE(CEx_ADODoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ADODoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ADODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ADODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ADODOC_H__860DCD8C_E6CF_463E_A331_E0766348A89D__INCLUDED_)
