// OtherDoc.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_MDIDemo.h"
#include "OtherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COtherDoc

IMPLEMENT_DYNCREATE(COtherDoc, CDocument)

COtherDoc::COtherDoc()
{
}

BOOL COtherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

COtherDoc::~COtherDoc()
{
}


BEGIN_MESSAGE_MAP(COtherDoc, CDocument)
	//{{AFX_MSG_MAP(COtherDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COtherDoc diagnostics

#ifdef _DEBUG
void COtherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COtherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COtherDoc serialization

void COtherDoc::Serialize(CArchive& ar)
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
// COtherDoc commands
