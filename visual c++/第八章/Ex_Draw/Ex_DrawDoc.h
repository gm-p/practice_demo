// Ex_DrawDoc.h : interface of the CEx_DrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DRAWDOC_H__A3BCFEA0_3ADF_41F9_BEAD_FEFBCADD148D__INCLUDED_)
#define AFX_EX_DRAWDOC_H__A3BCFEA0_3ADF_41F9_BEAD_FEFBCADD148D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DrawDoc : public CDocument
{
protected: // create from serialization only
	CEx_DrawDoc();
	DECLARE_DYNCREATE(CEx_DrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_DrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DRAWDOC_H__A3BCFEA0_3ADF_41F9_BEAD_FEFBCADD148D__INCLUDED_)
