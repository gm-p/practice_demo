#include <stdio.h>
int ans[101][101];//��ά���飬���ʼֵ��Ϊ��ͼ���ڽӾ���
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
				ans[i][j]=-1;//���ڽӾ����ʼ����������-1��������
			ans[i][i]=0;//�Լ����Լ���·��������Ϊ0 
		}
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;//���ڽӾ���ֵ������������ͼ���ø�ֵ����Ҫ��������	
		} 
		for(int k=1;k<=n;k++)//k��1��Nѭ�������δ������������м�����С�ڵ���K
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)//�������е�ans[i][j] ,�ж���ֵ����ԭֵ���ǽ�Ҫ������
				{
					if(ans[i][k]==-1||ans[k][j]==-1) 
						continue;//����ֵ����һ��ֵΪ�����ans[i][j]�������ھ������k�������£�����ѭ��������ԭֵ
					if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
						ans[i][j]=ans[i][k]+ans[k][j];//�����ھ���k���Ի�ø��̵����·��ʱ�����¸�ֵ 
				}
		printf("%d\n",ans[1][n]);//ѭ�������������	 
	}
	return 0;
} 
