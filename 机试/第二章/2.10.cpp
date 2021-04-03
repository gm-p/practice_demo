#include <stdio.h>
int main()
{
	int h;
	while(scanf("%d",&h)!=EOF)
	{
		int maxLine=h+(h-1)*2;//计算最后一行包含的星号个数
		for(int i=1;i<=h;i++)//依次输出每行信息
		{ 	
		  for(int j=1;j<=maxLine;j++)//依次输出每行当中的空格或星号
		  {
		    if(j<maxLine-h-(i-1)*2+1)//输出空格
			  printf(" ");
			else//输出星号 
			  printf("*");
		   }
		  printf("\n");//输出换行 
		}
	}
	return 0;
}
