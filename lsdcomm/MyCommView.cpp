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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommView construction/destruction

CMyCommView::CMyCommView()
	: CFormView(CMyCommView::IDD)
{
	//{{AFX_DATA_INIT(CMyCommView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMyCommView::~CMyCommView()
{
}

void CMyCommView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyCommView)
	DDX_Control(pDX, IDC_BMPCOM, m_ctrlComImg);
	//}}AFX_DATA_MAP
}

BOOL CMyCommView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMyCommView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMyCommView diagnostics

#ifdef _DEBUG
void CMyCommView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyCommView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMyCommDoc* CMyCommView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCommDoc)));
	return (CMyCommDoc*)m_pDocument;
}

void CMyCommView::DoRefreshControl(void)
{
	// send botton
	BOOL myAction = GetDocument()->m_ComAction;
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
		GetDocument()->m_Comm.ClosePort();

		CBitmap myBitmap;
		myBitmap.LoadBitmap(IDB_BITMAPCLOSECOM);
		m_ctrlComImg.SetBitmap(myBitmap);
		CButton * myb = ((CButton *)this->GetDlgItem(IDC_BTOPENCOMM));
		myb->SetWindowText(_T("打开串口"));
		GetDocument()->m_ComAction = FALSE;
	}
	else{
		GetDocument()->m_Comm.InitPort(this);

		CBitmap myBitmap;
		myBitmap.LoadBitmap(IDB_BITMAPOPENCOM);
		m_ctrlComImg.SetBitmap(myBitmap);
		CButton * myb = ((CButton *)this->GetDlgItem(IDC_BTOPENCOMM));
		myb->SetWindowText(_T("关闭串口"));
		GetDocument()->m_ComAction = TRUE;
	}
	DoRefreshControl();
}
