; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_FileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_File.h"

ClassCount=3
Class1=CEx_FileApp
Class2=CEx_FileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_FILE_DIALOG

[CLS:CEx_FileApp]
Type=0
HeaderFile=Ex_File.h
ImplementationFile=Ex_File.cpp
Filter=N

[CLS:CEx_FileDlg]
Type=0
HeaderFile=Ex_FileDlg.h
ImplementationFile=Ex_FileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_OPEN

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_FileDlg.h
ImplementationFile=Ex_FileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_FILE_DIALOG]
Type=1
Class=CEx_FileDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_TITLE,static,1342312960
Control3=IDC_EDIT1,edit,1353777348
Control4=IDC_BUTTON_OPEN,button,1342242816

