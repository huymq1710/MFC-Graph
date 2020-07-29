#pragma once


// COptions dialog

class COptions : public CDialog
{
	DECLARE_DYNAMIC(COptions)

public:
	COptions(CWnd* pParent = nullptr);   // standard constructor
	virtual ~COptions();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPTIONS};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_text;
	int m_bgColor;
	//int m_x;
	//int m_y;
	//int m_r;
	int m_head;
	int m_distance;
};
