// CGraph2Dlg.cpp : implementation file
//

#include "pch.h"
#include "SimpleDlg.h"
#include "CGraph2Dlg.h"
#include "afxdialogex.h"


// CGraph2Dlg dialog

IMPLEMENT_DYNAMIC(CGraph2Dlg, CDialog)

CGraph2Dlg::CGraph2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_text2(_T(""))
	, m_a2(0)
	, m_b2(0)
	, m_c2(0)
{

}

CGraph2Dlg::~CGraph2Dlg()
{
}

void CGraph2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT2, m_text2);
	DDX_Text(pDX, IDC_EDIT_A2, m_a2);
	DDX_Text(pDX, IDC_EDIT_B2, m_b2);
	DDX_Text(pDX, IDC_EDIT_C2, m_c2);
}


BEGIN_MESSAGE_MAP(CGraph2Dlg, CDialog)
END_MESSAGE_MAP()


// CGraph2Dlg message handlers
