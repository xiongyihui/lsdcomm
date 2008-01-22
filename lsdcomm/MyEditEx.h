#if !defined(AFX_MYEDITEX_H__A385A48F_E6B2_4048_8C0B_3BB13EFA9325__INCLUDED_)
#define AFX_MYEDITEX_H__A385A48F_E6B2_4048_8C0B_3BB13EFA9325__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEditEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEditEx window

#define MES_UNDO _T("&Undo")
#define MES_CUT _T("Cu&t")
#define MES_COPY _T("&Copy")
#define MES_PASTE _T("&Paste")
#define MES_DELETE _T("&Delete")
#define MES_SELECTALL _T("Select &All")
#define ME_SELECTALL WM_USER+0x7000 

//add 
#define ME_CHECKSUM WM_USER+0x7001
#define MES_CHECKSUM _T("Ð£¼ìºÍ")

#define ME_COMMAND	WM_USER+0x7002; 

class CMyEditEx : public CEdit
{
// Construction
public:
	CMyEditEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEditEx)
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyEditEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyEditEx)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDITEX_H__A385A48F_E6B2_4048_8C0B_3BB13EFA9325__INCLUDED_)
