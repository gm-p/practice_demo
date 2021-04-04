// Ex_StudentDoc.h : interface of the CEx_StudentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTDOC_H__F0E9A860_C564_4A4B_92A0_7A42780363B2__INCLUDED_)
#define AFX_EX_STUDENTDOC_H__F0E9A860_C564_4A4B_92A0_7A42780363B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStudent:public CObject
{
	CString strName;
	CString strID;
	float fScore1,fScore2,fScore3;
	float fAverage;
	DECLARE_SERIAL(CStudent)
public:
	CStudent() {};
	CStudent(CString name,CString id,float f1,float f2,float f3);
	void Serialize(CArchive &ar);
	void Display(int y,CDC *pDC);
};
class CEx_StudentDoc : public CDocument
{
protected: // create from serialization only
	CEx_StudentDoc();
	DECLARE_DYNCREATE(CEx_StudentDoc)

// Attributes
public:
	CObArray m_stuObArray;
	int GetAllRecNum(void);
	CStudent *GetStudentAt(int nIndex);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_StudentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentDoc)
	afx_msg void OnSturecAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTDOC_H__F0E9A860_C564_4A4B_92A0_7A42780363B2__INCLUDED_)
