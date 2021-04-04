<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server"><style type="text/css">
.style1
{
    margin-top:0px;
    margin-bottom:0px;
    height:10px;
    line-height:10px;
}
.style2
{
    margin-top:0px;
    margin-bottom:0px;
    height:20px;
    line-height:20px;
}
.style3
{
   margin-top:5px;
    margin-bottom:0px;
    height:20px;
    line-height:20px;
}


</style>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <div class=style1><asp:Label ID="lblName" runat="server" Text="用户名"></asp:Label>
        <asp:TextBox ID="txtName" runat="server" ></asp:TextBox></div>
      <br/>
        <div class=style1><asp:Label ID="lblPwd" runat="server" Text="密码"></asp:Label>
        <asp:TextBox ID="txtPwd" runat="server" ></asp:TextBox></div>
      <br/>
        <div class=style1><asp:TextBox ID="txtCheckCode" class="style2"  runat="server" ></asp:TextBox>
        <asp:Image ID="Image1" class="style2"  runat="server" ImageUrl="~/验证码.aspx" /></div>
        <br />
        <div class=style3><asp:Button ID="btnLogin" runat="server" onclick="btnLogin_Click" Text="登录" />
        <asp:Label ID="lblInfo" runat="server"></asp:Label></div>
    
       
    
    </div>
    </form>
</body>
</html>
