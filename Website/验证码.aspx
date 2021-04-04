<%@ Page Language="C#" AutoEventWireup="true" CodeFile="验证码.aspx.cs" Inherits="数据库1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:TextBox ID="txtCheckCode" runat="server"></asp:TextBox> <img src="数据库1.aspx">
        <asp:Label ID="lblMessage" runat="server"></asp:Label>
        <br />
     <%--<asp:Button ID="btnLogin" runat="server" Text="登录" onclick="btnLogin_Click1"/> --%>
    
        </div>
    </form>
</body>
</html>
