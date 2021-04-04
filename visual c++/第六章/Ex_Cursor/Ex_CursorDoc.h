// Ex_CursorDoc.h : interface of the CEx_CursorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CURSORDOC_H__70EA07C3_B5D3_4D99_971F_CB3FC4690501__INCLUDED_)
#define AFX_EX_CURSORDOC_H__70EA07C3_B5D3_4D99_971F_CB3FC4690501__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_CursorDoc : public CDocument
{
protected: // create from serialization only
	CEx_CursorDoc();
	DECLARE_DYNCREATE(CEx_CursorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CursorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_CursorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_CursorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CURSORDOC_H__70EA07C3_B5D3_4D99_971F_CB3FC4690501__INCLUDED_)
