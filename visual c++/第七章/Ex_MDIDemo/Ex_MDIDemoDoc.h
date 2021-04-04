// Ex_MDIDemoDoc.h : interface of the CEx_MDIDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MDIDEMODOC_H__9C6CEBEE_7076_4965_9FB5_E8742CD65B30__INCLUDED_)
#define AFX_EX_MDIDEMODOC_H__9C6CEBEE_7076_4965_9FB5_E8742CD65B30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MDIDemoDoc : public CDocument
{
protected: // create from serialization only
	CEx_MDIDemoDoc();
	DECLARE_DYNCREATE(CEx_MDIDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MDIDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MDIDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDIDEMODOC_H__9C6CEBEE_7076_4965_9FB5_E8742CD65B30__INCLUDED_)
