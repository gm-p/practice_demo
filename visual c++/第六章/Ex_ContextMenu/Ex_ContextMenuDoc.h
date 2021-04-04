// Ex_ContextMenuDoc.h : interface of the CEx_ContextMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CONTEXTMENUDOC_H__5F6F7FDA_D590_4A84_A383_B81689ADCC3C__INCLUDED_)
#define AFX_EX_CONTEXTMENUDOC_H__5F6F7FDA_D590_4A84_A383_B81689ADCC3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ContextMenuDoc : public CDocument
{
protected: // create from serialization only
	CEx_ContextMenuDoc();
	DECLARE_DYNCREATE(CEx_ContextMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ContextMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ContextMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ContextMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CONTEXTMENUDOC_H__5F6F7FDA_D590_4A84_A383_B81689ADCC3C__INCLUDED_)
