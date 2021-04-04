// Ex_SDIArchiveDoc.h : interface of the CEx_SDIArchiveDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIARCHIVEDOC_H__718B2C67_A812_419A_B23B_7B579958D10C__INCLUDED_)
#define AFX_EX_SDIARCHIVEDOC_H__718B2C67_A812_419A_B23B_7B579958D10C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIArchiveDoc : public CDocument
{
protected: // create from serialization only
	CEx_SDIArchiveDoc();
	DECLARE_DYNCREATE(CEx_SDIArchiveDoc)

// Attributes
public:
	char m_chArchive[100];
	CString m_strArchive;
	BOOL m_bIsMyDoc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIArchiveDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SDIArchiveDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIArchiveDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIARCHIVEDOC_H__718B2C67_A812_419A_B23B_7B579958D10C__INCLUDED_)
