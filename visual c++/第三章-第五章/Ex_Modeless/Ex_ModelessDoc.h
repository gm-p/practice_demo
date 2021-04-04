// Ex_ModelessDoc.h : interface of the CEx_ModelessDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MODELESSDOC_H__A0AF71CC_D6DA_42F1_8590_15BD586D463D__INCLUDED_)
#define AFX_EX_MODELESSDOC_H__A0AF71CC_D6DA_42F1_8590_15BD586D463D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ModelessDoc : public CDocument
{
protected: // create from serialization only
	CEx_ModelessDoc();
	DECLARE_DYNCREATE(CEx_ModelessDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ModelessDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ModelessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ModelessDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MODELESSDOC_H__A0AF71CC_D6DA_42F1_8590_15BD586D463D__INCLUDED_)
