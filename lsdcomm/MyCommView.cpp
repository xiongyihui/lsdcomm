// MyCommView.cpp : implementation of the CMyCommView class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MyCommDoc.h"
#include "MyCommView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCommView

IMPLEMENT_DYNCREATE(CMyCommView, CFormView)

BEGIN_MESSAGE_MAP(CMyCommView, CFormView)
	//{{AFX_MSG_MAP(CMyCommView)
	ON_BN_CLICKED(IDC_BTOPENCOMM, OnBtopencomm)
	ON_BN_CLICKED(IDC_BTADVANCED, OnBtadvanced)
	ON_BN_CLICKED(IDC_CHREVHEX, OnChrevhex)
	ON_BN_CLICKED(IDC_CHSENDHEX, OnChsendhex)
	ON_BN_CLICKED(IDC_BTSEND, OnBtSend)
	ON_BN_CLICKED(IDC_BTVIEWPROTOCOL, OnBtviewprotocol)
	ON_BN_CLICKED(IDC_BTCLEARRECEIVEDATA, OnBtclearreceivedata)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHVIEWLINE, OnChviewline)
	ON_BN_CLICKED(IDC_BTCOMMAND_A, OnBtcommandA)
	ON_BN_CLICKED(IDC_BTCOMMAND_B, OnBtcommandB)
	ON_BN_CLICKED(IDC_BTCOMMAND_C, OnBtcommandC)
	ON_BN_CLICKED(IDC_BTCOMMAND_D, OnBtcommandD)
	ON_BN_CLICKED(IDC_BTCOMMAND_E, OnBtcommandE)
	ON_BN_CLICKED(IDC_BTCOMMAND_F, OnBtcommandF)
	ON_BN_CLICKED(IDC_BTCOMMAND_G, OnBtcommandG)
	ON_BN_CLICKED(IDC_BTCOMMAND_H, OnBtcommandH)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommView construction/destruction

CMyCommView::CMyCommView()
	: ETSLayoutFormView(CMyCommView::IDD)
{
	//{{AFX_DATA_INIT(CMyCommView)
	m_strSendData = _T("");
	m_IsViewLine = TRUE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_hint.Create(this) ;
}

CMyCommView::~CMyCommView()
{
}

void CMyCommView::DoDataExchange(CDataExchange* pDX)
{
	ETSLayoutFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyCommView)
	DDX_Control(pDX, IDC_CBSTOPBITS, m_ctrlStopBits);
	DDX_Control(pDX, IDC_CBPARITY, m_ctrlParity);
	DDX_Control(pDX, IDC_CBDATABITS, m_ctrlDataBits);
	DDX_Control(pDX, IDC_CBCOM, m_ctrlCOM);
	DDX_Control(pDX, IDC_CBBANDRATE, m_ctrlBaudRate);
	DDX_Control(pDX, IDC_EDRECDATA, m_ctrlRecEdit);
	DDX_Control(pDX, IDC_CHSENDHEX, m_ctrlSendHex);
	DDX_Control(pDX, IDC_CHREVHEX, m_ctrlReceiveHex);
	DDX_Control(pDX, IDC_BMPCOM, m_ctrlComImg);
	DDX_Text(pDX, IDC_EDSENDDATA, m_strSendData);
	DDX_Text(pDX,IDC_EDRECDATA,m_strReceiveData);
	DDX_Check(pDX, IDC_CHVIEWLINE, m_IsViewLine);
	//}}AFX_DATA_MAP
}

BOOL CMyCommView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return ETSLayoutFormView::PreCreateWindow(cs);
}

