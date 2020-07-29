#pragma once


// CGraphCircleDlg dialog

class CGraphCircleDlg : public CDialog
{
	DECLARE_DYNAMIC(CGraphCircleDlg)

public:
	CGraphCircleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGraphCircleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_a4;
	int m_b4;
	int m_r;
};
