// SimpleDlgView.cpp : implementation of the CSimpleDlgView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SimpleDlg.h"
#endif

#include "SimpleDlgDoc.h"
#include "SimpleDlgView.h"
#include "COptions.h"

#include "CGraph1Dlg.h"
#include "CGraph2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleDlgView

IMPLEMENT_DYNCREATE(CSimpleDlgView, CView)

BEGIN_MESSAGE_MAP(CSimpleDlgView, CView, CEdit)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOLS_OPTIONS, &CSimpleDlgView::OnToolsOptions)
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10Clicked)
	ON_WM_LBUTTONDBLCLK(IDC_EDITBOX10, &MessageManage::OnItemDoubleClick)
END_MESSAGE_MAP()

// CSimpleDlgView construction/destruction

CSimpleDlgView::CSimpleDlgView() noexcept
{
	// TODO: add construction code here

}

CSimpleDlgView::~CSimpleDlgView()
{
}

BOOL CSimpleDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimpleDlgView drawing

//2 ham tinhj tien vector do thi
int CSimpleDlgView::ConvertX(int x, int m_head, int m_distance) {
	return (50 * x) / m_distance + 250 - (50 * m_head) / m_distance;
}
int CSimpleDlgView::ConvertY(int y, int m_head, int m_distance) {
	return 900 + (50 * m_head) / m_distance - (50 * y) / m_distance;
}

void CSimpleDlgView::DrawGraph(CDC* pDC) {
	pDC->TextOutW(0, 0, m_text);

	CBrush brush(RGB(230, 230, 230));
	CBrush* pBrush = pDC->SelectObject(&brush);
	pDC->Rectangle(250, 0, 2000, 900);
	pDC->SelectObject(pBrush);

	CPen pen;
	pen.CreatePen(PS_DASH, 0.5, RGB(0, 0, 0));
	pDC->SelectObject(&pen);

	for (int i = 850; i > 0; i = i - 50) {
		pDC->MoveTo(250, i);
		pDC->LineTo(2000, i);

	}

	for (int i = 300; i < 2000; i = i + 50) {
		pDC->MoveTo(i, 900);
		pDC->LineTo(i, 0);
	}
}

void CSimpleDlgView::DrawUnit(CDC* pDC, int m_head, int m_distance) {
	CString headBegin;
	headBegin.Format(_T("%d"), m_head);
	pDC->TextOutW(220, 920, headBegin);

	float last_x = m_head + 33 * m_distance;
	CString endX;
	endX.Format(_T("%6.3f"), last_x);
	pDC->TextOutW(2000 - 16, 920, endX);

	float last_y = m_head + 18 * m_distance;
	CString endY;
	endY.Format(_T("%6.3f"), last_y);
	pDC->TextOutW(195, 0, endY);

	CString toa_doY;
	float pos_y = m_distance;
	for (int i = 850; i > 0; i = i - 50) {
		toa_doY.Format(_T("%6.3f"), pos_y);
		pos_y += m_distance;
		pDC->TextOutW(195, i - 7, toa_doY);
	}

	CString toa_doX;
	float pos_x = m_distance;
	for (int i = 300; i < 2000; i = i + 50) {
		toa_doX.Format(_T("%4.1f"), pos_x);
		pos_x += m_distance;
		pDC->TextOutW(i - 18, 920, toa_doX);
	}

}


