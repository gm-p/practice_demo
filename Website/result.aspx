<%@ Page Language="C#" AutoEventWireup="true" CodeFile="result.aspx.cs" Inherits="Login" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div><asp:Label ID="lblInfo" runat="server"></asp:Label>
    <br/>
        
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:tsglxtConnectionString1 %>" 
            DeleteCommand="DELETE FROM [userbasic] WHERE [id] = @id" 
            InsertCommand="INSERT INTO [userbasic] ([account], [password], [sign]) VALUES (@account, @password, @sign)" 
            ProviderName="<%$ ConnectionStrings:tsglxtConnectionString1.ProviderName %>" 
            SelectCommand="SELECT * FROM [userbasic] WHERE ([account] = @account)" 
            UpdateCommand="UPDATE [userbasic] SET [account] = @account, [password] = @password, [sign] = @sign WHERE [id] = @id">
            <DeleteParameters>
                <asp:Parameter Name="id" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="account" Type="String" />
                <asp:Parameter Name="password" Type="String" />
                <asp:Parameter Name="sign" Type="String" />
            </InsertParameters>
            <SelectParameters>
                <asp:ControlParameter ControlID="DropDownList1" DefaultValue="sa" 
                    Name="account" PropertyName="SelectedValue" Type="String" />
            </SelectParameters>
            <UpdateParameters>
                <asp:Parameter Name="account" Type="String" />
                <asp:Parameter Name="password" Type="String" />
                <asp:Parameter Name="sign" Type="String" />
                <asp:Parameter Name="id" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
            ConnectionString="<%$ ConnectionStrings:tsglxtConnectionString1 %>" 
            ProviderName="<%$ ConnectionStrings:tsglxtConnectionString1.ProviderName %>" 
            SelectCommand="SELECT * FROM [userbasic]"></asp:SqlDataSource>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
                    DataKeyNames="id" DataSourceID="SqlDataSource1" 
                    EmptyDataText="没有可显示的数据记录。" CellPadding="4" ForeColor="#333333" 
                    GridLines="None">
                    <AlternatingRowStyle BackColor="White" />
                    <Columns>
                        <asp:BoundField DataField="id" HeaderText="id" ReadOnly="True" 
                            SortExpression="id" />
                        <asp:BoundField DataField="account" HeaderText="account" 
                            SortExpression="account" />
                        <asp:BoundField DataField="password" HeaderText="password" 
                            SortExpression="password" />
                        <asp:BoundField DataField="sign" HeaderText="sign" SortExpression="sign" />
                    </Columns>
                    <FooterStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                    <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                    <PagerStyle BackColor="#FFCC66" ForeColor="#333333" HorizontalAlign="Center" />
                    <RowStyle BackColor="#FFFBD6" ForeColor="#333333" />
                    <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="Navy" />
                    <SortedAscendingCellStyle BackColor="#FDF5AC" />
                    <SortedAscendingHeaderStyle BackColor="#4D0000" />
                    <SortedDescendingCellStyle BackColor="#FCF6C0" />
                    <SortedDescendingHeaderStyle BackColor="#820000" />
                </asp:GridView>
                <asp:ScriptManager ID="ScriptManager1" runat="server">
                </asp:ScriptManager>
                <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
                    DataSourceID="SqlDataSource2" DataTextField="account" DataValueField="account">
                </asp:DropDownList>
            </ContentTemplate>
        </asp:UpdatePanel>
    
    </div>
    <asp:GridView ID="GridView2" runat="server" CellPadding="4" ForeColor="#333333" 
        GridLines="None">
        <AlternatingRowStyle BackColor="White" />
        <EditRowStyle BackColor="#2461BF" />
        <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
        <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
        <RowStyle BackColor="#EFF3FB" />
        <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
        <SortedAscendingCellStyle BackColor="#F5F7FB" />
        <SortedAscendingHeaderStyle BackColor="#6D95E1" />
        <SortedDescendingCellStyle BackColor="#E9EBEF" />
        <SortedDescendingHeaderStyle BackColor="#4870BE" />
    </asp:GridView>
    <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" 
        DeleteMethod="Delete" InsertMethod="Insert" 
        OldValuesParameterFormatString="original_{0}" SelectMethod="GetData" 
        TypeName="MainDbSetTableAdapters.userbasicTableAdapter" UpdateMethod="Update">
        <DeleteParameters>
            <asp:Parameter Name="Original_id" Type="Int32" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="account" Type="String" />
            <asp:Parameter Name="password" Type="String" />
            <asp:Parameter Name="sign" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="account" Type="String" />
            <asp:Parameter Name="password" Type="String" />
            <asp:Parameter Name="sign" Type="String" />
            <asp:Parameter Name="Original_id" Type="Int32" />
        </UpdateParameters>
    </asp:ObjectDataSource>
    <br />
    <asp:GridView ID="GridView3" runat="server" AutoGenerateColumns="False" 
        DataKeyNames="id" DataSourceID="ObjectDataSource1">
        <Columns>
            <asp:BoundField DataField="id" HeaderText="id" InsertVisible="False" 
                ReadOnly="True" SortExpression="id" />
            <asp:BoundField DataField="account" HeaderText="account" 
                SortExpression="account" />
            <asp:BoundField DataField="password" HeaderText="password" 
                SortExpression="password" />
            <asp:BoundField DataField="sign" HeaderText="sign" SortExpression="sign" />
            <asp:HyperLinkField DataNavigateUrlFormatString="Detail.aspx?id={0}" 
                HeaderText="详细" NavigateUrl="~/Detail.aspx" Text="详细" 
                DataNavigateUrlFields="account" />
            <asp:HyperLinkField DataNavigateUrlFields="account" 
                DataNavigateUrlFormatString="detail.aspx?id={0}" DataTextField="account" 
                HeaderText="账号" />
            <asp:CommandField ShowDeleteButton="True" />
        </Columns>
    </asp:GridView>
    </form>
</body>
</html>
