
// GiaitoanGUIDlg.h : header file
//

#pragma once
#include "Giaitoan.h"

// CGiaitoanGUIDlg dialog
class CGiaitoanGUIDlg : public CDialogEx
{
// Construction
public:
	CGiaitoanGUIDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIAITOANGUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int a;
	int b;
	Giaitoan objGiaitoan;
	int tong;
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedBtntinhtong();
	CStatic mctrKetqua;
	afx_msg void OnBnClickedBtmtinhhieu();
};
