// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyComm.h"
#include "MainFrm.h"
#include "ScriptHelpDlg.h"
#include "MyCommView.h"
#include "afxinet.h"
#include "UpgradeDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_COMMAND, OnEditCommand)
	ON_COMMAND(ID_EDIT_PROTOCOL, OnEditProtocol)
	ON_COMMAND(ID_HELP_SCRIPT, OnHelpScript)
	ON_COMMAND(ID_APP_SNEDMAIL, OnAppSnedmail)
	ON_COMMAND(ID_APP_UPGRADE, OnAppUpgrade)
	ON_COMMAND(ID_APP_HOME, OnAppHome)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_STATUSBAR_TX,
	ID_STATUSBAR_RX,
	ID_STATUSBAR_COMM,
	ID_STATUSBAR_SENDKEY,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_firstShow = FALSE;
	m_language = LACHINA;
	
}

CMainFrame::~CMainFrame()
{
}


BOOL IsFileExist( CString strFileName )  
{  
	WIN32_FIND_DATA   FindFileData;  
	HANDLE   hFind;  
	//   �жϲ����ļ��Ƿ����  
	hFind=FindFirstFile(   (LPCTSTR)strFileName,   &FindFileData   );  
	if (hFind==INVALID_HANDLE_VALUE)  
		return   FALSE;  
	return   TRUE;  
}

void ThreadCheckVersion()
{
	//app dir
	CString myAppDir;
	CMyCommApp *myApp = (CMyCommApp *)AfxGetApp();
	CMainFrame * myMain = (CMainFrame *) myApp->GetMainWnd();
	CStdioFile myfile;
	myAppDir = myApp->m_AppDir;
	CString vertext = myAppDir + "\\version";
	if(!myfile.Open(vertext,CFile::modeRead))
	{
		
		CString myver;
		char s[256];
		_tcscpy(s,vertext.GetBuffer(vertext.GetLength())) ;
		myMain->DonwLoadFile("http://lsdcomm.googlecode.com/svn/trunk/lsdcomm/version/ver.txt",
			s);
		return;
	}
	else{
	   CString myverion;
	   myfile.ReadString(myverion); //line:1
	   myverion.TrimLeft();  myverion.TrimRight();
       if (atof(myApp->m_AppVersion)<atof(myverion))
	   {
			//new version
			CMyCommView * myview = (CMyCommView *) myMain->GetActiveView();
			myview->m_EditLogger.AddText(vertext+"\r\n");
			myview->m_EditLogger.AddText(myverion+"\r\n");
			myview->m_EditLogger.AddText(myApp->m_AppVersion+"\r\n");
			myview->m_EditLogger.AddText(">>44���°汾:"+myverion+"\r\n");
			CString strLine;
			myfile.ReadString(strLine); // downfilename line:2
			myApp->m_downfileexefilename = strLine;
			myfile.ReadString(strLine); //line:3
			myview->m_EditLogger.AddText(">>"+strLine +"\r\n");
			myview->m_EditLogger.AddText(">>����������˵���[����]->[��������]\r\n");

			myfile.Close();
	   }
	   else{
		   
		   char s[256];
		   _tcscpy(s,vertext.GetBuffer(vertext.GetLength())) ;
		   myMain->DonwLoadFile("http://lsdcomm.googlecode.com/svn/trunk/lsdcomm/version/ver.txt",
			   s);
		   myfile.Close();
		   return;
	   }
	}
	
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	CRect rect;
	GetClientRect(&rect);
	m_wndStatusBar.SetPaneInfo(SBSINFO,ID_SEPARATOR,SBPS_STRETCH,0);      
	m_wndStatusBar.SetPaneInfo(SBSTX,ID_STATUSBAR_TX ,SBPS_NORMAL,60); 
	m_wndStatusBar.SetPaneInfo(SBSRX,ID_STATUSBAR_RX ,SBPS_NORMAL,60); 
	m_wndStatusBar.SetPaneInfo(SBSCOMM,ID_STATUSBAR_COMM ,SBPS_NORMAL,40); 
	m_wndStatusBar.SetPaneInfo(SBSSENDKEY,ID_STATUSBAR_SENDKEY ,SBPS_NORMAL,10); 

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::ActivateFrame(int nCmdShow) 
{
	
	// TODO: Add your specialized code here and/or call the base class

	if (!m_firstShow)
	{
		
		WINDOWPLACEMENT   WndStatus;  
		CRect   rect;  
		rect.left     = AfxGetApp()->GetProfileInt("Layout","LEFT",100);  
		rect.top      = AfxGetApp()->GetProfileInt("Layout","TOP",100);  
		rect.right    = AfxGetApp()->GetProfileInt("Layout","RIGHT",800);  
		rect.bottom   = AfxGetApp()->GetProfileInt("Layout","BOTTOM",600);  
		WndStatus.rcNormalPosition   =   rect;  
		WndStatus.flags=   AfxGetApp()->GetProfileInt("Layout","FLAG",0);  
		nCmdShow   =   AfxGetApp()->GetProfileInt("Layout","SHOWCMD",SW_SHOW);  
		WndStatus.showCmd   =   nCmdShow;  
		WndStatus.ptMinPosition   =   CPoint(0,0);  
		SetWindowPlacement(&WndStatus); 


		//check version
		
		hThread=CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)ThreadCheckVersion,
			NULL,
			0,
			&ThreadID);
		
        
		m_firstShow = TRUE;
	}
	

	CFrameWnd::ActivateFrame(nCmdShow);
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	WINDOWPLACEMENT   WndStatus;  
	GetWindowPlacement(&WndStatus);  
	AfxGetApp()->WriteProfileInt("Layout","FLAG",WndStatus.flags);  
	AfxGetApp()->WriteProfileInt("Layout","SHOWCMD",WndStatus.showCmd);  
	AfxGetApp()->WriteProfileInt("Layout","LEFT",WndStatus.rcNormalPosition.left);  
	AfxGetApp()->WriteProfileInt("Layout","RIGHT",WndStatus.rcNormalPosition.right);  
	AfxGetApp()->WriteProfileInt("Layout","TOP",WndStatus.rcNormalPosition.top);  
	AfxGetApp()->WriteProfileInt("Layout","BOTTOM",WndStatus.rcNormalPosition.bottom); 
	
	CFrameWnd::OnClose();
}

