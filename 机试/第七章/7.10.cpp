#include <stdio.h>
struct E //大米
{
	int w;//价格
	int v;//重量 
}list[2001];
int dp[101];
int max(int a,int b)//取最大值函数
{
	return a>b?a:b;
} 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s,n;
		scanf("%d%d",&s,&n);
		int cnt=0;//拆分后物品总数
		for(int i=1;i<=n;i++)//输入
		{
			int v,w,k;
			scanf("%d%d%d",&w,&v,&k);
			int c=1;
			while(k-c>0)//对输入的数字k，拆分成1，2，4...k-2^c+1,其中c为使最后一项大于0的最大整数
			{
				k-=c;
				list[++cnt].w=c*w;
				list[cnt].v=c*v;//拆分后的大米重量和价格均为组成该物品的大米的重量价格和
				c*=2; 
			} 
			list[++cnt].w=w*k;
			list[cnt].v=v*k;
		} 
		for(int i=1;i<=s;i++)
			dp[i]=0;//初始值
		for(int i=1;i<=cnt;i++)//对拆分后得所有物品进行0-1背包
			for(int j=s;j>=list[i].w;j--)
				dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);
		printf("%d\n",dp[s]);//输出答案 
	}
	return 0;
}
