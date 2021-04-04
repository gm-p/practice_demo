// Ex_Ctrl1SDIDoc.h : interface of the CEx_Ctrl1SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTRL1SDIDOC_H__4D9B503A_1DBE_46AB_AF0E_0B0131DF0AB2__INCLUDED_)
#define AFX_EX_CTRL1SDIDOC_H__4D9B503A_1DBE_46AB_AF0E_0B0131DF0AB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctrl1SDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_Ctrl1SDIDoc();
	DECLARE_DYNCREATE(CEx_Ctrl1SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl1SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Ctrl1SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctrl1SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL1SDIDOC_H__4D9B503A_1DBE_46AB_AF0E_0B0131DF0AB2__INCLUDED_)
