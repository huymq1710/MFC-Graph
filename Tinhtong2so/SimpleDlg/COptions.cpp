// COptions.cpp : implementation file
//

#include "pch.h"
#include "SimpleDlg.h"
#include "COptions.h"
#include "afxdialogex.h"


// COptions dialog

IMPLEMENT_DYNAMIC(COptions, CDialog)

COptions::COptions(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_OPTIONS, pParent)
	, m_text(_T(""))
	, m_bgColor(0)
	, m_head(0)
	, m_distance(0)
{

}

COptions::~COptions()
{
}

void COptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
	DDX_Radio(pDX, IDC_RADIO_RED, m_bgColor);
	//DDX_Text(pDX, IDC_EDIT_POS_X, m_x);
	//DDV_MinMaxInt(pDX, m_x, 0, 99999999);
	//DDX_Text(pDX, IDC_EDIT_POS_Y, m_y);
	//DDV_MinMaxInt(pDX, m_y, 0, 999999999);
	//DDX_Text(pDX, IDC_EDIT_R, m_r);
	//DDV_MinMaxInt(pDX, m_r, 0, 99999999);
	DDX_Text(pDX, IDC_EDIT_HEAD, m_head);
	DDX_Text(pDX, IDC_EDIT_DISTANCE, m_distance);
}


BEGIN_MESSAGE_MAP(COptions, CDialog)
END_MESSAGE_MAP()


// COptions message handlers
