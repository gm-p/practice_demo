// Ex_EditDoc.h : interface of the CEx_EditDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_EDITDOC_H__2BE88A0C_7CDD_4CCB_872B_44062686EF48__INCLUDED_)
#define AFX_EX_EDITDOC_H__2BE88A0C_7CDD_4CCB_872B_44062686EF48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_EditDoc : public CDocument
{
protected: // create from serialization only
	CEx_EditDoc();
	DECLARE_DYNCREATE(CEx_EditDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_EditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_EditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_EditDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_EDITDOC_H__2BE88A0C_7CDD_4CCB_872B_44062686EF48__INCLUDED_)
