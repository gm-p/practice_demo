// Ex_DySplitDoc.h : interface of the CEx_DySplitDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DYSPLITDOC_H__AAA6DCA9_F12B_4610_89A3_DB9CD5FD079C__INCLUDED_)
#define AFX_EX_DYSPLITDOC_H__AAA6DCA9_F12B_4610_89A3_DB9CD5FD079C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DySplitDoc : public CDocument
{
protected: // create from serialization only
	CEx_DySplitDoc();
	DECLARE_DYNCREATE(CEx_DySplitDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DySplitDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_DySplitDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DySplitDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DYSPLITDOC_H__AAA6DCA9_F12B_4610_89A3_DB9CD5FD079C__INCLUDED_)
