; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommandDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyComm.h"
LastPage=0

ClassCount=6
Class1=CMyCommApp
Class2=CMyCommDoc
Class3=CMyCommView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_MYCOMM_FORM
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CCommandDlg
Resource4=IDD_DLGCOMMAND

[CLS:CMyCommApp]
Type=0
HeaderFile=MyComm.h
ImplementationFile=MyComm.cpp
Filter=N

[CLS:CMyCommDoc]
Type=0
HeaderFile=MyCommDoc.h
ImplementationFile=MyCommDoc.cpp
Filter=N
LastObject=CMyCommDoc

[CLS:CMyCommView]
Type=0
HeaderFile=MyCommView.h
ImplementationFile=MyCommView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CMyCommView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_EDIT_COMMAND




[CLS:CAboutDlg]
Type=0
HeaderFile=MyComm.cpp
ImplementationFile=MyComm.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_COMMAND
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_MYCOMM_FORM]
Type=1
Class=CMyCommView
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDRECDATA,edit,1352732804
Control5=IDC_EDSENDDATA,edit,1352732804
Control6=IDC_BTCOMMAND_A,button,1342242816
Control7=IDC_BTCOMMAND_B,button,1342242816
Control8=IDC_BTCOMMAND_C,button,1342242816
Control9=IDC_BTCOMMAND_D,button,1342242816
Control10=IDC_BTCOMMAND_E,button,1342242816
Control11=IDC_BTCOMMAND_F,button,1342242816
Control12=IDC_BTCOMMAND_G,button,1342242816
Control13=IDC_BTCOMMAND_H,button,1342242816
Control14=IDC_BTSEND,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CBCOM,combobox,1344340034
Control17=IDC_STATIC,static,1342308352
Control18=IDC_CBBANDRATE,combobox,1344340226
Control19=IDC_STATIC,static,1342308352
Control20=IDC_CBDATABITS,combobox,1344340226
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_CBPARITY,combobox,1344340226
Control24=IDC_CBSTOPBITS,combobox,1344340226
Control25=IDC_BTOPENCOMM,button,1342242816
Control26=IDC_BMPCOM,static,1342177550

[DLG:IDD_DLGCOMMAND]
Type=1
Class=CCommandDlg
ControlCount=82
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDNAME_1,edit,1350631552
Control4=IDC_EDCOMMAND_1,edit,1350631552
Control5=IDC_CBSHUT_1,combobox,1344340034
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDNAME_2,edit,1350631552
Control8=IDC_EDCOMMAND_2,edit,1350631552
Control9=IDC_CBSHUT_2,combobox,1344340034
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDNAME_3,edit,1350631552
Control12=IDC_EDCOMMAND_3,edit,1350631552
Control13=IDC_CBSHUT_3,combobox,1344340034
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDNAME_4,edit,1350631552
Control16=IDC_EDCOMMAND_4,edit,1350631552
Control17=IDC_CBSHUT_4,combobox,1344340034
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDNAME_5,edit,1350631552
Control20=IDC_EDCOMMAND_5,edit,1350631552
Control21=IDC_CBSHUT_5,combobox,1344340034
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDNAME_6,edit,1350631552
Control24=IDC_EDCOMMAND_6,edit,1350631552
Control25=IDC_CBSHUT_6,combobox,1344340034
Control26=IDC_STATIC,static,1342308352
Control27=IDC_EDNAME_7,edit,1350631552
Control28=IDC_EDCOMMAND_7,edit,1350631552
Control29=IDC_CBSHUT_7,combobox,1344340034
Control30=IDC_STATIC,static,1342308352
Control31=IDC_EDNAME_8,edit,1350631552
Control32=IDC_EDCOMMAND_8,edit,1350631552
Control33=IDC_CBSHUT_8,combobox,1344340034
Control34=IDC_STATIC,static,1342308352
Control35=IDC_EDNAME_9,edit,1350631552
Control36=IDC_EDCOMMAND_9,edit,1350631552
Control37=IDC_CBSHUT_9,combobox,1344340034
Control38=IDC_STATIC,static,1342308352
Control39=IDC_EDNAME_10,edit,1350631552
Control40=IDC_EDCOMMAND_10,edit,1350631552
Control41=IDC_CBSHUT_10,combobox,1344340034
Control42=IDC_STATIC,static,1342308352
Control43=IDC_EDNAME_11,edit,1350631552
Control44=IDC_EDCOMMAND_11,edit,1350631552
Control45=IDC_CBSHUT_11,combobox,1344340034
Control46=IDC_STATIC,static,1342308352
Control47=IDC_EDNAME_12,edit,1350631552
Control48=IDC_EDCOMMAND_12,edit,1350631552
Control49=IDC_CBSHUT_12,combobox,1344340034
Control50=IDC_STATIC,static,1342308352
Control51=IDC_EDNAME_13,edit,1350631552
Control52=IDC_EDCOMMAND_13,edit,1350631552
Control53=IDC_CBSHUT_13,combobox,1344340034
Control54=IDC_STATIC,static,1342308352
Control55=IDC_EDNAME_14,edit,1350631552
Control56=IDC_EDCOMMAND_14,edit,1350631552
Control57=IDC_CBSHUT_14,combobox,1344340034
Control58=IDC_STATIC,static,1342308352
Control59=IDC_EDNAME_15,edit,1350631552
Control60=IDC_EDCOMMAND_15,edit,1350631552
Control61=IDC_CBSHUT_15,combobox,1344340034
Control62=IDC_STATIC,static,1342308352
Control63=IDC_EDNAME_16,edit,1350631552
Control64=IDC_EDCOMMAND_16,edit,1350631552
Control65=IDC_CBSHUT_16,combobox,1344340034
Control66=IDC_STATIC,static,1342308352
Control67=IDC_EDNAME_17,edit,1350631552
Control68=IDC_EDCOMMAND_17,edit,1350631552
Control69=IDC_CBSHUT_17,combobox,1344340034
Control70=IDC_STATIC,static,1342308352
Control71=IDC_EDNAME_18,edit,1350631552
Control72=IDC_EDCOMMAND_18,edit,1350631552
Control73=IDC_CBSHUT_18,combobox,1344340034
Control74=IDC_STATIC,static,1342308352
Control75=IDC_EDNAME_19,edit,1350631552
Control76=IDC_EDCOMMAND_19,edit,1350631552
Control77=IDC_CBSHUT_19,combobox,1344340034
Control78=IDC_STATIC,static,1342308352
Control79=IDC_EDNAME_20,edit,1350631552
Control80=IDC_EDCOMMAND_20,edit,1350631552
Control81=IDC_CBSHUT_20,combobox,1344340034
Control82=IDC_STATIC,static,1342308352

[CLS:CCommandDlg]
Type=0
HeaderFile=CommandDlg.h
ImplementationFile=CommandDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CBSHUT_1
VirtualFilter=dWC

