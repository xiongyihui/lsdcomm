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
	mystr += "//"; mystr += re;
	mystr += "//2008-1-15 author:mrlong" ;mystr += re; 
	mystr += "//�����ִ�Сд";mystr += re; 
	mystr += "//"; mystr += re;
	mystr +=re;
	mystr += "�﷨��ʽ: ����=����1,����2,����3,..����n ;"; mystr +=re;
	mystr += "          ע��ÿ����������;�Ž�����"; mystr+=re;
	mystr += "ע�ͷ�# �������ǵ�һ���ַ����ռһ�С����� #�ҵ�˵����"; mystr +=re;
	mystr +=re;
	
	
	mystr += "1. send �������� "; mystr += re;
	mystr += " ����: 1.1 send=%1; ����%1��ʾָ��1"; mystr +=re;
	mystr += "       1.2 Send=68 01 01 68 41 00 41 16;"; mystr +=re;

	mystr +=re;
	mystr += "2. sleep ͣ��ʱ��(��λ����) "; mystr +=re;
	mystr += " ����: 2.1 sleep=300;"; mystr +=re;

	mystr +=re;
	mystr += "3. out �����ַ������մ���"; mystr +=re;
	mystr += " ����: 3.1 out=�ҵ��ַ�;"; mystr +=re;
	
	mystr +=re;
	mystr += "4. date ��ʱ�䷢�͵�����"; mystr +=re;
	mystr += " ����: 4.1 date=%Y-%m-%d %H:%M:%S ������ʾ��ʽ"; mystr +=re; 
	mystr += "   %Y=2008 ; %y=08, %m �� %M ��ͬ��ע����������Ĵ�Сд��"; mystr += re;
	mystr += "       4.2 date; �޲���Ĭ���Ǹ�ʽΪ%Y-%m-%d %H:%M:%S��"; mystr +=re;

	mystr +=re;
	mystr += "5. clear ��ս��մ�������"; mystr +=re;
	mystr += " ���� clear;"; mystr +=re;
	

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