void CMainFrame::OnEditCommand() 
{
	// TODO: Add your command handler code here
	CCommandDlg dlg;
	CMyCommDoc   *Doc   =  (CMyCommDoc   *)GetActiveDocument();
	dlg.m_strName_1    = Doc->m_Command[0].m_strName;
	dlg.m_strCommand_1 = Doc->m_Command[0].m_strCommand;
	dlg.m_IsHex_1      = Doc->m_Command[0].m_IsHex;
	dlg.m_IsScript_1   = Doc->m_Command[0].m_isScript;
	
	dlg.m_strName_2    = Doc->m_Command[1].m_strName;
	dlg.m_strCommand_2 = Doc->m_Command[1].m_strCommand;
	dlg.m_IsHex_2      = Doc->m_Command[1].m_IsHex;
	dlg.m_IsScript_2   = Doc->m_Command[1].m_isScript;

	dlg.m_strName_3    = Doc->m_Command[2].m_strName;
	dlg.m_strCommand_3 = Doc->m_Command[2].m_strCommand;
	dlg.m_IsHex_3      = Doc->m_Command[2].m_IsHex;
	dlg.m_IsScript_3   = Doc->m_Command[2].m_isScript;

	dlg.m_strName_4    = Doc->m_Command[3].m_strName;
	dlg.m_strCommand_4 = Doc->m_Command[3].m_strCommand;
	dlg.m_IsHex_4      = Doc->m_Command[3].m_IsHex;
	dlg.m_IsScript_4   = Doc->m_Command[3].m_isScript;

	dlg.m_strName_5    = Doc->m_Command[4].m_strName;
	dlg.m_strCommand_5 = Doc->m_Command[4].m_strCommand;
	dlg.m_IsHex_5      = Doc->m_Command[4].m_IsHex;
	dlg.m_IsScript_5   = Doc->m_Command[4].m_isScript;

	dlg.m_strName_6    = Doc->m_Command[5].m_strName;
	dlg.m_strCommand_6 = Doc->m_Command[5].m_strCommand;
	dlg.m_IsHex_6      = Doc->m_Command[5].m_IsHex;
	dlg.m_IsScript_6   = Doc->m_Command[5].m_isScript;
	
	dlg.m_strName_7    = Doc->m_Command[6].m_strName;
	dlg.m_strCommand_7 = Doc->m_Command[6].m_strCommand;
	dlg.m_IsHex_7      = Doc->m_Command[6].m_IsHex;
	dlg.m_IsScript_7   = Doc->m_Command[6].m_isScript;
	
	dlg.m_strName_8    = Doc->m_Command[7].m_strName;
	dlg.m_strCommand_8 = Doc->m_Command[7].m_strCommand;
	dlg.m_IsHex_8      = Doc->m_Command[7].m_IsHex;
	dlg.m_IsScript_8   = Doc->m_Command[7].m_isScript;
	
	dlg.m_strName_9    = Doc->m_Command[8].m_strName;
	dlg.m_strCommand_9 = Doc->m_Command[8].m_strCommand;
	dlg.m_IsHex_9      = Doc->m_Command[8].m_IsHex;
	dlg.m_IsScript_9   = Doc->m_Command[8].m_isScript;

	dlg.m_strName_10    = Doc->m_Command[9].m_strName;
	dlg.m_strCommand_10 = Doc->m_Command[9].m_strCommand;
	dlg.m_IsHex_10      = Doc->m_Command[9].m_IsHex;
	dlg.m_IsScript_10   = Doc->m_Command[9].m_isScript;

	dlg.m_strName_11    = Doc->m_Command[10].m_strName;
	dlg.m_strCommand_11 = Doc->m_Command[10].m_strCommand;
	dlg.m_IsHex_11      = Doc->m_Command[10].m_IsHex;
	dlg.m_IsScript_11   = Doc->m_Command[10].m_isScript;

	dlg.m_strName_12    = Doc->m_Command[11].m_strName;
	dlg.m_strCommand_12 = Doc->m_Command[11].m_strCommand;
	dlg.m_IsHex_12      = Doc->m_Command[11].m_IsHex;
	dlg.m_IsScript_12   = Doc->m_Command[11].m_isScript;
	
	dlg.m_strName_13    = Doc->m_Command[12].m_strName;
	dlg.m_strCommand_13 = Doc->m_Command[12].m_strCommand;
	dlg.m_IsHex_13      = Doc->m_Command[12].m_IsHex;
	dlg.m_IsScript_13   = Doc->m_Command[12].m_isScript;


	dlg.m_strName_14    = Doc->m_Command[13].m_strName;
	dlg.m_strCommand_14 = Doc->m_Command[13].m_strCommand;
	dlg.m_IsHex_14      = Doc->m_Command[13].m_IsHex;
	dlg.m_IsScript_14   = Doc->m_Command[13].m_isScript;

	dlg.m_strName_15    = Doc->m_Command[14].m_strName;
	dlg.m_strCommand_15 = Doc->m_Command[14].m_strCommand;
	dlg.m_IsHex_15      = Doc->m_Command[14].m_IsHex;
	dlg.m_IsScript_15   = Doc->m_Command[14].m_isScript;

	dlg.m_strName_16    = Doc->m_Command[15].m_strName;
	dlg.m_strCommand_16 = Doc->m_Command[15].m_strCommand;
	dlg.m_IsHex_16      = Doc->m_Command[15].m_IsHex;
	dlg.m_IsScript_16   = Doc->m_Command[15].m_isScript;

	dlg.m_strName_17    = Doc->m_Command[16].m_strName;
	dlg.m_strCommand_17 = Doc->m_Command[16].m_strCommand;
	dlg.m_IsHex_17      = Doc->m_Command[16].m_IsHex;
	dlg.m_IsScript_17   = Doc->m_Command[16].m_isScript;

	dlg.m_strName_18    = Doc->m_Command[17].m_strName;
	dlg.m_strCommand_18 = Doc->m_Command[17].m_strCommand;
	dlg.m_IsHex_18      = Doc->m_Command[17].m_IsHex;
	dlg.m_IsScript_18   = Doc->m_Command[17].m_isScript;

	dlg.m_strName_19    = Doc->m_Command[18].m_strName;
	dlg.m_strCommand_19 = Doc->m_Command[18].m_strCommand;
	dlg.m_IsHex_19      = Doc->m_Command[18].m_IsHex;
	dlg.m_IsScript_19   = Doc->m_Command[18].m_isScript;

	dlg.m_strName_20    = Doc->m_Command[19].m_strName;
	dlg.m_strCommand_20 = Doc->m_Command[19].m_strCommand;
	dlg.m_IsHex_20      = Doc->m_Command[19].m_IsHex;
	dlg.m_IsScript_20   = Doc->m_Command[19].m_isScript;

    UpdateData(FALSE);
	if (dlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		Doc->m_Command[0].m_strName    = dlg.m_strName_1;
		Doc->m_Command[0].m_strCommand = dlg.m_strCommand_1;
		Doc->m_Command[0].m_IsHex = dlg.m_IsHex_1;
		Doc->m_Command[0].m_isScript = dlg.m_IsScript_1;

		Doc->m_Command[1].m_strName    = dlg.m_strName_2;
		Doc->m_Command[1].m_strCommand = dlg.m_strCommand_2;
		Doc->m_Command[1].m_IsHex = dlg.m_IsHex_2;
		Doc->m_Command[1].m_isScript = dlg.m_IsScript_2;

		Doc->m_Command[2].m_strName    = dlg.m_strName_3;
		Doc->m_Command[2].m_strCommand = dlg.m_strCommand_3;
		Doc->m_Command[2].m_IsHex = dlg.m_IsHex_3;
		Doc->m_Command[2].m_isScript = dlg.m_IsScript_3;

		Doc->m_Command[3].m_strName    = dlg.m_strName_4;
		Doc->m_Command[3].m_strCommand = dlg.m_strCommand_4;
		Doc->m_Command[3].m_IsHex = dlg.m_IsHex_4;
		Doc->m_Command[3].m_isScript = dlg.m_IsScript_4;

		Doc->m_Command[4].m_strName    = dlg.m_strName_5;
		Doc->m_Command[4].m_strCommand = dlg.m_strCommand_5;
		Doc->m_Command[4].m_IsHex = dlg.m_IsHex_5;
		Doc->m_Command[4].m_isScript = dlg.m_IsScript_5;

		Doc->m_Command[5].m_strName    = dlg.m_strName_6;
		Doc->m_Command[5].m_strCommand = dlg.m_strCommand_6;
		Doc->m_Command[5].m_IsHex = dlg.m_IsHex_6;
		Doc->m_Command[5].m_isScript = dlg.m_IsScript_6;

		Doc->m_Command[6].m_strName    = dlg.m_strName_7;
		Doc->m_Command[6].m_strCommand = dlg.m_strCommand_7;
		Doc->m_Command[6].m_IsHex = dlg.m_IsHex_7;
		Doc->m_Command[6].m_isScript = dlg.m_IsScript_7;

		Doc->m_Command[7].m_strName    = dlg.m_strName_8;
		Doc->m_Command[7].m_strCommand = dlg.m_strCommand_8;
		Doc->m_Command[7].m_IsHex = dlg.m_IsHex_8;
		Doc->m_Command[7].m_isScript = dlg.m_IsScript_8;

		Doc->m_Command[8].m_strName    = dlg.m_strName_9;
		Doc->m_Command[8].m_strCommand = dlg.m_strCommand_9;
		Doc->m_Command[8].m_IsHex = dlg.m_IsHex_9;
		Doc->m_Command[8].m_isScript = dlg.m_IsScript_9;

		Doc->m_Command[9].m_strName    = dlg.m_strName_10;
		Doc->m_Command[9].m_strCommand = dlg.m_strCommand_10;
		Doc->m_Command[9].m_IsHex = dlg.m_IsHex_10;
		Doc->m_Command[9].m_isScript = dlg.m_IsScript_10;

		Doc->m_Command[10].m_strName    = dlg.m_strName_11;
		Doc->m_Command[10].m_strCommand = dlg.m_strCommand_11;
		Doc->m_Command[10].m_IsHex = dlg.m_IsHex_11;
		Doc->m_Command[10].m_isScript = dlg.m_IsScript_11;

		Doc->m_Command[11].m_strName    = dlg.m_strName_12;
		Doc->m_Command[11].m_strCommand = dlg.m_strCommand_12;
		Doc->m_Command[11].m_IsHex = dlg.m_IsHex_12;
		Doc->m_Command[11].m_isScript = dlg.m_IsScript_12;

		Doc->m_Command[12].m_strName    = dlg.m_strName_13;
		Doc->m_Command[12].m_strCommand = dlg.m_strCommand_13;
		Doc->m_Command[12].m_IsHex = dlg.m_IsHex_13;
		Doc->m_Command[12].m_isScript = dlg.m_IsScript_13;

		Doc->m_Command[13].m_strName    = dlg.m_strName_14;
		Doc->m_Command[13].m_strCommand = dlg.m_strCommand_14;
		Doc->m_Command[13].m_IsHex = dlg.m_IsHex_14;
		Doc->m_Command[13].m_isScript = dlg.m_IsScript_14;

		Doc->m_Command[14].m_strName    = dlg.m_strName_15;
		Doc->m_Command[14].m_strCommand = dlg.m_strCommand_15;
		Doc->m_Command[14].m_IsHex = dlg.m_IsHex_15;
		Doc->m_Command[14].m_isScript = dlg.m_IsScript_15;

		Doc->m_Command[15].m_strName    = dlg.m_strName_16;
		Doc->m_Command[15].m_strCommand = dlg.m_strCommand_16;
		Doc->m_Command[15].m_IsHex = dlg.m_IsHex_16;
		Doc->m_Command[15].m_isScript = dlg.m_IsScript_16;

		Doc->m_Command[16].m_strName    = dlg.m_strName_17;
		Doc->m_Command[16].m_strCommand = dlg.m_strCommand_17;
		Doc->m_Command[16].m_IsHex = dlg.m_IsHex_17;
		Doc->m_Command[16].m_isScript = dlg.m_IsScript_17;

		Doc->m_Command[17].m_strName    = dlg.m_strName_18;
		Doc->m_Command[17].m_strCommand = dlg.m_strCommand_18;
		Doc->m_Command[17].m_IsHex = dlg.m_IsHex_18;

		Doc->m_Command[18].m_strName    = dlg.m_strName_19;
		Doc->m_Command[18].m_strCommand = dlg.m_strCommand_19;
		Doc->m_Command[18].m_IsHex = dlg.m_IsHex_19;
		Doc->m_Command[18].m_isScript = dlg.m_IsScript_19;

		Doc->m_Command[19].m_strName    = dlg.m_strName_20;
		Doc->m_Command[19].m_strCommand = dlg.m_strCommand_20;
		Doc->m_Command[19].m_IsHex = dlg.m_IsHex_20;
		Doc->m_Command[19].m_isScript = dlg.m_IsScript_20;

		//command combox
		CMyCommView * myView = (CMyCommView *)  this->GetActiveView();
		CString myCommandStr;
		myView->m_ctrlCommand.ResetContent();
		for(int i=0 ;i<COMMANDCOUNT ;i++)
		{
			if (!Doc->m_Command[i].m_strName.IsEmpty())
			{
				myCommandStr.Format("%d %s",i+1,Doc->m_Command[i].m_strName);
				myView->m_ctrlCommand.AddString(myCommandStr);
			}
		}
		
	
	}
}


