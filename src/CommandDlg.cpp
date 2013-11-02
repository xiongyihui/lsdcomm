// CommandDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "CommandDlg.h"
#include "ScriptHelpDlg.h"
#include "MyCommDoc.h"
#include "MyCommView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommandDlg dialog
CCommandDlg::CCommandDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommandDlg::IDD, pParent)
{
	win = pParent;
	//{{AFX_DATA_INIT(CCommandDlg)
	m_strCommand_1 = _T("");
	m_strName_1 = _T("");
	m_strName_10 = _T("");
	m_strName_11 = _T("");
	m_strName_12 = _T("");
	m_strName_13 = _T("");
	m_strName_14 = _T("");
	m_strName_15 = _T("");
	m_strName_16 = _T("");
	m_strName_17 = _T("");
	m_strName_18 = _T("");
	m_strName_19 = _T("");
	m_strName_2 = _T("");
	m_strName_20 = _T("");
	m_strName_3 = _T("");
	m_strName_4 = _T("");
	m_strName_5 = _T("");
	m_strName_6 = _T("");
	m_strName_7 = _T("");
	m_strName_8 = _T("");
	m_strName_9 = _T("");
	m_strCommand_10 = _T("");
	m_strCommand_11 = _T("");
	m_strCommand_12 = _T("");
	m_strCommand_13 = _T("");
	m_strCommand_14 = _T("");
	m_strCommand_15 = _T("");
	m_strCommand_16 = _T("");
	m_strCommand_17 = _T("");
	m_strCommand_18 = _T("");
	m_strCommand_19 = _T("");
	m_strCommand_2 = _T("");
	m_strCommand_20 = _T("");
	m_strCommand_3 = _T("");
	m_strCommand_4 = _T("");
	m_strCommand_5 = _T("");
	m_strCommand_6 = _T("");
	m_strCommand_7 = _T("");
	m_strCommand_8 = _T("");
	m_strCommand_9 = _T("");
	m_IsHex_1 = FALSE;
	m_IsHex_10 = FALSE;
	m_IsHex_11 = FALSE;
	m_IsHex_12 = FALSE;
	m_IsHex_13 = FALSE;
	m_IsHex_14 = FALSE;
	m_IsHex_15 = FALSE;
	m_IsHex_16 = FALSE;
	m_IsHex_17 = FALSE;
	m_IsHex_18 = FALSE;
	m_IsHex_19 = FALSE;
	m_IsHex_2 = FALSE;
	m_IsHex_20 = FALSE;
	m_IsHex_3 = FALSE;
	m_IsHex_4 = FALSE;
	m_IsHex_5 = FALSE;
	m_IsHex_6 = FALSE;
	m_IsHex_7 = FALSE;
	m_IsHex_8 = FALSE;
	m_IsHex_9 = FALSE;
	m_IsScript_1 = FALSE;
	m_IsScript_10 = FALSE;
	m_IsScript_11 = FALSE;
	m_IsScript_12 = FALSE;
	m_IsScript_13 = FALSE;
	m_IsScript_14 = FALSE;
	m_IsScript_15 = FALSE;
	m_IsScript_16 = FALSE;
	m_IsScript_17 = FALSE;
	m_IsScript_18 = FALSE;
	m_IsScript_19 = FALSE;
	m_IsScript_2 = FALSE;
	m_IsScript_20 = FALSE;
	m_IsScript_3 = FALSE;
	m_IsScript_4 = FALSE;
	m_IsScript_5 = FALSE;
	m_IsScript_6 = FALSE;
	m_IsScript_7 = FALSE;
	m_IsScript_8 = FALSE;
	m_IsScript_9 = FALSE;
	//}}AFX_DATA_INIT
}


void CCommandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommandDlg)
	DDX_Text(pDX, IDC_EDNAME_1, m_strName_1);
	DDX_Text(pDX, IDC_EDNAME_3, m_strName_3);
	DDX_Text(pDX, IDC_EDNAME_4, m_strName_4);
	DDX_Text(pDX, IDC_EDNAME_5, m_strName_5);
	DDX_Text(pDX, IDC_EDNAME_6, m_strName_6);
	DDX_Text(pDX, IDC_EDNAME_7, m_strName_7);
	DDX_Text(pDX, IDC_EDNAME_8, m_strName_8);
	DDX_Text(pDX, IDC_EDNAME_9, m_strName_9);
	DDX_Text(pDX, IDC_EDNAME_10, m_strName_10);
	DDX_Text(pDX, IDC_EDNAME_11, m_strName_11);
	DDX_Text(pDX, IDC_EDNAME_12, m_strName_12);
	DDX_Text(pDX, IDC_EDNAME_13, m_strName_13);
	DDX_Text(pDX, IDC_EDNAME_14, m_strName_14);
	DDX_Text(pDX, IDC_EDNAME_15, m_strName_15);
	DDX_Text(pDX, IDC_EDNAME_16, m_strName_16);
	DDX_Text(pDX, IDC_EDNAME_17, m_strName_17);
	DDX_Text(pDX, IDC_EDNAME_18, m_strName_18);
	DDX_Text(pDX, IDC_EDNAME_19, m_strName_19);
	DDX_Text(pDX, IDC_EDNAME_2, m_strName_2);
	DDX_Text(pDX, IDC_EDNAME_20, m_strName_20);

	DDX_Text(pDX, IDC_EDCOMMAND_1, m_strCommand_1);
	DDX_Text(pDX, IDC_EDCOMMAND_2, m_strCommand_2);
	DDX_Text(pDX, IDC_EDCOMMAND_3, m_strCommand_3);
	DDX_Text(pDX, IDC_EDCOMMAND_4, m_strCommand_4);
	DDX_Text(pDX, IDC_EDCOMMAND_5, m_strCommand_5);
	DDX_Text(pDX, IDC_EDCOMMAND_6, m_strCommand_6);
	DDX_Text(pDX, IDC_EDCOMMAND_7, m_strCommand_7);
	DDX_Text(pDX, IDC_EDCOMMAND_8, m_strCommand_8);
	DDX_Text(pDX, IDC_EDCOMMAND_9, m_strCommand_9);
	DDX_Text(pDX, IDC_EDCOMMAND_10, m_strCommand_10);
	DDX_Text(pDX, IDC_EDCOMMAND_11, m_strCommand_11);
	DDX_Text(pDX, IDC_EDCOMMAND_12, m_strCommand_12);
	DDX_Text(pDX, IDC_EDCOMMAND_13, m_strCommand_13);
	DDX_Text(pDX, IDC_EDCOMMAND_14, m_strCommand_14);
	DDX_Text(pDX, IDC_EDCOMMAND_15, m_strCommand_15);
	DDX_Text(pDX, IDC_EDCOMMAND_16, m_strCommand_16);
	DDX_Text(pDX, IDC_EDCOMMAND_17, m_strCommand_17);
	DDX_Text(pDX, IDC_EDCOMMAND_18, m_strCommand_18);
	DDX_Text(pDX, IDC_EDCOMMAND_19, m_strCommand_19);
	DDX_Text(pDX, IDC_EDCOMMAND_20, m_strCommand_20);
	
	DDX_Check(pDX, IDC_CHHEX_1, m_IsHex_1);
	DDX_Check(pDX, IDC_CHHEX_3, m_IsHex_3);
	DDX_Check(pDX, IDC_CHHEX_4, m_IsHex_4);
	DDX_Check(pDX, IDC_CHHEX_5, m_IsHex_5);
	DDX_Check(pDX, IDC_CHHEX_6, m_IsHex_6);
	DDX_Check(pDX, IDC_CHHEX_7, m_IsHex_7);
	DDX_Check(pDX, IDC_CHHEX_8, m_IsHex_8);
	DDX_Check(pDX, IDC_CHHEX_9, m_IsHex_9);
	DDX_Check(pDX, IDC_CHHEX_10, m_IsHex_10);
	DDX_Check(pDX, IDC_CHHEX_11, m_IsHex_11);
	DDX_Check(pDX, IDC_CHHEX_12, m_IsHex_12);
	DDX_Check(pDX, IDC_CHHEX_13, m_IsHex_13);
	DDX_Check(pDX, IDC_CHHEX_14, m_IsHex_14);
	DDX_Check(pDX, IDC_CHHEX_15, m_IsHex_15);
	DDX_Check(pDX, IDC_CHHEX_16, m_IsHex_16);
	DDX_Check(pDX, IDC_CHHEX_17, m_IsHex_17);
	DDX_Check(pDX, IDC_CHHEX_18, m_IsHex_18);
	DDX_Check(pDX, IDC_CHHEX_19, m_IsHex_19);
	DDX_Check(pDX, IDC_CHHEX_2, m_IsHex_2);
	DDX_Check(pDX, IDC_CHHEX_20, m_IsHex_20);

	DDX_Check(pDX, IDC_CHSCRIPT_1, m_IsScript_1);
	DDX_Check(pDX, IDC_CHSCRIPT_2, m_IsScript_2);
	DDX_Check(pDX, IDC_CHSCRIPT_3, m_IsScript_3);
	DDX_Check(pDX, IDC_CHSCRIPT_4, m_IsScript_4);
	DDX_Check(pDX, IDC_CHSCRIPT_5, m_IsScript_5);
	DDX_Check(pDX, IDC_CHSCRIPT_6, m_IsScript_6);
	DDX_Check(pDX, IDC_CHSCRIPT_7, m_IsScript_7);
	DDX_Check(pDX, IDC_CHSCRIPT_8, m_IsScript_8);
	DDX_Check(pDX, IDC_CHSCRIPT_9, m_IsScript_9);
	DDX_Check(pDX, IDC_CHSCRIPT_10, m_IsScript_10);
	DDX_Check(pDX, IDC_CHSCRIPT_11, m_IsScript_11);
	DDX_Check(pDX, IDC_CHSCRIPT_12, m_IsScript_12);
	DDX_Check(pDX, IDC_CHSCRIPT_13, m_IsScript_13);
	DDX_Check(pDX, IDC_CHSCRIPT_14, m_IsScript_14);
	DDX_Check(pDX, IDC_CHSCRIPT_15, m_IsScript_15);
	DDX_Check(pDX, IDC_CHSCRIPT_16, m_IsScript_16);
	DDX_Check(pDX, IDC_CHSCRIPT_17, m_IsScript_17);
	DDX_Check(pDX, IDC_CHSCRIPT_18, m_IsScript_18);
	DDX_Check(pDX, IDC_CHSCRIPT_19, m_IsScript_19);
	DDX_Check(pDX, IDC_CHSCRIPT_20, m_IsScript_20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommandDlg, CDialog)
	//{{AFX_MSG_MAP(CCommandDlg)
	ON_BN_CLICKED(IDC_BTSCRIPTHELP, OnBtscripthelp)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON2, IDC_BUTTON21, OnBtSendCmd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommandDlg message handlers