void CSimpleDlgView::OnDraw(CDC* pDC)
{


	CSimpleDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect clientRect;
	GetClientRect(clientRect);
	//clientRect.bottom /= 9;
	if (m_bgColor == 0) {
		pDC->FillSolidRect(clientRect, RGB(200, 200, 200)); //GREY
	}
	else if (m_bgColor == 1) {
		pDC->FillSolidRect(clientRect, RGB(200, 54, 54)); //RED
	}


	//Ve khung do thi
	DrawGraph(pDC);

	//Ve duong do thi y= ax+b
	//pDC->TextOutW(250, 50, pDoc->GetText());
	int a1 = pDoc->GetA1();
	int b1 = pDoc->GetB1();
	if (a1 != 0 && b1 != 0 && a1 != -842150451 && b1 != -842150451) {
		pDC->MoveTo(ConvertX(m_head, m_head, m_distance), ConvertY(m_head * a1 + b1, m_head, m_distance)); //Diem dau la m_head
		CPen pen;
		pen.CreatePen(PS_DOT, 4, RGB(54, 54, 200));
		pDC->SelectObject(&pen);
		for (int i = m_distance; i < m_head + 33 * m_distance; i += 1) {
			pDC->LineTo(ConvertX(i, m_head, m_distance), ConvertY(i * a1 + b1, m_head, m_distance));
		}
	}

	//Ve duong do thi y=ax^2+bx+c
	//pDC->TextOutW(1400, 50, pDoc->GetText2());
	float a2 = pDoc->GetA2();
	float b2 = pDoc->GetB2();
	float c2 = pDoc->GetC2();
	if (a2 != 0 && b2 != 0 && a2 != -842150451 && b2 != -842150451) {
		pDC->MoveTo(ConvertX(m_head, m_head, m_distance), ConvertY(a2 * pow(m_head, 2) + b2 * m_head + c2, m_head, m_distance)); //Diem dau la m_head
		CPen pen;
		pen.CreatePen(PS_DOT, 4, RGB(200, 54, 54));
		pDC->SelectObject(&pen);
		for (float i = m_distance; i < m_head + 33 * m_distance; i += 1) {
			pDC->LineTo(ConvertX(i, m_head, m_distance), ConvertY(a2 * pow(i, 2) + b2 * i + c2, m_head, m_distance));
		}
	}

	//Ve hinh tron (x-a)^2+(y-b)^2=R^2
	int a4 = pDoc->GetA4();
	int b4 = pDoc->GetB4();
	int R = pDoc->GetR();
	// O(m_x,m_y), R= m_r => 2 diem chan tren duoi => A(mx-mr,my+mr) B(mx+mr,my-mr)
	CPen pen;
	pen.CreatePen(PS_DOT, 4, RGB(54, 200, 54));
	pDC->SelectObject(&pen);
	//pDC->Ellipse(ConvertX(a4-R), ConvertY(b4+ R), ConvertX(a4 +R), ConvertY(b4-R));
	pDC->Arc(ConvertX(a4 - R, m_head, m_distance), ConvertY(b4 + R, m_head, m_distance), ConvertX(a4 + R, m_head, m_distance), ConvertY(b4 - R, m_head, m_distance), ConvertX(a4 + R, m_head, m_distance), ConvertY(b4, m_head, m_distance), ConvertX(a4 - R, m_head, m_distance), ConvertY(b4, m_head, m_distance));
	pDC->SetArcDirection(AD_CLOCKWISE);
	pDC->Arc(ConvertX(a4 - R, m_head, m_distance), ConvertY(b4 + R, m_head, m_distance), ConvertX(a4 + R, m_head, m_distance), ConvertY(b4 - R, m_head, m_distance), ConvertX(a4 + R, m_head, m_distance), ConvertY(b4, m_head, m_distance), ConvertX(a4 - R, m_head, m_distance), ConvertY(b4, m_head, m_distance));

	//Chen khung nen de che cac net thua
	DrawUnit(pDC, m_head, m_distance);


}

void CSimpleDlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSimpleDlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSimpleDlgView diagnostics

