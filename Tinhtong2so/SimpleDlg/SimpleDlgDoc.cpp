
// SimpleDlgDoc.cpp : implementation of the CSimpleDlgDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SimpleDlg.h"
#endif

#include "SimpleDlgDoc.h"

#include "CGraph1Dlg.h"
#include "CGraph2Dlg.h"
#include "CGraphCircleDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSimpleDlgDoc

IMPLEMENT_DYNCREATE(CSimpleDlgDoc, CDocument)

BEGIN_MESSAGE_MAP(CSimpleDlgDoc, CDocument)
	ON_COMMAND(ID_GRAPH_DRAW, &CSimpleDlgDoc::OnGraph1Draw)
	ON_COMMAND(ID_GRAPH_Y, &CSimpleDlgDoc::OnGraph2Draw)
	ON_COMMAND(ID_GRAPH_, &CSimpleDlgDoc::OnGraphCircle)
END_MESSAGE_MAP()


// CSimpleDlgDoc construction/destruction

CSimpleDlgDoc::CSimpleDlgDoc() noexcept
{
	// TODO: add one-time construction code here

}

CSimpleDlgDoc::~CSimpleDlgDoc()
{
}

BOOL CSimpleDlgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSimpleDlgDoc serialization

void CSimpleDlgDoc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSimpleDlgDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSimpleDlgDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSimpleDlgDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSimpleDlgDoc diagnostics

#ifdef _DEBUG
void CSimpleDlgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSimpleDlgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSimpleDlgDoc commands


void CSimpleDlgDoc::OnGraph1Draw()
{
	// TODO: Add your command handler code here
	//AfxMessageBox(L"Hi");
	CGraph1Dlg dlgSetAB;
	if (dlgSetAB.DoModal() == IDOK) {
		m_a1 = dlgSetAB.m_a1;
		m_b1 = dlgSetAB.m_b1;
		m_text1 = dlgSetAB.m_text1;
		UpdateAllViews(NULL);
	}
}


void CSimpleDlgDoc::OnGraph2Draw()
{
	// TODO: Add your command handler code here
	CGraph2Dlg dlgSetABC;
	if (dlgSetABC.DoModal() == IDOK) {
		m_a2 = dlgSetABC.m_a2;
		m_b2 = dlgSetABC.m_b2;
		m_c2 = dlgSetABC.m_c2;
		m_text2 = dlgSetABC.m_text2;
		UpdateAllViews(NULL);
	}
}


void CSimpleDlgDoc::OnGraphCircle()
{
	// TODO: Add your command handler code here
	CGraphCircleDlg dlgCircle;
	if (dlgCircle.DoModal() == IDOK) {
		m_a4 = dlgCircle.m_a4;
		m_b4 = dlgCircle.m_b4;
		m_r = dlgCircle.m_r;
		UpdateAllViews(NULL);
	}
}
