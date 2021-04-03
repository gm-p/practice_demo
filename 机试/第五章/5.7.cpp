#include <stdio.h>
#include <vector>
using namespace std;
struct E //�ڽ�����Ԫ�ؽṹ��
{
	int next;
	int c;
	int cost;
} ;
vector<E> edge[1001];//�ڽ�����
int Dis[1001];//��������
int cost[1001];//��������
bool mark[1001];//�Ƿ����ڼ���k����
int main()
{
	int n,m;
	int S,T;//��㣬�յ�
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			edge[i].clear();//��ʼ���ڽ����� 
		while(m--)
		{
			int a,b,c,cost;
			scanf("%d%d%d%d",&a,&b,&c,&cost);
			E tmp;
			tmp.c=c;
			tmp.cost=cost;//�ڽ������������˸ñߵĻ�����Ϣ 
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		} 
		scanf("%d%d",&S,&T);//��������յ���Ϣ
		for(int i=1;i<=n;i++)//��ʼ��
		{
			Dis[i]=-1;
			mark[i]=false;
		} 
		Dis[S]=0;
		mark[S]=true;
		int newP=S;//���ΪS��������뼯��K��������̾���ȷ��Ϊ0
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<edge[newP].size();j++)
			{
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				int co=edge[newP][j].cost;//���� 
				if(mark[t]==true)
					continue;
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c||Dis[t]==Dis[newP]+c&&cost[t]>cost[newP]+co)//�Ƚϴ�Сʱ����������ͬ�����Ѹ���Ҳ��Ϊ���µ�����֮һ
				{
					Dis[t]=Dis[newP]+c;
					cost[t]=cost[newP]+co;//���»��� 
				} 
			}
			int min=123123123;
			for(int j=1;j<=n;j++)//ѡ����Сֵ��ѡ��ʱ���ÿ��ǻ��ѵ����أ���Ϊ��������ĵ�Ļ����Ѿ����������ھ���������������ı���
			{
				if(mark[j]==true)
					continue;
				if(Dis[j]==-1)
					continue;
				if(Dis[j]<min)
				{
					min=Dis[j];
					newP=j;
				}
			} 
			mark[newP]=true;
		} 
		printf("%d %d\n",Dis[T],cost[T]);//����� 
	} 
	return 0;
} 
