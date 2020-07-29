// CGraph1Dlg.cpp : implementation file
//

#include "pch.h"
#include "SimpleDlg.h"
#include "CGraph1Dlg.h"
#include "afxdialogex.h"


// CGraph1Dlg dialog

IMPLEMENT_DYNAMIC(CGraph1Dlg, CDialog)

CGraph1Dlg::CGraph1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_a1(0)
	, m_b1(0)
	, m_text1(_T(""))
{

}

CGraph1Dlg::~CGraph1Dlg()
{
}

void CGraph1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A1, m_a1);
	DDX_Text(pDX, IDC_EDIT_B1, m_b1);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text1);
}


BEGIN_MESSAGE_MAP(CGraph1Dlg, CDialog)
END_MESSAGE_MAP()


// CGraph1Dlg message handlers
