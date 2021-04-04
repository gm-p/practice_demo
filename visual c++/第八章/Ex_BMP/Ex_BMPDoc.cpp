// Ex_BMPDoc.cpp : implementation of the CEx_BMPDoc class
//

#include "stdafx.h"
#include "Ex_BMP.h"

#include "Ex_BMPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPDoc

IMPLEMENT_DYNCREATE(CEx_BMPDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_BMPDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_BMPDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPDoc construction/destruction

CEx_BMPDoc::CEx_BMPDoc()
{
	// TODO: add one-time construction code here

}

CEx_BMPDoc::~CEx_BMPDoc()
{
}

BOOL CEx_BMPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_BMPDoc serialization

void CEx_BMPDoc::Serialize(CArchive& ar)
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
// CEx_BMPDoc diagnostics

#ifdef _DEBUG
void CEx_BMPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_BMPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPDoc commands
