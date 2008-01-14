// MyCommDoc.h : interface of the CMyCommDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_)
#define AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SerialPort.h"

const COMMANDCOUNT = 20; 

struct CommCommand {
	CString m_strName;
	CString m_strCommand;
	BOOL  m_IsHex;  //is Hex
} ;

struct CommTimeout{
	WORD ReadIntervalTimeout;
	WORD ReadTotalTimeoutMultiplier;
	WORD ReadTotalTimeoutConstant;
	WORD WriteTotalTimeoutMultiplier;
	WORD WriteTotalTimeoutConstant;
};

class CMyCommDoc : public CDocument
{
protected: // create from serialization only
	CMyCommDoc();
	DECLARE_DYNCREATE(CMyCommDoc)

// Attributes
public:
	CSerialPort m_Comm;
	BOOL m_ComAction;
	int m_intPort;  
	int m_intBaudRate;
	int m_intDataBits  ;  //数据位
	char m_cParity   ;    //校验位 0 ,1,2 
	int m_intStopBits;    // 0=1 1=1.5 2=2
	CommTimeout m_CommTimeout;
	CommCommand m_Command[COMMANDCOUNT];

	BOOL m_IsReceiveHex;
	BOOL m_IsSendHex;

	CString m_strReceiveData;
	CString m_strSendData;
	CString m_strProtocol;
	LONG  m_TXCount;
	LONG  m_RXCount;

// Operations
public:
	BOOL OpenComm(CWnd * POwner);
	void CloseComm();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCommDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCommDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_)