void CCommandDlg::OnBtscripthelp() 
{
	// TODO: Add your control notification handler code here
	CScriptHelpDlg dlg;
	dlg.DoModal();
}


void CCommandDlg::OnBtSendCmd(UINT nID) 
{
	static UINT idHexCh[] = {IDC_CHHEX_1, IDC_CHHEX_2, IDC_CHHEX_3, IDC_CHHEX_4, IDC_CHHEX_5, 
		IDC_CHHEX_6, IDC_CHHEX_7, IDC_CHHEX_8, IDC_CHHEX_9, IDC_CHHEX_10, 
		IDC_CHHEX_11, IDC_CHHEX_12, IDC_CHHEX_13, IDC_CHHEX_14, IDC_CHHEX_15, 
		IDC_CHHEX_16, IDC_CHHEX_17, IDC_CHHEX_18, IDC_CHHEX_19, IDC_CHHEX_20};
	static UINT idScriptCh[] = {
		IDC_CHSCRIPT_1, IDC_CHSCRIPT_2, IDC_CHSCRIPT_3, IDC_CHSCRIPT_4, IDC_CHSCRIPT_5, 
		IDC_CHSCRIPT_6, IDC_CHSCRIPT_7, IDC_CHSCRIPT_8, IDC_CHSCRIPT_9, IDC_CHSCRIPT_10, 
		IDC_CHSCRIPT_11, IDC_CHSCRIPT_12, IDC_CHSCRIPT_13, IDC_CHSCRIPT_14, IDC_CHSCRIPT_15, 
		IDC_CHSCRIPT_16, IDC_CHSCRIPT_17, IDC_CHSCRIPT_18, IDC_CHSCRIPT_19, IDC_CHSCRIPT_20};
	static UINT idCommandEd[] = {IDC_EDCOMMAND_1, IDC_EDCOMMAND_2, IDC_EDCOMMAND_3, IDC_EDCOMMAND_4, 
		IDC_EDCOMMAND_5, IDC_EDCOMMAND_6, IDC_EDCOMMAND_7, IDC_EDCOMMAND_8, IDC_EDCOMMAND_9, 
		IDC_EDCOMMAND_10, IDC_EDCOMMAND_11, IDC_EDCOMMAND_12, IDC_EDCOMMAND_13, IDC_EDCOMMAND_14, 
		IDC_EDCOMMAND_15, IDC_EDCOMMAND_16, IDC_EDCOMMAND_17, IDC_EDCOMMAND_18, IDC_EDCOMMAND_19, 
		IDC_EDCOMMAND_20};
	static UINT idNameEd[] = {IDC_EDNAME_1, IDC_EDNAME_2, IDC_EDNAME_3, IDC_EDNAME_4, IDC_EDNAME_5, 
		IDC_EDNAME_6, IDC_EDNAME_7, IDC_EDNAME_8, IDC_EDNAME_9, IDC_EDNAME_10, IDC_EDNAME_11, 
		IDC_EDNAME_12, IDC_EDNAME_13, IDC_EDNAME_14, IDC_EDNAME_15, IDC_EDNAME_16, IDC_EDNAME_17, 
		IDC_EDNAME_18, IDC_EDNAME_19, IDC_EDNAME_20};

	CMainFrame *frame = (CMainFrame *)win;
	CMyCommDoc   *Doc   =  (CMyCommDoc   *)(frame->GetActiveDocument());
	CMyCommView *myView = (CMyCommView *)(frame->GetActiveView());

	int myindex;
	myindex = nID - IDC_BUTTON2;
	if (myindex>=0 && myindex < COMMANDCOUNT)
	{
		CString name;
		CString command;
		GetDlgItem(idNameEd[myindex])->GetWindowText(name);
		GetDlgItem(idCommandEd[myindex])->GetWindowText(command);

		BOOL hex = ((CButton *)GetDlgItem(idHexCh[myindex]))->GetCheck();
		BOOL script = ((CButton *)GetDlgItem(idScriptCh[myindex]))->GetCheck();

		Doc->m_Command[myindex].m_strName = name;
		Doc->m_Command[myindex].m_strCommand = command;
		Doc->m_Command[myindex].m_IsHex = hex;
		Doc->m_Command[myindex].m_isScript = script;

		myView->m_strSendData = command;
		myView->m_ctrlSendHex.SetCheck(hex);
		myView->m_ctrlSendScript.SetCheck(script);
		
		myView->UpdateData(FALSE);

		if (!Doc->m_ComAction) 
		{
			return;
		}
		
		int i;

		
		if(script)
		{
			CString mycommand;
			CString myscript;
			char myc;
			mycommand.Empty();
			myscript = command;
			for(i=0;i<myscript.GetLength();i++)
			{
				myc = myscript[i];
				if (myc==';')
				{
					myView->DoRunScript(mycommand);
					mycommand.Empty();
				}	
				else{
					if ((myc != '\n') && (myc != '\r')) {mycommand += myc;}
				}
				
			}
				 
		}
		else if(hex)
		{
			char data[512];
			int len = myView->DoStr2Hex(command, data);
			Doc->m_Comm.WriteToPort(data,len);
			Doc->m_TXCount += len;
			CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
			CString str;
			str.Format("TX:%d", Doc->m_TXCount);
			myApp->DoSetStautsBarText(SBSTX,str);
		}
		else 
		{
			Doc->m_Comm.WriteToPort((LPCTSTR)command);	//·¢ËÍÊý¾Ý
			Doc->m_TXCount += command.GetLength();
			CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
			CString str;
			str.Format("TX:%d", Doc->m_TXCount);
			myApp->DoSetStautsBarText(SBSTX,str);
		}
		
		CommCommand myCommand;
		myCommand.m_IsHex = hex;
		myCommand.m_isScript = script;
		myCommand.m_strCommand = command;
		myView->m_CurrenthistoryIndex = Doc->AddHistory(myCommand);
	}
}
