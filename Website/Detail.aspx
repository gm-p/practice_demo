<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Detail.aspx.cs" Inherits="Detail" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:Label ID="Label1" runat="server" Text="id"></asp:Label>
        <asp:TextBox ID="txtId" runat="server" Enabled="False"></asp:TextBox>
        <br />
        <asp:Label ID="Label2" runat="server" Text="账号"></asp:Label>
        <asp:TextBox ID="txtAccount" runat="server"></asp:TextBox>
        <br />
        <asp:Label ID="Label3" runat="server" Text="密码"></asp:Label>
        <asp:TextBox ID="txtPwd" runat="server"></asp:TextBox>
        <br />
        <asp:Label ID="Label4" runat="server" Text="状态"></asp:Label>
        <asp:TextBox ID="txtSign" runat="server"></asp:TextBox>
        <br />
        <asp:Button ID="btnAlter" runat="server" onclick="btnAlter_Click" Text="提交" />
    
    </div>
    </form>
</body>
</html>