void CMyCommView::OnInitialUpdate()
{
	ModifyStyleEx(0,  WS_EX_STATICEDGE);
    ModifyStyleEx(WS_EX_CLIENTEDGE,0 );
	
	ETSLayoutFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_ctrlReceiveHex.SetCheck(GetDocument()->m_IsReceiveHex);
	m_ctrlSendHex.SetCheck(GetDocument()->m_IsSendHex);
	CString mystr;
	m_ctrlCOM.SetCurSel(GetDocument()->m_intPort-1);
	mystr.Format("%d",GetDocument()->m_intBaudRate); 
	m_ctrlBaudRate.SetCurSel(m_ctrlBaudRate.FindString(0,mystr));
	mystr.Format("%d",GetDocument()->m_intDataBits);
	m_ctrlDataBits.SetCurSel(m_ctrlDataBits.FindString(0,mystr));

	switch(GetDocument()->m_cParity)
	{
		case 'N':
			m_ctrlParity.SetCurSel(0);
			break;
		case 'O':
			m_ctrlParity.SetCurSel(1);
			break;
		case 'E':
			m_ctrlParity.SetCurSel(2);
			break;
		case 'M':
			m_ctrlParity.SetCurSel(3);
			break;
		case 'S':
			m_ctrlParity.SetCurSel(4);
			break;

	}
	m_ctrlStopBits.SetCurSel(GetDocument()->m_intStopBits); 
	DoRefreshControl(FALSE);	
	
	//layout
	CreateRoot(VERTICAL)
		<< 	( pane(HORIZONTAL)
		<<( pane(VERTICAL,ABSOLUTE_VERT)
		<< item( IDC_STATIC1, NORESIZE )
		<< item( IDC_STATIC2, NORESIZE ))
		<< item(IDC_EDRECDATA,GREEDY)    //revdata edit
		)	
		
		//	<< item ( IDC_ITEM_LIST_STATIC, NORESIZE )
		//	<< item ( IDC_ITEM_LIST, GREEDY )
		
		<<	( pane(HORIZONTAL, ABSOLUTE_VERT )
		//<< (paneCtrl(IDC_STATIC3,VERTICAL,GREEDY, nDefaultBorder, 10, 10)
		<< (pane(VERTICAL)
			//<< item( IDC_STATIC3, NORESIZE)
			//<< itemGrowing(VERTICAL)
			<< item (IDC_STATIC_SEND,NORESIZE)
			<< item( IDC_CHSENDHEX,NORESIZE)
			

			)
		<< ( pane(VERTICAL,ABSOLUTE_VERT)
		<< item( IDC_EDSENDDATA,RELATIVE_HORZ)
		<<(pane(HORIZONTAL, ABSOLUTE_VERT)
		<< item( IDC_BTCOMMAND_A, NORESIZE)
		<< item( IDC_BTCOMMAND_B, NORESIZE)
		<< item( IDC_BTCOMMAND_C, NORESIZE)
		<< item( IDC_BTCOMMAND_D, NORESIZE)
		<< item( IDC_BTCOMMAND_E, NORESIZE)
		<< item( IDC_BTCOMMAND_F, NORESIZE)
		<< item( IDC_BTCOMMAND_G, NORESIZE)
		<< item( IDC_BTCOMMAND_H, NORESIZE)
		<< itemGrowing (HORIZONTAL)    // bank row 
		<< item( IDC_BTSEND, NORESIZE)   // send button ALIGN_RIGHT					
		 )
		
		));
	
	UpdateLayout();

	//hint
	EnableToolTips(TRUE);
	m_hint.Activate(TRUE);
	for(int i=0;i<20;i++)
	{
		if(GetDocument()->m_Command[i].m_ShutChar=='A')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_A),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='B')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_B),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='C')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_C),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='D')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_D),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='E')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_E),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='F')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_F),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='G')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_G),GetDocument()->m_Command[i].m_strName);
		if(GetDocument()->m_Command[i].m_ShutChar=='H')
			m_hint.AddTool(GetDlgItem(IDC_BTCOMMAND_H),GetDocument()->m_Command[i].m_strName);
		
	}
	m_hint.SetTipTextColor(RGB(0,0,0));  
	m_hint.SetDelayTime(100);            

}

/////////////////////////////////////////////////////////////////////////////
// CMyCommView diagnostics

#ifdef _DEBUG
void CMyCommView::AssertValid() const
{
	ETSLayoutFormView::AssertValid();
}

void CMyCommView::Dump(CDumpContext& dc) const
{
	ETSLayoutFormView::Dump(dc);
}

CMyCommDoc* CMyCommView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCommDoc)));
	return (CMyCommDoc*)m_pDocument;
}

void CMyCommView::DoRefreshControl(BOOL bValue)
{
	// send botton
	BOOL myAction = bValue;
	GetDlgItem(IDC_BTSEND)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_A)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_B)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_C)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_D)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_E)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_F)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_G)->EnableWindow(myAction);
	GetDlgItem(IDC_BTCOMMAND_H)->EnableWindow(myAction);
	

	// com param
	GetDlgItem(IDC_CBCOM)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBBANDRATE)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBDATABITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBPARITY)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBSTOPBITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_BTADVANCED)->EnableWindow(!myAction);
    //GetDlgItem(IDC_STATICCOMIMG)->VisielbWindow(!m_ComAction);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCommView message handlers

