using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Configuration;
using System.Data;
using System.Data.SqlClient;
//using System.Web.Security;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
       // Response.Write(FormsAuthentication.HashPasswordForStoringInConfigFile("123456", "MD5"));
    }

    protected void btnLogin_Click(object sender, EventArgs e)
   // {
        // private void btnLogin_Click(object sender, System.Web.UI.ImageClickEventArgs e)
  {
     if (Request.Cookies["CheckCode"] == null)
      {
          lblInfo.Text = "您的浏览器设置已被禁用 Cookies，您必须设置浏览器允许使用 Cookies 选项后才能使用本系统。";
          lblInfo.Visible = true;
          return;
      }
      if (String.Compare(Request.Cookies["CheckCode"].Value, txtCheckCode.Text, true) != 0)
      {
          lblInfo.Text = "验证码错误，请输入正确的验证码。";
          lblInfo.Visible = true;
          return;
      }

      MainDbSetTableAdapters.userbasicTableAdapter stuDA = new MainDbSetTableAdapters.userbasicTableAdapter();
      DataTable stuDT= stuDA.GetDataById( txtName.Text,txtPwd.Text);
      if (stuDT.Rows.Count == 1)
      {
          Session["UserName"] = txtName.Text;
          Response.Redirect("result.aspx");
      }
      else
          lblInfo.Text = "用户名或密码错误";

        //string strConn = ConfigurationManager.ConnectionStrings["tsglxtConnectionString1"].ConnectionString;
        //SqlConnection conn=new SqlConnection(strConn);
        //conn.Open();
        ////string strSql = "select * from userbasic where account='" + txtName.Text + "'and password='" + txtPwd.Text + "'";
        //string strSql = "select * from userbasic where account='" + txtName.Text  + "'";
        //SqlDataAdapter da=new SqlDataAdapter(strSql,strConn);
        //DataSet ds = new DataSet();
        //da.Fill(ds);
        //if (ds.Tables[0].Rows.Count==1)
        //{
        //    //if (txtPwd.Text != "'or '1'='1")
        //    if(ds.Tables[0].Rows[0][2].ToString()==txtPwd.Text)
        //    {
        //        Session["UserName"] = txtName.Text;
        //        Response.Redirect("result.aspx");
        //    }
        //    else
        //    {
        //        lblInfo.Text = "密码错误";
        //    }
        //}
        //else
        //{
        //    lblInfo.Text = "用户名错误";
        //}
    }
}