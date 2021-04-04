// Ex_TreeDoc.h : interface of the CEx_TreeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TREEDOC_H__90EA9B79_4D64_4B73_8544_E5E9A0036B78__INCLUDED_)
#define AFX_EX_TREEDOC_H__90EA9B79_4D64_4B73_8544_E5E9A0036B78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TreeDoc : public CDocument
{
protected: // create from serialization only
	CEx_TreeDoc();
	DECLARE_DYNCREATE(CEx_TreeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TreeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_TreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TreeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TREEDOC_H__90EA9B79_4D64_4B73_8544_E5E9A0036B78__INCLUDED_)
