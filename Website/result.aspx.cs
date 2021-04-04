using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Configuration;
using System.Data;
using System.Data.SqlClient;

public partial class Login : System.Web.UI.Page
{
    string strConn = ConfigurationManager.ConnectionStrings["tsglxtConnectionString1"].ConnectionString;
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["UserName"] != null)
        {
            lblInfo.Text = "欢迎您:" + Session["UserName"].ToString();
            SqlConnection conn = new SqlConnection(strConn);
            conn.Open();
            string strSQL = "select * from userbasic";
            SqlDataAdapter da = new SqlDataAdapter(strSQL, conn);
            DataSet ds = new DataSet();
            da.Fill(ds);
            GridView2.DataSource = ds;
            GridView2.DataBind();
            conn.Close();
        }
        else
            Response.Redirect("Login.aspx");

    }
}