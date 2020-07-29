#pragma once


// CGraph2Dlg dialog

class CGraph2Dlg : public CDialog
{
	DECLARE_DYNAMIC(CGraph2Dlg)

public:
	CGraph2Dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGraph2Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_text2;
	float m_a2;
	float m_b2;
	float m_c2;
};
