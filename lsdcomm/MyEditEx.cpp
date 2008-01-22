// MyEditEx.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "MyEditEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CMyEditEx

CMyEditEx::CMyEditEx()
{
}

CMyEditEx::~CMyEditEx()
{
}


BEGIN_MESSAGE_MAP(CMyEditEx, CEdit)
	//{{AFX_MSG_MAP(CMyEditEx)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEditEx message handlers

void CMyEditEx::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	SetFocus();
	CMenu menu;
	menu.CreatePopupMenu();
	BOOL bReadOnly = GetStyle() & ES_READONLY;
	DWORD flags = CanUndo() && !bReadOnly ? 0 : MF_GRAYED;
	menu.InsertMenu(0, MF_BYPOSITION | flags, EM_UNDO,
		MES_UNDO);
	
	menu.InsertMenu(1, MF_BYPOSITION | MF_SEPARATOR);
	
	DWORD sel = GetSel();
	flags = LOWORD(sel) == HIWORD(sel) ? MF_GRAYED : 0;
	menu.InsertMenu(2, MF_BYPOSITION | flags, WM_COPY,
		MES_COPY);
	
	flags = (flags == MF_GRAYED || bReadOnly) ? MF_GRAYED : 0;
	menu.InsertMenu(2, MF_BYPOSITION | flags, WM_CUT,
		MES_CUT);
	menu.InsertMenu(4, MF_BYPOSITION | flags, WM_CLEAR,
		MES_DELETE);
	
	flags = IsClipboardFormatAvailable(CF_TEXT) &&
		!bReadOnly ? 0 : MF_GRAYED;
	menu.InsertMenu(4, MF_BYPOSITION | flags, WM_PASTE,
		MES_PASTE);
	
	//menu.InsertMenu(6, MF_BYPOSITION | MF_SEPARATOR);
	
	int len = GetWindowTextLength();
	flags = (!len || (LOWORD(sel) == 0 && HIWORD(sel) ==
		len)) ? MF_GRAYED : 0;
	menu.InsertMenu(7, MF_BYPOSITION | flags, ME_SELECTALL,MES_SELECTALL); 
	
	// add
	
	menu.InsertMenu(8, MF_BYPOSITION | MF_SEPARATOR);
	flags = LOWORD(sel) == HIWORD(sel) ? MF_GRAYED : 0;
	menu.InsertMenu(9, MF_BYPOSITION | flags, ME_CHECKSUM,
		MES_CHECKSUM);
	
	menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON |TPM_RIGHTBUTTON, point.x, point.y, this); 
}

BOOL CMyEditEx::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch (LOWORD(wParam))
	{
	case EM_UNDO:
	case WM_CUT:
	case WM_COPY:
	case WM_CLEAR:
	case WM_PASTE:
		return SendMessage(LOWORD(wParam));
	case ME_SELECTALL:
		return SendMessage (EM_SETSEL, 0, -1);
	case ME_CHECKSUM:
		{
			int a,b;
			GetSel(a,b);
			CString mystr;
			mystr.Format("%d %d",a,b);
			AfxMessageBox(mystr);
			
			CString myv;
			GetWindowText(myv);
			myv = myv.Mid(a,b-a);
			AfxMessageBox(myv);
			//return SendMessage (EM_SETSEL, 0, -1);
			return SendMessage(ME_CHECKSUM,wParam,(LPARAM)&myv);
		}
	default:
		return CEdit::OnCommand(wParam, lParam);
	}
	
}
