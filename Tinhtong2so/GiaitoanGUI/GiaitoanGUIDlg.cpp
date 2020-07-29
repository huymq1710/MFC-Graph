
// GiaitoanGUIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "GiaitoanGUI.h"
#include "GiaitoanGUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGiaitoanGUIDlg dialog



CGiaitoanGUIDlg::CGiaitoanGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GIAITOANGUI_DIALOG, pParent)
	, a(0)
	, b(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGiaitoanGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A, a);
	DDX_Text(pDX, IDC_EDIT_B, b);
	DDX_Control(pDX, IDC_TEXTKETQUA, mctrKetqua);
}

BEGIN_MESSAGE_MAP(CGiaitoanGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_A, &CGiaitoanGUIDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BTNTINHTONG, &CGiaitoanGUIDlg::OnBnClickedBtntinhtong)
	ON_BN_CLICKED(IDC_BTMTINHHIEU, &CGiaitoanGUIDlg::OnBnClickedBtmtinhhieu)
END_MESSAGE_MAP()


// CGiaitoanGUIDlg message handlers

BOOL CGiaitoanGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGiaitoanGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGiaitoanGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGiaitoanGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGiaitoanGUIDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CGiaitoanGUIDlg::OnBnClickedBtntinhtong()
{
	// Lay duoc gia tri tu 2 o nhap ( 2 o nhap lay kieu gtr la text)
	CString strA, strB;

	GetDlgItemText(IDC_EDIT_A, strA);
	GetDlgItemText(IDC_EDIT_B, strB);

	//CString -> int
	a = _wtoi(strA);
	b = _wtoi(strB);

	if (a == 0 && b == 0) {
		MessageBox(_T("Your input is null!"), _T("Error"), MB_ICONERROR | MB_OK);
	}
	tong = objGiaitoan.tinhtonghaiso(a, b);

	CString strKetqua;
	strKetqua.Format(L"%d", tong);
	mctrKetqua.SetWindowText(strKetqua);
}


void CGiaitoanGUIDlg::OnBnClickedBtmtinhhieu()
{
	// Lay duoc gia tri tu 2 o nhap ( 2 o nhap lay kieu gtr la text)
	CString strA, strB;

	GetDlgItemText(IDC_EDIT_A, strA);
	GetDlgItemText(IDC_EDIT_B, strB);

	//CString -> int
	a = _wtoi(strA);
	b = _wtoi(strB);

	if (a == 0 && b == 0) {
		MessageBox(_T("Your input is null!"), _T("Error"), MB_ICONERROR | MB_OK);
	}
	tong = objGiaitoan.tinhhieuhaiso(a, b);

	CString strKetqua;
	strKetqua.Format(L"%d", tong);
	mctrKetqua.SetWindowText(strKetqua);
}
