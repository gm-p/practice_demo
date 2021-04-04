#if !defined(AFX_OTHERDOC_H__7DED3CB3_7318_4488_A659_3BB331AA7FD7__INCLUDED_)
#define AFX_OTHERDOC_H__7DED3CB3_7318_4488_A659_3BB331AA7FD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OtherDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COtherDoc document

class COtherDoc : public CDocument
{
protected:
	COtherDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COtherDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COtherDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COtherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(COtherDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHERDOC_H__7DED3CB3_7318_4488_A659_3BB331AA7FD7__INCLUDED_)
