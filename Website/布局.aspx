<%@ Page Language="C#" AutoEventWireup="true" CodeFile="布局.aspx.cs" Inherits="布局" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>管理员</title>

    <style type="text/css"> 
        .alldiv
        {
            width:778px;
            border:#00ff00 1px solid;
        }
        #top
        {
            width:100%;
            height:113px;
            line-height:113px;
            background-image:url("图片/exame_02.gif");
            font-family:@微软雅黑;
            font-size:18px;
         }
         #left
         {
             width:197px;
             height:500px;
             line-height:500px;
             font-family:@宋体;
             font-size:18px;
             float:left;
          }
          #right
          {
              width:576px;
              height:500px;
              line-height:500px;
              font-family:@宋体;
              font-size:18px;
              float:left;
           }
           #bottom
           {
               width:100%;
               height:72px;              
               background-image:url("图片/back_13.gif"); 
               line-height:72px;
               clear:both;
            }
           .style1
           {
               float:left;
            margin-left: 3px;
            margin-top:10px;
        }     
            
            #style2
        {
            width: 100%;
            height:72px;
        }
        .style3
        {
            height:18px;
            line-height:18px;
         }
            
            .style4
        {
            width: 100%;
            height: 17px;
            margin-top: 0px;
        }
        .style6
        {
            width: 65px;
            height: 15px;
        }
        .style7
        {
            width: 58px;
            height: 15px;
        }
        .style10
        {
            width: 93px;
            height: 15px;
        }
        .style11
        {
            width: 53px;
            height: 15px;
        }
        .style12
        {
            width: 57px;
            height: 15px;
        }
        .style13
        {
            width: 63px;
            height: 15px;
        }
            
            .style14
        {
            width: 54px;
            height: 15px;
        }
            
            .style15
        {
            height: 15px;
        }
        .style16
        {
            height: 6px;
            line-height: 18px;
        }
            
            </style>
</head>
<body >
    <form runat="server">
    <center>
    <div class="alldiv">
 
     <div id="top" class="alldiv">
         <ul style="float:left;width:100%; height: 20px;line-height:20px;margin-top:93px; margin-left: 0px; margin-bottom: 0px;">
         <li style="float:left;width:19%;font-size:20px;color:Red;overflow:hidden; "><a href="http://www.baidu.com" target="iframe1">百度一下</a></li>
         <li style="float:left;width:19%;font-size:20px;color:Red;overflow:hidden;"><a href="http://www.qq.com"target="iframe1">腾讯网</a></li>
         <li style="float:left;width:19%;font-size:20px;color:Red;overflow:hidden;"><a href="http://www.xinlang.com"target="iframe1">新浪网</a></li>
         <li style="float:left;width:19%;font-size:20px;color:Red;overflow:hidden;"><a href="http://www.360.cn"target="iframe1">360搜索</a></li>
         <li style="float:left;width:19%; font-size:20px;color:Red;overflow:hidden;"><a href="http://www.hubu.edu.cn"target="iframe1">湖北大学</a></li>
         </ul>
        </div>

     <div id="left" class="alldiv">
     <div style="height:20px;line-height:20px;">
         <asp:Label ID="lblName" runat="server" Text="用户名" CssClass=style1 Width="54px"></asp:Label>
         <asp:TextBox ID="txtName" runat="server" CssClass=style1 Width="125px"></asp:TextBox></div>
          <div style="height:20px;line-height:20px;">
         <asp:Label ID="lblPassword" runat="server" Text="密码" CssClass=style1 Width="54px"></asp:Label>
         <asp:TextBox ID="TextBox1" runat="server" CssClass=style1 Width="125px" 
                  TextMode="Password"></asp:TextBox></div>
          <div style="height:20px;line-height:20px; margin-left:90px;margin-top:10px;">
              <asp:Button ID="btnLogin" runat="server" Text="登录" /></div>
     </div>
        

     <div id="right" class="alldiv">
     <iframe name="iframe1" src="Default.aspx" 
             style="height:491px; line-height:500px;width:571px;" ></iframe>
     </div>

     <div id="bottom" class="alldiv">
        
        
         <table id="style2">
             <tr>
                 <td class=style16 colspan="3">
                     </td>
             </tr>
             <tr>
                 <td class=style3 colspan="3">
                     <table class="style4">
                         <tr>
                             <td class="style10">
                                 </td>
                             <td class="style11">
                                 </td>
                             <td class="style12">
                                 </td>
                             <td class="style6">
                                 <div><a href="http://www.hao123.com">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</a></div></td>
                             <td class="style7">
                                <a href="http://www.hao123.com">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</a></td>
                             <td class="style13">
                                <a href="http://www.hao123.com">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</a></td>
                             <td class="style13">
                                 <a href="http://www.baidu.com">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</a></td>
                             <td class="style14">
                                <a href="http://www.baidu.com">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</a></td>
                             <td class="style15">
                                 </td>
                             <td class="style15">
                                 </td>
                         </tr>
                     </table>
                 </td>
             </tr>
             <tr>
                 <td class=style3>
                     &nbsp;</td>
                 <td class=style3>
                     &nbsp;</td>
                 <td class=style3>
                     &nbsp;</td>
             </tr>
             </table>
        
        
        </div>

    </div></center>
    </form>
</body>

</html>
