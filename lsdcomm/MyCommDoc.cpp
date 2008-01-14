// MyCommDoc.cpp : implementation of the CMyCommDoc class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MyCommDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc

IMPLEMENT_DYNCREATE(CMyCommDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCommDoc, CDocument)
	//{{AFX_MSG_MAP(CMyCommDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc construction/destruction

CMyCommDoc::CMyCommDoc()
{
	// TODO: add one-time construction code here
	m_ComAction = FALSE;

	m_intPort     = 1;
	m_intBaudRate = 9600;
	m_intDataBits = 8;
	m_cParity     ='N';
	m_intStopBits = 0;

	m_IsReceiveHex = TRUE;
	m_IsSendHex = TRUE;
	m_CommTimeout.ReadIntervalTimeout = 1000;
	m_CommTimeout.ReadTotalTimeoutMultiplier = 0;
	m_CommTimeout.ReadTotalTimeoutConstant = 0;
	m_CommTimeout.WriteTotalTimeoutMultiplier = 0;
	m_CommTimeout.WriteTotalTimeoutConstant = 0;

	m_TXCount = 0;
	m_RXCount = 0;
}

CMyCommDoc::~CMyCommDoc()
{
}

BOOL CMyCommDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc serialization

void CMyCommDoc::Serialize(CArchive& ar)
{
	//
	// 2. È¥µô¿ì½Ý¼ü 2008-1-14
	//
	//
	int ver; 
	int count;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		
		ver = 2;
		ar<<ver;  //version
		ar<<m_intPort;
		ar<<m_intBaudRate;
		ar<<m_intStopBits;
		ar<<m_intStopBits;
		ar<<m_cParity;
		ar<<m_intDataBits;
		
		//Timeout
		ar<<m_CommTimeout.ReadIntervalTimeout;
		ar<<m_CommTimeout.ReadTotalTimeoutMultiplier;
		ar<<m_CommTimeout.ReadTotalTimeoutConstant;
		ar<<m_CommTimeout.WriteTotalTimeoutMultiplier;
		ar<<m_CommTimeout.WriteTotalTimeoutConstant;
		
		count = COMMANDCOUNT;
		ar<<count;
		for(int i=0;i<count-1;i++)
		{
			ar<<m_Command[i].m_strName;
			//ar<<m_Command[i].m_ShutChar; ver=2 È¥µô
			ar<<m_Command[i].m_strCommand;
					
		};

		ar<<m_IsReceiveHex;
		ar<<m_IsSendHex;
		ar<<m_strProtocol;

				
	}
	else
	{
		// TODO: add loading code here
		ar>>ver;
		ar>>m_intPort;
		ar>>m_intBaudRate;
		ar>>m_intStopBits;
		ar>>m_intStopBits;
		ar>>m_cParity;
		ar>>m_intDataBits;

		//Timeout
		ar>>m_CommTimeout.ReadIntervalTimeout;
		ar>>m_CommTimeout.ReadTotalTimeoutMultiplier;
		ar>>m_CommTimeout.ReadTotalTimeoutConstant;
		ar>>m_CommTimeout.WriteTotalTimeoutMultiplier;
		ar>>m_CommTimeout.WriteTotalTimeoutConstant;

		ar>>count;
		for(int i=0;i<count-1;i++)
		{
			ar>>m_Command[i].m_strName;
			if (ver < 2) 
			{
				char myc;
				ar>>myc;
			}
			ar>>m_Command[i].m_strCommand;
		};

		ar>>m_IsReceiveHex;
		ar>>m_IsSendHex;
		ar>>m_strProtocol;

	};
}

BOOL CMyCommDoc::OpenComm(CWnd * POwner)
{
	if (m_Comm.InitPort(POwner,m_intPort,m_intBaudRate,m_cParity,
		m_intDataBits,m_intStopBits
		/*
		m_CommTimeout.ReadIntervalTimeout,
		m_CommTimeout.ReadTotalTimeoutConstant,
		m_CommTimeout.ReadTotalTimeoutMultiplier,
		m_CommTimeout.WriteTotalTimeoutMultiplier,
		m_CommTimeout.WriteTotalTimeoutConstant*/))
	{
		m_Comm.StartMonitoring();
		return TRUE;
	}
	else
		return FALSE;
}
void CMyCommDoc::CloseComm()
{
	m_Comm.ClosePort();
	m_Comm.StopMonitoring();
}


/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc diagnostics

#ifdef _DEBUG
void CMyCommDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCommDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc commands
