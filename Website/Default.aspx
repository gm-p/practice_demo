<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <link href="StyleSheet2.css" rel="stylesheet" type="text/css" />
    <title>使用style属性设置格式</title>
</head>
<body style="background-color:Silver;color:Blue">
<h1 style="text-align:center">用第1级标题显示文字</h1>
<h2 style="text-align:center">用第2级标题显示文字</h2>
<p style="font-size:20px;font-family:隶书;text-align:center">文字大小20像素，字体隶书</p>
<p style="text-align:center">正常字体&nbsp;<b>粗体&nbsp;<i>斜体</i>&nbsp;<u>下划线</u></b></p>
    <form id="form1" runat="server">
    <div>
    <h1 style="font-size:20pt;color:Red;">第1章 ASP.NET与Visual Studio开发平台</h1>
    <h2 style="font-size:20pt;color:Blue;">1.1 C/S和B/S架构体系</h2>
    <h2 style="font-size:20pt;color:Blue;">1.2 ASP.NET的体系结构</h2>
    <h1 style="font-size:30pt;color:Red;">第2章  网页设计基础</h1>
    <h2 style="font-size;20pt;color:Blue;">2.1  HTML标记语言</h2>
    <h2 style="font-size:20pt;color:Blue;">2.2  XHTML标记语言</h2>
    </div>
    <table border=1 width=800px>
    <tr>
       <td>&nbsp;</td>
      <td>&nbsp;</td>
      <td rowspan="2" align=center><div class="ddlcenter">
          <asp:DropDownList ID="DropDownList1" runat="server" CssClass="style1">
              <asp:ListItem>2013</asp:ListItem>
              <asp:ListItem>二零一三</asp:ListItem>
          </asp:DropDownList> </div></td>
      <!--代码中“&quot;”标记表示双引号-->
      <td>&nbsp;</td>
      </tr>
      <tr>
          <td colspan="2" align=center>colspan=&quot;2&quot;</td>
          <td>&nbsp;</td>
      </tr>
      </table>
    </form>
</body>
</html>
