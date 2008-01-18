// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyComm.h"
#include "MainFrm.h"
#include "ScriptHelpDlg.h"

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
	ON_COMMAND(IDC_LANGCHINESE, OnLangchinese)
	ON_COMMAND(ID_HELP_SCRIPT, OnHelpScript)
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

void CMainFrame::OnLangchinese() 
{
	// TODO: Add your command handler code here
	//	
}


void CMainFrame::OnHelpScript() 
{
	// TODO: Add your command handler code here
	CScriptHelpDlg dlg;
	dlg.DoModal();
}