#ifdef _DEBUG
void CSimpleDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CSimpleDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleDlgDoc* CSimpleDlgView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleDlgDoc)));
	return (CSimpleDlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CSimpleDlgView message handlers

void CSimpleDlgView::OnToolsOptions()
{
	COptions dlgOptions;

	dlgOptions.m_text = m_text;
	dlgOptions.m_bgColor = m_bgColor;
	dlgOptions.m_head = m_head;
	dlgOptions.m_distance = m_distance;

	if (dlgOptions.DoModal() == IDOK) { //Neu cua so Ok -> Lay cac gtri tu cua so
		m_text = dlgOptions.m_text;
		m_bgColor = dlgOptions.m_bgColor;
		m_head = dlgOptions.m_head;
		m_distance = dlgOptions.m_distance;
	}
	Invalidate();
	UpdateWindow();
}


void CSimpleDlgView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CString str1, str2;
	str1.Format(_T("Window -> X': %04d,Y': %04d"), (int)point.x, (int)point.y); //%04d : so in ra co 4 chu so, neu it hon thi them 0 o dau
	dc.TextOutW(0, 420, str1);

	float x, y; //Tu x',y' ve x,y
	x = (float)(point.x - 250 + (float)(50 * (float)m_head) / m_distance) * (float)((float)m_distance / 50);
	y = (float)(point.y - 900 - (float)(50 * (float)m_head) / m_distance) * (float)(-(float)m_distance / 50);
	str2.Format(_T("Graph -> X: %5.3f,Y: %5.3f"), x, y);
	dc.TextOutW(0, 520, str2);


	CView::OnMouseMove(nFlags, point);
}


//#include <cctype>
//
//Cstring Validate(CString str)
//{
// for (int i = 0; i < str.GetLength(); i++) {
// if (!std::isdigit(str[i]))
// return _T("string contains non numeric characters");
// }
// return _T("string only numeric characters");
//}

//Enter to get value: https://stackoverflow.com/questions/15711311/edit-control-capture-enter-key


void CSimpleDlgView::OnButton10Clicked() {
	m_editBox.GetWindowTextW(tmp_editBox);
	if (!tmp_editBox.IsEmpty()) {
		if (0) { // Check xem input co chu hay ko
			AfxMessageBox(L"Nhap so di :D!");
		}
		else {
			AfxMessageBox(tmp_editBox);
			float last_y = _ttoi(tmp_editBox);
			tmp_editBox.Format(_T("%6.3f"), last_y);
			m_editBox.SetWindowTextW(tmp_editBox);
			m_distance = (float)(last_y - m_head) / 18;
		}

	}
	else {
		AfxMessageBox(L"Hi! Nhap gi do di");
	}

	UpdateData(FALSE);
	Invalidate();
	UpdateWindow();

}

void CSimpleDlgView::OnLButtonDblClk(UINT nFlags, CPoint point) {
	CClientDC dc(this);
	CString str3;
	float x1, y1;
	x1 = (float)((float)point.x - 250);
	y1 = (float)((float)point.y - 900);
	str3.Format(_T("Graph -> X: %5.3f,Y: %5.3f"), x1, y1);
	dc.TextOutW(0, 920, str3);

	if (x1 < 10 && x1> -70 && y1 < -870) {
		//AfxMessageBox(L"Hi");
		m_editBox.ShowWindow(SW_SHOW);
	}
	else {
		m_editBox.ShowWindow(HIDE_WINDOW);
		m_editBox.GetWindowTextW(tmp_editBox);
		AfxMessageBox(tmp_editBox);
		float last_y = _ttoi(tmp_editBox);
		tmp_editBox.Format(_T("%6.3f"), last_y);
		m_editBox.SetWindowTextW(tmp_editBox);
		m_distance = (float)(last_y - m_head) / 18;
		Invalidate();
		UpdateWindow();
	}

}

int CSimpleDlgView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_button.Create(_T("OK"), BS_BOTTOM, CRect(195, 21, 247, 44), this, IDC_BUTTON10);
	//m_button.ShowWindow(SW_SHOW);
	//m_editBox.ShowWindow(HIDE_WINDOW);


	m_editBox.Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(192, 0, 249, 20), this, IDC_EDITBOX10);
	//m_editBox.ShowWindow(SW_SHOW);
	m_editBox.ShowWindow(HIDE_WINDOW);

	m_editBox.SetWindowTextW(tmp_editBox);
	return 0;
}
