#pragma once


// CGraph1Dlg dialog

class CGraph1Dlg : public CDialog
{
	DECLARE_DYNAMIC(CGraph1Dlg)

public:
	CGraph1Dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGraph1Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_a1{ 0 };
	int m_b1{ 0 };
	CString m_text1{ "Graph Name: y=ax+b" };
};
