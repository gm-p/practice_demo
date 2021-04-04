; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Ctrl1SDI.h"
LastPage=0

ClassCount=6
Class1=CEx_Ctrl1SDIApp
Class2=CEx_Ctrl1SDIDoc
Class3=CEx_Ctrl1SDIView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CInputDlg
Resource3=IDD_INPUT

[CLS:CEx_Ctrl1SDIApp]
Type=0
HeaderFile=Ex_Ctrl1SDI.h
ImplementationFile=Ex_Ctrl1SDI.cpp
Filter=N

[CLS:CEx_Ctrl1SDIDoc]
Type=0
HeaderFile=Ex_Ctrl1SDIDoc.h
ImplementationFile=Ex_Ctrl1SDIDoc.cpp
Filter=N

[CLS:CEx_Ctrl1SDIView]
Type=0
HeaderFile=Ex_Ctrl1SDIView.h
ImplementationFile=Ex_Ctrl1SDIView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Ctrl1SDI.cpp
ImplementationFile=Ex_Ctrl1SDI.cpp
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
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_TEST_INPUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_INPUT]
Type=1
Class=CInputDlg
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342177296
Control9=IDC_EDIT_NAME,edit,1350631552
Control10=IDC_EDIT_NO,edit,1350631552
Control11=IDC_EDIT_S1,edit,1350631552
Control12=IDC_SPIN_S1,msctls_updown32,1342177332
Control13=IDC_EDIT_S2,edit,1350631552
Control14=IDC_SPIN_S2,msctls_updown32,1342177334
Control15=IDC_EDIT_S3,edit,1350631552
Control16=IDC_SPIN_S3,msctls_updown32,1342177334

[CLS:CInputDlg]
Type=0
HeaderFile=InputDlg.h
ImplementationFile=InputDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_NO

