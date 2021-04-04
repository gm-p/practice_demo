// Ex_DySplitDoc.cpp : implementation of the CEx_DySplitDoc class
//

#include "stdafx.h"
#include "Ex_DySplit.h"

#include "Ex_DySplitDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitDoc

IMPLEMENT_DYNCREATE(CEx_DySplitDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_DySplitDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_DySplitDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitDoc construction/destruction

CEx_DySplitDoc::CEx_DySplitDoc()
{
	// TODO: add one-time construction code here

}

CEx_DySplitDoc::~CEx_DySplitDoc()
{
}

BOOL CEx_DySplitDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitDoc serialization

void CEx_DySplitDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitDoc diagnostics

#ifdef _DEBUG
void CEx_DySplitDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_DySplitDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitDoc commands
