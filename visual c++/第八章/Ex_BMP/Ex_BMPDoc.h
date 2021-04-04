// Ex_BMPDoc.h : interface of the CEx_BMPDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_BMPDOC_H__BA0AAECD_9250_4D6A_9CCA_01E63A89F2E0__INCLUDED_)
#define AFX_EX_BMPDOC_H__BA0AAECD_9250_4D6A_9CCA_01E63A89F2E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_BMPDoc : public CDocument
{
protected: // create from serialization only
	CEx_BMPDoc();
	DECLARE_DYNCREATE(CEx_BMPDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_BMPDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_BMPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_BMPDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_BMPDOC_H__BA0AAECD_9250_4D6A_9CCA_01E63A89F2E0__INCLUDED_)
