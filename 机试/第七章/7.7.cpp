#include <stdio.h>
#define INF 0x7fffffff
int max(int a,int b)
{
	return a>b?a:b;//ȡ���ֵ���� 
}
struct E //������Ʒ��Ϣ�ṹ��
{
	int w;//��Ʒ�����
	int v;//��Ʒ�ļ�ֵ 
}list[101];
int dp[101][1001];//��¼״̬���飬dp[i][j]��ʾǰi����Ʒ��ɵ������������j������ֵ��
int main()
{
	int s,n;
	while(scanf("%d%d",&s,&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&list[i].w,&list[i].v);//����
		for(int i=0;i<=s;i++)
			dp[0][i]=0;//��ʼ��״̬
		for(int i=1;i<=n;i++)//ѭ��ÿһ����Ʒ
		{
			for(int j=s;j>=list[i].w;j--)//��s��list[i].w��ÿ��j״̬ת����ԴΪdp[i-1][j]��dp[i-1][j-list[i].w]+list[i].vѡ�����нϴ��ֵ
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-list[i].w]+list[i].v); 
			for(int j=list[i].w-1;j>=0;j--)//��list[i].w-1��0��ÿ��j��״̬������Դ��dp[i-1][j],��ֱ�Ӹ�ֵ
				dp[i][j]=dp[i-1][j];
		}	
		printf("%d\n",dp[n][s]);//����� 	
	}
	return 0; 
} 
