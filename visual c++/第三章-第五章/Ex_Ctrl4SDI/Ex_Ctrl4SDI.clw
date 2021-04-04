; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Ctrl4SDI.h"
LastPage=0

ClassCount=6
Class1=CEx_Ctrl4SDIApp
Class2=CEx_Ctrl4SDIDoc
Class3=CEx_Ctrl4SDIView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CProgressDlg
Resource3=IDD_PROGRESS

[CLS:CEx_Ctrl4SDIApp]
Type=0
HeaderFile=Ex_Ctrl4SDI.h
ImplementationFile=Ex_Ctrl4SDI.cpp
Filter=N

[CLS:CEx_Ctrl4SDIDoc]
Type=0
HeaderFile=Ex_Ctrl4SDIDoc.h
ImplementationFile=Ex_Ctrl4SDIDoc.cpp
Filter=N

[CLS:CEx_Ctrl4SDIView]
Type=0
HeaderFile=Ex_Ctrl4SDIView.h
ImplementationFile=Ex_Ctrl4SDIView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_TEST_PROGRESS




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Ctrl4SDI.cpp
ImplementationFile=Ex_Ctrl4SDI.cpp
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
Command16=ID_TEST_PROGRESS
Command17=ID_APP_ABOUT
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

[DLG:IDD_PROGRESS]
Type=1
Class=CProgressDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_TEXT,static,1342308353
Control3=IDC_PROGRESS1,msctls_progress32,1350565888
Control4=IDC_BUTTON_BACK,button,1342242816
Control5=IDC_BUTTON_GOON,button,1342242816

[CLS:CProgressDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_BACK
VirtualFilter=dWC

