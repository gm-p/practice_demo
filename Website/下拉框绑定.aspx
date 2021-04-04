<%@ Page Language="C#" AutoEventWireup="true" CodeFile="下拉框绑定.aspx.cs" Inherits="下拉框绑定" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        
    
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate><asp:Label ID="Label1" runat="server" Text="学院"></asp:Label>
        <asp:DropDownList ID="DropDownList1" runat="server" 
            DataSourceID="SqlDataSource1" DataTextField="Academyname" 
            DataValueField="Academyno" AutoPostBack="True"> </asp:DropDownList>
        <asp:Label ID="Label2" runat="server" Text="专业"></asp:Label>
        <asp:DropDownList ID="DropDownList2" runat="server" 
            DataSourceID="SqlDataSource2" DataTextField="Majorname" 
            DataValueField="Majorname"></asp:DropDownList>
                <asp:ScriptManager ID="ScriptManager1" runat="server">
                </asp:ScriptManager>
            </ContentTemplate>
        </asp:UpdatePanel>
    
        <br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:StumanagementConnectionString1 %>" 
            SelectCommand="SELECT * FROM [Academy]"></asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
            ConnectionString="<%$ ConnectionStrings:StumanagementConnectionString1 %>" 
            SelectCommand="SELECT * FROM [Major] WHERE ([Academyno] = @Academyno)">
            <SelectParameters>
                <asp:ControlParameter ControlID="DropDownList1" Name="Academyno" 
                    PropertyName="SelectedValue" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
