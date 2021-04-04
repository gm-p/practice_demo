// Ex_Ctrl4SDIDoc.h : interface of the CEx_Ctrl4SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTRL4SDIDOC_H__E7EA1CF9_DC7A_4341_B97F_80ACD52F6565__INCLUDED_)
#define AFX_EX_CTRL4SDIDOC_H__E7EA1CF9_DC7A_4341_B97F_80ACD52F6565__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctrl4SDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_Ctrl4SDIDoc();
	DECLARE_DYNCREATE(CEx_Ctrl4SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl4SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_Ctrl4SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctrl4SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL4SDIDOC_H__E7EA1CF9_DC7A_4341_B97F_80ACD52F6565__INCLUDED_)
