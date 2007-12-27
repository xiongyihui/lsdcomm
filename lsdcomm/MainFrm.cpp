// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MainFrm.h"

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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_firstShow = FALSE;
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
		rect.left     = AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","LEFT",100);  
		rect.top      = AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","TOP",100);  
		rect.right    = AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","RIGHT",500);  
		rect.bottom   = AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","BOTTOM",400);  
		WndStatus.rcNormalPosition   =   rect;  
		WndStatus.flags=   AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","FLAG",0);  
		nCmdShow   =   AfxGetApp()->GetProfileInt("MYCOMMWNDSTATUS","SHOWCMD",SW_SHOW);  
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
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","FLAG",WndStatus.flags);  
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","SHOWCMD",WndStatus.showCmd);  
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","LEFT",WndStatus.rcNormalPosition.left);  
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","RIGHT",WndStatus.rcNormalPosition.right);  
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","TOP",WndStatus.rcNormalPosition.top);  
	AfxGetApp()->WriteProfileInt("MYCOMMWNDSTATUS","BOTTOM",WndStatus.rcNormalPosition.bottom);  
	
	CFrameWnd::OnClose();
}

void CMainFrame::OnEditCommand() 
{
	// TODO: Add your command handler code here
	CCommandDlg dlg;
	dlg.m_strName_1 = _T("ABC");
	if (dlg.DoModal()==IDOK)
	{
		AfxMessageBox("OK");
	}
}
