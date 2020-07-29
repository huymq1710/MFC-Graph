// CGraphCircleDlg.cpp : implementation file
//

#include "pch.h"
#include "SimpleDlg.h"
#include "CGraphCircleDlg.h"
#include "afxdialogex.h"


// CGraphCircleDlg dialog

IMPLEMENT_DYNAMIC(CGraphCircleDlg, CDialog)

CGraphCircleDlg::CGraphCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, m_a4(0)
	, m_b4(0)
	, m_r(0)
{

}

CGraphCircleDlg::~CGraphCircleDlg()
{
}

void CGraphCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A4, m_a4);
	DDX_Text(pDX, IDC_EDIT_B4, m_b4);
	DDX_Text(pDX, IDC_EDIT_R4, m_r);
}


BEGIN_MESSAGE_MAP(CGraphCircleDlg, CDialog)
END_MESSAGE_MAP()


// CGraphCircleDlg message handlers
