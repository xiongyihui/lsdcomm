// MyCommView.h : interface of the CMyCommView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)
#define AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CommAdvancedDlg.h"
#include "ETSLayout.h"


class CMyCommView : public ETSLayoutFormView
{
protected: // create from serialization only
	CMyCommView();
	DECLARE_DYNCREATE(CMyCommView)
public:
	//{{AFX_DATA(CMyCommView)
	enum { IDD = IDD_MYCOMM_FORM };
	CComboBox	m_ctrlCommand;
	CButton	m_ctrlAutoSend;
	CComboBox	m_ctrlStopBits;
	CComboBox	m_ctrlParity;
	CComboBox	m_ctrlDataBits;
	CComboBox	m_ctrlCOM;
	CComboBox	m_ctrlBaudRate;
	CButton	m_ctrlSendHex;
	CButton	m_ctrlReceiveHex;
	CStatic	m_ctrlComImg;
	CString	m_strSendData;
	CString m_strReceiveData;
	int		m_AutoSendTime;
	//}}AFX_DATA

// Attributes
public:
	CMyCommDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCommView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CToolTipCtrl m_hint;

	int DoStr2Hex(CString str,char* data);
	char DoHexChar(char c);
	BOOL DoIsNumeric(const CString &strText);
	void DoRefreshControl2(BOOL bValue);
	
// Generated message map functions

protected:
	
	//{{AFX_MSG(CMyCommView)
	afx_msg void OnBtopencomm();
	afx_msg void OnBtadvanced();
	afx_msg void OnChrevhex();
	afx_msg void OnChsendhex();
	afx_msg void OnBtSend();
	afx_msg void OnBtviewprotocol();
	afx_msg void OnBtclearreceivedata();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChautosend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);
	afx_msg void OnSelchangeCbcommand();
	afx_msg void OnBtsaverecdata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyCommView.cpp
inline CMyCommDoc* CMyCommView::GetDocument()
   { return (CMyCommDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)