void CMainFrame::OnEditProtocol() 
{
	CMyCommDoc   *Doc   =  (CMyCommDoc   *)GetActiveDocument();
	CProtocolEditDlg dlg;
	dlg.m_Edit = Doc->m_strProtocol;
	if(dlg.DoModal()==IDOK)
	{
		Doc->m_strProtocol = dlg.m_Edit;
	}	
}

void CMainFrame::OnHelpScript() 
{
	// TODO: Add your command handler code here
	CScriptHelpDlg dlg;
	dlg.DoModal();
}

void CMainFrame::OnAppSnedmail() 
{
	// TODO: Add your command handler code here

	ShellExecute(NULL,NULL,"mailto:mrlong.com@gmail.com",NULL,NULL,SW_SHOW);
}

void CMainFrame::OnAppUpgrade() 
{
	// TODO: Add your command handler code here
	
	CString myStr;
	BOOL myhasUpgrade = FALSE;
	CMyCommApp *myApp = (CMyCommApp *)AfxGetApp();
	CMainFrame * myMain = (CMainFrame *) myApp->GetMainWnd();
	CStdioFile myfile;
	CString vertext = myApp->m_AppDir + "\\version";
	if (!IsFileExist(vertext))
	{
		char s[256];
		_tcscpy(s,vertext.GetBuffer(vertext.GetLength())) ;
		if(!DonwLoadFile("http://lsdcomm.googlecode.com/svn/trunk/lsdcomm/version/ver.txt",s))
		{
			AfxMessageBox(_T("�޷����ӷ�������"));
			return;
		}
	};
	
	if(!myfile.Open(vertext,CFile::modeRead))
	{
		AfxMessageBox(_T("�������ļ�����"));
		return;
	}
	else{

		CString myverion;
		myfile.ReadString(myverion); //line:1
		myverion.TrimLeft();  myverion.TrimRight();
		if (atof(myApp->m_AppVersion)<atof(myverion))
		{
			//new version
			myhasUpgrade = TRUE;
			CMyCommView * myview = (CMyCommView *) myMain->GetActiveView();
			myStr = "���°汾:"+myverion+"\r\n";
			CString strLine;
			myfile.ReadString(strLine); // downfilename line:2
			myApp->m_downfileexefilename = strLine;
			while(myfile.ReadString(strLine))
			{
				if(strLine.GetLength()>2)
					if ((strLine[0] == '>') && (strLine[1]=='>'))
						myStr += strLine+"\r\n";
			} 
		}
		else{
			myStr = myApp->m_AppVersion + "�汾����������";
		}
		
	}
	myfile.Close();

	CUpgradeDlg dlg;
	dlg.m_strData = myStr;
	dlg.m_strdownfile  = myApp->m_downfileexefilename;
	dlg.m_StrLocalfile = myApp->m_AppDir + "\\exe";
	dlg.m_IsUpgrade = myhasUpgrade;
	if((dlg.DoModal()==IDOK) && myhasUpgrade)
	{
		if(!IsFileExist(myApp->m_AppDir + "\\exe"))	return;
		CStdioFile batfile;
		CString mybatFile;
		mybatFile = myApp->m_AppDir+"\\update.bat";
		if(!batfile.Open(mybatFile,CStdioFile::modeReadWrite|CStdioFile::modeCreate)) 
			return;
		
		batfile.WriteString("@echo off\n\r");
		CString myexename;
		myexename = myApp->m_AppDir + "\\MyComm.exe";
		batfile.WriteString("del "+ myexename + "\n\r");
		batfile.WriteString("if exist "+myexename+" goto loop" + "\n\r");
		batfile.WriteString("copy "+ myApp->m_AppDir + "\\exe" + " " + myexename + "\n\r");
		batfile.WriteString("del "+myApp->m_AppDir + "\\exe" + "\n\r");
		batfile.WriteString(myexename+"\n\r");
		batfile.WriteString("del "+mybatFile+"\n\r");
		batfile.Close();

		ShellExecute(NULL,NULL,mybatFile,NULL,NULL,SW_HIDE);
		CFrameWnd::OnClose();
	};

}

