#include <stdio.h>
int main()
{
	int outPutBuf[82][82];//用于预排版的输出缓存
	char a,b;//输入的两个字符
	int n;//叠框大小
	bool firstCase=true;//是否为第一组数据标志，初始值为true
	while(scanf("%d %c %c",&n,&a,&b)==3)
	{
		if(firstCase==true)//若是第一组数据
		  firstCase=false;//将第一组数据标志标记成false
		else
		  printf("\n");//否则输出换行
		for(int i=1,j=1;i<=n;i+=2,j++)//从里至外输出每个圈 
		{
			int x=n/2+1,y=x;
			x-=j-1;  y-=j-1;//计算每个圈右上角点的坐标
			char c=j%2==1?a:b;//计算当前圈需要使用哪个字符 
			for(int k=1;k<=i;k++)//对当前圈进行赋值
			{
				outPutBuf[x+k-1][y]=c;//左边赋值
				outPutBuf[x][y+k-1]=c;//上边赋值
				outPutBuf[x+i-1][y+k-1]=c;//右边赋值
				outPutBuf[x+k-1][y+i-1]=c;//下边赋值 
			} 
		} 
		if(n!=1)//注意当n为1时不需此步骤
		{
			outPutBuf[1][1]=' ';
			outPutBuf[n][1]=' ';
			outPutBuf[1][n]=' ';
			outPutBuf[n][n]=' ';//将四角置为空格 
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			  printf("%c",outPutBuf[i][j]);
			printf("\n");
		}//输出已经经过排版的在输出缓存中的数据 
	} 
	return 0;
}
