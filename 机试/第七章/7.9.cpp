#include <stdio.h>
#define INF 0x7fffffff
int min(int a,int b)
{
	return a<b?a:b;//ȡ��Сֵ���� 
}
struct E  //����Ǯ�ҽṹ��
{
	int w;//����
	int v;//��ֵ 
}list[501];
int dp[10001];//״̬
int main()
{
	int T;
	scanf("%d",&T);//���������������
	while(T--)//T��ѭ��������T������
	{
		int s,tmp;
		scanf("%d%d",&tmp,&s);//����մ������������װ��Ǯ�ҵĴ��������
		s-=tmp;//����Ǯ����ռ����
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].v,&list[i].w);//�������� 
		} 
		for(int i=0;i<=s;i++)
			dp[i]=INF;
		dp[0]=0;//��ΪҪ��������Ʒǡ��װ�������Գ�ʼʱ����dp[0]�⣬����dp[j]��Ϊ������߲�����)
		for(int i=1;i<=n;i++)//����������Ʒ
			for(int j=list[i].w;j<=s;j++)//��ȫ������˳��������п���ת�Ƶ�״̬ 
			{
				if(dp[j-list[i].w]!=INF)//��dp[j-list[i].w]��Ϊ����Ϳ����ɴ�״̬ת�ƶ���
					dp[j]=min(dp[j],dp[j-list[i].w]+list[i].v);//ȡת��ֵ��ԭֵ�Ľ�Сֵ 
			}
		if(dp[s]!=INF)//������һ�ַ���ʹ����ǡ��װ�����������Сֵ
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[s]);
		else //�������ڷ���
		 	puts("This is impossible.");
	} 
	return 0;
} 
