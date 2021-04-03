#include <stdio.h>
int ans[101][101];//二维数组，其初始值即为该图的邻接矩阵
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				ans[i][j]=-1;//对邻接矩阵初始化，我们用-1代表无穷
			ans[i][i]=0;//自己到自己的路径长度设为0 
		}
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;//对邻接矩阵赋值，由于是无向图，该赋值操作要进行两次	
		} 
		for(int k=1;k<=n;k++)//k从1到N循环，依次代表允许经过的中间结点编号小于等于K
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)//遍历所有的ans[i][j] ,判断其值保持原值还是将要被更新
				{
					if(ans[i][k]==-1||ans[k][j]==-1) 
						continue;//若两值中有一个值为无穷，则ans[i][j]不能由于经过结点k而被更新，跳过循环，保持原值
					if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
						ans[i][j]=ans[i][k]+ans[k][j];//当由于经过k可以获得更短的最短路径时，更新该值 
				}
		printf("%d\n",ans[1][n]);//循环结束后输出答案	 
	}
	return 0;
} 
