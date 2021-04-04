// Ex_TextDoc.h : interface of the CEx_TextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TEXTDOC_H__AA1B18A9_E365_4948_BE47_D911E7972FE8__INCLUDED_)
#define AFX_EX_TEXTDOC_H__AA1B18A9_E365_4948_BE47_D911E7972FE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TextDoc : public CDocument
{
protected: // create from serialization only
	CEx_TextDoc();
	DECLARE_DYNCREATE(CEx_TextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CStringArray m_strContents;
	virtual ~CEx_TextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TEXTDOC_H__AA1B18A9_E365_4948_BE47_D911E7972FE8__INCLUDED_)
