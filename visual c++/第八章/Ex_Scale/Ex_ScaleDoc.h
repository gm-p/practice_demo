// Ex_ScaleDoc.h : interface of the CEx_ScaleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SCALEDOC_H__E427A3EA_D84F_422F_BE46_3A9DE7F55EC8__INCLUDED_)
#define AFX_EX_SCALEDOC_H__E427A3EA_D84F_422F_BE46_3A9DE7F55EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ScaleDoc : public CDocument
{
protected: // create from serialization only
	CEx_ScaleDoc();
	DECLARE_DYNCREATE(CEx_ScaleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ScaleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ScaleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ScaleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SCALEDOC_H__E427A3EA_D84F_422F_BE46_3A9DE7F55EC8__INCLUDED_)
