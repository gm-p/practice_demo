#include <stdio.h>
#define INF 0x7fffffff
int max(int a,int b)//ȡ���ֵ���� 
{
	return a>b?a:b;
}
struct E //��ʾ��Ʒ�ṹ��
{
	int w;
	int v;
}list[101];
int dp[1001];
int main()
{
	int s,n;
	while(scanf("%d%d",&s,&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&list[i].w,&list[i].v);//����
		for(int i=0;i<=s;i++)
			dp[i]=0;//��ʼֵ 
		for(int i=1;i<=n;i++)
			for(int j=s;j>=list[i].w;j--)//���뵹�����ÿ��dp[j]��ֵ��jС��list[i].w�ĸ�dp[j]�������£�����ԭֵ�����ȼ���dp[i][j]=dp[i-1][j]
				dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);//dp[j]��ԭֵ��dp[j-list[i].w]+list[i].v��ѡȡ�ϴ���Ǹ� 
	printf("%d\n",dp[s]);//�����
	}
	return 0; 
}