BOOL CMainFrame::DonwLoadFile(PSTR pURL, LPSTR SaveAsFilePath)
{
	CInternetSession session; 
	CHttpConnection* pServer = NULL; 
	CHttpFile * pHttpFile = NULL;
	CString strServerName;  //ȥ��http://
	CString strObject;  
	INTERNET_PORT nPort;
	DWORD dwServiceType; 
	DWORD dwHttpRequestFlags = INTERNET_FLAG_NO_AUTO_REDIRECT; //�����־
	const TCHAR szHeaders[]=_T("Accept: text/*\r\nUser-Agent:HttpClient\r\n");
	
	BOOL OK=AfxParseURL( 
		pURL, 
		dwServiceType, 
		strServerName, 
		strObject, 
		nPort ); 
	
	pServer = session.GetHttpConnection(strServerName, nPort); //��÷�������
	
	pHttpFile = pServer-> OpenRequest( CHttpConnection::HTTP_VERB_GET,
		strObject,
		NULL, 
		1, 
		NULL, 
		NULL,
		dwHttpRequestFlags);
	
	pHttpFile->AddRequestHeaders(szHeaders);
	pHttpFile->SendRequest(); //��������
	CStdioFile f; 
	if( !f.Open( SaveAsFilePath, 
		CFile::modeCreate | CFile::modeWrite | CFile::typeBinary ) )
	{ 
		return false;
	}
	
	TCHAR szBuf[1024];
	int length=0;
	long a=pHttpFile->GetLength();
	while (length=pHttpFile->Read(szBuf, 1023))
		f.Write(szBuf,length);
	f.Close();
	pHttpFile ->Close();
	pServer ->Close();
	if (pHttpFile != NULL) delete pHttpFile;
	if (pServer != NULL) delete pServer;
	session.Close();
	return true;
}

void CMainFrame::OnAppHome() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL,NULL,"Http://lsdcomm.googlecode.com",NULL,NULL,SW_SHOW);
}
