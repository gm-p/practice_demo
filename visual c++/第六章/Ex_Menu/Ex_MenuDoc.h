// Ex_MenuDoc.h : interface of the CEx_MenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MENUDOC_H__C04FF2D1_F6D0_4D34_8367_A8BFB1980DB0__INCLUDED_)
#define AFX_EX_MENUDOC_H__C04FF2D1_F6D0_4D34_8367_A8BFB1980DB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MenuDoc : public CDocument
{
protected: // create from serialization only
	CEx_MenuDoc();
	DECLARE_DYNCREATE(CEx_MenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENUDOC_H__C04FF2D1_F6D0_4D34_8367_A8BFB1980DB0__INCLUDED_)