void CMyCommView::OnBtopencomm() 
{
	// TODO: Add your control notification handler code here
	if (GetDocument()->m_ComAction) 
	{
		GetDocument()->CloseComm();

		CBitmap myBitmap;
		myBitmap.LoadBitmap(IDB_BITMAPCLOSECOM);
		m_ctrlComImg.SetBitmap(myBitmap);
		CButton * myb = ((CButton *)this->GetDlgItem(IDC_BTOPENCOMM));
		myb->SetWindowText(_T("打开串口"));
		GetDocument()->m_ComAction = FALSE;
		DoRefreshControl(FALSE);
	}
	else{
		
		CString mystr;
		char myc;		

		if (m_ctrlCOM.GetCurSel()<0) 
		{
			AfxMessageBox("请选择串口");
			return ;
		}	
		GetDocument()->m_intPort = m_ctrlCOM.GetCurSel()+1;
		m_ctrlBaudRate.GetWindowText(mystr);
		if (!DoIsNumeric(mystr)) 
		{	
			AfxMessageBox("请选择波特率");
			return;
		}	
		GetDocument()->m_intBaudRate = atoi(mystr);
		m_ctrlDataBits.GetWindowText(mystr);
		if (!DoIsNumeric(mystr)) 
		{
			AfxMessageBox("请选择数据位");
			return;
		}	
		GetDocument()->m_intDataBits = atoi(mystr);
		
		myc = 'N';
		int i=m_ctrlParity.GetCurSel();
		switch(i)
		{
		case 0:
			myc='N';
			break;
		case 1:
			myc='O';
			break;
		case 2:
			myc='E';
			break;
		case 3:
			myc='M';
			break;
		case 4:
			myc='S';
			break;
		}
		GetDocument()->m_cParity=myc;
		
		if (m_ctrlStopBits.GetCurSel()<0) 
		{
			AfxMessageBox("请选择停止位");
			return;
		}	
		GetDocument()->m_intStopBits = m_ctrlStopBits.GetCurSel();  //index 表示
		
		if (GetDocument()->OpenComm(this))
		{	
			CBitmap myBitmap;
			myBitmap.LoadBitmap(IDB_BITMAPOPENCOM);
			m_ctrlComImg.SetBitmap(myBitmap);
			CButton * myb = ((CButton *)this->GetDlgItem(IDC_BTOPENCOMM));
			myb->SetWindowText(_T("关闭串口"));
			GetDocument()->m_ComAction = TRUE;
			DoRefreshControl(TRUE);
		}
	}
	
}

int CMyCommView::DoStr2Hex(CString str,char* data)
{
	int t,t1;
	int rlen=0,len=str.GetLength();
	for (int i=0;i<len;)
	{
		char l,h=str[i];
		if(h==' ')
		{
			i++;
			continue;
		}
		i++;
		if(i>=len) break;
		l=str[i];
		t=DoHexChar(h);
		t1=DoHexChar(l);
		if((t==16)||(t1=16)) break;
		else t=t*16+t1;
		i++;
		data[rlen]=(char)t;
		rlen++;
	}
	return rlen;
	
}

char CMyCommView::DoHexChar(char c)
{
	if((c>='0')&&(c<='9'))
		return c-0x30;
	else if((c>='A')&&(c<='F'))
		return c-'A'+10;
	else if((c>='a')&&(c<='f'))
		return c-'a'+10;
	else
		return 0x10;
}

void CMyCommView::OnBtadvanced() 
{
	// TODO: Add your control notification handler code here
	CCommAdvancedDlg dlg;
	
	dlg.m_dwoReadInter       = GetDocument()->m_CommTimeout.ReadIntervalTimeout;
	dlg.m_dwoReadTotalMult   = GetDocument()->m_CommTimeout.ReadTotalTimeoutMultiplier;
	dlg.m_dwoReadTotalConst  = GetDocument()->m_CommTimeout.ReadTotalTimeoutConstant;
	dlg.m_dwoWriteTotalMult  = GetDocument()->m_CommTimeout.WriteTotalTimeoutMultiplier;
	dlg.m_dwoWriteTotalConst = GetDocument()->m_CommTimeout.WriteTotalTimeoutConstant;
	if (dlg.DoModal()==IDOK)
	{
		GetDocument()->m_CommTimeout.ReadIntervalTimeout = 	dlg.m_dwoReadInter;
		GetDocument()->m_CommTimeout.ReadTotalTimeoutMultiplier = dlg.m_dwoReadTotalMult;
		GetDocument()->m_CommTimeout.ReadTotalTimeoutConstant = dlg.m_dwoReadTotalConst;
		GetDocument()->m_CommTimeout.WriteTotalTimeoutMultiplier = dlg.m_dwoWriteTotalMult;
		GetDocument()->m_CommTimeout.WriteTotalTimeoutConstant = dlg.m_dwoWriteTotalConst;
	}

}

