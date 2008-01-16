// ScriptHelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "ScriptHelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptHelpDlg dialog


CScriptHelpDlg::CScriptHelpDlg(CWnd* pParent /*=NULL*/)
	: ETSLayoutDialog(CScriptHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScriptHelpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScriptHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	ETSLayoutDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptHelpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	CString mystr;
	char   re[3]   =   {VK_RETURN,   0x0a};
	
	mystr = "//2008-1-15 author:mrlong" ;mystr +=   re; 
	mystr += "//不区分大小写";mystr += re; 
	mystr +=re;
	mystr += "语法格式: 命令=参数1,参数2,参数3,..参数n ;"; mystr +=re;
	mystr += "          注意每个语句必须用;号结束。"; mystr+=re;
	mystr +=re;
	
	mystr += "1. send 发送命令 "; mystr += re;
	mystr += " 例如: 1.1 send=#1; 其中#1表示指令1"; mystr +=re;
	mystr += "       1.2 Send=68 01 01 68 41 00 41 16;"; mystr +=re;

	mystr +=re;
	mystr += "2. sleep 停留时间(单位毫秒) "; mystr +=re;
	mystr += " 例如: 2.1 sleep=300;"; mystr +=re;

	mystr +=re;
	mystr += "3. out 发送字符到接收窗口"; mystr +=re;
	mystr += " 例如: 3.1 out=我的字符;"; mystr +=re;
	

	CEdit * myedit = (CEdit *) GetDlgItem(IDC_EDIT1);
	myedit->SetWindowText(_T(mystr));

}


BEGIN_MESSAGE_MAP(CScriptHelpDlg, ETSLayoutDialog)
	//{{AFX_MSG_MAP(CScriptHelpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptHelpDlg message handlers

BOOL CScriptHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CreateRoot(VERTICAL)
		<< item (IDC_EDIT1)
		<<	( pane(HORIZONTAL, ABSOLUTE_VERT )
		<< itemGrowing (HORIZONTAL) 
		<< item( IDOK, NORESIZE)
		<< item( IDCANCEL, NORESIZE )
		);
	
	UpdateLayout();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
