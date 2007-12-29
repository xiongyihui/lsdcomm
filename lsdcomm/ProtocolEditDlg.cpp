// ProtocolEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "ProtocolEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProtocolEditDlg dialog


CProtocolEditDlg::CProtocolEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProtocolEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProtocolEditDlg)
	m_Edit = _T("");
	//}}AFX_DATA_INIT
}


void CProtocolEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProtocolEditDlg)
	DDX_Text(pDX, IDC_EDIT, m_Edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProtocolEditDlg, CDialog)
	//{{AFX_MSG_MAP(CProtocolEditDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProtocolEditDlg message handlers

BOOL CProtocolEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
