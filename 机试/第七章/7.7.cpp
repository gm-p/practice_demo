#include <stdio.h>
#define INF 0x7fffffff
int max(int a,int b)
{
	return a>b?a:b;//取最大值函数 
}
struct E //保存物品信息结构体
{
	int w;//物品的体积
	int v;//物品的价值 
}list[101];
int dp[101][1001];//记录状态数组，dp[i][j]表示前i个物品组成的总体积不大于j的最大价值和
int main()
{
	int s,n;
	while(scanf("%d%d",&s,&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&list[i].w,&list[i].v);//输入
		for(int i=0;i<=s;i++)
			dp[0][i]=0;//初始化状态
		for(int i=1;i<=n;i++)//循环每一个物品
		{
			for(int j=s;j>=list[i].w;j--)//对s到list[i].w的每个j状态转移来源为dp[i-1][j]或dp[i-1][j-list[i].w]+list[i].v选择其中较大的值
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-list[i].w]+list[i].v); 
			for(int j=list[i].w-1;j>=0;j--)//对list[i].w-1到0的每个j，状态仅能来源于dp[i-1][j],故直接赋值
				dp[i][j]=dp[i-1][j];
		}	
		printf("%d\n",dp[n][s]);//输出答案 	
	}
	return 0; 
} 
