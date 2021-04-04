; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Ctrl2SDI.h"
LastPage=0

ClassCount=6
Class1=CEx_Ctrl2SDIApp
Class2=CEx_Ctrl2SDIDoc
Class3=CEx_Ctrl2SDIView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CCityDlg
Resource3=IDD_CITYZIP

[CLS:CEx_Ctrl2SDIApp]
Type=0
HeaderFile=Ex_Ctrl2SDI.h
ImplementationFile=Ex_Ctrl2SDI.cpp
Filter=N

[CLS:CEx_Ctrl2SDIDoc]
Type=0
HeaderFile=Ex_Ctrl2SDIDoc.h
ImplementationFile=Ex_Ctrl2SDIDoc.cpp
Filter=N

[CLS:CEx_Ctrl2SDIView]
Type=0
HeaderFile=Ex_Ctrl2SDIView.h
ImplementationFile=Ex_Ctrl2SDIView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_TEST_CITY




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Ctrl2SDI.cpp
ImplementationFile=Ex_Ctrl2SDI.cpp
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
Command16=ID_TEST_CITY
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

[DLG:IDD_CITYZIP]
Type=1
Class=CCityDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,listbox,1352728835
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CITY,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_ZIP,edit,1350631552
Control7=IDC_BUTTON_AND,button,1342242816
Control8=IDC_BUTTON_DEL,button,1342242816

[CLS:CCityDlg]
Type=0
HeaderFile=CityDlg.h
ImplementationFile=CityDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

