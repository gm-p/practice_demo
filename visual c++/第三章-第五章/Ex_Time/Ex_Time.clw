; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_TimeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Time.h"

ClassCount=3
Class1=CEx_TimeApp
Class2=CEx_TimeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_TIME_DIALOG

[CLS:CEx_TimeApp]
Type=0
HeaderFile=Ex_Time.h
ImplementationFile=Ex_Time.cpp
Filter=N

[CLS:CEx_TimeDlg]
Type=0
HeaderFile=Ex_TimeDlg.h
ImplementationFile=Ex_TimeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MONTHCALENDAR1

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_TimeDlg.h
ImplementationFile=Ex_TimeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_TIME_DIALOG]
Type=1
Class=CEx_TimeDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_DATA,static,1342312961
Control3=IDC_MONTHCALENDAR1,SysMonthCal32,1342242832
Control4=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control5=IDC_CHECK1,button,1342242819