void CMyCommView::OnChrevhex() 
{
	// TODO: Add your control notification handler code here
	if (m_ctrlReceiveHex.GetCheck())
		GetDocument()->m_IsReceiveHex = TRUE;
	else
		GetDocument()->m_IsReceiveHex = FALSE;	
}

void CMyCommView::OnChsendhex() 
{
	// TODO: Add your control notification handler code here
	if (m_ctrlSendHex.GetCheck())
		GetDocument()->m_IsSendHex = TRUE;
	else
		GetDocument()->m_IsSendHex = FALSE;			
}

void CMyCommView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
}


BOOL CMyCommView::DoIsNumeric(const CString &strText)
{
	BOOL  bRet=TRUE;  
	int   nLen=strText.GetLength();  
	if(strText.IsEmpty())  
	{  
		bRet =  FALSE;
	} 
	
	for(int i=0;i<nLen;i++)  
	{  
		bRet=(_istdigit(strText.GetAt(i)) != 0);  
		if(!bRet)  
			break;  
	}  
	return   bRet;  
}

/*
LONG CMyCommView::OnComm(WPARAM ch,LPARAM port)
{
	if (m_ctrlReceiveHex.GetCheck())
	{
		CString str;
		str.Format("%X",ch);
		DoAppendToRevEdit(str);
	}
	else{
		CString str;
		str.Format("%c",ch);
		DoAppendToRevEdit(str);
	}
	
	UpdateData(FALSE);
	return 0;
}
*/

void CMyCommView::OnBtSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if(m_ctrlSendHex.GetCheck())
	{
		char data[512];
		int len=DoStr2Hex(m_strSendData,data);
		GetDocument()->m_Comm.WriteToPort(data,len);
		GetDocument()->TX_count+=(long)((m_strSendData.GetLength()+1)/3);
	}
	else 
	{
		GetDocument()->m_Comm.WriteToPort((LPCTSTR)m_strSendData);	//发送数据
		GetDocument()->TX_count+=m_strSendData.GetLength();
	}
	
}

void CMyCommView::OnBtviewprotocol() 
{
	// TODO: Add your control notification handler code here
	if (!GetDocument()->m_strProtocol.IsEmpty())
	{
		DoAppendToRevEdit(GetDocument()->m_strProtocol+"\n");	
	}
	else{
		DoAppendToRevEdit("无串口通信协议内容\n");
	}	
	
}

void CMyCommView::OnBtclearreceivedata() 
{
	// TODO: Add your control notification handler code here
	m_ctrlRecEdit.SetWindowText("");
}

void CMyCommView::DoAppendToRevEdit(CString str)
{
	int  nLength  =  m_ctrlRecEdit.SendMessage(WM_GETTEXTLENGTH);
	m_ctrlRecEdit.SetSel(nLength, nLength);
	m_ctrlRecEdit.ReplaceSel(str);	
}

void CMyCommView::OnSize(UINT nType, int cx, int cy) 
{
	ETSLayoutFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void CMyCommView::OnChviewline() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctrlRecEdit.SetVisibleLine(m_IsViewLine);
}

void CMyCommView::DoRunCommand(const char ch)
{
	CString mystr;
	for(int i=0;i<20;i++)
	{
		if (GetDocument()->m_Command[i].m_ShutChar == ch) {
			mystr = GetDocument()->m_Command[i].m_strCommand;
			break;
		}	
	}

	//run command
	if(!mystr.IsEmpty())
	{
		m_strSendData = mystr;
		UpdateData(FALSE);
		OnBtSend();
	}

	
}

void CMyCommView::OnBtcommandA() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('A');
}

void CMyCommView::OnBtcommandB() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('B');
}

void CMyCommView::OnBtcommandC() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('C');
}

void CMyCommView::OnBtcommandD() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('D');
}

void CMyCommView::OnBtcommandE() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('E');
}

void CMyCommView::OnBtcommandF() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('F');
}

void CMyCommView::OnBtcommandG() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('G');
}

void CMyCommView::OnBtcommandH() 
{
	// TODO: Add your control notification handler code here
	DoRunCommand('H');
}

BOOL CMyCommView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_hint.RelayEvent(pMsg);
	return CFormView::PreTranslateMessage(pMsg);
}
