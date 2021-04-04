// Ex_MultiBarDoc.h : interface of the CEx_MultiBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MULTIBARDOC_H__AB929237_35C6_4204_9772_25709B4E62DB__INCLUDED_)
#define AFX_EX_MULTIBARDOC_H__AB929237_35C6_4204_9772_25709B4E62DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MultiBarDoc : public CDocument
{
protected: // create from serialization only
	CEx_MultiBarDoc();
	DECLARE_DYNCREATE(CEx_MultiBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MultiBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MultiBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MultiBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MULTIBARDOC_H__AB929237_35C6_4204_9772_25709B4E62DB__INCLUDED_)
