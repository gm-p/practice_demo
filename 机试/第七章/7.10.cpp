#include <stdio.h>
struct E //����
{
	int w;//�۸�
	int v;//���� 
}list[2001];
int dp[101];
int max(int a,int b)//ȡ���ֵ����
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
		int cnt=0;//��ֺ���Ʒ����
		for(int i=1;i<=n;i++)//����
		{
			int v,w,k;
			scanf("%d%d%d",&w,&v,&k);
			int c=1;
			while(k-c>0)//�����������k����ֳ�1��2��4...k-2^c+1,����cΪʹ���һ�����0���������
			{
				k-=c;
				list[++cnt].w=c*w;
				list[cnt].v=c*v;//��ֺ�Ĵ��������ͼ۸��Ϊ��ɸ���Ʒ�Ĵ��׵������۸��
				c*=2; 
			} 
			list[++cnt].w=w*k;
			list[cnt].v=v*k;
		} 
		for(int i=1;i<=s;i++)
			dp[i]=0;//��ʼֵ
		for(int i=1;i<=cnt;i++)//�Բ�ֺ��������Ʒ����0-1����
			for(int j=s;j>=list[i].w;j--)
				dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);
		printf("%d\n",dp[s]);//����� 
	}
	return 0;
}
