// SimpleDlgView.h : interface of the CSimpleDlgView class
//

#pragma once

constexpr UINT IDC_BUTTON10{ 110 };
constexpr UINT IDC_EDITBOX10{ 111 };

class CSimpleDlgView : public CView
{
protected: // create from serialization only
	CSimpleDlgView() noexcept;
	DECLARE_DYNCREATE(CSimpleDlgView)

	// Attributes
public:
	CSimpleDlgDoc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	void DrawGraph(CDC* pDC);
	void DrawUnit(CDC* pDC, int m_head, int m_distance);
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	int ConvertX(int x, int m_head, int m_distance);
	int ConvertY(int y, int m_head, int m_distance);
protected:

	// Implementation
public:
	virtual ~CSimpleDlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	void OnButton10Clicked();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnToolsOptions();
private:
	CString m_text{ _T("Place name here") };
	int m_bgColor{ 0 };
	//int m_x{950};
	//int m_y{500};
	//int m_r{100};
	float m_head{ 0 };
	float m_distance{ 50 };
	CButton m_button;
	CEdit m_editBox;
	CString tmp_editBox{ _T("900.000") };
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in SimpleDlgView.cpp
inline CSimpleDlgDoc* CSimpleDlgView::GetDocument() const
{
	return reinterpret_cast<CSimpleDlgDoc*>(m_pDocument);
}
#endif
