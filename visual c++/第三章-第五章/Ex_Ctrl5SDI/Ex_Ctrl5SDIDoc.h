// Ex_Ctrl5SDIDoc.h : interface of the CEx_Ctrl5SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTRL5SDIDOC_H__83E0AB81_D766_44E3_A3BD_E459A7550D2C__INCLUDED_)
#define AFX_EX_CTRL5SDIDOC_H__83E0AB81_D766_44E3_A3BD_E459A7550D2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctrl5SDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_Ctrl5SDIDoc();
	DECLARE_DYNCREATE(CEx_Ctrl5SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl5SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Ctrl5SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctrl5SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL5SDIDOC_H__83E0AB81_D766_44E3_A3BD_E459A7550D2C__INCLUDED_)
