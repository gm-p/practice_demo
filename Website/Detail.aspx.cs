using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Configuration;
using System.Data;
using System.Data.SqlClient;

public partial class Detail : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            MainDbSetTableAdapters.userbasicTableAdapter stuDA = new MainDbSetTableAdapters.userbasicTableAdapter();
            DataTable stuDT = stuDA.GetdetailDataByAccount(Request.QueryString["id"].ToString());
            txtId.Text=stuDT.Rows[0]["id"].ToString();
            txtAccount.Text=stuDT.Rows[0]["account"].ToString();
            txtPwd.Text=stuDT.Rows[0]["password"].ToString();
            txtSign.Text = stuDT.Rows[0]["sign"].ToString();
        }
    }
    protected void btnAlter_Click(object sender, EventArgs e)
    {
        MainDbSetTableAdapters.userbasicTableAdapter stuDA = new MainDbSetTableAdapters.userbasicTableAdapter();
        int result=stuDA.UpdateStu(txtAccount.Text, txtPwd.Text, txtSign.Text,int.Parse( txtId.Text));
        if (result > 0)
            Response.Write("<script language=javascript>alert('修改成功!');</script>");
    }
}