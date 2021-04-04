<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>嵌入式样式控制</title>
    <style type="text/css">
    h1{font-size:20pt;color:Red}
    h2{font-size:15pt;color:Blue}
    </style>
    <link href="StyleSheet.css" rel="stylesheet" type="text/css" />
</head>
<body>
    <form id="form1" runat="server">
    <div>
     <h1 >第1章 ASP.NET与Visual Studio开发平台</h1>
    <h2 >1.1 C/S和B/S架构体系</h2>
    <h2>1.2 ASP.NET的体系结构</h2>
    <h1 >第2章  网页设计基础</h1>
    <h2>2.1  HTML标记语言</h2>
    <h2 >2.2  XHTML标记语言</h2>
    </div>
    <div> 
          <div class="left">左边的层</div>
          <div class="right">右边的层</div>
     </div>
    </form>
</body>
</html>
