// Ex_Ctlr3SDIDoc.h : interface of the CEx_Ctlr3SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTLR3SDIDOC_H__2DCFAB0C_F929_4CB6_90E6_087DF447F8BE__INCLUDED_)
#define AFX_EX_CTLR3SDIDOC_H__2DCFAB0C_F929_4CB6_90E6_087DF447F8BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctlr3SDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_Ctlr3SDIDoc();
	DECLARE_DYNCREATE(CEx_Ctlr3SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctlr3SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Ctlr3SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctlr3SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTLR3SDIDOC_H__2DCFAB0C_F929_4CB6_90E6_087DF447F8BE__INCLUDED_)
